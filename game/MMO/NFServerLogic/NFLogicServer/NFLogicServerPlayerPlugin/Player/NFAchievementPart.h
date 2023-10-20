// -------------------------------------------------------------------------
//    @FileName         :    NFAchievementPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAchievementPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFAchievementPart : public NFPart
{
public:
    NFAchievementPart();

    virtual ~NFAchievementPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFAchievementPart)
};