#include "protbufsxe.h"

static const char fdescname[]="User-Agent: Mozilla/4.0\r\n";

/**********************************************************************************************************/
/*  SXE Unknown1                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown1__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, has_unknown1),
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, has_unknown2),
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, has_unknown3),
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, unknown4),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,5,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, has_unknown5),
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, unknown5),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,6,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown1, unknown6),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown1__field_indices_by_name[] = { 5, 0, 1, 2, 4, 3, };
static const ProtobufCIntRange sxe__unknown1__number_ranges[] ={{ 1, 0 }, { 0, 6 }};

void  sxe__unknown1__init(SXE__Unknown1 *message);

const ProtobufCMessageDescriptor sxe__unknown1__descriptor ={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown1),
  6,
  sxe__unknown1__field_descriptors,
  sxe__unknown1__field_indices_by_name,
  1,  sxe__unknown1__number_ranges,
  (ProtobufCMessageInit) sxe__unknown1__init,
  NULL,NULL,NULL
};

void sxe__unknown1__init(SXE__Unknown1 *message){
  static SXE__Unknown1 init_value = SXE__UNKNOWN1__INIT;
  *message = init_value;
}

size_t sxe__unknown1__get_packed_size(const SXE__Unknown1 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown1__pack(const SXE__Unknown1 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown1__pack_to_buffer(const SXE__Unknown1 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown1 * sxe__unknown1__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown1 *)protobuf_c_message_unpack(&sxe__unknown1__descriptor,allocator, len, data);
}

void sxe__unknown1__free_unpacked(SXE__Unknown1 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown2                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown2__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, has_unknown3),
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown4),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,5,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, has_unknown5),
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown5),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,6,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown6),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,7,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, has_unknown7),
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown7),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,8,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown8),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,9,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, has_unknown9),
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown9),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,10,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_BYTES,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown10),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,11,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown2, unknown11),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown2__field_indices_by_name[] = { 0, 7, 10, 5, 1, 2, 4, 6, 8, 9, 3 };
static const ProtobufCIntRange sxe__unknown2__number_ranges[] ={{ 1, 0 },{ 0,11 }};

void  sxe__unknown2__init(SXE__Unknown2 *message);

const ProtobufCMessageDescriptor sxe__unknown2__descriptor ={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown2),
  11,
  sxe__unknown2__field_descriptors,
  sxe__unknown2__field_indices_by_name,
  1,  sxe__unknown2__number_ranges,
  (ProtobufCMessageInit) sxe__unknown2__init,
  NULL,NULL,NULL
};

void sxe__unknown2__init(SXE__Unknown2 *message){
  static SXE__Unknown2 init_value = SXE__UNKNOWN2__INIT;
  *message = init_value;
}

size_t sxe__unknown2__get_packed_size(const SXE__Unknown2 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown2__pack(const SXE__Unknown2 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown2__pack_to_buffer(const SXE__Unknown2 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown2 * sxe__unknown2__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown2 *)protobuf_c_message_unpack(&sxe__unknown2__descriptor,allocator, len, data);
}

void sxe__unknown2__free_unpacked(SXE__Unknown2 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown3                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown3__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown1),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, key1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown3),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown4),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown4),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,5,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, loversion),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,6,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown6),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown6),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,7,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_key2),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, key2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,8,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, rand_),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,9,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown9),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown9),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,10,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown10),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown10),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,11,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, hiversion),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,12,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown12),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown12),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,13,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, has_unknown13),
    PROTOBUF_C_OFFSETOF(SXE__Unknown3, unknown13),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown3__field_indices_by_name[] = {10, 4, 1, 6, 0, 2, 3, 5, 8, 9, 11, 12, 7};
static const ProtobufCIntRange sxe__unknown3__number_ranges[] ={{ 1, 0 },{ 0,13 }};

void  sxe__unknown3__init(SXE__Unknown3 *message);

const ProtobufCMessageDescriptor sxe__unknown3__descriptor={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown3),
  13,
  sxe__unknown3__field_descriptors,
  sxe__unknown3__field_indices_by_name,
  1,  sxe__unknown3__number_ranges,
  (ProtobufCMessageInit) sxe__unknown3__init,
  NULL,NULL,NULL
};

void sxe__unknown3__init(SXE__Unknown3 *message){
  static SXE__Unknown3 init_value = SXE__UNKNOWN3__INIT;
  *message = init_value;
}

size_t sxe__unknown3__get_packed_size(const SXE__Unknown3 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown3__pack(const SXE__Unknown3 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown3__pack_to_buffer(const SXE__Unknown3 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown3 * sxe__unknown3__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown3 *)protobuf_c_message_unpack(&sxe__unknown3__descriptor,allocator, len, data);
}

void sxe__unknown3__free_unpacked(SXE__Unknown3 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown4                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown4__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown2),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown3),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown4),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown4),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,5,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown5),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,6,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown6),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown6),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,7,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown7),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown7),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,8,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown8),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown8),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,9,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown9),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,10,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown10),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown10),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,11,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown11),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,12,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown12),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown12),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,13,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_BYTES,
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, has_unknown13),
    PROTOBUF_C_OFFSETOF(SXE__Unknown4, unknown13),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown4__field_indices_by_name[] = {10, 11, 8, 4, 0, 12, 2, 1, 3, 5, 7, 9, 6};
static const ProtobufCIntRange sxe__unknown4__number_ranges[] ={{1, 0 },{ 0, 13 }};

void  sxe__unknown4__init(SXE__Unknown4 *message);

const ProtobufCMessageDescriptor sxe__unknown4__descriptor={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown4),
  13,
  sxe__unknown4__field_descriptors,
  sxe__unknown4__field_indices_by_name,
  1,  sxe__unknown4__number_ranges,
  (ProtobufCMessageInit) sxe__unknown4__init,
  NULL,NULL,NULL
};

void sxe__unknown4__init(SXE__Unknown4 *message){
  static SXE__Unknown4 init_value = SXE__UNKNOWN4__INIT;
  *message = init_value;
}

size_t sxe__unknown4__get_packed_size(const SXE__Unknown4 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown4__pack(const SXE__Unknown4 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown4__pack_to_buffer(const SXE__Unknown4 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown4 * sxe__unknown4__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown4 *)protobuf_c_message_unpack(&sxe__unknown4__descriptor,allocator, len, data);
}

void sxe__unknown4__free_unpacked(SXE__Unknown4 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown5                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown5__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown2),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown3),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown4),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown4),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,5,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown5),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown5),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,6,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown6),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown6),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,7,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown7),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown7),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,8,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown8),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown8),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,9,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, has_unknown9),
    PROTOBUF_C_OFFSETOF(SXE__Unknown5, unknown9),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown5__field_indices_by_name[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
static const ProtobufCIntRange sxe__unknown5__number_ranges[] ={{ 1, 0 },{ 0, 9 }};

void  sxe__unknown5__init(SXE__Unknown5 *message);

const ProtobufCMessageDescriptor sxe__unknown5__descriptor ={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown5),
  9,
  sxe__unknown5__field_descriptors,
  sxe__unknown5__field_indices_by_name,
  1,  sxe__unknown5__number_ranges,
  (ProtobufCMessageInit) sxe__unknown5__init,
  NULL,NULL,NULL    /* reserved[123] */
};

