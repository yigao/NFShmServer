// -------------------------------------------------------------------------
//    @FileName         :    NFVipPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFVipPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFVipPart : public NFPart
{
public:
    NFVipPart();

    virtual ~NFVipPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFVipPart)
};