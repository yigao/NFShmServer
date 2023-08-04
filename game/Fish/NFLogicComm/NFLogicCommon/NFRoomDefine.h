// -------------------------------------------------------------------------
//    @FileName         :    NFRoomDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoomDefine
//
// -------------------------------------------------------------------------

#pragma once

#define MAX_GAME_TYPE_NUM 10
#define MAX_GAME_ROOM_NUM 10
#define MAX_ONE_ROOM_DESK_NUM 300
#define MAX_ONE_ROOM_ONE_DESK_PLAYER_NUM 10
#define MAX_ONE_ROOM_PLAYER_NUM MAX_ONE_ROOM_DESK_NUM*MAX_ONE_ROOM_ONE_DESK_PLAYER_NUM
#define MAX_GAME_DESK_CHAIR_NUM 10

//游戏状态
enum EnumGameStatus
{
    GAMES_FREE = 0,     //空闲状态
    GAMES_PLAYING = 1,//游戏状态
};