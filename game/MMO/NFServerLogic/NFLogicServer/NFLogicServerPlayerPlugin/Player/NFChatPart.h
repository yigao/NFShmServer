// -------------------------------------------------------------------------
//    @FileName         :    NFChatPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFChatPart : public NFShmObjTemplate<NFChatPart, EOT_LOGIC_PART_ID+PART_CHAT, NFPart>
{
public:
    NFChatPart();

    virtual ~NFChatPart();

    int CreateInit();

    int ResumeInit();
};