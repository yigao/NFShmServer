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

const ::google::protobuf::EnumDescriptor* Proto_SvrLogicMsgID_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_ServerInternalCmd_2eproto() {
  protobuf_AddDesc_ServerInternalCmd_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ServerInternalCmd.proto");
  GOOGLE_CHECK(file != NULL);
  Proto_SvrLogicMsgID_descriptor_ = file->enum_type(0);
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

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027ServerInternalCmd.proto\022\010proto_ff*\322\006\n\023"
    "Proto_SvrLogicMsgID\022\033\n\027NF_PTW_PLAYER_LOG"
    "IN_REQ\020d\022\033\n\027NF_WTP_PLAYER_LOGIN_RSP\020e\022\033\n"
    "\027NF_WTL_PLAYER_LOGIN_REQ\020f\022\033\n\027NF_LTW_PLA"
    "YER_LOGIN_RSP\020g\022\033\n\027NF_WTS_PLAYER_LOGIN_R"
    "EQ\020h\022\033\n\027NF_STW_PLAYER_LOGIN_RSP\020i\022\037\n\033NF_"
    "LTW_PLAYER_LOGOUT_NOTIFY\020j\022\037\n\033NF_WTL_PLA"
    "YER_LOGOUT_NOTIFY\020k\022\037\n\033NF_WTS_PLAYER_LOG"
    "OUT_NOTIFY\020l\022 \n\034NF_PTW_PLAYER_DISCONNECT"
    "_MSG\020n\022 \n\034NF_WTL_PLAYER_DISCONNECT_MSG\020o"
    "\022 \n\034NF_WTS_PLAYER_DISCONNECT_MSG\020p\022 \n\034NF"
    "_WTG_PLAYER_DISCONNECT_MSG\020q\022#\n\037NF_PTW_P"
    "LAYER_RECONNECT_MSG_REQ\020x\022#\n\037NF_WTP_PLAY"
    "ER_RECONNECT_MSG_RSP\020y\022#\n\037NF_WTL_PLAYER_"
    "RECONNECT_MSG_REQ\020z\022#\n\037NF_LTW_PLAYER_REC"
    "ONNECT_MSG_RSP\020{\022#\n\037NF_WTS_PLAYER_RECONN"
    "ECT_MSG_REQ\020|\022#\n\037NF_STW_PLAYER_RECONNECT"
    "_MSG_RSP\020}\022#\n\037NF_WTG_PLAYER_RECONNECT_MS"
    "G_REQ\020~\022#\n\037NF_GTW_PLAYER_RECONNECT_MSG_R"
    "SP\020\177\022\'\n\"NF_TS_QUERY_PLAYER_SIMPLE_DATA_R"
    "PC\020\202\001\022&\n!NF_LTS_PLAYER_ADD_BANK_JETTON_R"
    "PC\020\364\003\022)\n$NF_LTS_PLAYER_REDUCE_BANK_JETTO"
    "N_RPC\020\365\003", 888);
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
const ::google::protobuf::EnumDescriptor* Proto_SvrLogicMsgID_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Proto_SvrLogicMsgID_descriptor_;
}
bool Proto_SvrLogicMsgID_IsValid(int value) {
  switch(value) {
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 110:
    case 111:
    case 112:
    case 113:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 130:
    case 500:
    case 501:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
