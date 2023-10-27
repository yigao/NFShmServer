// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerOnline.h
//    @Author           :    gaoyi
//    @Date             :    23-7-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerOnline
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFPlayerOnline : public NFShmObjTemplate<NFPlayerOnline, EOT_PLAYER_ONLINE_ID, NFShmObj>
{
public:
    NFPlayerOnline();

    virtual ~NFPlayerOnline();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @return
     */
    virtual int Init();

    /**
     * @brief
     * @return
     */
    virtual int UnInit();
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
    virtual int WeekZeroUpdate() { return 0; };

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
public:
    uint64_t GetCid() const;

    void SetCid(uint64_t cid);

    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

    bool IsOnline() const;

    void SetIsOnline(bool isOnline);
public:
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);

    int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToWorldServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToGameServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);
public:
    /**
     * @brief 线上系统，更在线有关
     */

    uint64_t m_cid;

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