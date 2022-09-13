// -------------------------------------------------------------------------
//    @FileName         :    NFCMasterServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCMasterServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFServer/NFCommHead/NFIMasterServerModule.h"
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

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);

	int ConnectGlobalServer();
    int ServerReport();

	int SynServerToOthers(NF_SHARE_PTR<NFServerData> pServerData);
	int OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnServerReportProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnServerDumpInfoProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnServerKillAllServerProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    bool HandleReloadServer(uint32_t, const NFIHttpHandle &req);
    bool HandleReloadAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleRestartServer(uint32_t, const NFIHttpHandle &req);
    bool HandleRestartAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStartServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStartAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStopServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStopAllServer(uint32_t, const NFIHttpHandle &req);
    bool HandleKillAllServer(uint32_t, const NFIHttpHandle &req);

    int HandleStopSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleStartSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleRestartSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleReloadSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleStopAllSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleStartAllSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleRestartAllSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int HandleReloadAllSeverRsp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnGlobalSocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleGlobalOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int RegisterGlobalServer();
protected:
	int OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnClientDisconnect(uint64_t unLinkId);
};
