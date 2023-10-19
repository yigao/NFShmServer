// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.cpp
//
// -------------------------------------------------------------------------

#include "NFPlayer.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFPlayerMgr.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "Part/NFPart.h"
#include "AllProtocol.h"
#include "Jetton/NFJettonPart.h"
#include "Room/NFRoomPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayer, EOT_LOGIC_PLAYER_ID, NFShmObj)

NFPlayer::NFPlayer()
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

NFPlayer::~NFPlayer()
{

}

int NFPlayer::CreateInit()
{
    m_playerId = 0;
    m_proxyId = 0;
    m_iStatus = proto_ff::PLAYER_STATUS_NONE;
    m_lastDiconnectTime = 0;
    m_createTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;
    m_lastSavingDBTime = 0;
    m_iTransNum = 0;
    m_saveDBTimer = INVALID_ID;
    m_lastLoginTime = 0;
    m_faceId = 0;
    m_regDate = 0;
    m_gender = 0;
    m_age = 0;
    m_phonenum = 0;
    m_pPart.resize(PART_MAX);
    return 0;
}

int NFPlayer::ResumeInit()
{
    return 0;
}

int NFPlayer::OnTimer(int timeId, int callcount)
{
    if (timeId == m_saveDBTimer)
    {
        SaveToDB();
    }
    return 0;
}

void NFPlayer::Tick()
{
    switch (m_iStatus)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t) NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            if (m_iTransNum > 0 || FindModule<NFICoroutineModule>()->IsExistUserCo(m_playerId))
            {
                if ((uint64_t) NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            if (IsInGaming())
            {
                if ((uint64_t) NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            SetStatus(proto_ff::PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_DEAD", GetPlayerId());
        }
            break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
            Update();
        }
            break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t) NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            if (m_iTransNum > 0 || FindModule<NFICoroutineModule>()->IsExistUserCo(m_playerId))
            {
                if ((uint64_t) NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            if (IsInGaming())
            {
                if ((uint64_t) NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            MarkDirty();
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (FindModule<NFICoroutineModule>()->IsExistUserCo(m_playerId))
            {
                break;
            }

            if (!IsUrgentNeedSave())
            {
                if (m_iTransNum <= 0)
                {
                    OnLogout();
                }
            }
            else if (!IsInSaving())
            {
                if ((m_lastSavingDBTime + LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME < (uint64_t) NFTime::Now().UnixSec() &&
                    m_lastSavingDBTime + 86400 > (uint64_t) NFTime::Now().UnixSec()) || m_pObjPluginManager->IsServerStopping())
                {
                    SendTransToDB(TRANS_SAVEROLEDETAIL_LOGOUT);
                }
            }
            break;
        }
    }
}

int NFPlayer::Init(const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer)
{
    SetStatus(proto_ff::PLAYER_STATUS_NONE);
    if (bCreatePlayer)
    {
        InitConfig(dbData);
    }
    else
    {
        LoadFromDB(dbData);
    }

    std::vector<NFPart *> vec;
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        m_pPart[i] = CreatePart(i, dbData, bCreatePlayer);
        if (nullptr == m_pPart[i])
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Player Init, Create Part Failed, playerId:{} part:{}", m_playerId, i);
            for (int i = 0; i < (int) vec.size(); i++)
            {
                FindModule<NFISharedMemModule>()->DestroyObj(vec[i]);
            }
            return -1;
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

int NFPlayer::UnInit()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            RecylePart(m_pPart[i]);
        }
    }

    return 0;
}

int NFPlayer::LoadFromDB(const proto_ff::tbFishPlayerData &data)
{
    m_regDate = data.regdate();
    m_ipAddr = data.ip();
    m_faceId = data.faceid();
    m_gender = data.gender();
    m_age = data.age();
    m_phonenum = data.phonenum();
    return 0;
}

int NFPlayer::InitConfig(const proto_ff::tbFishPlayerData &data)
{
    LoadFromDB(data);
    return 0;
}

int NFPlayer::OnLogin(const proto_ff::Proto_WorldToLogicLoginReq& data, proto_ff::Proto_UserDetailCommonData& detailData, bool isCreatePlayer)
{
    detailData.set_nick_name(m_nickName.data());
    detailData.set_gender(m_gender);
    detailData.set_face_id(m_faceId);
    detailData.set_phonenum(0);
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin(data, detailData, isCreatePlayer);
        }
    }
    return 0;
}

int NFPlayer::OnLogin()
{
    SetStatus(proto_ff::PLAYER_STATUS_ONLINE);
    m_lastLoginTime = NFTime::Now().UnixSec();
    MarkDirty();

    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin();
        }
    }
    return 0;
}

int NFPlayer::OnLogout()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogout();
        }
    }

    proto_ff::Proto_LTWLogoutNotify notify;
    notify.set_player_id(m_playerId);
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_LTW_PLAYER_LOGOUT_NOTIFY, notify);

    SetStatus(proto_ff::PLAYER_STATUS_DEAD);
    return 0;
}

int NFPlayer::OnDisconnect()
{
    m_lastDiconnectTime = NFTime::Now().UnixSec();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnDisconnect();
        }
    }
    return 0;
}

int NFPlayer::OnReconnect()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnReconnect();
        }
    }
    return 0;
}

int NFPlayer::Update()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->Update();
        }
    }
    return 0;
}

int NFPlayer::SaveDB(proto_ff::tbFishPlayerData &data)
{
    data.set_regdate(m_regDate);
    data.set_ip(m_ipAddr.ToString());
    data.set_faceid(m_faceId);
    data.set_gender(m_gender);
    data.set_age(m_age);
    data.set_phonenum(m_phonenum);
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->SaveDB(data);
        }
    }
    return 0;
}

