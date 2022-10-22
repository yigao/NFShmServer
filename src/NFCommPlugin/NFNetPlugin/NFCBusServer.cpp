// -------------------------------------------------------------------------
//    @FileName         :    NFCBusServer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCBusServer.cpp
//
// -------------------------------------------------------------------------


#include "NFCBusServer.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFIPacketParse.h"
#include "NFComm/NFPluginModule/NFNetPackagePool.h"
#include <string.h>
#include <sstream>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFPluginModule/NFIConfigModule.h>

NFCBusServer::NFCBusServer(NFIPluginManager* p, NF_SERVER_TYPES serverType, const NFMessageFlag& flag):NFIBusConnection(p, serverType, flag)
{
    mHandleMsgNumPerFrame = NF_NO_FIX_FAME_HANDLE_MAX_MSG_COUNT;
    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(mServerType);
    if (pServerConfig)
    {
        mHandleMsgNumPerFrame= pServerConfig->HandleMsgNumPerFrame;
    }
}

NFCBusServer::~NFCBusServer()
{

}

bool NFCBusServer::Execute()
{
    ProcessMsgLogicThread();
    return true;
}

bool NFCBusServer::Init()
{
    int64_t linkId = BindServer(mFlag);
    if (linkId <= 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "BindServer Failed!");
        return false;
    }

    return true;
}

bool NFCBusServer::Shut()
{
    m_busMsgPeerCb = NULL;

    return true;
}

bool NFCBusServer::Finalize()
{
    return true;
}

/**
* @brief	初始化
*
* @return 是否成功
*/
int64_t NFCBusServer::BindServer(const NFMessageFlag& flag)
{
    if (flag.mBusId <= 0 || flag.mBusLength <= 4096)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "busid:{} busLength:{} error!", flag.mBusId, flag.mBusLength);
        return -1;
    }

    int ret = AttachShm((key_t)flag.mBusId, (size_t)flag.mBusLength);
    if (ret < 0)
    {
        ret = InitShm((key_t)flag.mBusId, (size_t)flag.mBusLength);
    }

    if (ret < 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "bus init failed:{} ", ret);
        return ret;
    }

    NFShmRecordType * pShmRecord = GetShmRecord();
    if (pShmRecord == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetShmRecord failed, busid:{} ", flag.mBusId);
        return -1;
    }

    pShmRecord->m_nOwner = true;
    pShmRecord->m_nBusId = flag.mBusId;
    pShmRecord->m_nBusLenth = flag.mBusLength;
    pShmRecord->mPacketParseType = flag.mPacketParseType;
    pShmRecord->m_nUnLinkId = GetUnLinkId(NF_IS_BUS, mServerType, flag.mBusId);
    m_bindFlag = flag;
    m_bindFlag.mLinkId = pShmRecord->m_nUnLinkId;
    SetLinkId(pShmRecord->m_nUnLinkId);
    SetConnectionType(NF_CONNECTION_TYPE_TCP_SERVER);

    NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
    if (head->m_nShmAddr.mDstLinkId == 0)
    {
        head->m_nShmAddr.mDstLinkId = pShmRecord->m_nUnLinkId;
    }
    else
    {
        if (head->m_nShmAddr.mDstLinkId != pShmRecord->m_nUnLinkId)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "shm dst linkId:{} != now linkId:{} ", head->m_nShmAddr.mDstLinkId, pShmRecord->m_nUnLinkId);
            return -1;
        }
    }

    return pShmRecord->m_nUnLinkId;
}

/**
 * @brief 主线程处理消息队列
 */
void NFCBusServer::ProcessMsgLogicThread()
{
    size_t max_times = NF_NO_FIX_FAME_HANDLE_MAX_MSG_COUNT;
    if (!m_pObjPluginManager->IsLoadAllServer() && m_pObjPluginManager->IsFixedFrame())
    {
        max_times = NF_FIX_FRAME_HANDLE_MAX_MSG_COUNT;
    }

    NFShmRecordType* pShmRecord = GetShmRecord();
    if (pShmRecord->m_nOwner)
    {
        NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
        NFShmChannel *pChannel = &head->m_nShmChannel;
        size_t left_times = max_times;
        mxBuffer.Clear();
        while(left_times-- > 0)
        {
            size_t recv_len = 0;
            int ret = ShmRecv(pChannel, mxBuffer.WriteAddr(), mxBuffer.WritableSize(), &recv_len);

            if (ret == EN_NFBUS_ERR_NO_DATA) {
                break;
            }

            mxBuffer.Produce(recv_len);

            // 回调收到数据事件
            if (ret < 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Shm Recv Error:{}", ret)
                break;
            }
            else
            {
                while (true)
                {
                    char* outData = nullptr;
                    uint32_t outLen = 0;
                    uint32_t allLen = 0;
                    NFDataPackage dataPacket;
                    int ret = NFIPacketParse::DeCode(pShmRecord->mPacketParseType, mxBuffer.ReadAddr(), mxBuffer.ReadableSize(), outData, outLen, allLen, dataPacket);
                    if (ret < 0)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "nfbus parse data failed!");
                        mxBuffer.Clear();
                        break;
                    }
                    else if (ret > 0)
                    {
                        break;
                    }
                    else
                    {
                        mxBuffer.Consume(allLen);

                        dataPacket.nBuffer = outData;
                        dataPacket.nMsgLen = outLen;

                        if (dataPacket.mModuleId == 0 && dataPacket.nMsgId == NF_SERVER_TO_SERVER_BUS_CONNECT_REQ)
                        {
                            m_busMsgPeerCb(eMsgType_CONNECTED, dataPacket.nSendBusLinkId, dataPacket.nSendBusLinkId, dataPacket);
                        }
                        else if (dataPacket.mModuleId == 0 && dataPacket.nMsgId == NF_SERVER_TO_SERVER_BUS_CONNECT_RSP)
                        {
                            m_busMsgPeerCb(eMsgType_CONNECTED, dataPacket.nSendBusLinkId, dataPacket.nSendBusLinkId, dataPacket);
                        }
                        else
                        {
                            m_busMsgPeerCb(eMsgType_RECIVEDATA, dataPacket.nSendBusLinkId, dataPacket.nSendBusLinkId, dataPacket);
                        }

                        continue;
                    }
                }
            }
        }
    }
}

bool NFCBusServer::Send(NFDataPackage& packet, const char* msg, uint32_t nLen)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Bus Server Can't Send Data............., packet:{}", packet.ToString());
    return false;
}

bool NFCBusServer::Send(NFDataPackage& packet, const google::protobuf::Message& xData)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Bus Server Can't Send Data............., packet:{}", packet.ToString());
    return false;
}


