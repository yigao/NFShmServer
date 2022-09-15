// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFMessageMgr.h"
#include "NFCheck.h"

NFMessageMgr::NFMessageMgr()
{
	m_pMessageModule = NULL;
}

NFMessageMgr::~NFMessageMgr()
{

}

bool NFMessageMgr::Init(NFIMessageModule *pMessageModule)
{
    m_pMessageModule = pMessageModule;
    return true;
}

void NFMessageMgr::UnInit()
{
    m_pMessageModule = NULL;
}

int64_t NFMessageMgr::BindServer(NF_SERVER_TYPES eServerType, const string &url, uint32_t netThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType, bool bSecurity)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->BindServer(eServerType, url, netThreadNum, nMaxConnectNum, nPacketParseType, bSecurity);
}

int64_t NFMessageMgr::ConnectServer(NF_SERVER_TYPES eServerType, const string &url, uint32_t nPacketParseType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ConnectServer(eServerType, url, nPacketParseType);
}

int NFMessageMgr::ResumeConnect(NF_SERVER_TYPES eServerType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ResumeConnect(eServerType);
}

std::string NFMessageMgr::GetLinkIp(uint64_t usLinkId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetLinkIp(usLinkId);
}

void NFMessageMgr::CloseLinkId(uint64_t usLinkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CloseLinkId(usLinkId);
}

void NFMessageMgr::CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CloseServer(eServerType, destServer, busId, usLinkId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const string &strData, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nModuleId, nMsgID, strData, nSendValue, nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nModuleId, nMsgID, msg, nLen, nSendValue, nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nModuleId, nMsgID, xData, nSendValue, nSendId);
}

int NFMessageMgr::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgByBusId(eType, busId, nModuleId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgByBusId(eType, busId, nModuleId, nMsgId, msg, nLen, valueId);
}

int NFMessageMgr::SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nModuleId, uint32_t nMsgId,
                                  const google::protobuf::Message &xData, uint64_t param1, uint64_t param2)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToServer(eSendType, recvType, srcBusId, dstBusId, nModuleId, nMsgId, xData, param1, param2);
}

NFServerData *NFMessageMgr::GetRouteData(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetRouteData(eSendType);
}

const NFServerData *NFMessageMgr::GetRouteData(NF_SERVER_TYPES eSendType) const
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetRouteData(eSendType);
}

NFServerData *NFMessageMgr::GetMasterData(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetMasterData(eSendType);
}

const NFServerData *NFMessageMgr::GetMasterData(NF_SERVER_TYPES eSendType) const
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetMasterData(eSendType);
}

void NFMessageMgr::CloseAllLink(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CloseAllLink(eSendType);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerByServerId(eSendType, busId);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerByUnlinkId(eSendType, unlinkId);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->CreateServerByServerId(eSendType, busId, busServerType, data);
}

void NFMessageMgr::CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId, uint64_t linkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CreateLinkToServer(eSendType, busId, linkId);
}

void NFMessageMgr::DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->DelServerLink(eSendType, linkId);
}

bool NFMessageMgr::AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget, const NET_EVENT_FUNCTOR &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddEventCallBack(eType, linkId, pTaraget, cb);
}

bool NFMessageMgr::AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void *pTaraget, const NET_RECEIVE_FUNCTOR &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddMessageCallBack(eType, nMsgID, pTaraget, cb);
}

bool NFMessageMgr::AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, void* pTaraget, const NET_RECEIVE_FUNCTOR & cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddMessageCallBack(eType, nModuleId, nMsgID, pTaraget, cb);
}

bool NFMessageMgr::AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget, const NET_RECEIVE_FUNCTOR &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddOtherCallBack(eType, linkId, pTaraget, cb);
}

int NFMessageMgr::HttpGet(NF_SERVER_TYPES serverType, const string &strUri, const HTTP_CLIENT_RESPONE &respone, const map<std::string, std::string> &xHeaders, int timeout)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->HttpGet(serverType, strUri, respone, xHeaders, timeout);
}

int NFMessageMgr::HttpPost(NF_SERVER_TYPES serverType, const string &strUri, const string &strPostData, const HTTP_CLIENT_RESPONE &respone, const map<std::string, std::string> &xHeaders, int timeout)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->HttpPost(serverType, strUri, strPostData, respone, xHeaders, timeout);
}

bool NFMessageMgr::DelAllCallBack(void *pTarget)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->DelAllCallBack(pTarget);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFMessageMgr::GetAllServer(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetAllServer(eSendType);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFMessageMgr::GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetAllServer(eSendType, serverTypes);
}

std::vector<std::string> NFMessageMgr::GetDBNames(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetDBNames(eSendType);
}

bool NFMessageMgr::ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const string &strMsg, NFWebStatus code, const string &reason)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ResponseHttpMsg(serverType, req, strMsg, code, reason);
}

bool NFMessageMgr::ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const string &strMsg, NFWebStatus code, const string &reason)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ResponseHttpMsg(serverType, requestId, strMsg, code, reason);
}

uint64_t NFMessageMgr::GetServerLinkId(NF_SERVER_TYPES eSendType) const
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerLinkId(eSendType);
}

void NFMessageMgr::SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->SetServerLinkId(eSendType, linkId);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFMessageMgr::GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerByServerType(eSendType, serverTypes);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetFirstServerByServerType(eSendType, serverTypes);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetRandomServerByServerType(eSendType, serverTypes);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetSuitServerByServerType(eSendType, serverTypes, value);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const string &value)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetSuitServerByServerType(eSendType, serverTypes, value);
}
