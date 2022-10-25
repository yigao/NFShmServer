// -------------------------------------------------------------------------
//    @FileName         :    NFCLoginServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCLoginServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServerComm/NFServerCommon/NFILogicServerModule.h"

class NFCLogicServerModule : public NFILogicServerModule
{
public:
    explicit NFCLogicServerModule(NFIPluginManager *p);

    virtual ~NFCLogicServerModule();

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
    //////////////////////////////////////////////////////////LogicServer服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief LogicServer服务器连接事件，可以是网络/bus的连接事件
     * @param nEvent
     * @param unLinkId
     * @return
     */
    int OnLogicServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief 处理LogicServer未注册的消息
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleLogicServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理LogicServer服务器的连接掉线
     * @param unLinkId
     * @return
     */
    int OnHandleLogicServerDisconnect(uint64_t unLinkId);
    //////////////////////////////////////////////////////////LogicServer服务器//////////////////////////////////////////////////////////////////

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
    int OnMasterSocketEvent(eMsgType nEvent,uint64_t unLinkId);

    /**
     * @brief 处理Master服务器未注册消息
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 接受来自MasterServer的其他服务器的报告
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleServerReportFromMasterServer(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 每隔一段时间向Master服务器发送自身信息
     * @return
     */
    int ServerReportToMasterServer();
    //////////////////////////////////////////////////////////NFMasterServer服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFProxyServer,NFProxyAgentServer 服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 收到NFProxyAgentServer服务器报告, 连接NFProxyAgentServer服务器
     * @param xData
     * @return
     */
    int OnHandleProxyAgentServerReport(const proto_ff::ServerInfoReport& xData);

    /**
     * @brief 连接NFProxyAgentServer服务器网络事件处理
     * @param nEvent
     * @param unLinkId
     * @return
     */
    int OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief 处理NFProxyAgentServer转发过来的未注册的协议, 协议来自客户端，以及NFPRoxyServer
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleProxyAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 注册自身信息到NFProxyAgentServer, 通过NFProxyAgentServer转发, 最终注册到NFProxyServer
     * @param unLinkId
     * @return
     */
    int RegisterProxyAgentServer(uint64_t unLinkId);

    /**
     * @brief 受来自其他服务器的注册，这里主要是NFProxyServer注册, 通过NFProxyAgentServer转发
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnServerRegisterProcessFromProxyServer(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理来自NFProxyAgentServer转发的NFProxyServer注册
     * @param xData
     * @param unlinkId
     * @return
     */
    int OnHandleProxyServerRegister(const proto_ff::ServerInfoReport &xData, uint64_t unlinkId);

    //////////////////////////////////////////////////////////NFProxyServer,NFProxyAgentServer 服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFStoreServer服务器//////////////////////////////////////////////////////////////////
	int OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData);
    //////////////////////////////////////////////////////////NFStoreServer服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFRouteAgent服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 收到NFRouteAgentServer服务器报告, 连接NFRouteAgentServer服务器
     * @param xData
     * @return
     */
    int OnHandleRouteAgentServerReport(const proto_ff::ServerInfoReport& xData);

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
    int OnRegisterRouteAgentServerRspProcess(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 连接NFRouteAgentServer服务器网络事件处理
     * @param nEvent
     * @param unLinkId
     * @return
     */
    int OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief NFRouteAgentServer服务器未处理协议,协议来自别的内网服务器， 由NFRouteAgentServer,NFRouteServer转发
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleRouteAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet);
    //////////////////////////////////////////////////////////NFRouteAgent服务器//////////////////////////////////////////////////////////////////



    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestOtherServerToWorldServer();
    int OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet);
};