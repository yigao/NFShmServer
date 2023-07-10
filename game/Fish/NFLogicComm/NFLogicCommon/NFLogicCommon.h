//
// Created by gaoyi on 2022/9/21.
//

#pragma once

#include "NFComm/NFShmCore/NFShmString.h"

#define NF_SERVER_COMMON_MAX_STRING_32 32
#define NF_SERVER_COMMON_MAX_STRING_64 64
#define NF_SERVER_COMMON_MAX_STRING_128 128
#define NF_SERVER_COMMON_MAX_STRING_256 256
#define NF_SERVER_COMMON_USE_STRING NF_SERVER_COMMON_MAX_STRING_128

typedef NFShmString<NF_SERVER_COMMON_USE_STRING> NFCommonStr;

/**
 * @brief 玩家最大断线重连时间  120秒
 */
#define PLAYER_MAX_DISCONNECT_RECONNECT_TIME 120

/**
 * @brief 玩家最大断线游戏存在时间  150秒
 */
#define PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME (PLAYER_MAX_DISCONNECT_RECONNECT_TIME + 30)
#define PLAYER_MAX_DISCONNECT_EXIST_TIME 600
#define PLAYER_MAX_NO_MSG_TIME 3600

/**
 * @brief 玩家最大断线逻辑服数据存在时间  300秒
 */
#define LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME  (PLAYER_MAX_DISCONNECT_GAME_EXIST_TIME*2)

/**
 * @brief 如果在游戏中玩家最大断线逻辑服数据存在时间  900秒 15分钟
 */
#define LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME  (LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME*3)

/**
 * @brief 玩家最大断线世界服数据存在时间  600秒 10分钟
 */
#define WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME  (LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME * 2)

/**
 * @brief 如果在游戏中玩家最大断线世界服数据存在时间  1800秒 30分钟
 */
#define WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME  (WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME * 3)


#define LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME 60

class NFLogicCommon {
public:
    NFLogicCommon();
    virtual ~NFLogicCommon();
public:
    static std::string GetLoginToken(const std::string& account, uint64_t userId, uint64_t time, const std::string& specialStr);
};


