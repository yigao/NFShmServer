// -------------------------------------------------------------------------
//    @FileName         :    NFCCenterServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2023-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFCCenterServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFCommMapEx.hpp"
#include "NFComm/NFCore/NFCommMap.hpp"
#include "NFServerComm/NFServerCommon/NFICenterServerModule.h"

class NFCCenterServerModule : public NFICenterServerModule
{
public:
    explicit NFCCenterServerModule(NFIPluginManager *p);

    virtual ~NFCCenterServerModule();

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
