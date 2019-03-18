#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "CRC32.h"
#include <openssl/md5.h>
#include <openssl/rsa.h>
#include <openssl/rc4.h>
#include "sxe13.1.pb-c.h"
#include "engine.h"

HINSTANCE g_hInstance;HANDLE hThread=NULL;
cl_enginefunc_t *pEngfuncs;
cl_enginefunc_t  gEngfuncs;
unsigned int ukey=0,sstimer=0,gkey=0;
time_t svTime=0;

UINT rseed=0;

VOID WINAPI SetSeed(UINT s){
  rseed=s;
}

UINT WINAPI Rand(){
  rseed=1103515245*rseed+12345;
  return ((rseed>>16)%0x8000);
}

unsigned char *RC4String(int klen,const unsigned char *kdata,int inlen,const unsigned char *indata){
  static unsigned char rBuf[1024];
  RC4_KEY key;unsigned char tBuf[512];int i;
  memset(tBuf,0,sizeof(tBuf));
  memset(rBuf,0,sizeof(rBuf));

  RC4_set_key(&key,klen,kdata);
  RC4(&key,inlen,indata,tBuf);
  for(i=0;i<inlen;i++)
    sprintf((char*)&rBuf[i*2],"%02X",tBuf[i]&0xFF);

  return rBuf;
}

unsigned char *MD5String(int inlen,unsigned char *inString){
  static unsigned char rBuf[1024];

  unsigned char tBuf[512];int i;
  MD5(inString,inlen,tBuf);
  for(i=0;i<16;i++)
    sprintf((char*)&rBuf[i*2],"%02x",tBuf[i]&0xFF);

  return rBuf;
}

unsigned char *RSAString(int inlen,const unsigned char *indata){
  static unsigned char rBuf[1024];
  memset(rBuf,0,sizeof(rBuf));
  RSA *rsa = RSA_new();
	BN_hex2bn(&rsa->n,"D327115ABA9867BD63C66AE8C4A8E6F8A770D99DCFEDB4C112B9A6CD8B50A9F27068310875D140D09A6091B5C59EF3099E8BA72DEAFEEB7E0FB09AD323340C16B7B6EB0F14139B7849D19F94B85640DBF161710670FD8C0F358EE522648121D299743F303AA69485160BB535AF29A4990AFE3EDB6FD55B5819F9D5DC6FD7F043");
  BN_hex2bn(&rsa->e,"010001");
  BN_hex2bn(&rsa->d,"6750EF61E87958114837B6E9EC0804F3D7E214E8EDEB8E8D061F86E97DE85B2F8026CB0F2BAED6BAFB3E932D50E40461498D65A0C7223291FD1559BC43B65CCF00E7C49EA190430500BF7830730427B5D29B6A240A2E7050402D972C19A4FF1C84BEC340ED970B823BFCD04AD046412836C3AF39932210E33C99F243008786A9");
  BN_hex2bn(&rsa->p,"F6EC40133AE71A2D0BBA131B826682A5E219CFDE4349DF9A05E8281D2DA4C86DA2C68ABC20D5FA6213C6A13C50D148463B67BF6EC7FA584E932595AA87F15777");
  BN_hex2bn(&rsa->q,"DAEA30909D8A20DC98983F6D6CFC01ECF23C1673A4566ED44B89C7BA79EB6859D8118102FEB2231883CE65724D840EC525EB80FCB1FB2F30BA8B19DC10323895");
  BN_hex2bn(&rsa->dmp1,"C6D6F2B6499DA6A795A4EF141D0B3DB4258211B173503EDEC258F44CA2DFEA82D72CB8B5CC5F63B4AD262BDAED5DCAACBBD3CD0581C6686C45F46334A32A46FB");
  BN_hex2bn(&rsa->dmq1,"36325E7D9F131059ACC99C8259C5F63014347E16792C10DA2C2D5B2E367AEA65BBD171902D402AE229D79253FF0EDF9D3D6B158EF9FD46CC9892517FA2DEDC15");
  BN_hex2bn(&rsa->iqmp,"48C6D304C91D78F8B839C917441F5D60CF7A26A821A94795787A82DC4EE1ED4AA74B560F0A8011891DB8F98817442316CA1CEFE081E45CB4BE6C04E30A20FB28");
  RSA_private_encrypt(inlen,indata,rBuf,rsa,RSA_PKCS1_PADDING);
  RSA_free(rsa);
  return rBuf;
}

