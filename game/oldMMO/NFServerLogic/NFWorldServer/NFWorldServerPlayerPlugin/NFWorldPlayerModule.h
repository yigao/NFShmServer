// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFWorldPlayerMgr.h"

class NFCWorldPlayerModule : public NFIDynamicModule
{
public:
    explicit NFCWorldPlayerModule(NFIPluginManager *p);

    virtual ~NFCWorldPlayerModule();

    virtual bool Awake() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

public:
    /**
     * @brief 检查服务器消息，是否应该处理
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnCheckWorldServerMsg(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 处理登录协议
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet);
private:
    /**
     * @brief NFILuaModule
     */
    NFILuaModule m_luaModule;
};
