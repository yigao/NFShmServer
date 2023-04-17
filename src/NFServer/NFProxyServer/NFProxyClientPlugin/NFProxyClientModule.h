// -------------------------------------------------------------------------
//    @FileName         :    NFProxyClientModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyClientModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerComm/NFServerCommon/NFIProxyClientModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMap.hpp"

class NFCProxyClientModule : public NFIProxyClientModule
{
public:
    explicit NFCProxyClientModule(NFIPluginManager *p);

    virtual ~NFCProxyClientModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

private:
    /*
        对外部客户端监听唯一ID
    */
    uint64_t m_proxyClientLinkId;
};
