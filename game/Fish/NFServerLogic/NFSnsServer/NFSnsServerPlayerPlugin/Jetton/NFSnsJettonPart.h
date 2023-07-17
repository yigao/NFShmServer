// -------------------------------------------------------------------------
//    @FileName         :    NFSnsJettonPart.h
//    @Author           :    gaoyi
//    @Date             :    23-7-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsJettonPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFSnsPart.h"

class NFSnsJettonPart : public NFSnsPart
{
public:
    NFSnsJettonPart();

    virtual ~NFSnsJettonPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFSnsJettonPart)
};