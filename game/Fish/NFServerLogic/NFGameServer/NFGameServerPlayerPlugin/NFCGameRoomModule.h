// -------------------------------------------------------------------------
//    @FileName         :    NFCGameRoomModule.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGameRoomModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFFishDynamicModule.h"

class NFCGameRoomModule : public NFFishDynamicModule
{
public:
    explicit NFCGameRoomModule(NFIPluginManager *p);

    virtual ~NFCGameRoomModule();

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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2) override;
public:
    /**
     * @brief 请求获得一个桌子和座位
     * @param request
     * @param respone
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleDeskListReq(proto_ff::DeskListReq& request, proto_ff::DeskListRsp& respone, uint64_t playerId, uint64_t param2);

    /**
     * @brief 请求进入游戏
     * @return
     */
    int OnHandleEnterGameReq(proto_ff::EnterGameReq& request, proto_ff::EnterGameRsp& respone, uint64_t playerId, uint64_t param2);

    /**
     * @brief 请求退出游戏
     * @return
     */
    int OnHandleExitGameReq(proto_ff::ExitGameReq& request, proto_ff::ExitGameRsp& respone, uint64_t playerId, uint64_t param2);
};
