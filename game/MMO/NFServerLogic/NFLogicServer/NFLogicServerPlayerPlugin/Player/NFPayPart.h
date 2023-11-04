// -------------------------------------------------------------------------
//    @FileName         :    NFPayPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPayPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFPayPart : public NFShmObjTemplate<NFPayPart, EOT_LOGIC_PART_ID+PART_PAY, NFPart>
{
public:
    NFPayPart();

    virtual ~NFPayPart();

    int CreateInit();

    int ResumeInit();
    
    //累计充值人名币
    uint32_t RealRmb() { return 0; }
};