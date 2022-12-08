// -------------------------------------------------------------------------
//    @FileName         :    NFChatPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatPart
//
// -------------------------------------------------------------------------

#include "NFChatPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFChatPart, EOT_LOGIC_CHAT_PART_ID, NFShmObj)

NFChatPart::NFChatPart() : NFPart()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFChatPart::~NFChatPart()
{
}

int NFChatPart::CreateInit()
{
    return 0;
}

int NFChatPart::ResumeInit()
{
    return 0;
}
