// -------------------------------------------------------------------------
//    @FileName         :    NFCLoginServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCLoginServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFILogicServerModule.h"

class NFCLogicServerModule : public NFILogicServerModule
{
public:
    explicit NFCLogicServerModule(NFIPluginManager *p);

    virtual ~NFCLogicServerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;
public:
    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestOtherServerToWorldServer();
    int OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet);
};