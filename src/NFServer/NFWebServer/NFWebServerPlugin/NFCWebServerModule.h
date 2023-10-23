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
#include "NFComm/NFCore/NFSTLMapEx.hpp"
#include "NFComm/NFCore/NFSTLMap.hpp"
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

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;
};