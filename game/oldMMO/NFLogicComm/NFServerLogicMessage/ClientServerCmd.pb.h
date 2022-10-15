// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClientServerCmd.proto

#ifndef PROTOBUF_ClientServerCmd_2eproto__INCLUDED
#define PROTOBUF_ClientServerCmd_2eproto__INCLUDED

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
#include "yd_fieldoptions.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ClientServerCmd_2eproto();
void protobuf_AssignDesc_ClientServerCmd_2eproto();
void protobuf_ShutdownFile_ClientServerCmd_2eproto();


enum ClientToServerCmd {
  CLIENT_TO_SERVER_LOGIN_BEGIN = 1,
  CLIENT_TO_LOGIN_PING = 2,
  CLIENT_TO_LOGIN_ACCOUNT_LOGIN = 3,
  CLIENT_TO_LOGIN_SELECT_ZONE = 4,
  CLIENT_TO_ZONE_GATEINFO_REQ = 5,
  CLIENT_TO_SERVER_LOGIN_END = 9,
  CLIENT_TO_LOGIC_PING = 10,
  CLIENT_TO_ZONE_PING = 11,
  CLIENT_TO_CENTER_LOGIN_BEGIN = 18,
  CLIENT_TO_CENTER_LOGIN = 19,
  CLIENT_TO_CENTER_CREATE_CHARACTER = 20,
  CLIENT_TO_CENTER_DEL_CHARACTER = 21,
  CLIENT_MAX_CMD_ID_VALUE = 5000
};
bool ClientToServerCmd_IsValid(int value);
const ClientToServerCmd ClientToServerCmd_MIN = CLIENT_TO_SERVER_LOGIN_BEGIN;
const ClientToServerCmd ClientToServerCmd_MAX = CLIENT_MAX_CMD_ID_VALUE;
const int ClientToServerCmd_ARRAYSIZE = ClientToServerCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientToServerCmd_descriptor();
inline const ::std::string& ClientToServerCmd_Name(ClientToServerCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientToServerCmd_descriptor(), value);
}
inline bool ClientToServerCmd_Parse(
    const ::std::string& name, ClientToServerCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientToServerCmd>(
    ClientToServerCmd_descriptor(), name, value);
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
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::ClientToServerCmd>() {
  return ::proto_ff::ClientToServerCmd_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ClientServerCmd_2eproto__INCLUDED