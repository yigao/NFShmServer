#include "NFTestRobot.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"

enum RobotTimer
{
    ENUM_ROBOT_TIMER_PLAZE = 1,
    ENUM_ROBOT_TIMER_GAME = 2,
};

void NFTestRobot::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == ENUM_ROBOT_TIMER_PLAZE)
    {
        OnHandlePlazeStatus();
    }
}

int NFTestRobot::ConnectServer(const std::string& url)
{
	NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
	mStatus = NF_TEST_ROBOT_START_CONNECT;
    m_proxyLinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_GAME_SERVER, url, PACKET_PARSE_TYPE_EXTERNAL);
	CHECK_EXPR(m_proxyLinkId > 0, -1, "ConnectServer url:{} failed!", url);
    m_loginLinkId = m_proxyLinkId;

	NFMessageMgr::Instance()->AddEventCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnProxyServerSocketEvent);
	NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnHandleProxyOtherMessage);

	NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    mStatus = NF_TEST_ROBOT_CONNECT_SUCCESS;

	SetTimer(ENUM_ROBOT_TIMER_PLAZE, 1000, 0);
	return 0;
}

int NFTestRobot::CloseGameServer()
{
    NFMessageMgr::Instance()->CloseLinkId(m_proxyLinkId);
    m_proxyLinkId = 0;
    return 0;
}

int NFTestRobot::ReconnectGameServer()
{
    std::string url = NF_FORMAT("tcp://{}:{}", m_proxyIp, m_port);
    m_proxyLinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_GAME_SERVER, url, PACKET_PARSE_TYPE_EXTERNAL);
    CHECK_EXPR(m_proxyLinkId > 0, -1, "ConnectServer url:{} failed!", url);

    NFMessageMgr::Instance()->AddEventCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnGameServerSocketEvent);
    NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnHandleProxyOtherMessage);
    return 0;
}

int NFTestRobot::SendReconnectGameServer()
{
    mStatus = NF_TEST_ROBOT_SEND_RECONNECT;
    proto_login::Proto_CSReconnectReq cgMsg;
    cgMsg.set_userid(m_playerId);

    SendMsgToServer(proto_login::NF_CS_Msg_ReConnect_REQ, cgMsg);
    return 0;
}

int NFTestRobot::ConnectGameServer(const std::string& ip, int port)
{
    mStatus = NF_TEST_ROBOT_START_GAME_CONNECT;
    std::string url = NF_FORMAT("tcp://{}:{}", ip, port);
    m_proxyLinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_GAME_SERVER, url, PACKET_PARSE_TYPE_EXTERNAL);
    CHECK_EXPR(m_proxyLinkId > 0, -1, "ConnectServer url:{} failed!", url);
    m_proxyIp = ip;
    m_port = port;

    NFMessageMgr::Instance()->AddEventCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnGameServerSocketEvent);
    NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_GAME_SERVER, m_proxyLinkId, this, &NFTestRobot::OnHandleProxyOtherMessage);
    return 0;
}

int NFTestRobot::OnGameServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {
        if (mStatus >= NF_TEST_ROBOT_LOGIN_USER_SUCCESS)
        {
            mStatus = NF_TEST_ROBOT_RECONNECT_SUCCESS;
            NFLogDebug(NF_LOG_TEST_PLUGIN, 0, "rebot:{} reconnect game success!", m_robotId);
        }
        else
        {
            mStatus = NF_TEST_ROBOT_CONNECT_GAME_SUCCESS;
            NFLogDebug(NF_LOG_TEST_PLUGIN, 0, "rebot:{} connect game success!", m_robotId);
        }
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        if (mStatus >= NF_TEST_ROBOT_LOGIN_USER_SUCCESS)
        {
            mStatus = NF_TEST_ROBOT_DISCONNECT_USER;
        }
        else
        {
            mStatus = NF_TEST_ROBOT_CONNECT_GAME_FAILE;
        }
        NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "robot:{} disconnect game", m_robotId);
    }
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		//mStatus = NF_TEST_ROBOT_CONNECT_SUCCESS;
		NFLogDebug(NF_LOG_TEST_PLUGIN, 0, "rebot:{} connect login success!", m_robotId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		mStatus = NF_TEST_ROBOT_CONNECT_FAILE;
		NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "robot:{} disconnect login", m_robotId);
	}
	NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTestRobot::OnHandleProxyOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	if (nMsgId == proto_login::NF_SC_MSG_AccountLoginRsp)
    {
	    OnHandleAccountLogin(unLinkId, playerId, value2, nMsgId, msg, nLen);
    }
    else if (nMsgId == proto_login::NF_SC_MSG_UserLoginRsp)
    {
        OnHandleUserLogin(unLinkId, playerId, value2, nMsgId, msg, nLen);
    }
    else if (nMsgId == proto_login::NF_SC_MSG_RegisterAccountRsp)
    {
        OnHandleAccountRegister(unLinkId, playerId, value2, nMsgId, msg, nLen);
    }
    else if (nMsgId == proto_login::NF_SC_MSG_LoginServer_PhoneAutoCodeRsp)
    {
        OnHandleRegisterAccountPhoneAutoCode(unLinkId, playerId, value2, nMsgId, msg, nLen);
    }
    else if (nMsgId == proto_login::NF_SC_MSG_LoginServer_CheckPhoneCodeRsp)
    {
        OnHandleRegisterAccountBindPhone(unLinkId, playerId, value2, nMsgId, msg, nLen);
    }
	else if (nMsgId == proto_login::NF_SC_Msg_HeartBeat_RSP)
    {

    }
	else
    {
	   for(int i = 0; i < (int)m_statusAction.size(); i++)
       {
           //m_statusAction[i]->OnHandleMessage(unLinkId, playerId, value2, nMsgId, msg, nLen);
       }
    }
	return 0;
}

