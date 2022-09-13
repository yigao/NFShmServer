// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServer/NFCommHead/NFIRouteServerModule.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
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
    int OnHandleOtherMessage(uint64_t unLinkId, uint64_t sendLinkId, uint64_t destLinkId, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleServerDisconnect(uint64_t unLinkId);

	int OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleServerRegisterRouteAgent(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int RegisterMasterServer();
	int ServerReport();

	int OnHandleRouteAgentRegister(const proto_ff::ServerInfoReport& xData, uint64_t unlinkId);

	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
};
