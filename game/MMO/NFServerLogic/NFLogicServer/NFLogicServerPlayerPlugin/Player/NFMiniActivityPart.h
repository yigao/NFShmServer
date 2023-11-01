// -------------------------------------------------------------------------
//    @FileName         :    NFMIniActivity.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMIniActivity
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFMiniActivityPart : public NFShmObjTemplate<NFMiniActivityPart, EOT_LOGIC_PART_ID+PART_MINI_ACTIVITY, NFPart>
{
public:
    NFMiniActivityPart();

    virtual ~NFMiniActivityPart();

    int CreateInit();

    int ResumeInit();
};