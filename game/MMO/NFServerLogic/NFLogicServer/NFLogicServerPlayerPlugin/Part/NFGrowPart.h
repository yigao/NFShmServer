// -------------------------------------------------------------------------
//    @FileName         :    NFGrowPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFPart.h"

class NFGrowPart : public NFPart
{
public:
    NFGrowPart();

    virtual ~NFGrowPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFGrowPart)
};