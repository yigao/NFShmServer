// -------------------------------------------------------------------------
//    @FileName         :    NFServerFrameTypeDefines.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTypeDefines.h"

typedef enum
{
	EOT_SF_BEGIN_ID = EOT_SERVER_FRAME_BEGIN_ID,
	////////////////////////////sns server/////////////////////////////
	EOT_SNS_ONLINE_USER_ID = 101,
	EOT_SNS_ONLINE_USER_HASH_TABLE_ID = 102,

	EOT_SNS_ACTIVITY_MAIL_DATA = 110,
	EOT_USER_MAIL_EXT_ID = 111,
	EOT_USER_MAIL_HASHTABLE_ID = 112,
	EOT_USER_MAIL_CACHE_MNG_ID = 113,
	EOT_TRANS_USER_MAIL_ID = 114,
	EOT_TRANS_USER_MAIL_CREATE_ID = 115,
	EOT_TRANS_SNS_SEND_EVENT_LOG_ID = 116,
	EOT_TRANS_SAVE_USER_SIMPLEL = 117,
	EOT_SNS_USER_SIMPLE_ID = 118,
	EOT_SNS_USER_SIMPLE_HASH_TABLE_ID = 120,
	EOT_SNS_USER_SIMPLE_UTIL_ID = 121,
	EOT_TRANS_GET_USER_SIMPLE = 122,
	EOT_TRANS_SNS_BASE = 123,
	EOT_TRANS_SNS_USER_ONLINE = 124,
	EOT_TRANS_SNS_GET_TRANS_ID = 125,
	EOT_USER_MAIL_CACHE_ID = 126,
	EOT_TRANS_SNS_WEB_HANDLE_TRANS_ID = 127,

	EOT_RANK_COMMON_ID = 130,
	EOT_RANK_MGR_ID = 131,

	EOT_WHILE_BLACK_LIST_DESC_ID = 132,
	EOT_LOG_SYSTEM_DAY_ID = 133,
	EOT_SYSTEM_STAT_MGR_ID = 134,
    EOT_LOG_GAME_DAY_ID = 135,
    EOT_LOG_SYSTEM_STAT_ID = 136,
    EOT_GM_CTRL_GIVE_DATA_DESC_ID = 137,
    EOT_REDEEM_CODE_MGR_ID = 138,
    EOT_REDEEM_CODE_TRANS_ID = 139,
	////////////////////////////sns server/////////////////////////////

	////////////////////////////logic server/////////////////////////////
	EOT_USER_MISC_EXT_ID = 150,
	EOT_USER_MISC_HASHTABLE_ID = 151,
	EOT_TRANS_USER_MISC_ID = 152,

	EOT_USER_BANK_CACHE_MNG_ID = 153,
	EOT_TRANS_USER_MISC_CREATE_ID = 154,
	EOT_TRANS_USER_BANK_ID = 155,
	EOT_TRANS_SEND_EVENT_LOG_ID = 156,
	EOT_TRANS_GET_EVENT_LOG_ID = 157,
	EOT_TRANS_HANDLE_EVENT_LOG_ID = 158,
	EOT_TRANS_GET_USER_DETAIL = 159,
	EOT_TRANS_CREATE_USER_DETAIL = 160,
	EOT_TRANS_SAVE_USER_MONEY = 161,
	EOT_TRANS_SAVE_USER_DETAIL = 162,
	EOT_TRANS_LOGIC_USER_BASE = 163,
	EOT_USER_DETAIL_ID = 164,
	EOT_USER_DETAIL_HASH_TABLE_ID = 165,
	EOT_USER_BANK_CACHE_ID = 166,
    EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID = 167,
    EOT_TRANS_USER_WEB_HANDLE_TRANS_ID = 168,
    EOT_TRANS_SHOW_USER_ID_HANDLE_TRANS_ID = 169,
	////////////////////////////logic server/////////////////////////////

	////////////////////////////login server/////////////////////////////
	EOT_ACCOUNTLOGIN_HASHTABLE_ID = 200,
	EOT_TRANS_GET_ACCOUNT = 201,
	EOT_TRANS_REGISTER_ACCOUNT = 202,
	EOT_TRANS_REGISTER_ACCOUNT_BIND_PHONE = 203,
	EOT_PHONE_AUTO_CODE_MGR_ID = 204,
	EOT_PHONE_AUTO_CODE_ID = 205,

	////////////////////////////login server/////////////////////////////
	////////////////////////////world server/////////////////////////////
	EOT_WORLD_ROOM_INFO_ID = 220,
	EOT_WORLD_ROOM_ID_MGR = 221,

	EOT_WORLD_PLAYER_ID = 223,
	EOT_WORLD_PLAYER_MGR_ID = 224,

	EOT_WORLD_GAME_ROOM_TRANS_ID = 225,
	EOT_WORLD_WEB_HANDLE_TRANS_ID = 226,
	////////////////////////////world server/////////////////////////////

	////////////////////////////game server/////////////////////////////
	EOT_GAME_DESK_ID = 250,
	EOT_GAME_ROOM_ID = 251,
	EOT_GAME_ROOM_ID_HASH_ID = 252,
	EOT_GAME_ROOM_ID_HASH_TABLE_ID = 253,
	EOT_GAME_ROOM_CONFIG_DESC_ID = 254,
	EOT_CONST_CONFIG_DESC_ID = 255,
	EOT_MAIL_CONFIG_DESC_ID = 256,
	EOT_GAME_PLAYER_ID = 257,
	EOT_GAME_PLAYER_HASH_ID = 258,
	EOT_GAME_PLAYER_HASH_TABLE_ID = 259,
	EOT_TRANS_GAME_PLAYER_BASE = 260,
	EOT_TRANS_QUERY_COIN_BALANCE_BASE = 261,

	EOT_GAME_ROBOT_ID = 262,
	EOT_GAME_ROBOT_ID_HASH_ID = 263,
	EOT_GAME_ROBOT_ID_HASH_TABLE_ID = 264,

	EOT_GAME_CREATE_ROBOT_TRANS_ID = 265,
    EOT_NAME_CONFIG_DESC_ID = 266,
    EOT_GAME_ROBOT_COMMON_ID = 267,
    EOT_GAME_ROBOT_MGR_ID = 268,


    ////////////////////////////game server/////////////////////////////


	///////////////////////////////////////////////////////////
	EOT_SF_END_ID = EOT_SERVER_FRAME_END_ID,
} EN_SERVERFRAME_SHMOBJ_TYPE;
