// -------------------------------------------------------------------------
//    @FileName         :    NFCNetServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCNetServerModule
// -------------------------------------------------------------------------

#include "NFCNetMessageDriverModule.h"

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFIPacketParse.h"
#include "NFEvppNetMessage.h"
#include "NFCBusMessage.h"
#include "NFComm/NFCore/NFSocketLibFunction.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

NFCNetMessageDriverModule::NFCNetMessageDriverModule(NFIPluginManager* p):NFIMessageDriver(p)
{
	NFSocketLibFunction::InitSocket();
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

int64_t NFCNetMessageDriverModule::ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType)
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

			NFINetMessage* pServer = mNetServerArray[eServerType];
			if (!pServer)
			{
#ifdef USE_NET_EVPP
				pServer = NF_NEW NFEvppNetMessage(m_pPluginManager, eServerType);
#else

#endif

				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
			}


			uint64_t linkId = pServer->ConnectServer(flag);
			if (linkId >= 0)
			{
				mNetServerArray[eServerType] = pServer;
				return (int64_t)linkId;
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

			NFINetMessage* pServer = mBusServerArray[eServerType];
			if (!pServer)
			{
				pServer = NF_NEW NFCBusMessage(m_pPluginManager, eServerType);
				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
			}


			uint64_t linkId = pServer->ConnectServer(flag);
			if (linkId >= 0)
			{
				mBusServerArray[eServerType] = pServer;
				return (int64_t)linkId;
			}

			NFLogError(NF_LOG_NET_PLUGIN, 0, "Add Server Failed!");
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

int64_t NFCNetMessageDriverModule::BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nNetThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType)
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
			if (addr.mScheme == "http")
            {
			    flag.bHttp = true;
            }

			NFINetMessage* pServer = mNetServerArray[eServerType];
			if (!pServer)
			{
				pServer = NF_NEW NFEvppNetMessage(m_pPluginManager, eServerType);
				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
				pServer->SetHttpRecvCB(mHttpReceiveCB);
				pServer->SetHttpFilterCB(mHttpFilter);
			}

			int64_t linkId = pServer->BindServer(flag);
			if (linkId >= 0)
			{
				mNetServerArray[eServerType] = pServer;
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

			NFINetMessage* pServer = mBusServerArray[eServerType];
			if (!pServer)
			{
				pServer = NF_NEW NFCBusMessage(m_pPluginManager, eServerType);

				pServer->SetRecvCB(mRecvCB);
				pServer->SetEventCB(mEventCB);
			}

			int64_t linkId = pServer->BindServer(flag);
			if (linkId >= 0)
			{
				mBusServerArray[eServerType] = pServer;
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

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId)
{
    Send(usLinkId, nMsgID, strData.c_str(), strData.length(), nSendValue, nSendId);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
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
                SendMsg(pServer, usLinkId, nMsgID, msg, nLen, nSendValue, nSendId);
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
                SendMsg(pServer, usLinkId, nMsgID, msg, nLen, nSendValue, nSendId);
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

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId)
{
    std::string strData;
    if (!xData.SerializeToString(&strData))
    {
        return;
    }

    Send(usLinkId, nMsgID, strData, nSendValue, nSendId);
}

void NFCNetMessageDriverModule::SendMsg(NFINetMessage* pServer, uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    if (pServer)
    {
        pServer->Send(usLinkId, nMsgID, msg, nLen, nSendValue, nSendId);
    }
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId)
{
    uint32_t msgId = MAKE_UINT32(nSubMsgID, nMainMsgID);
    Send(usLinkId, msgId, strData, nSendValue, nSendId);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    uint32_t msgId = MAKE_UINT32(nSubMsgID, nMainMsgID);
    Send(usLinkId, msgId, msg, nLen, nSendValue, nSendId);
}

void NFCNetMessageDriverModule::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId)
{
    uint32_t msgId = MAKE_UINT32(nSubMsgID, nMainMsgID);
    Send(usLinkId, msgId, xData, nSendValue, nSendId);
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
