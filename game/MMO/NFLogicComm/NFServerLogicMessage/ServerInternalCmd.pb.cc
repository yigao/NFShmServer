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
  ::proto_ff::protobuf_AddDesc_Com_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\027ServerInternalCmd.proto\022\010proto_ff\032\025yd_"
    "fieldoptions.proto\032\022common_logic.proto\032\t"
    "Com.proto*\3621\n\021ServerInternalCmd\022\014\n\010SYS_P"
    "ING\020\001\022\024\n\020SYS_CLOSE_SERVER\020\002\022\037\n\033SYS_REDIR"
    "ECT_CLIENT_BY_GATE\020\n\022!\n\035SYS_REDIRECT_CLI"
    "ENT_BY_CENTER\020\013\022!\n\035SYS_REDIRECT_SOCIAL_B"
    "Y_CENTER\020\014\022 \n\034SYS_REDIRECT_LOGIC_BY_CENT"
    "ER\020\r\022#\n\037SYS_REDIRECT_LOGIC_ID_BY_CENTER\020"
    "\016\022\037\n\033SYS_REDIRECT_SERVER_BY_GATE\020\017\022\031\n\025LO"
    "GIC_REGISTER_CENTER\020\020\022\035\n\031LOGIC_REGISTER_"
    "CENTER_RSP\020\021\022\027\n\023LOGIC_REGISTER_GATE\020\022\022\033\n"
    "\027LOGIC_REGISTER_GATE_RSP\020\023\022\030\n\024CENTER_REG"
    "ISTER_GATE\020\024\022\034\n\030CENTER_REGISTER_GATE_RSP"
    "\020\025\022\026\n\022CENTER_REGISTER_DB\020\026\022\032\n\026SOCIAL_REG"
    "ISTER_CENTER\020\027\022\036\n\032SOCIAL_REGISTER_CENTER"
    "_RSP\020\030\022\034\n\030SOCIAL_QUERY_CENTER_INFO\020\031\022 \n\034"
    "SOCIAL_QUERY_CENTER_INFO_RSP\020\032\022\026\n\022NOTIFY"
    "_LOGIC_STATE\020\033\022\021\n\rINNER_LOG_REQ\020\037\022\034\n\030NOT"
    "IFY_LOGIC_DATA_UPDATE\020 \022\025\n\020DB_ROLE_LIST_"
    "REQ\020\255\002\022\025\n\020DB_ROLE_LIST_RSP\020\256\002\022\027\n\022DB_CREA"
    "TE_ROLE_REQ\020\257\002\022\027\n\022DB_CREATE_ROLE_RSP\020\260\002\022"
    "\025\n\020DB_ROLE_INFO_REQ\020\261\002\022\025\n\020DB_ROLE_INFO_R"
    "SP\020\262\002\022\034\n\027DB_ROLE_INFO_UPDATE_REQ\020\263\002\022 \n\033N"
    "OTIFY_LOGIC_ENTER_GAME_REQ\020\264\002\022 \n\033NOTIFY_"
    "LOGIC_ENTER_GAME_RSP\020\265\002\022 \n\033NOTIFY_LOGIC_"
    "LEAVE_GAME_REQ\020\266\002\022 \n\033NOTIFY_LOGIC_LEAVE_"
    "GAME_RSP\020\267\002\022\033\n\026NOTIFY_CENTER_KICK_REQ\020\270\002"
    "\022\033\n\026NOTIFY_GATE_ENTER_GAME\020\271\002\022\035\n\030NOTIFY_"
    "GATE_CHANGE_LOGIC\020\272\002\022\033\n\026NOTIFY_GATE_LEAV"
    "E_GAME\020\273\002\022\037\n\032NOTIFY_GATE_RECONNECT_GAME\020"
    "\274\002\022\035\n\030NOTIFY_CENTER_DISCONNECT\020\275\002\022\034\n\027NOT"
    "IFY_LOGIC_DISCONNECT\020\276\002\022\033\n\026NOTIFY_LOGIC_"
    "RECONNECT\020\277\002\022\034\n\027DB_ROLE_SIMPLE_LIST_REQ\020"
    "\300\002\022\034\n\027DB_ROLE_SIMPLE_LIST_RSP\020\301\002\022\031\n\024SOCI"
    "AL_ROLE_INFO_REQ\020\302\002\022\031\n\024SOCIAL_ROLE_INFO_"
    "RSP\020\303\002\022\033\n\026SOCIAL_ROLE_INFO_EVENT\020\304\002\022\033\n\026S"
    "YN_ATTR_TO_CENTER_RSP\020\305\002\022\031\n\024DB_ROLE_CHG_"
    "NAME_REQ\020\306\002\022\031\n\024DB_ROLE_CHG_NAME_RSP\020\307\002\022!"
    "\n\034NOTIFY_GATE_RETURN_ROLE_LIST\020\310\002\022$\n\037NOT"
    "IFY_CENTER_RECONNECT_SUCCESS\020\311\002\022\"\n\035CENTE"
    "R_CREATE_SCENE_REQ_LOGIC\020\221\003\022\"\n\035CENTER_CR"
    "EATE_SCENE_RSP_LOGIC\020\222\003\022#\n\036SOCIAL_TO_CEN"
    "TER_ADD_NEW_SCENE\020\223\003\022\037\n\032SOCIAL_TO_CENTER"
    "_DEL_SCENE\020\224\003\022&\n!LOGIC_NOTIFY_DESTORY_SC"
    "ENE_CENTER\020\225\003\022*\n%LOGIC_CREATURE_TRANS_SC"
    "ENE_REQ_CENTER\020\226\003\0221\n,CENTER_CREATURE_TRA"
    "NS_SCENE_RSP_LOGIC_RESULT\020\227\003\0222\n-CENTER_C"
    "REATURE_TRANS_SCENE_RSP_LOGIC_SUCCESS\020\230\003"
    "\022 \n\033DB_CREATURE_TRANS_SCENE_REQ\020\231\003\022 \n\033DB"
    "_CREATURE_TRANS_SCENE_RSP\020\232\003\022\034\n\027NOTIFY_R"
    "OLE_ENTER_SCENE\020\233\003\022\035\n\030NOTIFY_ROLE_CHANGE"
    "_LOGIC\020\234\003\022 \n\033DBPROXY_PROTOCOL_MAIL_BEGIN"
    "\020\302\003\022-\n(DBPROXY_PROTOCOL_CHARACTER_MAIL_D"
    "ATA_REQ\020\303\003\022-\n(DBPROXY_PROTOCOL_CHARACTER"
    "_MAIL_DATA_RSP\020\304\003\022%\n DBPROXY_PROTOCOL_MA"
    "X_MAIL_ID_REQ\020\305\003\022%\n DBPROXY_PROTOCOL_MAX"
    "_MAIL_ID_RSP\020\306\003\022/\n*DBPROXY_PROTOCOL_CHAR"
    "ACTER_DELETE_MAIL_REQ\020\307\003\022,\n\'DBPROXY_PROT"
    "OCOL_ALL_ZONE_MAIL_SAVE_REQ\020\310\003\022,\n\'DBPROX"
    "Y_PROTOCOL_ALL_ZONE_MAIL_SAVE_RSP\020\311\003\022)\n$"
    "DBPROXY_PROTOCOL_ZONE_MAIL_TRANS_REQ\020\312\003\022"
    ")\n$DBPROXY_PROTOCOL_ZONE_MAIL_TRANS_RSP\020"
    "\313\003\022#\n\036DBPROXY_PROTOCOL_MAIL_SAVE_REQ\020\314\003\022"
    "#\n\036DBPROXY_PROTOCOL_MAIL_SAVE_RSP\020\315\003\022\'\n\""
    "DBPROXY_PROTOCOL_WEB_MAIL_DATA_REQ\020\316\003\022\'\n"
    "\"DBPROXY_PROTOCOL_WEB_MAIL_DATA_RSP\020\317\003\022)"
    "\n$CENTER_SERVER_PROTOCOL_SEND_MAIL_REQ\020\320"
    "\003\022)\n$CENTER_SERVER_PROTOCOL_SEND_MAIL_RS"
    "P\020\321\003\0228\n3CENTER_SERVER_PROTOCOL_GET_MAIL_"
    "ATTACHMENT_TO_LOGIC\020\322\003\022.\n)CENTER_SERVER_"
    "PROTOCOL_UPDATE_MAIL_NOTIFY\020\323\003\022<\n7CENTER"
    "_SERVER_PROTOCOL_GET_ALL_MAIL_ATTACHMENT"
    "_TO_LOGIC\020\324\003\022,\n\'CENTER_SERVER_PROTOCOL_S"
    "END_SYSTEM_MAIL\020\325\003\022.\n)CENTER_SERVER_PROT"
    "OCOL_SEND_MAIL_TO_LOGIC\020\326\003\022\036\n\031DBPROXY_PR"
    "OTOCOL_MAIL_END\020\337\003\022\037\n\032SERVER_INTERNAL_CH"
    "AT_BEGIN\020\340\003\022$\n\037CENTER_SERVER_PROTOCOL_CH"
    "AT_REQ\020\341\003\022.\n)CENTER_SERVER_PROTOCOL_GWSY"
    "SCHATMSGNOTIFY\020\342\003\022 \n\033SERVER_TO_SERVER_CR"
    "OSS_CHAT\020\343\003\022#\n\036CENTER_TO_LOGCI_VIR_FORBI"
    "D_RSP\020\344\003\022\035\n\030SERVER_INTERNAL_CHAT_END\020\351\003\022"
    "\031\n\024NOTIFY_SERVER_GM_RSP\020\364\003\022!\n\034SERVER_INT"
    "ERNAL_FRIEND_BEGIN\020\247\004\022\035\n\030LOGIC_TO_CENTER"
    "_ADD_HATE\020\250\004\022!\n\034LOGIC_TO_CENTER_KILL_SOM"
    "EONE\020\251\004\022\037\n\032CENTER_TO_LOGIC_ADD_FRIEND\020\252\004"
    "\022 \n\033LOGIC_TO_CENTER_GIVING_GIFT\020\253\004\022&\n!CE"
    "NTER_TO_LOGIC_GIVING_GIFT_ERROR\020\254\004\022)\n$DB"
    "PROXY_PROTOCOL_ALL_FRIEND_DATA_REQ\020\260\004\022*\n"
    "%DBPROXY_PROTOCOL_SAVE_FRIEND_DATA_REQ\020\261"
    "\004\022)\n$DBPROXY_PROTOCOL_ALL_FRIEND_DATA_RS"
    "P\020\262\004\022*\n%DBPROXY_PROTOCOL_SAVE_FRIEND_DAT"
    "A_RSP\020\263\004\022/\n*DBPROXY_PROTOCOL_DELETE_FRIE"
    "ND_DATA_NOTIFY\020\264\004\022%\n DBPROXY_PROTOCOL_FR"
    "IEND_DATA_REQ\020\265\004\022%\n DBPROXY_PROTOCOL_FRI"
    "END_DATA_RSP\020\266\004\022\037\n\032SERVER_INTERNAL_FRIEN"
    "D_END\020\272\004\022\026\n\021L2C_ENTER_DUP_REQ\020\330\004\022\027\n\022L2C_"
    "CREATE_DUP_RSP\020\331\004\022\035\n\030L2C_DUP_STATE_CHG_N"
    "OTIFY\020\332\004\022#\n\036C2L_PULL_ROLE_ENTER_DUP_NOTI"
    "FY\020\333\004\022\037\n\032L2C_DUP_ROLE_ACTION_NOTIFY\020\334\004\022\026"
    "\n\021S2C_ENTER_DUP_REQ\020\335\004\022\026\n\021C2S_ENTER_DUP_"
    "RSP\020\336\004\022\036\n\031L2C_TOWER_RECV_RECORD_REQ\020\337\004\022\026"
    "\n\021L2S_ENTER_DUP_REQ\020\340\004\022\034\n\027L2S_DUP_TEAM_I"
    "NVITE_REQ\020\341\004\022\036\n\031C2S_CREATE_DUP_RESULT_RS"
    "P\020\342\004\022\036\n\031S2C_NOTIFY_CHAR_ENTER_DUP\020\343\004\022\033\n\026"
    "NOTIFY_REBOT_ENTER_DUP\020\344\004\022\031\n\024L2S_DUP_TEA"
    "M_OPT_REQ\020\345\004\022$\n\037S2C_NOFITY_ROLE_REBOT_EN"
    "TER_DUP\020\346\004\022!\n\034C2L_ROLE_ROBOT_ENTER_DUP_R"
    "EQ\020\347\004\022\027\n\022L2C_DUP_RESULT_RSP\020\350\004\022\036\n\031C2S_NO"
    "TIFY_DUP_FINISH_RSP\020\351\004\022\026\n\021DB_GET_GLOBAL_"
    "REQ\020\212\005\022\026\n\021DB_GET_GLOBAL_RSP\020\213\005\022\026\n\021DB_SET"
    "_GLOBAL_REQ\020\214\005\022\030\n\023L2C_UPDATE_BOSS_REQ\020\224\005"
    "\022\027\n\022L2C_SYN_ATTENT_REQ\020\225\005\022\026\n\021L2C_KILL_BO"
    "SS_REQ\020\226\005\022\026\n\021L2C_BOSS_DROP_REQ\020\227\005\022\030\n\023DB_"
    "ACT_GET_DATA_REQ\020\274\005\022\030\n\023DB_ACT_GET_DATA_R"
    "SP\020\275\005\022\031\n\024DB_ACT_SAVE_DATA_REQ\020\276\005\022\031\n\024ACT_"
    "LS_INIT_DATA_REQ\020\277\005\022\031\n\024ACT_LS_INIT_DATA_"
    "RSP\020\300\005\022\031\n\024ACT_CS_INIT_DATA_REQ\020\301\005\022\031\n\024ACT"
    "_CS_INIT_DATA_RSP\020\302\005\022\032\n\025ACT_LS_PRE_FINIS"
    "H_REQ\020\303\005\022\031\n\024ACT_CL_INIT_DATA_REQ\020\304\005\022\036\n\031S"
    "ERVER_INTERAL_ARENA_BEIN\020\356\005\022$\n\037CENTER_TO"
    "_LOGIC_ARENA_RANK_INFO\020\357\005\022\'\n\"LOGIC_TO_CE"
    "NTER_ARENA_CHALL_RESULT\020\360\005\022&\n!CENTER_TO_"
    "LOGIC_ARENA_RANK_CHANGE\020\361\005\022,\n\'LOGIC_TO_C"
    "ENTER_ARENA_CAMP_CHALL_RESULT\020\362\005\022$\n\037LOGI"
    "C_TO_CENTER_ARENA_CHALL_REQ\020\363\005\022\037\n\032CENTER"
    "_TO_LOGIC_ADD_REWARD\020\364\005\022,\n\'CENTER_TO_LOG"
    "IC_ARENA_DUP_BATTLE_RESULT\020\365\005\022\035\n\030SERVER_"
    "INTERAL_ARENA_END\020\240\006\022\027\n\022DB_ROLE_MIRROR_R"
    "EQ\020\252\006\022\027\n\022DB_ROLE_MIRROR_RSP\020\253\006\022!\n\034SOCIAL"
    "_TO_CENTER_CREATE_TEAM\020\322\006\022$\n\037SOCIAL_TO_C"
    "ENTER_CHAR_JOIN_TEAM\020\323\006\022$\n\037SOCIAL_TO_CEN"
    "TER_CHAR_QUIT_TEAM\020\324\006\022!\n\034SOCIAL_TO_CENTE"
    "R_TEAM_LEADER\020\325\006\022\"\n\035SOCIAL_TO_CENTER_TEA"
    "M_DISMISS\020\326\006\022%\n SOCIAL_TO_CENTER_TEAM_ME"
    "M_UPDATE\020\327\006\022\'\n\"CENTER_TO_LOGIC_UPDATE_TE"
    "AM_NOTIFY\020\330\006\022(\n#CENTER_TO_LOGIC_DISMISS_"
    "TEAM_NOTIFY\020\331\006\022/\n*CENTER_TO_LOGIC_UPDATE"
    "_TEAM_CLONESS_NOTIFY\020\332\006\022%\n CENTER_TO_LOG"
    "IC_TEAM_INFO_NOTIFY\020\333\006\022\'\n\"LOGIC_TO_SOCIA"
    "L_TEAM_ROBOT_HP_SYNC\020\334\006\022 \n\033DB_FACTION_GE"
    "T_ALL_DATA_REQ\020\205\007\022 \n\033DB_FACTION_GET_ALL_"
    "DATA_RSP\020\206\007\022\035\n\030DB_FACTION_SAVE_DATA_REQ\020"
    "\207\007\022\027\n\022DB_FACTION_DEL_REQ\020\210\007\022\033\n\026FACTION_C"
    "L_ROLE_UPDATE\020\211\007\022\026\n\021FACTION_LC_CREATE\020\212\007"
    "\022\035\n\030FACTION_CL_CREATE_RESULT\020\213\007\022\030\n\023FACTI"
    "ON_LC_CHG_NAME\020\214\007\022\037\n\032FACTION_CL_CHG_NAME"
    "_RESULT\020\215\007\022\036\n\031FACTION_CL_DISMISS_NOTIFY\020"
    "\216\007\022\027\n\022L2C_SYN_ASSIST_REQ\020\230\007\022\030\n\023L2C_ASSIS"
    "T_HELP_REQ\020\231\007\022\032\n\025C2L_ASSIST_CANCEL_REQ\020\232"
    "\007\022\027\n\022C2L_ASSIST_ACK_REQ\020\233\007\022\027\n\022C2L_ASSIST"
    "_RMV_REQ\020\234\007\022\031\n\024L2C_ASSIST_THANK_REQ\020\235\007\022\032"
    "\n\025PAY_CL_DELIVER_NOTIFY\020\350\007\022\034\n\027PAY_LC_DEL"
    "IVER_FAIL_RSP\020\351\007\022\017\n\nDB_PAY_REQ\020\352\007\022\017\n\nDB_"
    "PAY_RSP\020\353\007\022\024\n\017DB_PAY_SAVE_REQ\020\354\007\022\026\n\021DB_P"
    "AY_UPDATE_REQ\020\355\007\022\017\n\nDB_RED_REQ\020\233\010\022\017\n\nDB_"
    "RED_RSP\020\234\010\022\024\n\017DB_RED_SAVE_REQ\020\235\010\022\023\n\016DB_R"
    "ED_DEL_REQ\020\236\010\022\024\n\017DB_RED_ROLE_REQ\020\237\010\022\024\n\017D"
    "B_RED_ROLE_RSP\020\240\010\022\024\n\017RED_LC_SEND_REQ\020\241\010\022"
    "\025\n\020RED_CL_FETCH_RSP\020\242\010\022\031\n\024RED_CL_SEND_FA"
    "IL_RSP\020\243\010\022\024\n\017RED_LC_RECHARGE\020\244\010\022\034\n\027DB_CE"
    "NTER_LOAD_ROLE_REQ\020\257\010\022\034\n\027DB_CENTER_SAVE_"
    "ROLE_REQ\020\260\010\022\031\n\024SERVER_INTER_MAX_CMD\020\210\'", 6478);
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
    case 650:
    case 651:
    case 652:
    case 660:
    case 661:
    case 662:
    case 663:
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
    case 920:
    case 921:
    case 922:
    case 923:
    case 924:
    case 925:
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
    case 1055:
    case 1056:
    case 1057:
    case 1058:
    case 1059:
    case 1060:
    case 1071:
    case 1072:
    case 5000:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
