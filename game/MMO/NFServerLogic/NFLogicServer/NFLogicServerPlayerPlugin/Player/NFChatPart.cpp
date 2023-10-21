// -------------------------------------------------------------------------
//    @FileName         :    NFChatPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatPart
//
// -------------------------------------------------------------------------

#include "NFChatPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFChatPart, EOT_LOGIC_PART_ID+PART_CHAT, NFPart
)

NFChatPart::NFChatPart()
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
