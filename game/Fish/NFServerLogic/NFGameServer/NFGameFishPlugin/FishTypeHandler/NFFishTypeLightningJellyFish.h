// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeLightningJellyFish.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeLightningJellyFish
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeLightningJellyFish : public NFFishTypeHandler
{
public:
    NFFishTypeLightningJellyFish();

    virtual ~NFFishTypeLightningJellyFish();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual uint64_t KillFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledFishMul(NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledDeathMul(NFGameFish* pFish, const NFFishBullet& bullet);
    std::vector<NFGameFish*> GetKilledSubFishes(NFGameFish* pMainFish);
private:
DECLARE_IDCREATE(NFFishTypeLightningJellyFish)
};