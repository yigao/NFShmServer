
#include "NFEvppServer.h"


bool NFEvppServer::Init()
{
    m_eventLoop.reset(NF_NEW evpp::EventLoopThread());
    m_eventLoop->set_name(GetServerName(mServerType));
    m_eventLoop->Start(true);

    std::string listenAddr;
    if (mFlag.mStrIp == "127.0.0.1")
    {
        listenAddr = NF_FORMAT("{}:{}", mFlag.mStrIp, mFlag.nPort);
    } else
    {
        listenAddr = NF_FORMAT("0.0.0.0:{}", mFlag.nPort);
    }

    m_tcpServer.reset(NF_NEW evpp::TCPServer(m_eventLoop->loop(), listenAddr, GetServerName(mServerType), mFlag.nWorkThreadNum, mFlag.mMaxConnectNum));
    if (!m_tcpServer)
    {
        return false;
    }

    mConnectionType = NF_CONNECTION_TYPE_TCP_SERVER;

    //链接回调是在别的线程里运行的
    m_tcpServer->SetConnectionCallback(mConnCallback);

    //消息回调是在别的线程里运行的
    m_tcpServer->SetMessageCallback(mMessageCallback);

    if (m_tcpServer->Init())
    {
        if (m_tcpServer->Start())
        {
            return true;
        }
    }
    return false;
}

bool NFEvppServer::Shut()
{
    m_eventLoop->loop()->RunAfter(100.0, [this]()
    {
        m_tcpServer->Stop();
    });

    while (!m_tcpServer->IsStopped()) {
        NFSLEEP(1);
    }

    m_eventLoop->Stop(true);

    return true;
}

bool NFEvppServer::Finalize()
{
    m_eventLoop.reset();
    m_tcpServer.reset();
    return true;
}

