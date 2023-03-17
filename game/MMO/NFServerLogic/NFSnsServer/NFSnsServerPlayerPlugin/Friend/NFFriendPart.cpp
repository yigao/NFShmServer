// -------------------------------------------------------------------------
//    @FileName         :    NFFriendPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFFriendPart
//
// -------------------------------------------------------------------------

#include "NFFriendPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFriendPart, EOT_SNS_FriendPart_ID, NFShmObj
)

NFFriendPart::NFFriendPart()
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

NFFriendPart::~NFFriendPart()
{
}

int NFFriendPart::CreateInit()
{
    return 0;
}

int NFFriendPart::ResumeInit()
{
    return 0;
}

int NFFriendPart::Init(const proto_ff::RoleDBSnsDetail &data)
{
    return NFSnsPart::Init(data);
}

int NFFriendPart::UnInit()
{
    return NFSnsPart::UnInit();
}

int NFFriendPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFSnsPart::OnHandleClientMessage(msgId, packet);
}

int NFFriendPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFSnsPart::OnHandleServerMessage(msgId, packet);
}

int NFFriendPart::RegisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return 0;
}

int NFFriendPart::RegisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return 0;
}
