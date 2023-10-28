// -------------------------------------------------------------------------
//    @FileName         :    NFPackagePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackagePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFPackagePart : public NFShmObjTemplate<NFPackagePart, EOT_LOGIC_PART_ID+PART_PACKAGE, NFPart>
{
public:
    NFPackagePart();

    virtual ~NFPackagePart();

    int CreateInit();

    int ResumeInit();
};