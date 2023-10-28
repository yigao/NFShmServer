// -------------------------------------------------------------------------
//    @FileName         :    NFArmorPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFArmorPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFArmorPart : public NFShmObjTemplate<NFArmorPart, EOT_LOGIC_PART_ID+PART_ARMOR, NFPart>
{
public:
    NFArmorPart();

    virtual ~NFArmorPart();

    int CreateInit();

    int ResumeInit();
};