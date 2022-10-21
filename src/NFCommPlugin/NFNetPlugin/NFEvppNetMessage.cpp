// -------------------------------------------------------------------------
//    @FileName         :    NFEvppServer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFNetPlugin
// -------------------------------------------------------------------------

#include "NFEvppNetMessage.h"

#include <stddef.h>
#include <cstdint>
#include <list>
#include <string>
#include <vector>
#include <NFComm/NFCore/NFCommon.h>
#include <NFComm/NFPluginModule/NFCheck.h>

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCodeQueue.h"
#include "NFEvppClient.h"
#include "NFEvppServer.h"
#include "NFIPacketParse.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "Encrypt.h"

NFEvppNetMessage::NFEvppNetMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType) : NFINetMessage(p, serverType), NFTimerObj(p),m_netObjectPool(1000, false)
{
	mxSendBuffer.AssureSpace(MAX_SEND_BUFFER_SIZE);
    mxRecvBuffer.AssureSpace(MAX_RECV_BUFFER_SIZE);
	SetTimer(ENUM_EVPP_CLIENT_TIMER_HEART, ENUM_EVPP_CLIENT_TIMER_HEART_TIME_LONGTH);
	SetTimer(ENUM_EVPP_SERVER_TIMER_CHECK_HEART, ENUM_EVPP_SERVER_TIMER_CHECK_HEART_TIME_LONGTH);
    m_httpServer = NULL;
#if defined(EVPP_HTTP_SERVER_SUPPORTS_SSL)
    m_httpServerEnableSSL = false;
#endif
    m_httpClient = NULL;

    if (m_pObjPluginManager->IsLoadAllServer())
    {
        m_coonectionThreadPool.reset(NF_NEW evpp::EventLoopThreadPool(NULL, 1));
        m_coonectionThreadPool->Start(true);
    }

    /**
     * @brief 0作废，作为一个错误处理，从1开始
     */
    for(int i = 1; i < MAX_CLIENT_INDEX; i++)
    {
        uint64_t unlinkId = GetUnLinkId(NF_IS_NET, mServerType, i);
        while (!mFreeLinks.Enqueue(unlinkId)) {
        }
    }
}

NFEvppNetMessage::~NFEvppNetMessage()
{
	for (auto iter = mNetObjectArray.begin(); iter != mNetObjectArray.end(); ++iter)
	{
		auto pObject = iter->second;
		if (pObject)
		{
            m_netObjectPool.FreeObj(pObject);
		}
	}
	mNetObjectArray.clear();
}

