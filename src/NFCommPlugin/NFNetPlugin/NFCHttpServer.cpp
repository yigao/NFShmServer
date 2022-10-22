// -------------------------------------------------------------------------
//    @FileName         :    NFCHttpServer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCHttpServer.cpp
//
// -------------------------------------------------------------------------


#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFCHttpServer.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFCommon.h"
#include "evpp/http/context.h"
#include "evpp/libevent.h"
#include "NFComm/NFCore/NFTime.h"

NFCHttpServer::NFCHttpServer(uint32_t serverType, uint32_t netThreadNum)
{
    mServerType = serverType;
    mPort = 0;
    m_pHttpServer = new evpp::http::Server(netThreadNum);
    mIndex = 0;
    mListHttpRequestPool = NF_NEW NFObjectPool<NFServerHttpHandle>(1000, false);
    m_pHttpServer->RegisterDefaultHandler([this](evpp::EventLoop *loop,
                                                 const evpp::http::ContextPtr &ctx,
                                                 const evpp::http::HTTPSendResponseCallback &respcb)
                                          {
                                              NFEvppHttMsg msg;
                                              msg.mCtx = ctx;
                                              msg.mResponseCb = respcb;
                                              while (!mMsgQueue.Enqueue(msg)) {}
                                          });
}

NFCHttpServer::~NFCHttpServer()
{
    for (auto iter = mHttpRequestMap.begin(); iter != mHttpRequestMap.end(); iter++)
    {
        NF_SAFE_DELETE(iter->second);
    }
    mHttpRequestMap.clear();

    if (mListHttpRequestPool)
    {
        NF_SAFE_DELETE(mListHttpRequestPool);
    }

    if (m_pHttpServer)
    {
        m_pHttpServer->Stop();
        NFSLEEP(1000*1000); // sleep a while to release the listening address and port
        NF_SAFE_DELETE(m_pHttpServer);
    }
}

bool NFCHttpServer::Execute()
{
    ProcessMsgLogicThread();
    std::vector<NFServerHttpHandle *> vec;
    for (auto iter = mHttpRequestMap.begin(); iter != mHttpRequestMap.end(); iter++)
    {
        auto pRequest = iter->second;
        if (pRequest->timeOut + 30 <= (uint64_t) NFGetSecondTime())
        {
            vec.push_back(pRequest);
        }
    }

    for (int i = 0; i < (int) vec.size(); i++)
    {
        NFServerHttpHandle *pRequest = vec[i];
        ResponseMsg(*pRequest, "TimeOut Error", NFWebStatus::WEB_TIMEOUT);
    }

    return true;
}

uint32_t NFCHttpServer::GetServerType() const
{
    return mServerType;
}

bool NFCHttpServer::InitServer(uint32_t listen_port)
{
    if (m_pHttpServer->Init(listen_port))
    {
        if (m_pHttpServer->Start())
        {
            return true;
        }
        NFLogError(NF_LOG_NET_PLUGIN, 0, "Start Listen Port:{} Failed!", listen_port);
    }

    NFLogError(NF_LOG_NET_PLUGIN, 0, "Init Listen Port:{} Failed!", listen_port);
    return false;
}

bool NFCHttpServer::InitServer(const std::vector<uint32_t> &listen_ports)
{
    if (m_pHttpServer->Init((const std::vector<int> &) listen_ports))
    {
        if (m_pHttpServer->Start())
        {
            return true;
        }
        NFLogError(NF_LOG_NET_PLUGIN, 0, "Start Listen Port:{} Failed!", NFCommon::tostr(listen_ports));
    }

    NFLogError(NF_LOG_NET_PLUGIN, 0, "Init Listen Port:{} Failed!", NFCommon::tostr(listen_ports));
    return false;
}

bool NFCHttpServer::InitServer(const std::string &listen_ports/*like "80,8080,443"*/)
{
    if (m_pHttpServer->Init(listen_ports))
    {
        if (m_pHttpServer->Start())
        {
            return true;
        }
        NFLogError(NF_LOG_NET_PLUGIN, 0, "Start Listen Port:{} Failed!", listen_ports);
    }

    NFLogError(NF_LOG_NET_PLUGIN, 0, "Init Listen Port:{} Failed!", listen_ports);
    return false;
}

