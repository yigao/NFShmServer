// -------------------------------------------------------------------------
//    @FileName         :    NFIMsgModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <stdint.h>
#include "NFIModule.h"
#include "NFServerDefine.h"
#include "google/protobuf/message.h"
#include "NFComm/NFPluginModule/NFIHttpHandle.h"

/// @brief 网络驱动接口
class NFIMessageDriver : public NFIModule
{
public:
	NFIMessageDriver(NFIPluginManager* p):NFIModule(p) {}
	virtual ~NFIMessageDriver() {}

	/**
	 *@brief  设置接收回调.
	 */
	template <typename BaseType>
	void SetRecvCB(BaseType* pBaseType, int (BaseType::*handleRecieve)(uint64_t connectionLink, uint64_t objectLinkId, uint64_t nSendValue, uint64_t nSendId, uint32_t nMsgId, const char* msg, uint32_t nLen))
	{
		NET_CALLBACK_RECEIVE_FUNCTOR func = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7);
		SetRecvCB(func);
	}

	/**
	 *@brief  设置连接事件回调.
	 */
	template <typename BaseType>
	void SetEventCB(BaseType* pBaseType, int (BaseType::*handleEvent)(eMsgType nEvent, uint64_t connectionLink, uint64_t objectLinkId))
	{
		NET_CALLBACK_EVENT_FUNCTOR func = std::bind(handleEvent, pBaseType, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		SetEventCB(func);
	}

    /**
    *@brief  设置接收回调.
    */
    template<typename BaseType>
    void SetHttpRecvCB(BaseType *pBaseType, bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_RECEIVE_FUNCTOR func = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2);
        SetHttpRecvCB(func);
    }

    /**
     *@brief  设置连接事件回调.
     */
    template<typename BaseType>
    void SetHttpFilterCB(BaseType *pBaseType, NFWebStatus(BaseType::*handleFilter)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_FILTER_FUNCTOR func = std::bind(handleFilter, pBaseType, std::placeholders::_1, std::placeholders::_2);
        SetHttpFilterCB(func);
    }

	/**
	 *@brief  设置接收回调.
	 */
	virtual void SetRecvCB(const NET_CALLBACK_RECEIVE_FUNCTOR& recvcb) = 0;

	/**
	 *@brief  设置连接事件回调.
	 */
	virtual void SetEventCB(const NET_CALLBACK_EVENT_FUNCTOR& eventcb) = 0;

    /**
    *@brief  设置接收回调.
    */
    virtual void SetHttpRecvCB(const HTTP_RECEIVE_FUNCTOR& recvcb) = 0;

    /**
     *@brief  设置连接事件回调.
     */
    virtual void SetHttpFilterCB(const HTTP_FILTER_FUNCTOR& eventcb) = 0;

	/**
	 * @brief 添加服务器
	 *
	 * @param  eType		服务器类型
	 * @param  nServerID	服务器ID
	 * @param  nMaxClient	服务器最大连接客户端数
	 * @param  nPort		服务器监听端口
	 * @return int			返回0错误
	 */
	virtual int64_t BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nNetThreadNum = 1, uint32_t nMaxConnectNum = 100, uint32_t nPacketParseType = PACKET_PARSE_TYPE_INTERNAL) = 0;

	/**
	 * @brief 添加服务器
	 *
	 * @param  eType		服务器类型
	 * @param  nServerID	服务器ID
	 * @param  nMaxClient	服务器最大连接客户端数
	 * @param  nPort		服务器监听端口
	 * @return int			返回0错误
	 */
	virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType = 0) = 0;

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType) = 0;

	virtual std::string GetLinkIp(uint64_t usLinkId) = 0;

	virtual void CloseLinkId(uint64_t usLinkId) = 0;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId = 0) = 0;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg,uint32_t nLen, uint64_t nSendValue, uint64_t nSendId = 0) = 0;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId = 0) = 0;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId = 0) = 0;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId = 0) = 0;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId = 0) = 0;

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK, const std::string &reason = "OK") = 0;

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK") = 0;

    virtual int HttpGet(NF_SERVER_TYPES serverType, const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3) = 0;

    virtual int HttpPost(NF_SERVER_TYPES serverType, const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3) = 0;
};
