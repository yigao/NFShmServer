// -------------------------------------------------------------------------
//    @FileName         :    NFPetPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPetPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFPetPart : public NFPart
{
public:
    NFPetPart();
    
    virtual ~NFPetPart();
    
    int CreateInit();
    
    int ResumeInit();
public:
    void OnChgAttr() {}
private:
DECLARE_IDCREATE(NFPetPart)
};