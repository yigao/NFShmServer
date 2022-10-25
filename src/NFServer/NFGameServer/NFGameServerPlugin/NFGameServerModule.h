// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFIGameServerModule.h"

class NFCGameServerModule : public NFIGameServerModule
{
public:
    explicit NFCGameServerModule(NFIPluginManager *p);

    virtual ~NFCGameServerModule();

    virtual bool Awake() override;

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet) override;
public:
    //////////////////////////////////////////////////////////游戏战斗服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 游戏战斗服务器连接事件，可以是网络/bus的连接事件
     * @param nEvent
     * @param unLinkId
     * @return
     */
    int OnGameSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief 处理未注册的消息
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleGameOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理游戏服务器的连接掉线
     * @param unLinkId
     * @return
     */
    int OnHandleGameServerDisconnect(uint64_t unLinkId);
    //////////////////////////////////////////////////////////游戏战斗服务器//////////////////////////////////////////////////////////////////



    //////////////////////////////////////////////////////////NFMasterServer服务器//////////////////////////////////////////////////////////////////
	/**
	 * @brief 链接Master服务器
	 * @param xData
	 * @return
	 */
    int ConnectMasterServer(const proto_ff::ServerInfoReport& xData);

    /**
     * @brief 注册Master服务器
     * @param serverState
     * @return
     */
	int RegisterMasterServer(uint32_t serverState);

	/**
	 * @brief 处理Master服务器链接事件
	 * @param nEvent
	 * @param unLinkId
	 * @return
	 */
	int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);

	/**
	 * @brief 处理Master服务器未注册消息
	 * @param unLinkId
	 * @param packet
	 * @return
	 */
	int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

	/**
	 * @brief 每隔一段时间向Master服务器发送自身信息
	 * @return
	 */
    int ServerReport();

    /**
     * @brief 接受来自MasterServer的其他服务器的报告
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleServerReportFromMasterServer(uint64_t unLinkId, NFDataPackage& packet);
    //////////////////////////////////////////////////////////NFMasterServer服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFProxyServer,NFProxyAgentServer 服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief NFGameServer连接NFProxyAgentServer服务器, 不连接NFProxyServer
     */

    /**
     * @brief 收到NFProxyAgentServer服务器报告, 连接RouteAgent服务器
     * @param xData
     * @return
     */
    int OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData);

    /**
     * @brief 注册自身信息到NFProxyAgentServer, 通过NFProxyAgentServer转发, 最终注册到NFProxyServer
     * @param unLinkId
     * @return
     */
    int RegisterProxyAgentServer(uint64_t unLinkId);

    /**
     * @brief  连接NFProxyAgentServer服务器网络事件处理
     * @param nEvent
     * @param unLinkId
     * @return
     */
    int OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief NFProxyAgentServer服务器未处理协议
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleProxyAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 接受来自其他服务器的注册，这里主要是NFProxyServer注册, 通过NFProxyAgentServer转发
     * @param unLinkId
     * @param packet
     * @return
     */
	int OnServerRegisterProcessFromProxyAgent(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 网关服务器注册协议回调, 处理来自NFProxyAgentServer的NFProxyServer注册
     * @param xData
     * @param unlinkId
     * @return
     */
    int OnHandleProxyRegister(const proto_ff::ServerInfoReport &xData, uint64_t unlinkId);

    //////////////////////////////////////////////////////////NFProxyServer,NFProxyAgentServer 服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFStoreServer服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 收到StoreServer服务器报告
     * @param xData
     * @return
     */
	int OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData);
    //////////////////////////////////////////////////////////NFStoreServer服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFRouteAgent服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 收到NFRouteAgentServer服务器报告, 连接NFRouteAgentServer服务器
     * @param xData
     * @return
     */
	int OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData);

    /**
     * @brief 注册自身信息到NFRouteAgentServer
     * @param unLinkId
     * @return
     */
	int RegisterRouteAgentServer(uint64_t unLinkId);

    /**
     * @brief NFRouteAgentServer注册返回
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 连接NFRouteAgentServer服务器网络事件处理
     * @param nEvent
     * @param unLinkId
     * @return
     */
	int OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief NFRouteAgentServer服务器未处理协议
     * @param unLinkId
     * @param packet
     * @return
     */
	int OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    //////////////////////////////////////////////////////////NFRouteAgent服务器//////////////////////////////////////////////////////////////////





    int OnTestProxyServerMsg(uint64_t unLinkId, NFDataPackage& packet);
    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestOtherServerToWorldServer();
    int OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet);
};
