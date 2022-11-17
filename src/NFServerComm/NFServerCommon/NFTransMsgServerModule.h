// -------------------------------------------------------------------------
//    @FileName         :    NFTransMsgServerModule.h
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransMsgServerModule
//
// -------------------------------------------------------------------------

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

/**
 * @brief 服务器类似NFProxyServer,NFProxyAgentServer,NFRouteAgentServer，实现类似连接NFMasterServer等功能
 */
class NFTransMsgServerModule : public NFIDynamicModule
{
public:
    NFTransMsgServerModule(NFIPluginManager *p, NF_SERVER_TYPES serverType) : NFIDynamicModule(p), m_serverType(serverType)
    {
        m_connectMasterServer = true;
    }

    virtual ~NFTransMsgServerModule()
    {

    }

    /**
     * @brief 处理定时器
     * @param nTimerID
     */
    virtual void OnTimer(uint32_t nTimerID) override;

    /**
     * @brief 响应注册事件
     * @param nEventID
     * @param nSrcID
     * @param bySrcType
     * @param message
     * @return
     */
    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message* pMessage) override;
public:
    int BindServer();
    int ConnectMasterServer();
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
    bool IsConnectMasterServer() const;

    void SetConnectMasterServer(bool connectMasterServer);
private:
    NF_SERVER_TYPES m_serverType;
    bool m_connectMasterServer;
};

