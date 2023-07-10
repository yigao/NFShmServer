// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClientServerCmd.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ClientServerCmd.pb.h"

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

const ::google::protobuf::EnumDescriptor* ClientServerCmd_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_ClientServerCmd_2eproto() {
  protobuf_AddDesc_ClientServerCmd_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ClientServerCmd.proto");
  GOOGLE_CHECK(file != NULL);
  ClientServerCmd_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ClientServerCmd_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_ClientServerCmd_2eproto() {
}

void protobuf_AddDesc_ClientServerCmd_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025ClientServerCmd.proto\022\010proto_ff\032\025yd_fi"
    "eldoptions.proto*\350\024\n\017ClientServerCmd\022\017\n\n"
    "E_CS_ERROR\020\350\007\022 \n\033NF_CS_Msg_Get_Room_Info"
    "_Req\020\363\007\022 \n\033NF_SC_Msg_Get_Room_Info_Rsp\020\364"
    "\007\022&\n!NF_CS_MSG_EnterGame_AUTO_JOIN_Req\020\365"
    "\007\022&\n!NF_CS_MSG_EnterGame_AUTO_JOIN_Rsp\020\366"
    "\007\022\032\n\025NF_CS_MSG_DeskListReq\020\367\007\022\032\n\025NF_SC_M"
    "SG_DeskListRsp\020\370\007\022\034\n\027NF_CS_MSG_ChairChec"
    "kReq\020\371\007\022\034\n\027NF_SC_MSG_ChairCheckRsp\020\372\007\022\033\n"
    "\026NF_CS_MSG_EnterGameReq\020\373\007\022\033\n\026NF_SC_MSG_"
    "EnterGameRsp\020\374\007\022\032\n\025NF_CS_MSG_ExitRoomReq"
    "\020\375\007\022\032\n\025NF_SC_MSG_ExitRoomRsp\020\376\007\022\032\n\025NF_CS"
    "_MSG_ExitGameReq\020\377\007\022\032\n\025NF_SC_MSG_ExitGam"
    "eRsp\020\200\010\022\034\n\027NF_CS_MSG_UserRecomeReq\020\201\010\022\034\n"
    "\027NF_SC_MSG_UserRecomeRsp\020\202\010\022\036\n\031NF_SC_MSG"
    "_GamePlayerLeave\020\204\010\022 \n\033NF_SC_MSG_MoneyCh"
    "angeNotify\020\206\010\022\036\n\031NF_SC_MSG_PaoMaDengNoti"
    "fy\020\207\010\022\034\n\027NF_CS_MSG_RedeemCodeReq\020\210\010\022\034\n\027N"
    "F_SC_MSG_RedeemCodeRsp\020\211\010\022\034\n\027NF_CS_Msg_R"
    "eConnect_REQ\020\355\007\022\034\n\027NF_SC_Msg_ReConnect_R"
    "SP\020\356\007\022\037\n\032NF_SC_Msg_KitPlayer_Notify\020\357\007\022\034"
    "\n\027NF_CS_Msg_HeartBeat_REQ\020\361\007\022\034\n\027NF_SC_Ms"
    "g_HeartBeat_RSP\020\362\007\022\036\n\031NF_CS_MSG_AccountL"
    "oginReq\020\315\010\022\036\n\031NF_SC_MSG_AccountLoginRsp\020"
    "\316\010\022\033\n\026NF_CS_MSG_UserLoginReq\020\317\010\022\033\n\026NF_SC"
    "_MSG_UserLoginRsp\020\320\010\022!\n\034NF_CS_MSG_Regist"
    "erAccountReq\020\321\010\022!\n\034NF_SC_MSG_RegisterAcc"
    "ountRsp\020\322\010\022+\n&NF_CS_MSG_LoginServer_Phon"
    "eAutoCodeReq\020\323\010\022+\n&NF_SC_MSG_LoginServer"
    "_PhoneAutoCodeRsp\020\324\010\022,\n\'NF_CS_MSG_LoginS"
    "erver_CheckPhoneCodeReq\020\325\010\022,\n\'NF_SC_MSG_"
    "LoginServer_CheckPhoneCodeRsp\020\326\010\022\"\n\035NF_C"
    "S_MSG_CHANGE_PASSWORD_REQ\020\327\010\022#\n\036NF_SC_MS"
    "G_CHANGE_PASSWORD_RESP\020\330\010\022+\n&NF_SC_MSG_L"
    "oginServer_NotifyPhoneCheck\020\331\010\022%\n NF_CS_"
    "MSG_PlayerPhoneAutoCodeReq\020\352\010\022%\n NF_SC_M"
    "SG_PlayerPhoneAutoCodeRsp\020\353\010\022&\n!NF_CS_MS"
    "G_PlayerCheckPhoneCodeReq\020\354\010\022&\n!NF_SC_MS"
    "G_PlayerCheckPhoneCodeRsp\020\355\010\022\034\n\027NF_CS_MS"
    "G_ChangeFaceReq\020\356\010\022\034\n\027NF_SC_MSG_ChangeFa"
    "ceRsp\020\357\010\022 \n\033NF_CS_MSG_ChangeNickNameReq\020"
    "\360\010\022 \n\033NF_SC_MSG_ChangeNickNameRsp\020\361\010\022\035\n\030"
    "NF_CS_MSG_BIND_PHONE_REQ\020\362\010\022\035\n\030NF_CS_MSG"
    "_BIND_PHONE_RSP\020\363\010\022,\n\'NF_CS_MSG_PHONE_CH"
    "ANG_BAND_PASSWORD_REQ\020\364\010\022,\n\'NF_CS_MSG_PH"
    "ONE_CHANG_BAND_PASSWORD_RSP\020\365\010\022%\n NF_CS_"
    "QUERY_USER_SIMPLE_DATA_REQ\020\256\t\022%\n NF_SC_Q"
    "UERY_USER_SIMPLE_DATA_RSP\020\257\t\022\034\n\027NF_CS_SN"
    "S_MAIL_LIST_REQ\020\376\010\022\034\n\027NF_SC_SNS_MAIL_LIS"
    "T_RSP\020\377\010\022\034\n\027NF_CS_SNS_MAIL_READ_REQ\020\200\t\022\034"
    "\n\027NF_SC_SNS_MAIL_READ_RSP\020\201\t\022\033\n\026NF_CS_SN"
    "S_MAIL_DEL_REQ\020\202\t\022\033\n\026NF_SC_SNS_MAIL_DEL_"
    "RSP\020\203\t\022!\n\034NF_SC_SNS_MAIL_AUTO_PUSH_RSP\020\204"
    "\t\022 \n\033NF_CS_SNS_MAIL_GET_ITEM_REQ\020\205\t\022 \n\033N"
    "F_SC_SNS_MAIL_GET_ITEM_RSP\020\206\t\022\034\n\027NF_CS_B"
    "ANK_GET_DATA_REQ\020\222\t\022\034\n\027NF_SC_BANK_GET_DA"
    "TA_RSP\020\223\t\022\036\n\031NF_CS_BANK_SAVE_MONEY_REQ\020\224"
    "\t\022\036\n\031NF_SC_BANK_SAVE_MONEY_RSP\020\225\t\022\035\n\030NF_"
    "CS_BANK_GET_MONEY_REQ\020\226\t\022\035\n\030NF_SC_BANK_G"
    "ET_MONEY_RSP\020\227\t\022 \n\033NF_CS_BANK_SET_PASSWO"
    "RD_REQ\020\230\t\022 \n\033NF_SC_BANK_SET_PASSWORD_RSP"
    "\020\231\t\022$\n\037NF_CS_BANK_GIVE_BANK_JETTON_REQ\020\232"
    "\t\022$\n\037NF_SC_BANK_GIVE_BANK_JETTON_RSP\020\233\t\022"
    ".\n)NF_SC_BANK_GIVE_BANK_JETTON_AUTO_PUSH"
    "_RSP\020\234\t\022\036\n\031NF_CS_BANK_GET_RECORD_REQ\020\235\t\022"
    "\036\n\031NF_SC_BANK_GET_RECORD_RSP\020\236\t\022\036\n\031NF_CS"
    "_GET_COMMON_RANK_REQ\020\260\t\022\036\n\031NF_CS_GET_COM"
    "MON_RANK_RSP\020\261\t\022\032\n\025CLIENT_SERVER_MAX_CMD"
    "\020\210\'", 2723);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ClientServerCmd.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ClientServerCmd_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ClientServerCmd_2eproto {
  StaticDescriptorInitializer_ClientServerCmd_2eproto() {
    protobuf_AddDesc_ClientServerCmd_2eproto();
  }
} static_descriptor_initializer_ClientServerCmd_2eproto_;
const ::google::protobuf::EnumDescriptor* ClientServerCmd_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ClientServerCmd_descriptor_;
}
bool ClientServerCmd_IsValid(int value) {
  switch(value) {
    case 1000:
    case 1005:
    case 1006:
    case 1007:
    case 1009:
    case 1010:
    case 1011:
    case 1012:
    case 1013:
    case 1014:
    case 1015:
    case 1016:
    case 1017:
    case 1018:
    case 1019:
    case 1020:
    case 1021:
    case 1022:
    case 1023:
    case 1024:
    case 1025:
    case 1026:
    case 1028:
    case 1030:
    case 1031:
    case 1032:
    case 1033:
    case 1101:
    case 1102:
    case 1103:
    case 1104:
    case 1105:
    case 1106:
    case 1107:
    case 1108:
    case 1109:
    case 1110:
    case 1111:
    case 1112:
    case 1113:
    case 1130:
    case 1131:
    case 1132:
    case 1133:
    case 1134:
    case 1135:
    case 1136:
    case 1137:
    case 1138:
    case 1139:
    case 1140:
    case 1141:
    case 1150:
    case 1151:
    case 1152:
    case 1153:
    case 1154:
    case 1155:
    case 1156:
    case 1157:
    case 1158:
    case 1170:
    case 1171:
    case 1172:
    case 1173:
    case 1174:
    case 1175:
    case 1176:
    case 1177:
    case 1178:
    case 1179:
    case 1180:
    case 1181:
    case 1182:
    case 1198:
    case 1199:
    case 1200:
    case 1201:
    case 5000:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
