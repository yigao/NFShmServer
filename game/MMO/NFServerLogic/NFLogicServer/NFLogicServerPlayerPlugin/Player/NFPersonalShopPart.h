// -------------------------------------------------------------------------
//    @FileName         :    NFPersonalShopPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPersonalShopPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFPersonalShopPart : public NFShmObjTemplate<NFPersonalShopPart, EOT_LOGIC_PART_ID+PART_PersonalShop, NFPart>
{
public:
    NFPersonalShopPart();

    virtual ~NFPersonalShopPart();

    int CreateInit();

    int ResumeInit();
};