int NFTestRobot::OnHandleUserLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");

    proto_login::Proto_SCUserLoginRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    NFLogError(NF_LOG_SYSTEMLOG, 0, "user login use time:{}", NFGetTime() - m_userLoginTime);
    if (gcMsg.result() == 0)
    {
        mStatus = NF_TEST_ROBOT_LOGIN_USER_SUCCESS;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} user login success", m_robotId);
    } else {
        mStatus = NF_TEST_ROBOT_LOGIN_USER_FAILED;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} user login failed", m_robotId);
    }

    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::OnHandleRegisterAccountBindPhone(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");

    proto_login::Proto_SC_LoginServer_CheckPhoneCodeRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    if (gcMsg.result() == 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} bind phone success", m_robotId);
        mStatus = NF_TEST_ROBOT_LOGIN_SUCCESS;
        RegisterAccountByPhonenum();
    } else {
        mStatus = NF_TEST_ROBOT_LOGIN_FAILED;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} bind phone failed", m_robotId);
    }

    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::OnHandleRegisterAccountPhoneAutoCode(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");

    proto_login::Proto_SC_LoginServer_PhoneAutoCodeRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    if (gcMsg.result() == 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} phone auto code success", m_robotId);
        mStatus = NF_TEST_ROBOT_LOGIN_SUCCESS;
        int authcode = 888888;

        proto_login::Proto_CS_LoginServer_CheckPhoneCodeReq reqMsg;
        reqMsg.set_phone_num(gcMsg.phone_num());
        reqMsg.set_auth_code(authcode);

        SendMsgToServer(proto_login::NF_CS_MSG_LoginServer_CheckPhoneCodeReq, reqMsg);
    } else {
        mStatus = NF_TEST_ROBOT_LOGIN_FAILED;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} phone auto code failed", m_robotId);
    }

    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::OnHandleAccountRegister(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");

    proto_login::Proto_SCRegisterAccountRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

    if (gcMsg.result() == 0)
    {
        m_playerId = gcMsg.user_id();
        m_loginTime = gcMsg.login_time();
        m_token = gcMsg.token();
        mStatus = NF_TEST_ROBOT_LOGIN_SUCCESS;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} account register success", m_robotId);
        if (gcMsg.server_ip_list_size() > 0)
        {
            int index = NFRandInt(0, gcMsg.server_ip_list_size());
            ConnectGameServer(gcMsg.server_ip_list(index).ip(), gcMsg.server_ip_list(index).port());
        }
    } else {
        mStatus = NF_TEST_ROBOT_LOGIN_FAILED;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} register login failed", m_robotId);
    }

    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::OnHandleAccountLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");

    proto_login::Proto_SCAccountLoginRsp gcMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, gcMsg);

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
            int index = NFRandInt(0, gcMsg.server_ip_list_size());
            ConnectGameServer(gcMsg.server_ip_list(index).ip(), gcMsg.server_ip_list(index).port());
        }
    } else {
        mStatus = NF_TEST_ROBOT_LOGIN_FAILED;
        NFLogError(NF_LOG_SYSTEMLOG, 0, "robot:{} account login failed", m_robotId);
        RegisterServer();
    }

    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::SendBeatHeart()
{
    proto_login::Proto_CSHeartBeatReq cgMsg;
    NFMessageMgr::Instance()->Send(m_proxyLinkId, proto_login::NF_CS_Msg_HeartBeat_REQ, cgMsg, 0);

    NFMessageMgr::Instance()->Send(m_loginLinkId, proto_login::NF_CS_Msg_HeartBeat_REQ, cgMsg, 0);

    return 0;
}

int NFTestRobot::OnHandlePlazeStatus()
{
	if (mStatus == NF_TEST_ROBOT_CONNECT_SUCCESS)
	{
        //RegisterPhonenum();
		LoginServer();
	}

	if (mStatus >= NF_TEST_ROBOT_CONNECT_SUCCESS)
    {
	    SendBeatHeart();
    }

    if (mStatus == NF_TEST_ROBOT_CONNECT_GAME_SUCCESS)
    {
        UserLoginServer();
    }

	if (mStatus >= NF_TEST_ROBOT_LOGIN_USER_SUCCESS)
    {
	    if (mStatus == NF_TEST_ROBOT_DISCONNECT_USER)
        {
            ReconnectGameServer();
        }
        else if (mStatus == NF_TEST_ROBOT_RECONNECT_SUCCESS)
        {
            SendReconnectGameServer();
        }
        else if (mStatus == NF_TEST_ROBOT_SEND_RECONNECT)
        {

        }
        else
        {
            int rand = NFRandInt(1, 100);
            if (rand <= 0)
            {
                CloseGameServer();
            }
            else
            {
                OnHandleAction();
            }
        }
    }
	return 0;
}