PBYTE FindCodeSignature(PBYTE bStart,UINT iLength,PBYTE bCode,UINT iCodeLen,UINT offset){
	for(PBYTE p=bStart;(p+iCodeLen)<(bStart+iLength);p++){
    for(PBYTE q=p,s=bCode;(UINT)(q-p)<iCodeLen;q++,s++){
      if(*q!=*s)break;
      if((UINT)(q-p)==iCodeLen-1)
        return (p+offset);
    }
	}
	return 0;
}

BOOL FindOffsets(void){
  PBYTE dir=(PBYTE)GetModuleHandle("hw.dll");
  if(!dir)dir=(PBYTE)GetModuleHandle("sw.dll");
  if(!dir)dir=(PBYTE)0x1D00000;
  BYTE bPushAddrPattern[]={0x68,0x90,0x90,0x90,0x90};
  PBYTE pEngStr=FindCodeSignature(dir,0x01226000,(PBYTE)"ScreenFade",10,0);
  if(pEngStr){
    *(PDWORD)(&bPushAddrPattern[1])=(DWORD)pEngStr;
    pEngfuncs=(cl_enginefunc_t*)(*(PDWORD*)FindCodeSignature(dir,0x01226000,bPushAddrPattern,5,13));
    return TRUE;
  }
  return FALSE;
}

VOID GetServerIP(unsigned char ip[4]){
  struct net_status_s status;
  pEngfuncs->pNetAPI->Status(&status);
  memcpy(ip,status.remote_address.ip,4);
}

PUCHAR GetEnd(PUCHAR a){
  while(*++a);return a;
}

int sXeI(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned int i=0,key=0;
  unsigned char chlgbuf[512],respbuf[512],tmprespbuf[256],ip[4];
  unsigned char md5buf[256],rc4buf[256],rsabuf[512],*pBuf;

  BEGIN_READ(pbuf,iSize);
  PCHAR version=READ_STRING();
  LONG time=READ_LONG();
  DWORD sp=READ_LONG();
  DWORD sp1=READ_LONG();
  DWORD sp2=READ_LONG();
  float fversion=atof(version);

  memset(chlgbuf,0,sizeof(chlgbuf));
  memset(md5buf,0,sizeof(md5buf));
  memset(rc4buf,0,sizeof(rc4buf));

  GetServerIP(ip);
  if(fversion==12.3f){
    //sxe >= 12.3 -> Ironic... :P
    sprintf((char*)chlgbuf,"%2.1f#(%d@[%d#(%d)]@[%d&{%d}&{%d}])",
      fversion,ip[2],ip[0],ip[3],ip[1],(int)time,(int)(ip[0]^time));
  }else{
    //sxe >= 12.1, 12.2
    sprintf((char*)chlgbuf,"%sq2,;::%d.fgt%d.$%d.9_7%dbn.09%d",
      version,ip[2],ip[0],ip[3],ip[1],(int)time);
    //version,ip[3],ip[1],ip[2],ip[0],(int)time); (old sxe 11.X)
  }
  pBuf=chlgbuf;pBuf=GetEnd(pBuf);
  if(fversion==12.3f){
    *(pBuf++)=chlgbuf[sp1+2];
    *(pBuf++)=2*chlgbuf[11];
  }else{
    *(pBuf++)=chlgbuf[sp1+5];
    *(pBuf++)=3*chlgbuf[17];
  }
  strcpy((char*)md5buf,(const char*)MD5String(strlen((const char*)chlgbuf),chlgbuf));

  pBuf=md5buf;pBuf=GetEnd(pBuf);
  *(pBuf++)=2*md5buf[11];
  *(pBuf++)=md5buf[sp2+2];
  memcpy((char*)rsabuf,RSAString(strlen((char*)md5buf),md5buf),128);

  pBuf=rc4buf;
  if(fversion==12.3f)
    *(DWORD*)pBuf=0x33320209;//(sxe >= 12.3)
  else
    *(DWORD*)pBuf=0x02323309;//(old sxe 12.1)

  if(sp==10){//updated by sxe 12.1 (dll)
    ukey=0;
    sprintf((char*)pBuf+4,"%d",(int)time+68);
  }else{
    ukey=sp-20;
    if(ukey>9)
      ukey=1;
    gkey=time+ukey;
    for(i=0;i<ukey;++i)
      gkey=1103515245*gkey+12345;
    key=(gkey>>16)%0x8000;
    sprintf((char*)pBuf+4,"%d",(int)key);
  }

  pBuf=GetEnd(pBuf);
  *(DWORD*)pBuf=0x08980634;
  strcpy((char*)respbuf,(const char*)RC4String(strlen((char*)rc4buf),rc4buf,128,rsabuf));

  //send responce...
  pBuf=respbuf;
  //it's to big?
  if(strlen((char*)pBuf)>80){
    strncpy((char*)tmprespbuf,(char*)pBuf,80);tmprespbuf[80]=0;
    pBuf+=80;
    //first!
    sprintf((char*)chlgbuf,"[sXe-I-ReplyA] %s",tmprespbuf);
    pEngfuncs->pfnClientCmd((char*)chlgbuf);
  }

  //still to big?
  if(strlen((char*)pBuf)>80){
    strncpy((char*)tmprespbuf,(char*)pBuf,80);tmprespbuf[80]=0;
    pBuf+=80;
    //second!
    sprintf((char*)chlgbuf,"[sXe-I-ReplyB] %s",tmprespbuf);
    pEngfuncs->pfnClientCmd((char*)chlgbuf);
  }

  //finaly!
  sprintf((char*)chlgbuf,"[sXe-I-Reply] %s CLEAN 32",pBuf);
  pEngfuncs->pfnClientCmd((char*)chlgbuf);

  pEngfuncs->pfnClientCmd("bind F3 sxe_screenoff");
  return 0;
}

