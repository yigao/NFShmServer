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


enum ClientServerCmd {
  CLIENT_LOGIN_REQ = 1,
  CLIENT_LOGIN_RSP = 2,
  CLIENT_CREATE_ROLE_REQ = 3,
  CLIENT_CREATE_ROLE_RSP = 4,
  CLIENT_QUEUE_POS_REQ = 5,
  CLIENT_QUEUE_POS_RSP = 6,
  CLIENT_QUEUE_CANCEL_REQ = 7,
  CLIENT_QUEUE_CANCEL_RSP = 8,
  CLIENT_RECONNECT_REQ = 9,
  CLIENT_RECONNECT_RSP = 10,
  CLIENT_ENTER_GAME_REQ = 11,
  CLIENT_ENTER_GAME_RSP = 12,
  CLIENT_RET_ROLE_LIST_REQ = 13,
  CLIENT_RET_ROLE_LIST_RSP = 14,
  CLIENT_PING_REQ = 15,
  CLIENT_PING_RSP = 16,
  NOTIFY_CLIENT_CREATURE_CREATE = 101,
  NOTIFY_CLIENT_CREATURE_DESTORY = 102,
  BROAD_CHG_NAME = 103,
  BROAD_FACTION_INFO = 104,
  NOTIFY_CLIENT_LOAD_MAP = 151,
  NOTIFY_CLIENT_TRANS_SCENE_RSP = 152,
  CLIENT_LOAD_MAP_FINISH = 153,
  CLIENT_SCENE_TRANS_REQ = 154,
  NOTIFY_SCENE_CORPSE_INFO_RSP = 155,
  NOTIFY_SCENE_DRIVE_RSP = 156,
  CLIENT_PACKAGE_INFO_REQ = 200,
  CLIENT_PACKAGE_INFO_RSP = 201,
  CLIENT_PACKAGE_SORT_REQ = 202,
  CLIENT_PACKAGE_SORT_RSP = 203,
  CLIENT_STORAGE_OPERATE_REQ = 204,
  CLIENT_STORAGE_OPERATE_RSP = 205,
  NOTIFY_PACKAGE_UPDATE = 206,
  CLIENT_TO_LOGIC_PACKAGE_USE = 207,
  LOGIC_TO_CLIENT_PACKAGE_USE = 208,
  CLIENT_TO_LOGIC_PACKAGE_SELL = 209,
  LOGIC_TO_CLIENT_PACKAGE_SELL = 210,
  CLIENT_PLAYER_INFO_RSP = 251,
  CREATURE_ATTR_SYN = 252,
  CREATURE_ATTR_BROAD = 253,
  CLIENT_SHOW_INFO_RSP = 254,
  NOTIFY_FACADE_CAST_RSP = 255,
  CLIENT_CHG_NAME_REQ = 256,
  CLIENT_CHG_NAME_RSP = 257,
  CREATURE_STATE_BROAD = 258,
  CLIENT_TO_LOGIC_PLAYER_SEAT_REQ = 259,
  LOGIC_TO_CLIENT_SEAT_RSP = 260,
  LOGIC_TO_CLIENT_SEAT_EXP_RSP = 261,
  CLIENT_TO_LOGIC_LOGIN_HANGUP_DATA_REQ = 262,
  LOGIC_TO_CLIENT_LOGIN_HANGUP_DATA_RSP = 263,
  CLIENT_TO_LOGIC_GET_HANGUP_REWARD_REQ = 264,
  LOGIC_TO_CLIENT_GET_HANGUP_REWARD_RSP = 265,
  CLIENT_GM_REQ = 270,
  CLIENT_GM_RSP = 271,
  NOTIFY_GROW_RSP = 281,
  CLIENT_GROW_LVUP_REQ = 282,
  CLIENT_GROW_LVUP_RSP = 283,
  CLIENT_GROW_FACADE_DRESS_REQ = 284,
  CLIENT_GROW_FACADE_DRESS_RSP = 285,
  CLIENT_GROW_FACADE_UNDRESS_REQ = 286,
  CLIENT_GROW_FACADE_UNDRESS_RSP = 287,
  CLIENT_EQUIP_DRESS_REQ = 300,
  CLIENT_EQUIP_DRESS_RSP = 301,
  CLIENT_EQUIP_UNDRESS_REQ = 302,
  CLIENT_EQUIP_UNDRESS_RSP = 303,
  NOTIFY_EQUIP_INFO_RSP = 304,
  CLIENT_EQUIP_STRONG_REQ = 305,
  CLIENT_EQUIP_STRONG_RSP = 306,
  ClIENT_EQUIP_LV_ATTR_ACTIVE_REQ = 307,
  CLIENT_EQUIP_LV_ATTR_ACTIVE_RSP = 308,
  NOTIFY_EQUIP_LV_ATTR_RSP = 309,
  CLIENT_STONE_INLAY_REQ = 310,
  CLIENT_STONE_INLAY_RSP = 311,
  CLIENT_STONE_LV_REQ = 312,
  CLIENT_STONE_LV_RSP = 313,
  CLIENT_STONE_OPEN_SLOT_REQ = 314,
  CLIENT_STONE_OPEN_SLOT_RSP = 315,
  CLIENT_EQUIP_STOVE_INFO_REQ = 320,
  CLIENT_EQUIP_STOVE_INFO_RSP = 321,
  CLIENT_EQUIP_STOVE_SMELT_REQ = 322,
  CLIENT_EQUIP_STOVE_SMELT_RSP = 323,
  CLIENT_TO_SERVER_MISSION_BEGIN = 350,
  CLIENT_TO_LOGIC_QUERY_MiSSIONLIST = 351,
  LOGIC_TO_CLIENT_QUERY_MiSSIONLIST = 352,
  CLIENT_TO_LOGIC_ACCEPTMISSION = 353,
  LOGIC_TO_CLIENT_ACCEPTMISSION = 354,
  CLIENT_TO_LOGIC_ABANDONMISSION = 355,
  LOGIC_TO_CLIENT_ABANDONMISSION = 356,
  CLIENT_TO_LOGIC_SUBMITMISSION = 357,
  LOGIC_TO_CLIENT_SUBMITMISSION = 358,
  CLIENT_TO_LOGIC_TALKWITHNPC = 359,
  CLIENT_TO_LOGIC_SUBMITMISSIONGOODS = 361,
  LOGIC_TO_CLIENT_SUBMITMISSIONGOODS = 362,
  CLIENT_TO_LOGIC_NPC_ACCEPTMISSION = 363,
  LOGIC_TO_CLIENT_NPC_ACCEPTMISSION = 364,
  CLIENT_TO_LOGIC_MISSION_ONEKEY_FINISH = 365,
  LOGIC_TO_CLIENT_MISSION_ONEKEY_FINISH = 366,
  CLIENT_TO_LOGIC_MISSION_ONCE_FINISH = 367,
  LOGIC_TO_CLIENT_MISSION_ONCE_FINISH = 368,
  LOGIC_TO_CLIENT_UPDATEMISSIONSTATUSNOTIFY = 370,
  LOGIC_TO_CLIENT_UPDDATE_DY_ACCEPT_NUM = 371,
  LOGIC_TO_CLIENT_RECEIVEMISSIONNOTIFY = 372,
  LOGIC_TO_CLIENT_GCDELETEMISSIONNOTIFY = 373,
  CLIENT_TO_LOGIC_MISSION_RECV_SPECIAL_REWARD = 374,
  LOGIC_TO_CLIENT_MISSION_RECV_SPICIAL_REWARD = 375,
  CLIENT_TO_SERVER_MISSION_END = 400,
  CLIENT_SERVER_CHAT_BEGIN = 430,
  CLIENT_TO_LOGIC_CHAT_MSG_REQ = 431,
  LOGIC_TO_CLIENT_CHAT_MSG_RSP = 432,
  CLIENT_TO_CENTER_ASK_OFFLINE_MSG_REQ = 433,
  CENTER_TO_CLIENT_ASK_OFFLINE_MSG_RSP = 434,
  CLIENT_TO_CENTER_INTRVAL_ASK_OFFLINE_MSG_REQ = 435,
  CENTER_TO_CLIENT_INTRVAL_ASK_OFFLINE_MSG_RSP = 436,
  LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY = 437,
  SERVER_TO_CLIENT_SHOW_MESSAGE_NOTIFY = 438,
  CLIENT_SERVER_CHAT_END = 450,
  CLIENT_TO_SERVER_FRIEND_BEGIN = 460,
  CLIENT_TO_CENTER_RELATION_DATA_REQ = 461,
  CENTER_TO_CLIENT_RELATION_DATA_RSP = 462,
  CLIENT_TO_CENTER_FRIEND_APPLY_REQ = 463,
  CENTER_TO_CLIENT_FRIEND_APPLY_RSP = 464,
  CLIENT_TO_CENTER_AGREE_APPLY_REQ = 465,
  CENTER_TO_CLIENT_AGREE_APPLY_RSP = 466,
  CENTER_TO_CLIENT_SYNC_RELATION_NOTIFY = 467,
  CENTER_TO_CLIENT_RELATION_ONLINE_NOTIFY = 468,
  CLIENT_TO_CENTER_ADD_BLACK_REQ = 469,
  CENTER_TO_CLIENT_ADD_BLACK_RSP = 470,
  CLIENT_TO_CENTER_DELETE_RELATION_REQ = 471,
  CENTER_TO_CLIENT_DELETE_RELATION_RSP = 472,
  CENTER_TO_CLIENT_SYNC_DELRELATION_NOTIFY = 473,
  CLIENT_TO_CENTER_RECOMMEND_FRIEND_REQ = 474,
  CENTER_TO_CLIENT_RECOMMEND_FRIEND_RSP = 475,
  CLIENT_TO_CENTER_ADD_SHIELD_RELATION_REQ = 476,
  CENTER_TO_CLIENT_ADD_SHIELD_RELATION_RSP = 477,
  CLIENT_TO_CENTER_GIFT_GIVING_RECORD_REQ = 490,
  CENTER_TO_CLIENT_GIFT_GIVING_RECORD_RSP = 491,
  CLIENT_TO_CENTER_GIVING_GIFT_REQ = 492,
  CENTER_TO_CLIENT_GIVING_GIFT_RSP = 493,
  CENTER_TO_CLIENT_GIVING_GIFT_NOTICE = 494,
  CLIENT_TO_CENTER_THANKS_GIVING_GIFT = 495,
  CLIENT_TO_SERVER_FRIEND_END = 500,
  CLIENT_TO_CENTER_QUERY_BEGIN = 501,
  CLIENT_TO_CENTER_CHARACTER_DETAIL_DATA = 502,
  CENTER_TO_CLIENT_CHARACTER_DETAIL_DATA = 503,
  CLIENT_TO_CENTER_CHARACTER_MINI_DATA = 504,
  CENTER_TO_CLIENT_CHARACTER_MINI_DATA = 505,
  CLIENT_TO_CENTER_CHAR_FUNC_FIGHT_DATA = 506,
  CENTER_TO_CLIENT_CHAR_FUNC_FIGHT_DATA = 507,
  CLIENT_TO_CENTER_QUERY_END = 510,
  CLIENT_SERVER_MAIL_BEGIN = 560,
  CLIENT_TO_CENTER_GETMAILITEMLIST_REQ = 561,
  SERVER_TO_CLIENT_GETMAILITEMLIST_RSP = 562,
  CLIENT_TO_CENTER_ASKMAIL_REQ = 563,
  SERVER_TO_CLIENT_ASKMAIL_RSP = 564,
  CLIENT_TO_CENTER_DELETEMAIL_REQ = 565,
  SERVER_TO_CLIENT_DELETEMAIL_RSP = 566,
  CLIENT_TO_CENTER_GETALLMAILATTACHMENT_REQ = 567,
  SERVER_TO_CLIENT_GETALLMAILATTACHMENT_RSP = 568,
  CLIENT_TO_CENTER_GETMAILATTACHMENT_REQ = 570,
  SERVER_TO_CLIENT_GETMAILATTACHMENT_RSP = 569,
  SERVER_TO_CLIENT_UNREADMAIL_NOTIFY = 571,
  SERVER_TO_CLIENT_NEWMAIL_NOTIFY = 572,
  CLIENT_SERVER_MAIL_END = 579,
  SERVER_TO_CLIENT_FUNCTIONUNLOCK_NOTIFY = 580,
  SERVER_TO_CLIENT_FUNCTIONUNLOCK_INFO = 581,
  CLIENT_TO_SERVER_FUNCTIONUNLOCK_GET_REWARD_REQ = 582,
  SERVER_TO_CLIENT_FUNCTIONUNLOCK_GET_REWARD_RSP = 583,
  CLIENT_MOVE_REQ = 601,
  MOVE_BROAD_RSP = 602,
  MOVE_TELEPORT_RSP = 603,
  PLAYER_RELIVE_NOTIFY = 651,
  PLAYER_RELIVE_REQ = 652,
  PLAYER_RELIVE_RSP = 653,
  SKILL_USE_REQ = 701,
  SKILL_TARGET_SYNC_REQ = 702,
  SKILL_USE_RESULT_BROAD = 703,
  SKILL_USE_BROAD_RSP = 704,
  SKILL_WARN_BROAD_RSP = 705,
  SKILL_CANCEL_USE_REQ = 706,
  SKILL_CANCEL_USE_BROAD_RSP = 707,
  SKILL_GROUP_UPDATE_RSP = 708,
  SKILL_INFO_REQ = 709,
  SKILL_INFO_RSP = 710,
  SKILL_INFO_UPDATE_RSP = 711,
  SKILL_INFO_DEL_RSP = 714,
  SKILL_WAKE_UP_REQ = 715,
  SKILL_WAKE_UP_RSP = 716,
  SKILL_CHG_POS_REQ = 717,
  SKILL_CHG_POS_RSP = 718,
  SKILL_UPGRADE_REQ = 719,
  SKILL_UPGRADE_RSP = 720,
  SKILL_SET_AUTO_USE_REQ = 721,
  SKILL_SET_AUTO_USE_RSP = 722,
  SKILL_ADVANCE_REQ = 723,
  SKILL_ADVANCE_RSP = 724,
  SKILL_ADVANCE_CHG_POS_REQ = 725,
  SKILL_ADVANCE_CHG_POS_RSP = 726,
  SKILL_ADVANCE_RESET_REQ = 727,
  SKILL_ADVANCE_RESET_RSP = 728,
  SKILL_ADVANCE_UPDATE_RSP = 729,
  SKILL_ADVANCE_UNLOCK_POS_REQ = 730,
  SKILL_ADVANCE_UNLOCK_POS_RSP = 731,
  BUFF_LIST_REQ = 751,
  BUFF_LIST_RSP = 752,
  BUFF_UPDATE_RSP = 753,
  BUFF_DEL_RSP = 754,
  BUFF_EFFECT_BROAD_RSP = 755,
  NOTIFY_BOSS_SIMPLE_RSP = 850,
  BOSS_DATA_REQ = 851,
  BOSS_DATA_RSP = 852,
  NOTIFY_SCENE_BOSS_DATA_RSP = 853,
  NOTIFY_SCENE_BOSS_UPDATE_RSP = 854,
  NOTIFY_BOSS_INFO_RSP = 855,
  ENTER_BOSS_MAP_REQ = 856,
  ENTER_BOSS_MAP_RSP = 857,
  ATTENT_BOSS_REQ = 858,
  ATTENT_BOSS_RSP = 859,
  BOSS_DROP_REQ = 860,
  BOSS_DROP_RSP = 861,
  NOTIFY_BOSS_RESULT_RSP = 862,
  BOSS_KILL_REQ = 863,
  BOSS_KILL_RSP = 864,
  CLIENT_TO_LOGIC_FACADE_BEGIN = 900,
  CLIENT_TO_LOGIC_FACADE_INFO_REQ = 901,
  LOGIC_TO_CLIENT_FACADE_INFO_RSP = 902,
  CLIENT_TO_LOGIC_FACADE_LEVUP_REQ = 903,
  LOGIC_TO_CLIENT_FACADE_LEVUP_RSP = 904,
  CLIENT_TO_LOGIC_FACADE_DRESS_REQ = 905,
  LOGIC_TO_CLIENT_FACADE_DRESS_RSP = 906,
  CLIENT_TO_LOGIC_FACADE_UNDRESS_REQ = 911,
  LOGIC_TO_CLIENT_FACADE_UNDRESS_RSP = 912,
  CLIENT_TO_LOGIC_FACADE_FRAGEMNT_USE_REQ = 913,
  LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP = 914,
  CLIENT_TO_LOGIC_FACADE_SKILL_UNLOCK_NOTIFY = 915,
  CLIENT_TO_LOGIC_FACADE_SKILL_LEV_REQ = 916,
  LOGIC_TO_CLIENT_FACADE_SKILL_LEV_RSP = 917,
  CLIENT_TO_LOGIC_FACADE_FANTASY_INFO_REQ = 920,
  LOGIC_TO_CLIENT_FACADE_FANTASY_INFO_RSP = 921,
  CLIENT_TO_LOGIC_FACADE_FANTASY_ACTIVE_REQ = 922,
  LOGIC_TO_CLIENT_FACADE_FANTASY_ACTIVE_RSP = 923,
  CLIENT_TO_LOGIC_FACADE_FANTASY_LEVELUP_REQ = 924,
  LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP = 925,
  CLIENT_TO_LOGIC_FACADE_FANTASY_DRESS_REQ = 926,
  LOGIC_TO_CLIENT_FACADE_FANTASY_DRESS_RSP = 927,
  CLIENT_TO_LOGIC_FACADE_FANTASY_UNDRESS_REQ = 928,
  LOGIC_TO_CLIENT_FACADE_FANTASY_UNDRESS_RSP = 929,
  CLIENT_TO_LOGIC_FACADE_BUY_SOUL_REQ = 930,
  LOGIC_TO_CLIENT_FACADE_BUG_SOUL_RSP = 931,
  CLIENT_TO_LOGIC_FACADE_SOUL_INFO_REQ = 932,
  LOGIC_TO_CLIENT_FACADE_SOUL_INFO_RSP = 933,
  CLIENT_TO_LOGIC_FACADE_SOUL_ACTIVE_REQ = 936,
  LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP = 937,
  CLIENT_TO_LOGIC_FACADE_SOUL_LEVELUP_REQ = 938,
  LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP = 939,
  CLIENT_TO_LOGIC_FACADE_SOUL_ACTIVITY_RECV_REQ = 940,
  LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP = 941,
  LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_NOTIFY = 942,
  LOGIC_TO_CLIENT_FACADE_SOUL_SKILL_INFO_NOTIFY = 943,
  CLIENT_TO_LOGIC_FACADE_SOUL_RESET_SKILL_REQ = 944,
  LOGIC_TO_CLIENT_FACADE_SOUL_RESET_SKILL_RSP = 945,
  CLIENT_TO_LOGIC_FACADE_END = 950,
  CLIENT_TO_LOGIC_MINI_ACTIVITY_BEGIN = 951,
  CLIENT_TO_LOGIC_GET_GOD_RELICS_INFO_REQ = 952,
  LOGIC_TO_CLIENT_GET_GOD_RELICS_INFO_RSP = 953,
  LOGIC_TO_CLIENT_UPDATE_GOD_RELICS_NOTIFY = 954,
  CLIENT_TO_LOGIC_GET_GOD_RELICS_TASK_REWARD_REQ = 955,
  LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP = 956,
  CLIENT_TO_LOGIC_GET_GOD_RELICS_GROUP_TASK_REWARD_REQ = 957,
  LOGIC_TO_CLIENT_GET_GOD_RELICS_GROUP_TASK_REWARD_RSP = 958,
  CLIENT_TO_LOGIC_GET_DAILY_TASK_DATA_REQ = 960,
  LOGIC_TO_CLIENT_GET_DAILY_TASK_DATA_RSP = 961,
  LOGIC_TO_CLIENT_UPDATE_DAILY_TASK_NOTIFY = 962,
  CLIENT_TO_LOGIC_GET_DAILY_TASK_REWARD_REQ = 964,
  LOGIC_TO_CLIENT_GET_DAILY_TASK_REWARD_RSP = 965,
  CLIENT_TO_LOGIC_DAILY_TASK_LEVELUP_REQ = 966,
  LOGIC_TO_CLIENT_DAILY_TASK_LEVELUP_RSP = 967,
  CLIENT_TO_LOGIC_DAILY_LIMIT_TASK_ADD_READY_REQ = 968,
  LOGIC_TO_CLIENT_DAILY_LIMIT_TASK_ADD_READY_RSP = 969,
  CLIENT_TO_LOGIC_DAILY_BACK_TASK_BACK_REQ = 970,
  LOGIC_TO_CLIENT_DAILY_BACK_TASK_BACK_RSP = 971,
  CLIENT_TO_LOGIC_DAILY_LIMIT_TASK_ADD_ALL_READY_REQ = 972,
  LOGIC_TO_CLIENT_DAILY_LIMIT_TASK_ADD_ALL_READY_RSP = 973,
  CLIENT_TO_LOGIC_DAILY_BACK_ALL_TASK_BACK_REQ = 974,
  LOGIC_TO_CLIENT_DAILY_BACK_ALL_TASK_BACK_RSP = 975,
  CLIENT_TO_LOGIC_MINI_ACTIVITY_END = 999,
  ENTER_DUP_REQ = 1000,
  ENTER_DUP_RSP = 1001,
  DUP_RESULT_REQ = 1002,
  DUP_RESULT_RSP = 1003,
  DUP_LEAVE_REQ = 1004,
  DUP_LEAVE_RSP = 1005,
  NOTIFY_DUP_END_RSP = 1006,
  NOTIFY_DUP_RSP = 1007,
  NOTIFY_DUP_RUN_RSP = 1008,
  NOTIFY_DUP_BEGIN_CD_RSP = 1009,
  RECV_TOWER_DUP_REQ = 1010,
  RECV_TOWER_DUP_RSP = 1011,
  BUY_DUP_NUM_REQ = 1012,
  BUY_DUP_NUM_RSP = 1013,
  DUP_TOWER_RECORD_REQ = 1014,
  DUP_TOWER_RECORD_RSP = 1015,
  DUP_TEAM_INVITE_REQ = 1016,
  DUP_TEAM_INVITE_RSP = 1017,
  NOTIFY_DUP_TEAM_INVITE_STATE_RSP = 1018,
  DUP_TEAM_OPT_REQ = 1019,
  DUP_TEAM_OPT_RSP = 1020,
  DUP_SWEEP_REQ = 1021,
  DUP_SWEEP_RSP = 1022,
  ACT_LIST_REQ = 1201,
  ACT_LIST_RSP = 1202,
  CLIENT_TO_CENTER_CREATE_TEAM = 1301,
  CLIENT_TO_CENTER_APPLY_JOIN_TEAM = 1302,
  CLIENT_TO_CENTER_REPLY_JOIN_TEAM = 1303,
  CLIENT_TO_CENTER_QUIT_TEAM = 1304,
  CLIENT_TO_CENTER_INVITE_JOIN_TEAM = 1305,
  CLIENT_TO_CENTER_REPLY_INVITE_JOIN_TEAM = 1306,
  CLIENT_TO_CENTER_KICK_TEAM_MEMBER = 1307,
  CLIENT_TO_CENTER_TEAM_APPLY_LIST = 1308,
  CLIENT_TO_CENTER_CLEAR_APPLY_LIST = 1309,
  CLIENT_TO_CENTER_TEAM_SET_TARGET = 1310,
  CLIENT_TO_CENTER_TEAM_PROMOTE_LEADER = 1311,
  CLIENT_TO_CENTER_TEAM_AUTO_MATCH = 1312,
  CLIENT_TO_CENTER_TEAM_MATCH_ATONCE = 1313,
  CENTER_TO_CLIENT_TEAM_MATCH_ATONCE = 1314,
  CENTER_TO_CLIENT_CREATE_TEAM = 1331,
  CENTER_TO_CLIENT_APPLY_JOIN_TEAM = 1332,
  CENTER_TO_CLIENT_REPLY_JOIN_TEAM = 1333,
  CENTER_TO_CLIENT_QUIT_TEAM = 1334,
  CENTER_TO_CLIENT_INVITE_JOIN_TEAM = 1335,
  CENTER_TO_CLIENT_REPLY_INVITE_JOIN_TEAM = 1336,
  CENTER_TO_CLIENT_KICK_TEAM_MEMBER = 1337,
  CENTER_TO_CLIENT_TEAM_APPLY_LIST = 1338,
  CENTER_TO_CLIENT_CLEAR_APPLY_LIST = 1339,
  CENTER_TO_CLIENT_TEAM_SET_TARGET = 1340,
  CENTER_TO_CLIENT_TEAM_PROMOTE_LEADER = 1341,
  CENTER_TO_CLIENT_TEAM_AUTO_MATCH = 1342,
  CENTER_TO_CLIENT_UPDATE_TEAM_APPLY = 1343,
  CENTER_TO_CLIENT_UPDATE_TEAM_MEM = 1344,
  CENTER_TO_CLIENT_UPDATE_TEAM_MEM_SIMPLE = 1345,
  CENTER_TO_CLIENT_INVITE_TEAM_NOTIFY = 1346,
  CENTER_TO_CLIENT_UPDATE_TEAM_INFO = 1347,
  CENTER_TO_CLIENT_UPDATE_TEAM_SIMPLE = 1348,
  CENTER_TO_CLIENT_TEAM_REFUSE_NOTIFY = 1349,
  CLIENT_TO_CENTER_ARENA_BEGIN = 1400,
  CLIENT_TO_CENTER_ARENA_RANK_INFO = 1401,
  CENTER_TO_CLIENT_ARENA_RANK_INFO = 1402,
  CLIENT_TO_CENTER_ARENA_UPDATE_OPPONENT_INFO = 1403,
  CENTER_TO_CLIENT_ARENA_UPDATE_OPPONENT_INFO = 1404,
  CLIENT_TO_CENTER_ARENA_TOP_LIST = 1405,
  CENTER_TO_CLIENT_ARENA_TOP_LIST = 1406,
  CLIENT_TO_CENTER_ARENA_CHALL = 1407,
  CENTER_TO_CLIENT_ARENA_CHALL = 1408,
  CLIENT_TO_SERVER_ARENA_BUY_CHALLENGE_REQ = 1409,
  SERVER_TO_CLIENT_ARENA_BUY_CHALLENGE_RSP = 1410,
  CLIENT_TO_SERVER_ARENA_ABANDON = 1411,
  CLIENT_TO_SERVER_ARENA_SWEEP_REQ = 1412,
  LOGIC_TO_CLIENT_ARENA_SWEEP_RSP = 1413,
  CENTER_TO_CLIENT_ARENA_CHALL_RESULT = 1414,
  LOGIC_TO_CLIENT_ARENA_CAMP_RESULT = 1415,
  CLIENT_TO_LOGIC_ARENA_GET_CHALL_RESULT_REQ = 1416,
  LOGIC_TO_CLIENT_ARENA_GET_CHALL_RESULT_RSP = 1417,
  CLIENT_TO_LOGIC_ARENA_GET_CHALL_REWARD_REQ = 1420,
  LOGIC_TO_CLIENT_ARENA_GET_CHALL_REWARD_RSP = 1421,
  LOGIC_TO_CLIENT_CHALL_REWARD_CHANGE_NOTIFY = 1423,
  CLIENT_TO_LOGIC_ARENA_RECEIVE_CHALL_REWARD_REQ = 1426,
  LOGIC_TO_CLIENT_ARENA_RECEIVE_CHALL_REWARD_RSP = 1427,
  CLIENT_TO_LOGIC_ARENA_SKIP_BATTLE_REQ = 1428,
  CLIENT_TO_LOGIC_ARENA_SKIP_BATTLE_RSP = 1429,
  CLIENT_TO_CENTER_ARENA_END = 1449,
  DROP_PICK_REQ = 1450,
  DROP_PICK_RSP = 1451,
  DROP_HEAD_NOTIFY = 1452,
  NOTIFY_VIP_DATA_RSP = 1480,
  NOTIFY_SERVER_FLAG_RSP = 1481,
  CLIENT_TO_LOGIC_MOUNT_INFO_REQ = 1501,
  LOGIC_TO_CLIENT_MOUNT_INFO_RSP = 1502,
  CLIENT_TO_LOGIC_MOUNT_LEVUP_REQ = 1503,
  LOGIC_TO_CLIENT_MOUNT_LEVUP_RSP = 1504,
  CLIENT_TO_LOGIC_MOUNT_DRESS_REQ = 1505,
  LOGIC_TO_CLIENT_MOUNT_DRESS_RSP = 1506,
  CLIENT_TO_LOGIC_MOUNT_UNDRESS_REQ = 1507,
  LOGIC_TO_CLIENT_MOUNT_UNDRESS_RSP = 1508,
  CLIENT_TO_LOGIC_MOUNT_FRAGEMNT_USE_REQ = 1509,
  LOGIC_TO_CLIENT_MOUNT_FRAGEMNT_USE_RSP = 1510,
  CLIENT_TO_LOGIC_MOUNT_SKILL_UNLOCK_NOTIFY = 1511,
  CLIENT_TO_LOGIC_MOUNT_FANTASY_INFO_REQ = 1515,
  LOGIC_TO_CLIENT_MOUNT_FANTASY_INFO_RSP = 1516,
  CLIENT_TO_LOGIC_MOUNT_FANTASY_ACTIVE_REQ = 1517,
  LOGIC_TO_CLIENT_MOUNT_FANTASY_ACTIVE_RSP = 1518,
  CLIENT_TO_LOGIC_MOUNT_FANTASY_LEVELUP_REQ = 1519,
  LOGIC_TO_CLIENT_MOUNT_FANTASY_LEVELUP_RSP = 1520,
  CLIENT_TO_LOGIC_MOUNT_FANTASY_STARUP_REQ = 1521,
  LOGIC_TO_CLIENT_MOUNT_FANTASY_STARUP_RSP = 1522,
  CLIENT_TO_LOGIC_MOUNT_FANTASY_DRESS_REQ = 1523,
  LOGIC_TO_CLIENT_MOUNT_FANTASY_DRESS_RSP = 1524,
  CLIENT_TO_LOGIC_MOUNT_FANTASY_UNDRESS_REQ = 1525,
  LOGIC_TO_CLIENT_MOUNT_FANTASY_UNDRESS_RSP = 1526,
  CLIENT_TO_LOGIC_MOUNT_KUN_INFO_REQ = 1530,
  LOGIC_TO_CLIENT_MOUNT_KUN_INFO_RSP = 1531,
  CLIENT_TO_LOGIC_MOUNT_KUN_ACTIVE_REQ = 1532,
  LOGIC_TO_CLIENT_MOUNT_KUN_ACTIVE_RSP = 1533,
  CLIENT_TO_LOGIC_MOUNT_KUN_LEVELUP_REQ = 1534,
  LOGIC_TO_CLIENT_MOUNT_KUN_LEVELUP_RSP = 1535,
  CLIENT_TO_LOGIC_MOUNT_KUN_STARUP_REQ = 1536,
  LOGIC_TO_CLIENT_MOUNT_KUN_STARUP_RSP = 1537,
  CLIENT_TO_LOGIC_MOUNT_KUN_DRESS_REQ = 1538,
  LOGIC_TO_CLIENT_MOUNT_KUN_DRESS_RSP = 1539,
  CLIENT_TO_LOGIC_MOUNT_KUN_UNDRESS_REQ = 1540,
  LOGIC_TO_CLIENT_MOUNT_KUN_UNDRESS_RSP = 1541,
  CLIENT_TO_LOGIC_MOUNT_BLOOD_ACTIVE_REQ = 1542,
  LOGIC_TO_CLIENT_MOUNT_BLOOD_ACTIVE_RSP = 1543,
  CLIENT_TO_LOGIC_MOUNT_BABY_EGG_INFO_REQ = 1544,
  LOGIC_TO_CLIENT_MOUNT_BABY_EGG_INFO_RSP = 1545,
  CLIENT_TO_LOGIC_MOUNT_BABY_CREATE_EGG_REQ = 1546,
  LOGIC_TO_CLIENT_MOUNT_BABY_CREATE_EGG_RSP = 1547,
  CLIENT_TO_LOGIC_MOUNT_BABY_DUHUA_REQ = 1548,
  LOGIC_TO_CLIENT_MOUNT_BABY_DUHUA_SUCCESS_NOTIFY = 1549,
  CLIENT_TO_LOGIC_MOUNT_BABY_RECV_DUHUA_KUN_REQ = 1550,
  LOGIC_TO_CLIENT_MOUNT_BABY_RECV_DUHUA_KUN_RSP = 1551,
  CLIENT_TO_LOGIC_MOUNT_BABY_UNLOCK_REQ = 1552,
  LOGIC_TO_CLIENT_MOUNT_BABY_UNLOCK_RSP = 1553,
  CLIENT_TO_LOGIC_MOUNT_RIDE_ON_REQ = 1554,
  LOGIC_TO_CLIENT_MOUNT_RIDE_ON_RSP = 1555,
  CLIENT_TO_LOGIC_MOUNT_RIDE_OFF_REQ = 1556,
  LOGIC_TO_CLIENT_MOUNT_RIDE_OFF_RSP = 1557,
  CLIENT_TO_LOGIC_DEITY_INFO_REQ = 1601,
  LOGIC_TO_CLIENT_DEITY_INFO_RSP = 1602,
  CLIENT_TO_LOGIC_DEITY_LEVUP_REQ = 1603,
  LOGIC_TO_CLIENT_DEITY_LEVUP_RSP = 1604,
  CLIENT_TO_LOGIC_DEITY_FANTASY_BATTLE_REQ = 1605,
  LOGIC_TO_CLIENT_DEITY_FANTASY_BATTLE_RSP = 1606,
  CLIENT_TO_LOGIC_DEITY_FANTASY_QUIT_BATTLE_REQ = 1607,
  LOGIC_TO_CLIENT_DEITY_FANTASY_QUIT_BATTLE_RSP = 1608,
  CLIENT_TO_LOGIC_DEITY_FRAGEMNT_USE_REQ = 1609,
  LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP = 1610,
  CLIENT_TO_LOGIC_DEITY_SKILL_UNLOCK_NOTIFY = 1611,
  LOGIC_TO_CLIENT_DEITY_BATTLE_SLOT_UNLOCK_NOTIFY = 1612,
  CLIENT_TO_LOGIC_DEITY_UNLOCK_BATTLE_SLOT_REQ = 1613,
  LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP = 1614,
  CLIENT_TO_LOGIC_DEITY_FANTASY_INFO_REQ = 1615,
  LOGIC_TO_CLIENT_DEITY_FANTASY_INFO_RSP = 1616,
  CLIENT_TO_LOGIC_DEITY_FANTASY_ACTIVE_REQ = 1617,
  LOGIC_TO_CLIENT_DEITY_FANTASY_ACTIVE_RSP = 1618,
  CLIENT_TO_LOGIC_DEITY_FANTASY_LEVELUP_REQ = 1619,
  LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP = 1620,
  CLIENT_TO_LOGIC_DEITY_FANTASY_STARUP_REQ = 1621,
  LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP = 1622,
  CLIENT_TO_LOGIC_DEITY_FANTASY_ENTER_WAR_REQ = 1623,
  LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP = 1624,
  CLIENT_TO_LOGIC_DEITY_SHOW_FANTASY_LIST_REQ = 1625,
  LOGIC_TO_CLIENT_DEITY_SHOW_FANTASY_LIST_RSP = 1626,
  CLIENT_DEITY_EQUIP_DRESS_REQ = 1627,
  CLIENT_DEITY_EQUIP_DRESS_RSP = 1628,
  CLIENT_DEITY_EQUIP_UNDRESS_REQ = 1629,
  CLIENT_DEITY_EQUIP_UNDRESS_RSP = 1630,
  NOTIFY_DEITY_EQUIP_INFO_RSP = 1631,
  CLIENT_DEITY_EQUIP_STRONG_REQ = 1632,
  CLIENT_DEITY_EQUIP_STRONG_RSP = 1633,
  CLIENT_DEITY_EQUIP_STRONG_LV_REQ = 1634,
  CLIENT_DEITY_EQUIP_STRONG_LV_RSP = 1635,
  CLIENT_DEITY_EQUIP_SUIT_ACTIVE_REQ = 1636,
  CLIENT_DEITY_EQUIP_SUIT_ACTIVE_RSP = 1637,
  CLIENT_DEITY_EQUIP_DECOMPOSE_REQ = 1638,
  CLIENT_DEITY_EQUIP_DECOMPOSE_RSP = 1639,
  CLIENT_DEITY_EQUIP_DISASSEMBLE_REQ = 1640,
  CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP = 1641,
  NOTIFY_PET_MODULE_RSP = 1701,
  NOTIFY_PET_RSP = 1702,
  NOTIFY_PET_FETTER_RSP = 1703,
  NOTIFY_PET_HATCH_RSP = 1704,
  CLIENT_PET_LVUP_REQ = 1705,
  CLIENT_PET_LVUP_RSP = 1706,
  CLIENT_PET_STEP_LV_REQ = 1707,
  CLIENT_PET_STEP_LV_RSP = 1708,
  CLIENT_PET_STAR_LV_REQ = 1709,
  CLIENT_PET_STAR_LV_RSP = 1710,
  CLIENT_PET_FORMATION_REQ = 1711,
  CLIENT_PET_FORMATION_RSP = 1712,
  CLIENT_PET_ADD_HATCH_REQ = 1713,
  CLIENT_PET_ADD_HATCH_RSP = 1714,
  CLIENT_PET_HATCH_UNLOCK_REQ = 1715,
  CLIENT_PET_HATCH_UNLOCK_RSP = 1716,
  CLIENT_PET_HATCH_EGG_REQ = 1717,
  CLIENT_PET_HATCH_EGG_RSP = 1718,
  CLIENT_PET_ACTIVE_FETTER_REQ = 1719,
  CLIENT_PET_ACTIVE_FETTER_RSP = 1720,
  CLIENT_PET_SKILL_LV_REQ = 1721,
  CLIENT_PET_SKILL_LV_RSP = 1722,
  CLIENT_PET_REST_REQ = 1723,
  CLIENT_PET_REST_RSP = 1724,
  CLIENT_PET_DECOMPOSE_REQ = 1725,
  CLIENT_PET_DECOMPOSE_RSP = 1726,
  CLIENT_PET_QUICK_HATCH_EGG_REQ = 1727,
  CLIENT_PET_QUICK_HATCH_EGG_RSP = 1728,
  NOTIFY_PET_GETED_LIST_RSP = 1729,
  MALL_INFO_REQ = 2050,
  MALL_INFO_RSP = 2051,
  MALL_BUY_REQ = 2052,
  MALL_BUY_RSP = 2053,
  MALL_INFO_UPDATE_RSP = 2054,
  FACTION_SYNC_LOGIN = 2101,
  FACTION_SYNC_INFO = 2102,
  FACTION_LIST_REQ = 2103,
  FACTION_LIST_RSP = 2104,
  FACTION_SIMPLE_REQ = 2105,
  FACTION_SIMPLE_RSP = 2106,
  FACTION_MEM_LIST_REQ = 2107,
  FACTION_MEM_LIST_RSP = 2108,
  FACTION_CREATE_REQ = 2109,
  FACTION_CREATE_RSP = 2110,
  FACTION_APPLY_LIST_REQ = 2111,
  FACTION_APPLY_LIST_RSP = 2112,
  FACTION_APPLY_JOIN_REQ = 2113,
  FACTION_APPLY_JOIN_RSP = 2114,
  FACTION_APPLY_OP_REQ = 2115,
  FACTION_APPLY_OP_RSP = 2116,
  FACTION_KICK_REQ = 2117,
  FACTION_KICK_RSP = 2118,
  FACTION_QUIT_REQ = 2119,
  FACTION_QUIT_RSP = 2120,
  FACTION_APPOINT_REQ = 2121,
  FACTION_APPOINT_RSP = 2122,
  FACTION_CHG_NOTICE_REQ = 2123,
  FACTION_CHG_NOTICE_RSP = 2124,
  FACTION_SET_APPLY_REQ = 2125,
  FACTION_SET_APPLY_RSP = 2126,
  FACTION_ONE_KEY_APPLY_JOIN_REQ = 2127,
  FACTION_ONE_KEY_APPLY_JOIN_RSP = 2128,
  FACTION_CHG_NAME_REQ = 2129,
  FACTION_CHG_NAME_RSP = 2130,
  FACTION_NEW_APPLY_NOTIFY = 2131,
  FACTION_INFO_REQ = 2132,
  FACTION_INFO_RSP = 2133,
  FACTION_INVITE_JOIN_REQ = 2134,
  FACTION_INVITE_JOIN_RSP = 2135,
  FACTION_INVITE_JOIN_NOTIFY = 2136,
  FACTION_RECORD_LIST_REQ = 2137,
  FACTION_RECORD_LIST_RSP = 2138,
  NOTIFY_CONVOY_INFO = 2200,
  CLIENT_CONVOY_ACCEPT_REQ = 2201,
  CLIENT_CONVOY_ACCEPT_RSP = 2202,
  NOTIFY_CONVOY_REWARD_RSP = 2203,
  NOTIFY_CONVOY_TIMEOUT_RSP = 2204,
  CLIENT_CONVOY_REFRESH_REQ = 2205,
  CLIENT_CONVOY_REFRESH_RSP = 2206,
  ARMOR_ACTIVE_REQ = 2210,
  ARMOR_ACTIVE_RSP = 2211,
  NOTIFY_ARMOR_RSP = 2212,
  NOTIFY_ASSIST_POOL_LIST = 2220,
  NOTIFY_ROLE_ASSIST = 2221,
  ASSIST_HELP_REQ = 2222,
  ASSIST_HELP_RSP = 2223,
  NOTIFY_HELP_DST = 2224,
  ASSIST_EXIT_HELP_REQ = 2225,
  ASSIST_EXIT_HELP_RSP = 2226,
  NOTIFY_ASSIST_CMPT = 2227,
  ASSIST_THANK_REQ = 2228,
  ASSIST_THANK_RSP = 2229,
  NOTIFY_ASSIST_THANK = 2230,
  NOTIFY_HELP_HURT_RANK = 2231,
  NOTIFY_BOSS_HURT_RANK = 2232,
  SEND_BOSS_HELP_REQ = 2233,
  SEND_BOSS_HELP_RSP = 2234,
  CLIENT_SERVER_MAX_CMD = 5000
};
bool ClientServerCmd_IsValid(int value);
const ClientServerCmd ClientServerCmd_MIN = CLIENT_LOGIN_REQ;
const ClientServerCmd ClientServerCmd_MAX = CLIENT_SERVER_MAX_CMD;
const int ClientServerCmd_ARRAYSIZE = ClientServerCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientServerCmd_descriptor();
inline const ::std::string& ClientServerCmd_Name(ClientServerCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientServerCmd_descriptor(), value);
}
inline bool ClientServerCmd_Parse(
    const ::std::string& name, ClientServerCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientServerCmd>(
    ClientServerCmd_descriptor(), name, value);
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
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::ClientServerCmd>() {
  return ::proto_ff::ClientServerCmd_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ClientServerCmd_2eproto__INCLUDED
