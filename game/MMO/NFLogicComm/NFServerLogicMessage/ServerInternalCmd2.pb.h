// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerInternalCmd2.proto

#ifndef PROTOBUF_ServerInternalCmd2_2eproto__INCLUDED
#define PROTOBUF_ServerInternalCmd2_2eproto__INCLUDED

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
#include "Com.pb.h"
#include "ComDefine.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ServerInternalCmd2_2eproto();
void protobuf_AssignDesc_ServerInternalCmd2_2eproto();
void protobuf_ShutdownFile_ServerInternalCmd2_2eproto();


enum ServerInternalCmd2 {
  SERVER_INTERNAL2_BEGIN = 5000,
  WORLD_TO_LOGIC_GET_ROLE_LIST_REQ = 5001,
  LOGIC_TO_WORLD_GET_ROLE_LIST_RSP = 5002,
  WORLD_TO_LOGIC_CREATE_ROLE_INFO_REQ = 5003,
  LOGIC_TO_WORLD_CREATE_ROLE_INFO_RSP = 5004,
  WORLD_TO_PROXY_SERVER_BUS_ID_CHANGE_NOTIFY = 5005,
  WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT = 5006,
  WORLD_TO_LOGIC_LOGIN_REQ = 5007,
  LOGIC_TO_WORLD_LOGIN_RSP = 5008,
  WORLD_TO_SNS_LOGIN_REQ = 5009,
  SNS_TO_WORLD_LOGIN_RSP = 5010,
  GAME_TO_WORLD_REGISTER_MAP_REQ = 5011,
  WORLD_TO_GAME_RESITER_MAP_RSP = 5012,
  WORLD_TO_LOGIC_LOGIN_FINISH_NOTIFY = 5013,
  LOGIC_TO_WORLD_ENTER_SCENE_REQ = 5014,
  WORLD_TO_LOGIC_ENTER_SCENE_RSP = 5015,
  WORLD_TO_GAME_ENTER_SCENE_REQ = 5016,
  GAME_TO_WORLD_ENTER_SCENE_RSP = 5017,
  LOGIC_TO_WORLD_LEAVE_SCENE_REQ = 5018,
  WORLD_TO_LOGIC_LEAVE_SCENE_RSP = 5019,
  WORLD_TO_GAME_LEAVE_SCENE_REQ = 5020,
  GAME_TO_WORLD_LEAVE_SCENE_RSP = 5021,
  LOGIC_TO_WORLD_GET_MAP_INFO_REQ = 5022,
  WORLD_TO_LOGIC_GET_MAP_INFO_RSP = 5023
};
bool ServerInternalCmd2_IsValid(int value);
const ServerInternalCmd2 ServerInternalCmd2_MIN = SERVER_INTERNAL2_BEGIN;
const ServerInternalCmd2 ServerInternalCmd2_MAX = WORLD_TO_LOGIC_GET_MAP_INFO_RSP;
const int ServerInternalCmd2_ARRAYSIZE = ServerInternalCmd2_MAX + 1;

const ::google::protobuf::EnumDescriptor* ServerInternalCmd2_descriptor();
inline const ::std::string& ServerInternalCmd2_Name(ServerInternalCmd2 value) {
  return ::google::protobuf::internal::NameOfEnum(
    ServerInternalCmd2_descriptor(), value);
}
inline bool ServerInternalCmd2_Parse(
    const ::std::string& name, ServerInternalCmd2* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ServerInternalCmd2>(
    ServerInternalCmd2_descriptor(), name, value);
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
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::ServerInternalCmd2>() {
  return ::proto_ff::ServerInternalCmd2_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ServerInternalCmd2_2eproto__INCLUDED
