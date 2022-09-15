// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.h
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "common/spdlog/fmt/fmt.h"
#include "NFIMessageModule.h"

class NFMessageMgr : public NFSingleton<NFMessageMgr>
{
public:
    NFMessageMgr();
    virtual ~NFMessageMgr();
public:
    bool Init(NFIMessageModule* pMessageModule = nullptr);
    void UnInit();
public:
    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual int64_t BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t netThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType, bool bSecurity = false);

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType = 0);

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType);

    virtual std::string GetLinkIp(uint64_t usLinkId);

    virtual void CloseLinkId(uint64_t usLinkId);

    virtual void CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId);

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t param1, uint64_t param2 = 0);

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t param1, uint64_t param2 = 0);

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nModuleId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0);


    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t param1, uint64_t param2 = 0);

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t param1, uint64_t param2 = 0);

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0);

    virtual NF_SHARE_PTR<NFServerData> GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId);

    virtual NF_SHARE_PTR<NFServerData> GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId);


    virtual NF_SHARE_PTR<NFServerData> CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType,
                                                              const proto_ff::ServerInfoReport &data);

    virtual void CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId,
                                    uint64_t linkId);

    virtual void DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId);

    virtual NFServerData *GetRouteData(NF_SERVER_TYPES eSendType);

    virtual const NFServerData *GetRouteData(NF_SERVER_TYPES eSendType) const;

    virtual NFServerData *GetMasterData(NF_SERVER_TYPES eSendType);

    virtual const NFServerData *GetMasterData(NF_SERVER_TYPES eSendType) const;

    virtual void CloseAllLink(NF_SERVER_TYPES eSendType);

    virtual uint64_t GetServerLinkId(NF_SERVER_TYPES eSendType) const;

    virtual void SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId);

    virtual std::vector<NF_SHARE_PTR<NFServerData>>
    GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual NF_SHARE_PTR<NFServerData>
    GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value);

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string& value);

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType);

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual std::vector<std::string> GetDBNames(NF_SERVER_TYPES eSendType);
public:
    template<typename BaseType>
    bool AddHttpRequestHandler(NF_SERVER_TYPES serverType, const std::string &strPath, const NFHttpType eRequestType,
                               BaseType *pBase, bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return m_pMessageModule->AddHttpMsgCB(serverType, strPath, eRequestType, functor);
    }

    template<typename BaseType>
    bool AddHttpRequestHandler(NF_SERVER_TYPES serverType, const NFHttpType eRequestType, BaseType *pBase,
                               bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return m_pMessageModule->AddHttpOtherMsgCB(serverType, eRequestType, functor);
    }

    template<typename BaseType>
    bool AddHttpNetFilter(NF_SERVER_TYPES serverType, const std::string &strPath, BaseType *pBase,
                          NFWebStatus(BaseType::*handleFilter)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_FILTER_FUNCTOR functor = std::bind(handleFilter, pBase, std::placeholders::_1, std::placeholders::_2);

        return m_pMessageModule->AddHttpFilterCB(serverType, strPath, functor);
    }

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK, const std::string &reason = "OK");

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK");

    virtual int HttpGet(NF_SERVER_TYPES serverType, const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3);

    virtual int HttpPost(NF_SERVER_TYPES serverType, const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3);
public:
    template<typename BaseType>
    bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, BaseType* pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, const NFDataPackage& packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddMessageCallBack(eType, nMsgID, pBase, functor);
    }

    template<typename BaseType>
    bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, BaseType* pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, const NFDataPackage& packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddMessageCallBack(eType, nModuleId, nMsgID, pBase, functor);
    }

    template <typename BaseType>
    bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType* pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, const NFDataPackage& packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddOtherCallBack(eType, linkId, pBase, functor);
    }

    template <typename BaseType>
    bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType* pBase, int (BaseType::*handler)(eMsgType nEvent, uint64_t unLinkId))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIMessageProcessor");
        NET_EVENT_FUNCTOR functor = std::bind(handler, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddEventCallBack(eType, linkId, pBase, functor);
    }

public:
    virtual bool DelAllCallBack(void *pTarget);

    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void* pTaraget, const NET_RECEIVE_FUNCTOR & cb);

    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, void* pTaraget, const NET_RECEIVE_FUNCTOR & cb);

    virtual bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void* pTaraget, const NET_RECEIVE_FUNCTOR & cb);

    virtual bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void* pTaraget, const NET_EVENT_FUNCTOR& cb);
protected:
    NFIMessageModule* m_pMessageModule;
};
