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
#include "Trans/NFSnsTransSaveSimpleDB.h"
#include "Trans/NFSnsTransSaveDetailDB.h"

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
    m_playerId = 0;
    m_proxyId = 0;
    m_gameId = 0;
    m_isOnline = false;
    m_isInited = false;
    m_lastSavingDBTime = 0;
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
    return m_playerId;
}

void NFPlayerSimple::SetPlayerId(uint64_t playerId)
{
    m_playerId = playerId;
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

const proto_ff_s::tbFishSnsPlayerSimpleData_s &NFPlayerSimple::GetBaseData() const
{
    return m_simpleData;
}

void NFPlayerSimple::SetBaseData(const proto_ff_s::tbFishSnsPlayerSimpleData_s &baseData)
{
    m_simpleData = baseData;
}

void NFPlayerSimple::ReadFromPB(const proto_ff::tbFishSnsPlayerSimpleData& dbData)
{
    m_simpleData.read_from_pbmsg(dbData);
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

int NFPlayerSimple::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_SNS_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, m_simpleData.player_id, 0);
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

int NFPlayerSimple::Init(const proto_ff::tbFishSnsPlayerSimpleData &dbData)
{
    m_isInited = true;
    m_simpleData.read_from_pbmsg(dbData);
    return 0;
}

int NFPlayerSimple::SaveToDB(bool bForce)
{
    if (IsUrgentNeedSave())
    {
        if (bForce || NFTime::Now().UnixSec() - m_lastSavingDBTime >= LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME)
        {
            SendTransToDB();
        }
    }
    return 0;
}

int NFPlayerSimple::SendTransToDB()
{
    NFSnsTransSaveSimpleDB* pSave = (NFSnsTransSaveSimpleDB*) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_SAVE_PLAYER_SIMPLE);
    CHECK_EXPR(pSave, -1, "Create Trans:NFSnsTransSaveSimpleDB Failed! ");

    int iRet = pSave->SaveDB(this);
    if (iRet != 0)
    {
        pSave->SetFinished(iRet);
    }

    return iRet;
}

int NFPlayerSimple::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetCurSeq())
    {
        ClearUrgent();
    }
    return 0;
}

uint64_t NFPlayerSimple::GetClientId() const
{
    return 0;
}

void NFPlayerSimple::SetClientId(uint64_t clientId)
{

}

int NFPlayerSimple::LoadFromDB(const proto_ff::tbFishSnsPlayerSimpleData &data)
{
    return 0;
}

int NFPlayerSimple::SaveDB(proto_ff::tbFishSnsPlayerSimpleData &data)
{
    return 0;
}

int NFPlayerSimple::InitConfig(const proto_ff::tbFishSnsPlayerSimpleData &data)
{
    return 0;
}
