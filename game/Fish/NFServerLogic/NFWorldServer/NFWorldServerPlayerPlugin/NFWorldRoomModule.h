// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomModule.h
//    @Author           :    gaoyi
//    @Date             :    23-7-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFFishDynamicModule.h"

class NFWorldRoomModule : public NFFishDynamicModule
{
public:
    explicit NFWorldRoomModule(NFIPluginManager* p);
    virtual ~NFWorldRoomModule();

    virtual bool Awake() override;

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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2) override;
public:
    /** 房间注册
     * @brief
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServiceRoomRegister(proto_ff::Proto_GTW_RegisterRoomInfoReq &request, proto_ff::Proto_WTG_RegisterRoomInfoRsp &respone);
public:
    /**
     * @brief 获取房间信息
     * @param msgId
     * @param packet
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleGetRoomInfoReq(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2);

    /**
     * @brief 请求桌子信息
     * @param msgId
     * @param packet
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleDeskListReq(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2);

    /**
     * @brief 请求进入游戏
     * @param msgId
     * @param packet
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleEnterGameReq(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2);

    /**
     * @brief 请求退出游戏
     * @param msgId
     * @param packet
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleExitGameReq(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2);
public:
    /**
     * @brief 收到通知，玩家离开游戏
     * @param msgId
     * @param packet
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleNotifyPlayerLeaveGame(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2);
};