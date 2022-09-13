// -------------------------------------------------------------------------
//    @FileName         :    NFEvppServer.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
// -------------------------------------------------------------------------

#include "NFEvppNetMessage.h"

#include <stddef.h>
#include <sys/types.h>
#include <cstdint>
#include <list>
#include <string>
#include <vector>

#include "../../NFComm/NFPluginModule/NFILogModule.h"
#include "../../NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFEvppClient.h"
#include "NFEvppServer.h"
#include "NFIPacketParse.h"
#include "NFComm/NFCore/NFStringUtility.h"

NFEvppNetMessage::NFEvppNetMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType) : NFINetMessage(p, serverType)
{
	mxSendBuffer.AssureSpace(MAX_SEND_BUFFER_SIZE);
	SetTimer(ENUM_EVPP_CLIENT_TIMER_HEART, ENUM_EVPP_CLIENT_TIMER_HEART_TIME_LONGTH);
	SetTimer(ENUM_EVPP_SERVER_TIMER_CHECK_HEART, ENUM_EVPP_SERVER_TIMER_CHECK_HEART_TIME_LONGTH);
    m_httpServer = NULL;
    m_httpClient = NULL;
}

NFEvppNetMessage::~NFEvppNetMessage()
{
	for (auto iter = mNetObjectArray.begin(); iter != mNetObjectArray.end(); ++iter)
	{
		auto pObject = iter->second;
		if (pObject)
		{
			NF_SAFE_DELETE(pObject);
		}
	}
	mNetObjectArray.clear();
}

void NFEvppNetMessage::ProcessMsgLogicThread()
{
    int max_times = 10000;
    while(!mMsgQueue.IsQueueEmpty() && max_times >= 0)
    {
        std::vector<MsgFromNetInfo> vecMsg;
        vecMsg.resize(200);

        mMsgQueue.TryDequeueBulk(vecMsg);

        for (size_t index = 0; index < vecMsg.size(); index++)
        {
            max_times--;
            MsgFromNetInfo* pMsg = &vecMsg[index];

            if (pMsg->nType == eMsgType_CONNECTED)
            {
                if (pMsg->mTCPConPtr && pMsg->mTCPConPtr->IsConnected())
                {
                    for (size_t i = 0; i < m_connectionList.size(); i++)
                    {
                        if (m_connectionList[i]->GetLinkId() == pMsg->nLinkId)
                        {
                            if (m_connectionList[i]->GetConnectionType() == NF_CONNECTION_TYPE_TCP_CLIENT)
                            {
                                NetEvppObject* pObject = GetNetObject(m_connectionList[i]->GetLinkId());
                                if (pObject == NULL)
                                {
                                    pObject = AddNetObject(m_connectionList[i]->GetLinkId(), pMsg->mTCPConPtr, m_connectionList[i]->GetPacketParseType());
                                }

                                if (pObject)
                                {
                                    pObject->SetConnPtr(pMsg->mTCPConPtr);
                                    pObject->SetIsServer(false);
                                    pMsg->mTCPConPtr->set_context(evpp::Any(pObject));
                                    OnHandleMsgPeer(eMsgType_CONNECTED, m_connectionList[i]->GetLinkId(), pObject->m_usLinkId, nullptr, 0, 0, 0, 0);
                                }
                                else
                                {
                                    //这里应该断开链接
                                    pMsg->mTCPConPtr->Close();
                                }
                            }
                            else
                            {
                                NetEvppObject* pObject = AddNetObject(pMsg->mTCPConPtr, m_connectionList[i]->GetPacketParseType());
                                if (pObject)
                                {
                                    pMsg->mTCPConPtr->set_context(evpp::Any(pObject));
                                    OnHandleMsgPeer(eMsgType_CONNECTED, m_connectionList[i]->GetLinkId(), pObject->m_usLinkId, nullptr, 0, 0, 0, 0);
                                }
                                else
                                {
                                    //这里应该断开链接
                                    pMsg->mTCPConPtr->Close();
                                }
                            }
                            break;
                        }
                    }
                }
            }
            else if (pMsg->nType == eMsgType_DISCONNECTED)
            {
                if (pMsg->mTCPConPtr)
                {
                    if (!pMsg->mTCPConPtr->context().IsEmpty())
                    {
                        NetEvppObject* pObject = evpp::any_cast<NetEvppObject*>(pMsg->mTCPConPtr->context());
                        if (pObject)
                        {
                            if (pObject->GetNeedRemove() == false)
                            {
                                if (pObject->mIsServer)
                                {
                                    pObject->SetNeedRemove(true);
                                }
                                else
                                {
                                    pObject->SetNeedRemove(false);
                                }
                            }

                            pObject->mConnPtr = NULL;
                            OnHandleMsgPeer(eMsgType_DISCONNECTED, pMsg->nLinkId, pObject->m_usLinkId, nullptr, 0, 0, 0, 0);
                        }

                        pMsg->mTCPConPtr->set_context(evpp::Any());
                    }
                    else
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "net server diconnect, tcp context error");
                        for (size_t i = 0; i < m_connectionList.size(); i++) {
                            if (m_connectionList[i]->GetLinkId() == pMsg->nLinkId) {
                                if (m_connectionList[i]->GetConnectionType() == NF_CONNECTION_TYPE_TCP_CLIENT) {
                                    OnHandleMsgPeer(eMsgType_DISCONNECTED, pMsg->nLinkId, pMsg->nLinkId, nullptr, 0, 0, 0, 0);
                                }
                                else
                                {
                                    OnHandleMsgPeer(eMsgType_DISCONNECTED, pMsg->nLinkId, 0, nullptr, 0, 0, 0, 0);
                                }
                            }
                        }

                    }
                }
            }
            else if (pMsg->nType == eMsgType_RECIVEDATA)
            {
                if (pMsg->mTCPConPtr)
                {
                    if (!pMsg->mTCPConPtr->context().IsEmpty())
                    {
                        NetEvppObject* pObject = evpp::any_cast<NetEvppObject*>(pMsg->mTCPConPtr->context());
                        if (pObject)
                        {
                            OnHandleMsgPeer(eMsgType_RECIVEDATA, pMsg->nLinkId, pObject->m_usLinkId, (char*)pMsg->strMsg.data(), pMsg->strMsg.length(), pMsg->nMsgId, pMsg->nSendValue, pMsg->nSendId);
                        }
                        else
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "net server recv data, tcp context error");
                        }
                    }
                    else
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "net server recv data, tcp context error");
                    }
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "net server  error");
            }
        }
    }
}

