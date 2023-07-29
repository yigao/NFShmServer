// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorldPlayerMgr.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "ServerInternal.pb.h"

class NFCWorldPlayerModule : public NFIDynamicModule
{
public:
	explicit NFCWorldPlayerModule(NFIPluginManager* p);
	virtual ~NFCWorldPlayerModule();

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
    virtual int OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;
public:
    /**
     * @brief
     * @param request
     * @param respone
     * @return
     */
    int OnHandleRoomRegisterReq(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 玩家登录
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerLogin(proto_ff::Proto_PTWUserLoginReq& request, proto_ff::Proto_WTPPlayerLoginRsp& respone);

    /**
     * @brief 玩家重连
     * @param request
     * @param respone
     * @return
     */
    int OnRpcServicePlayerReconnect(proto_ff::PTWPlayerReconnectReq& request, proto_ff::WTPPlayerReconnctRsp& respone);

    /**
     * @brief 玩家掉线
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandlePlayerDisconnectMsg(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 玩家登出
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandlePlayerLogoutNotify(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief
     * @param playerId
     * @return
     */
    int NotifySnsPlayerLogout(uint64_t playerId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    int NotifyLogicPlayerLogout(uint64_t playerId);
};
