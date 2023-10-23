// -------------------------------------------------------------------------
//    @FileName         :    NFCSceneModule.h
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFCSceneModule
//
// -------------------------------------------------------------------------

#pragma once

#include <ServerInternal.pb.h>
#include "NFLogicCommon/NFMMODynamicModule.h"

class NFCSceneModule : public NFMMODynamicModule
{
public:
    explicit NFCSceneModule(NFIPluginManager *pPluginManager);

    virtual ~NFCSceneModule();

    virtual bool Awake() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    /**
     * @brief 响应注册事件
     * @param nEventID
     * @param nSrcID
     * @param bySrcType
     * @param message
     * @return
     */
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;
private:
    /**
     * @brief NFILuaModule
     */
    NFILuaLoader m_luaModule;
};