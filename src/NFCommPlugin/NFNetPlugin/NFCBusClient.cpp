// -------------------------------------------------------------------------
//    @FileName         :    NFCBusClient.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCBusClient.cpp
//
// -------------------------------------------------------------------------

#include "NFCBusClient.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFIPacketParse.h"
#include <string.h>
#include <sstream>

NFCBusClient::~NFCBusClient()
{

}

bool NFCBusClient::Execute()
{
    return true;
}

bool NFCBusClient::Init()
{
    if (mServerType == NF_ST_ROUTE_AGENT_SERVER || mServerType == NF_ST_ROUTE_SERVER || mServerType == NF_ST_PROXY_AGENT_SERVER)
    {
        m_eventLoop = NF_NEW evpp::EventLoopThread();
        m_eventLoop->set_name(GetServerName(mServerType));
        m_eventLoop->Start(true);
    }

    int64_t linkId = ConnectServer(mFlag, m_bindFlag);
    if (linkId <= 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ConnectServer Failed!");
        return false;
    }
    return true;
}

bool NFCBusClient::Shut()
{
    if (m_eventLoop)
    {
        while(m_eventLoop->IsRunning())
        {
            m_eventLoop->Stop(true);
        }
    }

    return true;
}

bool NFCBusClient::Finalize()
{
    if (m_eventLoop)
    {
        NF_SAFE_DELETE(m_eventLoop);
        m_eventLoop = NULL;
    }
    return true;
}

/**
* @brief	初始化
*
* @return 是否成功
*/
int64_t NFCBusClient::ConnectServer(const NFMessageFlag& flag, const NFMessageFlag& bindFlag)
{
    if (flag.mBusId <= 0 || flag.mBusLength <= 4096)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "busid:{} busLength:{} error!", NFServerIDUtil::GetBusNameFromBusID(flag.mBusId), flag.mBusLength);
        return -1;
    }

    int ret = AttachShm((key_t)flag.mBusId, (size_t)flag.mBusLength, NULL, NULL);
    if (ret < 0)
    {
        ret = InitShm((key_t)flag.mBusId, (size_t)flag.mBusLength, NULL, NULL);
    }

    if (ret < 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "bus init failed:{} ", ret);
        return ret;
    }

    NFShmRecordType * pShmRecord = GetShmRecord();
    if (pShmRecord == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetShmRecord failed, busid:{} ", NFServerIDUtil::GetBusNameFromBusID(flag.mBusId));
        return -1;
    }

    pShmRecord->m_nOwner = false;
    pShmRecord->m_nBusId = flag.mBusId;
    pShmRecord->m_nBusLenth = flag.mBusLength;
    pShmRecord->mPacketParseType = flag.mPacketParseType;
    pShmRecord->m_nUnLinkId = GetUnLinkId(NF_IS_BUS, mServerType, flag.mBusId);
    SetLinkId(pShmRecord->m_nUnLinkId);
    SetConnectionType(NF_CONNECTION_TYPE_TCP_CLIENT);

    bool find = false;
    NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
    for(size_t i = 0; i < ARRAYSIZE(head->m_nShmAddr.mSrcLinkId); i++)
    {
        if (head->m_nShmAddr.mSrcLinkId[i] == m_bindFlag.mLinkId)
        {
            find = true;
            break;
        }
    }

    if (!find)
    {
        for(size_t i = 0; i < ARRAYSIZE(head->m_nShmAddr.mSrcLinkId); i++)
        {
            if (head->m_nShmAddr.mSrcLinkId[i] == m_bindFlag.mLinkId)
            {
                break;
            }

            uint64_t curValue = 0;
            bool f = head->m_nShmAddr.mSrcLinkId[i].compare_exchange_strong(curValue, (uint64_t)m_bindFlag.mLinkId);
            if (f)
            {
                find = true;
                head->m_nShmAddr.mSrcBusLength[i] = m_bindFlag.mBusLength;
                head->m_nShmAddr.mSrcParseType[i] = m_bindFlag.mPacketParseType;
                if (flag.bActivityConnect)
                {
                    head->m_nShmAddr.bActiveConnect[i] = true;
                }
                else
                {
                    head->m_nShmAddr.bActiveConnect[i] = false;
                }
                break;
            }
        }
    }

    if (!find)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ConnectServer:{} failed! the bus no seat, too many connection!", NFServerIDUtil::GetBusNameFromBusID(flag.mBusId));
    }

    if (flag.bActivityConnect)
    {
        SendBusConnectMsg(m_bindFlag.mBusId, (uint64_t)m_bindFlag.mBusLength);
    }

    return (int64_t)pShmRecord->m_nUnLinkId;
}

/**
 * @brief	发送数据
 *
 * @param pData		发送的数据, 这里的数据已经包含了数据头
 * @param unSize	数据的大小
 * @return
 */
bool NFCBusClient::Send(const char* pData, uint32_t unSize)
{
    NFShmRecordType * pShmRecord = GetShmRecord();
    if (pShmRecord == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetShmRecord failed");
        return false;
    }

    if (pShmRecord->m_nOwner == true)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "bus owner can't send data, uslinkId:{} ", pShmRecord->m_nUnLinkId);
        return false;
    }

    if (pShmRecord->m_nBuffer == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "buffer = null, uslinkId:{} ", pShmRecord->m_nUnLinkId);
        return false;
    }

    NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
    NFShmChannel *pChannel = &head->m_nShmChannel;
    if (pChannel)
    {
        return SendToLoop(pChannel, pData, unSize);
    }
    return false;
}

bool NFCBusClient::SendToLoop(NFShmChannel *pChannel, const char* pData, uint32_t unSize)
{
    if (m_eventLoop)
    {
        m_eventLoop->loop()->QueueInLoop(std::bind(&NFCBusClient::SendStringInLoop, this, pChannel, std::string(pData, unSize)));
        return true;
    }
    else
    {
        int iRet = ShmSend(pChannel, pData, unSize);
        if (iRet)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ShmSend from:{} to:{} error:{}", NFServerIDUtil::GetBusNameFromBusID(m_bindFlag.mBusId), NFServerIDUtil::GetBusNameFromBusID(mFlag.mBusId), iRet);
            return false;
        }
    }
    return true;
}

void NFCBusClient::SendStringInLoop(NFShmChannel *pChannel, const std::string& msg)
{
    int iRet = ShmSend(pChannel, msg.data(), msg.length());
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ShmSend from:{} to:{} error:{}", NFServerIDUtil::GetBusNameFromBusID(m_bindFlag.mBusId), NFServerIDUtil::GetBusNameFromBusID(mFlag.mBusId), iRet);
    }
}

bool NFCBusClient::Send(uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    NFShmRecordType * pShmRecord = GetShmRecord();
    if (pShmRecord == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetShmRecord failed,");
        return false;
    }

    if (pShmRecord->m_nOwner == true)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "bus owner can't send data, uslinkId:{} ", pShmRecord->m_nUnLinkId);
        return false;
    }

    if (pShmRecord->m_nBuffer == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "buffer = null, uslinkId:{} ", pShmRecord->m_nUnLinkId);
        return false;
    }

    mxBuffer.Clear();
    NFIPacketParse::EnCode(pShmRecord->mPacketParseType, nMsgID, nSendValue, nSendId, msg, nLen, mxBuffer, m_bindFlag.mLinkId);

    NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
    NFShmChannel *pChannel = &head->m_nShmChannel;
    if (pChannel)
    {
        return SendToLoop(pChannel, mxBuffer.ReadAddr(), mxBuffer.ReadableSize());
    }
    return false;
}