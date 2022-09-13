// -------------------------------------------------------------------------
//    @FileName         :    NFCHttpClient.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCHttpClient.cpp
//
// -------------------------------------------------------------------------

#include "NFCHttpClient.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "evpp/httpc/response.h"
#include "NFComm/NFCore/NFCommon.h"

NFCHttpClient::NFCHttpClient() {
    m_threadLoop.Start();
    m_staticReqId = 10000;
}

NFCHttpClient::~NFCHttpClient() {
    m_threadLoop.Stop(true);
}

void NFCHttpClient::HandleHTTPGetResponse(const std::shared_ptr<evpp::httpc::Response> &response,
                                          evpp::httpc::GetRequest *request) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "HttpRespone url:http://{}{} code:{} body:{}", request->host(), request->uri(),
               response->http_code(), response->body().ToString());
    NF_ASSERT(request == response->request());

    NFHttpClientMsg *pMsg = NF_NEW NFHttpClientMsg();
    pMsg->code = response->http_code();
    pMsg->body = response->body().ToString();
    pMsg->reqid = request->GetId();
    mMsgQueue.Push(pMsg);

    NF_SAFE_DELETE(request); // The request MUST BE deleted in EventLoop thread.
}

int NFCHttpClient::HttpGet(const string &strUri, const HTTP_CLIENT_RESPONE &respone,
                           const map<std::string, std::string> &xHeaders, int timeout) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "HttpGet uri:{} headers:{}", strUri, NFCommon::tostr(xHeaders));

    evpp::httpc::GetRequest *req = new evpp::httpc::GetRequest(m_threadLoop.loop());
    CHECK_EXPR(req, -1, "new GetRequest Failed!");

    int ret = req->Init(strUri, "", evpp::Duration(timeout));
    CHECK_RET(ret, "req->Init uri:{} posData:{} Failed, ret:{}", strUri, "", ret);

    req->SetId(m_staticReqId++);

    for(auto iter = xHeaders.begin(); iter != xHeaders.end(); iter++)
    {
        req->AddHeader(iter->first, iter->second);
    }

    NFCHttpClientParam *pParam = NF_NEW NFCHttpClientParam(req->GetId(), respone, timeout);
    m_httpClientMap.emplace(pParam->m_id, pParam);

    req->Execute(std::bind(&NFCHttpClient::HandleHTTPGetResponse, this, std::placeholders::_1, req));
    return 0;
}

int NFCHttpClient::HttpPost(const string &strUri, const string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                            const map<std::string, std::string> &xHeaders, int timeout) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "HttpPost uri:{} headers:{}", strUri, NFCommon::tostr(xHeaders));

    evpp::httpc::PostRequest *req = new evpp::httpc::PostRequest(m_threadLoop.loop());
    CHECK_EXPR(req, -1, "new PostRequest Failed!");

    int ret = req->Init(strUri, strPostData, evpp::Duration(timeout));
    CHECK_RET(ret, "req->Init uri:{} posData:{} Failed", strUri, strPostData);

    req->SetId(m_staticReqId++);

    for(auto iter = xHeaders.begin(); iter != xHeaders.end(); iter++)
    {
        req->AddHeader(iter->first, iter->second);
    }

    NFCHttpClientParam *pParam = NF_NEW NFCHttpClientParam(req->GetId(), respone, timeout);
    m_httpClientMap.emplace(pParam->m_id, pParam);

    req->Execute(std::bind(&NFCHttpClient::HandleHTTPPostResponse, this, std::placeholders::_1, req));
    return 0;
}

void NFCHttpClient::HandleHTTPPostResponse(const shared_ptr<evpp::httpc::Response> &response,
                                           evpp::httpc::PostRequest *request) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "HttpRespone url:http://{}{} code:{} body:{}", request->host(), request->uri(),
               response->http_code(), response->body().ToString());
    NF_ASSERT(request == response->request());

    NFHttpClientMsg *pMsg = NF_NEW NFHttpClientMsg();
    pMsg->code = response->http_code();
    pMsg->body = response->body().ToString();
    pMsg->reqid = request->GetId();
    mMsgQueue.Push(pMsg);

    NF_SAFE_DELETE(request); // The request MUST BE deleted in EventLoop thread.
}

bool NFCHttpClient::Execute() {
    std::vector<NFHttpClientMsg*> vecMsg;
    mMsgQueue.Pop(vecMsg);
    for(int i = 0; i < (int)vecMsg.size(); i++)
    {
        NFHttpClientMsg* pMsg = vecMsg[i];
        if (pMsg)
        {
            auto iter = m_httpClientMap.find(pMsg->reqid);
            if (iter != m_httpClientMap.end())
            {
                NFCHttpClientParam* pParam = iter->second;
                if (pParam)
                {
                   pParam->m_resp(pMsg->code, pMsg->body);
                }
                m_httpClientMap.erase(iter);
            }
        }
        NF_SAFE_DELETE(pMsg);
    }

    for(auto iter = m_httpClientMap.begin(); iter != m_httpClientMap.end(); )
    {
        NFCHttpClientParam* pParam = iter->second;
        if (pParam)
        {
            if (!pParam->IsTimeOut())
            {
                iter++;
                continue;
            }
        }
        iter = m_httpClientMap.erase(iter);
    }
    return true;
}

