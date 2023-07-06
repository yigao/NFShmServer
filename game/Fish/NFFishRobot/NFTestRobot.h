#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

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
	int OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleProxyOtherMessage(uint64_t unLinkId, NFDataPackage &packet);
    int OnHandleAccountLogin(uint64_t unLinkId, NFDataPackage &packet);


    int OnTimer(uint32_t nTimerID);
    int SendMsgToServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int OnHandlePlazeStatus();
public:
    /**
     * @brief 游客直接登录
     * @return
     */
    int VisitorLogin();

    /**
     * @brief 账号登录
     * @return
     */
    int AccountLogin();

    /**
     * @brief 注册账号
     * @return
     */
    int RegisterAccount();

    /**
     * @brief 发心跳包
     * @return
     */
    int SendBeatHeart();
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
