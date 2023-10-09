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
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;
public:
    /**
     * @brief 获取角色列表
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleGetRoleList(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 创建角色
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleCreateRole(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 处理玩家进游戏
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleLoginRole(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 处理玩家掉线
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandlePlayerDisconnect(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleLoginFinishNotify(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleLeaveGameReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleTransSceneReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2);
};

