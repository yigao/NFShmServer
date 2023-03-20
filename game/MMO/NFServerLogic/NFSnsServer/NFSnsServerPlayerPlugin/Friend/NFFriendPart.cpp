// -------------------------------------------------------------------------
//    @FileName         :    NFFriendPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFFriendPart
//
// -------------------------------------------------------------------------

#include "NFFriendPart.h"
#include "ClientServerCmd.pb.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "Relation.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFLogicCommon/RelationDefine.h"
#include "Cache/NFRoleSimple.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFriendPart, EOT_SNS_FriendPart_ID, NFSnsPart)

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
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_CENTER_RELATION_DATA_REQ:
        {
            OnHandleRelationDataReq(msgId, packet);
            break;
        }
        default:
            break;
    }

    return 0;
}

int NFFriendPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFSnsPart::OnHandleServerMessage(msgId, packet);
}

int NFFriendPart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_CENTER_RELATION_DATA_REQ, SNS_PART_FRIEND);
    return 0;
}

int NFFriendPart::RetisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFFriendPart::OnHandleRelationDataReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CWRelationDataReq relationInfoReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, relationInfoReq);

    //检查分组索引

    uint32_t groupIndex = relationInfoReq.groupindex();
    if (groupIndex >= GROUP_MAX)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_cid, "CWRelationInfoReq groupIndex is error. groupIndex:{}, CharID:{} ", groupIndex, m_cid);
        return -1;
    }

    auto pRoleSimple = GetRoleSimple();
    if (pRoleSimple == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_cid, "CWRelationInfoReq  pRoleSimple is nil. m_cid:{} ", m_cid);
        return -1;
    }

    proto_ff::WCRelationDataRsp relationInfoRsp;

    //发送数据到看客户端
    relationInfoRsp.set_groupindex(groupIndex);
    pRoleSimple->SendMsgToClient(proto_ff::CENTER_TO_CLIENT_RELATION_DATA_RSP, relationInfoRsp);
    return 0;
}