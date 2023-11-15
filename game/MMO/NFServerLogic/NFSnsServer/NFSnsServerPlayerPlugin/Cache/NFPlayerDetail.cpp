// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#include "NFPlayerDetail.h"

#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>

#include "Part/NFSnsPart.h"
#include "NFCacheMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "Trans/NFSnsTransSaveDetailDB.h"
#include "NFComm/NFCore/NFRandom.hpp"

NFPlayerDetail::NFPlayerDetail()
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

NFPlayerDetail::~NFPlayerDetail()
{
}

int NFPlayerDetail::CreateInit()
{
    m_cid = 0;
    m_uid = 0;
    m_zid = 0;
    m_pPart.resize(SNS_PART_MAX);
    m_lastSavingDBTime = 0;
    m_saveDBTimer = INVALID_ID;
    m_proxyId = 0;
    m_gameId = 0;
    m_logicId = 0;
    m_isOnline = false;
    return 0;
}

int NFPlayerDetail::ResumeInit()
{
    return 0;
}

uint64_t NFPlayerDetail::GetCid() const
{
    return m_cid;
}

void NFPlayerDetail::SetCid(uint64_t cid)
{
    m_cid = cid;
}

uint32_t NFPlayerDetail::GetUid() const
{
    return m_uid;
}

void NFPlayerDetail::SetUid(uint32_t uid)
{
    m_uid = uid;
}

uint32_t NFPlayerDetail::GetZid() const
{
    return m_zid;
}

void NFPlayerDetail::SetZid(uint32_t zid)
{
    m_zid = zid;
}

bool NFPlayerDetail::CanDelete()
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

bool NFPlayerDetail::IsInited() const
{
    return m_isInited;
}

void NFPlayerDetail::SetIsInited(bool isInited)
{
    m_isInited = isInited;
}

int NFPlayerDetail::Init(const proto_ff::RoleDBSnsDetail& data)
{
    m_isInited = true;
    m_cid = data.cid();

    ResetCurSeq();
    m_isInited = true;

    LoadFromDB(data);
    InitConfig(data);

    std::vector<NFSnsPart *> vec;
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        m_pPart[i] = CreatePart(i, data);
        if (nullptr == m_pPart[i])
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Create Part Failed, roleId:{} part:{}", m_cid, i);
            for (int i = 0; i < (int)vec.size(); i++)
            {
                FindModule<NFISharedMemModule>()->DestroyObj(vec[i]);
            }
            return proto_ff::RET_FAIL;
        }
        vec.push_back(m_pPart[i].GetPoint());
    }

    /**
     * @brief
     */
    uint32_t startMS = NFRandInt(1000, LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000);
    m_saveDBTimer = SetTimer(LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000, 0, 0, 0, 0, startMS);

    return 0;
}

int NFPlayerDetail::UnInit()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            RecylePart(m_pPart[i]);
        }
    }

    return 0;
}

NFSnsPart* NFPlayerDetail::CreatePart(uint32_t partType)
{
    NFSnsPart* pPart = dynamic_cast<NFSnsPart *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_SNS_PART_ID + partType));
    if (pPart)
    {
        pPart->SetPartType(partType);
    }
    return pPart;
}

NFSnsPart* NFPlayerDetail::CreatePart(uint32_t partType, const proto_ff::RoleDBSnsDetail& data)
{
    NFSnsPart* pPart = CreatePart(partType);
    if (pPart)
    {
        int iRet = pPart->Init(this, partType, data);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}::Init Failed", pPart->GetClassName());
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
            return NULL;
        }
    }
    return pPart;
}

int NFPlayerDetail::RecylePart(NFSnsPart* pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

int NFPlayerDetail::OnTimer(int timeId, int callcount)
{
    if (timeId == m_saveDBTimer)
    {
        SaveToDB();
    }
    return 0;
}

NFSnsPart* NFPlayerDetail::GetPart(uint32_t partType)
{
    if (partType > PART_NONE && partType < (uint32_t)m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }

    return NULL;
}

NFPlayerSimple* NFPlayerDetail::GetRoleSimple() const
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(m_cid);
}

int NFPlayerDetail::OnLogin()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin();
        }
    }
    return 0;
}

