// -------------------------------------------------------------------------
//    @FileName         :    NFMountPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMountPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFMountPart : public NFShmObjTemplate<NFMountPart, EOT_LOGIC_PART_ID+PART_MOUNT, NFPart>
{
public:
    NFMountPart();

    virtual ~NFMountPart();

    int CreateInit();

    int ResumeInit();
};