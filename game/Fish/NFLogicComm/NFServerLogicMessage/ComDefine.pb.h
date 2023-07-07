// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ComDefine.proto

#ifndef PROTOBUF_ComDefine_2eproto__INCLUDED
#define PROTOBUF_ComDefine_2eproto__INCLUDED

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
void  protobuf_AddDesc_ComDefine_2eproto();
void protobuf_AssignDesc_ComDefine_2eproto();
void protobuf_ShutdownFile_ComDefine_2eproto();


enum PingConfig {
  CLIENT_PING_INTERVAL = 9,
  SERVER_PING_INTERVAL = 9
};
bool PingConfig_IsValid(int value);
const PingConfig PingConfig_MIN = CLIENT_PING_INTERVAL;
const PingConfig PingConfig_MAX = CLIENT_PING_INTERVAL;
const int PingConfig_ARRAYSIZE = PingConfig_MAX + 1;

const ::google::protobuf::EnumDescriptor* PingConfig_descriptor();
inline const ::std::string& PingConfig_Name(PingConfig value) {
  return ::google::protobuf::internal::NameOfEnum(
    PingConfig_descriptor(), value);
}
inline bool PingConfig_Parse(
    const ::std::string& name, PingConfig* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PingConfig>(
    PingConfig_descriptor(), name, value);
}
enum Proto_CS_ErrorCode {
  ERR_CODE_SYSTEM_ERROR = -1,
  ERR_CODE_OK = 0,
  ERR_CODE_SYSTEM_TIMEOUT = 10000,
  ERR_CODE_SYSTEM_DATABASE_ERROR = 10001,
  ERR_CODE_MSG_PARAM_ERROR = 10002,
  ERR_CODE_ACCOUNT_PASSWORD_ERROR = 10101,
  ERR_CODE_NEED_RELOGIN = 10102,
  ERR_CODE_ACCOUNT_NOT_EXIST = 10103,
  ERR_CODE_PLAYER_NOT_EXIST = 10104,
  ERR_CODE_TOKEN_ERROR = 10106,
  ERR_CODE_TOKEN_TIMEOUT = 10107,
  ERR_CODE_ACCOUNT_ALREADY_EXIST_NO_RESITER = 10108,
  ERR_CODE_BIND_PHONE_ALREADY = 10109,
  ERR_CODE_PHONE_AUTO_CODE_ERROR = 10110,
  ERR_CODE_PHONE_AUTO_CODE_TIMEOUT = 10111,
  ERR_CODE_PHONE_SEND_TOO_MUCH = 10112,
  ERR_CODE_PHONE_NOT_RIGHT = 10113,
  ERR_CODE_PHONE_ALREADY_BIND = 10114,
  ERR_CODE_VISITOR_LOGIN_DEVICE_ERROR = 10115,
  ERR_CODE_PASSWORD_NOT_CHANGE = 10120,
  ERR_CODE_OTHER_PLACE_LOGIN_ACCOUNT = 10121,
  ERR_CODE_USER_IS_BAN = 10122,
  ERR_CODE_USER_IS_NO_TRANSFER = 10123,
  ERR_CODE_USER_AGENT_DEAD_CYCLE = 10124,
  ERR_CODE_PLAYER_OFFLINE = 10200,
  ERR_CODE_WORLD_MAX_PLAYER_COUNT = 10201,
  ERR_CODE_GAME_ROOM_NOT_ONLINE = 10202,
  ERR_CODE_GAME_ROOM_NOT_EXIST = 10203,
  ERR_CODE_MAIL_CANT_DEL_NO_READ = 10300,
  ERR_CODE_ROLE_MAIL_NOT_FIND = 10301,
  ERR_CODE_GET_MAIL_FAIL = 10304,
  ERR_CODE_READ_MAIL_FAIL = 10305,
  ERR_CODE_DEL_MAIL_FAIL = 10306,
  ERR_CODE_BANK_PASSWORD_NOT_RIGHT = 10400,
  ERR_CODE_BANK_PASSWORD_FORMAT_NOT_RIGHT = 10401,
  ERR_CODE_FACE_NOT_EXIST = 10402,
  ERR_CODE_BANK_GIVE_MONEY_NOT_TO_MYSELF = 10403,
  ERR_CODE_IN_GAMEING_NOT_BANK = 10404,
  ERR_CODE_FIRST_BIND_PHONE = 10405,
  ERR_CODE_BANK_NOT_VIP_ZHUAN_NOT_VIP = 10406,
  ERR_CODE_BANK_DRAW_MIN_JETTON = 10407,
  ERR_CODE_MODIFY_MONEY_LESS_ZERO = 10501,
  ERR_CODE_MODIFY_MONEY_TIMEOUT = 10502,
  ERR_CODE_PLAYER_ALREADY_BIND_PHONE = 10503,
  ERR_CODE_PLAYER_DONOT_CHANGE_PHONE = 10504,
  ERR_CODE_PLAYER_PHONE_AUTO_CODE_TOO_MUCH = 10505,
  ERR_CODE_EXIT_NOT_PERMITED_WHILE_PLAYING = 10600,
  EOT_CODE_REDEEM_CODE_USED = 10700,
  EOT_CODE_REDEEM_CODE_NOT_EXIST = 10701,
  EOT_CODE_REDEEM_CODE_UNREG_USER = 10702,
  EOT_CODE_REDEEM_CODE_HAS_USED = 10703,
  ERR_CODE_USER_MONEY_NOT_ENOUGH = 11000,
  ERR_CODE_USER_IN_GAMEING = 11001,
  ERR_CODE_CHAIR_HAS_OTHER_PLAYTER = 11002,
  ERR_CODE_CHAIR_NOT_RIGHT = 11003,
  ERR_CODE_USER_MONEY_TOO_MUCH = 11004,
  ERR_CODE_DESK_NOT_EXIST = 11005
};
bool Proto_CS_ErrorCode_IsValid(int value);
const Proto_CS_ErrorCode Proto_CS_ErrorCode_MIN = ERR_CODE_SYSTEM_ERROR;
const Proto_CS_ErrorCode Proto_CS_ErrorCode_MAX = ERR_CODE_DESK_NOT_EXIST;
const int Proto_CS_ErrorCode_ARRAYSIZE = Proto_CS_ErrorCode_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_CS_ErrorCode_descriptor();
inline const ::std::string& Proto_CS_ErrorCode_Name(Proto_CS_ErrorCode value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_CS_ErrorCode_descriptor(), value);
}
inline bool Proto_CS_ErrorCode_Parse(
    const ::std::string& name, Proto_CS_ErrorCode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_CS_ErrorCode>(
    Proto_CS_ErrorCode_descriptor(), name, value);
}
enum Proto_AccountType {
  E_VISITOR = 0,
  E_ACCOUNT = 1,
  E_WECHAT = 2,
  E_PHONE = 3,
  E_ROBOT = 10
};
bool Proto_AccountType_IsValid(int value);
const Proto_AccountType Proto_AccountType_MIN = E_VISITOR;
const Proto_AccountType Proto_AccountType_MAX = E_ROBOT;
const int Proto_AccountType_ARRAYSIZE = Proto_AccountType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_AccountType_descriptor();
inline const ::std::string& Proto_AccountType_Name(Proto_AccountType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_AccountType_descriptor(), value);
}
inline bool Proto_AccountType_Parse(
    const ::std::string& name, Proto_AccountType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_AccountType>(
    Proto_AccountType_descriptor(), name, value);
}
enum Proto_SexType {
  E_MALE = 0,
  E_FEMALE = 1
};
bool Proto_SexType_IsValid(int value);
const Proto_SexType Proto_SexType_MIN = E_MALE;
const Proto_SexType Proto_SexType_MAX = E_FEMALE;
const int Proto_SexType_ARRAYSIZE = Proto_SexType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_SexType_descriptor();
inline const ::std::string& Proto_SexType_Name(Proto_SexType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_SexType_descriptor(), value);
}
inline bool Proto_SexType_Parse(
    const ::std::string& name, Proto_SexType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_SexType>(
    Proto_SexType_descriptor(), name, value);
}
enum Proto_PlatType {
  E_PLAT_NONE = 0,
  E_PLAT_ANDROID = 1,
  E_PLAT_IOS = 2,
  E_PLAT_WP = 3,
  E_PLAT_MAX = 4
};
bool Proto_PlatType_IsValid(int value);
const Proto_PlatType Proto_PlatType_MIN = E_PLAT_NONE;
const Proto_PlatType Proto_PlatType_MAX = E_PLAT_MAX;
const int Proto_PlatType_ARRAYSIZE = Proto_PlatType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_PlatType_descriptor();
inline const ::std::string& Proto_PlatType_Name(Proto_PlatType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_PlatType_descriptor(), value);
}
inline bool Proto_PlatType_Parse(
    const ::std::string& name, Proto_PlatType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_PlatType>(
    Proto_PlatType_descriptor(), name, value);
}
enum Proto_NetworkType {
  E_NETWORK_2G = 0,
  E_NETWORK_3G = 1,
  E_NETWORK_4G = 2,
  E_NETWORK_WIFI = 3
};
bool Proto_NetworkType_IsValid(int value);
const Proto_NetworkType Proto_NetworkType_MIN = E_NETWORK_2G;
const Proto_NetworkType Proto_NetworkType_MAX = E_NETWORK_WIFI;
const int Proto_NetworkType_ARRAYSIZE = Proto_NetworkType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_NetworkType_descriptor();
inline const ::std::string& Proto_NetworkType_Name(Proto_NetworkType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_NetworkType_descriptor(), value);
}
inline bool Proto_NetworkType_Parse(
    const ::std::string& name, Proto_NetworkType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_NetworkType>(
    Proto_NetworkType_descriptor(), name, value);
}
enum Proto_PlayerCreateState {
  E_CREATE_SUCESS = 0,
  E_CREATE_REGIST_NAME = 1,
  E_CREATE_WAIT_NAME = 2
};
bool Proto_PlayerCreateState_IsValid(int value);
const Proto_PlayerCreateState Proto_PlayerCreateState_MIN = E_CREATE_SUCESS;
const Proto_PlayerCreateState Proto_PlayerCreateState_MAX = E_CREATE_WAIT_NAME;
const int Proto_PlayerCreateState_ARRAYSIZE = Proto_PlayerCreateState_MAX + 1;

