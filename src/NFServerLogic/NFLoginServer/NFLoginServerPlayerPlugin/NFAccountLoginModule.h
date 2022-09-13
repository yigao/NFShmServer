// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServer/NFCommHead/NFIAccountLoginModule.h"

class NFAccountLoginMgr;

class NFCAccountLoginModule : public NFIAccountLoginModule
{
    enum {
        ENUM_SERVER_LOAD_FROM_WORLD = 1,
    };
public:
	explicit NFCAccountLoginModule(NFIPluginManager* p);
	virtual ~NFCAccountLoginModule();

	virtual bool Awake() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

public:
    int OnHandleAccountLoginFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleChangePasswordFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleLoadServerFromWorldServer(uint64_t unLinkId, uint64_t clientLinkId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleAccountRegisterFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandlePhoneAutoCodeFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleCheckPhoneCodeFromClient(uint64_t unLinkId, uint64_t clientLinkId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
};
