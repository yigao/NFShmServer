// -------------------------------------------------------------------------
//    @FileName         :    NFCMasterServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCMasterServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFIMasterServerModule.h"
#include "NFComm/NFPluginModule/NFIHttpHandle.h"

class NFCMasterServerModule : public NFIMasterServerModule
{
public:
	explicit NFCMasterServerModule(NFIPluginManager* p);
	virtual ~NFCMasterServerModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

	virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message* pMessage) override;

	int ConnectGlobalServer();
    int ServerReport();

	int SynServerToOthers(NF_SHARE_PTR<NFServerData> pServerData);
    int SynOtherServerToServer(NF_SHARE_PTR<NFServerData> pServerData);
	int OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet);
	int OnServerReportProcess(uint64_t unLinkId, NFDataPackage& packet);

	int OnServerDumpInfoProcess(uint64_t unLinkId, NFDataPackage& packet);

    int OnServerKillAllServerProcess(uint64_t unLinkId, NFDataPackage& packet);

    bool HandleReloadServer(uint32_t, const NFIHttpHandle &req);
    bool HandleReloadAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleRestartServer(uint32_t, const NFIHttpHandle &req);
    bool HandleRestartAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStartServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStartAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStopServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStopAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleKillAllServer(uint32_t, const NFIHttpHandle &req);

    int HandleStopSeverRsp(uint64_t unLinkId, NFDataPackage& packet);
    int HandleStartSeverRsp(uint64_t unLinkId, NFDataPackage& packet);
    int HandleRestartSeverRsp(uint64_t unLinkId, NFDataPackage& packet);
    int HandleReloadSeverRsp(uint64_t unLinkId, NFDataPackage& packet);
    int HandleStopAllSeverRsp(uint64_t unLinkId, NFDataPackage& packetn);
    int HandleStartAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet);
    int HandleRestartAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet);
    int HandleReloadAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet);

    int OnGlobalSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleGlobalOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    int RegisterGlobalServer();
protected:
	int OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
	int OnClientDisconnect(uint64_t unLinkId);
};
