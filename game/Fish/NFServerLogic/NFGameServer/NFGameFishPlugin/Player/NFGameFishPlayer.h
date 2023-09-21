// -------------------------------------------------------------------------
//    @FileName         :    NFGameFishPlayer.h
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFishPlayer
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "Fish/NFFishBulletMgr.h"

#define MAX_GAME_FISH_PLAYER_HIT_FISH_COUNT 500

class NFGameFishDesk;
class NFGameFish;
class NFGameFishPlayer
{
public:
    NFGameFishPlayer();

    virtual ~NFGameFishPlayer();

    int CreateInit();

    int ResumeInit();

    void SetDeskHandle(NFGameFishDesk* pDesk) { m_pDesk = pDesk; }
    uint64_t GetPlayerID() const { return m_ullPlayerId; }

    void SetPlayerID(uint64_t playerId) { m_ullPlayerId = playerId; }

    uint32_t GetChairIdForClient() { return m_uChairId+1; }
    int32_t GetRealPlayerChairIdForRobot();

    bool IsRobot() const { return m_isRobot; }

    int ShootBullet(NFIPluginManager* pPluginManager, NFFishBullet& bullet);
    void SetDoubleGunValueOn(int iOnOff);
    int  GetDoubeGunValueOn();


    void SendUserMoney();

    void ResetPlayerData();

    int Tick();

    uint64_t GetCurMoney();
    uint64_t GetMaxWinMoney() { return 10000000000; }
public:
    //获取子弹伤害
    double GetBulletHarmData();

    //清除打击鱼次数
    void ResetHitFishCount(const NFGameFish& serverFishTraceInfo);
    void AddHitFishCount(const NFGameFish& serverFishTraceInfo, double dbBulletHarm);
    double GetHitFishCount(const NFGameFish& serverFishTraceInfo);

    //玩家变化的总消耗和总捕获
    void AddUserChangedTotalShootMoney(int64_t iChangedMoney);

    void AddUserChangedTotalCaptureMoney(int64_t iChangedMoney);
    void AddCaptureMoney(int64_t ullChangedMoney);

    int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win);

    int AchievementCount(uint64_t Count, uint64_t fee);

    int UpdateUserInfo(const proto_ff_s::GamePlayerDetailData_s* pUserDetailInfo);
public:
    int m_iIndex;
    NFCommonStr m_strUserName;
    uint64_t m_ullPlayerId;
    int32_t m_uChairId;
    uint32_t m_iGameId;
    uint32_t m_iRoomId;
    int32_t m_iDeskId;
    NFShmPtr<NFGameFishDesk> m_pDesk;

    bool m_isRobot;
    bool m_online;
    bool m_ready;
    uint64_t m_lastDisconnectTime;
    int m_iDoubleGunValueOnOff;
    //------------------------------

    uint16_t m_nCurBulletLevel;//这个是和客户端定义的一样，最小从1开始

    uint64_t m_lastSaveUserMoney;

    uint32_t m_uLockOnOff;
    uint32_t m_uLockFishId;
    uint32_t m_uAutoShootOnOff;
    int32_t  m_iBulletSpeedLev;

    NFFishBulletMgr m_BulletMgr;

    NFShmHashMap<int, double, MAX_GAME_FISH_PLAYER_HIT_FISH_COUNT> m_arHitNormalFishCount; //玩家打击普通鱼次数
    //玩家自己总消耗和总捕获

    int64_t m_iUserChangedTotalShootMoney;   //玩家总发射金币
    int64_t m_iUserChangedTotalCaptureMoney; //玩家总捕获金币
};
