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
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "Trans/NFTransSaveDB.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFLogicCommon/NFCharactorDefine.h"

class NFPart;
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
    virtual int Init(const proto_ff::RoleDBData& data);

    virtual int UnInit();

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData& data);

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData &data);

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData& data);

    /**
     * @brief
     * @return
     */
    virtual int Update();

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout();

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect();

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect();

    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate();

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate();

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate();

public:
    proto_ff::enPlayerStatus GetStatus() const { return m_iStatus; }
    void SetStatus(proto_ff::enPlayerStatus status) { m_iStatus = status; }
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
    void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    uint64_t GetPlayerId() const { return m_playerId; }
    void SetPlayerId(uint64_t playerId) { m_playerId = playerId; }
    uint32_t GetProxyId() const { return m_proxyId; }
    void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
    uint32_t GetGameBusId() const;
    void SetGameBusId(uint32_t gameBusId);
    uint64_t GetLastLogoutTime() const { return m_lastLogoutTime; }
    void SetLastLogtouTime(uint64_t logoutTime) { m_lastLogoutTime = logoutTime; }
public:
    /**
     * @brief
     * @return
     */
    bool IsInGaming() { return GetGameBusId() > 0; }
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
    bool IsNeedSave();

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

    /**
     * @brief
     * @return
     */
    uint32_t GetAllSeq();

    /**
     * @brief
     */
    void ClearAllSeq();
public:
    /**
     * @brief
     * @param nMsgId
     * @param errCode
     * @return
     */
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);

    /**
     * @brief 在协程里获取远程服务器的rpc服务, 这个程序必须在协程里调用，需要先创建协程
     * @return 如果你在player或part的函数里，请优先调用这个函数，而不是调用FindModule<NFIMessageModule>()->GetRpcService系统函数， 因为玩家的生命周期是不确定的
     */
    template<size_t msgId, typename RequestType, typename ResponeType>
    int GetRpcService(NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType &request, ResponeType &respone)
    {
        FindModule<NFICoroutineModule>()->AddUserCo(m_playerId);
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<msgId>(NF_ST_LOGIC_SERVER, dstServerType, dstBusId, request, respone, m_playerId);
        FindModule<NFICoroutineModule>()->DelUserCo(m_playerId);
        return iRet;
    }
public:
    template<typename PART>
    PART *GetPart(uint32_t partType)
    {
        return dynamic_cast<PART *>(GetPart(partType));
    }

    template<typename PART>
    const PART* GetPart(uint32_t partType) const
    {
        return dynamic_cast<const PART *>(GetPart(partType));
    }

    NFPart *GetPart(uint32_t partType);
    const NFPart *GetPart(uint32_t partType) const;

    /**
     * @brief 创建Part
     * @param partType
     * @param dbData
     * @return
     */
    NFPart *CreatePart(uint32_t partType, const ::proto_ff::RoleDBData &dbData);

    /**
     * @brief 静态函数 创建Part
     * @param partType
     * @return
     */
    static NFPart* CreatePart(NFIPluginManager* pObjPluginManager, uint32_t partType);

    /**
     * @brief 释放Part
     * @param pPart
     * @return
     */
    int RecylePart(NFPart *pPart);
private:
    NFShmVector<NFShmPtr<NFPart>, PART_MAX> m_pPart;
private:
    uint64_t m_playerId;
    uint32_t m_proxyId;
    proto_ff::enPlayerStatus m_iStatus;
    uint64_t m_createTime;
    uint64_t m_lastDiconnectTime;
private:
    uint64_t m_lastLoginTime;
    uint64_t m_lastLogoutTime;
private:
    int m_iTransNum;
    uint64_t m_lastSavingDBTime;
private:
    int m_saveDBTimer;
DECLARE_IDCREATE(NFPlayer)
};
