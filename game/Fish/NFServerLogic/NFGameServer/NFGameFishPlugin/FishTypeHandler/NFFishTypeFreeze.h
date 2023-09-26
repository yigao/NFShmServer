// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFreeze.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFreeze
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"
#include "AllProtocol.h"

class NFFishTypeFreeze : public NFFishTypeHandler
{
public:
    NFFishTypeFreeze();

    virtual ~NFFishTypeFreeze();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual uint64_t KillFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    std::vector<NFGameFish *> GetKilledSubFishes(NFGameFish *mainFish);
public:
    virtual int OnTimer(int timeId, int callcount);
public:
    proto_ff_s::gcFreezeFishes_s m_gcFreezeFishes;
    int m_iTimerObjId_Freeze;
    uint64_t m_ullFreezeStartTime;
private:
DECLARE_IDCREATE(NFFishTypeFreeze)
};