void NFEvppNetMessage::ProcessMsgLogicThread()
{
    int max_times = NF_NO_FIX_FAME_HANDLE_MAX_MSG_COUNT;
    if (!m_pObjPluginManager->IsLoadAllServer() && m_pObjPluginManager->IsFixedFrame())
    {
        max_times = NF_FIX_FRAME_HANDLE_MAX_MSG_COUNT;
    }

    while(!mMsgQueue.IsQueueEmpty() && max_times >= 0)
    {
        std::vector<MsgFromNetInfo*> vecMsg;
        vecMsg.resize(200);

        mMsgQueue.TryDequeueBulk(vecMsg);

        for (size_t index = 0; index < vecMsg.size(); index++)
        {
            max_times--;
            MsgFromNetInfo* pMsg = vecMsg[index];
            CHECK_EXPR_CONTINUE(pMsg, "pMsg == NULL");
            CHECK_EXPR_ASSERT_NOT_RET(pMsg->mTCPConPtr != NULL, "");

            if (pMsg->nType == eMsgType_CONNECTED)
            {
                if (pMsg->pRecvBuffer)
                {
                    m_recvCodeQueueList.push_back(pMsg->pRecvBuffer);
                }

                for (size_t i = 0; i < m_connectionList.size(); i++)
                {
                    if (m_connectionList[i]->GetLinkId() == pMsg->nConnectLinkId)
                    {
                        if (m_connectionList[i]->GetConnectionType() == NF_CONNECTION_TYPE_TCP_CLIENT)
                        {
                            CHECK_EXPR_ASSERT_NOT_RET(m_connectionList[i]->GetLinkId() == pMsg->nObjectLinkId, "m_connectionList[i]->GetLinkId() != pMsg->nObjectLinkId, Error..........");

                            NetEvppObject* pObject = GetNetObject(pMsg->nObjectLinkId);
                            if (pObject == NULL)
                            {
                                pObject = AddNetObject(pMsg->nObjectLinkId, pMsg->mTCPConPtr, m_connectionList[i]->GetPacketParseType(), m_connectionList[i]->IsSecurity());
                                CHECK_EXPR_ASSERT_NOT_RET(pObject != NULL, "AddNetObject Failed");
                            }
                            CHECK_EXPR_ASSERT_NOT_RET(m_connectionList[i]->GetLinkId() == pObject->m_usLinkId, "m_connectionList[i]->GetLinkId() != pObject->m_usLinkId, Error..........");

                            pObject->SetConnPtr(pMsg->mTCPConPtr);
                            pObject->SetIsServer(false);
                            NFDataPackage tmpPacket;
                            OnHandleMsgPeer(eMsgType_CONNECTED, m_connectionList[i]->GetLinkId(), pObject->m_usLinkId, tmpPacket);
                        }
                        else
                        {
                            NetEvppObject* pObject = GetNetObject(pMsg->nObjectLinkId);
                            CHECK_EXPR_ASSERT_NOT_RET(pObject == NULL, "GetNetObject(pMsg->nObjectLinkId:{}) Exist", pMsg->nObjectLinkId);
                            pObject = AddNetObject(pMsg->nObjectLinkId, pMsg->mTCPConPtr, m_connectionList[i]->GetPacketParseType(), m_connectionList[i]->IsSecurity());
                            CHECK_EXPR_ASSERT_NOT_RET(pObject != NULL, "AddNetObject Failed");

                            NFDataPackage tmpPacket;
                            OnHandleMsgPeer(eMsgType_CONNECTED, m_connectionList[i]->GetLinkId(), pObject->m_usLinkId, tmpPacket);
                        }
                        break;
                    }
                }
            }
            else if (pMsg->nType == eMsgType_DISCONNECTED)
            {
                if (pMsg->nObjectLinkId != 0)
                {
                    /**
                     * @brief 不允许出现pMsg->nObjectLinkId找不到的情况，说明代码设置有考虑不周到的情况
                     */
                    NetEvppObject* pObject = GetNetObject(pMsg->nObjectLinkId);
                    CHECK_EXPR_ASSERT_NOT_RET(pObject != NULL, "net diconnect, tcp context error, can't find the net object:{}", pMsg->nObjectLinkId);
                    if (pObject->GetNeedRemove() == false)
                    {
                        if (pObject->IsServer())
                        {
                            pObject->SetNeedRemove(true);
                        }
                    }

                    pObject->mConnPtr = NULL;
                    NFDataPackage tmpPacket;
                    OnHandleMsgPeer(eMsgType_DISCONNECTED, pMsg->nConnectLinkId, pMsg->nObjectLinkId, tmpPacket);
                }
                else {
                    /**
                     * @brief   处理客户端连接服务器掉线, 这里相当于NFClient主动连接服务器，没有连接上
                     *         这里的conn其实是一个临时的对象
                     */
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "net client:{} diconnect, can't connect the server", pMsg->nConnectLinkId);

                    NFDataPackage tmpPacket;
                    OnHandleMsgPeer(eMsgType_DISCONNECTED, pMsg->nConnectLinkId, pMsg->nConnectLinkId, tmpPacket);
                }
            }
            else if (pMsg->nType == eMsgType_RECIVEDATA)
            {
                if (pMsg->mTCPConPtr)
                {
                    if (!pMsg->mTCPConPtr->context().IsEmpty())
                    {
                        uint64_t objectLinkId = evpp::any_cast<uint64_t>(pMsg->mTCPConPtr->context());
                        NetEvppObject* pObject = GetNetObject(objectLinkId);
                        if (pObject)
                        {
                            OnHandleMsgPeer(eMsgType_RECIVEDATA, pMsg->nConnectLinkId, objectLinkId, pMsg->mPacket);
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

            pMsg->Clear();
            NFNetPackagePool<MsgFromNetInfo>::Instance()->Free(pMsg, pMsg->mPacket.mBufferMsg.Capacity());
        }
    }
}

void NFEvppNetMessage::ProcessCodeQueue(NFCodeQueue* pRecvQueue)
{
    NF_ASSERT_MSG(pRecvQueue != NULL, "pRecvQueue == NULL");
    while(pRecvQueue->HasCode())
    {
        mxRecvBuffer.Clear();
        int iCodeLen = 0;
        int iRet = pRecvQueue->Get(mxRecvBuffer.WriteAddr(), mxRecvBuffer.WritableSize(), iCodeLen);
        if (iRet || iCodeLen < (int)sizeof(NFCodeQueuePackage))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "get code from pRecvQueue failed ret={}, codelen={}", iRet, iCodeLen);
            continue;
        }
        mxRecvBuffer.Produce(iCodeLen);

        // 先获取NetHead
        NFCodeQueuePackage* pCodePackage = (NFCodeQueuePackage*)mxRecvBuffer.ReadAddr();
        if (iCodeLen != (int)sizeof(NFCodeQueuePackage) + (int)pCodePackage->nMsgLen) // 长度不一致
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "code length invalid. iCodeLen:{} != sizeof(NFCodeQueuePackage):{} + pCodePackage->nMsgLen:{}", iCodeLen,
                    sizeof(NFCodeQueuePackage), pCodePackage->nMsgLen);
            continue;
        }

        NetEvppObject* pObject = GetNetObject(pCodePackage->nObjectLinkId);
        if (pObject)
        {
            NFDataPackage package;
            package.Copy(*pCodePackage);
            package.mBufferMsg.PushData(mxRecvBuffer.ReadAddr()+sizeof(NFCodeQueuePackage), pCodePackage->nMsgLen);
            OnHandleMsgPeer(eMsgType_RECIVEDATA, pCodePackage->nConnectLinkId, pCodePackage->nObjectLinkId, package);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "net server recv data, tcp context error");
        }
    }
}


