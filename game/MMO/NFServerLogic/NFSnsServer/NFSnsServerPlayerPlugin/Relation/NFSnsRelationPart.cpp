// -------------------------------------------------------------------------
//    @FileName         :    NFSnsRelationPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsRelationPart
//
// -------------------------------------------------------------------------

#include "NFSnsRelationPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Relation.pb.h"

NFSnsRelationPart::NFSnsRelationPart()
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

NFSnsRelationPart::~NFSnsRelationPart()
{
}

int NFSnsRelationPart::CreateInit()
{
    return 0;
}

int NFSnsRelationPart::ResumeInit()
{
    return 0;
}

int NFSnsRelationPart::Init(NFPlayerDetail *pMaster, uint32_t partType, const proto_ff::RoleDBSnsDetail &data)
{
    return NFSnsPart::Init(pMaster, partType, data);
}

int NFSnsRelationPart::UnInit()
{
    return NFSnsPart::UnInit();
}

int NFSnsRelationPart::LoadFromDB(const proto_ff::RoleDBSnsDetail &data)
{
    return NFSnsPart::LoadFromDB(data);
}

int NFSnsRelationPart::SaveDB(proto_ff::RoleDBSnsDetail &dbData)
{
    return NFSnsPart::SaveDB(dbData);
}

int NFSnsRelationPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_CENTER_RELATION_DATA_REQ);
    return 0;
}

int NFSnsRelationPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_CENTER_RELATION_DATA_REQ:
        {
            OnRelationInfoReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFSnsRelationPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFSnsPart::OnHandleServerMessage(msgId, packet);
}

int NFSnsRelationPart::OnRelationInfoReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CWRelationDataReq relationInfoReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, relationInfoReq);
    
    proto_ff::WCRelationDataRsp relationInfoRsp;
    relationInfoRsp.set_groupindex(relationInfoReq.groupindex());
    SendMsgToClient(proto_ff::CENTER_TO_CLIENT_RELATION_DATA_RSP, relationInfoRsp);
    return 0;
}