int sXeIH(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned char chlgbuf[256],respbuf[70];
  unsigned char rc4buf[256],hwidbuf[64];
  unsigned int i,key;

  memset(rc4buf,0,sizeof(rc4buf));

  BEGIN_READ(pbuf,iSize);
  DWORD time=READ_LONG();
  DWORD sp1=READ_LONG();
  DWORD sp2=READ_LONG();

  srand(time);
  for(i=0;i<5;i++)
    sprintf((char*)&hwidbuf[i*5],"%4.4X-",rand()&0xFFFF);
  hwidbuf[i*5-1]=0;

  //CRC32 HWID
  key=CRC32((char*)hwidbuf);
  sprintf((char*)hwidbuf,"%s-%-4.4X-%-4.4X",hwidbuf,key>>16,key&0xFFFF);

  //set HID info for if server try to compare...
  pEngfuncs->PlayerInfo_SetValueForKey("*HID",(const char*)hwidbuf);

  *(DWORD*)&rc4buf[0]=0x8C3233A1;
  *(DWORD*)&rc4buf[4]=time;
  *(DWORD*)&rc4buf[8]=0x08DA774E;
  *(DWORD*)&rc4buf[12]=sp1+0x18624;
  *(DWORD*)&rc4buf[16]=sp2+0xAD44;

  strcpy((char*)respbuf,(const char*)RC4String(20,rc4buf,strlen((char*)hwidbuf),hwidbuf));
  //send response
  sprintf((char*)chlgbuf,"[sXe-I-H-Reply] 22%s",respbuf);
  pEngfuncs->pfnClientCmd((char*)chlgbuf);
  return 0;
}

int sXeSS(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned char chlgbuf[256];
  memset(chlgbuf,0,sizeof(chlgbuf));

  BEGIN_READ(pbuf,iSize);
  sstimer=READ_LONG();

  //send response -> ( realsize xres yres encodedsize time )
  sprintf((char*)chlgbuf,"[sXe-I-SS-Reply] %d %d %d %d %d",1,640,480,1,sstimer);

  pEngfuncs->pfnClientCmd((char*)chlgbuf);
  return 0;
}

int sXeSSD(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned char chlgbuf[256];
  memset(chlgbuf,0,sizeof(chlgbuf));

  BEGIN_READ(pbuf,iSize);
  DWORD epos=READ_LONG();
  DWORD size=READ_LONG();
  DWORD blastpart=READ_LONG();

  //send response -> ( bufsize buffer lastpart time )
  sprintf((char*)chlgbuf,"[sXe-I-SSD-Reply] %d %s %d %d",1,"0",blastpart,sstimer);

  pEngfuncs->pfnClientCmd((char*)chlgbuf);
  if(blastpart)
    sstimer=0;
  return 0;
}

