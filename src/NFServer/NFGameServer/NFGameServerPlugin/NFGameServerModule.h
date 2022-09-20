// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFIGameServerModule.h"

class NFCGameServerModule : public NFIGameServerModule
{
public:
    explicit NFCGameServerModule(NFIPluginManager *p);

    virtual ~NFCGameServerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);
public:
    int OnGameSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleServerDisconnect(uint64_t unLinkId);

    //网关服务器注册协议回调
    int OnHandleProxyRegister(const proto_ff::ServerInfoReport &xData, uint64_t unlinkId);

	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int RegisterMasterServer();
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

	int ServerReport();
	int OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet);
	int OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet);

	int OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData);
	int OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData);
	int RegisterRouteAgentServer(uint64_t unLinkId);
    int OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet);
	int OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    int OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData);
    int RegisterProxyAgentServer(uint64_t unLinkId);
    int OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleProxyAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    int OnTestProxyServerMsg(uint64_t unLinkId, NFDataPackage& packet);
    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestOtherServerToWorldServer(uint64_t dstBusId);
    int OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet);
};
