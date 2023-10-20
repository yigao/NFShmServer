// -------------------------------------------------------------------------
//    @FileName         :    NFSnsRelationPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsRelationPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFSnsRelationPart : public NFShmObj
{
public:
    NFSnsRelationPart();

    virtual ~NFSnsRelationPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFSnsRelationPart)
};