void NFEvppNetMessage::ProcessCodeQueue()
{
    for(int i = 0; i < (int)m_recvCodeQueueList.size(); i++)
    {
        NF_SHARE_PTR<NFBuffer> pRecvBuffer = m_recvCodeQueueList[i];
        if (pRecvBuffer)
        {
            NFCodeQueue* pQueue = (NFCodeQueue*)pRecvBuffer->ReadAddr();
            ProcessCodeQueue(pQueue);
        }
    }
}

/**
* @brief 连接回调
*
* @return
*/
void NFEvppNetMessage::ConnectionCallback(const evpp::TCPConnPtr& conn, uint64_t connectLinkId)
{
	if (conn->IsConnected())
	{
		conn->SetTCPNoDelay(true);
        MsgFromNetInfo* pMsg = NFNetPackagePool<MsgFromNetInfo>::Instance()->Alloc(0);
        NF_ASSERT_MSG(pMsg, "pMsg == NULL, NFNetPackagePool<MsgFromNetInfo>::Instance().Alloc Failed");
        pMsg->mTCPConPtr = conn;
        pMsg->nConnectLinkId = connectLinkId;
        pMsg->nType = eMsgType_CONNECTED;
        //client connect
        if (conn->type() == evpp::TCPConn::kOutgoing)
        {
            /**
             * @brief 客户端掉线，一定会清理调conn->context(), 不如程序有问题
             */
            CHECK_EXPR_ASSERT_NOT_RET(conn->context().IsEmpty(), "conn->context().IsEmpty() Error");
            pMsg->nObjectLinkId = connectLinkId;
            pMsg->mTCPConPtr->set_context(evpp::Any(pMsg->nObjectLinkId));
        }
        else {
            CHECK_EXPR_ASSERT_NOT_RET(conn->context().IsEmpty(), "conn->context().IsEmpty() Error");
            pMsg->nObjectLinkId = GetFreeUnLinkId();
            if (pMsg->nObjectLinkId == 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetFreeUnLinkId() Failed, No Free UnlinkId");
                pMsg->mTCPConPtr->Close();

                /**
                 * @brief 用来区分GetFreeUnLinkId Failed
                 */
                pMsg->mTCPConPtr->set_context(1, evpp::Any(pMsg->nObjectLinkId));

                pMsg->Clear();
                NFNetPackagePool<MsgFromNetInfo>::Instance()->Free(pMsg, 0);
                return;
            }
            pMsg->mTCPConPtr->set_context(evpp::Any(pMsg->nObjectLinkId));
        }

        if (conn->loop()->context(EVPP_LLOP_CONTEXT_0_MAIN_THREAD_RECV).IsEmpty())
        {
            NF_SHARE_PTR<NFBuffer> pRecvBuffer = NF_SHARE_PTR<NFBuffer>(NF_NEW NFBuffer());
            pRecvBuffer->AssureSpace(MAX_CODE_QUEUE_SIZE);
            pRecvBuffer->Produce(MAX_CODE_QUEUE_SIZE);
            NFCodeQueue* pQueue = (NFCodeQueue*)pRecvBuffer->ReadAddr();
            pQueue->Init(pRecvBuffer->ReadableSize());
            conn->loop()->set_context(EVPP_LLOP_CONTEXT_0_MAIN_THREAD_RECV, evpp::Any(pRecvBuffer));
            pMsg->pRecvBuffer = pRecvBuffer;
        }

        if (conn->loop()->context(EVPP_LLOP_CONTEXT_1_MAIN_THREAD_SEND).IsEmpty())
        {
            NF_SHARE_PTR<NFBuffer> pSendBuffer = NF_SHARE_PTR<NFBuffer>(NF_NEW NFBuffer());
            pSendBuffer->AssureSpace(MAX_CODE_QUEUE_SIZE);
            pSendBuffer->Produce(MAX_CODE_QUEUE_SIZE);
            NFCodeQueue* pQueue = (NFCodeQueue*)pSendBuffer->ReadAddr();
            pQueue->Init(pSendBuffer->ReadableSize());
            conn->loop()->set_context(EVPP_LLOP_CONTEXT_1_MAIN_THREAD_SEND, evpp::Any(pSendBuffer));
        }
		while(!mMsgQueue.Enqueue(pMsg)) {}
	}
	else
	{
        MsgFromNetInfo* pMsg = NFNetPackagePool<MsgFromNetInfo>::Instance()->Alloc(0);
        NF_ASSERT_MSG(pMsg, "pMsg == NULL, NFNetPackagePool<MsgFromNetInfo>::Instance().Alloc Failed");
        pMsg->Clear();
        pMsg->mTCPConPtr = conn;
        pMsg->nConnectLinkId = connectLinkId;
        pMsg->nType = eMsgType_DISCONNECTED;
        /**
         * @brief 处理客户端连接服务器掉线
         */
        if (conn->type() == evpp::TCPConn::kOutgoing)
        {
            if (!conn->context().IsEmpty())
            {
                pMsg->nObjectLinkId  = evpp::any_cast<uint64_t>(conn->context());
                pMsg->mTCPConPtr->set_context(evpp::Any());
            }
            else {
                /**
                 * @brief   处理NFClient客户端连接服务器掉线, 这里相当于NFClient主动连接服务器，没有连接上, 这里的conn其实是一个临时的对象.
                 */

                pMsg->nObjectLinkId = 0;
            }
        }
        else {
            /**
             * @brief 处理服务器的连接掉线
             */
            if (!conn->context().IsEmpty())
            {
                pMsg->nObjectLinkId  = evpp::any_cast<uint64_t>(conn->context());
                pMsg->mTCPConPtr->set_context(evpp::Any());
            }
            else {
                /**
                 * @brief  GetFreeUnLinkId() Failed, NFServer的连接被主动关闭导致
                 */
                if (!conn->context(1).IsEmpty())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetFreeUnLinkId() Failed, net client disconnect, can't find the net context!");
                    pMsg->Clear();
                    NFNetPackagePool<MsgFromNetInfo>::Instance()->Free(pMsg, 0);
                    return;
                }

                NFLogError(NF_LOG_SYSTEMLOG, 0, "Unknow Failed, net client disconnect, can't find the net context!");
                pMsg->nObjectLinkId = 0;
            }
        }

        while(!mMsgQueue.Enqueue(pMsg)) {}
	}
}