int sXeSSSend(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned char chlgbuf[256];
  memset(chlgbuf,0,sizeof(chlgbuf));

  BEGIN_READ(pbuf,iSize);
  PCHAR pname=READ_STRING();
  DWORD rsize=READ_LONG();
  DWORD xres=READ_LONG();
  DWORD yres=READ_LONG();
  DWORD esize=READ_LONG();

  //send response
  sprintf((char*)chlgbuf,"[sXe-I-SSR-Ready] %d",sstimer);
  pEngfuncs->pfnClientCmd((char*)chlgbuf);

  return 0;
}

int sXeSSSendD(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned char chlgbuf[256];
  memset(chlgbuf,0,sizeof(chlgbuf));

  BEGIN_READ(pbuf,iSize);
  DWORD psize=READ_LONG();
  DWORD lpart=READ_LONG();
  PCHAR buffer=READ_STRING();

  if(!lpart){
    //send response
    sprintf((char*)chlgbuf,"[sXe-I-SSR-Ready] %d",sstimer);
    pEngfuncs->pfnClientCmd((char*)chlgbuf);
  }
  return 0;
}

int sXeSSInfo(const char */*pszName*/, int iSize, void *pbuf){
  BEGIN_READ(pbuf,iSize);
  return 0;
}

int sXeAD(const char* /*pszName*/, int iSize, void *pbuf){
  BEGIN_READ(pbuf,iSize);
  float origin[3];
  origin[0]=READ_COORD();
  origin[1]=READ_COORD();
  origin[2]=READ_COORD();
  float volume=READ_COORD();
  float attenuation=READ_COORD();
  int fFlags=READ_SHORT();
  int pitch=READ_SHORT();
  int channel=READ_SHORT();
  char *sample=READ_STRING();
  pEngfuncs->pEventAPI->EV_PlaySound(-1,origin,channel,sample,volume,attenuation,fFlags,pitch);
  return 0;
}

int sXePing(const char* /*pszName*/, int /*iSize*/, void */*pbuf*/){
  return 0;
}

unsigned int hwidnum[4];
void RegenerateHWID(){
  char hwidbuf[64];size_t len=0;
  srand(time(NULL));
  hwidnum[0]=rand()<<16|rand();
  hwidnum[1]=rand()<<16|rand();
  hwidnum[2]=rand()<<16|rand();

  //hash hwid (SXE 13.1)
  sprintf(hwidbuf,"%u%u%u",hwidnum[0],hwidnum[1],hwidnum[2]);
  len=strlen(hwidbuf);
  if(len){
    unsigned int count=0,ultimo=0;
    char *anteult=&hwidbuf[len-1];
    do{
      int x=(((++count)&1)+1)*(*anteult-- - '0');
      if(x>9)
        x-=9;
      ultimo+=x;
    }while(len!=count);
    hwidnum[3]=10-ultimo%10;
  }else
    hwidnum[3]=0;

  //set HID info for if server try to compare...
  sprintf(hwidbuf,"%08X-%08X-%08X-%01d",hwidnum[0],hwidnum[1],hwidnum[2],hwidnum[3]);
  pEngfuncs->PlayerInfo_SetValueForKey("*HID",(const char*)hwidbuf);
}

