// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#pragma once
#include "NFServer/NFCommHead/NFIProxyServerModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include <NFComm/NFPluginModule/NFEventObj.h>
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServer/NFCommHead/NFCommLogicHead.h"


class NFCProxyServerModule : public NFIProxyServerModule
{
public:
	explicit NFCProxyServerModule(NFIPluginManager* p);
	virtual ~NFCProxyServerModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);
public:
	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, const NFDataPackage& packet);

	int RegisterMasterServer();
	int ServerReport();
	int OnHandleMasterServerReport(uint64_t unLinkId, const NFDataPackage& packet);
    int OnHandleProxyAgentServerReport(uint64_t unLinkId, const NFDataPackage& packet);
    int OnHandleOtherReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);
    int OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);

    int OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleProxyServerOtherMessage(uint64_t unLinkId, const NFDataPackage& packet);
    int OnHandleProxyServerDisconnect(uint64_t unLinkId);

    int RegisterProxyAgentServer(uint64_t unLinkId);
public:
    uint64_t m_proxyServerLinkId;
};
