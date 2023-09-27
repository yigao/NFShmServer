// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeHaiWangCrab.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeHaiWangCrab
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeHaiWangCrab : public NFFishTypeHandler
{
public:
    NFFishTypeHaiWangCrab();

    virtual ~NFFishTypeHaiWangCrab();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual uint64_t KillFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledFishMul(NFGameFish* pFish);
    virtual int OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    int OnHandleHaiWangCrabHitPart(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
private:
DECLARE_IDCREATE(NFFishTypeHaiWangCrab)
};