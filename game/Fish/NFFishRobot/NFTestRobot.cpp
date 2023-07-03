#include "NFTestRobot.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFMD5.h"
#include "ClientServerCmd.pb.h"
#include "CSLogin.pb.h"

enum RobotTimer
{
    ENUM_ROBOT_TIMER_PLAZE = 1,
    ENUM_ROBOT_TIMER_GAME = 2,
};

int NFTestRobot::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == ENUM_ROBOT_TIMER_PLAZE)
    {
        OnHandlePlazeStatus();
    }
    return 0;
}

int NFTestRobot::ConnectServer(const std::string& url)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
	mStatus = NF_TEST_ROBOT_START_CONNECT;
    m_proxyLinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_GAME_SERVER, url, PACKET_PARSE_TYPE_EXTERNAL);
	CHECK_EXPR(m_proxyLinkId > 0, -1, "ConnectServer url:{} failed!", url);
    m_loginLinkId = m_proxyLinkId;

    FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnProxyServerSocketEvent);
    FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnHandleProxyOtherMessage);

	SetTimer(ENUM_ROBOT_TIMER_PLAZE, 1000, 0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
	return 0;
}

int NFTestRobot::OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		mStatus = NF_TEST_ROBOT_CONNECT_SUCCESS;
		NFLogDebug(NF_LOG_SYSTEMLOG, 0, "rebot:{} connect login success!", m_robotId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		mStatus = NF_TEST_ROBOT_CONNECT_FAILE;
		NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} disconnect login", m_robotId);
	}
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
	return 0;
}

int NFTestRobot::OnHandleProxyOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    uint32_t nMsgId = packet.nMsgId;
	if (nMsgId == proto_ff::NF_SC_MSG_AccountLoginRsp)
    {
	    OnHandleAccountLogin(unLinkId, packet);
    }
	else if (nMsgId == proto_ff::NF_SC_Msg_HeartBeat_RSP)
    {

    }
	else
    {
    }
	return 0;
}

int NFTestRobot::OnHandleAccountLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::Proto_SCAccountLoginRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, gcMsg);

    NFLogError(NF_LOG_SYSTEMLOG, 0, "account login use time:{}", NFGetTime() - m_accoutLoginTime);
    if (gcMsg.result() == 0)
    {
        m_playerId = gcMsg.user_id();
        m_loginTime = gcMsg.login_time();
        m_token = gcMsg.token();
        mStatus = NF_TEST_ROBOT_LOGIN_SUCCESS;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} account login success", m_robotId);
        if (gcMsg.server_ip_list_size() > 0)
        {
            //int index = NFRandInt(0, gcMsg.server_ip_list_size());
            //ConnectGameServer(gcMsg.server_ip_list(index).ip(), gcMsg.server_ip_list(index).port());
        }
    } else {
        mStatus = NF_TEST_ROBOT_LOGIN_FAILED;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} account login failed", m_robotId);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTestRobot::SendBeatHeart()
{
    proto_ff::Proto_CSHeartBeatReq cgMsg;
    if (m_proxyLinkId > 0)
    {
        FindModule<NFIMessageModule>()->Send(m_proxyLinkId, proto_ff::NF_CS_Msg_HeartBeat_REQ, cgMsg, 0);
    }

    if (m_loginLinkId > 0)
    {
        FindModule<NFIMessageModule>()->Send(m_loginLinkId, proto_ff::NF_CS_Msg_HeartBeat_REQ, cgMsg, 0);
    }

    return 0;
}

int NFTestRobot::OnHandlePlazeStatus()
{
	if (mStatus == NF_TEST_ROBOT_CONNECT_SUCCESS)
	{
		LoginServer();
	}

	if (mStatus >= NF_TEST_ROBOT_CONNECT_SUCCESS)
    {
	    SendBeatHeart();
    }

    if (mStatus == NF_TEST_ROBOT_CONNECT_GAME_SUCCESS)
    {
    }

	if (mStatus >= NF_TEST_ROBOT_LOGIN_USER_SUCCESS)
    {
	    if (mStatus == NF_TEST_ROBOT_DISCONNECT_USER)
        {
        }
        else if (mStatus == NF_TEST_ROBOT_RECONNECT_SUCCESS)
        {
        }
        else if (mStatus == NF_TEST_ROBOT_SEND_RECONNECT)
        {

        }
        else
        {

        }
    }
	return 0;
}

int NFTestRobot::SendMsgToServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIMessageModule>()->Send(m_proxyLinkId, nMsgId, xData);
    return 0;
}

int NFTestRobot::LoginServer()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    mStatus = NF_TEST_ROBOT_START_LOGIN;
    m_account = "robot_" + NFCommon::tostr(m_robotId);
    m_password = "robot_" + NFCommon::tostr(m_robotId);

    m_accoutLoginTime = NFGetTime();
    proto_ff::Proto_CSAccountLoginReq xMsg;
    xMsg.set_account(m_account);
    xMsg.set_password(m_password);
    xMsg.set_login_type(proto_ff::E_VISITOR);

    SendMsgToServer(proto_ff::NF_CS_MSG_AccountLoginReq, xMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}