// -------------------------------------------------------------------------
//    @FileName         :    NFWelfarePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFWelfarePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFWelfarePart : public NFShmObjTemplate<NFWelfarePart, EOT_LOGIC_PART_ID+PART_WELFARE, NFPart>
{
public:
    NFWelfarePart();

    virtual ~NFWelfarePart();

    int CreateInit();

    int ResumeInit();
};