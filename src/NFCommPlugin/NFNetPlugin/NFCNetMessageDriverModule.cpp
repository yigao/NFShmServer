// -------------------------------------------------------------------------
//    @FileName         :    NFCNetServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Module           :    NFCNetServerModule
// -------------------------------------------------------------------------

#include <NFComm/NFPluginModule/NFIConfigModule.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFCNetMessageDriverModule.h"

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFIPacketParse.h"
#include "NFEvppNetMessage.h"
#include "NFCBusMessage.h"
#include "NFComm/NFCore/NFSocketLibFunction.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "evpp/httpc/ssl.h"
#include "NFEmailSender.h"

NFCNetMessageDriverModule::NFCNetMessageDriverModule(NFIPluginManager* p):NFIMessageDriver(p)
{
	NFSocketLibFunction::InitSocket();
#if defined(EVPP_HTTP_CLIENT_SUPPORTS_SSL)
	if (!evpp::httpc::GetSSLCtx())
    {
        evpp::httpc::InitSSL();
    }
#endif
	mNetServerArray.resize(NF_ST_MAX);
	for (int i = 0; i < NF_SERVER_TYPES::NF_ST_MAX; ++i)
	{
		mNetServerArray[i] = nullptr;
	}
	mBusServerArray.resize(NF_ST_MAX);
	for (int i = 0; i < NF_SERVER_TYPES::NF_ST_MAX; ++i)
	{
		mBusServerArray[i] = nullptr;
	}
}

NFCNetMessageDriverModule::~NFCNetMessageDriverModule()
{
#if defined(EVPP_HTTP_CLIENT_SUPPORTS_SSL)
    if (evpp::httpc::GetSSLCtx())
    {
        evpp::httpc::CleanSSL();
    }
#endif
}

bool NFCNetMessageDriverModule::Awake()
{
	return true;
}

bool NFCNetMessageDriverModule::BeforeShut()
{
	return true;
}

bool NFCNetMessageDriverModule::Shut()
{
	for (size_t i = 0; i < mNetServerArray.size(); i++)
	{
		if (mNetServerArray[i] != nullptr)
		{
			mNetServerArray[i]->Shut();
		}
	}
	for (size_t i = 0; i < mBusServerArray.size(); i++)
	{
		if (mBusServerArray[i] != nullptr)
		{
			mBusServerArray[i]->Shut();
		}
	}
	return true;
}

bool NFCNetMessageDriverModule::Finalize()
{
	for (size_t i = 0; i < mNetServerArray.size(); i++)
	{
		if (mNetServerArray[i] != nullptr)
		{
			mNetServerArray[i]->Finalize();
			NF_SAFE_DELETE(mNetServerArray[i]);
		}
	}
	for (size_t i = 0; i < mBusServerArray.size(); i++)
	{
		if (mBusServerArray[i] != nullptr)
		{
			mBusServerArray[i]->Finalize();
			NF_SAFE_DELETE(mBusServerArray[i]);
		}
	}
	mNetServerArray.clear();
	mBusServerArray.clear();
	return true;
}

bool NFCNetMessageDriverModule::ReadyExecute()
{
    for (size_t i = 0; i < mNetServerArray.size(); i++)
    {
        if (mNetServerArray[i] != nullptr)
        {
            mNetServerArray[i]->ReadyExecute();
        }
    }
    for (size_t i = 0; i < mBusServerArray.size(); i++)
    {
        if (mBusServerArray[i] != nullptr)
        {
            mBusServerArray[i]->ReadyExecute();
        }
    }
    return true;
}

bool NFCNetMessageDriverModule::Execute()
{
	for (size_t i = 0; i < mNetServerArray.size(); i++)
	{
		if (mNetServerArray[i] != nullptr)
		{
			mNetServerArray[i]->Execute();
		}
	}
	for (size_t i = 0; i < mBusServerArray.size(); i++)
	{
		if (mBusServerArray[i] != nullptr)
		{
			mBusServerArray[i]->Execute();
		}
	}
	return true;
}

NFINetMessage* NFCNetMessageDriverModule::GetServerByServerType(NF_SERVER_TYPES eServerType)
{
	if (eServerType > NF_ST_NONE && eServerType < NF_ST_MAX)
	{
		return mNetServerArray[eServerType];
	}
	return nullptr;
}

