#ifndef CRC32_H
#define CRC32_H

#include <windows.h>

VOID InitCRC32Table();
ULONG CRC32(LPCTSTR text);
BOOL Check(LPCTSTR text,ULONG crc);

unsigned char *Base64Decode(char const* encoded_string,unsigned char *result,unsigned int *out_len);
char *Base64Encode(unsigned char const* bytes_to_encode,unsigned int in_len,char *result);

#endif //CRC32_H
