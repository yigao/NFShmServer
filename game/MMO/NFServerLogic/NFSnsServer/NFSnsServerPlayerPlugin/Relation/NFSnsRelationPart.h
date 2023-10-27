// -------------------------------------------------------------------------
//    @FileName         :    NFSnsRelationPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsRelationPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFSnsPart.h"

class NFSnsRelationPart : public NFShmObjTemplate<NFSnsRelationPart, EOT_SNS_PART_ID+SNS_PART_RELATION, NFSnsPart>
{
public:
    NFSnsRelationPart();

    virtual ~NFSnsRelationPart();

    int CreateInit();

    int ResumeInit();
};