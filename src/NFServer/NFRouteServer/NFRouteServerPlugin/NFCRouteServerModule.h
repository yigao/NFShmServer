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
#include "NFServerComm/NFServerCommon/NFIRouteServerModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"

class NFIMessageModule;
class NFCRouteServerModule : public NFIRouteServerModule
{
public:
	explicit NFCRouteServerModule(NFIPluginManager* p);
	virtual ~NFCRouteServerModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);

	int OnRouteSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
	int OnHandleServerDisconnect(uint64_t unLinkId);

	int OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet);
	int OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleServerRegisterRouteAgent(uint64_t unLinkId, NFDataPackage& packet);

	int RegisterMasterServer();
	int ServerReport();

	int OnHandleRouteAgentRegister(const proto_ff::ServerInfoReport& xData, uint64_t unlinkId);

	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
};
