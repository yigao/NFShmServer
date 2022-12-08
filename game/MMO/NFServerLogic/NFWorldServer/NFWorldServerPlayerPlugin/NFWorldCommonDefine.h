// -------------------------------------------------------------------------
//    @FileName         :    WorldCommonDefine.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/12
//    @Email			:    445267987@qq.com
//    @Module           :    WorldCommonDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

enum WorldPlayerState
{
    PLAYER_STATE_NULL,
    PLAYER_STATE_LOGIN,			// 登录游戏
    PLAYER_STATE_QUEUE,			// 排队状态
    PLAYER_STATE_LOADCHARLIS,	// 加载角色列表
    PLAYER_STATE_ENTER,			// 进入游戏
    PLAYER_STATE_GAMING,		// 游戏状态
    PLAYER_STATE_SWITCH,		// 切换场景
    PLAYER_STATE_LOGOUT,		// 登出游戏
    PLAYER_STATE_DISCONNECT,    // 断线状态
};

#define WORLD_SERVER_MAX_ONLINE_COUNT 10000