int64_t NFCNetMessageDriverModule::ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType, bool bSecurity)
{
	NFChannelAddress addr;
	if (!NFServerIDUtil::MakeAddress(url, addr))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "usl:{} error", url);
		return -1;
	}

	if (eServerType > NF_ST_NONE && eServerType < NF_ST_MAX)
	{
		if (addr.mScheme == "tcp" || addr.mScheme == "udp" || addr.mScheme == "http")
		{
			NFMessageFlag flag;
			flag.mStrIp = addr.mHost;
			flag.nPort = addr.mPort;
			flag.mPacketParseType = nPacketParseType;
			flag.mSecurity = bSecurity;

			NFINetMessage* pServer = mNetServerArray[eServerType];
			if (!pServer)
			{
#ifdef USE_NET_EVPP
				pServer = NF_NEW NFEvppNetMessage(m_pObjPluginManager, eServerType);
#else

#endif

				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
			}


			uint64_t linkId = pServer->ConnectServer(flag);
			mNetServerArray[eServerType] = pServer;
			return (int64_t)linkId;
		}
		else if (addr.mScheme == "bus")
		{
			uint32_t busid = NFServerIDUtil::GetBusID(addr.mHost);
			if (busid <= 0)
			{
				NFLogError(NF_LOG_NET_PLUGIN, 0, "BusAddrAton Failed! host:{}", addr.mHost);
				return -1;
			}
			NFMessageFlag flag;
			flag.mStrIp = addr.mHost;
			flag.nPort = addr.mPort;
			flag.mBusId = busid;
			flag.mBusLength = addr.mPort;
			flag.mPacketParseType = nPacketParseType;
            flag.mSecurity = bSecurity;

			NFINetMessage* pServer = mBusServerArray[eServerType];
			if (!pServer)
			{
				pServer = NF_NEW NFCBusMessage(m_pObjPluginManager, eServerType);
				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
			}


			uint64_t linkId = pServer->ConnectServer(flag);
			mBusServerArray[eServerType] = pServer;
			return (int64_t)linkId;
		}

	}
	return -1;
}

int NFCNetMessageDriverModule::ResumeConnect(NF_SERVER_TYPES eServerType)
{
    NFINetMessage* pServer = mBusServerArray[eServerType];
    if (pServer)
    {
       return pServer->ResumeConnect();
    }
    return -1;
}

int64_t NFCNetMessageDriverModule::BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nNetThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType, bool bSecurity)
{
	NFChannelAddress addr;
	if (!NFServerIDUtil::MakeAddress(url, addr))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "usl:{} error", url);
		return -1;
	}

	if (eServerType > NF_ST_NONE && eServerType < NF_ST_MAX)
	{
		if (addr.mScheme == "tcp" || addr.mScheme == "udp" || addr.mScheme == "http")
		{
			NFMessageFlag flag;
			flag.mStrIp = addr.mHost;
			flag.nPort = addr.mPort;
			flag.mPacketParseType = nPacketParseType;
			flag.nWorkThreadNum = nNetThreadNum;
			flag.mMaxConnectNum = nMaxConnectNum;
			flag.mSecurity = bSecurity;
			if (addr.mScheme == "http")
            {
			    flag.bHttp = true;
            }

			NFINetMessage* pServer = mNetServerArray[eServerType];
			if (!pServer)
			{
				pServer = NF_NEW NFEvppNetMessage(m_pObjPluginManager, eServerType);
				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
				pServer->SetHttpRecvCB(mHttpReceiveCB);
				pServer->SetHttpFilterCB(mHttpFilter);
                mNetServerArray[eServerType] = pServer;
			}

			int64_t linkId = pServer->BindServer(flag);
			if (linkId >= 0)
			{
				return linkId;
			}

			NFLogError(NF_LOG_NET_PLUGIN, 0, "Add Server Failed!");
		}
		else if (addr.mScheme == "bus")
		{
			uint32_t busid = NFServerIDUtil::GetBusID(addr.mHost);
			if (busid <= 0)
			{
				NFLogError(NF_LOG_NET_PLUGIN, 0, "BusAddrAton Failed! host:{}", addr.mHost);
				return -1;
			}
			NFMessageFlag flag;
			flag.mStrIp = addr.mHost;
			flag.nPort = addr.mPort;
			flag.mBusId = busid;
			flag.mBusLength = addr.mPort;
			flag.mPacketParseType = nPacketParseType;
            flag.nWorkThreadNum = nNetThreadNum;
            flag.mMaxConnectNum = nMaxConnectNum;
            flag.mSecurity = bSecurity;

			NFINetMessage* pServer = mBusServerArray[eServerType];
			if (!pServer)
			{
				pServer = NF_NEW NFCBusMessage(m_pObjPluginManager, eServerType);

				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
                mBusServerArray[eServerType] = pServer;
			}

			int64_t linkId = pServer->BindServer(flag);
			if (linkId >= 0)
			{
				return linkId;
			}

			NFLogError(NF_LOG_NET_PLUGIN, 0, "Add Server Failed!");
		}
	}
	return -1;
}

