// -------------------------------------------------------------------------
//    @FileName         :    NFFactionPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFactionPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFFactionPart : public NFShmObjTemplate<NFFactionPart, EOT_LOGIC_PART_ID+PART_FACTION, NFPart>
{
public:
    NFFactionPart();

    virtual ~NFFactionPart();

    int CreateInit();

    int ResumeInit();
};