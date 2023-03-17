// -------------------------------------------------------------------------
//    @FileName         :    NFSnsPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsPart
//
// -------------------------------------------------------------------------

#include "NFSnsPart.h"
#include "Cache/NFRoleDetail.h"
#include "Cache/NFRoleSimple.h"
#include "Cache/NFCacheMgr.h"
#include "NFSnsPartModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSnsPart, EOT_SNS_PART_ID, NFShmObj)

NFSnsPart::NFSnsPart()
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

NFSnsPart::~NFSnsPart()
{
}

int NFSnsPart::CreateInit()
{
    m_roleId = 0;
    return 0;
}

int NFSnsPart::ResumeInit()
{
    return 0;
}

int NFSnsPart::InitBase(NFRoleDetail *pMaster, uint32_t partType)
{
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");
    m_roleId = pMaster->GetRoleId();
    m_partType = partType;
    return 0;
}

int NFSnsPart::Init(const proto_ff::RoleDBSnsDetail &data)
{
    return 0;
}

int NFSnsPart::UnInit()
{
    return 0;
}

uint32_t NFSnsPart::GetCurRoleDetailSeq() const
{
    return GetCurSeq();
}

int NFSnsPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "client part package not handle:{}", packet.ToString());
    return 0;
}

int NFSnsPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "server part package not handle:{}", packet.ToString());
    return 0;
}

int NFSnsPart::RegisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return pPluginManager->FindModule<NFSnsPartModule>()->RegisterClientPartMsg(nMsgID, partType);
}

int NFSnsPart::RegisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return pPluginManager->FindModule<NFSnsPartModule>()->RegisterServerPartMsg(nMsgID, partType);
}

int NFSnsPart::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    auto *pMaster = GetRoleSimple();
    CHECK_NULL(pMaster);

    return pMaster->SendMsgToClient(nMsgId, xData);
}

int NFSnsPart::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    auto *pMaster = GetRoleSimple();
    CHECK_NULL(pMaster);

    return pMaster->SendMsgToGameServer(nMsgId, xData);
}

int NFSnsPart::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    auto *pMaster = GetRoleSimple();
    CHECK_NULL(pMaster);

    return pMaster->SendMsgToWorldServer(nMsgId, xData);
}

int NFSnsPart::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    auto *pMaster = GetRoleSimple();
    CHECK_NULL(pMaster);

    return pMaster->SendMsgToLogicServer(nMsgId, xData);
}

NFRoleDetail *NFSnsPart::GetRoleDetail() const
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetRoleDetail(m_roleId);
}

NFRoleSimple *NFSnsPart::GetRoleSimple() const
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetRoleSimple(m_roleId);
}


