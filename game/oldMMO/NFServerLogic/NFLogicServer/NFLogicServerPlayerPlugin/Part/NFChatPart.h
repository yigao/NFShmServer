// -------------------------------------------------------------------------
//    @FileName         :    NFChatPart.h
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFPart.h"

class NFChatPart : public NFPart
{
public:
    NFChatPart();

    virtual ~NFChatPart();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFChatPart)
};