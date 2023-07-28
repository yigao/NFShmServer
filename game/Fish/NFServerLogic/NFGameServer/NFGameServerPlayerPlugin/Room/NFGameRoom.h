// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoom.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoom
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "AllProtocol.h"

#define ONE_GAME_ROOM_MAX_DESK_COUNT 255

class NFGameRoom : public NFShmObj
{
public:
    NFGameRoom();

    virtual ~NFGameRoom();

    int CreateInit();

    int ResumeInit();

    virtual int OnTimer(int timeId, int callcount);
public:
    //游戏开始时，通知平台
    int OnGameBegin(int iDeskId);

    //游戏结束时，通知平台
    int OnGameFinish(int iDeskId);

    //判断座位是否有人玩游戏
    bool IsPlayGame(int iDeskId, int iDeskStation);

    bool IsPlayGameCanLeave(int iDeskId, int iDeskStation);

    //清理闲逛人员
    int ClearIdleUser(uint64_t playerId);

    //清理用户异常退出后的残留的脏数据
    int ClearDirtyData(uint64_t playerId);

    //清理超时不操作用户
    int ClearTimeOutUser(uint64_t playerId);

    //清理不在线用户
    int ClearOfflineUser(uint64_t playerId);

    //因某种原因踢出用户
    void KickUser(uint64_t playerId, int nReasonCode);

    int ClearJiangChi();
    int ChangeJiangChi(int64_t jiangchi);

    //抽水计算，结果为抽水后玩家赢得钱
    int GameDataCommit(uint64_t cur_fee, uint64_t cur_ach, int64_t cur_win);

    const proto_ff_s::E_RoomRoom_s* GetRoomConfig();
public:
    int UpdateUserMoney(int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange);
public:
    uint32_t m_gameId;
    uint32_t m_roomId;
    NFCommonStr m_gameName;
    NFCommonStr m_roomName;
    NFShmVector<int, ONE_GAME_ROOM_MAX_DESK_COUNT> m_AryDesks; //desk global id
    int m_statTimer;
    int m_lastSendTime;
private:
DECLARE_IDCREATE(NFGameRoom)
};