// -------------------------------------------------------------------------
//    @FileName         :    NFPartStar.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPartStar
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFStarPart: public NFShmObjTemplate<NFStarPart, EOT_LOGIC_PART_ID+PART_STAR, NFPart>
{
public:
    NFStarPart();

    virtual ~NFStarPart();

    int CreateInit();

    int ResumeInit();
};