int NFPlayerDetail::OnLogout()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogout();
        }
    }
    return 0;
}

int NFPlayerDetail::OnDisconnect()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnDisconnect();
        }
    }
    return 0;
}

int NFPlayerDetail::OnReconnect()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnReconnect();
        }
    }
    return 0;
}

int NFPlayerDetail::LoadFromDB(const proto_ff::RoleDBSnsDetail& data)
{
    CHECK_EXPR(m_cid == data.cid(), -1, "data cid is not right, db cid:{} my cid:{}", data.cid(), m_cid);
    m_uid = data.uid();
    m_zid = data.zid();
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->LoadFromDB(data);
        }
    }
    return 0;
}

int NFPlayerDetail::SaveDB(proto_ff::RoleDBSnsDetail& data)
{
    data.set_cid(GetCid());
    data.set_uid(GetUid());
    data.set_zid(GetZid());
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->SaveDB(data);
        }
    }
    return 0;
}

int NFPlayerDetail::InitConfig(const proto_ff::RoleDBSnsDetail& data)
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->InitConfig(data);
        }
    }
    return 0;
}

int NFPlayerDetail::Update()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->Update();
        }
    }
    return 0;
}

bool NFPlayerDetail::IsNeedSave()
{
    if (IsUrgentNeedSave())
    {
        return true;
    }

    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i] && m_pPart[i]->IsUrgentNeedSave())
        {
            return true;
        }
    }

    return false;
}

int NFPlayerDetail::SaveToDB(bool bForce)
{
    if (IsNeedSave())
    {
        if (bForce || NFTime::Now().UnixSec() - m_lastSavingDBTime >= LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME)
        {
            SendTransToDB();
        }
    }
    return 0;
}

int NFPlayerDetail::SendTransToDB()
{
    NFSnsTransSaveDetailDB* pSave = (NFSnsTransSaveDetailDB *)FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_SAVE_PLAYER_DETAIL);
    CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveDB Failed! ");

    int iRet = pSave->SaveDB(this);
    if (iRet != 0)
    {
        pSave->SetFinished(iRet);
    }

    return iRet;
}

int NFPlayerDetail::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetAllSeq())
    {
        ClearAllSeq();
    }
    return 0;
}

uint32_t NFPlayerDetail::GetAllSeq()
{
    uint32_t seq = GetCurSeq();
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            seq += m_pPart[i]->GetCurSeq();
        }
    }
    return seq;
}

void NFPlayerDetail::ClearAllSeq()
{
    ClearUrgent();
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->ClearUrgent();
        }
    }
}

int NFPlayerDetail::DailyZeroUpdate()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->DailyZeroUpdate();
        }
    }
    return 0;
}

int NFPlayerDetail::WeekZeroUpdate()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->WeekZeroUpdate();
        }
    }
    return 0;
}

int NFPlayerDetail::MonthZeroUpdate()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->MonthZeroUpdate();
        }
    }
    return 0;
}

uint32_t NFPlayerDetail::GetProxyId() const
{
    return m_proxyId;
}

void NFPlayerDetail::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint32_t NFPlayerDetail::GetLogicId() const
{
    return m_logicId;
}

void NFPlayerDetail::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

uint32_t NFPlayerDetail::GetGameId() const
{
    return m_gameId;
}

void NFPlayerDetail::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

bool NFPlayerDetail::IsOnline() const
{
    return m_isOnline;
}

void NFPlayerDetail::SetIsOnline(bool isOnline)
{
    m_isOnline = isOnline;
}

int NFPlayerDetail::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_SNS_SERVER, m_proxyId, NF_MODULE_CLIENT, nMsgId, xData, GetUid(), 0);
    return 0;
}

int NFPlayerDetail::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, GetCid());
    return 0;
}

int NFPlayerDetail::SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_SNS_SERVER, m_logicId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerDetail::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, GetCid());
    return 0;
}

int NFPlayerDetail::SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_SNS_SERVER, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int NFPlayerDetail::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, GetCid());
    return 0;
}

int NFPlayerDetail::SendTransToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    FindModule<NFIServerMessageModule>()->SendTransToGameServer(NF_ST_SNS_SERVER, m_gameId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}
