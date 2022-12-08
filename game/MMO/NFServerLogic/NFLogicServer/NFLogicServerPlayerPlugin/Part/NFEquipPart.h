// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFPart.h"

class NFEquipPart : public NFPart
{
public:
    NFEquipPart();

    virtual ~NFEquipPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFEquipPart)
};