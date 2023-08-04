// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerInternalCmd.proto

#ifndef PROTOBUF_ServerInternalCmd_2eproto__INCLUDED
#define PROTOBUF_ServerInternalCmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ServerInternalCmd_2eproto();
void protobuf_AssignDesc_ServerInternalCmd_2eproto();
void protobuf_ShutdownFile_ServerInternalCmd_2eproto();


enum Proto_SvrLogicMsgID {
  NF_PTW_PLAYER_LOGIN_REQ = 100,
  NF_WTP_PLAYER_LOGIN_RSP = 101,
  NF_WTL_PLAYER_LOGIN_REQ = 102,
  NF_LTW_PLAYER_LOGIN_RSP = 103,
  NF_WTS_PLAYER_LOGIN_REQ = 104,
  NF_STW_PLAYER_LOGIN_RSP = 105,
  NF_LTW_PLAYER_LOGOUT_NOTIFY = 106,
  NF_WTL_PLAYER_LOGOUT_NOTIFY = 107,
  NF_WTS_PLAYER_LOGOUT_NOTIFY = 108,
  NF_PTW_PLAYER_DISCONNECT_MSG = 110,
  NF_WTL_PLAYER_DISCONNECT_MSG = 111,
  NF_WTS_PLAYER_DISCONNECT_MSG = 112,
  NF_WTG_PLAYER_DISCONNECT_MSG = 113,
  NF_PTW_PLAYER_RECONNECT_MSG_REQ = 120,
  NF_WTP_PLAYER_RECONNECT_MSG_RSP = 121,
  NF_WTL_PLAYER_RECONNECT_MSG_REQ = 122,
  NF_LTW_PLAYER_RECONNECT_MSG_RSP = 123,
  NF_WTS_PLAYER_RECONNECT_MSG_REQ = 124,
  NF_STW_PLAYER_RECONNECT_MSG_RSP = 125,
  NF_LTG_PLAYER_RECONNECT_MSG_REQ = 126,
  NF_GTL_PLAYER_RECONNECT_MSG_RSP = 127,
  NF_GTW_REGISTER_ROOM_INFO_RPC = 130,
  NF_TS_QUERY_PLAYER_SIMPLE_DATA_RPC = 150,
  NF_LTS_PLAYER_ADD_BANK_JETTON_RPC = 500,
  NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC = 501,
  NF_GTL_COIN_QUERY_BALANCE_RPC = 550,
  NF_STS_GAME_PLAYER_LEAVE_GAME = 551
};
bool Proto_SvrLogicMsgID_IsValid(int value);
const Proto_SvrLogicMsgID Proto_SvrLogicMsgID_MIN = NF_PTW_PLAYER_LOGIN_REQ;
const Proto_SvrLogicMsgID Proto_SvrLogicMsgID_MAX = NF_STS_GAME_PLAYER_LEAVE_GAME;
const int Proto_SvrLogicMsgID_ARRAYSIZE = Proto_SvrLogicMsgID_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_SvrLogicMsgID_descriptor();
inline const ::std::string& Proto_SvrLogicMsgID_Name(Proto_SvrLogicMsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_SvrLogicMsgID_descriptor(), value);
}
inline bool Proto_SvrLogicMsgID_Parse(
    const ::std::string& name, Proto_SvrLogicMsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_SvrLogicMsgID>(
    Proto_SvrLogicMsgID_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_SvrLogicMsgID>() {
  return ::proto_ff::Proto_SvrLogicMsgID_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ServerInternalCmd_2eproto__INCLUDED
