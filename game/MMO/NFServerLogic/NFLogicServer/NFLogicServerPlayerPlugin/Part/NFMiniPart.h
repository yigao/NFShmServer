// -------------------------------------------------------------------------
//    @FileName         :    NFMiniPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFMiniPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFPart.h"

class NFMiniPart : public NFPart
{
public:
    NFMiniPart();

    virtual ~NFMiniPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFMiniPart)
};