void sxe__unknown5__init(SXE__Unknown5 *message){
  static SXE__Unknown5 init_value = SXE__UNKNOWN5__INIT;
  *message = init_value;
}

size_t sxe__unknown5__get_packed_size(const SXE__Unknown5 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown5__pack(const SXE__Unknown5 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown5__pack_to_buffer(const SXE__Unknown5 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown5 * sxe__unknown5__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown5 *)protobuf_c_message_unpack(&sxe__unknown5__descriptor,allocator, len, data);
}

void sxe__unknown5__free_unpacked(SXE__Unknown5 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown6                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown6__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown6, has_unknown1),
    PROTOBUF_C_OFFSETOF(SXE__Unknown6, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown6, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown6, has_unknown3),
    PROTOBUF_C_OFFSETOF(SXE__Unknown6, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_BYTES,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown6, unknown4),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown6__field_indices_by_name[] = {3, 0, 2, 1};
static const ProtobufCIntRange sxe__unknown6__number_ranges[] ={{ 1, 0 },{ 0, 4 }};

void  sxe__unknown6__init(SXE__Unknown6 *message);

const ProtobufCMessageDescriptor sxe__unknown6__descriptor ={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown6),
  4,
  sxe__unknown6__field_descriptors,
  sxe__unknown6__field_indices_by_name,
  1,  sxe__unknown6__number_ranges,
  (ProtobufCMessageInit) sxe__unknown6__init,
  NULL,NULL,NULL
};

void sxe__unknown6__init(SXE__Unknown6 *message){
  static SXE__Unknown6 init_value = SXE__UNKNOWN6__INIT;
  *message = init_value;
}

