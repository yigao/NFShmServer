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
/*
    uint32_t groupIndex = relationInfoReq.groupindex();
    if (groupIndex < 0 || groupIndex >= GROUP_MAX)
    {
        MMOLOG_FMT_ERROR("[center] CWRelationInfoReq groupIndex is error. groupIndex:%u, CharID:%llu ", groupIndex, charID);
        return false;
    }
    //检查离线数据
    auto pOfflineCharacterData = g_GetCacheMgr()->GetRoleSimple(charID);
    if (nullptr == pOfflineCharacterData)
    {
        MMOLOG_FMT_ERROR("[center] CWRelationInfoReq  pOfflineCharacterData is nil. CharID:%llu ", charID);
        return false;
    }
    //好友数据
    Relation* pRelation = findRelation(charID);
    if (nullptr == pRelation)
    {
        MMOLOG_FMT_ERROR("[center] CWRelationInfoReq pRelation is nil,CharID:%llu ", charID);
        return false;
    }

    return HandleRelationInfoReq(charID, relationInfoReq);
*/
    return 0;
}