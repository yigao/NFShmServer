// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: server_to_client.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "server_to_client.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto_ff {

namespace {

const ::google::protobuf::EnumDescriptor* ServerToClientCmd_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_server_5fto_5fclient_2eproto() {
  protobuf_AddDesc_server_5fto_5fclient_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "server_to_client.proto");
  GOOGLE_CHECK(file != NULL);
  ServerToClientCmd_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_server_5fto_5fclient_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_server_5fto_5fclient_2eproto() {
}

void protobuf_AddDesc_server_5fto_5fclient_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026server_to_client.proto\022\010proto_ff\032\025yd_f"
    "ieldoptions.proto*\223\004\n\021ServerToClientCmd\022"
    " \n\034SERVER_TO_CLIENT_LOGIN_BEGIN\020\001\022\031\n\025SER"
    "VER_TO_CLIENT_PING\020\002\022!\n\035LOGIN_TO_CLIENT_"
    "ACCOUNT_LOGIN\020\003\022\037\n\033LOGIN_TO_CLIENT_SELEC"
    "T_ZONE\020\004\022\037\n\033ZONE_TO_CLIENT_GATEINFO_RSP\020"
    "\005\022\030\n\024LOGIN_TO_CLIENT_PING\020\006\022!\n\035SERVER_TO"
    "_CLIENT_QUEUE_RESULT\020\007\022\036\n\032SERVER_TO_CLIE"
    "NT_LOGIN_END\020\024\022\'\n#SERVER_TO_CLIENT_CENTE"
    "R_LOGIN_BEGIN\020\025\022\032\n\026CENTER_TO_CLIENT_LOGI"
    "N\020\026\022%\n!CENTER_TO_CLIENT_CREATE_CHARACTER"
    "\020\027\022\"\n\036CENTER_TO_CLIENT_DEL_CHARACTER\020\030\022\035"
    "\n\031CENTER_TO_CLIENT_LOGINOUT\020\031\022%\n!CENTER_"
    "TO_CLIENT_RECONNECT_RESUTL\020\032\022)\n%CENTER_T"
    "O_CLIENT_DEL_CHARACTER_CANCEL\020!", 591);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "server_to_client.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_server_5fto_5fclient_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_server_5fto_5fclient_2eproto {
  StaticDescriptorInitializer_server_5fto_5fclient_2eproto() {
    protobuf_AddDesc_server_5fto_5fclient_2eproto();
  }
} static_descriptor_initializer_server_5fto_5fclient_2eproto_;
const ::google::protobuf::EnumDescriptor* ServerToClientCmd_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerToClientCmd_descriptor_;
}
bool ServerToClientCmd_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 33:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
