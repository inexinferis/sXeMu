#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdio.h>
#include "protobuf-c/protobuf-c.h"

#define GETVALUE(b,o) ((DWORD)b+(DWORD)o)

FILE *fp=NULL;
DWORD dwFileSize=0;
LPSTR pszFileText=NULL;
LPCSTR prefix="sxe";

BOOL LoadFile(LPSTR pszFileName){
  HANDLE hFile;
  BOOL bSuccess = FALSE;
  hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
  if(hFile != INVALID_HANDLE_VALUE){
    dwFileSize = GetFileSize(hFile, NULL);
    if(dwFileSize != 0xFFFFFFFF){
      pszFileText = (LPSTR)GlobalAlloc(GPTR, dwFileSize + 1);
      if(pszFileText != NULL){
        DWORD dwRead;
        if(ReadFile(hFile, pszFileText, dwFileSize, &dwRead, NULL)){
          pszFileText[dwFileSize] = 0;
          bSuccess = TRUE;
        }
      }
    }
    CloseHandle(hFile);
  }
  return bSuccess;
}

VOID ProcessCMessageDescriptor(FILE *fp,PBYTE base,ProtobufCMessageDescriptor *md,int parent,int index){
  CHAR buffer[5000],type[64],*p=buffer;INT k;
  ZeroMemory(buffer,sizeof(buffer));
  ProtobufCFieldDescriptor* fields=(ProtobufCFieldDescriptor*)GETVALUE(base,md->fields);
  ProtobufCFieldDescriptor* field;ProtobufCMessageDescriptor *child;
  p+=sprintf(p,"\nmessage %s%0.2d__unknown__%0.2d {\n",prefix,parent+1,index+1);
  for(k=0;k<md->n_fields;k++){
    field=&fields[k];
    switch(field->type){
      case PROTOBUF_C_TYPE_INT32:
        strcpy(type,"int32");
      break;
      case PROTOBUF_C_TYPE_SINT32:
        strcpy(type,"sint32");
      break;
      case PROTOBUF_C_TYPE_SFIXED32:
        strcpy(type,"sfixed32");
      break;
      case PROTOBUF_C_TYPE_INT64:
        strcpy(type,"int64");
      break;
      case PROTOBUF_C_TYPE_SINT64:
        strcpy(type,"sint64");
      break;
      case PROTOBUF_C_TYPE_SFIXED64:
        strcpy(type,"sfixed64");
      break;
      case PROTOBUF_C_TYPE_UINT32:
        strcpy(type,"uint32");
      break;
      case PROTOBUF_C_TYPE_FIXED32:
        strcpy(type,"fixed32");
      break;
      case PROTOBUF_C_TYPE_UINT64:
        strcpy(type,"uint64");
      break;
      case PROTOBUF_C_TYPE_FIXED64:
        strcpy(type,"fixed64");
      break;
      case PROTOBUF_C_TYPE_FLOAT:
        strcpy(type,"float");
      break;
      case PROTOBUF_C_TYPE_DOUBLE:
        strcpy(type,"double");
      break;
      case PROTOBUF_C_TYPE_BOOL:
        strcpy(type,"bool");
      break;
      case PROTOBUF_C_TYPE_ENUM:
        strcpy(type,"enum");
      break;
      case PROTOBUF_C_TYPE_STRING:
        strcpy(type,"string");
      break;
      case PROTOBUF_C_TYPE_BYTES:
        strcpy(type,"bytes");
      break;
      case PROTOBUF_C_TYPE_MESSAGE:
        sprintf(type,"%s%0.2d__unknown__%0.2d",prefix,index+1,k+1);
      break;
      default:
        strcpy(type,"UNKNOWN");
      break;
    }
    p+=sprintf(p,"  %s %s p%0.2d_unknown_%0.2d=%d;\n",
      (field->label == PROTOBUF_C_LABEL_REQUIRED) ? "required" :
      (field->label == PROTOBUF_C_LABEL_OPTIONAL) ? "optional" : "",
      type,((unsigned*)GETVALUE(base,md->fields_sorted_by_name))[k],k+1,k+1);
  }
  p+=sprintf(p,"}\n");

  //process subimports
  for(k=0;k<md->n_fields;k++){
    field=&fields[k];
    if(field->type==PROTOBUF_C_TYPE_MESSAGE){
      child=(ProtobufCMessageDescriptor *)GETVALUE(base,field->descriptor);
      ProcessCMessageDescriptor(fp,base,child,index,k);
    }
  }

  fputs(buffer,fp);
}

int main(void){
  LPSTR file="";//file to analize
  DWORD offset=0;//Addres when protobuf starts
  LPSTR proto="results\\sxe.proto";
  if(LoadFile(file)){
    if(pszFileText){
      printf("File \"%s\" Loaded -> Offset %X\n",file,offset);
      fp=fopen(proto,"w");
      if(fp){
        printf("File \"%s\" Created\n",proto);
        PBYTE p=(PBYTE)pszFileText+offset;
        if(p){
          ProtobufCMessageDescriptor *md=(ProtobufCMessageDescriptor *)p;
          if(md->magic==PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC){
            puts("Processing Start");
            ProcessCMessageDescriptor(fp,pszFileText,md,-1,0);
          }else{
            printf("Error getting protocol buffer at offset %X\n",offset);
          }
        }
        puts("File Processed");
        fclose(fp);
      }else{
        printf("Error creating %s\n",proto);
      }
      GlobalFree(pszFileText);
      pszFileText=NULL;
    }else{
      printf("Error allocating memory\n");
    }
  }else{
    printf("Error opening %s\n",file);
  }
  system("pause");
  return 0;
}
