// -------------------------------------------------------------------------
//    @FileName         :    NFSoulPart.h
//    @Author           :    gaoyi
//    @Date             :    23-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFSoulPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFSoulPart : public NFShmObjTemplate<NFSoulPart, EOT_LOGIC_PART_ID+PART_SOUL, NFPart>
{
public:
    NFSoulPart();
    
    virtual ~NFSoulPart();
    
    int CreateInit();
    int ResumeInit();
    
    bool IsCmptTaskAll() { return false; }
};