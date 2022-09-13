// -------------------------------------------------------------------------
//    @FileName         :    NFGameSession.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameSession.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFServer/NFCommHead/NFIGamePlayer.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFCore/NFTime.h"

class NFGameSession: public NFShmObj
{
public:
    NFGameSession();

    virtual ~NFGameSession();

    int CreateInit();
    int ResumeInit();
public:
    //用户 ID
    virtual uint64_t GetPlayerId() const { return m_playerId; };
    //Game ID
    virtual uint32_t GetGameId() const { return m_gameId; };
    //Room ID
    virtual uint32_t GetRoomId() const { return m_roomId; }
    //桌子号码
    virtual int32_t GetDeskId() const { return m_deskId; }

	virtual int32_t GetChairId() const { return m_chairId; }

    //proxy ID
    virtual uint32_t GetProxyId() const { return m_proxyId; }

    virtual uint32_t GetLogicId() const { return m_logicId; }

    virtual bool IsOnline() const { return m_online; }

	//用户 ID
	virtual void SetPlayerId(uint64_t playerId) { m_playerId = playerId; };
	//Game ID
	virtual void SetGameId(uint32_t gameId) { m_gameId = gameId; };
	//Room ID
	virtual void SetRoomId(uint32_t roomId) { m_roomId = roomId; }
	//桌子号码
	virtual void SetDeskId(int32_t deskId) { m_deskId = deskId; }

	virtual void SetChairId(int32_t chairId) { m_chairId = chairId; }

	//proxy ID
	virtual void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
	virtual void SetLogicId(uint32_t logicId) { m_logicId = logicId; }

	virtual bool IsOnline() { return m_online; }

	virtual void SetOnline(bool online) { m_online = online; }

	virtual void SetClearFlag(bool flag) { m_clearFlag = flag; }
	virtual bool GetClearFlag() const { return m_clearFlag;  }

	virtual uint32_t GetOfflineTime() const { return m_offlineTime; }
	virtual void SetOfflineTime(uint32_t nowTime) { m_offlineTime = nowTime; }

	virtual uint32_t GetLastMsgTime() const { return m_lastMsgTime; }
	virtual void SetLastMsgTime(uint32_t nowTime) { m_lastMsgTime = nowTime; }

	virtual bool IsInGame() const { return m_gameId > 0 && m_roomId > 0 && m_deskId >= 0 && m_chairId >= 0;  }

    virtual bool IsIdle() const { return m_gameId <= 0 && m_roomId <= 0 && m_deskId < 0 && m_chairId < 0 && NFTime::Now().UnixSec() - m_reservedTime > 15;  }

	virtual void ClearGameData();

	int SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode);
	int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);
	int SendMsgToClient(uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData);
	int SendMsgToWorld(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0);
	int SendMsgToLogic(uint32_t nMsgId, const google::protobuf::Message &xData);
	int SendMsgToSns(uint32_t nMsgId, const google::protobuf::Message &xData);
	int SendTransToWorld(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);
	int SendTransToLogic(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);
	int SendTransToSns(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);
public:
    uint64_t m_playerId;
    uint32_t m_proxyId;
    uint32_t m_logicId;
    uint32_t m_gameId;
    uint32_t m_roomId;
    int32_t  m_deskId;
	int32_t  m_chairId;
	bool m_isRobot;
    bool m_online;
	uint32_t m_offlineTime;
	uint32_t m_lastMsgTime;
	bool m_clearFlag;
    uint64_t m_reservedTime;
    int32_t  m_reservedDeskId;
    int32_t  m_reservedChairId;
DECLARE_IDCREATE(NFGameSession)
};