/**
* @brief 消息回调
*
* @return 消息回调
*/
void NFEvppNetMessage::MessageCallback(const evpp::TCPConnPtr& conn, evpp::Buffer* msg, uint64_t linkId, uint32_t packetparse, bool bSecurity)
{
	if (msg)
	{
		while (true)
		{
            char* outData = nullptr;
            uint32_t outLen = 0;
            uint32_t allLen = 0;
            if (bSecurity)
            {
                Decryption((char*)msg->data(), msg->size());
            }
            NFBaseDataPackage basePacket;
            int ret = NFIPacketParse::DeCode(packetparse, msg->data(), msg->size(), outData, outLen, allLen, basePacket);
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
                if (!(basePacket.mModuleId == 0 && (basePacket.nMsgId == NF_CLIENT_TO_SERVER_HEART_BEAT
                                                    || basePacket.nMsgId == NF_CLIENT_TO_SERVER_HEART_BEAT_RSP || basePacket.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT || basePacket.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT_RSP)))
                {
                    NFLogTrace(NF_LOG_RECV_MSG, 0, "recv msg:{} ", basePacket.ToString());
                }

                if (basePacket.bCompress)
                {
                    if (conn->loop()->context(EVPP_LOOP_CONTEXT_2_COMPRESS_BUFFER).IsEmpty())
                    {
                        NF_SHARE_PTR<NFBuffer> pComBuffer = NF_SHARE_PTR<NFBuffer>(NF_NEW NFBuffer());
                        pComBuffer->AssureSpace(MAX_RECV_BUFFER_SIZE);
                        conn->loop()->set_context(EVPP_LOOP_CONTEXT_2_COMPRESS_BUFFER, evpp::Any(pComBuffer));
                    }

                    NF_SHARE_PTR<NFBuffer> pComBuffer = evpp::any_cast<NF_SHARE_PTR<NFBuffer>>(conn->loop()->context(EVPP_LOOP_CONTEXT_2_COMPRESS_BUFFER));
                    pComBuffer->Clear();

                    int decompressLen = NFIPacketParse::Decompress(packetparse, outData, outLen, (void *)pComBuffer->WriteAddr(), (int)pComBuffer->WritableSize());
                    if (decompressLen < 0)
                    {
                        NFLogError(NF_LOG_RECV_MSG, 0, "recv msg:{}, decompress failed!", basePacket.ToString());
                        msg->Skip(allLen);
                        continue;
                    }
                    pComBuffer->Produce(decompressLen);

                    if (!conn->loop()->context(EVPP_LLOP_CONTEXT_0_MAIN_THREAD_RECV).IsEmpty())
                    {
                        NF_SHARE_PTR<NFBuffer> pRecvBuffer = evpp::any_cast<NF_SHARE_PTR<NFBuffer>>(conn->loop()->context(EVPP_LLOP_CONTEXT_0_MAIN_THREAD_RECV));
                        NF_ASSERT(pRecvBuffer != NULL);
                        NFCodeQueue* pRecvQueue = (NFCodeQueue*)pRecvBuffer->ReadAddr();
                        NF_ASSERT(pRecvQueue != NULL);

                        NFCodeQueuePackage codePackage;
                        codePackage.Copy(basePacket);
                        codePackage.nMsgLen = pComBuffer->ReadableSize();
                        codePackage.nConnectLinkId = linkId;
                        if (!conn->context().IsEmpty())
                        {
                            codePackage.nObjectLinkId  = evpp::any_cast<uint64_t>(conn->context());
                        }
                        else {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "net server diconnect, tcp context error");
                            codePackage.nObjectLinkId = 0;
                        }
                        int iRet = pRecvQueue->Put((const char*)&codePackage, sizeof(NFCodeQueuePackage), (const char*)pComBuffer->ReadAddr(), pComBuffer->ReadableSize());
                        if (iRet != 0)
                        {
                            if (iRet == -1)
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "pRecvQueue->Put((const char*)&codePackage, sizeof(NFCodeQueuePackage), (const char*)outData, outLen) param error");
                            }
                            else if (iRet == -1)
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "Recv Queue Full error, can't put the error");
                            }

                            MsgFromNetInfo* pMsg = NFNetPackagePool<MsgFromNetInfo>::Instance()->Alloc(decompressLen);
                            NF_ASSERT_MSG(pMsg, "pMsg == NULL, NFNetPackagePool<MsgFromNetInfo>::Instance().Alloc Failed");
                            pMsg->mTCPConPtr = conn;
                            pMsg->nConnectLinkId = linkId;
                            pMsg->mPacket = basePacket;
                            pMsg->nType = eMsgType_RECIVEDATA;
                            pMsg->mPacket.mBufferMsg.PushData(pComBuffer->ReadAddr(), pComBuffer->ReadableSize());
                            while(!mMsgQueue.Enqueue(pMsg)) {}
                        }
                    }
                    else {
                        MsgFromNetInfo* pMsg = NFNetPackagePool<MsgFromNetInfo>::Instance()->Alloc(decompressLen);
                        NF_ASSERT_MSG(pMsg, "pMsg == NULL, NFNetPackagePool<MsgFromNetInfo>::Instance().Alloc Failed");
                        pMsg->mTCPConPtr = conn;
                        pMsg->nConnectLinkId = linkId;
                        pMsg->mPacket = basePacket;
                        pMsg->nType = eMsgType_RECIVEDATA;
                        pMsg->mPacket.mBufferMsg.PushData(pComBuffer->ReadAddr(), pComBuffer->ReadableSize());
                        while(!mMsgQueue.Enqueue(pMsg)) {}
                    }
                }
                else {
                    if (!conn->loop()->context(EVPP_LLOP_CONTEXT_0_MAIN_THREAD_RECV).IsEmpty())
                    {
                        NF_SHARE_PTR<NFBuffer> pRecvBuffer = evpp::any_cast<NF_SHARE_PTR<NFBuffer>>(conn->loop()->context(EVPP_LLOP_CONTEXT_0_MAIN_THREAD_RECV));
                        NF_ASSERT(pRecvBuffer != NULL);
                        NFCodeQueue* pRecvQueue = (NFCodeQueue*)pRecvBuffer->ReadAddr();
                        NF_ASSERT(pRecvQueue != NULL);

                        NFCodeQueuePackage codePackage;
                        codePackage.Copy(basePacket);
                        codePackage.nMsgLen = outLen;
                        codePackage.nConnectLinkId = linkId;
                        if (!conn->context().IsEmpty())
                        {
                            codePackage.nObjectLinkId  = evpp::any_cast<uint64_t>(conn->context());
                        }
                        else {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "net server diconnect, tcp context error");
                            codePackage.nObjectLinkId = 0;
                        }

                        if (!(basePacket.mModuleId == 0 && (basePacket.nMsgId == NF_CLIENT_TO_SERVER_HEART_BEAT
                                                            || basePacket.nMsgId == NF_CLIENT_TO_SERVER_HEART_BEAT_RSP || basePacket.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT || basePacket.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT_RSP)))
                        {
                            NFLogTrace(NF_LOG_RECV_MSG, 0, "put one code msg:{} ", codePackage.ToString());
                        }

                        int iRet = pRecvQueue->Put((const char*)&codePackage, sizeof(NFCodeQueuePackage), (const char*)outData, outLen);
                        if (iRet != 0)
                        {
                            if (iRet == -1)
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "pRecvQueue->Put((const char*)&codePackage, sizeof(NFCodeQueuePackage), (const char*)outData, outLen) param error");
                            }
                            else if (iRet == -1)
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "Recv Queue Full error, can't put the error");
                            }

                            MsgFromNetInfo* pMsg = NFNetPackagePool<MsgFromNetInfo>::Instance()->Alloc(outLen);
                            NF_ASSERT_MSG(pMsg, "pMsg == NULL, NFNetPackagePool<MsgFromNetInfo>::Instance().Alloc Failed");
                            pMsg->mTCPConPtr = conn;
                            pMsg->nConnectLinkId = linkId;
                            pMsg->mPacket = basePacket;
                            pMsg->nType = eMsgType_RECIVEDATA;
                            pMsg->mPacket.mBufferMsg.PushData(outData, outLen);
                            while(!mMsgQueue.Enqueue(pMsg)) {}
                        }
                    }
                    else {
                        MsgFromNetInfo* pMsg = NFNetPackagePool<MsgFromNetInfo>::Instance()->Alloc(outLen);
                        NF_ASSERT_MSG(pMsg, "pMsg == NULL, NFNetPackagePool<MsgFromNetInfo>::Instance().Alloc Failed");
                        pMsg->mTCPConPtr = conn;
                        pMsg->nConnectLinkId = linkId;
                        pMsg->mPacket = basePacket;
                        pMsg->nType = eMsgType_RECIVEDATA;
                        pMsg->mPacket.mBufferMsg.PushData(outData, outLen);
                        while(!mMsgQueue.Enqueue(pMsg)) {}
                    }
                }

				msg->Skip(allLen);

                if (msg->length() <= 0)
                {
                    break;
                }
				continue;
			}
		}
	}
}