/**
* @brief 连接回调
*
* @return
*/
void NFEvppNetMessage::ConnectionCallback(const evpp::TCPConnPtr& conn, uint64_t linkId)
{
	if (conn->IsConnected())
	{
		conn->SetTCPNoDelay(true);
		MsgFromNetInfo msg(conn, linkId);
		msg.nType = eMsgType_CONNECTED;
		while(!mMsgQueue.Enqueue(msg)) {}
	}
	else
	{
        MsgFromNetInfo msg(conn, linkId);
		msg.nType = eMsgType_DISCONNECTED;
        while(!mMsgQueue.Enqueue(msg)) {}
	}
}

/**
* @brief 消息回调
*
* @return 消息回调
*/
void NFEvppNetMessage::MessageCallback(const evpp::TCPConnPtr& conn, evpp::Buffer* msg, uint64_t linkId, uint32_t packetparse)
{
	if (msg)
	{
		while (true)
		{
			char* outData = nullptr;
			uint32_t outLen = 0;
			uint32_t allLen = 0;
			uint32_t nMsgId = 0;
			uint64_t nSendValue = 0;
            uint64_t nSendId = 0;
			int ret = NFIPacketParse::DeCode(packetparse, msg->data(), msg->size(), outData, outLen, allLen, nMsgId, nSendValue, nSendId);
			if (ret < 0)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "net server parse data failed!");
				msg->Reset();
				break;
			}
			else if (ret > 0)
			{
				break;
			}
			else
			{
                if (nMsgId != 1009 && nMsgId != 1010 && nMsgId != 1 && nMsgId != 2)
                {
                    NFLogTrace(NF_LOG_RECV_MSG,0,"recv msg:{} value:{} value2:{}", nMsgId, nSendValue, nSendId);
                }
				MsgFromNetInfo msgInfo(conn, linkId);
                msgInfo.nType = eMsgType_RECIVEDATA;
                msgInfo.strMsg = std::string(outData, outLen);
                msgInfo.nMsgId = nMsgId;
                msgInfo.nSendValue = nSendValue;
                msgInfo.nSendId = nSendId;
                while(!mMsgQueue.Enqueue(msgInfo)) {}

				msg->Skip(allLen);
				continue;
			}
		}
	}
}

