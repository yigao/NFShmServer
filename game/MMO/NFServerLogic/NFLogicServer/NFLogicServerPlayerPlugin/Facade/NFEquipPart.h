// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFEquipPart : public NFShmObjTemplate<NFEquipPart, EOT_LOGIC_PART_ID+PART_EQUIP, NFPart>
{
public:
    NFEquipPart();

    virtual ~NFEquipPart();

    int CreateInit();

    int ResumeInit();
};