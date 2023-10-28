// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFMissionPart : public NFShmObjTemplate<NFMissionPart, EOT_LOGIC_PART_ID+PART_MISSION, NFPart>
{
public:
    NFMissionPart();

    virtual ~NFMissionPart();

    int CreateInit();

    int ResumeInit();
};