// -------------------------------------------------------------------------
//    @FileName         :    NFBuffPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFBuffPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFBuffPart : public NFShmObjTemplate<NFBuffPart, EOT_LOGIC_PART_ID + PART_BUFF, NFPart>
{
public:
    NFBuffPart();
    
    virtual ~NFBuffPart();
    
    int CreateInit();
    
    int ResumeInit();

public:
    //获取战力属性
    int64_t GetFightAttr(uint32_t ANum) { return 0; }
    
    //获取处于变身状态的天神ID
    int64_t GetFacadeDeityId() { return 0; }
};