int64_t NFEvppNetMessage::BindServer(const NFMessageFlag& flag)
{
    if (flag.bHttp)
    {
        int iRet = BindHttpServer(flag.nPort, flag.nWorkThreadNum);
        if (iRet)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "BindHttpServer Failed! port:{}", flag.nPort);
        }
        return iRet;
    }
    else
    {
        NFEvppServer* pServer = NF_NEW NFEvppServer(m_pPluginManager, mServerType, flag);

        uint64_t unLinkId = GetFreeUnLinkId();
        pServer->SetLinkId(unLinkId);
        pServer->SetConnCallback(
                std::bind(&NFEvppNetMessage::ConnectionCallback, this, std::placeholders::_1, unLinkId));
        pServer->SetMessageCallback(
                std::bind(&NFEvppNetMessage::MessageCallback, this, std::placeholders::_1, std::placeholders::_2,
                          unLinkId, flag.mPacketParseType));
        if (pServer->Init()) {
            m_connectionList.push_back(pServer);
            return unLinkId;
        }
    }

    return -1;
}

int64_t NFEvppNetMessage::BindHttpServer(uint32_t listen_port, uint32_t netThreadNum) {
    NFCHttpServer *pServer = NF_NEW NFCHttpServer(mServerType, netThreadNum);
    if (pServer) {
        pServer->SetRecvCB(mHttpReceiveCB);
        pServer->SetFilterCB(mHttpFilter);
        if (pServer->InitServer(listen_port)) {
            m_httpServer = pServer;
            return 0;
        }
    }
    return -1;
}

/**
* @brief	初始化
*
* @return 是否成功
*/
int64_t NFEvppNetMessage::ConnectServer(const NFMessageFlag &flag) {
    NFEvppClient *pClient = NF_NEW NFEvppClient(m_pPluginManager, mServerType, flag);

	if (pClient)
	{
		uint64_t unLinkId = GetFreeUnLinkId();
		pClient->SetLinkId(unLinkId);
		pClient->SetConnCallback(std::bind(&NFEvppNetMessage::ConnectionCallback, this, std::placeholders::_1, unLinkId));
		pClient->SetMessageCallback(std::bind(&NFEvppNetMessage::MessageCallback, this, std::placeholders::_1, std::placeholders::_2, unLinkId, flag.mPacketParseType));
		if (pClient->Init())
		{
			m_connectionList.push_back(pClient);

			return (int64_t)unLinkId;
		}
	}
	return -1;
}

std::string NFEvppNetMessage::GetLinkIp(uint64_t usLinkId)
{
	NetEvppObject* pObject = GetNetObject(usLinkId);
	if (pObject)
	{
		return pObject->GetStrIp();
	}

	return std::string("");
}

NetEvppObject* NFEvppNetMessage::AddNetObject(const evpp::TCPConnPtr conn, uint32_t parseType)
{
	uint64_t usLinkId = GetFreeUnLinkId();
	if (usLinkId == 0)
	{
		NFLogError(NF_LOG_NET_PLUGIN, 0, "connected count:{}  Can't add connect", mNetObjectArray.size());
		return nullptr;
	}

	return AddNetObject(usLinkId, conn, parseType);
}

NetEvppObject* NFEvppNetMessage::AddNetObject(uint64_t unLinkId, const evpp::TCPConnPtr conn, uint32_t parseType)
{
	if (mNetObjectArray.find(unLinkId) != mNetObjectArray.end())
	{
		NFLogError(NF_LOG_NET_PLUGIN, 0, "GetServerIndexFromUnLinkId Failed!");
		return nullptr;
	}

	auto pObject = NF_NEW NetEvppObject(conn);
	mNetObjectArray.emplace(unLinkId, pObject);

	pObject->SetLinkId(unLinkId);

	if (conn)
	{
		std::string remote_addr = conn->remote_addr();
		std::vector<std::string> vec;
        NFStringUtility::Split(remote_addr, ":", &vec);
        if (vec.size() > 0)
        {
            pObject->SetStrIp(vec[0]);
        }
	}

	pObject->SetPacketParseType(parseType);

	return pObject;
}

NetEvppObject* NFEvppNetMessage::GetNetObject(uint64_t usLinkId)
{
	uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);
	if (serverType != mServerType)
	{
		NFLogError(NF_LOG_NET_PLUGIN, 0, "serverType != mServerType, this usLinkId:%s is not of the server:%s", usLinkId, GetServerName(mServerType).c_str());
		return nullptr;
	}

	auto iter = mNetObjectArray.find(usLinkId);

	if (iter != mNetObjectArray.end())
	{
		auto pObject = iter->second;
		if (pObject)
		{
			return pObject;
		}
		else
		{
			NFLogError(NF_LOG_NET_PLUGIN, 0, "the usLinkId:{} is nullptr", usLinkId);
		}
	}
	return nullptr;
}

