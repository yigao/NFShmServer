// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerInternalCmd.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ServerInternalCmd.pb.h"

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

const ::google::protobuf::EnumDescriptor* ServerInternalCmd_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_ServerInternalCmd_2eproto() {
  protobuf_AddDesc_ServerInternalCmd_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ServerInternalCmd.proto");
  GOOGLE_CHECK(file != NULL);
  ServerInternalCmd_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ServerInternalCmd_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_ServerInternalCmd_2eproto() {
}

void protobuf_AddDesc_ServerInternalCmd_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::proto_ff::protobuf_AddDesc_common_5flogic_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027ServerInternalCmd.proto\022\010proto_ff\032\025yd_"
    "fieldoptions.proto\032\022common_logic.proto*x"
    "\n\021ServerInternalCmd\022\032\n\025SERVER_INTERNAL_B"
    "EGIN\020\254\002\022$\n\037WORLD_NOTIFY_PROXY_CHANGE_LOG"
    "IC\020\255\002\022!\n\034WORLD_TO_LOGIC_GET_ROLE_LIST\020\256\002", 200);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ServerInternalCmd.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ServerInternalCmd_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ServerInternalCmd_2eproto {
  StaticDescriptorInitializer_ServerInternalCmd_2eproto() {
    protobuf_AddDesc_ServerInternalCmd_2eproto();
  }
} static_descriptor_initializer_ServerInternalCmd_2eproto_;
const ::google::protobuf::EnumDescriptor* ServerInternalCmd_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServerInternalCmd_descriptor_;
}
bool ServerInternalCmd_IsValid(int value) {
  switch(value) {
    case 300:
    case 301:
    case 302:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)