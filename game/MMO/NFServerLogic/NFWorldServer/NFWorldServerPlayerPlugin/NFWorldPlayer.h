// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "NFWorldCommonDefine.h"
#include "NFWorldRoleInfo.h"
#include "NFLogicCommon/NFAccountDefine.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "DBProto.pb.h"

class NFWorldPlayer : public NFShmObj
{
public:
    NFWorldPlayer();

    virtual ~NFWorldPlayer();

    int CreateInit();

    int ResumeInit();

    void Tick();

    virtual int OnTimer(int timeId, int callcount);

public:
    /**
     * @brief 玩家发信息到网关
     * @param msgId
     * @param xData
     */
    void SendMsgToProxyServer(uint32_t msgId, const google::protobuf::Message &xData);

    /**
     * @brief 玩家发信息到网关
     * @param msgId
     * @param xData
     */
    void SendMsgToClient(uint32_t msgId, const google::protobuf::Message &xData);

    /**
     * @brief
     * @param moduleId
     * @param msgId
     * @param xData
     */
    void SendMsgToLogicServer(uint32_t msgId, const google::protobuf::Message &xData);
    void SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    /**
     * @brief
     * @param moduleId
     * @param msgId
     * @param xData
     */
    void SendMsgToSnsServer(uint32_t msgId, const google::protobuf::Message &xData);
    void SendTransToSnsServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    /**
     * @brief
     * @param msgId
     * @param xData
     */
    void SendMsgToGameServer(uint32_t msgId, const google::protobuf::Message &xData);
    void SendTransToGameServer(uint32_t msgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);
public:
    /**
     * @brief
     * @return
     */
    uint64_t GetUid() const;

    /**
     * @brief
     * @param uid
     */
    void SetUid(uint64_t uid);

    /**
     * @brief
     * @return
     */
    uint32_t GetProxyId() const;

    /**
     * @brief
     * @param proxyId
     */
    void SetProxyId(uint32_t proxyId);

    /**
     * @brief
     * @return
     */
    uint64_t GetClientId() const;

    /**
     * @brief
     * @param clientId
     */
    void SetClientId(uint64_t clientId);

    /**
     * @brief
     * @return
     */
    uint32_t GetLogicId() const;

    /**
     * @brief
     * @param logicId
     */
    void SetLogicId(uint32_t logicId);

    /**
     * @brief
     * @return
     */
    PLAYER_STATUS GetStatus() const;

    /**
     * @brief
     * @param status
     */
    void SetStatus(PLAYER_STATUS status);

    /**
     * @brief
     * @return
     */
    uint64_t GetCreateTime() const;

    /**
     * @brief
     * @param createTime
     */
    void SetCreateTime(uint64_t createTime);

    /**
     * @brief
     * @return
     */
    uint64_t GetLastDiconnectTime() const;

    /**
     * @brief
     * @param lastDiconnectTime
     */
    void SetLastDiconnectTime(uint64_t lastDiconnectTime);

    /**
     * @brief
     * @return
     */
    uint64_t GetLastLogoutTime() const;

    /**
     * @brief
     * @param lastLogoutTime
     */
    void SetLastLogoutTime(uint64_t lastLogoutTime);

public:
    /**
     * @brief
     * @return
     */
    bool IsDisconnect() const;

    /**
     * @brief
     * @param isDisConnect
     */
    void SetIsDisconnect(bool isDisConnect);

    /**
     * @brief
     * @return
     */
    const string &GetToken() const;

    /**
     * @brief
     * @param token
     */
    void SetToken(const string &token);

    /**
     * @brief
     * @return
     */
    uint64_t GetTokenTimeStamp() const;

    /**
     * @brief
     * @param tokenTimeStamp
     */
    void SetTokenTimeStamp(uint64_t tokenTimeStamp);

    /**
     * @brief
     * @return
     */
    uint64_t GetRoleId() const;

    /**
     * @brief
     * @param playCid
     */
    void SetRoleId(uint64_t playCid);

    /**
     * @brief
     * @return
     */
    uint32_t GetChannelId() const;

    /**
     * @brief
     * @param channelId
     */
    void SetChannelId(uint32_t channelId);

    /**
     * @brief
     * @return
     */
    uint32_t GetLoginZid() const;

    /**
     * @brief
     * @param zid
     */
    void SetLoginZid(uint32_t zid);

    /**
     * @brief
     * @return
     */
    bool IsWhite() const;

    /**
     * @brief
     * @param isWhite
     */
    void SetIsWhite(bool isWhite);

    uint32_t GetCharNum() const;

    void SetCharNum(uint32_t charNum);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

public:
    NFWorldRoleInfo *GetRoleInfo(uint64_t roleId);

    NFWorldRoleInfo *CreateRoleInfo(uint64_t roleId);

    int DeleteRoleInfo(uint64_t roleId);

    void ClearRoleInfo();

    NFShmHashMap<uint64_t, NFWorldRoleInfo, MAX_ROLE_NUM>& GetAllRoleInfo() { return m_roleInfo; }
private:
    /**
     * @brief
     */
    uint64_t m_uid;

    /**
     * @brief
     */
    uint32_t m_proxyId;

    /**
     * @brief
     */
    uint64_t m_clientId;

    /**
     * @brief
     */
    uint32_t m_logicId;

    /**
     * @brief
     */
    uint32_t m_gameId;


private:

    /**
     * @brief
     */
    PLAYER_STATUS m_status;

    /**
     * @brief
     */
    uint64_t m_createTime;

    /**
     * @brief
     */
    uint64_t m_lastDiconnectTime;

    /**
     * @brief
     */
    uint64_t m_lastLogoutTime;

    /**
     * @brief
     */
    bool m_isDisconnect;

    /**
     * @brief
     */
    std::string m_token;

    /**
     * @brief
     */
    uint64_t m_tokenTimeStamp;

    /**
     * @brief
     */
    uint64_t m_roleId;

    /**
     * @brief
     */
    uint32_t m_channelId;

    /**
     * @brief
     */
    uint32_t m_loginZid;

    /**
     * @brief
     */
    bool m_isWhite;

    /**
     * @brief
     */
    uint32_t m_charNum;
private:
    NFShmHashMap<uint64_t, NFWorldRoleInfo, MAX_ROLE_NUM> m_roleInfo;
private:
DECLARE_IDCREATE(NFWorldPlayer)
};
