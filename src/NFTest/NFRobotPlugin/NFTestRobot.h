#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_cs_login.pb.h"

enum NFTestRobotStatus
{
	NF_TEST_ROBOT_NONE_STATUS = 0,
	NF_TEST_ROBOT_START_CONNECT,
    NF_TEST_ROBOT_CONNECT_FAILE,
	NF_TEST_ROBOT_CONNECT_SUCCESS,
	NF_TEST_ROBOT_START_LOGIN,
	NF_TEST_ROBOT_LOGIN_FAILED,
	NF_TEST_ROBOT_LOGIN_SUCCESS,
    NF_TEST_ROBOT_START_GAME_CONNECT,
    NF_TEST_ROBOT_CONNECT_GAME_FAILE,
    NF_TEST_ROBOT_CONNECT_GAME_SUCCESS,
	NF_TEST_ROBOT_START_USER_LOGIN,
    NF_TEST_ROBOT_LOGIN_USER_FAILED,
    NF_TEST_ROBOT_LOGIN_USER_SUCCESS,
    NF_TEST_ROBOT_DISCONNECT_USER,
    NF_TEST_ROBOT_RECONNECT_SUCCESS,
    NF_TEST_ROBOT_SEND_RECONNECT,
	NF_TEST_MAX_STATUS,
};

class StatusAction;
class NFTestRobot : public NFIDynamicModule
{
public:
	NFTestRobot(NFIPluginManager* p):NFIDynamicModule(p)
	{
        m_playerId = 0;
        m_proxyLinkId = 0;
        m_gameId = 0;
        m_robotId = 0;
        m_deskId = 0;
        m_loginTime = 0;
		mStatus = NF_TEST_ROBOT_NONE_STATUS;
        m_phonenum = 0;
        m_loginLinkId = 0;
	}

	int ConnectServer(const std::string& url);
	int ConnectGameServer(const std::string& ip, int port);
    int CloseGameServer();
	int OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnGameServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleProxyOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleAccountLogin(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleAccountRegister(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleUserLogin(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleRegisterAccountPhoneAutoCode(uint64_t unLinkId, uint64_t value2, uint64_t playerId, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleRegisterAccountBindPhone(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandlePlazeStatus();
	int RegisterServer();
	int RegisterPhonenum();
	int RegisterAccountByPhonenum();
	int LoginServer();
	int UserLoginServer();
    int SendBeatHeart();
    int OnHandleAction();
    int ReconnectGameServer();
    int SendReconnectGameServer();
    int RedeemCodeReq();
    int OnHandleRedeemCodeRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    void OnTimer(uint32_t nTimerID);
    int SendMsgToServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToServer(uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData);
public:
    uint64_t m_phonenum;
	std::string m_account;
	std::string m_password;
	uint64_t m_playerId;
	uint64_t m_loginTime;
	std::string m_token;
	uint32_t m_gameId;
	uint32_t m_robotId;
	uint32_t m_deskId;
	NFTestRobotStatus mStatus;
	uint64_t m_proxyLinkId;
    uint64_t m_loginLinkId;
	std::string m_proxyIp;
	uint32_t m_port;

	uint64_t m_accoutLoginTime;
	uint64_t m_userLoginTime;
	std::vector<StatusAction*> m_statusAction;
};
