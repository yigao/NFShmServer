// -------------------------------------------------------------------------
//    @FileName         :    NFRoleSimple.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleSimple
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFCore/NFTime.h"
#include "DBProxy2_s.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFPlayerSimple : public NFShmObjTemplate<NFPlayerSimple, EOT_SNS_ROLE_SIMPLE_ID, NFShmObj>
{
public:
    NFPlayerSimple();

    virtual ~NFPlayerSimple();

    int CreateInit();

    int ResumeInit();

public:
    //must be virtual
    virtual int OnTimer(int timeId, int callcount);

public:
    uint64_t GetCid() const;

    void SetCid(uint64_t cid);

    uint64_t Cid() const;

    uint64_t GetUid() const;

    uint32_t GetZid() const;

    std::string GetName() const;
public:
    const proto_ff_s::RoleDBSnsSimple_s& GetBaseData() const;

    void SetBaseData(const proto_ff_s::RoleDBSnsSimple_s& baseData);

    void ReadFromPB(const proto_ff::RoleDBSnsSimple& dbData);

    bool IsInited() const;

    void SetIsInited(bool isInited);

public:
    /**
     * @brief
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(const proto_ff::RoleDBSnsSimple& dbData);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();

public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBSnsSimple& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBSnsSimple& data);

public:
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

public:
    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; }

public:
    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

    bool IsOnline() const;

    void SetIsOnline(bool isOnline);

public:
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message& xData);

    int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToWorldServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToGameServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

public:
    bool CanDelete();
private:
    /**
     * @brief
     */
    bool m_isInited;

public:
    proto_ff_s::RoleDBSnsSimple_s m_data;
private:
    /**
    * @brief
    */
    uint32_t m_proxyId;

    /**
     * @brief
     */
    uint32_t m_logicId;

    /**
     * @brief
     */
    uint32_t m_gameId;

    /**
     * @brief
     */
    bool m_isOnline;
};
