// -------------------------------------------------------------------------
//    @FileName         :    NFEvppClient.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
//
//                    .::::.
//                  .::::::::.
//                 :::::::::::  FUCK YOU
//             ..:::::::::::'
//           '::::::::::::'
//             .::::::::::
//        '::::::::::::::..
//             ..::::::::::::.
//           ``::::::::::::::::
//            ::::``:::::::::'        .:::.
//           ::::'   ':::::'       .::::::::.
//         .::::'      ::::     .:::::::'::::.
//        .:::'       :::::  .:::::::::' ':::::.
//       .::'        :::::.:::::::::'      ':::::.
//      .::'         ::::::::::::::'         ``::::.
//  ...:::           ::::::::::::'              ``::.
// ```` ':.          ':::::::::'                  ::::..
//                    '.:::::'                    ':'````..
//
// -------------------------------------------------------------------------

#include "NFEvppClient.h"

bool NFEvppClient::Init()
{
	m_eventLoop = NF_NEW evpp::EventLoopThread();
	m_eventLoop->set_name(GetServerName(mServerType));
	m_eventLoop->Start(true);

	std::string strIpPort = NF_FORMAT("{}:{}", mFlag.mStrIp, mFlag.nPort);

	m_tcpClient = NF_NEW evpp::TCPClient(m_eventLoop->loop(), strIpPort, "NFEvppClient");
	if (!m_tcpClient)
	{
		return false;
	}

	mConnectionType = NF_CONNECTION_TYPE_TCP_CLIENT;

	//链接回调是在别的线程里运行的
	m_tcpClient->SetConnectionCallback(mConnCallback);

	//消息回调是在别的线程里运行的
	m_tcpClient->SetMessageCallback(mMessageCallback);
	m_tcpClient->set_auto_reconnect(true);
	m_tcpClient->set_reconnect_interval(evpp::Duration((double)10));
    m_tcpClient->set_connecting_timeout(evpp::Duration((double)10));

	m_tcpClient->Connect();

	return true;
}

bool NFEvppClient::Shut()
{
	if (m_tcpClient)
	{
		m_tcpClient->Disconnect();
	}

	while(m_eventLoop->IsRunning())
	{
		m_eventLoop->Stop(true);
	}

	return true;
}

bool NFEvppClient::Finalize()
{
	if (m_eventLoop)
	{
		NF_SAFE_DELETE(m_eventLoop);
	}

	if (m_tcpClient)
	{
		NF_SAFE_DELETE(m_tcpClient);
	}
	return true;
}