size_t sxe__unknown6__get_packed_size(const SXE__Unknown6 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown6__pack(const SXE__Unknown6 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown6__pack_to_buffer(const SXE__Unknown6 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown6 * sxe__unknown6__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown6 *)protobuf_c_message_unpack(&sxe__unknown6__descriptor,allocator, len, data);
}

void sxe__unknown6__free_unpacked(SXE__Unknown6 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown7                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown7__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown7, has_unknown1),
    PROTOBUF_C_OFFSETOF(SXE__Unknown7, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_BYTES,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown7, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown7__field_indices_by_name[] = {1, 0};
static const ProtobufCIntRange sxe__unknown7__number_ranges[] ={{ 1, 0 },{ 0, 2 }};

void  sxe__unknown7__init(SXE__Unknown7 *message);

const ProtobufCMessageDescriptor sxe__unknown7__descriptor ={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown7),
  2,
  sxe__unknown7__field_descriptors,
  sxe__unknown7__field_indices_by_name,
  1,  sxe__unknown7__number_ranges,
  (ProtobufCMessageInit) sxe__unknown7__init,
  NULL,NULL,NULL
};

void sxe__unknown7__init(SXE__Unknown7 *message){
  static SXE__Unknown7 init_value = SXE__UNKNOWN7__INIT;
  *message = init_value;
}

size_t sxe__unknown7__get_packed_size(const SXE__Unknown7 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown7__pack(const SXE__Unknown7 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown7__pack_to_buffer(const SXE__Unknown7 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown7 * sxe__unknown7__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown7 *)protobuf_c_message_unpack(&sxe__unknown7__descriptor,allocator, len, data);
}

void sxe__unknown7__free_unpacked(SXE__Unknown7 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown8                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown8__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown8, has_unknown1),
    PROTOBUF_C_OFFSETOF(SXE__Unknown8, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_UINT32,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown8, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_BYTES,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown8, unknown3),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown8__field_indices_by_name[] = {2, 0, 1};
static const ProtobufCIntRange sxe__unknown8__number_ranges[] ={{ 1, 0 },{ 0, 3 }};

void  sxe__unknown8__init(SXE__Unknown8 *message);

const ProtobufCMessageDescriptor sxe__unknown8__descriptor ={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown8),
  3,
  sxe__unknown8__field_descriptors,
  sxe__unknown8__field_indices_by_name,
  1,  sxe__unknown8__number_ranges,
  (ProtobufCMessageInit) sxe__unknown8__init,
  NULL,NULL,NULL
};

void sxe__unknown8__init(SXE__Unknown8 *message){
  static SXE__Unknown8 init_value = SXE__UNKNOWN8__INIT;
  *message = init_value;
}

size_t sxe__unknown8__get_packed_size(const SXE__Unknown8 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown8__pack(const SXE__Unknown8 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown8__pack_to_buffer(const SXE__Unknown8 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown8 * sxe__unknown8__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown8 *)protobuf_c_message_unpack(&sxe__unknown8__descriptor,allocator, len, data);
}

void sxe__unknown8__free_unpacked(SXE__Unknown8 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Unknown9                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown9__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_UINT32,
    PROTOBUF_C_OFFSETOF(SXE__Unknown9, has_unknown1),
    PROTOBUF_C_OFFSETOF(SXE__Unknown9, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_BYTES,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown9, unknown2),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown9__field_indices_by_name[] = {1, 0};
static const ProtobufCIntRange sxe__unknown9__number_ranges[] ={{ 1, 0 },{ 0, 2 }};

void  sxe__unknown9__init(SXE__Unknown9 *message);

const ProtobufCMessageDescriptor sxe__unknown9__descriptor={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown9),
  2,
  sxe__unknown9__field_descriptors,
  sxe__unknown9__field_indices_by_name,
  1,  sxe__unknown9__number_ranges,
  (ProtobufCMessageInit) sxe__unknown9__init,
  NULL,NULL,NULL
};

void sxe__unknown9__init(SXE__Unknown9 *message){
  static SXE__Unknown9 init_value = SXE__UNKNOWN9__INIT;
  *message = init_value;
}

size_t sxe__unknown9__get_packed_size(const SXE__Unknown9 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown9__pack(const SXE__Unknown9 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown9__pack_to_buffer(const SXE__Unknown9 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown9 * sxe__unknown9__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown9 *)protobuf_c_message_unpack(&sxe__unknown9__descriptor,allocator, len, data);
}

void sxe__unknown9__free_unpacked(SXE__Unknown9 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}


/**********************************************************************************************************/
/*  SXE Unknown10                                                                                         */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__unknown10__field_descriptors[]={
  {
    fdescname,3,PROTOBUF_C_LABEL_REQUIRED,PROTOBUF_C_TYPE_BYTES,0,
    PROTOBUF_C_OFFSETOF(SXE__Unknown10, unknown1),
    NULL,NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__unknown10__field_indices_by_name[] = {0};

static const ProtobufCIntRange sxe__unknown10__number_ranges[] ={{ 1, 0 },{ 0, 1 }};

void  sxe__unknown10__init(SXE__Unknown10 *message);

const ProtobufCMessageDescriptor sxe__unknown10__descriptor={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Unknown10),
  1,
  sxe__unknown10__field_descriptors,
  sxe__unknown10__field_indices_by_name,
  1,  sxe__unknown10__number_ranges,
  (ProtobufCMessageInit) sxe__unknown10__init,
  NULL,NULL,NULL
};

void sxe__unknown10__init(SXE__Unknown10 *message){
  static SXE__Unknown10 init_value = SXE__UNKNOWN10__INIT;
  *message = init_value;
}

size_t sxe__unknown10__get_packed_size(const SXE__Unknown10 *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__unknown10__pack(const SXE__Unknown10 *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__unknown10__pack_to_buffer(const SXE__Unknown10 *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Unknown10 * sxe__unknown10__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Unknown10 *)protobuf_c_message_unpack(&sxe__unknown10__descriptor,allocator, len, data);
}

void sxe__unknown10__free_unpacked(SXE__Unknown10 *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  SXE Protocol                                                                                          */
/**********************************************************************************************************/

static const ProtobufCFieldDescriptor sxe__protocol__field_descriptors[]={
  {
    fdescname,1,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown1),
    &sxe__unknown1__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,2,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown2),
    &sxe__unknown2__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,3,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown3),
    &sxe__unknown3__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,4,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown4),
    &sxe__unknown4__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,5,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown5),
    &sxe__unknown5__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,6,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown6),
    &sxe__unknown6__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,7,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown7),
    &sxe__unknown7__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,8,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown8),
    &sxe__unknown8__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,9,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown9),
    &sxe__unknown9__descriptor,
    NULL,0,0,NULL,NULL
  },{
    fdescname,10,PROTOBUF_C_LABEL_OPTIONAL,PROTOBUF_C_TYPE_MESSAGE,0,
    PROTOBUF_C_OFFSETOF(SXE__Protocol, unknown10),
    &sxe__unknown10__descriptor,
    NULL,0,0,NULL,NULL
  },
};

