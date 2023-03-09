// -------------------------------------------------------------------------
//    @FileName         :    NFRoleSimple.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleSimple
//
// -------------------------------------------------------------------------

#include "NFRoleSimple.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRoleSimple, EOT_SNS_ROLE_SIMPLE_ID, NFShmObj)

NFRoleSimple::NFRoleSimple() : NFShmObj()
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

NFRoleSimple::~NFRoleSimple()
{
}

int NFRoleSimple::CreateInit()
{
    m_uid = 0;
    m_roleId = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_gameId = 0;
    m_isOnline = false;
    m_isInited = false;
    return 0;
}

bool NFRoleSimple::IsInited() const
{
    return m_isInited;
}

void NFRoleSimple::SetIsInited(bool isInited)
{
    m_isInited = isInited;
}

int NFRoleSimple::ResumeInit()
{
    return 0;
}

uint64_t NFRoleSimple::GetRoleId() const
{
    return m_roleId;
}

void NFRoleSimple::SetRoleId(uint64_t roleId)
{
    m_roleId = roleId;
}

uint64_t NFRoleSimple::GetUid() const
{
    return m_uid;
}

void NFRoleSimple::SetUid(uint64_t uid)
{
    m_uid = uid;
}

uint32_t NFRoleSimple::GetProxyId() const
{
    return m_proxyId;
}

void NFRoleSimple::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint32_t NFRoleSimple::GetClientId() const
{
    return m_clientId;
}

void NFRoleSimple::SetClientId(uint32_t clientId)
{
    m_clientId = clientId;
}

uint32_t NFRoleSimple::GetLogicId() const
{
    return m_logicId;
}

void NFRoleSimple::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

uint32_t NFRoleSimple::GetGameId() const
{
    return m_gameId;
}

void NFRoleSimple::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

bool NFRoleSimple::IsOnline() const
{
    return m_isOnline;
}

void NFRoleSimple::SetIsOnline(bool isOnline)
{
    m_isOnline = isOnline;
}

const proto_ff_s::RoleDBBaseData_s &NFRoleSimple::GetBaseData() const
{
    return m_baseData;
}

void NFRoleSimple::SetBaseData(const proto_ff_s::RoleDBBaseData_s &baseData)
{
    m_baseData = baseData;
}

void NFRoleSimple::ReadFromPB(const proto_ff::RoleDBBaseData& dbData)
{
    m_baseData.read_from_pbmsg(dbData);
}

int NFRoleSimple::OnLogin(bool isLoadDB)
{
    return 0;
}

int NFRoleSimple::OnLogout()
{
    return 0;
}

int NFRoleSimple::OnDisconnect(uint32_t reason)
{
    return 0;
}

int NFRoleSimple::OnReconnect()
{
    return 0;
}

int NFRoleSimple::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_SNS_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, m_uid, m_clientId);
    return 0;
}

int NFRoleSimple::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData);
    return 0;
}

int NFRoleSimple::SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFRoleSimple::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData);
    return 0;
}

int NFRoleSimple::SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFRoleSimple::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData);
    return 0;
}

int NFRoleSimple::SendTransToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

bool NFRoleSimple::CanDelete()
{
    return true;
}

int NFRoleSimple::Init(const proto_ff::RoleDBSimpleData &dbData)
{
    m_isInited = true;
    m_uid = dbData.uid();
    m_baseData.read_from_pbmsg(dbData.base());
    return 0;
}
