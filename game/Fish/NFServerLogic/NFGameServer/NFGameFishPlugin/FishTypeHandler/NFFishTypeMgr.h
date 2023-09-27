// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "Fish/NFGameFish.h"

class NFGameFishDesk;
class NFFishTypeHandler;
class NFGameFishPlayer;
class NFFishBullet;
class NFGameFish;
class NFFishTypeMgr : public NFShmObj
{
public:
    NFFishTypeMgr();

    virtual ~NFFishTypeMgr();

    int CreateInit();

    int ResumeInit();

public:
    void Init(NFGameFishDesk *pDeskHandler);

    int OnHandleClientMessage(NFGameFishPlayer *pPlayer, NFDataPackage &packet);

    int GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet);

    int GetKilledDeathMul(NFGameFish *pFish, const NFFishBullet &bullet);

    uint64_t KillFishByType(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet);

    int OnKilledFish_AllType(NFGameFishPlayer *pPlayer, NFGameFish *pFish);

    int OnAddScore(NFGameFishPlayer *pPlayer, NFGameFish *pFish, uint64_t ullScoreMoney);//这个只用于技能里统计分数

    int DoubleCannonHandler(NFGameFishPlayer *pPlayer, NFGameFish *pFish);

    void SyncFishBomb(NFGameFishPlayer *pPlayer);

    void UserLeftDesk(NFGameFishPlayer *pPlayer);

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);

    void OnTimerAllType(int iTimerId);

    bool IsFreeze();

    void SetIsFreezs(bool isfreeze) { m_bIsFreeze = isfreeze; }
    //int GetFishBaseMul(NFGameFish* pFish, FishConfig* pFishConfig);

private:
    NFFishTypeHandler* AddFishTypeHandler(int iFishType);

    NFFishTypeHandler *FindFishTypeHandler(int iFishType);

    void ClearFishTypes();

    NFFishTypeHandler *CreateFishTypeHandle(int iFishType);

public:
    NFShmPtr<NFGameFishDesk> m_pDesk;
    NFShmHashMap<int, int, NFGAME_FISHTYPE_MAX_VALUE> m_mapFishTypeHandler;
    bool m_bIsFreeze;
    NFShmHashMap<int, uint64_t, 100> m_mapTimer_Player;//目前这里只用作双倍炮的定时，别的没用到
private:
DECLARE_IDCREATE(NFFishTypeMgr)
};