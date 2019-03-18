#ifndef _SXEPROTBUF_H
#define _SXEPROTBUF_H

#include "protobuf-c/protobuf-c.h"

/**********************************************************************************************************/
/*  SXE Unknown1                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown1{
  ProtobufCMessage base;
  protobuf_c_boolean has_unknown1;
  int32_t unknown1;
  protobuf_c_boolean has_unknown2;
  int32_t unknown2;
  protobuf_c_boolean has_unknown3;
  int32_t unknown3;
  int32_t unknown4;
  protobuf_c_boolean has_unknown5;
  int32_t unknown5;
  int32_t unknown6;
}SXE__Unknown1;

#define SXE__UNKNOWN1__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown1__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

void sxe__unknown1__init(SXE__Unknown1 *message);
size_t sxe__unknown1__get_packed_size(const SXE__Unknown1 *message);
size_t sxe__unknown1__pack(const SXE__Unknown1 *message,uint8_t *out);
size_t sxe__unknown1__pack_to_buffer(const SXE__Unknown1 *message,ProtobufCBuffer *buffer);
SXE__Unknown1 * sxe__unknown1__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown1__free_unpacked(SXE__Unknown1 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown2                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown2{
  ProtobufCMessage base;
  int32_t unknown1;
  int32_t unknown2;
  protobuf_c_boolean has_unknown3;
  int32_t unknown3;
  int32_t unknown4;
  protobuf_c_boolean has_unknown5;
  int32_t unknown5;
  int32_t unknown6;
  protobuf_c_boolean has_unknown7;
  int32_t unknown7;
  int32_t unknown8;
  protobuf_c_boolean has_unknown9;
  int32_t unknown9;
  ProtobufCBinaryData unknown10;
  int32_t unknown11;
}SXE__Unknown2;

#define SXE__UNKNOWN2__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown2__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0, NULL }, 0 }

void sxe__unknown2__init(SXE__Unknown2 *message);
size_t sxe__unknown2__get_packed_size(const SXE__Unknown2 *message);
size_t sxe__unknown2__pack(const SXE__Unknown2 *message,uint8_t *out);
size_t sxe__unknown2__pack_to_buffer(const SXE__Unknown2 *message,ProtobufCBuffer *buffer);
SXE__Unknown2 * sxe__unknown2__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown2__free_unpacked(SXE__Unknown2 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown3                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown3{
  ProtobufCMessage base;
  protobuf_c_boolean has_unknown1;
  int32_t unknown1;
  int32_t key1;
  protobuf_c_boolean has_unknown3;
  int32_t unknown3;
  protobuf_c_boolean has_unknown4;
  int32_t unknown4;
  int32_t loversion;
  protobuf_c_boolean has_unknown6;
  int32_t unknown6;
  protobuf_c_boolean has_key2;
  int32_t key2;
  int32_t rand_;
  protobuf_c_boolean has_unknown9;
  int32_t unknown9;
  protobuf_c_boolean has_unknown10;
  int32_t unknown10;
  int32_t hiversion;
  protobuf_c_boolean has_unknown12;
  int32_t unknown12;
  protobuf_c_boolean has_unknown13;
  int32_t unknown13;
}SXE__Unknown3;

#define SXE__UNKNOWN3__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown3__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

void sxe__unknown3__init(SXE__Unknown3 *message);
size_t sxe__unknown3__get_packed_size(const SXE__Unknown3 *message);
size_t sxe__unknown3__pack(const SXE__Unknown3 *message,uint8_t *out);
size_t sxe__unknown3__pack_to_buffer(const SXE__Unknown3 *message,ProtobufCBuffer *buffer);
SXE__Unknown3 * sxe__unknown3__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown3__free_unpacked(SXE__Unknown3 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown4                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown4{
  ProtobufCMessage base;
  int32_t unknown1;
  protobuf_c_boolean has_unknown2;
  int32_t unknown2;
  protobuf_c_boolean has_unknown3;
  int32_t unknown3;
  protobuf_c_boolean has_unknown4;
  int32_t unknown4;
  int32_t unknown5;
  protobuf_c_boolean has_unknown6;
  int32_t unknown6;
  protobuf_c_boolean has_unknown7;
  ProtobufCBinaryData unknown7;
  protobuf_c_boolean has_unknown8;
  int32_t unknown8;
  int32_t unknown9;
  protobuf_c_boolean has_unknown10;
  int32_t unknown10;
  int32_t unknown11;
  protobuf_c_boolean has_unknown12;
  int32_t unknown12;
  protobuf_c_boolean has_unknown13;
  ProtobufCBinaryData unknown13;
}SXE__Unknown4;

#define SXE__UNKNOWN4__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown4__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0 , NULL }, 0, 0, 0, 0, 0, 0, 0, 0, 0, { 0, NULL } }

void sxe__unknown4__init(SXE__Unknown4 *message);
size_t sxe__unknown4__get_packed_size(const SXE__Unknown4 *message);
size_t sxe__unknown4__pack(const SXE__Unknown4 *message,uint8_t *out);
size_t sxe__unknown4__pack_to_buffer(const SXE__Unknown4 *message,ProtobufCBuffer *buffer);
SXE__Unknown4 * sxe__unknown4__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown4__free_unpacked(SXE__Unknown4 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown5                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown5{
  ProtobufCMessage base;
  int32_t unknown1;
  protobuf_c_boolean has_unknown2;
  int32_t unknown2;
  protobuf_c_boolean has_unknown3;
  int32_t unknown3;
  protobuf_c_boolean has_unknown4;
  int32_t unknown4;
  protobuf_c_boolean has_unknown5;
  int32_t unknown5;
  protobuf_c_boolean has_unknown6;
  int32_t unknown6;
  protobuf_c_boolean has_unknown7;
  int32_t unknown7;
  protobuf_c_boolean has_unknown8;
  int32_t unknown8;
  protobuf_c_boolean has_unknown9;
  int32_t unknown9;
}SXE__Unknown5;

#define SXE__UNKNOWN5__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown5__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

void sxe__unknown5__init(SXE__Unknown5 *message);
size_t sxe__unknown5__get_packed_size(const SXE__Unknown5 *message);
size_t sxe__unknown5__pack(const SXE__Unknown5 *message,uint8_t *out);
size_t sxe__unknown5__pack_to_buffer(const SXE__Unknown5 *message,ProtobufCBuffer *buffer);
SXE__Unknown5 * sxe__unknown5__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown5__free_unpacked(SXE__Unknown5 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown6                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown6{
  ProtobufCMessage base;
  protobuf_c_boolean has_unknown1;
  int32_t unknown1;
  int32_t unknown2;
  protobuf_c_boolean has_unknown3;
  int32_t unknown3;
  ProtobufCBinaryData unknown4;
}SXE__Unknown6;

#define SXE__UNKNOWN6__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown6__descriptor) \
    , 0, 0, 0, 0, 0, { 0, NULL } }

void sxe__unknown6__init(SXE__Unknown6 *message);
size_t sxe__unknown6__get_packed_size(const SXE__Unknown6 *message);
size_t sxe__unknown6__pack(const SXE__Unknown6 *message,uint8_t *out);
size_t sxe__unknown6__pack_to_buffer(const SXE__Unknown6 *message,ProtobufCBuffer *buffer);
SXE__Unknown6 * sxe__unknown6__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown6__free_unpacked(SXE__Unknown6 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown7                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown7{
  ProtobufCMessage base;
  protobuf_c_boolean has_unknown1;
  int32_t unknown1;
  ProtobufCBinaryData unknown2;
}SXE__Unknown7;

#define SXE__UNKNOWN7__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown7__descriptor) \
    , 0, 0, { 0 , NULL } }

void sxe__unknown7__init(SXE__Unknown7 *message);
size_t sxe__unknown7__get_packed_size(const SXE__Unknown7 *message);
size_t sxe__unknown7__pack(const SXE__Unknown7 *message,uint8_t *out);
size_t sxe__unknown7__pack_to_buffer(const SXE__Unknown7 *message,ProtobufCBuffer *buffer);
SXE__Unknown7 * sxe__unknown7__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown7__free_unpacked(SXE__Unknown7 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown8                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown8{
  ProtobufCMessage base;
  protobuf_c_boolean has_unknown1;
  int32_t unknown1;
  int32_t unknown2;
  ProtobufCBinaryData unknown3;
}SXE__Unknown8;

#define SXE__UNKNOWN8__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown8__descriptor) \
    , 0, 0, 0, { 0, NULL } }

void sxe__unknown8__init(SXE__Unknown8 *message);
size_t sxe__unknown8__get_packed_size(const SXE__Unknown8 *message);
size_t sxe__unknown8__pack(const SXE__Unknown8 *message,uint8_t *out);
size_t sxe__unknown8__pack_to_buffer(const SXE__Unknown8 *message,ProtobufCBuffer *buffer);
SXE__Unknown8 * sxe__unknown8__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown8__free_unpacked(SXE__Unknown8 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown9                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Unknown9{
  ProtobufCMessage base;
  protobuf_c_boolean has_unknown1;
  int32_t unknown1;
  ProtobufCBinaryData unknown2;
}SXE__Unknown9;

#define SXE__UNKNOWN9__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown9__descriptor) \
    , 0, 0, { 0 , NULL } }

void sxe__unknown9__init(SXE__Unknown9 *message);
size_t sxe__unknown9__get_packed_size(const SXE__Unknown9 *message);
size_t sxe__unknown9__pack(const SXE__Unknown9 *message,uint8_t *out);
size_t sxe__unknown9__pack_to_buffer(const SXE__Unknown9 *message,ProtobufCBuffer *buffer);
SXE__Unknown9 * sxe__unknown9__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown9__free_unpacked(SXE__Unknown9 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Unknown10                                                                                         */
/**********************************************************************************************************/