int NFTestRobot::OnHandleAction()
{
    if (m_statusAction.empty())
    {
//        StatusAction* pMailAction = NF_NEW NFMailAction(m_pPluginManager, this);
//        pMailAction->Awake();
//        m_statusAction.push_back(pMailAction);
//        NFBankAction* pBankAction = NF_NEW NFBankAction(m_pPluginManager, this);
//        pBankAction->Awake();
//        m_statusAction.push_back(pBankAction);
    }

//    int index = NFRandInt(0, (int)m_statusAction.size());
//    if (index >= 0 && index < (int)m_statusAction.size())
//    {
        //StatusAction* pA = m_statusAction[index];
        //pA->OnHandleAction();
//    }
    return 0;
}

int NFTestRobot::RegisterServer()
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
    mStatus = NF_TEST_ROBOT_START_LOGIN;
    m_account = "gaoyi" + NFCommon::tostr(m_robotId);
    m_password = "gaoyi" + NFCommon::tostr(m_robotId);

    proto_login::Proto_CSRegisterAccountReq xMsg;
    xMsg.set_account(m_account);
    xMsg.set_password(m_password);

    SendMsgToServer(proto_login::NF_CS_MSG_RegisterAccountReq, xMsg);
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::RegisterAccountByPhonenum()
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
    mStatus = NF_TEST_ROBOT_START_LOGIN;
    m_account = "18927427460";
    m_password = "18927427460";

    proto_login::Proto_CSRegisterAccountReq xMsg;
    xMsg.set_account(m_account);
    xMsg.set_password(m_password);
    xMsg.set_nick_name("18927427460");
    xMsg.set_is_phone(true);

    SendMsgToServer(proto_login::NF_CS_MSG_RegisterAccountReq, xMsg);
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::RegisterPhonenum()
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
    mStatus = NF_TEST_ROBOT_START_LOGIN;
    m_phonenum = 18927427460;

    proto_login::Proto_CS_LoginServer_PhoneAutoCodeReq xMsg;
    xMsg.set_phone_num(m_phonenum);
    xMsg.set_code_type(1);

    SendMsgToServer(proto_login::NF_CS_MSG_LoginServer_PhoneAutoCodeReq, xMsg);
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::LoginServer()
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
    mStatus = NF_TEST_ROBOT_START_LOGIN;
    m_account = "robot_" + NFCommon::tostr(m_robotId);
    m_password = "robot_" + NFCommon::tostr(m_robotId);

    m_accoutLoginTime = NFGetTime();
    proto_login::Proto_CSAccountLoginReq xMsg;
    xMsg.set_account(m_account);
    xMsg.set_password(m_password);
    xMsg.set_contract_info(NFMD5::md5str("ubuntu37du_0000001"));
    xMsg.set_login_type(proto_ff::E_VISITOR);

    SendMsgToServer(proto_login::NF_CS_MSG_AccountLoginReq, xMsg);
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::UserLoginServer()
{
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- begin --");
    mStatus = NF_TEST_ROBOT_START_USER_LOGIN;
    proto_login::Proto_CSUserLoginReq xMsg;
    xMsg.set_user_id(m_playerId);
    xMsg.set_account(m_account);
    xMsg.set_login_time(m_loginTime);
    xMsg.set_token(m_token);

    m_userLoginTime = NFGetTime();
    xMsg.mutable_ext_data()->set_agent_id(10000);
    xMsg.mutable_ext_data()->set_aread_id(1);
    xMsg.mutable_ext_data()->set_channel_id(1);
    xMsg.mutable_ext_data()->set_platform_os("ios12");
    xMsg.mutable_ext_data()->set_phone_mode("xiaomi10");
    xMsg.mutable_ext_data()->set_country("chinese");
    xMsg.mutable_ext_data()->set_province("guangdong");
    xMsg.mutable_ext_data()->set_city("shengzhen");

    SendMsgToServer(proto_login::NF_CS_MSG_UserLoginReq, xMsg);
    NFLogTrace(NF_LOG_TEST_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTestRobot::SendMsgToServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    NFMessageMgr::Instance()->Send(m_proxyLinkId, nMsgId, xData);
    return 0;
}

int NFTestRobot::SendMsgToServer(uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData)
{
    NFMessageMgr::Instance()->Send(m_proxyLinkId, nMainMsgId, nSubMsgId, xData);
    return 0;
}

int NFTestRobot::RedeemCodeReq()
{
    return 0;
}

int NFTestRobot::OnHandleRedeemCodeRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    return 0;
}