int sXeCHN(const char* /*pszName*/, int iSize, void *pbuf){
  unsigned int i=0,j=0,tkey=0,tmp1,tmp2;
  unsigned char chlgbuf[256],respbuf[256],packed[256];
  size_t len;unsigned int longip=0;
  char hwidbuf[64];

  SXEProtocol ret;
  SXEUnknown2 hwid;
  SXEUnknown4 challenge;
  RC4_KEY key;

  BEGIN_READ(pbuf,iSize);
  char *newchlg=READ_STRING();

  memset(chlgbuf,0,256);
  memset(respbuf,0,256);
  memset(packed,0,256);

  Base64Decode(newchlg,chlgbuf,&len);
  SXEProtocol *prot=sxe___protocol__unpack(NULL,len,chlgbuf);

  if(prot){

    if(prot->p06unknown3||prot->p09unknown5||prot->p08unknown1){

      memset(&ret,0,sizeof(ret));
      sxe___protocol__init(&ret);

      //HWID Part! sxe 13.1
      if(prot->p08unknown1){

        memset(&hwid,0,sizeof(hwid));
        sxe___unknown2__init(&hwid);
        ret.p07unknown2=&hwid;

        srand(time(NULL));
        hwid.p01unknown1=hwidnum[0];
        hwid.p05unknown2=hwidnum[1];
        hwid.p04unknown6=hwidnum[2];
        hwid.p02unknown8=hwidnum[3];

        //get parameters order...
        i=8;
        gkey=prot->p08unknown1->p01unknown1;
        while(i){
          gkey=1103515245*gkey+12345;
          tmp1=1+((gkey>>16)%0x8000)%8;
          tmp2=0;
          for(j=1;j<=8;++j){
            if(tmp1==((tkey>>(4*j-4))&0xF)){
              tmp2=1;
              break;
            }
          }
          if(!tmp2)
            tkey|=tmp1<<(4*i-- -4);
        }

        unsigned int servertime=0,hasservertime=0;
        switch(tkey&0xF){//1 - key 2
          case 1:
            if(prot->p08unknown1->has_p02unknown2){
              servertime=prot->p08unknown1->p02unknown2;
              hasservertime=1;
            }
          break;
          case 2:
            if(prot->p08unknown1->has_p03unknown3){
              servertime=prot->p08unknown1->p03unknown3;
              hasservertime=1;
            }
          break;
          case 3:
            if(prot->p08unknown1->has_p04unknown4){
              servertime=prot->p08unknown1->p04unknown4;
              hasservertime=1;
            }
          break;
          case 4:
            if(prot->p08unknown1->has_p05unknown5){
              servertime=prot->p08unknown1->p05unknown5;
              hasservertime=1;
            }
          break;
          case 5:
            if(prot->p08unknown1->has_p06unknown6){
              servertime=prot->p08unknown1->p06unknown6;
              hasservertime=1;
            }
          break;
          case 6:
            if(prot->p08unknown1->has_p07unknown7){
              servertime=prot->p08unknown1->p07unknown7;
              hasservertime=1;
            }
          break;
          case 7:
            if(prot->p08unknown1->has_p08unknown8){
              servertime=prot->p08unknown1->p08unknown8;
              hasservertime=1;
            }
          break;
          case 8:
            if(prot->p08unknown1->has_p09unknown9){
              servertime=prot->p08unknown1->p09unknown9;
              hasservertime=1;
            }
          break;
        }

        gkey=0;unsigned int hasgkey=0;
        switch((tkey>>4)&0xF){//2 - key 3 - random...
          case 1:
            if(prot->p08unknown1->has_p02unknown2){
              gkey=prot->p08unknown1->p02unknown2;
              hasgkey=1;
            }
          break;
          case 2:
            if(prot->p08unknown1->has_p03unknown3){
              gkey=prot->p08unknown1->p03unknown3;
              hasgkey=1;
            }
          break;
          case 3:
            if(prot->p08unknown1->has_p04unknown4){
              gkey=prot->p08unknown1->p04unknown4;
              hasgkey=1;
            }
          break;
          case 4:
            if(prot->p08unknown1->has_p05unknown5){
              gkey=prot->p08unknown1->p05unknown5;
              hasgkey=1;
            }
          break;
          case 5:
            if(prot->p08unknown1->has_p06unknown6){
              gkey=prot->p08unknown1->p06unknown6;
              hasgkey=1;
            }
          break;
          case 6:
            if(prot->p08unknown1->has_p07unknown7){
              gkey=prot->p08unknown1->p07unknown7;
              hasgkey=1;
            }
          break;
          case 7:
            if(prot->p08unknown1->has_p08unknown8){
              gkey=prot->p08unknown1->p08unknown8;
              hasgkey=1;
            }
          break;
          case 8:
            if(prot->p08unknown1->has_p09unknown9){
              gkey=prot->p08unknown1->p09unknown9;
              hasgkey=1;
            }
          break;
        }
        hwid.p03unknown11=(((1103515245*gkey+12345)>>16)%0x8000);
        hwid.p11unknown4=hwid.p03unknown11^servertime;

        unsigned int protkey3=0,hasprotkey3=0;
        switch((tkey>>8)&0xF){//3
          case 1:
            if(prot->p08unknown1->has_p02unknown2){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p02unknown2;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p02unknown2;
              hasprotkey3=1;
            }
          break;
          case 2:
            if(prot->p08unknown1->has_p03unknown3){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p03unknown3;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p03unknown3;
              hasprotkey3=1;
            }
          break;
          case 3:
            if(prot->p08unknown1->has_p04unknown4){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p04unknown4;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p04unknown4;
              hasprotkey3=1;
            }
          break;
          case 4:
            if(prot->p08unknown1->has_p05unknown5){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p05unknown5;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p05unknown5;
              hasprotkey3=1;
            }
          break;
          case 5:
            if(prot->p08unknown1->has_p06unknown6){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p06unknown6;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p06unknown6;
              hasprotkey3=1;
            }
          break;
          case 6:
            if(prot->p08unknown1->has_p07unknown7){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p07unknown7;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p07unknown7;
              hasprotkey3=1;
            }
          break;
          case 7:
            if(prot->p08unknown1->has_p08unknown8){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p08unknown8;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p08unknown8;
              hasprotkey3=1;
            }
          break;
          case 8:
            if(prot->p08unknown1->has_p09unknown9){
              hwid.p06unknown3=prot->p08unknown1->p01unknown1^prot->p08unknown1->p09unknown9;
              hwid.has_p06unknown3=1;
              protkey3=prot->p08unknown1->p09unknown9;
              hasprotkey3=1;
            }
          break;
        }

        unsigned int protkey4=0,hasprotkey4=0;
        switch((tkey>>12)&0xF){//4 -
          case 1:
            if(prot->p08unknown1->has_p02unknown2){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p02unknown2;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p02unknown2;
              hasprotkey4=1;
            }
          break;
          case 2:
            if(prot->p08unknown1->has_p03unknown3){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p03unknown3;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p03unknown3;
              hasprotkey4=1;
            }
          break;
          case 3:
            if(prot->p08unknown1->has_p04unknown4){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p04unknown4;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p04unknown4;
              hasprotkey4=1;
            }
          break;
          case 4:
            if(prot->p08unknown1->has_p05unknown5){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p05unknown5;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p05unknown5;
              hasprotkey4=1;
            }
          break;
          case 5:
            if(prot->p08unknown1->has_p06unknown6){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p06unknown6;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p06unknown6;
              hasprotkey4=1;
            }
          break;
          case 6:
            if(prot->p08unknown1->has_p07unknown7){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p07unknown7;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p07unknown7;
              hasprotkey4=1;
            }
          break;
          case 7:
            if(prot->p08unknown1->has_p08unknown8){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p08unknown8;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p08unknown8;
              hasprotkey4=1;
            }
          break;
          case 8:
            if(prot->p08unknown1->has_p09unknown9){
              hwid.p07unknown5=prot->p08unknown1->p01unknown1&~prot->p08unknown1->p09unknown9;
              hwid.has_p07unknown5=1;
              protkey4=prot->p08unknown1->p09unknown9;
              hasprotkey4=1;
            }
          break;
        }

        unsigned int protkey5=0,hasprotkey5=0;
        switch((tkey>>16)&0xF){//5 -
          case 1:
            if(prot->p08unknown1->has_p02unknown2){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p02unknown2;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p02unknown2;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p02unknown2;
              hasprotkey5=1;
            }
          break;
          case 2:
            if(prot->p08unknown1->has_p03unknown3){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p03unknown3;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p03unknown3;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p03unknown3;
              hasprotkey5=1;
            }
          break;
          case 3:
            if(prot->p08unknown1->has_p04unknown4){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p04unknown4;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p04unknown4;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p04unknown4;
              hasprotkey5=1;
            }
          break;
          case 4:
            if(prot->p08unknown1->has_p05unknown5){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p05unknown5;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p05unknown5;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p05unknown5;
              hasprotkey5=1;
            }
          break;
          case 5:
            if(prot->p08unknown1->has_p06unknown6){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p06unknown6;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p06unknown6;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p06unknown6;
              hasprotkey5=1;
            }
          break;
          case 6:
            if(prot->p08unknown1->has_p07unknown7){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p07unknown7;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p07unknown7;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p07unknown7;
              hasprotkey5=1;
            }
          break;
          case 7:
            if(prot->p08unknown1->has_p08unknown8){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p08unknown8;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p08unknown8;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p08unknown8;
              hasprotkey5=1;
            }
          break;
          case 8:
            if(prot->p08unknown1->has_p09unknown9){
              if(hasprotkey4)
                hwid.p08unknown7=protkey4^prot->p08unknown1->p09unknown9;
              else
                hwid.p08unknown7=prot->p08unknown1->p01unknown1+prot->p08unknown1->p09unknown9;
              hwid.has_p08unknown7=1;
              protkey5=prot->p08unknown1->p09unknown9;
              hasprotkey5=1;
            }
          break;
        }

        unsigned int protkey6=0,hasprotkey6=0;
        switch((tkey>>20)&0xF){//6 -
          case 1:
            if(prot->p08unknown1->has_p02unknown2){
              protkey6=prot->p08unknown1->p02unknown2;
              hasprotkey6=1;
            }
          break;
          case 2:
            if(prot->p08unknown1->has_p03unknown3){
              protkey6=prot->p08unknown1->p03unknown3;
              hasprotkey6=1;
            }
          break;
          case 3:
            if(prot->p08unknown1->has_p04unknown4){
              protkey6=prot->p08unknown1->p04unknown4;
              hasprotkey6=1;
            }
          break;
          case 4:
            if(prot->p08unknown1->has_p05unknown5){
              protkey6=prot->p08unknown1->p05unknown5;
              hasprotkey6=1;
            }
          break;
          case 5:
            if(prot->p08unknown1->has_p06unknown6){
              protkey6=prot->p08unknown1->p06unknown6;
              hasprotkey6=1;
            }
          break;
          case 6:
            if(prot->p08unknown1->has_p07unknown7){
              protkey6=prot->p08unknown1->p07unknown7;
              hasprotkey6=1;
            }
          break;
          case 7:
            if(prot->p08unknown1->has_p08unknown8){
              protkey6=prot->p08unknown1->p08unknown8;
              hasprotkey6=1;
            }
          break;
          case 8:
            if(prot->p08unknown1->has_p09unknown9){
              protkey6=prot->p08unknown1->p09unknown9;
              hasprotkey6=1;
            }
          break;
        }

        unsigned char str[9],data[9];
        sprintf((char*)str,"%08X",hwid.p02unknown8);
        hwid.p10unknown10.len=strlen((char*)str);
        RC4_set_key(&key,4,(unsigned char*)&hwid.p11unknown4);
        RC4(&key,hwid.p10unknown10.len,str,data);
        hwid.p10unknown10.data=data;
      }

      //HWID Part! sxe 13.0
      if(prot->p09unknown5){
        memset(&hwid,0,sizeof(hwid));
        sxe___unknown2__init(&hwid);
        ret.p07unknown2=&hwid;

        srand(time(NULL));
        hwid.p01unknown1=rand();
        hwid.p05unknown2=rand()<<16|rand();
        hwid.p04unknown6=rand()<<16|rand();
        hwid.p11unknown4=38;
        hwid.p03unknown11=38;

        //CRC32 HWID (SXE 13.0)
        sprintf(hwidbuf,"%4.4X-%4.4X-%4.4X-%4.4X-%4.4X",LOWORD(hwid.p01unknown1),HIWORD(hwid.p05unknown2),LOWORD(hwid.p05unknown2),HIWORD(hwid.p04unknown6),LOWORD(hwid.p04unknown6));
        hwid.p02unknown8=CRC32(hwidbuf);
        sprintf(hwidbuf,"%s-%-4.4X-%-4.4X",hwidbuf,hwid.p02unknown8>>16,hwid.p02unknown8&0xFFFF);

        //set HID info for if server try to compare...
        pEngfuncs->PlayerInfo_SetValueForKey("*HID",(const char*)hwidbuf);

        unsigned char str[9],data[9];
        sprintf((char*)str,"%X",hwid.p02unknown8);
        hwid.p10unknown10.len=strlen((char*)str);
        RC4_set_key(&key,4,(unsigned char*)&hwid.p11unknown4);
        RC4(&key,hwid.p10unknown10.len,str,data);
        hwid.p10unknown10.data=data;
      }

      //Protocol Part!
      if(prot->p06unknown3){

        memset(&challenge,0,sizeof(challenge));
        sxe___unknown4__init(&challenge);
        ret.p05unknown4=&challenge;

        GetServerIP((unsigned char*)&longip);

        challenge.p05unknown1=13;
        challenge.p03unknown9=1;
        challenge.p01unknown11=1;

        challenge.p13unknown7.len=0;
        challenge.p13unknown7.data=(unsigned char*)"";
        challenge.has_p13unknown7=1;

        challenge.p07unknown3=longip^0x4E67C6A7;
        challenge.has_p07unknown3=1;

        //more...
        if(prot->p06unknown3->has_p04unknown7){
          challenge.p02unknown12=prot->p06unknown3->p03unknown2^prot->p06unknown3->p04unknown7;
          challenge.has_p02unknown12=1;
        }
      }

      sxe___protocol__pack(&ret,packed);
      len=sxe___protocol__get_packed_size(&ret);
      Base64Encode(packed,len,(char*)respbuf);

      //send response
      sprintf((char*)chlgbuf,"scr %s",respbuf);
      pEngfuncs->pfnClientCmd((char*)chlgbuf);
    }else if(prot->p11unknown11||prot->p12unknown12){
      //Screenshot Part!

      //sXeSS
      if(prot->p11unknown11){
        //p11unknown11->p01unknown1 (time)
        sstimer=prot->p11unknown11->p01unknown1;

        //send response -> ( realsize xres yres encodedsize time )
        sprintf((char*)chlgbuf,"[sXe-I-SS-Reply] %d %d %d %d %d",1,640,480,1,sstimer);

        pEngfuncs->pfnClientCmd((char*)chlgbuf);
      }

      //sXeSSD
      if(prot->p12unknown12){

        unsigned char part[256];

        DWORD epos=prot->p12unknown12->p02unknown1;
        DWORD size=prot->p12unknown12->p03unknown2;
        DWORD blastpart=prot->p12unknown12->p01unknown3;

        //send response -> ( bufsize buffer lastpart time )
        sprintf((char*)chlgbuf,"[sXe-I-SSD-Reply] %d %s %d %d",1,"0",blastpart,sstimer);
        pEngfuncs->pfnClientCmd((char*)chlgbuf);

        if(blastpart)
          sstimer=0;
      }
    }
    sxe___protocol__free_unpacked(prot,NULL);
  }
  return 0;
}

