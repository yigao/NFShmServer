// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineRole.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFOnlineRole.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_error_code.pb.h"

class NFOnlineUser : public NFShmObj
{
public:
    NFOnlineUser();
    virtual ~NFOnlineUser();
    int CreateInit();
    int ResumeInit();

    virtual int GetHashKey( void *pvKey, int &iKeyLength );
    virtual int SetHashKey( const void *pvKey, int iKeyLength );

    int Init(uint64_t ulRoldID, uint32_t logicSvrId, uint64_t ulLastLoginTime, uint64_t ulLastLogoutTime);

    uint64_t GetUserID() const { return m_llUserID; }
    void SetUserID(uint64_t userId) { m_llUserID = userId; }
    uint32_t GetLogicId() const { return m_logicSvrId; }
    uint32_t GetGameId() const { return m_gameId; }
    uint32_t GetRoomId() const { return m_roomId; }
    uint32_t GetGameBusId() const { return m_gameBusId; }
    bool IsGaming() { return m_gameId > 0 && m_roomId > 0 && m_gameBusId > 0; }

    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    void SetRoomId(uint32_t roomId) { m_roomId = roomId; }
    void SetGameBusId(uint32_t busId) { m_gameBusId = busId; }

    uint64_t GetLastLoginTime() const { return m_ulLastLoginTime; }
    uint64_t GetLastLogoutTime() const { return m_ulLastLogoutTime; }

    int SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode);
    int SendMsgToLogicServer(uint32_t nMMsgId, const google::protobuf::Message &xData);

    //must be virtual
    virtual void OnTimer(int timeId, int callcount);
private:
    uint64_t m_llUserID;
	uint32_t m_logicSvrId;
    uint64_t 	m_ulLastLoginTime;
    uint64_t 	m_ulLastLogoutTime;
    uint32_t    m_gameId;
    uint32_t    m_roomId;
    uint32_t    m_gameBusId;
    int         m_validPlayerTimer;
DECLARE_IDCREATE(NFOnlineUser)
};
