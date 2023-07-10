// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "ComDefine.pb.h"
#include "DBProto.pb.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "Trans/NFTransSaveDB.h"

class NFPlayer : public NFShmObj, public NFSeqOP
{
public:
    NFPlayer();

    virtual ~NFPlayer();

    int CreateInit();
    int ResumeInit();

    void  Tick();
    virtual int OnTimer(int timeId, int callcount);

public:
    virtual int Init(const proto_ff::tbFishPlayerData& data, bool bCreatePlayer = false);

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishPlayerData& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::tbFishPlayerData& data);

    //登入
    virtual int OnLogin();
    //生物登出入口
    virtual int OnLogout();
    //断开连接
    virtual int OnDisconnect();
    //重新连接
    virtual int OnReconnect();
    //生物update
    virtual int Update();
    //存储DB
    virtual int SaveDB(proto_ff::tbFishPlayerData& data);

    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    virtual int DailyZeroUpdate();
    virtual int WeekZeroUpdate();
    virtual int MonthZeroUpdate();

public:
    proto_ff::PlayerStatus GetStatus() const { return m_iStatus; }
    void SetStatus(proto_ff::PlayerStatus status) { m_iStatus = status; }
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
    void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    uint64_t GetPlayerId() const { return m_playerId; }
    void SetPlayerId(uint64_t playerId) { m_playerId = playerId; }
    uint32_t GetProxyId() const { return m_proxyId; }
    void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
    uint32_t GetGameId() const { return m_gameId; }
    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    uint32_t GetRoomId() const { return m_roomId; }
    void SetRoomId(uint32_t roomId) { m_roomId = roomId; }
    uint64_t GetLastLogoutTime() const { return m_lastLogoutTime; }
    void SetLastLogtouTime(uint64_t logoutTime) { m_lastLogoutTime = logoutTime; }
public:
    /**
     * @brief
     * @return
     */
    bool IsInGaming() { return m_gameId > 0 && m_roomId > 0; }
public:
    /**
     * @brief trans num
     */
    void IncreaseTransNum();
    void DecreaseTransNum();
public:
    /**
     * @brief save db
     * @return
     */
    uint64_t GetLastSaveDBTime() const { return m_lastSavingDBTime; }
    void SetLastSaveDBTime(uint64_t saveTime) { m_lastSavingDBTime = saveTime; }
    bool IsInSaving() { return m_lastSavingDBTime > 0 && m_lastSavingDBTime + TRANS_ACTIVE_TIMEOUT + 5 >= (uint64_t)NFTime::Now().UnixSec(); }

    /**
     * @brief
     * @param iReason
     * @return
     */
    int SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);

    /**
     * @brief
     * @param iReason
     * @param bForce
     * @return
     */
    int SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL, bool bForce = false);

    /**
     * @brief
     * @param success
     * @param seq
     * @return
     */
    int OnSaveDB(bool success, uint32_t seq);
public:
    /**
     * @brief
     * @param nMsgId
     * @param errCode
     * @return
     */
    int SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode);
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);
private:
    uint64_t m_playerId;
    uint32_t m_proxyId;
    proto_ff::PlayerStatus m_iStatus;
    uint64_t m_createTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;
    uint32_t m_gameId;
    uint32_t m_roomId;
private:
    int m_iTransNum;
    uint64_t m_lastSavingDBTime;
private:
    int m_saveDBTimer;
DECLARE_IDCREATE(NFPlayer)
};
