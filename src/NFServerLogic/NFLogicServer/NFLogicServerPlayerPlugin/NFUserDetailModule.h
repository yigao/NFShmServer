// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetailModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserDetailModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServer/NFCommHead/NFILogicServerModule.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFServer/NFCommHead/NFIUserDetailModule.h"
#include "NFComm/NFMessageDefine/proto_cs_login.pb.h"

class NFCUserDetailModule : public NFIUserDetailModule
{
public:
    explicit NFCUserDetailModule(NFIPluginManager *p);

    virtual ~NFCUserDetailModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual void OnTimer(uint32_t nTimerID) override;

public:
    int OnHandlePlayerLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerReconnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerError(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerChangeFace(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleRegisterUser(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerChangeDevice(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandlePlayerPhoneAutoCodeReq(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerCheckPhoneCodeReq(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandlePlayerBindPhoneReq(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerPhoneChangeBandPasswordReq(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

	//sns server
	int OnHandleSnsLoginRsp(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHandleSnsLogoutRsp(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHandleEventLogNotify(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHandlePlayerChangeAgentNotify(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
};
