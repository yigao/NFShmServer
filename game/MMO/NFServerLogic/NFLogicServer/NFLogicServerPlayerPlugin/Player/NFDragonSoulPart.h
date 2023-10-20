// -------------------------------------------------------------------------
//    @FileName         :    NFDragonSoulPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDragonSoulPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFDragonSoulPart : public NFPart
{
public:
    NFDragonSoulPart();

    virtual ~NFDragonSoulPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFDragonSoulPart)
};