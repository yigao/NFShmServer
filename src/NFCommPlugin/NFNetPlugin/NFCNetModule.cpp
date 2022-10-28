// -------------------------------------------------------------------------
//    @FileName         :    NFCNetServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Module           :    NFCNetServerModule
// -------------------------------------------------------------------------

#include <NFComm/NFPluginModule/NFIConfigModule.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFPluginModule/NFITaskModule.h>
#include "NFCNetModule.h"

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

NFCNetModule::NFCNetModule(NFIPluginManager* p): NFINetModule(p)
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

NFCNetModule::~NFCNetModule()
{
#if defined(EVPP_HTTP_CLIENT_SUPPORTS_SSL)
    if (evpp::httpc::GetSSLCtx())
    {
        evpp::httpc::CleanSSL();
    }
#endif
}

bool NFCNetModule::Awake()
{
	return true;
}

bool NFCNetModule::BeforeShut()
{
	return true;
}

bool NFCNetModule::Shut()
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

bool NFCNetModule::Finalize()
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

    /**
     * @brief 释放资源
     */
    NFIPacketParse::ReleasePacketParse();
	return true;
}

bool NFCNetModule::ReadyExecute()
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

bool NFCNetModule::Execute()
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

NFINetMessage* NFCNetModule::GetServerByServerType(NF_SERVER_TYPES eServerType)
{
	if (eServerType > NF_ST_NONE && eServerType < NF_ST_MAX)
	{
		return mNetServerArray[eServerType];
	}
	return nullptr;
}

uint64_t NFCNetModule::ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType, bool bSecurity)
{
	NFChannelAddress addr;
	if (!NFServerIDUtil::MakeAddress(url, addr))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "usl:{} error", url);
		return 0;
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
                mNetServerArray[eServerType] = pServer;
			}


			uint64_t linkId = pServer->ConnectServer(flag);
			return linkId;
		}
		else if (addr.mScheme == "bus")
		{
			uint32_t busid = NFServerIDUtil::GetBusID(addr.mHost);
			if (busid <= 0)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "BusAddrAton Failed! host:{}", addr.mHost);
				return 0;
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
                mBusServerArray[eServerType] = pServer;
			}

			uint64_t linkId = pServer->ConnectServer(flag);
			return linkId;
		}

	}
	return 0;
}

int NFCNetModule::ResumeConnect(NF_SERVER_TYPES eServerType)
{
    NFINetMessage* pServer = mBusServerArray[eServerType];
    if (pServer)
    {
       return pServer->ResumeConnect();
    }
    return -1;
}

uint64_t NFCNetModule::BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nNetThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType, bool bSecurity)
{
	NFChannelAddress addr;
	if (!NFServerIDUtil::MakeAddress(url, addr))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "usl:{} error", url);
		return 0;
	}

	if (eServerType > NF_ST_NONE && eServerType < NF_ST_MAX)
	{
		if (addr.mScheme == "tcp" || addr.mScheme == "udp" || addr.mScheme == "http")
		{
			NFMessageFlag flag;
			flag.mStrIp = addr.mHost;
			flag.nPort = addr.mPort;
			flag.mPacketParseType = nPacketParseType;
			flag.nNetThreadNum = nNetThreadNum;
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

            uint64_t linkId = pServer->BindServer(flag);
			if (linkId > 0)
			{
				return linkId;
			}

			NFLogError(NF_LOG_SYSTEMLOG, 0, "Add Server Failed!");
		}
		else if (addr.mScheme == "bus")
		{
			uint32_t busid = NFServerIDUtil::GetBusID(addr.mHost);
			if (busid <= 0)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "BusAddrAton Failed! host:{}", addr.mHost);
				return 0;
			}
			NFMessageFlag flag;
			flag.mStrIp = addr.mHost;
			flag.nPort = addr.mPort;
			flag.mBusId = busid;
			flag.mBusLength = addr.mPort;
			flag.mPacketParseType = nPacketParseType;
            flag.nNetThreadNum = nNetThreadNum;
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

            uint64_t linkId = pServer->BindServer(flag);
			if (linkId > 0)
			{
				return linkId;
			}

			NFLogError(NF_LOG_SYSTEMLOG, 0, "Add Server Failed!");
		}
	}
	return 0;
}

std::string NFCNetModule::GetLinkIp(uint64_t usLinkId)
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

uint32_t NFCNetModule::GetPort(uint64_t usLinkId)
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