int64_t NFEvppNetMessage::BindServer(const NFMessageFlag& flag)
{
    if (flag.bHttp)
    {
        int iRet = BindHttpServer(flag.nPort, flag.nNetThreadNum);
        if (iRet)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "BindHttpServer Failed! port:{}", flag.nPort);
        }
        return iRet;
    }
    else
    {
        NFEvppServer* pServer = NF_NEW NFEvppServer(m_pObjPluginManager, mServerType, flag);

        uint64_t unLinkId = GetFreeUnLinkId();
        pServer->SetLinkId(unLinkId);
        pServer->SetConnCallback(
                std::bind(&NFEvppNetMessage::ConnectionCallback, this, std::placeholders::_1, unLinkId));
        pServer->SetMessageCallback(
                std::bind(&NFEvppNetMessage::MessageCallback, this, std::placeholders::_1, std::placeholders::_2,
                          unLinkId, flag.mPacketParseType, flag.mSecurity));
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
#if defined(EVPP_HTTP_SERVER_SUPPORTS_SSL)
        pServer->SetPortSSLOption(listen_port, m_httpServerEnableSSL, m_httpServerCertificateChainFile.c_str(), m_httpServerPrivateKeyFile.c_str());
#endif
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
    NFEvppClient *pClient = NF_NEW NFEvppClient(m_pObjPluginManager, mServerType, flag);

	if (pClient)
	{
		uint64_t unLinkId = GetFreeUnLinkId();
		pClient->SetLinkId(unLinkId);
		pClient->SetConnCallback(std::bind(&NFEvppNetMessage::ConnectionCallback, this, std::placeholders::_1, unLinkId));
		pClient->SetMessageCallback(std::bind(&NFEvppNetMessage::MessageCallback, this, std::placeholders::_1, std::placeholders::_2, unLinkId, flag.mPacketParseType, flag.mSecurity));

        if (m_pObjPluginManager->IsLoadAllServer() && m_coonectionThreadPool)
        {
            if (pClient->Init(m_coonectionThreadPool->GetNextLoop()))
            {
                m_connectionList.push_back(pClient);

                return (int64_t)unLinkId;
            }
        }
        else {
            if (pClient->Init(NULL))
            {
                m_connectionList.push_back(pClient);

                return (int64_t)unLinkId;
            }
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

uint32_t NFEvppNetMessage::GetPort(uint64_t usLinkId)
{
    NetEvppObject* pObject = GetNetObject(usLinkId);
    if (pObject)
    {
        return pObject->GetPort();
    }
    return 0;
}

NetEvppObject* NFEvppNetMessage::AddNetObject(const evpp::TCPConnPtr conn, uint32_t parseType, bool bSecurity)
{
	uint64_t usLinkId = GetFreeUnLinkId();
	if (usLinkId == 0)
	{
		NFLogError(NF_LOG_NET_PLUGIN, 0, "connected count:{}  Can't add connect", mNetObjectArray.size());
		return nullptr;
	}

	return AddNetObject(usLinkId, conn, parseType, bSecurity);
}

NetEvppObject* NFEvppNetMessage::AddNetObject(uint64_t unLinkId, const evpp::TCPConnPtr conn, uint32_t parseType, bool bSecurity)
{
	if (mNetObjectArray.find(unLinkId) != mNetObjectArray.end())
	{
		NFLogError(NF_LOG_NET_PLUGIN, 0, "GetServerIndexFromUnLinkId Failed!");
		return nullptr;
	}

	auto pObject = m_netObjectPool.MallocObjWithArgs(conn);
	CHECK_EXPR_ASSERT(pObject, NULL, "m_netObjectPool.Alloc() Failed");

	mNetObjectArray.emplace(unLinkId, pObject);

	pObject->SetLinkId(unLinkId);

	if (conn)
	{
		std::string remote_addr = conn->remote_addr();
		std::vector<std::string> vec;
        NFStringUtility::Split(remote_addr, ":", &vec);
        if (vec.size() >= 2)
        {
            pObject->SetStrIp(vec[0]);
            pObject->SetPort(NFCommon::strto<uint32_t>(vec[1]));
        }
	}

	pObject->SetPacketParseType(parseType);
	pObject->SetSecurity(bSecurity);

	return pObject;
}

NetEvppObject* NFEvppNetMessage::GetNetObject(uint64_t usLinkId)
{
	uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);
	if (serverType != mServerType)
	{
		NFLogError(NF_LOG_NET_PLUGIN, 0, "serverType != mServerType, this usLinkId:{} is not of the server:{}", usLinkId, GetServerName(mServerType).c_str());
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
    auto pObject = GetNetObject(usLinkId);
    if (pObject)
    {
        if (pObject->mIsServer == false)
        {
            for (auto iter = m_connectionList.begin(); iter != m_connectionList.end(); iter++)
            {
                NFIConnection* pConnection = *iter;
                if (pConnection->GetConnectionType() == NF_CONNECTION_TYPE_TCP_CLIENT)
                {
                    if (pConnection->GetLinkId() == usLinkId)
                    {
                        pConnection->Shut();
                        pConnection->Finalize();
                        NF_SAFE_DELETE(pConnection);
                        m_connectionList.erase(iter);
                        break;
                    }
                }
            }
        }

        pObject->SetNeedRemove(true);
        pObject->CloseObject();
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the unLinkId:{}", usLinkId);
    }
}

uint64_t NFEvppNetMessage::GetFreeUnLinkId()
{
	uint64_t unlinkId = 0;
	if (!mFreeLinks.IsQueueEmpty())
	{
        if (mFreeLinks.TryDequeue(unlinkId)) {
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

    while(!mMsgQueue.IsQueueEmpty())
    {
        std::vector<MsgFromNetInfo *> vecMsg;
        vecMsg.resize(200);
        mMsgQueue.TryDequeueBulk(vecMsg);
        for(int i = 0; i < (int)vecMsg.size(); i++)
        {
            MsgFromNetInfo* pMsg = vecMsg[i];
            if (vecMsg[i])
            {
                pMsg->Clear();
                NFNetPackagePool<MsgFromNetInfo>::Instance()->Free(pMsg, pMsg->mPacket.mBufferMsg.Capacity());
            }
        }
    }

    if (m_coonectionThreadPool)
    {
        m_coonectionThreadPool->Stop(true);
        NF_ASSERT(m_coonectionThreadPool->IsStopped());
        m_coonectionThreadPool->Join();
        m_coonectionThreadPool.reset();
    }

	return true;
}

bool NFEvppNetMessage::Execute()
{
	ProcessMsgLogicThread();
    ProcessCodeQueue();
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

bool NFEvppNetMessage::Send(uint64_t usLinkId, NFDataPackage* pPackage)
{
    NetEvppObject* pObject = GetNetObject(usLinkId);
    if (pObject)
    {
        return Send(pObject, pPackage);
    }

    return false;
}

void NFEvppNetMessage::OnHandleMsgPeer(eMsgType type, uint64_t connectionLink, uint64_t objectLinkId, NFDataPackage& packet)
{
	switch (type)
	{
	case eMsgType_RECIVEDATA:
	{
	    if (packet.mModuleId == 0)
        {
            if (packet.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT)
            {
                NetEvppObject* pObject = GetNetObject(objectLinkId);
                if (pObject && pObject->mIsServer)
                {
                    pObject->SetLastHeartBeatTime(NFGetTime());
                    NFDataPackage* pPacket = NFNetPackagePool<NFDataPackage>::Instance()->Alloc(0);
                    CHECK_EXPR_NOT_RET(pPacket, "pPacket == NULL, NFNetPackagePool<NFDataPackage>::Instance()->Alloc()");

                    pPacket->mModuleId = 0;
                    pPacket->nMsgId = NF_SERVER_TO_SERVER_HEART_BEAT_RSP;
                    if (!Send(pObject->GetLinkId(), pPacket))
                    {
                        pPacket->Clear();
                        NFNetPackagePool<NFDataPackage>::Instance()->Free(pPacket, pPacket->mBufferMsg.Capacity());
                    }
                    return;
                }
            }

            if (packet.nMsgId == NF_SERVER_TO_SERVER_HEART_BEAT_RSP)
            {
                NetEvppObject* pObject = GetNetObject(objectLinkId);
                if (pObject && pObject->mIsServer == false)
                {
                    pObject->SetLastHeartBeatTime(NFGetTime());
                    return;
                }
            }
        }

		if (mRecvCB)
		{
			mRecvCB(connectionLink, objectLinkId, packet);
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

            uint32_t index = GetServerIndexFromUnlinkId(objectLinkId);
            /**
             * @brief 处理特殊情况，比如客户端主动连接服务器，连接不上
             */
            if (index == 0)
            {
                return;
            }

            auto pObject = GetNetObject(objectLinkId);
            if (pObject && pObject->GetNeedRemove())
            {
                auto iter = mNetObjectArray.find(objectLinkId);
                if (iter != mNetObjectArray.end())
                {
                    mNetObjectArray.erase(iter);
                    m_netObjectPool.FreeObj(pObject);

                    while (!mFreeLinks.Enqueue(objectLinkId)) {
                    }
                }
            }
        }
	}
	break;
	default:
		break;
	}
}

bool NFEvppNetMessage::Send(NetEvppObject* pObject, NFDataPackage* pPackage)
{
    if (pObject && !pObject->GetNeedRemove() && pObject->mConnPtr && pObject->mConnPtr->IsConnected())
    {
        pObject->mConnPtr->loop()->RunInLoop(std::bind([](NFDataPackage* pPackage, evpp::TCPConnPtr pConn, int packetParseType, bool isSecurity){
            if (pConn->loop()->context(EVPP_LOOP_CONTEXT_2_COMPRESS_BUFFER).IsEmpty())
            {
                NF_SHARE_PTR<NFBuffer> pComBuffer = NF_SHARE_PTR<NFBuffer>(NF_NEW NFBuffer());
                pComBuffer->AssureSpace(MAX_RECV_BUFFER_SIZE);
                pConn->loop()->set_context(EVPP_LOOP_CONTEXT_2_COMPRESS_BUFFER, evpp::Any(pComBuffer));
            }

            NF_SHARE_PTR<NFBuffer> pComBuffer = evpp::any_cast<NF_SHARE_PTR<NFBuffer>>(pConn->loop()->context(EVPP_LOOP_CONTEXT_2_COMPRESS_BUFFER));
            pComBuffer->Clear();

            NFIPacketParse::EnCode(packetParseType, *pPackage, *pComBuffer);

            if (isSecurity)
            {
                Encryption(pComBuffer->ReadAddr(), pComBuffer->ReadableSize());
            }

            pConn->Send((const void*)pComBuffer->ReadAddr(), pComBuffer->ReadableSize());

            pComBuffer->Clear();
            pPackage->Clear();
            NFNetPackagePool<NFDataPackage>::Instance()->Free(pPackage, pPackage->mBufferMsg.Capacity());
        }, pPackage, pObject->mConnPtr, pObject->mPacketParseType, pObject->IsSecurity()));
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
            NFDataPackage* pPacket = NFNetPackagePool<NFDataPackage>::Instance()->Alloc(0);
            CHECK_EXPR_NOT_RET(pPacket, "pPacket == NULL, NFNetPackagePool<NFDataPackage>::Instance()->Alloc()");
            pPacket->mModuleId = 0;
            pPacket->nMsgId = NF_SERVER_TO_SERVER_HEART_BEAT;
			if (!Send(m_connectionList[i]->GetLinkId(), pPacket))
            {
                pPacket->Clear();
                NFNetPackagePool<NFDataPackage>::Instance()->Free(pPacket, pPacket->mBufferMsg.Capacity());
            }
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
