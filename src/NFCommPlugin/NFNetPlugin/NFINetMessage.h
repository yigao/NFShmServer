// -------------------------------------------------------------------------
//    @FileName         :    NFIServer.h
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
#include "NFComm/NFCore/NFMutex.h"
#include "NFComm/NFCore/NFLock.h"
#include "google/protobuf/message.h"
#include "NFComm/NFPluginModule/NFIHttpHandle.h"

class NFINetMessage : public NFIModule
{
	friend class NFCNetMessageDriverModule;
public:
	/**
	 * @brief 构造函数
	 */
	NFINetMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType) : NFIModule(p), mServerType(serverType)
	{
		mNetObjectMaxIndex = 1;
		assert(serverType > NF_ST_NONE && serverType < NF_ST_MAX);
	}

	/**
	* @brief 析构函数
	*/
	virtual ~NFINetMessage()
	{
	}

    /**
     *@brief  设置接收回调.
     */
    template<typename BaseType>
    void SetRecvCB(BaseType *pBaseType,
                   void (BaseType::*handleRecieve)(uint64_t conntionLinkId, uint64_t objectLinkId, uint64_t valueId,
                                                   uint32_t nMsgId, const char *msg, uint32_t nLen)) {
        mRecvCB = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2,
                            std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6);
    }

    /**
     *@brief  设置连接事件回调.
     */
    template<typename BaseType>
    void SetEventCB(BaseType *pBaseType,
                    void (BaseType::*handleEvent)(eMsgType nEvent, uint64_t conntionLinkId, uint64_t objectLinkId)) {
        mEventCB = std::bind(handleEvent, pBaseType, std::placeholders::_1, std::placeholders::_2,
                             std::placeholders::_3);
    }

    /**
    *@brief  设置接收回调.
    */
    template<typename BaseType>
    void SetHttpRecvCB(BaseType *pBaseType, bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        mHttpReceiveCB = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2);
    }

    /**
     *@brief  设置连接事件回调.
     */
    template<typename BaseType>
    void
    SetHttpFilterCB(BaseType *pBaseType, NFWebStatus(BaseType::*handleFilter)(uint32_t, const NFIHttpHandle &req)) {
        mHttpFilter = std::bind(handleFilter, pBaseType, std::placeholders::_1, std::placeholders::_2);
    }

    /**
     *@brief  设置接收回调.
     */
    void SetRecvCB(const NET_CALLBACK_RECEIVE_FUNCTOR &recvcb) {
        mRecvCB = recvcb;
    }

    /**
     *@brief  设置连接事件回调.
     */
    void SetEventCB(const NET_CALLBACK_EVENT_FUNCTOR &eventcb) {
        mEventCB = eventcb;
    }

    /**
     *@brief  设置接收回调.
     */
    void SetHttpRecvCB(const HTTP_RECEIVE_FUNCTOR &recvcb) {
        mHttpReceiveCB = recvcb;
    }

    /**
     *@brief  设置连接事件回调.
     */
    void SetHttpFilterCB(const HTTP_FILTER_FUNCTOR &eventcb) {
        mHttpFilter = eventcb;
    }

    /**
    * @brief	初始化
    *
    * @return 是否成功
    */
    virtual int64_t BindServer(const NFMessageFlag &flag) = 0;

    /**
    * @brief	初始化
    *
    * @return 是否成功
    */
    virtual int64_t ConnectServer(const NFMessageFlag &flag) = 0;

    /**
     * @brief	发送数据
     *
     * @param pData		发送的数据, 这里的数据已经包含了数据头
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(uint64_t usLinkId, const char *pData, uint32_t unSize) = 0;

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool
    Send(uint64_t usLinkId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t nSendValue = 0, uint64_t nSendId = 0) = 0;

    /**
     * @brief 获得连接IP
     *
     * @param  usLinkId
     * @return std::string
     */
    virtual std::string GetLinkIp(uint64_t usLinkId) = 0;

    /**
    * @brief 关闭连接
    *
    * @param  usLinkId
    * @return
    */
    virtual void CloseLinkId(uint64_t usLinkId) = 0;

    /**
    * @brief	获得服务器类型
    *
    * @return
    */
    virtual uint32_t GetServerType() const { return mServerType; }

    virtual bool ResponseHttpMsg(const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK") { return false; }

    virtual bool ResponseHttpMsg(uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                             const std::string &reason = "OK") { return false; }

    virtual int HttpGet(const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3) { return -1; }

    virtual int HttpPost(const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3) { return -1; }

    virtual int ResumeConnect() { return 0; }
protected:
    /**
     * @brief	处理接受数据的回调
     */
    NET_CALLBACK_RECEIVE_FUNCTOR mRecvCB;

    /**
     * @brief	网络事件回调
     */
    NET_CALLBACK_EVENT_FUNCTOR mEventCB;

    /**
    * @brief 服务器类型
    */
    NF_SERVER_TYPES mServerType;

    /**
    * @brief 当前链接对象最大索引
    */
    uint32_t mNetObjectMaxIndex;

    /**
    * @brief	HTTP处理接受数据的回调
    */
    HTTP_RECEIVE_FUNCTOR mHttpReceiveCB;
    /**
    * @brief	HTTP处理接受数据的回调
    */
    HTTP_FILTER_FUNCTOR mHttpFilter;
};
