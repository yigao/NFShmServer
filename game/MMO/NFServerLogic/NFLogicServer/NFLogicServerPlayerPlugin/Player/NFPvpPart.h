// -------------------------------------------------------------------------
//    @FileName         :    NFPvpPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFPvpPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFPvpPart : public NFPart
{
public:
    NFPvpPart();

    virtual ~NFPvpPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFPvpPart)
};