CHAR sxe_screenoff_buf[32];

DWORD WINAPI sXeThread(LPVOID /*lpParam*/){
  while(!FindOffsets())Sleep(100);
  //wait eng table is filled...
  while(!pEngfuncs||!pEngfuncs->pfnHookUserMsg||!pEngfuncs->pfnAddCommand||!pEngfuncs->pfnClientCmd||
    !pEngfuncs->pfnRegisterVariable||!pEngfuncs->pfnConsolePrint||!pEngfuncs->Con_IsVisible)Sleep(100);
  //start hooks...
  InitCRC32Table();
  pEngfuncs->pfnHookUserMsg("sXe-I",sXeI);
  pEngfuncs->pfnHookUserMsg("sXe-I-H",sXeIH);
  pEngfuncs->pfnHookUserMsg("sXe-SS",sXeSS);
  pEngfuncs->pfnHookUserMsg("sXe-SSD",sXeSSD);
  pEngfuncs->pfnHookUserMsg("sXe-SSSend",sXeSSSend);
  pEngfuncs->pfnHookUserMsg("sXe-SSSendD",sXeSSSendD);
  pEngfuncs->pfnHookUserMsg("sXe-SSInfo",sXeSSInfo);
  pEngfuncs->pfnHookUserMsg("sXe-AD",sXeAD);
  pEngfuncs->pfnHookUserMsg("sXe-ping",sXePing);
  pEngfuncs->pfnHookUserMsg("sXe-CHN",sXeCHN);
  //regenerate hwid...
  RegenerateHWID();
  return 0;
}

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID /*lpvReserved*/){
  switch(fdwReason){
    case DLL_PROCESS_ATTACH:
      g_hInstance=hInstance;
      hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)sXeThread,hInstance,0,NULL);
    break;
    case DLL_PROCESS_DETACH:
      TerminateThread(hThread,0);
      CloseHandle(hThread);
    break;
    default:
      return FALSE;
    break;
  }
  return TRUE;
}
