// -------------------------------------------------------------------------
//    @FileName         :    NFIWorldPlayerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWorldPlayerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "ServerInternal.pb.h"
#include "DBProto.pb.h"
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
     * @brief 通知客户端掉线
     * @param msgId
     * @param packet
     * @param unlinkId
     * @param uid
     * @return
     */
    int OnHandleClientDisconnect(uint32_t msgId, NFDataPackage& packet, uint64_t unlinkId, uint64_t uid);

    /**
     * @brief 处理登录协议
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleClientLogin(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 创造角色
     * @param msgId
     * @param packet
     * @param uid
     * @param param2
     * @return
     */
    int OnHandleCreateRole(uint32_t msgId, NFDataPackage& packet, uint64_t uid, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param uid
     * @param roleId
     * @return
     */
    int OnHandleEnterGame(uint32_t msgId, NFDataPackage& packet, uint64_t uid, uint64_t param2);
public:
    /**
     * @brief logic msg
     */

    /**
     * @brief 获取角色列表
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleLogicGetRoleListRsp(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param charDBBaseInfo
     * @param charSimpleInfo
     * @return
     */
    int CharDBToCharSimpleDB(const proto_ff::RoleDBData& charDBBaseInfo, proto_ff::LoginRoleProto& charSimpleInfo);

    /**
     * @brief 处理逻辑服务器创建角色返回
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleLogicCreateRoleRsp(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 处理逻辑登陆返回
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleLogicLoginRsp(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 处理Sns服务器登陆返回
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleSnsLoginRsp(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleGameRegisterMapReq(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleEnterSceneReq(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);
public:
      /**
       * @brief 通知网关离开游戏
       * @param pPlayer
       * @param flag
       * @return
       */
    int NotifyGateLeave(uint64_t proxyId, uint64_t clientId, proto_ff::LOGOUT_TYPE flag);

    /**
     * @brief 通知ProxyServer玩家服务器的busId改变
     * @param pPlayer
     * @param serverType
     * @param busId
     * @return
     */
    int NotifyGateChangeServerBusId(NFWorldPlayer* pPlayer, uint32_t serverType, uint32_t busId);

    /**
     * @brief 通知LogicServer玩家掉线
     * @param pPlayer
     * @param reason
     * @return
     */
    int NotifyOtherServerPlayerDisconnect(NFWorldPlayer* pPlayer, uint32_t reason);
private:
    /**
     * @brief NFILuaModule
     */
    NFILuaLoader m_luaModule;
};
