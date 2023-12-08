// -------------------------------------------------------------------------
//    @FileName         :    NFFestPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFestPart
//
// -------------------------------------------------------------------------

#include "NFFestPart.h"
#include "Fest.pb.h"

NFFestPart::NFFestPart()
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

NFFestPart::~NFFestPart()
{
}

int NFFestPart::CreateInit()
{
    return 0;
}

int NFFestPart::ResumeInit()
{
    return 0;
}

int NFFestPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFFestPart::UnInit()
{
    return NFPart::UnInit();
}

int NFFestPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::FEST_DETAIL_INFO_REQ);
    return 0;
}

int NFFestPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::FEST_DETAIL_INFO_REQ:
        {
            OnHandleDetailInfoReq(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFFestPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFFestPart::OnHandleDetailInfoReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::Fest_DetailReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    //int32_t festid = req.fest_id();
    //int32_t tplid = req.template_id();
    
    proto_ff::Fest_DetailRsp rsp;
    m_pMaster->SendMsgToClient(proto_ff::FEST_DETAIL_INFO_RSP, rsp);
    return 0;
}
