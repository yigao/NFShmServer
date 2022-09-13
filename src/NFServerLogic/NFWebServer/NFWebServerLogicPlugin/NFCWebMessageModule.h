// -------------------------------------------------------------------------
//    @FileName         :    NFCWebMessageModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCWebMessageModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServer/NFCommHead/NFIWebServerModule.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

class NFCWebMessageModule : public NFIDynamicModule
{
public:
    explicit NFCWebMessageModule(NFIPluginManager* p);
    virtual ~NFCWebMessageModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual void OnTimer(uint32_t nTimerID) override;
public:
    int OnHandleRegisterAccountPhoneAutoCodeReq(uint64_t unLinkId, uint64_t clientLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleAccountPhoneCheckCodeReq(uint64_t unLinkId, uint64_t clientLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen);
public:
    int OnHandlePlayerPhoneAutoCodeReq(uint64_t unLinkId, uint64_t clientLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerPhoneCheckCodeReq(uint64_t unLinkId, uint64_t clientLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleWebServerRspNotify(uint64_t unLinkId, uint64_t clientLinkId, uint64_t reqBusId, uint32_t nMsgId, const char* msg, uint32_t nLen);
};