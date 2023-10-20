// -------------------------------------------------------------------------
//    @FileName         :    NFTitlePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFTitlePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFTitlePart : public NFPart
{
public:
    NFTitlePart();

    virtual ~NFTitlePart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFTitlePart)
};