// -------------------------------------------------------------------------
//    @FileName         :    NFMiniPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMiniPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFMiniPart : public NFShmObjTemplate<NFMiniPart, EOT_LOGIC_PART_ID+PART_MINI, NFPart>
{
public:
    NFMiniPart();

    virtual ~NFMiniPart();

    int CreateInit();

    int ResumeInit();
};