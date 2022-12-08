// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFOnlineModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFCOnlineModule : public NFIDynamicModule
{
public:
    explicit NFCOnlineModule(NFIPluginManager *p);

    virtual ~NFCOnlineModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2) override;

public:
    int OnHandleRoleLogin(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    int OnHandleRoleLogout(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    int OnHandleRoleDisconnect(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2n);

    int OnHandleRoleReconnect(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);
};
