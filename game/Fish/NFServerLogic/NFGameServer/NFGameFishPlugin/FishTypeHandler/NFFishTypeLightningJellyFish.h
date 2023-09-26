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

private:
DECLARE_IDCREATE(NFFishTypeLightningJellyFish)
};