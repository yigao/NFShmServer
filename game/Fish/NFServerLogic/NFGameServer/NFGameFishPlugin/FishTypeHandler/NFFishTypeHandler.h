// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeHandler.h
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeHandler
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFGameFishDefine.h"
#include "NFComm/NFShmCore/NFShmPtr.h"

class NFGameFishDesk;
class NFGameFishPlayer;
class NFGameFish;
class NFFishBullet;
class NFFishTypeHandler : public NFShmObj
{
public:
    NFFishTypeHandler();

    virtual ~NFFishTypeHandler();

    int CreateInit();

    int ResumeInit();

    NFShmPtr<NFGameFishDesk> m_pDesk;
public:
    int Init(NFGameFishDesk* pDesk);
    virtual int OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual uint64_t KillFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledFishMul(NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledDeathMul(NFGameFish* pFish, const NFFishBullet& bullet);
    virtual uint32_t GetFishMaxWinMoney(NFGameFish fish, uint32_t bulletMul, uint32_t bulletMoney);
    virtual void SyncFishBomb(NFGameFishPlayer* pPlayer);
    virtual void UserLeftDesk(NFGameFishPlayer* pPlayer);
    virtual int OnAddScore(NFGameFishPlayer* pPlayer, NFGameFish* pFish, uint64_t ullScoreMoney);//这个只用于技能里统计分数
DECLARE_IDCREATE(NFFishTypeHandler)
};