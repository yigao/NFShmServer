// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeKindBomb.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeKindBomb
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeKindBomb : public NFFishTypeHandler
{
public:
    NFFishTypeKindBomb();

    virtual ~NFFishTypeKindBomb();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual uint64_t KillFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledFishMul(NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledDeathMul(NFGameFish* pFish, const NFFishBullet& bullet);
    std::vector<NFGameFish *> GetKilledSubFishes(NFGameFish *mainFish);
private:
DECLARE_IDCREATE(NFFishTypeKindBomb)
};