void NFCHttpServer::ProcessMsgLogicThread()
{
    int max_times = 10000;
    while (!mMsgQueue.IsQueueEmpty() && max_times >= 0)
    {
        std::vector<NFEvppHttMsg> vecMsg;
        vecMsg.resize(200);

        mMsgQueue.TryDequeueBulk(vecMsg);
        for (size_t i = 0; i < vecMsg.size(); i++)
        {
            max_times--;
            NFEvppHttMsg *pMsg = &vecMsg[i];
            if (pMsg == nullptr) continue;

            NFServerHttpHandle *pRequest = AllocHttpRequest();
            pRequest->mCtx = pMsg->mCtx;
            pRequest->mResponseCb = pMsg->mResponseCb;
            pRequest->type = (NFHttpType) pMsg->mCtx->req()->type;
            pRequest->timeOut = NFTime::Now().UnixSec();

            mHttpRequestMap.emplace(pRequest->requestId, pRequest);

            bool flag = true;
            if (mFilter)
            {
                //return 401
                try
                {
                    NFWebStatus xWebStatus = mFilter(mServerType, *pRequest);
                    if (xWebStatus != NFWebStatus::WEB_OK)
                    {
                        //401
                        ResponseMsg(*pRequest, "Filter error", xWebStatus);
                        flag = false;
                    }
                }
                catch (std::exception &e)
                {
                    ResponseMsg(*pRequest, e.what(), NFWebStatus::WEB_ERROR);
                    flag = false;
                }
                catch (...)
                {
                    ResponseMsg(*pRequest, "UNKNOW ERROR", NFWebStatus::WEB_ERROR);
                    flag = false;
                }
            }

            if (flag)
            {
                // call cb
                try
                {
                    if (mReceiveCB)
                    {
                        mReceiveCB(mServerType, *pRequest);
                    } else
                    {
                        ResponseMsg(*pRequest, "NO PROCESSER", NFWebStatus::WEB_ERROR);
                    }
                }
                catch (std::exception &e)
                {
                    ResponseMsg(*pRequest, e.what(), NFWebStatus::WEB_ERROR);
                }
                catch (...)
                {
                    ResponseMsg(*pRequest, "UNKNOW ERROR", NFWebStatus::WEB_ERROR);
                }
            }
        }
    }
}

NFServerHttpHandle *NFCHttpServer::AllocHttpRequest()
{
    NFServerHttpHandle *pRequest = mListHttpRequestPool->MallocObj();
    CHECK_EXPR_ASSERT(pRequest, NULL, "mListHttpRequestPool->MallocObj() Failed");

    pRequest->Reset();

    pRequest->requestId = ++mIndex;

    return pRequest;
}

bool NFCHttpServer::ResponseMsg(const NFIHttpHandle &req, const std::string &strMsg, NFWebStatus code,
                                const std::string &strReason)
{
    req.ResponseMsg(strMsg, code, strReason);

    auto it = mHttpRequestMap.find(req.GetRequestId());
    if (it != mHttpRequestMap.end())
    {
        it->second->Reset();
        mListHttpRequestPool->FreeObj(it->second);
        mHttpRequestMap.erase(it);
    }
    return true;
}

bool NFCHttpServer::ResponseMsg(uint64_t requestId, const std::string &strMsg, NFWebStatus code,
                                const std::string &strReason)
{
    NFServerHttpHandle *req = nullptr;
    auto it = mHttpRequestMap.find(requestId);
    if (it == mHttpRequestMap.end())
    {
        NFLogError(NF_LOG_NET_PLUGIN, 0, "Response Msg Timeout........ requestId:{}, mStrMsg:{}", requestId, strMsg);
        return false;
    }

    req = it->second;

    bool ret = req->ResponseMsg(strMsg, code, strReason);
    if (!ret)
    {
        NFLogError(NF_LOG_NET_PLUGIN, 0, "Response Msg error........ requestId:{}, mStrMsg:{}", requestId, strMsg);
    }

    req->Reset();
    mListHttpRequestPool->FreeObj(it->second);
    mHttpRequestMap.erase(it);
    return true;
}

#if defined(EVPP_HTTP_SERVER_SUPPORTS_SSL)
/* berif 对指定监听端口设置SSL选项
 * param listen_port 监听的端口
 * param enable_ssl 是否开启SSL支持
 * param certificate_chain_file 证书链文件
 * param private_key_file 私钥文件
 */
void NFCHttpServer::SetPortSSLOption(int listen_port,
                      bool enable_ssl,
                      const char* certificate_chain_file,
                      const char* private_key_file)
{
    m_pHttpServer->setPortSSLOption(listen_port, enable_ssl, certificate_chain_file, private_key_file);
}

/* berif 设置端口默认SSL配置选项
 * param enable_ssl 是否开启SSL支持
 * param certificate_chain_file 证书链文件
 * param private_key_file 私钥文件
 */
void NFCHttpServer::SetPortSSLDefaultOption(
        bool enable_ssl,
        const char* certificate_chain_file,
        const char* private_key_file)
{
    m_pHttpServer->setPortSSLDefaultOption( enable_ssl, certificate_chain_file, private_key_file);
}
#endif


