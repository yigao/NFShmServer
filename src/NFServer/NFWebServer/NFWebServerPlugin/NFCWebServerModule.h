// -------------------------------------------------------------------------
//    @FileName         :    NFCWebServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCWebServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFIWebServerModule.h"

class NFCWebServerModule : public NFIWebServerModule
{
public:
    explicit NFCWebServerModule(NFIPluginManager* p);
    virtual ~NFCWebServerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);

    int RegisterMasterServer();
    int ServerReport();

    int OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData);
    int OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    int RegisterRouteAgentServer(uint64_t unLinkId);
    int OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet);

    int OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet);

    /*
        处理Master服务器链接事件和未注册消息
    */
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);
    int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packetn);

    int OnWebSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packetn);
    int OnHandleServerDisconnect(uint64_t unLinkId);
};