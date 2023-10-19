// -------------------------------------------------------------------------
//    @FileName         :    NFCMatchServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2023-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFCMatchServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFIMatchServerModule.h"

class NFCMatchServerModule : public NFIMatchServerModule
{
public:
    explicit NFCMatchServerModule(NFIPluginManager *p);

    virtual ~NFCMatchServerModule();

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
