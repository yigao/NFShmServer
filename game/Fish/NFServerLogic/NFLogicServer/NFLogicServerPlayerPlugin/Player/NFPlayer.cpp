﻿// -------------------------------------------------------------------------
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
#include "ClientServerCmd.pb.h"
#include "ClientServer.pb.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "Part/NFPart.h"

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
    m_gameId = 0;
    m_roomId = 0;
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
    m_jetton = 0;
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

void  NFPlayer::Tick()
{
    switch (m_iStatus)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            if (m_iTransNum > 0)
            {
                if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            if (IsInGaming())
            {
                if ((uint64_t)NFTime::Now().UnixSec() - m_createTime <  LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
            Update();
        }
            break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            if (m_iTransNum > 0)
            {
                if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            if (IsInGaming())
            {
                if ((uint64_t)NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetPlayerId(), "player:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetPlayerId());
        }
            break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (!IsUrgentNeedSave())
            {
                if (m_iTransNum <= 0)
                {
                    OnLogout();
                }
            }
            else if (!IsInSaving())
            {
                if (m_lastSavingDBTime + LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME < (uint64_t)NFTime::Now().UnixSec() && m_lastSavingDBTime + 86400 > (uint64_t)NFTime::Now().UnixSec())
                {
                    SendTransToDB(TRANS_SAVEROLEDETAIL_LOGOUT);
                }
            }
            break;
        }
    }
}

int NFPlayer::Init(const proto_ff::tbFishPlayerData& dbData, bool bCreatePlayer)
{
    SetStatus(proto_ff::PLAYER_STATUS_NONE);
    if (bCreatePlayer)
    {
        InitConfig(dbData);
    }
    else {
        LoadFromDB(dbData);
    }

    std::vector<NFPart*> vec;
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        m_pPart[i] = CreatePart(i, dbData, bCreatePlayer);
        if (nullptr == m_pPart[i])
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Player Init, Create Part Failed, playerId:{} part:{}", m_playerId, i);
            for(int i = 0; i < (int)vec.size(); i++)
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
    uint32_t startMS = NFRandInt(1000, LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME*1000);
    m_saveDBTimer = SetTimer(LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000, 0, 0, 0, 0, startMS);

    return 0;
}

int NFPlayer::UnInit()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        RecylePart(m_pPart[i]);
    }

    return 0;
}

int NFPlayer::LoadFromDB(const proto_ff::tbFishPlayerData& data)
{
    m_regDate = data.regdate();
    m_ipAddr = data.ip();
    m_faceId = data.faceid();
    m_gender = data.gender();
    m_age = data.age();
    m_phonenum = data.phonenum();
    m_jetton = data.jetton();
    return 0;
}

int NFPlayer::InitConfig(const proto_ff::tbFishPlayerData& data)
{
    LoadFromDB(data);
    return 0;
}

int NFPlayer::OnLogin()
{
    SetStatus(proto_ff::PLAYER_STATUS_ONLINE);
    m_lastLoginTime = NFTime::Now().UnixSec();
    MarkDirty();
    return 0;
}

int NFPlayer::OnLogout()
{
    return 0;
}

int NFPlayer::OnDisconnect()
{
    m_lastDiconnectTime = NFTime::Now().UnixSec();
    return 0;
}

int NFPlayer::OnReconnect()
{
    return 0;
}

int NFPlayer::Update()
{
    return 0;
}

int NFPlayer::SaveDB(proto_ff::tbFishPlayerData& data)
{
    data.set_regdate(m_regDate);
    data.set_ip(m_ipAddr.ToString());
    data.set_faceid(m_faceId);
    data.set_gender(m_gender);
    data.set_age(m_age);
    data.set_phonenum(m_phonenum);
    data.set_jetton(m_jetton);
    return 0;
}

int NFPlayer::DailyZeroUpdate()
{
    return 0;
}

int NFPlayer::WeekZeroUpdate()
{
    return 0;
}

int NFPlayer::MonthZeroUpdate()
{
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::Proto_CSErrorRsp rspMsg;
    rspMsg.set_req_msg_id(nMsgId);
    rspMsg.set_error(errCode);

    SendMsgToClient(proto_ff::E_CS_ERROR, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFPlayer::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    CHECK_EXPR(m_proxyId > 0, -1, "player disconnect, SendMsgToClient msgId:{} msgData:{}", nMsgId, xData.DebugString());
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_LOGIC_SERVER, m_proxyId, nMsgId, xData, m_playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToClient msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData) {
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, nMsgId, xData);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToSnsServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData) {
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, nMsgId, xData);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToWorldServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData) {
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_LOGIC_SERVER, m_gameId, nMsgId, xData);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "SendMsgToGameServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason, bool bForce)
{
    if (IsUrgentNeedSave())
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
    NFTransSaveDB* pSave = (NFTransSaveDB*) FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_SAVE_PLAYER);
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
    if (success && seq == GetCurSeq())
    {
        ClearUrgent();
    }
    return 0;
}

NFPart *NFPlayer::GetPart(uint32_t partType)
{
    if (partType > PART_NONE && partType < (uint32_t) m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }

    return NULL;
}

NFPart *NFPlayer::CreatePart(uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer)
{
    NFPart *pPart = NULL;
    switch (partType)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_playerId, "Create Part Failed, partType Not Handle:{}", partType);
            break;
        }
    }

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
    return pPart;
}

int NFPlayer::RecylePart(NFPart *pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}