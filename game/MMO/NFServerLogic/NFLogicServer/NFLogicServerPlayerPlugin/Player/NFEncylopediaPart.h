// -------------------------------------------------------------------------
//    @FileName         :    NFEncylopediaPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEncylopediaPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFEncylopediaPart : public NFShmObjTemplate<NFEncylopediaPart, EOT_LOGIC_PART_ID+PART_ENCYLOPEDIA, NFPart>
{
public:
    NFEncylopediaPart();

    virtual ~NFEncylopediaPart();

    int CreateInit();

    int ResumeInit();
};