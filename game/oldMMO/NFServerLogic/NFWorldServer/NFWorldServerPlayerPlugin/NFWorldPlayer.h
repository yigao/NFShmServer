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

class NFWorldPlayer : public NFShmObj
{
public:
    NFWorldPlayer(NFIPluginManager *pPluginManager);

    virtual ~NFWorldPlayer();

    int CreateInit();

    int ResumeInit();

    void Tick();

    virtual void OnTimer(int timeId, int callcount);

public:


public:
    /**
     * @brief
     * @return
     */
    uint64_t GetPlayerId() const;

    /**
     * @brief
     * @param playerId
     */
    void SetPlayerId(uint64_t playerId);

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
    WorldPlayerState GetStatus() const;

    /**
     * @brief
     * @param status
     */
    void SetStatus(WorldPlayerState status);

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
    bool IsNotifyCloseProxy() const;

    /**
     * @brief
     * @param isNotifyCloseProxy
     */
    void SetIsNotifyCloseProxy(bool isNotifyCloseProxy);

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
    uint64_t GetPlayCid() const;

    /**
     * @brief
     * @param playCid
     */
    void SetPlayCid(uint64_t playCid);

    /**
     * @brief
     * @return
     */
    uint64_t GetStatusTimeStamp() const;

    /**
     * @brief
     * @param statusTimeStamp
     */
    void SetStatusTimeStamp(uint64_t statusTimeStamp);

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
    uint32_t GetBornZid() const;

    /**
     * @brief
     * @param bornZid
     */
    void SetBornZid(uint32_t bornZid);

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
private:
    /**
     * @brief
     */
    uint64_t m_playerId;

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
    WorldPlayerState m_status;

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
    bool m_isNotifyCloseProxy;

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
    uint64_t m_playCid;

    /**
     * @brief
     */
    uint64_t m_statusTimeStamp;

    /**
     * @brief
     */
    uint32_t m_channelId;

    /**
     * @brief
     */
    uint32_t m_bornZid;

    /**
     * @brief
     */
    bool m_isWhite;


DECLARE_IDCREATE(NFWorldPlayer)
};
