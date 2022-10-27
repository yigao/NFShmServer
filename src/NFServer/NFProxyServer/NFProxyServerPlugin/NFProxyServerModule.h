// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#pragma once
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include <NFComm/NFPluginModule/NFEventObj.h>
#include "NFComm/NFCore/NFMap.hpp"


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

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message) override;

    virtual void SetOtherServerMsgHandle(const NET_RECEIVE_FUNCTOR& func) override { m_otherServerMsgHandle = func; }

    virtual uint32_t GetClientMsgServer(uint32_t msgId) override;
public:
	/*
		处理Master服务器链接事件和未注册消息
	*/
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

	int RegisterMasterServer(uint32_t serverState);
	int ServerReport();
	int OnHandleMasterServerReport(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleProxyAgentServerReport(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleOtherReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);
    int OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);

    int OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleProxyServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    int OnHandleProxyServerDisconnect(uint64_t unLinkId);

    int RegisterProxyAgentServer(uint64_t unLinkId);

    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestSendProxyMsgToOtherServer(uint64_t dstBusId);
    int OnHandleTestOtherSendMsg(uint64_t unLinkId, NFDataPackage& packet);
public:
    uint64_t m_proxyServerLinkId;
    NET_RECEIVE_FUNCTOR m_otherServerMsgHandle;
    std::vector<uint32_t> m_clientMsgToServerMap;
};