const ::google::protobuf::EnumDescriptor* Proto_PlayerCreateState_descriptor();
inline const ::std::string& Proto_PlayerCreateState_Name(Proto_PlayerCreateState value) {
  return ::google::protobuf::internal::NameOfEnum(
    Proto_PlayerCreateState_descriptor(), value);
}
inline bool Proto_PlayerCreateState_Parse(
    const ::std::string& name, Proto_PlayerCreateState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Proto_PlayerCreateState>(
    Proto_PlayerCreateState_descriptor(), name, value);
}
enum PlayerStatus {
  PLAYER_STATUS_NONE = 0,
  PLAYER_STATUS_ONLINE = 1,
  PLAYER_STATUS_OFFLINE = 2,
  PLAYER_STATUS_LOGOUT = 3,
  PLAYER_STATUS_DEAD = 4
};
bool PlayerStatus_IsValid(int value);
const PlayerStatus PlayerStatus_MIN = PLAYER_STATUS_NONE;
const PlayerStatus PlayerStatus_MAX = PLAYER_STATUS_DEAD;
const int PlayerStatus_ARRAYSIZE = PlayerStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* PlayerStatus_descriptor();
inline const ::std::string& PlayerStatus_Name(PlayerStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    PlayerStatus_descriptor(), value);
}
inline bool PlayerStatus_Parse(
    const ::std::string& name, PlayerStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PlayerStatus>(
    PlayerStatus_descriptor(), name, value);
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
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::PingConfig>() {
  return ::proto_ff::PingConfig_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_CS_ErrorCode>() {
  return ::proto_ff::Proto_CS_ErrorCode_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_AccountType>() {
  return ::proto_ff::Proto_AccountType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_SexType>() {
  return ::proto_ff::Proto_SexType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_PlatType>() {
  return ::proto_ff::Proto_PlatType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_NetworkType>() {
  return ::proto_ff::Proto_NetworkType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::Proto_PlayerCreateState>() {
  return ::proto_ff::Proto_PlayerCreateState_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::PlayerStatus>() {
  return ::proto_ff::PlayerStatus_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ComDefine_2eproto__INCLUDED
