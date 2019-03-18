#include "CRC32.h"
#include <ctype.h>

static const CHAR base64_chars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
ULONG crc32_table[256];

ULONG Reflect(ULONG ref,BYTE ch){
  ULONG value=0,i;
  for(i=1;i<(BYTE)(ch+1);i++){
    if(ref&1)value|=1<<(ch-i);
    ref>>=1;
  }
  return value;
}

VOID InitCRC32Table(){
  ULONG ulPolynomial=0x04c11db7,i,j;
  for(i=0;i<=0xFF;i++){
    crc32_table[i]=Reflect(i,8)<<24;
    for(j=0;j<8;j++)
      crc32_table[i]=(crc32_table[i]<<1)^(crc32_table[i]&(1<<31)?ulPolynomial:0);
    crc32_table[i]=Reflect(crc32_table[i],32);
  }
}

ULONG CRC32(LPCTSTR text){
  ULONG ulCRC=0xffffffff;
  PBYTE buffer=(PBYTE)text;
  for(;*buffer;buffer++)
    ulCRC=(ulCRC>>8)^crc32_table[(ulCRC&0xFF)^*buffer];
  return (ulCRC^0xffffffff);
}


BOOL Check(LPCTSTR text,ULONG crc){
  InitCRC32Table();
  return (CRC32(text)==crc);
}


static inline BOOL IsBase64(unsigned char c){
  return (isalnum(c)||(c=='+')||(c=='/'));
}

static inline int FindPosition(char const* str,int c){
  char *ret=strchr(str,c);
  if(ret)return (ret-str);
  return 0;
}

char *Base64Encode(unsigned char const* bytes_to_encode,unsigned int in_len,char *result){
  unsigned char char_array_3[3],char_array_4[4];
  char* ret=result;int i=0,j=0;
  if(bytes_to_encode&&result){
    while(in_len--){
      char_array_3[i++]=*(bytes_to_encode++);
      if(i==3){
        char_array_4[0]=(char_array_3[0]&0xfc)>>2;
        char_array_4[1]=((char_array_3[0]&0x03)<<4)+((char_array_3[1]&0xf0)>>4);
        char_array_4[2]=((char_array_3[1]&0x0f)<<2)+((char_array_3[2]&0xc0)>>6);
        char_array_4[3]=char_array_3[2]&0x3f;
        for(i=0;(i<4);i++)
          *ret++=base64_chars[char_array_4[i]];
        i=0;
      }
    }
    if(i){
      for(j=i;j<3;j++)
        char_array_3[j]='\0';
      char_array_4[0]=(char_array_3[0]&0xfc)>>2;
      char_array_4[1]=((char_array_3[0]&0x03)<<4)+((char_array_3[1]&0xf0)>>4);
      char_array_4[2]=((char_array_3[1]&0x0f)<<2)+((char_array_3[2]&0xc0)>>6);
      char_array_4[3]=char_array_3[2]&0x3f;
      for(j=0;(j<i+1);j++)
        *ret++=base64_chars[char_array_4[j]];
      while((i++<3))
        *ret++='=';
    }
  }
  return result;
}

unsigned char *Base64Decode(char const* encoded_string,unsigned char *result,unsigned int *out_len){
  unsigned char char_array_4[4], char_array_3[3];
  unsigned char *ret=result;int i=0,j=0,in_=0;
  if(encoded_string&&result){
    int in_len=strlen(encoded_string);
    while(in_len--&&(encoded_string[in_]!='=')&&IsBase64(encoded_string[in_])){
      char_array_4[i++]=encoded_string[in_];in_++;
      if(i==4){
        for(i=0;i<4;i++)
          char_array_4[i]=FindPosition(base64_chars,char_array_4[i]);
        char_array_3[0]=(char_array_4[0]<<2)+((char_array_4[1]&0x30)>>4);
        char_array_3[1]=((char_array_4[1]&0xf)<<4)+((char_array_4[2]& 0x3c)>>2);
        char_array_3[2]=((char_array_4[2]&0x3)<<6)+char_array_4[3];
        for(i=0;(i<3);i++)
          *ret++=char_array_3[i];
        i = 0;
      }
    }
    if(i){
      for(j=i;j<4;j++)
        char_array_4[j]=0;
      for(j=0;j<4;j++)
        char_array_4[j]=FindPosition(base64_chars,char_array_4[j]);
      char_array_3[0]=(char_array_4[0]<<2)+((char_array_4[1]&0x30)>>4);
      char_array_3[1]=((char_array_4[1]&0xf)<<4)+((char_array_4[2]&0x3c)>>2);
      char_array_3[2]=((char_array_4[2]&0x3)<<6)+char_array_4[3];
      for(j=0;(j<i-1);j++)
        *ret++=char_array_3[j];
    }
    if(out_len)
      *out_len=ret-result;
  }
  return result;
}
