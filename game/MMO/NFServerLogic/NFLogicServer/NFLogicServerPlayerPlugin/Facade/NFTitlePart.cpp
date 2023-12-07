// -------------------------------------------------------------------------
//    @FileName         :    NFTitlePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFTitlePart
//
// -------------------------------------------------------------------------

#include "NFTitlePart.h"
#include "ClientServer.pb.h"

NFTitlePart::NFTitlePart()
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

NFTitlePart::~NFTitlePart()
{
}

int NFTitlePart::CreateInit()
{
    return 0;
}

int NFTitlePart::ResumeInit()
{
    return 0;
}

int NFTitlePart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFTitlePart::UnInit()
{
    return NFPart::UnInit();
}

int NFTitlePart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_TITLE_INFO_REQ);
    return 0;
}

int NFTitlePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_TITLE_INFO_REQ:
        {
            OnHandleTitleInfoReq(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFTitlePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFTitlePart::FillFacadeProto(proto_ff::RoleFacadeProto& outproto)
{
    return NFPart::FillFacadeProto(outproto);
}

int NFTitlePart::OnHandleTitleInfoReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::CGTitleInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::GCTitleInfoRsp rsp;
    rsp.set_cur_wearing_title(m_pMaster->GetAttr(proto_ff::A_TITLE_ID));
    for (auto iter = m_titleMap.begin(); iter != m_titleMap.end(); ++iter)
    {
        auto pData = rsp.add_data();
        pData->CopyFrom(iter->second);
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_INFO_RSP, rsp);
    return 0;
}