int NFPlayer::DailyZeroUpdate()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->DailyZeroUpdate();
        }
    }
    return 0;
}

int NFPlayer::WeekZeroUpdate()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->WeekZeroUpdate();
        }
    }
    return 0;
}

int NFPlayer::MonthZeroUpdate()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->MonthZeroUpdate();
        }
    }
    return 0;
}

void NFPlayer::IncreaseTransNum()
{
    ++m_iTransNum;
}


void NFPlayer::DecreaseTransNum()
{
    --m_iTransNum;
    if (m_iTransNum < 0)
    {
        m_iTransNum = 0;
    }
}

int NFPlayer::SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::Proto_CSErrorRsp rspMsg;
    rspMsg.set_req_msg_id(nMsgId);
    rspMsg.set_error(errCode);

    SendMsgToClient(proto_ff::E_CS_ERROR, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFPlayer::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    CHECK_EXPR(m_proxyId > 0, -1, "player disconnect, SendMsgToClient msgId:{} msgData:{}", nMsgId, xData.DebugString());
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_LOGIC_SERVER, m_proxyId, nMsgId, xData, m_playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToClient msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, nMsgId, xData, m_playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToSnsServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, nMsgId, xData, m_playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToWorldServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_LOGIC_SERVER, GetGameBusId(), nMsgId, xData, m_playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToGameServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

bool NFPlayer::IsNeedSave()
{
    if (IsUrgentNeedSave())
    {
        return true;
    }

    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i] && m_pPart[i]->IsUrgentNeedSave())
        {
            return true;
        }
    }

    return false;
}

int NFPlayer::SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason, bool bForce)
{
    if (IsNeedSave())
    {
        if (bForce || NFTime::Now().UnixSec() - m_lastSavingDBTime >= LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME)
        {
            SendTransToDB(iReason);
        }
    }
    return 0;
}

int NFPlayer::SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason)
{
    NFTransSaveDB *pSave = (NFTransSaveDB *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_SAVE_PLAYER);
    CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveDB Failed! ");

    pSave->Init(this, 0);
    int iRet = pSave->SaveDB(iReason);
    if (iRet != 0)
    {
        pSave->SetFinished(iRet);
    }

    return iRet;
}

int NFPlayer::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetAllSeq())
    {
        ClearAllSeq();
    }
    return 0;
}

uint32_t NFPlayer::GetAllSeq()
{
    uint32_t seq = GetCurSeq();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            seq += m_pPart[i]->GetCurSeq();
        }
    }
    return seq;
}

void NFPlayer::ClearAllSeq()
{
    ClearUrgent();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->ClearUrgent();
        }
    }
}

NFPart *NFPlayer::GetPart(uint32_t partType)
{
    if (partType > PART_NONE && partType < (uint32_t) m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }

    return NULL;
}

const NFPart *NFPlayer::GetPart(uint32_t partType) const
{
    if (partType > PART_NONE && partType < (uint32_t) m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }

    return NULL;
}

NFPart* NFPlayer::CreatePart(NFIPluginManager* pObjPluginManager, uint32_t partType)
{
    NFPart *pPart = NULL;
    switch (partType)
    {
        case PART_JETTON:
        {
            pPart = NFJettonPart::CreateObj(pObjPluginManager);
            break;
        }
        case PART_ROOM:
        {
            pPart = NFRoomPart::CreateObj(pObjPluginManager);
            break;
        }
        default:
        {
            break;
        }
    }

    if (pPart)
    {
        pPart->SetPartType(partType);
    }
    return pPart;
}

NFPart *NFPlayer::CreatePart(uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer)
{
    NFPart *pPart = CreatePart(m_pObjPluginManager, partType);
    if (pPart)
    {
        int iRet = pPart->Init(this, partType, dbData, bCreatePlayer);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}::Init Failed", pPart->GetClassName());
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
            return NULL;
        }
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Create Part Failed, partType Not Handle:{}", partType);
    }
    return pPart;
}

int NFPlayer::RecylePart(NFPart *pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

uint32_t NFPlayer::GetGameId() const
{
    auto pPart = GetPart<NFRoomPart>(PART_ROOM);
    if (pPart)
    {
        return pPart->GetGameId();
    }

    return 0;
}
uint32_t NFPlayer::GetRoomId() const
{
    auto pPart = GetPart<NFRoomPart>(PART_ROOM);
    if (pPart)
    {
        return pPart->GetRoomId();
    }

    return 0;
}

uint32_t NFPlayer::GetGameBusId() const
{
    auto pPart = GetPart<NFRoomPart>(PART_ROOM);
    if (pPart)
    {
        return pPart->GetGameBusId();
    }

    return 0;
}

void NFPlayer::SetGameId(uint32_t gameId)
{
    auto pPart = GetPart<NFRoomPart>(PART_ROOM);
    if (pPart)
    {
        return pPart->SetGameId(gameId);
    }
}

void NFPlayer::SetGameBusId(uint32_t gameBusId)
{
    auto pPart = GetPart<NFRoomPart>(PART_ROOM);
    if (pPart)
    {
        pPart->SetGameBusId(gameBusId);
    }
}

void NFPlayer::SetRoomId(uint32_t roomId)
{
    auto pPart = GetPart<NFRoomPart>(PART_ROOM);
    if (pPart)
    {
        pPart->SetRoomId(roomId);
    }
}