// -------------------------------------------------------------------------
//    @FileName         :    NFDeityPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDeityPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFDeityPart : public NFShmObjTemplate<NFDeityPart, EOT_LOGIC_PART_ID+PART_DEITY, NFPart>
{
public:
    NFDeityPart();

    virtual ~NFDeityPart();

    int CreateInit();

    int ResumeInit();
public:
    bool IsActiveDeity(int64_t id) { return false; }
};