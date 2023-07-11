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

class NFPlayerSimple : public NFShmObj
{
public:
    NFPlayerSimple();

    virtual ~NFPlayerSimple();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetPlayerId() const;

    void SetPlayerId(uint64_t playerId);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

    uint64_t GetClientId() const;

    void SetClientId(uint64_t clientId);

    bool IsOnline() const;

    void SetIsOnline(bool isOnline);

    const proto_ff_s::pbFishPlayerSimpleData_s &GetBaseData() const;

    void SetBaseData(const proto_ff_s::pbFishPlayerSimpleData_s &baseData);

    void ReadFromPB(const proto_ff::pbFishPlayerSimpleData &dbData);

    bool IsInited() const;

    void SetIsInited(bool isInited);

    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

public:
    int Init(const proto_ff::pbFishPlayerSimpleData &dbData);

public:
    int OnLogin(bool isLoadDB);

    int OnLogout();

    int OnDisconnect(uint32_t reason);

    int OnReconnect();

public:
    bool CanDelete();

public:
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);

    int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToWorldServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendTransToGameServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

private:
    /**
     * @brief
     */
    bool m_isInited;
public:
    /**
     * @brief 线上系统，更在线有关
     */

    uint64_t m_playerId;

    /**
     * @brief
     */
    uint32_t m_proxyId;

    uint64_t m_clientId;

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
private:
    proto_ff_s::pbFishPlayerSimpleData_s m_simpleData;

DECLARE_IDCREATE(NFPlayerSimple)
};