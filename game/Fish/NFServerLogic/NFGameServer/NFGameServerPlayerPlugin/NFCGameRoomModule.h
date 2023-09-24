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
#include "NFLogicCommon/NFIGameDeskImpl.h"
#include "NFLogicCommon/NFIGameRoomModule.h"


class NFCGameRoomModule : public NFIGameRoomModule
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
     * @brief
     * @param request
     * @param respone
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleChairCheckReq(proto_ff::ChairCheckReq& request, proto_ff::ChairCheckRsp& respone, uint64_t playerId, uint64_t param2);

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

    /**
     * @brief
     * @param request
     * @param respone
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleExitRoomReq(proto_ff::ExitRoomReq& request, proto_ff::ExitRoomRsp& respone, uint64_t playerId, uint64_t param2);

    /**
     * @brief
     * @param request
     * @param respone
     * @param playerId
     * @param param2
     * @return
     */
    int OnHandleRecomeReq(proto_ff::UserRecomeReq& request, proto_ff::UserRecomeRsp& respone, uint64_t playerId, uint64_t param2);
public:
    /**
     * @brief 注册创建桌子具体业务的函数
     * @param gameId
     * @param createFunc
     * @return
     */
    virtual int RegisterCreateDeskFunction(uint32_t gameId, const CreateDeskFunction& createFunc);

    /**
     * @brief 根据具体的游戏ID，创建游戏桌子
     * @param gameId
     * @return
     */
    virtual NFIGameDeskImpl* CreateDesk(uint32_t gameId);
public:
    /**
     * @brief 游戏注册客户端协议
     * @return
     */
    virtual bool RegisterClientMessage(uint32_t msgId);

    /**
     * @brief 游戏注册服务器协议
     * @param msgId
     * @return
     */
    virtual bool RegisterServerMessage(uint32_t msgId);

    /**
     * @brief 处理游戏客户端协议
     * @return
     */
    virtual int OnHandleRoomClientMessage(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 处理游戏服务器协议
     * @return
     */
    virtual int OnHandleRoomServerMessage(uint64_t unLinkId, NFDataPackage &packet);
private:
    std::unordered_map<uint32_t, CreateDeskFunction> m_deskCreateMap;
};