std::string NFCNetMessageDriverModule::GetLinkIp(uint64_t usLinkId)
{
	uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);
	if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
	{
		uint32_t isServer = GetServerLinkModeFromUnlinkId(usLinkId);
		if (isServer != NF_IS_BUS)
		{
			auto pServer = mNetServerArray[serverType];
			if (pServer)
			{
				return pServer->GetLinkIp(usLinkId);
			}
			else
			{
				return std::string();
			}
		}
		else
		{
			auto pServer = mBusServerArray[serverType];
			if (pServer)
			{
				return pServer->GetLinkIp(usLinkId);
			}
			else
			{
				return std::string();
			}
		}
	}
	return std::string();
}

uint32_t NFCNetMessageDriverModule::GetPort(uint64_t usLinkId)
{
    uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
    {
        uint32_t isServer = GetServerLinkModeFromUnlinkId(usLinkId);
        if (isServer != NF_IS_BUS)
        {
            auto pServer = mNetServerArray[serverType];
            if (pServer)
            {
                return pServer->GetPort(usLinkId);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            auto pServer = mBusServerArray[serverType];
            if (pServer)
            {
                return pServer->GetPort(usLinkId);
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

void NFCNetMessageDriverModule::CloseLinkId(uint64_t usLinkId)
{
    if (usLinkId == 0) return;

	uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);

	if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
	{
		uint32_t isServer = GetServerLinkModeFromUnlinkId(usLinkId);
		if (isServer != NF_IS_BUS)
		{
			auto pServer = mNetServerArray[serverType];
			if (pServer)
			{
				pServer->CloseLinkId(usLinkId);
				return;
			}
			else
			{
				NFLogError(NF_LOG_NET_PLUGIN, 0, "CloseLinkId error, usLinkId:{} not exist!", usLinkId);
			}
		}
		else
		{
			auto pServer = mBusServerArray[serverType];
			if (pServer)
			{
				pServer->CloseLinkId(usLinkId);
				return;
			}
			else
			{
				NFLogError(NF_LOG_NET_PLUGIN, 0, "CloseLinkId error, usLinkId:{} not exist!", usLinkId);
			}
		}
	}
	NFLogError(NF_LOG_NET_PLUGIN, 0, "CloseLinkId error, usLinkId:{} not exist!", usLinkId);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string& strData, uint64_t nParam1, uint64_t nParam2, uint64_t srcId, uint64_t dstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.mStrMsg = strData;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = srcId;
    packet.nDstId = dstId;
    Send(usLinkId, packet);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nParam1, uint64_t nParam2, uint64_t srcId, uint64_t dstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.mStrMsg = std::string(msg, nLen);
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = srcId;
    packet.nDstId = dstId;
    Send(usLinkId, packet);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nParam1, uint64_t nParam2, uint64_t srcId, uint64_t dstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = srcId;
    packet.nDstId = dstId;
    if (!xData.SerializeToString(&packet.mStrMsg))
    {
        return;
    }

    Send(usLinkId, packet);
}

void NFCNetMessageDriverModule::SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string& strData, uint64_t nParam1, uint64_t nParam2, uint64_t nSrcID, uint64_t nDstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.mStrMsg = strData;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = nSrcID;
    packet.nDstId = nDstId;
    Send(usLinkId, packet);
}

void NFCNetMessageDriverModule::SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nParam1, uint64_t nParam2, uint64_t nSrcID, uint64_t nDstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.mStrMsg = std::string(msg, nLen);
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = nSrcID;
    packet.nDstId = nDstId;
    Send(usLinkId, packet);
}

void NFCNetMessageDriverModule::SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nParam1, uint64_t nParam2, uint64_t nSrcID, uint64_t nDstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = nSrcID;
    packet.nDstId = nDstId;
    if (!xData.SerializeToString(&packet.mStrMsg))
    {
        return;
    }

    Send(usLinkId, packet);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, NFDataPackage& packet)
{
    uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);

    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
    {
        uint32_t isServer = GetServerLinkModeFromUnlinkId(usLinkId);
        if (isServer != NF_IS_BUS)
        {
            auto pServer = mNetServerArray[serverType];
            if (pServer)
            {
                SendMsg(pServer, usLinkId, packet);
                return;
            }
            else
            {
                NFLogError(NF_LOG_NET_PLUGIN, 0, "SendByServerID error, usLinkId:{} not exist!", usLinkId);
            }
        }
        else
        {
            auto pServer = mBusServerArray[serverType];
            if (pServer)
            {
                SendMsg(pServer, usLinkId, packet);
                return;
            }
            else
            {
                NFLogError(NF_LOG_NET_PLUGIN, 0, "bus SendByServerID error, usLinkId:{} not exist!", usLinkId);
            }
        }

    }
    if (usLinkId != 0)
    {
        NFLogError(NF_LOG_NET_PLUGIN, 0, "SendByServerID error, usLinkId:{} not exist!", usLinkId);
    }
}

