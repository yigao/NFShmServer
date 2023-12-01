// -------------------------------------------------------------------------
//    @FileName         :    NFFestPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFestPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFFestPart : public NFShmObjTemplate<NFFestPart, EOT_LOGIC_PART_ID+PART_FEST, NFPart>
{
public:
    NFFestPart();

    virtual ~NFFestPart();

    int CreateInit();

    int ResumeInit();
public:
    int GetTaskMult() { return 1; }
};