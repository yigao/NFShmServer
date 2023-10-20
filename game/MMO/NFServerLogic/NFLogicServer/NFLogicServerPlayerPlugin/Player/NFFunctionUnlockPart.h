// -------------------------------------------------------------------------
//    @FileName         :    NFFunctionUnlockPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFunctionUnlockPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFFunctionUnlockPart : public NFPart
{
public:
    NFFunctionUnlockPart();

    virtual ~NFFunctionUnlockPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFunctionUnlockPart)
};