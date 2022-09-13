// -------------------------------------------------------------------------
//    @FileName         :    NFEvppServer.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNetPlugin
//
//
//                    .::::.
//                  .::::::::.
//                 :::::::::::  FUCK YOU
//             ..:::::::::::'
//           '::::::::::::'
//             .::::::::::
//        '::::::::::::::..
//             ..::::::::::::.
//           ``::::::::::::::::
//            ::::``:::::::::'        .:::.
//           ::::'   ':::::'       .::::::::.
//         .::::'      ::::     .:::::::'::::.
//        .:::'       :::::  .:::::::::' ':::::.
//       .::'        :::::.:::::::::'      ':::::.
//      .::'         ::::::::::::::'         ``::::.
//  ...:::           ::::::::::::'              ``::.
// ```` ':.          ':::::::::'                  ::::..
//                    '.:::::'                    ':'````..
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFNetDefine.h"
#include "NetEvppObject.h"
#include "NFINetMessage.h"

#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include "NFComm/NFCore/NFQueue.hpp"
#include "NFComm/NFCore/NFConcurrentQueue.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"

#include "NFIConnection.h"
#include "NFCHttpServer.h"
#include "NFCHttpClient.h"

enum EnumNFEvppClientTimer
{
	ENUM_EVPP_CLIENT_TIMER_HEART = 1, //定时发送心跳
	ENUM_EVPP_SERVER_TIMER_CHECK_HEART = 2, //服务器定时坚持心跳包

	ENUM_EVPP_CLIENT_TIMER_HEART_TIME_LONGTH = 1000, //定时发送心跳时间长度 1000ms
	ENUM_EVPP_SERVER_TIMER_CHECK_HEART_TIME_LONGTH = 3000, //定时发送心跳时间长度 3000ms
};

struct MsgFromNetInfo
{
    MsgFromNetInfo()
    {
        mTCPConPtr = NULL;
        nLinkId = 0;
        nType = eMsgType_Num;
        nMsgId = 0;
        nSendValue = 0;
        nSendId = 0;
    }

	MsgFromNetInfo(const evpp::TCPConnPtr TCPConPtr, uint64_t linkId) : mTCPConPtr(TCPConPtr), nLinkId(linkId)
	{
		nType = eMsgType_Num;
		nMsgId = 0;
        nSendValue = 0;
		nSendId = 0;
	}

	eMsgType nType;
	evpp::TCPConnPtr mTCPConPtr;
	std::string strMsg;
	uint32_t nMsgId;
	uint64_t nSendValue;
	uint64_t nSendId;
	uint64_t nLinkId;
};

class NFCNetServerModule;

class NFEvppNetMessage : public NFINetMessage, public NFTimerObj
{
	friend NFCNetServerModule;
public:
	/**
	 * @brief 构造函数
	 */
	NFEvppNetMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType);

	/**
	* @brief 析构函数
	*/
	virtual ~NFEvppNetMessage();

	/**
	 * @brief 添加网络对象
	 *
	 * @return bool
	 */
	NetEvppObject* AddNetObject(const evpp::TCPConnPtr conn, uint32_t parseType);

	/**
	 * @brief 添加网络对象
	 *
	 * @return bool
	 */
	NetEvppObject* AddNetObject(uint64_t unLinkId, const evpp::TCPConnPtr conn, uint32_t parseType);

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
    * @brief	初始化
    *
    * @return 是否成功
    */
    virtual int64_t BindHttpServer(uint32_t listen_port, uint32_t netThreadNum);

	/**
	* @brief 连接回调
	*
	* @return
	*/
	void ConnectionCallback(const evpp::TCPConnPtr& conn, uint64_t linkId);

	/**
	* @brief 消息回调
	*
	* @return 消息回调
	*/
	void MessageCallback(const evpp::TCPConnPtr& conn, evpp::Buffer* msg, uint64_t linkId, uint32_t packetparse);

	/**
	* @brief	关闭客户端
	*
	* @return  是否成功
	*/
	virtual bool Shut() override;

	/**
	 * @brief 释放数据
	 *
	 * @return bool
	 */
	virtual bool Finalize() override;

	/**
	* @brief	服务器每帧执行
	*
	* @return	是否成功
	*/
	virtual bool Execute() override;

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

	/**
	 * @brief 获得一个可用的ID
	 *
	 * @return uint32_t
	 */
	virtual uint64_t GetFreeUnLinkId();

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
    virtual bool Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue = 0, uint64_t nSendId = 0);

	NetEvppObject* GetNetObject(uint64_t uslinkId);

	virtual void OnTimer(uint32_t nTimerID) override;

	virtual void SendHeartMsg();
	virtual void CheckServerHeartBeat();

    virtual bool ResponseHttpMsg(const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK, const std::string &reason = "OK") override;

    virtual bool ResponseHttpMsg(uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK") override;

    virtual int HttpGet(const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3) override;

    virtual int HttpPost(const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3) override;
protected:
	/**
	 * @brief 主线程处理消息队列
	 */
	virtual void ProcessMsgLogicThread();

	/**
	 * @brief	对解析出来的数据进行处理
	 *
	 * @param type    数据类型，主要是为了和多线程统一处理, 主要有接受数据处理，连接成功处理，断开连接处理
	 * @param usLink  本客户端的唯一id
	 * @param pBuf    数据指针
	 * @param sz      数据大小
	 * @param nMsgId  分析出来的消息id
	 * @param nValue  消息头携带的值，可能是玩家ID，也可能是对方客户端连接的唯一id
	 * @return
	 */
	virtual void OnHandleMsgPeer(eMsgType type, uint64_t connectionLink, uint64_t objectLinkId, char* pBuf, uint32_t sz, uint32_t nMsgId, uint64_t nSendValue, uint64_t nSendId);

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(NetEvppObject* pObject, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId);

	/**
	 * @brief	发送数据
	 *
	 * @param pData		发送的数据, 这里的数据已经包含了数据头
	 * @param unSize	数据的大小
	 * @return
	 */
	virtual bool Send(NetEvppObject* pObject, const char* msg, uint32_t nLen);
private:
	std::vector<NFIConnection* > m_connectionList;
	std::list<uint64_t>  mFreeLinks;
	NFCHttpServer* m_httpServer;
    NFCHttpClient* m_httpClient;
private:
	/**
	* @brief 链接对象数组
	*/
	std::unordered_map<uint64_t, NetEvppObject*> mNetObjectArray;

	/**
	* @brief 需要删除的连接对象
	*/
	std::vector<uint64_t> mvRemoveObject;

	/**
	* @brief 需要消息队列
	*/
    NFConcurrentQueue<MsgFromNetInfo> mMsgQueue;

	/**
	* @brief 发送BUFF
	*/
	NFBuffer mxSendBuffer;
};
