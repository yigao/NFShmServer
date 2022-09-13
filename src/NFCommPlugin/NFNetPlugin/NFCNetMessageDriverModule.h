// -------------------------------------------------------------------------
//    @FileName         :    NFCNetServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCNetServerModule
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

#include "NFComm/NFPluginModule/NFIMessageDriver.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFINetMessage.h"
#include <NFComm/NFCore/NFBuffer.h>

class NFCNetMessageDriverModule : public NFIMessageDriver
{
public:
	/**
	 * @brief 构造函数
	 */
	NFCNetMessageDriverModule(NFIPluginManager* p);

	/**
	 * @brief 析构函数
	 */
	virtual ~NFCNetMessageDriverModule();

	/**
	 *@brief  设置接收回调.
	 */
	virtual void SetRecvCB(const NET_CALLBACK_RECEIVE_FUNCTOR& recvcb)
	{
		mRecvCB = recvcb;
	}

	/**
	 *@brief  设置连接事件回调.
	 */
	virtual void SetEventCB(const NET_CALLBACK_EVENT_FUNCTOR& eventcb)
	{
		mEventCB = eventcb;
	}

    /**
    *@brief  设置接收回调.
    */
    void SetHttpRecvCB(const HTTP_RECEIVE_FUNCTOR& recvcb)
    {
        mHttpReceiveCB = recvcb;
    }

    /**
     *@brief  设置连接事件回调.
     */
    void SetHttpFilterCB(const HTTP_FILTER_FUNCTOR& eventcb)
    {
        mHttpFilter = eventcb;
    }

	/**
	* @brief
	*
	* @return bool
	*/
	virtual bool Awake() override;

	/**
	 * @brief
	 *
	 * @return bool
	 */
	virtual bool BeforeShut() override;

	/**
	 * @brief
	 *
	 * @return bool
	 */
	virtual bool Shut() override;

	/**
	 * @brief 释放数据
	 *
	 * @return bool
	 */
	virtual bool Finalize() override;

	virtual bool ReadyExecute() override;

	/**
	 * @brief
	 *
	 * @return bool
	 */
	virtual bool Execute() override;

	/**
	 * @brief 添加服务器
	 *
	 * @param  eType		服务器类型
	 * @param  nServerID	服务器ID
	 * @param  nMaxClient	服务器最大连接客户端数
	 * @param  nPort		服务器监听端口
	 * @return int			返回0错误
	 */
	virtual int64_t BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nNetThreadNum = 1, uint32_t nMaxConnectNum = 100, uint32_t nPacketParseType = PACKET_PARSE_TYPE_INTERNAL) override;

	/**
	 * @brief 添加服务器
	 *
	 * @param  eType		服务器类型
	 * @param  nServerID	服务器ID
	 * @param  nMaxClient	服务器最大连接客户端数
	 * @param  nPort		服务器监听端口
	 * @return int			返回0错误
	 */
	virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType = 0) override;

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType) override;

	/**
	 * @brief 获得服务器
	 *
	 * @param  eServerType
	 * @return NFIServer
	 */
	virtual NFINetMessage* GetServerByServerType(NF_SERVER_TYPES eServerType);

	/**
	 * @brief 获得连接的IP
	 *
	 * @param  usLinkId
	 * @return std::string
	 */
	virtual std::string GetLinkIp(uint64_t usLinkId) override;

	/**
	* @brief 关闭连接
	*
	* @param  usLinkId
	* @return
	*/
	virtual void CloseLinkId(uint64_t usLinkId) override;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId = 0) override;

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK, const std::string &reason = "OK") override;

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK") override;

    virtual int HttpGet(NF_SERVER_TYPES serverType, const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3) override;

    virtual int HttpPost(NF_SERVER_TYPES serverType, const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3) override;
protected:
	/**
	 * @brief 将消息编码后通过pServer发送出去
	 *
	 */
    void SendMsg(NFINetMessage* pServer, uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId);
private:
	/**
	 * @brief	处理接受数据的回调
	 */
	NET_CALLBACK_RECEIVE_FUNCTOR mRecvCB;

	/**
	 * @brief	网络事件回调
	 */
	NET_CALLBACK_EVENT_FUNCTOR mEventCB;

    /**
    * @brief	HTTP处理接受数据的回调
    */
    HTTP_RECEIVE_FUNCTOR mHttpReceiveCB;
    /**
    * @brief	HTTP处理接受数据的回调
    */
    HTTP_FILTER_FUNCTOR mHttpFilter;

	std::vector<NFINetMessage*> mNetServerArray;
	std::vector<NFINetMessage*> mBusServerArray;
};