void NFEvppNetMessage::CloseLinkId(uint64_t usLinkId)
{
	for (auto iter = m_connectionList.begin(); iter != m_connectionList.end(); iter++)
	{
		NFIConnection* pConnection = *iter;
		if (pConnection->GetLinkId() == usLinkId)
		{
			pConnection->Shut();
			pConnection->Finalize();
			NF_SAFE_DELETE(pConnection);
			m_connectionList.erase(iter);
			break;
		}
	}
	
	auto iter = mNetObjectArray.find(usLinkId);
	if (iter != mNetObjectArray.end())
	{
	    iter->second->SetNeedRemove(true);
        iter->second->CloseObject();
	}
}

uint64_t NFEvppNetMessage::GetFreeUnLinkId()
{
	uint64_t unlinkId = 0;
	if (mFreeLinks.size() > 1000)
	{
		unlinkId = mFreeLinks.front();
		mFreeLinks.pop_front();
		return unlinkId;
	}

	int count = 10000;
	while(--count >= 0)
    {
        if (mNetObjectMaxIndex < 0 || mNetObjectMaxIndex >= MAX_CLIENT_INDEX-10)
        {
            mNetObjectMaxIndex = 0;
        }

        mNetObjectMaxIndex++;
        unlinkId = GetUnLinkId(NF_IS_NET, mServerType, mNetObjectMaxIndex);


        if (mNetObjectArray.find(unlinkId) == mNetObjectArray.end())
        {
            return unlinkId;
        }
    }
    NFLogError(NF_LOG_NET_PLUGIN, 0, "GetFreeUnLinkId failed!");
    return 0;
}

bool NFEvppNetMessage::Shut()
{
	for (size_t i = 0; i < m_connectionList.size(); i++)
	{
		NFIConnection* pConn = m_connectionList[i];
		if (pConn)
		{
			pConn->Shut();
		}
	}


	return true;
}

bool NFEvppNetMessage::Finalize()
{
	for (size_t i = 0; i < m_connectionList.size(); i++)
	{
		NFIConnection* pConn = m_connectionList[i];
		if (pConn)
		{
			pConn->Finalize();
		}
	}

    for (size_t i = 0; i < m_connectionList.size(); i++)
    {
        NFIConnection* pConn = m_connectionList[i];
        if (pConn)
        {
            NF_SAFE_DELETE(pConn);
        }
    }
	return true;
}

bool NFEvppNetMessage::Execute()
{
	ProcessMsgLogicThread();
	if (m_httpServer)
    {
	    m_httpServer->Execute();
    }
    if (m_httpClient)
    {
        m_httpClient->Execute();
    }
	return true;
}

bool NFEvppNetMessage::Send(uint64_t usLinkId, const char* pData, uint32_t unSize)
{
	NetEvppObject* pObject = GetNetObject(usLinkId);
	if (pObject)
	{
		return Send(pObject, pData, unSize);
	}
	return false;
}

bool NFEvppNetMessage::Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    NetEvppObject* pObject = GetNetObject(usLinkId);
    if (pObject)
    {
        return Send(pObject, nMsgID, msg, nLen, nSendValue, nSendId);
    }
    return false;
}

void NFEvppNetMessage::OnHandleMsgPeer(eMsgType type, uint64_t connectionLink, uint64_t objectLinkId, char* pBuf, uint32_t sz, uint32_t nMsgId, uint64_t nSendValue, uint64_t nSendId)
{
	switch (type)
	{
	case eMsgType_RECIVEDATA:
	{
		if (nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT)
		{
			NetEvppObject* pObject = GetNetObject(objectLinkId);
			if (pObject && pObject->mIsServer)
			{
				pObject->SetLastHeartBeatTime(NFGetTime());
                Send(pObject->GetLinkId(), NF_SERVER_TO_SERVER_HEART_BEAT_RSP, NULL, 0);
				return;
			}
		}

		if (nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT_RSP)
        {
            NetEvppObject* pObject = GetNetObject(objectLinkId);
            if (pObject && pObject->mIsServer == false)
            {
                pObject->SetLastHeartBeatTime(NFGetTime());
                return;
            }
        }

		if (mRecvCB)
		{
			mRecvCB(connectionLink, objectLinkId, nSendValue, nSendId, nMsgId, pBuf, sz);
		}
	}
	break;
	case eMsgType_CONNECTED:
	{
		if (mEventCB)
		{
			mEventCB(type, connectionLink, objectLinkId);
		}
	}
	break;
	case eMsgType_DISCONNECTED:
	{
		if (mEventCB)
		{
			mEventCB(type, connectionLink, objectLinkId);
		}

		if (objectLinkId > 0)
        {
            uint32_t serverType = GetServerTypeFromUnlinkId(objectLinkId);
            NF_ASSERT_MSG(serverType == mServerType, "the unlinkId is not of the server");
            auto pObject = GetNetObject(objectLinkId);
            if (pObject && pObject->GetNeedRemove())
            {
                auto iter = mNetObjectArray.find(objectLinkId);
                if (iter != mNetObjectArray.end())
                {
                    mNetObjectArray.erase(iter);
                    NF_SAFE_DELETE(pObject);

                    mFreeLinks.push_back(objectLinkId);
                }
            }
        }
	}
	break;
	default:
		break;
	}
}

