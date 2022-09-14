// -------------------------------------------------------------------------
//    @FileName         :    NFCMsgModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIMessageDriver.h"
#include "NFComm/NFPluginModule/NFIHttpHandle.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFServerLinkData.h"
#include <stdint.h>

class NFCMessageModule : public NFIMessageModule {
public:
    explicit NFCMessageModule(NFIPluginManager *p);

    virtual ~NFCMessageModule();

    virtual bool Awake() override;

    virtual bool Finalize() override;

    virtual bool Execute() override;

    virtual bool OnReloadPlugin() override;

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual int64_t
    BindServer(NF_SERVER_TYPES eServerType, const std::string &url, uint32_t nNetThreadNum = 1, uint32_t nMaxConnectNum = 100, uint32_t nPacketParseType = PACKET_PARSE_TYPE_INTERNAL, bool bSecurity = false) override;

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
	virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType = 0, bool bSecurity = false) override;

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType) override;

	virtual std::string GetLinkIp(uint64_t usLinkId) override;

	virtual void CloseLinkId(uint64_t usLinkId) override;

    virtual void CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId) override;

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string& strData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t param1, uint64_t param2 = 0) override;

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t param1, uint64_t param2 = 0) override;

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t nModuleId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t param1 = 0) override;

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t param1 = 0) override;

    virtual NF_SHARE_PTR<NFServerData> GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId) override;

    virtual NF_SHARE_PTR<NFServerData> GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId) override;


    virtual NF_SHARE_PTR<NFServerData> CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data) override;

    virtual void CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId,
                                                          uint64_t linkId) override;

    virtual void DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId) override;

    virtual NFServerData* GetRouteData(NF_SERVER_TYPES eSendType) override;
    virtual const NFServerData* GetRouteData(NF_SERVER_TYPES eSendType) const override;

    virtual NFServerData* GetMasterData(NF_SERVER_TYPES eSendType) override;
    virtual const NFServerData* GetMasterData(NF_SERVER_TYPES eSendType) const override;

    virtual void CloseAllLink(NF_SERVER_TYPES eSendType) override;

    virtual uint64_t GetServerLinkId(NF_SERVER_TYPES eSendType) const override;

    virtual void SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId) override;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual NF_SHARE_PTR<NFServerData> GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value) override;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string& value) override;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType) override;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual std::vector<std::string> GetDBNames(NF_SERVER_TYPES eSendType) override;
public:
    /// @brief 设置通信驱动(通信库)，运行时只支持一种通信驱动，如rawudp，tbuspp或第3方网络库
    /// @param driver 对MessageDriver接口实现的网络库
    /// @return 0 表示成功
    /// @return -1 表示失败
    void SetMessageDriver(NFIMessageDriver *driver);

public:
    virtual bool DelAllCallBack(void *pTarget) override;

    virtual bool DelAllCallBack(NF_SERVER_TYPES eType, uint64_t unLinkId) override;

    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void *pTaraget,
                                    const NET_RECEIVE_FUNCTOR &cb) override;

    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, void* pTarget, const NET_RECEIVE_FUNCTOR & cb) override;

    virtual bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget,
                                  const NET_RECEIVE_FUNCTOR &cb) override;

    virtual bool
    AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget, const NET_EVENT_FUNCTOR &cb) override;

    int OnReceiveNetPack(uint64_t connectionLink, uint64_t objectLinkId, const NFDataPackage& packet);

	int OnHandleReceiveNetPack(uint64_t connectionLink, uint64_t objectLinkId, const NFDataPackage& packet);

    int OnSocketNetEvent(eMsgType nEvent, uint64_t connectionLink, uint64_t objectLinkId);

public:
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
protected:
    virtual bool AddHttpMsgCB(NF_SERVER_TYPES serverType, const std::string &strCommand, const NFHttpType eRequestType,
                              const HTTP_RECEIVE_FUNCTOR &cb);

    virtual bool AddHttpOtherMsgCB(NF_SERVER_TYPES serverType, const NFHttpType eRequestType, const HTTP_RECEIVE_FUNCTOR &cb);

    virtual bool AddHttpFilterCB(NF_SERVER_TYPES serverType, const std::string &strCommand, const HTTP_FILTER_FUNCTOR &cb);

    virtual bool OnHttpReceiveNetPack(uint32_t serverType, const NFIHttpHandle& req);
    virtual NFWebStatus OnHttpFilterPack(uint32_t serverType, const NFIHttpHandle& req);
protected:
    NFIMessageDriver *m_driver;

    std::vector<CallBack> mxCallBack;

    std::vector<ServerLinkData> mServerLinkData;
};
