// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServer/NFCommHead/NFIWorldPlayerModule.h"
#include "NFWorldPlayerMgr.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

class NFCWorldPlayerModule : public NFIWorldPlayerModule
{
public:
	explicit NFCWorldPlayerModule(NFIPluginManager* p);
	virtual ~NFCWorldPlayerModule();

	virtual bool Awake() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

public:
	int OnHandlePlayerLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleLogicServerLoginRsp(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandlePlayerReconnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleLogicServerReconnectRsp(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
public:
	int OnHandleRouteToSuitLogicServer(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHandleRegisterUserFromLoginServer(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqTransId, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHandleLogoutUserFromLoginServer(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqTransId, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHnadleChangeDeviceFromLoginServer(uint64_t unLinkId, uint64_t loginLinkId, uint64_t reqTransId, uint32_t nMsgId, const char* msg, uint32_t nLen);
};
