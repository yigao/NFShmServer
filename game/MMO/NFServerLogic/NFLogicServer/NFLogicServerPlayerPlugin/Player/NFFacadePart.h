// -------------------------------------------------------------------------
//    @FileName         :    NFFacadePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFacadePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFFacadePart : public NFShmObjTemplate<NFFacadePart, EOT_LOGIC_PART_ID+PART_FACADE, NFPart>
{
public:
    NFFacadePart();

    virtual ~NFFacadePart();

    int CreateInit();

    int ResumeInit();
};