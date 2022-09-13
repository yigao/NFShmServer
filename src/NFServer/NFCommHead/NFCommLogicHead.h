// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicHead.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicHead
//
// -------------------------------------------------------------------------

#pragma once

/*
* @biref 定义一些公共逻辑类
*/

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFShmCore/NFSizeString.h"

#define MAX_ACCOUNT_EXIST_TIME 300
#define MAX_PLAYER_ACCOUNT_SIZE  128
#define WG_INT_MAX32 0x7FFFFFFFL
#ifdef NF_DEBUG_MODE

#define SNSSVR_USER_SIMPLE_SAVE_TIME 3000
#define SNSSVR_USER_MAIL_SAVE_TIME 1200
#define RANK_MAX_SAVE_TIME 30
#define ROBOT_MAX_SAVE_TIME 30
#define SYSTEM_DAY_MAX_SAVE_TIME 30
#else
#define SNSSVR_USER_SIMPLE_SAVE_TIME 1000
#define SNSSVR_USER_MAIL_SAVE_TIME 1200
#define RANK_MAX_SAVE_TIME 900
#define ROBOT_MAX_SAVE_TIME 300
#define SYSTEM_DAY_MAX_SAVE_TIME 300
#endif

#define PLAYER_MAX_DISCONNECT_RECONNECT_TIME 120
#define PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME (PLAYER_MAX_DISCONNECT_RECONNECT_TIME + 30)
#define PLAYER_MAX_DISCONNECT_EXIST_TIME 600
#define PLAYER_MAX_NO_MSG_TIME 3600

#define LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME  (PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME*2)
#define LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME  (LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME*10)
#define WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME  (LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME * 2)
#define WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME  (WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME * 5)

#define MAX_VALID_PLAYER_STAT_TIME (15*60)
#define WEEK_SECOND_COUNT 604800
#define DAY_SECOND_COUNT 86400

//游戏状态
enum EnumGameStatus
{
    GAMES_FREE = 0,     //空闲状态
    GAMES_PLAYING = 1,//游戏状态
};

enum EnumUserStatus
{
    USER_STATUS_NUL     =   0,  //没有状态
    USER_STATUS_FREE    =   1,  //站立状态
    USER_STATUS_SIT     =   2,  //坐下状态
    USER_STATUS_READY   =   3,  //同意状态
    USER_STATUS_LOOKON  =   4,  //旁观状态
    USER_STATUS_PLAY    =   5,  //游戏状态
    USER_STATUS_OFFLINE =   6,  //断线状态
};

//结束原因
enum EnumGameEnd
{
    GAME_END_NORMAL  =   0,								//常规结束
    GAME_END__DISMISS =   1,								//游戏解散
    GAME_END_USER_LEFT = 2,								//用户离开
};

typedef enum
{
    PLAYER_STATUS_NONE = 0,
    PLAYER_STATUS_ONLINE = 1,
    PLAYER_STATUS_OFFLINE = 2,
    PLAYER_STATUS_LOGOUT = 3,
    PLAYER_STATUS_DEAD = 4,
} PLAYER_STATUS;

#include <string>

typedef NFSizeString<MAX_PLAYER_ACCOUNT_SIZE> SZ_USER_ACCOUNT;

namespace std
{
    template<>
    class hash<SZ_USER_ACCOUNT>
    {
    public:
        size_t operator()(const SZ_USER_ACCOUNT &s) const
        {
            return std::hash<std::string>()(s.GetString());
        }
    };
}


