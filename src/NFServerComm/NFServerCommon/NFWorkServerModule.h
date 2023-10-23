// -------------------------------------------------------------------------
//    @FileName         :    NFWorkServerModule.h
//    @Author           :    gaoyi
//    @Date             :    22-10-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorkServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFServerBindRpcService.h"
#include "NFCommPlugin/NFXPlugin/NFLuaScriptPlugin/NFCLuaScriptModule.h"

/**
 * @brief 业务服务器类似NFLogicServer,NFWorldServer,NFSnsServer，实现类似连接NFMasterServer,NFProxyAgentServer,NFRouteAgentServer等功能
 */
class NFWorkServerModule : public NFIDynamicModule
{
public:
    NFWorkServerModule(NFIPluginManager *p, NF_SERVER_TYPES serverType) : NFIDynamicModule(p), m_serverType(serverType)
    {
        m_connectMasterServer = true;
        m_connectRouteAgentServer = true;
        m_connectProxyAgentServer = true;
        m_checkStoreServer = false;
        m_checkWorldServer = false;
        m_checkCenterServer = false;
    }

    virtual ~NFWorkServerModule()
    {

    }

    /**
     * @brief 处理定时器
     * @param nTimerID
     */
    virtual int OnTimer(uint32_t nTimerID) override;

    /**
     * @brief 响应注册事件
     * @param nEventID
     * @param nSrcID
     * @param bySrcType
     * @param message
     * @return
     */
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;

public:
    NF_SERVER_TYPES GetServerType() const;

    void SetServerType(NF_SERVER_TYPES serverType);

    bool IsConnectMasterServer() const;

    void SetConnectMasterServer(bool connectMasterServer);

    bool IsConnectRouteAgentServer() const;

    void SetConnectRouteAgentServer(bool connectRouteAgentServer);

    bool IsConnectProxyAgentServer() const;

    void SetConnectProxyAgentServer(bool connectProxyAgentServer);

    bool IsCheckStoreServer() const;

    void SetCheckStoreServer(bool checkStoreServer);

    bool IsCheckWorldServer() const;

    void SetCheckWorldServer(bool checkWorldServer);

    bool IsCheckCenterServer() const;

    void SetCheckCenterServer(bool checkCenterServer);

public:
    int BindServer();

    int ConnectMasterServer();

    int InitLoadLua();
public:
    //////////////////////////////////////////////////////////Server服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief Server服务器连接事件，可以是网络/bus的连接事件
     * @param nEvent
     * @param unLinkId
     * @return
     */
    virtual int OnServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief 处理Server未注册的消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 处理Server服务器的连接掉线
     * @param unLinkId
     * @return
     */
    virtual int OnHandleServerDisconnect(uint64_t unLinkId);
    //////////////////////////////////////////////////////////Server服务器//////////////////////////////////////////////////////////////////
public:
    //////////////////////////////////////////////////////////NFMasterServer服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 链接Master服务器
     * @param xData
     * @return
     */
    virtual int ConnectMasterServer(const proto_ff::ServerInfoReport &xData);

    /**
     * @brief 注册Master服务器
     * @param serverState
     * @return
     */
    virtual int RegisterMasterServer(uint32_t serverState);

    /**
     * @brief 处理Master服务器链接事件
     * @param nEvent
     * @param unLinkId
     * @return
     */
    virtual int OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief 处理Master服务器未注册消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 接受来自MasterServer的其他服务器的报告
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerReportFromMasterServer(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 接受来自MasterServer的其他服务器的报告
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleOtherServerReportFromMasterServer(const proto_ff::ServerInfoReport &xData);

    /**
     * @brief 每隔一段时间向Master服务器发送自身信息
     * @return
     */
    virtual int ServerReportToMasterServer();
    //////////////////////////////////////////////////////////NFMasterServer服务器//////////////////////////////////////////////////////////////////
public:
    //////////////////////////////////////////////////////////NFProxyServer,NFProxyAgentServer 服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 收到NFProxyAgentServer服务器报告, 连接NFProxyAgentServer服务器
     * @param xData
     * @return
     */
    virtual int OnHandleProxyAgentServerReport(const proto_ff::ServerInfoReport &xData);

    /**
     * @brief 连接NFProxyAgentServer服务器网络事件处理
     * @param nEvent
     * @param unLinkId
     * @return
     */
    virtual int OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief 处理NFProxyAgentServer转发过来的未注册的协议, 协议来自客户端，以及NFPRoxyServer
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleProxyAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 注册自身信息到NFProxyAgentServer, 通过NFProxyAgentServer转发, 最终注册到NFProxyServer
     * @param unLinkId
     * @return
     */
    virtual int RegisterProxyAgentServer(uint64_t unLinkId);

    /**
     * @brief 受来自其他服务器的注册，这里主要是NFProxyServer注册, 通过NFProxyAgentServer转发
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnServerRegisterProcessFromProxyServer(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 处理来自NFProxyAgentServer转发的NFProxyServer注册
     * @param xData
     * @param unlinkId
     * @return
     */
    virtual int OnHandleProxyServerRegister(const proto_ff::ServerInfoReport &xData, uint64_t unlinkId);

    //////////////////////////////////////////////////////////NFProxyServer,NFProxyAgentServer 服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFStoreServer服务器//////////////////////////////////////////////////////////////////
    virtual int OnHandleStoreServerReport(const proto_ff::ServerInfoReport &xData);

    //////////////////////////////////////////////////////////NFStoreServer服务器//////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////NFWorldServer服务器//////////////////////////////////////////////////////////////////
    virtual int OnHandleWorldServerReport(const proto_ff::ServerInfoReport &xData);
    //////////////////////////////////////////////////////////NFCenterServer服务器//////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////NFCenterServer服务器//////////////////////////////////////////////////////////////////
    virtual int OnHandleCenterServerReport(const proto_ff::ServerInfoReport &xData);
    //////////////////////////////////////////////////////////NFWorldServer服务器//////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////NFRouteAgent服务器//////////////////////////////////////////////////////////////////
    /**
     * @brief 收到NFRouteAgentServer服务器报告, 连接NFRouteAgentServer服务器
     * @param xData
     * @return
     */
    virtual int OnHandleRouteAgentServerReport(const proto_ff::ServerInfoReport &xData);

    /**
     * @brief 注册自身信息到NFRouteAgentServer
     * @param unLinkId
     * @return
     */
    virtual int RegisterRouteAgentServer(uint64_t unLinkId);

    /**
     * @brief NFRouteAgentServer注册返回
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnRegisterRouteAgentServerRspProcess(uint64_t unLinkId, NFDataPackage &packet);

    /**
     * @brief 连接NFRouteAgentServer服务器网络事件处理
     * @param nEvent
     * @param unLinkId
     * @return
     */
    virtual int OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId);

    /**
     * @brief NFRouteAgentServer服务器未处理协议,协议来自别的内网服务器， 由NFRouteAgentServer,NFRouteServer转发
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleRouteAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet);
    //////////////////////////////////////////////////////////NFRouteAgent服务器//////////////////////////////////////////////////////////////////
protected:
    NF_SERVER_TYPES m_serverType;
    bool m_connectMasterServer;
    bool m_connectRouteAgentServer;
    bool m_connectProxyAgentServer;
    bool m_checkStoreServer;
    bool m_checkWorldServer;
    bool m_checkCenterServer;
};