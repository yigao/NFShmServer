// -------------------------------------------------------------------------
//    @FileName         :    NFEvppClient.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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

bool NFEvppClient::Init(evpp::EventLoop* loop)
{
    if (!loop)
    {
        m_eventLoop.reset(NF_NEW evpp::EventLoopThread());
        m_eventLoop->set_name(GetServerName(mServerType));
        m_eventLoop->Start(true);

        std::string strIpPort = NF_FORMAT("{}:{}", mFlag.mStrIp, mFlag.nPort);

        m_tcpClient.reset(NF_NEW evpp::TCPClient(m_eventLoop->loop(), strIpPort, "NFEvppClient"));
        if (!m_tcpClient)
        {
            return false;
        }
    }
    else
    {
        std::string strIpPort = NF_FORMAT("{}:{}", mFlag.mStrIp, mFlag.nPort);

        m_tcpClient.reset(NF_NEW evpp::TCPClient(loop, strIpPort, "NFEvppClient"));
        if (!m_tcpClient)
        {
            return false;
        }
    }

    mConnectionType = NF_CONNECTION_TYPE_TCP_CLIENT;

    //链接回调是在别的线程里运行的
    m_tcpClient->SetConnectionCallback(mConnCallback);

    //消息回调是在别的线程里运行的
    m_tcpClient->SetMessageCallback(mMessageCallback);
    m_tcpClient->set_auto_reconnect(true);
    m_tcpClient->set_reconnect_interval(evpp::Duration((double) 10));
    m_tcpClient->set_connecting_timeout(evpp::Duration((double) 10));

    m_tcpClient->Connect();

    return true;
}

bool NFEvppClient::Shut()
{
    if (m_tcpClient)
    {
        m_tcpClient->Disconnect();
    }

    if (m_eventLoop)
    {
        m_eventLoop->Stop(true);
    }

    return true;
}

bool NFEvppClient::Finalize()
{
    if (m_eventLoop)
    {
        m_eventLoop.reset();
    }

    if (m_tcpClient)
    {
        m_tcpClient.reset();
    }
    return true;
}

