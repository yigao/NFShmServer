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
#include "NFComm/NFMessageDefine/proto_common.pb.h"

class NFGlobalServerModule : public NFIDynamicModule
{
public:
    explicit NFGlobalServerModule(NFIPluginManager* p);
    virtual ~NFGlobalServerModule();

    virtual bool Awake() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;
public:
    int OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnServerReportProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
public:
    bool HandleKillServer(uint32_t, const NFIHttpHandle &req);
    bool HandleStopServer(uint32_t, const NFIHttpHandle &req);
protected:
    int OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId);
    int OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnClientDisconnect(uint64_t unLinkId);

    NF_SHARE_PTR<NFServerData> GetServerDataByContractInfo(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id);
    NF_SHARE_PTR<NFServerData> CreateServerData(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id);

    int GetServerMgrFromDB();
    proto_ff::tbServerMgr* GetServerDataByContractInfoFromDB(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id);
    proto_ff::tbServerMgr* CreateServerDataFromDB(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id);

    int SaveServerMgr(const proto_ff::tbServerMgr* pMgr);
private:
    std::map<std::string, NFMapEx<std::string, std::vector<NF_SHARE_PTR<NFServerData>>>> m_contractServerData;
    std::map<std::string, std::map<std::string, std::vector<proto_ff::tbServerMgr>>> m_contractServerMgr;
};