bool NFEvppNetMessage::Send(NetEvppObject* pObject, const char* pData, uint32_t unSize)
{
	if (pObject && !pObject->GetNeedRemove() && pObject->mConnPtr && pObject->mConnPtr->IsConnected())
	{
		pObject->mConnPtr->Send((const void*)pData, unSize);
		return true;
	}
	return false;
}

bool NFEvppNetMessage::Send(NetEvppObject* pObject, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    if (pObject && !pObject->GetNeedRemove() && pObject->mConnPtr && pObject->mConnPtr->IsConnected())
    {
        mxSendBuffer.Clear();
        NFIPacketParse::EnCode(pObject->mPacketParseType, nMsgID, nSendValue, nSendId, msg, nLen, mxSendBuffer);
        pObject->mConnPtr->Send((const void*)mxSendBuffer.ReadAddr(), mxSendBuffer.ReadableSize());
        return true;
    }
    return false;
}

void NFEvppNetMessage::OnTimer(uint32_t nTimerID)
{
	if (nTimerID == ENUM_EVPP_CLIENT_TIMER_HEART)
	{
		SendHeartMsg();
	}
	else if (nTimerID == ENUM_EVPP_SERVER_TIMER_CHECK_HEART)
	{
		CheckServerHeartBeat();
	}
}

void  NFEvppNetMessage::SendHeartMsg()
{
	for (size_t i = 0; i < m_connectionList.size(); i++)
	{
		if (m_connectionList[i] && m_connectionList[i]->GetConnectionType() == NF_CONNECTION_TYPE_TCP_CLIENT)
		{
			Send(m_connectionList[i]->GetLinkId(), NF_SERVER_TO_SERVER_HEART_BEAT, NULL, 0, 0);
		}
	}
}

void NFEvppNetMessage::CheckServerHeartBeat()
{
	uint64_t nowTime = NFGetTime();
	for (auto iter = mNetObjectArray.begin(); iter != mNetObjectArray.end(); iter++)
	{
		NetEvppObject* pObject = iter->second;
		if (pObject && pObject->mIsServer && pObject->mPacketParseType == PACKET_PARSE_TYPE_INTERNAL)//服务器与服务器之间有这个需求，协议必须是内网协议
		{
		    //debug 30min
#ifdef NF_DEBUG_MODE
			if (nowTime - pObject->mLastHeartBeatTime > ENUM_EVPP_CLIENT_TIMER_HEART_TIME_LONGTH * 30 * 60)
			{
				pObject->CloseObject();
			}
#else
            if (nowTime - pObject->mLastHeartBeatTime > ENUM_EVPP_CLIENT_TIMER_HEART_TIME_LONGTH * 3)
			{
				pObject->CloseObject();
			}
#endif
		}
	}
}

bool NFEvppNetMessage::ResponseHttpMsg(const NFIHttpHandle &req, const string &strMsg,
                                       NFWebStatus code, const string &reason) {
    if (m_httpServer)
    {
        return m_httpServer->ResponseMsg(req, strMsg, code, reason);
    }
    return false;
}

bool NFEvppNetMessage::ResponseHttpMsg(uint64_t requestId, const string &strMsg,
                                       NFWebStatus code, const string &reason) {
    if (m_httpServer)
    {
        return m_httpServer->ResponseMsg(requestId, strMsg, code, reason);
    }
    return false;
}

int NFEvppNetMessage::HttpGet(const string &strUri, const HTTP_CLIENT_RESPONE &respone,
                              const map<std::string, std::string> &xHeaders, int timeout) {
    if (!m_httpClient)
    {
        m_httpClient = NF_NEW NFCHttpClient();
    }

    return m_httpClient->HttpGet(strUri, respone, xHeaders, timeout);
}

int NFEvppNetMessage::HttpPost(const string &strUri, const string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                               const map<std::string, std::string> &xHeaders, int timeout) {
    if (!m_httpClient)
    {
        m_httpClient = NF_NEW NFCHttpClient();
    }

    return m_httpClient->HttpPost(strUri, strPostData, respone, xHeaders, timeout);
}
