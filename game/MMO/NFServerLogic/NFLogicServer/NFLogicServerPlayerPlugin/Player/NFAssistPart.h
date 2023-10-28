// -------------------------------------------------------------------------
//    @FileName         :    NFAssistPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAssistPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFAssistPart : public NFShmObjTemplate<NFAssistPart, EOT_LOGIC_PART_ID+PART_ASSIST, NFPart>
{
public:
    NFAssistPart();

    virtual ~NFAssistPart();

    int CreateInit();

    int ResumeInit();
};