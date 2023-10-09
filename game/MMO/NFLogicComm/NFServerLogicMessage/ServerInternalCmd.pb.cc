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

  ::proto_ff::protobuf_AddDesc_Com_2eproto();
  ::proto_ff::protobuf_AddDesc_ComDefine_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027ServerInternalCmd.proto\022\010proto_ff\032\tCom"
    ".proto\032\017ComDefine.proto*\237a\n\021ServerIntern"
    "alCmd\022\014\n\010SYS_PING\020\001\022\024\n\020SYS_CLOSE_SERVER\020"
    "\002\022\037\n\033SYS_REDIRECT_CLIENT_BY_GATE\020\n\022!\n\035SY"
    "S_REDIRECT_CLIENT_BY_CENTER\020\013\022!\n\035SYS_RED"
    "IRECT_SOCIAL_BY_CENTER\020\014\022 \n\034SYS_REDIRECT"
    "_LOGIC_BY_CENTER\020\r\022#\n\037SYS_REDIRECT_LOGIC"
    "_ID_BY_CENTER\020\016\022\037\n\033SYS_REDIRECT_SERVER_B"
    "Y_GATE\020\017\022\031\n\025LOGIC_REGISTER_CENTER\020\020\022\035\n\031L"
    "OGIC_REGISTER_CENTER_RSP\020\021\022\027\n\023LOGIC_REGI"
    "STER_GATE\020\022\022\033\n\027LOGIC_REGISTER_GATE_RSP\020\023"
    "\022\030\n\024CENTER_REGISTER_GATE\020\024\022\034\n\030CENTER_REG"
    "ISTER_GATE_RSP\020\025\022\026\n\022CENTER_REGISTER_DB\020\026"
    "\022\032\n\026SOCIAL_REGISTER_CENTER\020\027\022\036\n\032SOCIAL_R"
    "EGISTER_CENTER_RSP\020\030\022\034\n\030SOCIAL_QUERY_CEN"
    "TER_INFO\020\031\022 \n\034SOCIAL_QUERY_CENTER_INFO_R"
    "SP\020\032\022\026\n\022NOTIFY_LOGIC_STATE\020\033\022\016\n\nSY_LOG_R"
    "EQ\020\037\022\034\n\030NOTIFY_LOGIC_DATA_UPDATE\020 \022\031\n\025NO"
    "TIFY_MERGE_INFO_RSP\020!\022\025\n\020DB_ROLE_LIST_RE"
    "Q\020\255\002\022\025\n\020DB_ROLE_LIST_RSP\020\256\002\022\027\n\022DB_CREATE"
    "_ROLE_REQ\020\257\002\022\027\n\022DB_CREATE_ROLE_RSP\020\260\002\022\025\n"
    "\020DB_ROLE_INFO_REQ\020\261\002\022\025\n\020DB_ROLE_INFO_RSP"
    "\020\262\002\022\034\n\027DB_ROLE_INFO_UPDATE_REQ\020\263\002\022 \n\033NOT"
    "IFY_LOGIC_ENTER_GAME_REQ\020\264\002\022 \n\033NOTIFY_LO"
    "GIC_ENTER_GAME_RSP\020\265\002\022 \n\033NOTIFY_LOGIC_LE"
    "AVE_GAME_REQ\020\266\002\022 \n\033NOTIFY_LOGIC_LEAVE_GA"
    "ME_RSP\020\267\002\022\033\n\026NOTIFY_CENTER_KICK_REQ\020\270\002\022\033"
    "\n\026NOTIFY_GATE_ENTER_GAME\020\271\002\022\035\n\030NOTIFY_GA"
    "TE_CHANGE_LOGIC\020\272\002\022\033\n\026NOTIFY_GATE_LEAVE_"
    "GAME\020\273\002\022\037\n\032NOTIFY_GATE_RECONNECT_GAME\020\274\002"
    "\022\035\n\030NOTIFY_CENTER_DISCONNECT\020\275\002\022\034\n\027NOTIF"
    "Y_LOGIC_DISCONNECT\020\276\002\022\033\n\026NOTIFY_LOGIC_RE"
    "CONNECT\020\277\002\022\034\n\027DB_ROLE_SIMPLE_LIST_REQ\020\300\002"
    "\022\034\n\027DB_ROLE_SIMPLE_LIST_RSP\020\301\002\022\031\n\024SOCIAL"
    "_ROLE_INFO_REQ\020\302\002\022\031\n\024SOCIAL_ROLE_INFO_RS"
    "P\020\303\002\022\033\n\026SOCIAL_ROLE_INFO_EVENT\020\304\002\022\033\n\026SYN"
    "_ATTR_TO_CENTER_RSP\020\305\002\022\031\n\024DB_ROLE_CHG_NA"
    "ME_REQ\020\306\002\022\031\n\024DB_ROLE_CHG_NAME_RSP\020\307\002\022!\n\034"
    "NOTIFY_GATE_RETURN_ROLE_LIST\020\310\002\022$\n\037NOTIF"
    "Y_CENTER_RECONNECT_SUCCESS\020\311\002\022\023\n\016AO_FEI_"
    "LOG_REQ\020\312\002\022\"\n\035CENTER_CREATE_SCENE_REQ_LO"
    "GIC\020\221\003\022\"\n\035CENTER_CREATE_SCENE_RSP_LOGIC\020"
    "\222\003\022#\n\036SOCIAL_TO_CENTER_ADD_NEW_SCENE\020\223\003\022"
    "\037\n\032SOCIAL_TO_CENTER_DEL_SCENE\020\224\003\022&\n!LOGI"
    "C_NOTIFY_DESTORY_SCENE_CENTER\020\225\003\022*\n%LOGI"
    "C_CREATURE_TRANS_SCENE_REQ_CENTER\020\226\003\0221\n,"
    "CENTER_CREATURE_TRANS_SCENE_RSP_LOGIC_RE"
    "SULT\020\227\003\0222\n-CENTER_CREATURE_TRANS_SCENE_R"
    "SP_LOGIC_SUCCESS\020\230\003\022 \n\033DB_CREATURE_TRANS"
    "_SCENE_REQ\020\231\003\022 \n\033DB_CREATURE_TRANS_SCENE"
    "_RSP\020\232\003\022\034\n\027NOTIFY_ROLE_ENTER_SCENE\020\233\003\022\035\n"
    "\030NOTIFY_ROLE_CHANGE_LOGIC\020\234\003\022\032\n\025CL_MAIN_"
    "CITY_INFO_RSP\020\240\003\022\025\n\020CS_GenSceneIdReq\020\241\003\022"
    "\025\n\020CS_GenSceneIdRsp\020\242\003\022\027\n\022CS_NtLSCreateS"
    "cene\020\243\003\022\031\n\024CS_RegToCenterServer\020\244\003\022\022\n\rCS"
    "_DestroyReq\020\245\003\022 \n\033DBPROXY_PROTOCOL_MAIL_"
    "BEGIN\020\302\003\022-\n(DBPROXY_PROTOCOL_CHARACTER_M"
    "AIL_DATA_REQ\020\303\003\022-\n(DBPROXY_PROTOCOL_CHAR"
    "ACTER_MAIL_DATA_RSP\020\304\003\022%\n DBPROXY_PROTOC"
    "OL_MAX_MAIL_ID_REQ\020\305\003\022%\n DBPROXY_PROTOCO"
    "L_MAX_MAIL_ID_RSP\020\306\003\022/\n*DBPROXY_PROTOCOL"
    "_CHARACTER_DELETE_MAIL_REQ\020\307\003\022,\n\'DBPROXY"
    "_PROTOCOL_ALL_ZONE_MAIL_SAVE_REQ\020\310\003\022,\n\'D"
    "BPROXY_PROTOCOL_ALL_ZONE_MAIL_SAVE_RSP\020\311"
    "\003\022)\n$DBPROXY_PROTOCOL_ZONE_MAIL_TRANS_RE"
    "Q\020\312\003\022)\n$DBPROXY_PROTOCOL_ZONE_MAIL_TRANS"
    "_RSP\020\313\003\022#\n\036DBPROXY_PROTOCOL_MAIL_SAVE_RE"
    "Q\020\314\003\022#\n\036DBPROXY_PROTOCOL_MAIL_SAVE_RSP\020\315"
    "\003\022\'\n\"DBPROXY_PROTOCOL_WEB_MAIL_DATA_REQ\020"
    "\316\003\022\'\n\"DBPROXY_PROTOCOL_WEB_MAIL_DATA_RSP"
    "\020\317\003\022)\n$CENTER_SERVER_PROTOCOL_SEND_MAIL_"
    "REQ\020\320\003\022)\n$CENTER_SERVER_PROTOCOL_SEND_MA"
    "IL_RSP\020\321\003\0228\n3CENTER_SERVER_PROTOCOL_GET_"
    "MAIL_ATTACHMENT_TO_LOGIC\020\322\003\022.\n)CENTER_SE"
    "RVER_PROTOCOL_UPDATE_MAIL_NOTIFY\020\323\003\022<\n7C"
    "ENTER_SERVER_PROTOCOL_GET_ALL_MAIL_ATTAC"
    "HMENT_TO_LOGIC\020\324\003\022,\n\'CENTER_SERVER_PROTO"
    "COL_SEND_SYSTEM_MAIL\020\325\003\022.\n)CENTER_SERVER"
    "_PROTOCOL_SEND_MAIL_TO_LOGIC\020\326\003\022\036\n\031DBPRO"
    "XY_PROTOCOL_MAIL_END\020\337\003\022\037\n\032SERVER_INTERN"
    "AL_CHAT_BEGIN\020\340\003\022$\n\037CENTER_SERVER_PROTOC"
    "OL_CHAT_REQ\020\341\003\022.\n)CENTER_SERVER_PROTOCOL"
    "_GWSYSCHATMSGNOTIFY\020\342\003\022 \n\033SERVER_TO_SERV"
    "ER_CROSS_CHAT\020\343\003\022#\n\036CENTER_TO_LOGCI_VIR_"
    "FORBID_RSP\020\344\003\022\035\n\030SERVER_INTERNAL_CHAT_EN"
    "D\020\351\003\022\031\n\024NOTIFY_SERVER_GM_RSP\020\364\003\022!\n\034SERVE"
    "R_INTERNAL_FRIEND_BEGIN\020\247\004\022\035\n\030LOGIC_TO_C"
    "ENTER_ADD_HATE\020\250\004\022!\n\034LOGIC_TO_CENTER_KIL"
    "L_SOMEONE\020\251\004\022\037\n\032CENTER_TO_LOGIC_ADD_FRIE"
    "ND\020\252\004\022 \n\033LOGIC_TO_CENTER_GIVING_GIFT\020\253\004\022"
    "&\n!CENTER_TO_LOGIC_GIVING_GIFT_ERROR\020\254\004\022"
    "\'\n\"LOGIC_TO_CENTER_GIFT_GIVING_FLOWER\020\255\004"
    "\022(\n#CENTER_TO_LOGIC_GIVING_FLOWER_ERROR\020"
    "\256\004\022\030\n\023C2L_GIVE_FLOWER_RSP\020\257\004\022)\n$DBPROXY_"
    "PROTOCOL_ALL_FRIEND_DATA_REQ\020\260\004\022*\n%DBPRO"
    "XY_PROTOCOL_SAVE_FRIEND_DATA_REQ\020\261\004\022)\n$D"
    "BPROXY_PROTOCOL_ALL_FRIEND_DATA_RSP\020\262\004\022*"
    "\n%DBPROXY_PROTOCOL_SAVE_FRIEND_DATA_RSP\020"
    "\263\004\022/\n*DBPROXY_PROTOCOL_DELETE_FRIEND_DAT"
    "A_NOTIFY\020\264\004\022%\n DBPROXY_PROTOCOL_FRIEND_D"
    "ATA_REQ\020\265\004\022%\n DBPROXY_PROTOCOL_FRIEND_DA"
    "TA_RSP\020\266\004\022\037\n\032SERVER_INTERNAL_FRIEND_END\020"
    "\272\004\022\026\n\021L2C_ENTER_DUP_REQ\020\330\004\022\027\n\022L2C_CREATE"
    "_DUP_RSP\020\331\004\022\035\n\030L2C_DUP_STATE_CHG_NOTIFY\020"
    "\332\004\022#\n\036C2L_PULL_ROLE_ENTER_DUP_NOTIFY\020\333\004\022"
    "\037\n\032L2C_DUP_ROLE_ACTION_NOTIFY\020\334\004\022\026\n\021S2C_"
    "ENTER_DUP_REQ\020\335\004\022\026\n\021C2S_ENTER_DUP_RSP\020\336\004"
    "\022\036\n\031L2C_TOWER_RECV_RECORD_REQ\020\337\004\022\026\n\021L2S_"
    "ENTER_DUP_REQ\020\340\004\022\034\n\027L2S_DUP_TEAM_INVITE_"
    "REQ\020\341\004\022\036\n\031C2S_CREATE_DUP_RESULT_RSP\020\342\004\022\036"
    "\n\031S2C_NOTIFY_CHAR_ENTER_DUP\020\343\004\022\033\n\026NOTIFY"
    "_REBOT_ENTER_DUP\020\344\004\022\031\n\024L2S_DUP_TEAM_OPT_"
    "REQ\020\345\004\022$\n\037S2C_NOFITY_ROLE_REBOT_ENTER_DU"
    "P\020\346\004\022!\n\034C2L_ROLE_ROBOT_ENTER_DUP_REQ\020\347\004\022"
    "\027\n\022L2C_DUP_RESULT_RSP\020\350\004\022\036\n\031C2S_NOTIFY_D"
    "UP_FINISH_RSP\020\351\004\022\027\n\022S2L_CREATE_DUP_REQ\020\352"
    "\004\022\027\n\022L2S_CREATE_DUP_RSP\020\353\004\022\036\n\031S2L_NOTIFY"
    "_ROLE_ENTER_DUP\020\354\004\022\036\n\031L2S_NOTIFY_DUP_FIN"
    "ISH_RSP\020\355\004\022\033\n\026L2C_GHOST_DUP_RANK_REQ\020\356\004\022"
    "\"\n\035L2C_UPDATE_GHOST_DUP_RANK_REQ\020\357\004\022\034\n\027L"
    "2C_DUP_TEAM_INVITE_REQ\020\360\004\022\033\n\026C2S_TEAM_EN"
    "TER_DUP_REQ\020\361\004\022\026\n\021DB_GET_GLOBAL_REQ\020\212\005\022\026"
    "\n\021DB_GET_GLOBAL_RSP\020\213\005\022\026\n\021DB_SET_GLOBAL_"
    "REQ\020\214\005\022\030\n\023L2C_UPDATE_BOSS_REQ\020\224\005\022\027\n\022L2C_"
    "SYN_ATTENT_REQ\020\225\005\022\026\n\021L2C_KILL_BOSS_REQ\020\226"
    "\005\022\026\n\021L2C_BOSS_DROP_REQ\020\227\005\022\030\n\023L2S_UPDATE_"
    "BOSS_REQ\020\230\005\022\027\n\022C2S_SYN_ATTENT_REQ\020\231\005\022\027\n\022"
    "C2S_BOSS_LAYER_REQ\020\232\005\022\026\n\021L2S_KILL_BOSS_R"
    "EQ\020\233\005\022\027\n\022L2C_ATTENT_OPT_REQ\020\234\005\022\027\n\022C2S_AT"
    "TENT_OPT_REQ\020\235\005\022\026\n\021C2S_BOSS_DROP_REQ\020\236\005\022"
    "\025\n\020C2S_BOSS_LOG_REQ\020\237\005\022\030\n\023DB_ACT_GET_DAT"
    "A_REQ\020\274\005\022\030\n\023DB_ACT_GET_DATA_RSP\020\275\005\022\031\n\024DB"
    "_ACT_SAVE_DATA_REQ\020\276\005\022\031\n\024ACT_LS_INIT_DAT"
    "A_REQ\020\277\005\022\031\n\024ACT_LS_INIT_DATA_RSP\020\300\005\022\031\n\024A"
    "CT_CS_INIT_DATA_REQ\020\301\005\022\031\n\024ACT_CS_INIT_DA"
    "TA_RSP\020\302\005\022\032\n\025ACT_LS_PRE_FINISH_REQ\020\303\005\022\031\n"
    "\024ACT_CL_INIT_DATA_REQ\020\304\005\022\036\n\031SERVER_INTER"
    "AL_ARENA_BEIN\020\356\005\022$\n\037CENTER_TO_LOGIC_AREN"
    "A_RANK_INFO\020\357\005\022\'\n\"LOGIC_TO_CENTER_ARENA_"
    "CHALL_RESULT\020\360\005\022&\n!CENTER_TO_LOGIC_ARENA"
    "_RANK_CHANGE\020\361\005\022,\n\'LOGIC_TO_CENTER_ARENA"
    "_CAMP_CHALL_RESULT\020\362\005\022$\n\037LOGIC_TO_CENTER"
    "_ARENA_CHALL_REQ\020\363\005\022\037\n\032CENTER_TO_LOGIC_A"
    "DD_REWARD\020\364\005\022,\n\'CENTER_TO_LOGIC_ARENA_DU"
    "P_BATTLE_RESULT\020\365\005\022\035\n\030SERVER_INTERAL_ARE"
    "NA_END\020\240\006\022\027\n\022DB_ROLE_MIRROR_REQ\020\252\006\022\027\n\022DB"
    "_ROLE_MIRROR_RSP\020\253\006\022!\n\034SOCIAL_TO_CENTER_"
    "CREATE_TEAM\020\322\006\022$\n\037SOCIAL_TO_CENTER_CHAR_"
    "JOIN_TEAM\020\323\006\022$\n\037SOCIAL_TO_CENTER_CHAR_QU"
    "IT_TEAM\020\324\006\022!\n\034SOCIAL_TO_CENTER_TEAM_LEAD"
    "ER\020\325\006\022\"\n\035SOCIAL_TO_CENTER_TEAM_DISMISS\020\326"
    "\006\022%\n SOCIAL_TO_CENTER_TEAM_MEM_UPDATE\020\327\006"
    "\022\'\n\"CENTER_TO_LOGIC_UPDATE_TEAM_NOTIFY\020\330"
    "\006\022(\n#CENTER_TO_LOGIC_DISMISS_TEAM_NOTIFY"
    "\020\331\006\022/\n*CENTER_TO_LOGIC_UPDATE_TEAM_CLONE"
    "SS_NOTIFY\020\332\006\022%\n CENTER_TO_LOGIC_TEAM_INF"
    "O_NOTIFY\020\333\006\022\'\n\"LOGIC_TO_SOCIAL_TEAM_ROBO"
    "T_HP_SYNC\020\334\006\022 \n\033DB_FACTION_GET_ALL_DATA_"
    "REQ\020\205\007\022 \n\033DB_FACTION_GET_ALL_DATA_RSP\020\206\007"
    "\022\035\n\030DB_FACTION_SAVE_DATA_REQ\020\207\007\022\027\n\022DB_FA"
    "CTION_DEL_REQ\020\210\007\022\033\n\026FACTION_CL_ROLE_UPDA"
    "TE\020\211\007\022\026\n\021FACTION_LC_CREATE\020\212\007\022\035\n\030FACTION"
    "_CL_CREATE_RESULT\020\213\007\022\030\n\023FACTION_LC_CHG_N"
    "AME\020\214\007\022\037\n\032FACTION_CL_CHG_NAME_RESULT\020\215\007\022"
    "\036\n\031FACTION_CL_DISMISS_NOTIFY\020\216\007\022\034\n\027FACTI"
    "ON_LC_ADD_ATTR_REQ\020\217\007\022\034\n\027FACTION_LS_ANSW"
    "ER_COUNT\020\220\007\022\033\n\026FACTION_SL_ANSWER_RANK\020\221\007"
    "\022#\n\036FACTION_LS_ANSWER_CUR_RANK_REQ\020\222\007\022\033\n"
    "\026FACTION_SC_ANSWER_RANK\020\223\007\022\032\n\025FACTION_LS"
    "_ANSWER_END\020\224\007\022\034\n\027FACTION_LC_BEAST_FINIS"
    "H\020\225\007\022 \n\033FACTION_SC_ANSWER_FINAL_RSP\020\226\007\022#"
    "\n\036FACTION_CL_ANSWER_QUESTION_RSP\020\227\007\022\027\n\022L"
    "2C_SYN_ASSIST_REQ\020\230\007\022\030\n\023L2C_ASSIST_HELP_"
    "REQ\020\231\007\022\032\n\025C2L_ASSIST_CANCEL_REQ\020\232\007\022\027\n\022C2"
    "L_ASSIST_ACK_REQ\020\233\007\022\027\n\022C2L_ASSIST_RMV_RE"
    "Q\020\234\007\022\031\n\024L2C_ASSIST_THANK_REQ\020\235\007\022\033\n\026FACTI"
    "ON_LS_GUARD_COUNT\020\266\007\022\032\n\025FACTION_SL_GUARD"
    "_RANK\020\267\007\022\"\n\035FACTION_LS_GUARD_CUR_RANK_RE"
    "Q\020\270\007\022!\n\034FACTION_SL_GUARD_RANK_RESULT\020\271\007\022"
    "\031\n\024FACTION_LS_GUARD_END\020\272\007\022!\n\034FACTION_LC"
    "_GUARD_PLAYER_HARM\020\273\007\022!\n\034FACTION_CL_GUAR"
    "D_PLAYER_RANK\020\274\007\022\036\n\031FACTION_LC_GUARD_RAN"
    "K_END\020\275\007\022\032\n\025PAY_CL_DELIVER_NOTIFY\020\350\007\022\034\n\027"
    "PAY_LC_DELIVER_FAIL_RSP\020\351\007\022\017\n\nDB_PAY_REQ"
    "\020\352\007\022\017\n\nDB_PAY_RSP\020\353\007\022\024\n\017DB_PAY_SAVE_REQ\020"
    "\354\007\022\026\n\021DB_PAY_UPDATE_REQ\020\355\007\022\017\n\nDB_RED_REQ"
    "\020\233\010\022\017\n\nDB_RED_RSP\020\234\010\022\024\n\017DB_RED_SAVE_REQ\020"
    "\235\010\022\023\n\016DB_RED_DEL_REQ\020\236\010\022\024\n\017DB_RED_ROLE_R"
    "SP\020\240\010\022\024\n\017RED_LC_SEND_REQ\020\241\010\022\025\n\020RED_CL_FE"
    "TCH_RSP\020\242\010\022\031\n\024RED_CL_SEND_FAIL_RSP\020\243\010\022\024\n"
    "\017RED_LC_RECHARGE\020\244\010\022\033\n\026RED_CL_TRIGGER_RE"
    "D_RSP\020\245\010\022\024\n\017DB_COM_LOAD_REQ\020\257\010\022\024\n\017DB_COM"
    "_SAVE_REQ\020\260\010\022\023\n\016DB_COM_DEL_REQ\020\261\010\022\030\n\023DB_"
    "COM_LOAD_ALL_REQ\020\262\010\022\034\n\027NOTIFY_SERVER_ZON"
    "E_PLAN\020\314\010\022\037\n\032NOTIFY_SERVER_ZONE_PLAN_EX\020"
    "\315\010\022\026\n\021DB_LOAD_MARRY_REQ\020\340\010\022\026\n\021DB_LOAD_MA"
    "RRY_RSP\020\341\010\022\026\n\021DB_MARRY_SAVE_REQ\020\342\010\022\022\n\rC2"
    "L_MARRY_REQ\020\343\010\022\022\n\rL2C_MARRY_RSP\020\344\010\022\032\n\025C2"
    "L_NOTIFY_MARRY_CMPT\020\345\010\022\033\n\026L2C_UPDATE_MAR"
    "RY_BRIEF\020\346\010\022\027\n\022C2L_NOTIFY_DIVORCE\020\347\010\022\024\n\017"
    "C2L_EXPRESS_REQ\020\350\010\022\037\n\032L2C_NOTIFY_EXPRESS"
    "_SUCCESS\020\351\010\022\036\n\031C2L_NOTIFY_EXPRESS_TO_DST"
    "\020\352\010\022\031\n\024C2L_NOTIFY_MARRY_DST\020\353\010\022\033\n\026C2L_GL"
    "OBAL_EXPRESS_REQ\020\354\010\022!\n\034C2L_NOTIFY_MARRY_"
    "BUY_SUCCESS\020\355\010\022\034\n\027C2L_MARRY_RECV_DST_CAR"
    "D\020\370\010\022\035\n\030C2L_WEDDING_BUY_SEAT_REQ\020\371\010\022\035\n\030L"
    "2C_WEDDING_BUY_SEAT_RSP\020\372\010\022\034\n\027C2L_NOTIFY"
    "_WEDDING_TOUR\020\373\010\022\032\n\025C2L_WEDDING_TOUR_OVE"
    "R\020\374\010\022\020\n\013GVB_RoomReq\020\210\t\022\020\n\013GVB_RoomRsp\020\211\t"
    "\022\025\n\020GVB_RoomCloseReq\020\216\t\022\035\n\030LOGIC_TO_CENT"
    "ER_RANKDATA\020\234\t\022\037\n\032LOGIC_TO_CENTER_UPDATE"
    "RANK\020\235\t\022$\n\037LOGIC_TO_SOCIAL_RANK_UPDATE_R"
    "EQ\020\236\t\022#\n\036CENTER_TO_SOCIAL_RANK_INFO_REQ\020"
    "\237\t\022\035\n\030CENTER_TO_LOGIC_RANK_REQ\020\240\t\022\035\n\030LOG"
    "IC_TO_SOCIAL_RANK_REQ\020\241\t\022\"\n\035SOCIAL_TO_LO"
    "GIC_OPT_TITLE_REQ\020\242\t\022\'\n\"DBPROXY_PROTOCOL"
    "_ALL_RANK_DATA_REQ\020\244\t\022\'\n\"DBPROXY_PROTOCO"
    "L_ALL_RANK_DATA_RSP\020\245\t\022(\n#DBPROXY_PROTOC"
    "OL_SAVE_RANK_DATA_REQ\020\246\t\022*\n%DBPROXY_PROT"
    "OCOL_ALL_RANK_DATA_EX_REQ\020\247\t\022*\n%DBPROXY_"
    "PROTOCOL_ALL_RANK_DATA_EX_RSP\020\250\t\022+\n&DBPR"
    "OXY_PROTOCOL_SAVE_RANK_DATA_EX_REQ\020\251\t\022\031\n"
    "\024PVP_L2S_1V1_RANK_REQ\020\260\t\022\034\n\027PVP_S2L_1V1_"
    "RANK_NOTIFY\020\261\t\022\036\n\031PVP_L2S_1V1_SCORE_CHG_"
    "REQ\020\262\t\022\032\n\025PVP_L2S_1V1_MATCH_REQ\020\263\t\022\036\n\031PV"
    "P_L2S_1V1_RACE_INFO_REQ\020\264\t\022\036\n\031PVP_S2L_1V"
    "1_RACE_INFO_RSP\020\265\t\022\037\n\032SERVER_INTERAL_QUE"
    "RY_BEGIN\020\342\t\022*\n%CENTER_TO_LOGIC_CHARACTER"
    "_DETAIL_DATA\020\343\t\022*\n%LOGIC_TO_CENTER_CHARA"
    "CTER_DETAIL_DATA\020\344\t\022+\n&SERVET_TO_SERVER_"
    "QUERY_CHAR_DETAIL_REQ\020\345\t\022+\n&SERVET_TO_SE"
    "RVER_QUERY_CHAR_DETAIL_RSP\020\346\t\022)\n$SERVET_"
    "TO_SERVER_QUERY_CHAR_MINI_REQ\020\347\t\022)\n$SERV"
    "ET_TO_SERVER_QUERY_CHAR_MINI_RSP\020\350\t\0224\n/S"
    "ERVER_TO_SERVER_QUERY_CHAR_FUNC_FIGHT_DA"
    "TA_REQ\020\351\t\0224\n/SERVER_TO_SERVER_QUERY_CHAR"
    "_FUNC_FIGHT_DATA_RSP\020\352\t\022\035\n\030SERVER_INTERA"
    "L_QUERY_END\020\366\t\022 \n\033DB_FACTION_WAR_LOAD_AL"
    "L_RSP\020\224\n\022*\n%FACTION_WAR_S2C_PULL_RACE_FA"
    "CTION_REQ\020\225\n\022*\n%FACTION_WAR_C2S_PULL_RAC"
    "E_FACTION_RSP\020\226\n\022%\n FACTION_WAR_S2L_FACT"
    "ION_INFO_RSP\020\227\n\022\037\n\032FACTION_WAR_L2S_WAR_R"
    "ESULT\020\230\n\022$\n\037FACTION_WAR_S2C_RANK_REWARD_"
    "RSP\020\231\n\022\'\n\"FACTION_WAR_S2C_END_WIN_REWARD"
    "_RSP\020\232\n\022!\n\034FACTION_WAR_S2C_WIN_INFO_RSP\020"
    "\233\n\022 \n\033FACTION_WAR_S2C_DEL_WIN_RSP\020\234\n\022$\n\037"
    "FACTION_WAR_S2C_LEADER_INFO_REQ\020\235\n\022$\n\037FA"
    "CTION_WAR_C2S_LEADER_INFO_RSP\020\236\n\022%\n FACT"
    "ION_WAR_C2L_FETCH_WIN_REWARD\020\237\n\022 \n\033FACTI"
    "ON_WAR_C2S_WIN_DISMISS\020\240\n\022&\n!DAILY_WELFA"
    "RE_L2S_SAVE_RECORD_RSP\020\250\n\022#\n\036CENTER_TO_L"
    "OGIC_ACH_COMMON_ADD\020\251\n\022G\nBCENTER_TO_LOGI"
    "C_FIND_TREASURE_SI_SHENG_GET_SERVER_TOTA"
    "L_REWARD_REQ\020\253\n\0229\n4CENTER_TO_LOGIC_FIND_"
    "TREASURE_SI_SHENG_CHOUJIANG_REQ\020\254\n\022\021\n\014CL"
    "AN3_DB_RSP\020\310\n\022\021\n\014CLAN5_DB_RSP\020\311\n\022\024\n\017ROLE"
    "_3V3_DB_RSP\020\312\n\022\024\n\017ROLE_5V5_DB_RSP\020\313\n\022\025\n\020"
    "CLAN_SYS_OPT_REQ\020\314\n\022\027\n\022NOTIFY_PVP3_SEASO"
    "N\020\315\n\022\031\n\024NOTIFY_CLAN_SYN_RANK\020\316\n\022\031\n\024MODIF"
    "Y_CLAN_NAME_REQ\020\317\n\022\031\n\024MODIFY_CLAN_NAME_R"
    "SP\020\320\n\022\027\n\022C2S_CLAN3_RANK_REQ\020\321\n\022\036\n\031L2S_CL"
    "AN3_JOIN_MATHCH_REQ\020\322\n\022\032\n\025C2S_SYN_INIT_R"
    "ANK_REQ\020\323\n\022\037\n\032L2S_CLAN3_CANCEL_MATCH_REQ"
    "\020\324\n\022!\n\034NOTIFY_CLAN3_ACTION_WAIT_DUP\020\325\n\022 "
    "\n\033L2S_NOTIFY_CLAN3_DUP_RESULT\020\326\n\022#\n\036C2L_"
    "CLAN3_RECV_ROLE_REWARD_REQ\020\327\n\022\036\n\031S2C_SYN"
    "_CLAN3_ZERO_UPDATE\020\342\n\022\031\n\024C2L_CLAN3_REWAR"
    "D_REQ\020\343\n\022\036\n\031C2L_VERSION_ID_UPDATE_RSP\020\370\n"
    "\022\023\n\016LOAD_GOODS_REQ\020\375\n\022\027\n\022MARKET_DB_LOAD_"
    "RSP\020\376\n\022\031\n\024LOAD_MARKET_ROLE_RSP\020\377\n\022\024\n\017MAR"
    "KET_SAVE_REQ\020\200\013\022\023\n\016MARKET_DEL_REQ\020\201\013\022\033\n\026"
    "C2L_MARKET_ROLE_UP_REQ\020\202\013\022\033\n\026L2C_MARKET_"
    "ROLE_UP_RSP\020\203\013\022\027\n\022C2L_MARKET_VIE_REQ\020\204\013\022"
    "\027\n\022L2C_MARKET_VIE_RSP\020\205\013\022\027\n\022C2L_MARKET_B"
    "UY_REQ\020\207\013\022\027\n\022L2C_MARKET_BUY_RSP\020\210\013\022!\n\034FE"
    "ST_L2C_DIG_EGG_OPERATE_RSP\020\214\013\022\035\n\030FEST_L2"
    "C_DIG_EGG_LOG_REQ\020\215\013\022#\n\036FEST_L2C_RTURNAB"
    "LE_OPERATE_RSP\020\216\013\022\037\n\032FEST_L2C_RTURNABLE_"
    "LOG_REQ\020\217\013\022#\n\036FEST_L2C_DONATE_OPERATE_NO"
    "TIFY\020\220\013\022*\n%FEST_C2L_DONATE_GET_SERVER_RE"
    "WARD_REQ\020\221\013\022\036\n\031FEST_L2C_DRAWPIZE_LOG_REQ"
    "\020\222\013\0223\n.FEST_L2C_DRAWPIZE_CHOUJIANG_GET_S"
    "ERVER_NUM_REQ\020\223\013\0223\n.FEST_C2L_DRAWPIZE_CH"
    "OUJIANG_GET_SERVER_NUM_RSP\020\224\013\022&\n!FEST_C2"
    "L_FEST_SERVERRANK_SYNC_REQ\020\225\013\022&\n!FEST_C2"
    "L_FEST_SERVERRANK_SYNC_RSP\020\226\013\022\037\n\032L2C_FES"
    "T_BOSSKF_SIMPLE_REQ\020\227\013\022\033\n\026C2LFEST_BOSS_K"
    "F_NOTIFY\020\230\013\022\032\n\025C2LFEST_BOSS_INFO_REQ\020\231\013\022"
    " \n\033C2L_FEST_BOSS_FIRST_OPT_REQ\020\232\013\022\037\n\032FES"
    "T_S2S_XIYOU_SYNC_NOTIFY\020\245\013\022\036\n\031FEST_L2S_X"
    "IYOU_SYNC_LOGIC\020\246\013\022\037\n\032FEST_L2L_XIYOU_SYN"
    "C_FINISH\020\247\013\022$\n\037FEST_L2L_XIYOU_SYNC_FORCE"
    "_CLOSE\020\250\013\022\027\n\022SYN_WORLD_INFO_REQ\020\252\013\022\032\n\025SY"
    "N_WORLD_INFO_EX_REQ\020\253\013\022\035\n\030C2L_FMARRY_SYN"
    "_SCORE_REQ\020\254\013\022\035\n\030L2C_FMARRY_SYN_SCORE_RS"
    "P\020\255\013\022\033\n\026DB_CANDLE_LOAD_ALL_RSP\020\276\013\022\033\n\026S2C"
    "_CANDLE_RANK_REWARD\020\277\013\022\037\n\032L2S_CANDLE_ADD"
    "_HARM_NOTIFY\020\300\013\022\036\n\031S2L_CANDLE_TOTAL_HARM"
    "_RSP\020\301\013\022\030\n\023L2S_CANDLE_RANK_REQ\020\302\013\022\026\n\021L2C"
    "_ENTER_ACT_REQ\020\310\013\022\026\n\021C2L_ENTER_ACT_REQ\020\311"
    "\013\022\026\n\021L2C_ENTER_ACT_RSP\020\312\013\022\025\n\020NT_ENTER_AC"
    "T_RSP\020\313\013\022\027\n\022LC_TURN_HELPER_REQ\020\322\013\022\032\n\025CL_"
    "NOTIFY_TURN_HELPER\020\323\013\022\027\n\022LC_TURN_HELPER_"
    "RSP\020\324\013\022\034\n\027FACTION_MOYU_REWARD_REQ\020\334\013\022\034\n\027"
    "FACTION_MOYU_UPDATE_REQ\020\335\013\022\036\n\031FACTION_MO"
    "YU_ADD_HARM_REQ\020\336\013\022\031\n\024FACTION_SYN_MOYU_R"
    "EQ\020\337\013\022\032\n\025FACTION_PASS_MOYU_REQ\020\340\013\022\035\n\030CL_"
    "FACTION_MOYU_RANK_REQ\020\341\013\022\035\n\030CS_FACTION_M"
    "OYU_RANK_REQ\020\342\013\022\035\n\030CL_FACTION_MOYU_RECV_"
    "REQ\020\343\013\022\033\n\026L2C_SYN_PASS_YAOTA_REQ\020\346\013\022\034\n\027N"
    "OTIFY_DUP_TEAM_DIS_REQ\020\347\013\022#\n\036LC_NOTIFY_Y"
    "AOTA_FIRST_PASS_REQ\020\350\013\022\026\n\021CL_YAOTA_RECV_"
    "REQ\020\351\013\022\031\n\024SERVER_INTER_MAX_CMD\020\210\'", 12513);
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
    case 1:
    case 2:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 31:
    case 32:
    case 33:
    case 301:
    case 302:
    case 303:
    case 304:
    case 305:
    case 306:
    case 307:
    case 308:
    case 309:
    case 310:
    case 311:
    case 312:
    case 313:
    case 314:
    case 315:
    case 316:
    case 317:
    case 318:
    case 319:
    case 320:
    case 321:
    case 322:
    case 323:
    case 324:
    case 325:
    case 326:
    case 327:
    case 328:
    case 329:
    case 330:
    case 401:
    case 402:
    case 403:
    case 404:
    case 405:
    case 406:
    case 407:
    case 408:
    case 409:
    case 410:
    case 411:
    case 412:
    case 416:
    case 417:
    case 418:
    case 419:
    case 420:
    case 421:
    case 450:
    case 451:
    case 452:
    case 453:
    case 454:
    case 455:
    case 456:
    case 457:
    case 458:
    case 459:
    case 460:
    case 461:
    case 462:
    case 463:
    case 464:
    case 465:
    case 466:
    case 467:
    case 468:
    case 469:
    case 470:
    case 479:
    case 480:
    case 481:
    case 482:
    case 483:
    case 484:
    case 489:
    case 500:
    case 551:
    case 552:
    case 553:
    case 554:
    case 555:
    case 556:
    case 557:
    case 558:
    case 559:
    case 560:
    case 561:
    case 562:
    case 563:
    case 564:
    case 565:
    case 566:
    case 570:
    case 600:
    case 601:
    case 602:
    case 603:
    case 604:
    case 605:
    case 606:
    case 607:
    case 608:
    case 609:
    case 610:
    case 611:
    case 612:
    case 613:
    case 614:
    case 615:
    case 616:
    case 617:
    case 618:
    case 619:
    case 620:
    case 621:
    case 622:
    case 623:
    case 624:
    case 625:
    case 650:
    case 651:
    case 652:
    case 660:
    case 661:
    case 662:
    case 663:
    case 664:
    case 665:
    case 666:
    case 667:
    case 668:
    case 669:
    case 670:
    case 671:
    case 700:
    case 701:
    case 702:
    case 703:
    case 704:
    case 705:
    case 706:
    case 707:
    case 708:
    case 750:
    case 751:
    case 752:
    case 753:
    case 754:
    case 755:
    case 756:
    case 757:
    case 800:
    case 810:
    case 811:
    case 850:
    case 851:
    case 852:
    case 853:
    case 854:
    case 855:
    case 856:
    case 857:
    case 858:
    case 859:
    case 860:
    case 901:
    case 902:
    case 903:
    case 904:
    case 905:
    case 906:
    case 907:
    case 908:
    case 909:
    case 910:
    case 911:
    case 912:
    case 913:
    case 914:
    case 915:
    case 916:
    case 917:
    case 918:
    case 919:
    case 920:
    case 921:
    case 922:
    case 923:
    case 924:
    case 925:
    case 950:
    case 951:
    case 952:
    case 953:
    case 954:
    case 955:
    case 956:
    case 957:
    case 1000:
    case 1001:
    case 1002:
    case 1003:
    case 1004:
    case 1005:
    case 1051:
    case 1052:
    case 1053:
    case 1054:
    case 1056:
    case 1057:
    case 1058:
    case 1059:
    case 1060:
    case 1061:
    case 1071:
    case 1072:
    case 1073:
    case 1074:
    case 1100:
    case 1101:
    case 1120:
    case 1121:
    case 1122:
    case 1123:
    case 1124:
    case 1125:
    case 1126:
    case 1127:
    case 1128:
    case 1129:
    case 1130:
    case 1131:
    case 1132:
    case 1133:
    case 1144:
    case 1145:
    case 1146:
    case 1147:
    case 1148:
    case 1160:
    case 1161:
    case 1166:
    case 1180:
    case 1181:
    case 1182:
    case 1183:
    case 1184:
    case 1185:
    case 1186:
    case 1188:
    case 1189:
    case 1190:
    case 1191:
    case 1192:
    case 1193:
    case 1200:
    case 1201:
    case 1202:
    case 1203:
    case 1204:
    case 1205:
    case 1250:
    case 1251:
    case 1252:
    case 1253:
    case 1254:
    case 1255:
    case 1256:
    case 1257:
    case 1258:
    case 1270:
    case 1300:
    case 1301:
    case 1302:
    case 1303:
    case 1304:
    case 1305:
    case 1306:
    case 1307:
    case 1308:
    case 1309:
    case 1310:
    case 1311:
    case 1312:
    case 1320:
    case 1321:
    case 1323:
    case 1324:
    case 1352:
    case 1353:
    case 1354:
    case 1355:
    case 1356:
    case 1357:
    case 1358:
    case 1359:
    case 1360:
    case 1361:
    case 1362:
    case 1363:
    case 1364:
    case 1365:
    case 1366:
    case 1367:
    case 1378:
    case 1379:
    case 1400:
    case 1405:
    case 1406:
    case 1407:
    case 1408:
    case 1409:
    case 1410:
    case 1411:
    case 1412:
    case 1413:
    case 1415:
    case 1416:
    case 1420:
    case 1421:
    case 1422:
    case 1423:
    case 1424:
    case 1425:
    case 1426:
    case 1427:
    case 1428:
    case 1429:
    case 1430:
    case 1431:
    case 1432:
    case 1433:
    case 1434:
    case 1445:
    case 1446:
    case 1447:
    case 1448:
    case 1450:
    case 1451:
    case 1452:
    case 1453:
    case 1470:
    case 1471:
    case 1472:
    case 1473:
    case 1474:
    case 1480:
    case 1481:
    case 1482:
    case 1483:
    case 1490:
    case 1491:
    case 1492:
    case 1500:
    case 1501:
    case 1502:
    case 1503:
    case 1504:
    case 1505:
    case 1506:
    case 1507:
    case 1510:
    case 1511:
    case 1512:
    case 1513:
    case 5000:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
