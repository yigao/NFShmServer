// -------------------------------------------------------------------------
//    @FileName         :    NFDupPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDupPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFDupPart : public NFPart
{
public:
    NFDupPart();

    virtual ~NFDupPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFDupPart)
};