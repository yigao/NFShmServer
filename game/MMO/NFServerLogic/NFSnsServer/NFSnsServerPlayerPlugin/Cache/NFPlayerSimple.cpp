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
#include "NFLogicCommon/NFLogicCommon.h"
#include "Trans/NFSnsTransSaveDetailDB.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFCacheMgr.h"

NFPlayerSimple::NFPlayerSimple()
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
    m_isInited = false;
    m_proxyId = 0;
    m_gameId = 0;
    m_logicId = 0;
    m_isOnline = false;
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

int NFPlayerSimple::OnTimer(int timeId, int callcount)
{
    return 0;
}

uint64_t NFPlayerSimple::GetCid() const
{
    return m_data.cid;
}

void NFPlayerSimple::SetCid(uint64_t cid)
{
    m_data.cid = cid;
}

uint64_t NFPlayerSimple::Cid() const
{
    return GetCid();
}

uint64_t NFPlayerSimple::GetUid() const
{
    return m_data.uid;
}

uint32_t NFPlayerSimple::GetZid() const
{
    return m_data.zid;
}

std::string NFPlayerSimple::GetName() const
{
    return m_data.base.name.data();
}

const proto_ff_s::RoleDBSnsSimple_s& NFPlayerSimple::GetBaseData() const
{
    return m_data;
}

void NFPlayerSimple::SetBaseData(const proto_ff_s::RoleDBSnsSimple_s& baseData)
{
    m_data = baseData;
}

void NFPlayerSimple::ReadFromPB(const proto_ff::RoleDBSnsSimple& dbData)
{
    m_data.read_from_pbmsg(dbData);
}

int NFPlayerSimple::OnLogin()
{
    return 0;
}

int NFPlayerSimple::OnLogout()
{
    return 0;
}

int NFPlayerSimple::OnDisconnect()
{
    return 0;
}

int NFPlayerSimple::OnReconnect()
{
    return 0;
}

bool NFPlayerSimple::CanDelete()
{
    if (m_isOnline)
    {
        return false;
    }

    if (FindModule<NFICoroutineModule>()->IsExistUserCo(GetCid()))
    {
        return false;
    }
    return true;
}

int NFPlayerSimple::Init(const proto_ff::RoleDBSnsSimple& dbData)
{
    m_isInited = true;
    LoadFromDB(dbData);
    InitConfig(dbData);

    return 0;
}

int NFPlayerSimple::UnInit()
{
    return 0;
}

int NFPlayerSimple::LoadFromDB(const proto_ff::RoleDBSnsSimple& dbData)
{
    m_data.read_from_pbmsg(dbData);
    return 0;
}

int NFPlayerSimple::InitConfig(const proto_ff::RoleDBSnsSimple& dbData)
{
    m_data.read_from_pbmsg(dbData);
    return 0;
}

uint32_t NFPlayerSimple::GetProxyId() const
{
    return m_proxyId;
}

void NFPlayerSimple::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
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

int NFPlayerSimple::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_SNS_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, GetUid(), 0);
    return 0;
}

int NFPlayerSimple::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, Cid());
    return 0;
}

int NFPlayerSimple::SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerSimple::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, Cid());
    return 0;
}

int NFPlayerSimple::SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerSimple::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, Cid());
    return 0;
}

int NFPlayerSimple::SendTransToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}
