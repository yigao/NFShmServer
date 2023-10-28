// -------------------------------------------------------------------------
//    @FileName         :    NFMallPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMallPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFMallPart : public NFShmObjTemplate<NFMallPart, EOT_LOGIC_PART_ID+PART_MALL, NFPart>
{
public:
    NFMallPart();

    virtual ~NFMallPart();

    int CreateInit();

    int ResumeInit();
};