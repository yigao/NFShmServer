// -------------------------------------------------------------------------
//    @FileName         :    NFCBusClient.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCBusClient.cpp
//
// -------------------------------------------------------------------------

#include "NFCBusClient.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFIPacketParse.h"
#include "NFComm/NFPluginModule/NFNetPackagePool.h"
#include <string.h>
#include <sstream>
#include <NFComm/NFPluginModule/NFCheck.h>

NFCBusClient::~NFCBusClient()
{

}

bool NFCBusClient::Execute()
{
    return true;
}

bool NFCBusClient::Init()
{
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
    return true;
}

bool NFCBusClient::Finalize()
{
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

bool NFCBusClient::Send(NFShmChannel *pChannel, int packetParseType, NFDataPackage* packet)
{
    mxBuffer.Clear();
    NFIPacketParse::EnCode(packetParseType, *packet, mxBuffer, m_bindFlag.mLinkId);

    int iRet = ShmSend(pChannel, mxBuffer.ReadAddr(), mxBuffer.ReadableSize());
    if (iRet == 0)
    {
        packet->Clear();
        NFNetPackagePool<NFDataPackage>::Instance()->Free(packet, packet->mBufferMsg.Capacity());
        return true;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ShmSend from:{} to:{} error:{}", NFServerIDUtil::GetBusNameFromBusID(m_bindFlag.mBusId), NFServerIDUtil::GetBusNameFromBusID(mFlag.mBusId), iRet);
    }
    return false;
}

bool NFCBusClient::Send(NFDataPackage* pPackage)
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


    NFShmChannelHead *head = (NFShmChannelHead *)pShmRecord->m_nBuffer;
    NFShmChannel *pChannel = &head->m_nShmChannel;
    if (pChannel)
    {
        return Send(pChannel, pShmRecord->mPacketParseType, pPackage);
    }

    return false;
}