static const unsigned sxe__protocol__field_indices_by_name[] = {8, 7, 6, 5, 3, 2, 1, 0, 4, 9};
static const ProtobufCIntRange sxe__protocol__number_ranges[] ={{ 1, 0 },{ 0, 10 }};

void  sxe__protocol__init(SXE__Protocol *message);

const ProtobufCMessageDescriptor sxe__protocol__descriptor={
  PROTOBUF_C_MESSAGE_DESCRIPTOR_MAGIC,
  fdescname,fdescname,fdescname,fdescname,
  sizeof(SXE__Protocol),
  10,
  sxe__protocol__field_descriptors,
  sxe__protocol__field_indices_by_name,
  1,
  sxe__protocol__number_ranges,
  (ProtobufCMessageInit) sxe__protocol__init,
  NULL,NULL,NULL
};

void sxe__protocol__init(SXE__Protocol *message){
  static SXE__Protocol init_value = SXE__PROTOCOL__INIT;
  *message = init_value;
}

size_t sxe__protocol__get_packed_size(const SXE__Protocol *message){
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}

size_t sxe__protocol__pack(const SXE__Protocol *message,uint8_t *out){
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}

size_t sxe__protocol__pack_to_buffer(const SXE__Protocol *message,ProtobufCBuffer *buffer){
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}

SXE__Protocol * sxe__protocol__unpack(ProtobufCAllocator *allocator,size_t len,const uint8_t *data){
  return (SXE__Protocol *)protobuf_c_message_unpack(&sxe__protocol__descriptor,allocator, len, data);
}

void sxe__protocol__free_unpacked(SXE__Protocol *message,ProtobufCAllocator *allocator){
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}

/**********************************************************************************************************/
/*  End SXE Protocol                                                                                      */
/**********************************************************************************************************/

