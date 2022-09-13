// -------------------------------------------------------------------------
//    @FileName         :    NFCBusModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIBusModule.h"
#include "NFComm/NFCore/NFSpinLock.h"
#include "NFBusHash.h"
#include "NFBusDefine.h"
#include "NFBusShm.h"
#include "NFINetMessage.h"
#include "NFNetDefine.h"
#include "NFComm/NFCore/NFBuffer.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFConcurrentQueue.h"
#include "NFIBusConnection.h"
#include <map>

class NFCBusServer;
class NFCBusClient;

class NFCBusMessage : public NFINetMessage
{
public:
	explicit NFCBusMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType);

	virtual ~NFCBusMessage();

    virtual bool ReadyExecute() override;

	virtual bool Execute() override;

	virtual bool Shut() override;

	virtual bool Finalize() override;
public:
	/**
	* @brief	初始化
	*
	* @return 是否成功
	*/
	virtual int64_t BindServer(const NFMessageFlag& flag);

	/**
	* @brief	初始化
	*
	* @return 是否成功
	*/
	virtual int64_t ConnectServer(const NFMessageFlag& flag);

	/**
	 * @brief	发送数据
	 *
	 * @param pData		发送的数据, 这里的数据已经包含了数据头
	 * @param unSize	数据的大小
	 * @return
	 */
	virtual bool Send(uint64_t usLinkId, const char* pData, uint32_t unSize);

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nValue, uint64_t nvalue2);

	/**
	 * @brief 获得连接IP
	 *
	 * @param  usLinkId
	 * @return std::string
	 */
	virtual std::string GetLinkIp(uint64_t usLinkId);

	/**
	* @brief 关闭连接
	*
	* @param  usLinkId
	* @return
	*/
	virtual void CloseLinkId(uint64_t usLinkId);

    virtual void OnHandleMsgPeerThread(eMsgType type, uint64_t conntionLinkId, uint64_t objectLinkId, const char* pBuf, uint32_t sz, uint32_t nMsgId, uint64_t nSendValue, uint64_t nSendId);

	virtual void OnHandleMsgQueue();

    virtual void OnHandleMsgPeer(eMsgType type, uint64_t conntionLinkId, uint64_t objectLinkId, const char* pBuf, uint32_t sz, uint32_t nMsgId, uint64_t nSendValue, uint64_t nSendId);

    virtual int ResumeConnect() override;
private:
    NFMapEx<uint64_t, NFIBusConnection> m_busConnectMap;
    NF_SHARE_PTR<NFIBusConnection> m_bindConnect;
    NFConcurrentQueue<MsgFromBusInfo> m_msgQueue;
};
