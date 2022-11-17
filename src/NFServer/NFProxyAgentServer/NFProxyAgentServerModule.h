// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyAgentServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCProxyAgentServerModule
//
// -------------------------------------------------------------------------

#pragma once
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"


class NFCProxyAgentServerModule : public NFIDynamicModule
{
public:
	explicit NFCProxyAgentServerModule(NFIPluginManager* p);
	virtual ~NFCProxyAgentServerModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message* pMessage);
public:
    /*
    处理ProxyServer链接事件和未注册消息
    */
    int OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleProxyAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleProxyServerDisconnect(uint64_t unLinkId);
    int OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet);
    int OnOtherServerRegisterProcess(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);

	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

	int RegisterMasterServer(uint32_t serverState);
    int RegisterProxyServer(uint64_t unLinkId);
	int ServerReport();
	int OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleProxyReport(const proto_ff::ServerInfoReport& xData);

    int OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleProxyOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
};
