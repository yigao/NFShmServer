// -------------------------------------------------------------------------
//    @FileName         :    NFRoleSimple.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleSimple
//
// -------------------------------------------------------------------------

#include "NFPlayerSimple.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayerSimple, EOT_SNS_ROLE_SIMPLE_ID, NFShmObj)

NFPlayerSimple::NFPlayerSimple() : NFShmObj()
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

NFPlayerSimple::~NFPlayerSimple()
{
}

int NFPlayerSimple::CreateInit()
{
    m_proxyId = 0;
    m_clientId = 0;
    m_gameId = 0;
    m_isOnline = false;
    m_isInited = false;
    return 0;
}

bool NFPlayerSimple::IsInited() const
{
    return m_isInited;
}

void NFPlayerSimple::SetIsInited(bool isInited)
{
    m_isInited = isInited;
}

int NFPlayerSimple::ResumeInit()
{
    return 0;
}

uint64_t NFPlayerSimple::GetPlayerId() const
{
    return m_simpleData.player_id;
}

uint32_t NFPlayerSimple::GetProxyId() const
{
    return m_proxyId;
}

void NFPlayerSimple::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint64_t NFPlayerSimple::GetClientId() const
{
    return m_clientId;
}

void NFPlayerSimple::SetClientId(uint64_t clientId)
{
    m_clientId = clientId;
}

uint32_t NFPlayerSimple::GetLogicId() const
{
    return m_logicId;
}

void NFPlayerSimple::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

uint32_t NFPlayerSimple::GetGameId() const
{
    return m_gameId;
}

void NFPlayerSimple::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

bool NFPlayerSimple::IsOnline() const
{
    return m_isOnline;
}

void NFPlayerSimple::SetIsOnline(bool isOnline)
{
    m_isOnline = isOnline;
}

const proto_ff_s::pbFishPlayerSimpleData_s &NFPlayerSimple::GetBaseData() const
{
    return m_simpleData;
}

void NFPlayerSimple::SetBaseData(const proto_ff_s::pbFishPlayerSimpleData_s &baseData)
{
    m_simpleData = baseData;
}

void NFPlayerSimple::ReadFromPB(const proto_ff::pbFishPlayerSimpleData& dbData)
{
    m_simpleData.read_from_pbmsg(dbData);
}

int NFPlayerSimple::OnLogin(bool isLoadDB)
{
    return 0;
}

int NFPlayerSimple::OnLogout()
{
    return 0;
}

int NFPlayerSimple::OnDisconnect(uint32_t reason)
{
    return 0;
}

int NFPlayerSimple::OnReconnect()
{
    return 0;
}

int NFPlayerSimple::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_SNS_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, m_simpleData.player_id, m_clientId);
    return 0;
}

int NFPlayerSimple::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData);
    return 0;
}

int NFPlayerSimple::SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerSimple::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData);
    return 0;
}

int NFPlayerSimple::SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerSimple::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData);
    return 0;
}

int NFPlayerSimple::SendTransToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

bool NFPlayerSimple::CanDelete()
{
    return true;
}

int NFPlayerSimple::Init(const proto_ff::pbFishPlayerSimpleData &dbData)
{
    m_isInited = true;
    m_simpleData.read_from_pbmsg(dbData);
    return 0;
}
