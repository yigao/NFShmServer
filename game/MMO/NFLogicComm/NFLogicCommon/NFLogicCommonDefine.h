// -------------------------------------------------------------------------
//    @FileName         :    NFLogicCommonDefine.h
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicCommonDefine
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"

#define MAX_ACCOUNT_EXIST_TIME 300
#define MAX_PLAYER_ACCOUNT_SIZE  128
#define WG_INT_MAX32 0x7FFFFFFFL
#ifdef NF_DEBUG_MODE

#define CACHE_DATA_SAVE_TIME 3000
#define SNSSVR_USER_MAIL_SAVE_TIME 1200
#define RANK_MAX_SAVE_TIME 30
#define ROBOT_MAX_SAVE_TIME 30
#define SYSTEM_DAY_MAX_SAVE_TIME 30
#define SNSSVR_MAX_ROLE_SIMPLE_NUM 5000
#else
#define CACHE_DATA_SAVE_TIME 1000
#define SNSSVR_USER_MAIL_SAVE_TIME 1200
#define RANK_MAX_SAVE_TIME 900
#define ROBOT_MAX_SAVE_TIME 300
#define SYSTEM_DAY_MAX_SAVE_TIME 300
#define SNSSVR_MAX_ROLE_SIMPLE_NUM  50000
#endif

#define PLAYER_ONLINESYN_TIME_GAP    60
#define PLAYER_SAVEROLE_MAX_TRYTIME 86400

#define PLAYER_MAX_DISCONNECT_RECONNECT_TIME 120
#define PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME (PLAYER_MAX_DISCONNECT_RECONNECT_TIME + 30)
#define PLAYER_MAX_DISCONNECT_EXIST_TIME 600
#define PLAYER_MAX_NO_MSG_TIME 3600

#define LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME  (PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME*2)
#define LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME  (LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME*10)
#define WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME  (LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME * 2)
#define WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME  (WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME * 5)

#define CLIENT_MAX_CMD_ID_VALUE 10000

typedef enum
{
    PLAYER_STATUS_NONE = 0,
    PLAYER_STATUS_ONLINE = 1,
    PLAYER_STATUS_OFFLINE = 2,
    PLAYER_STATUS_LOGOUT = 3,
    PLAYER_STATUS_DEAD = 4,
} PLAYER_STATUS;

typedef enum
{
    PLAYER_SCENE_STATUS_NONE = 0,
    PLAYER_SCENE_STATUS_Entering = 1,
    PLAYER_SCENE_STATUS_Leaveing = 2,
    PLAYER_SCENE_STATUS_Gameing = 3,
    PLAYER_SCENE_STATUS_Fighting = 4,
} PLAYER_SCENE_STATE;