void NFCNetModule::CloseLinkId(uint64_t usLinkId)
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
				NFLogError(NF_LOG_SYSTEMLOG, 0, "CloseLinkId error, usLinkId:{} not exist!", usLinkId);
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
				NFLogError(NF_LOG_SYSTEMLOG, 0, "CloseLinkId error, usLinkId:{} not exist!", usLinkId);
			}
		}
	}
	NFLogError(NF_LOG_SYSTEMLOG, 0, "CloseLinkId error, usLinkId:{} not exist!", usLinkId);
}

void NFCNetModule::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string& strData, uint64_t nParam1, uint64_t nParam2, uint64_t srcId, uint64_t dstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = srcId;
    packet.nDstId = dstId;

    Send(usLinkId, packet, strData.data(), strData.length());
}

void NFCNetModule::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nParam1, uint64_t nParam2, uint64_t srcId, uint64_t dstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = srcId;
    packet.nDstId = dstId;

    Send(usLinkId, packet, msg, nLen);
}

void NFCNetModule::Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nParam1, uint64_t nParam2, uint64_t srcId, uint64_t dstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = srcId;
    packet.nDstId = dstId;

    Send(usLinkId, packet, xData);
}

void NFCNetModule::SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string& strData, uint64_t nParam1, uint64_t nParam2, uint64_t nSrcID, uint64_t nDstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = nSrcID;
    packet.nDstId = nDstId;

   Send(usLinkId, packet, strData.data(), strData.length());
}

void NFCNetModule::SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nParam1, uint64_t nParam2, uint64_t nSrcID, uint64_t nDstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = nSrcID;
    packet.nDstId = nDstId;

    Send(usLinkId, packet, msg, nLen);
}

void NFCNetModule::SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nParam1, uint64_t nParam2, uint64_t nSrcID, uint64_t nDstId)
{
    NFDataPackage packet;
    packet.mModuleId = nModuleId;
    packet.nMsgId = nMsgID;
    packet.nParam1 = nParam1;
    packet.nParam2 = nParam2;
    packet.nSrcId = nSrcID;
    packet.nDstId = nDstId;

    Send(usLinkId, packet, xData);
}

void NFCNetModule::TransPackage(uint64_t usLinkId, NFDataPackage& packet)
{
   Send(usLinkId, packet, packet.GetBuffer(), packet.GetSize());
}

bool NFCNetModule::Send(uint64_t usLinkId, NFDataPackage& packet, const char* msg, uint32_t nLen)
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
                return Send(pServer, usLinkId, packet, msg, nLen);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "SendByServerID error, usLinkId:{} not exist!", usLinkId);
            }
        }
        else
        {
            auto pServer = mBusServerArray[serverType];
            if (pServer)
            {
                return Send(pServer, usLinkId, packet, msg, nLen);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "bus SendByServerID error, usLinkId:{} not exist!", usLinkId);
            }
        }
    }

    if (usLinkId != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SendByServerID error, usLinkId:{} not exist!", usLinkId);
    }

    return false;
}

bool NFCNetModule::Send(uint64_t usLinkId, NFDataPackage& packet, const google::protobuf::Message& xData)
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
                return Send(pServer, usLinkId, packet, xData);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "SendByServerID error, usLinkId:{} not exist!", usLinkId);
            }
        }
        else
        {
            auto pServer = mBusServerArray[serverType];
            if (pServer)
            {
                return Send(pServer, usLinkId, packet, xData);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "bus SendByServerID error, usLinkId:{} not exist!", usLinkId);
            }
        }
    }

    if (usLinkId != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SendByServerID error, usLinkId:{} not exist!", usLinkId);
    }

    return false;
}

bool NFCNetModule::Send(NFINetMessage* pServer, uint64_t usLinkId, NFDataPackage& packet, const char* msg, uint32_t nLen)
{
    if (pServer)
    {
        return pServer->Send(usLinkId, packet, msg, nLen);
    }
    return false;
}

bool NFCNetModule::Send(NFINetMessage* pServer, uint64_t usLinkId, NFDataPackage& packet, const google::protobuf::Message& xData)
{
    if (pServer)
    {
        return pServer->Send(usLinkId, packet, xData);
    }
    return false;
}

bool
NFCNetModule::ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const string &strMsg,
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

bool NFCNetModule::ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const string &strMsg,
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

int NFCNetModule::HttpGet(NF_SERVER_TYPES serverType, const string &strUri, const HTTP_CLIENT_RESPONE &respone,
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
NFCNetModule::HttpPost(NF_SERVER_TYPES serverType, const string &strUri, const string &strPostData, const HTTP_CLIENT_RESPONE &respone,
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

int NFCNetModule::SendEmail(NF_SERVER_TYPES serverType, const std::string& title, const std::string& subject, const string &content)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
    CHECK_NULL(pConfig);

    NFSmtpSendMail sendMail;
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