void NFCNetMessageDriverModule::SendMsg(NFINetMessage* pServer, uint64_t usLinkId, NFDataPackage& packet)
{
    if (pServer)
    {
        pServer->Send(usLinkId, packet);
    }
}

bool
NFCNetMessageDriverModule::ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const string &strMsg,
                                           NFWebStatus code, const string &reason) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX) {
        NFINetMessage *pServer = mNetServerArray[serverType];
        if (pServer)
        {
            return pServer->ResponseHttpMsg(req, strMsg, code, reason);
        }
    }
    return false;
}

bool NFCNetMessageDriverModule::ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const string &strMsg,
                                                NFWebStatus code, const string &reason) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX) {
        NFINetMessage *pServer = mNetServerArray[serverType];
        if (pServer)
        {
            return pServer->ResponseHttpMsg(requestId, strMsg, code, reason);
        }
    }
    return false;
}

int NFCNetMessageDriverModule::HttpGet(NF_SERVER_TYPES serverType, const string &strUri, const HTTP_CLIENT_RESPONE &respone,
                                       const map<std::string, std::string> &xHeaders, int timeout) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX) {
        NFINetMessage *pServer = mNetServerArray[serverType];
        if (pServer)
        {
            return pServer->HttpGet(strUri, respone, xHeaders, timeout);
        }
    }
    return -1;
}

int
NFCNetMessageDriverModule::HttpPost(NF_SERVER_TYPES serverType, const string &strUri, const string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                                    const map<std::string, std::string> &xHeaders, int timeout) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX) {
        NFINetMessage *pServer = mNetServerArray[serverType];
        if (pServer)
        {
            return pServer->HttpPost(strUri, strPostData, respone, xHeaders, timeout);
        }
    }
    return -1;
}

int NFCNetMessageDriverModule::SendEmail(NF_SERVER_TYPES serverType, const std::string& title, const std::string& subject, const string &content)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
    CHECK_NULL(pConfig);

    CSmtpSendMail sendMail;
    sendMail.SetSmtpServer(pConfig->sendEmail, pConfig->sendEmailPass,pConfig->sendEmailUrl, pConfig->sendEmailPort);
    sendMail.SetSendName(title);
    sendMail.SetSendMail(pConfig->sendEmail);
    sendMail.AddRecvMail(pConfig->recvEmail);
    sendMail.SetSubject(subject);
    std::string dumpInfo = content;
    NFStringUtility::Replace(dumpInfo, "\n", "<br/>");
    sendMail.SetBodyContent(dumpInfo);
    if (!sendMail.SendMail())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Send Message(title:{} subject:{}) To Email:{} Failed", title, subject, pConfig->recvEmail);
        return -1;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Send Message(title:{} subject:{}) To Email:{} Success", title, subject, pConfig->recvEmail);
        return 0;
    }
}