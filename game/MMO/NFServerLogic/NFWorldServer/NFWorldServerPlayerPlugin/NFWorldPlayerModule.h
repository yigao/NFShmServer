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

    //添加离线uid和clientid的映射
    void AddLogoutClientId(uint32_t uid, uint32_t clientid);

    //移除离线uid和clientid的映射
    void DelLogoutClientId(uint32_t uid);
private:
    /**
     * @brief NFILuaModule
     */
    NFILuaLoader m_luaModule;
};
