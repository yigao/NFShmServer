// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ComDefine.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ComDefine.pb.h"

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

const ::google::protobuf::EnumDescriptor* PingConfig_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* Proto_CS_ErrorCode_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_ComDefine_2eproto() {
  protobuf_AddDesc_ComDefine_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ComDefine.proto");
  GOOGLE_CHECK(file != NULL);
  PingConfig_descriptor_ = file->enum_type(0);
  Proto_CS_ErrorCode_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ComDefine_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_ComDefine_2eproto() {
}

void protobuf_AddDesc_ComDefine_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017ComDefine.proto\022\010proto_ff\032\025yd_fieldopt"
    "ions.proto*D\n\nPingConfig\022\030\n\024CLIENT_PING_"
    "INTERVAL\020\t\022\030\n\024SERVER_PING_INTERVAL\020\t\032\002\020\001"
    "*\360\017\n\022Proto_CS_ErrorCode\022\"\n\025ERR_CODE_SYST"
    "EM_ERROR\020\377\377\377\377\377\377\377\377\377\001\022\017\n\013ERR_CODE_OK\020\000\022\034\n\027"
    "ERR_CODE_SYSTEM_TIMEOUT\020\220N\022#\n\036ERR_CODE_S"
    "YSTEM_DATABASE_ERROR\020\221N\022\035\n\030ERR_CODE_MSG_"
    "PARAM_ERROR\020\222N\022$\n\037ERR_CODE_ACCOUNT_PASSW"
    "ORD_ERROR\020\365N\022\032\n\025ERR_CODE_NEED_RELOGIN\020\366N"
    "\022\037\n\032ERR_CODE_ACCOUNT_NOT_EXIST\020\367N\022\036\n\031ERR"
    "_CODE_PLAYER_NOT_EXIST\020\370N\022\031\n\024ERR_CODE_TO"
    "KEN_ERROR\020\372N\022\033\n\026ERR_CODE_TOKEN_TIMEOUT\020\373"
    "N\022.\n)ERR_CODE_ACCOUNT_ALREADY_EXIST_NO_R"
    "ESITER\020\374N\022 \n\033ERR_CODE_BIND_PHONE_ALREADY"
    "\020\375N\022#\n\036ERR_CODE_PHONE_AUTO_CODE_ERROR\020\376N"
    "\022%\n ERR_CODE_PHONE_AUTO_CODE_TIMEOUT\020\377N\022"
    "!\n\034ERR_CODE_PHONE_SEND_TOO_MUCH\020\200O\022\035\n\030ER"
    "R_CODE_PHONE_NOT_RIGHT\020\201O\022 \n\033ERR_CODE_PH"
    "ONE_ALREADY_BIND\020\202O\022(\n#ERR_CODE_VISITOR_"
    "LOGIN_DEVICE_ERROR\020\203O\022!\n\034ERR_CODE_PASSWO"
    "RD_NOT_CHANGE\020\210O\022\'\n\"ERR_CODE_OTHER_PLACE"
    "_LOGIN_ACCOUNT\020\211O\022\031\n\024ERR_CODE_USER_IS_BA"
    "N\020\212O\022!\n\034ERR_CODE_USER_IS_NO_TRANSFER\020\213O\022"
    "#\n\036ERR_CODE_USER_AGENT_DEAD_CYCLE\020\214O\022\034\n\027"
    "ERR_CODE_PLAYER_OFFLINE\020\330O\022$\n\037ERR_CODE_W"
    "ORLD_MAX_PLAYER_COUNT\020\331O\022\"\n\035ERR_CODE_GAM"
    "E_ROOM_NOT_ONLINE\020\332O\022!\n\034ERR_CODE_GAME_RO"
    "OM_NOT_EXIST\020\333O\022#\n\036ERR_CODE_MAIL_CANT_DE"
    "L_NO_READ\020\274P\022 \n\033ERR_CODE_ROLE_MAIL_NOT_F"
    "IND\020\275P\022\033\n\026ERR_CODE_GET_MAIL_FAIL\020\300P\022\034\n\027E"
    "RR_CODE_READ_MAIL_FAIL\020\301P\022\033\n\026ERR_CODE_DE"
    "L_MAIL_FAIL\020\302P\022%\n ERR_CODE_BANK_PASSWORD"
    "_NOT_RIGHT\020\240Q\022,\n\'ERR_CODE_BANK_PASSWORD_"
    "FORMAT_NOT_RIGHT\020\241Q\022\034\n\027ERR_CODE_FACE_NOT"
    "_EXIST\020\242Q\022+\n&ERR_CODE_BANK_GIVE_MONEY_NO"
    "T_TO_MYSELF\020\243Q\022!\n\034ERR_CODE_IN_GAMEING_NO"
    "T_BANK\020\244Q\022\036\n\031ERR_CODE_FIRST_BIND_PHONE\020\245"
    "Q\022(\n#ERR_CODE_BANK_NOT_VIP_ZHUAN_NOT_VIP"
    "\020\246Q\022\"\n\035ERR_CODE_BANK_DRAW_MIN_JETTON\020\247Q\022"
    "$\n\037ERR_CODE_MODIFY_MONEY_LESS_ZERO\020\205R\022\"\n"
    "\035ERR_CODE_MODIFY_MONEY_TIMEOUT\020\206R\022\'\n\"ERR"
    "_CODE_PLAYER_ALREADY_BIND_PHONE\020\207R\022\'\n\"ER"
    "R_CODE_PLAYER_DONOT_CHANGE_PHONE\020\210R\022-\n(E"
    "RR_CODE_PLAYER_PHONE_AUTO_CODE_TOO_MUCH\020"
    "\211R\022-\n(ERR_CODE_EXIT_NOT_PERMITED_WHILE_P"
    "LAYING\020\350R\022\036\n\031EOT_CODE_REDEEM_CODE_USED\020\314"
    "S\022#\n\036EOT_CODE_REDEEM_CODE_NOT_EXIST\020\315S\022$"
    "\n\037EOT_CODE_REDEEM_CODE_UNREG_USER\020\316S\022\"\n\035"
    "EOT_CODE_REDEEM_CODE_HAS_USED\020\317S\022#\n\036ERR_"
    "CODE_USER_MONEY_NOT_ENOUGH\020\370U\022\035\n\030ERR_COD"
    "E_USER_IN_GAMEING\020\371U\022%\n ERR_CODE_CHAIR_H"
    "AS_OTHER_PLAYTER\020\372U\022\035\n\030ERR_CODE_CHAIR_NO"
    "T_RIGHT\020\373U\022!\n\034ERR_CODE_USER_MONEY_TOO_MU"
    "CH\020\374U\022\034\n\027ERR_CODE_DESK_NOT_EXIST\020\375U", 2155);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ComDefine.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ComDefine_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ComDefine_2eproto {
  StaticDescriptorInitializer_ComDefine_2eproto() {
    protobuf_AddDesc_ComDefine_2eproto();
  }
} static_descriptor_initializer_ComDefine_2eproto_;
const ::google::protobuf::EnumDescriptor* PingConfig_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PingConfig_descriptor_;
}
bool PingConfig_IsValid(int value) {
  switch(value) {
    case 9:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* Proto_CS_ErrorCode_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Proto_CS_ErrorCode_descriptor_;
}
bool Proto_CS_ErrorCode_IsValid(int value) {
  switch(value) {
    case -1:
    case 0:
    case 10000:
    case 10001:
    case 10002:
    case 10101:
    case 10102:
    case 10103:
    case 10104:
    case 10106:
    case 10107:
    case 10108:
    case 10109:
    case 10110:
    case 10111:
    case 10112:
    case 10113:
    case 10114:
    case 10115:
    case 10120:
    case 10121:
    case 10122:
    case 10123:
    case 10124:
    case 10200:
    case 10201:
    case 10202:
    case 10203:
    case 10300:
    case 10301:
    case 10304:
    case 10305:
    case 10306:
    case 10400:
    case 10401:
    case 10402:
    case 10403:
    case 10404:
    case 10405:
    case 10406:
    case 10407:
    case 10501:
    case 10502:
    case 10503:
    case 10504:
    case 10505:
    case 10600:
    case 10700:
    case 10701:
    case 10702:
    case 10703:
    case 11000:
    case 11001:
    case 11002:
    case 11003:
    case 11004:
    case 11005:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
