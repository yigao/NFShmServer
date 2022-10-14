// -------------------------------------------------------------------------
//    @FileName         :    NFLoginModule.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginModule
//
// -------------------------------------------------------------------------

#pragma once


#include <ServerInternal.pb.h>
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFLoginModule : public NFIDynamicModule
{
public:
    explicit NFLoginModule(NFIPluginManager *p);

    virtual ~NFLoginModule();

    virtual bool Awake() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;
public:
    /**
     * @brief 获取角色列表
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleGetRoleList(uint64_t unLinkId, NFDataPackage &packet);
};