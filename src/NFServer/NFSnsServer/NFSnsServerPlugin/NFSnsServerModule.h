// -------------------------------------------------------------------------
//    @FileName         :    NFCSnsServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCSnsServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFISnsServerModule.h"

class NFCSnsServerModule : public NFISnsServerModule
{
public:
    explicit NFCSnsServerModule(NFIPluginManager *p);

    virtual ~NFCSnsServerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message) override;
public:
	int ServerReport();
	int OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet);

    int OnSnsSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

	int OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData);
	int OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData);
	int RegisterRouteAgentServer(uint64_t unLinkId);
    int OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet);
	int OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int RegisterMasterServer(uint32_t serverState);
	int OnMasterSocketEvent(eMsgType nEvent,uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestOtherServerToWorldServer();
    int OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet);
};
