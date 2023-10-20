// -------------------------------------------------------------------------
//    @FileName         :    NFAncientPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAncientPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFAncientPart : public NFPart
{
public:
    NFAncientPart();

    virtual ~NFAncientPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFAncientPart)
};