typedef struct  _SXE__Unknown10{
  ProtobufCMessage base;
  ProtobufCBinaryData unknown1;
}SXE__Unknown10;

#define SXE__UNKNOWN10__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__unknown10__descriptor) \
    , { 0 , NULL } }

void sxe__unknown10__init(SXE__Unknown10 *message);
size_t sxe__unknown10__get_packed_size(const SXE__Unknown10 *message);
size_t sxe__unknown10__pack(const SXE__Unknown10 *message,uint8_t *out);
size_t sxe__unknown10__pack_to_buffer(const SXE__Unknown10 *message,ProtobufCBuffer *buffer);
SXE__Unknown10 * sxe__unknown10__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__unknown10__free_unpacked(SXE__Unknown10 *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  SXE Protocol                                                                                          */
/**********************************************************************************************************/

typedef struct _SXE__Protocol{
  ProtobufCMessage base;
  SXE__Unknown1 *unknown1;
  SXE__Unknown2 *unknown2;
  SXE__Unknown3 *unknown3;
  SXE__Unknown4 *unknown4;
  SXE__Unknown5 *unknown5;
  SXE__Unknown6 *unknown6;
  SXE__Unknown7 *unknown7;
  SXE__Unknown8 *unknown8;
  SXE__Unknown9 *unknown9;
  SXE__Unknown10 *unknown10;
}SXE__Protocol;

#define SXE__PROTOCOL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sxe__protocol__descriptor) \
    , NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }

void sxe__protocol__init(SXE__Protocol *message);
size_t sxe__protocol__get_packed_size(const SXE__Protocol *message);
size_t sxe__protocol__pack(const SXE__Protocol *message,uint8_t *out);
size_t sxe__protocol__pack_to_buffer(const SXE__Protocol *message,ProtobufCBuffer *buffer);
SXE__Protocol * sxe__protocol__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
void sxe__protocol__free_unpacked(SXE__Protocol *message,ProtobufCAllocator *allocator);

/**********************************************************************************************************/
/*  End SXE Protocol                                                                                      */
/**********************************************************************************************************/

#endif //_SXEPROTBUF_H
