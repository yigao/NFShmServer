// -------------------------------------------------------------------------
//    @FileName         :    NFGVBPDataPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGVBPDataPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFGVBPDataPart : public NFShmObjTemplate<NFGVBPDataPart, EOT_LOGIC_PART_ID+PART_GVBPData, NFPart>
{
public:
    NFGVBPDataPart();

    virtual ~NFGVBPDataPart();

    int CreateInit();

    int ResumeInit();
};