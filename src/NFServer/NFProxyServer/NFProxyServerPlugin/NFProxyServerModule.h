// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#pragma once
#include "NFServerComm/NFServerCommon/NFIProxyServerModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include <NFComm/NFPluginModule/NFEventObj.h>
#include "NFComm/NFCore/NFCommMap.hpp"


class NFCProxyServerModule : public NFIProxyServerModule
{
public:
	explicit NFCProxyServerModule(NFIPluginManager* p);
	virtual ~NFCProxyServerModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual uint32_t GetClientMsgServer(uint32_t msgId) override;

public:
    /**
     * @brief 处理来自NFProxyAgentServer服务器的注册,有可能是NFProxyAgentServer的注册，也可能是NFProxyAgentServer转发的继承NFWorkServerModule的业务服务器的注册
     * @param unLinkId
     * @param packet
     * @return
     */
    int OnHandleServerRegisterFromProxyAgentServer(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理NFProxyAgentServer转发的继承NFWorkServerModule的业务服务器的注册
     * @param xData
     * @param unLinkId
     * @return
     */
    int OnHandleOtherWorkServerRegister(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);

    /**
     * @brief 处理NFProxyAgentServer服务器的注册
     * @param xData
     * @param unLinkId
     * @return
     */
    int OnHandleProxyAgentServerRegister(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId);

    /**
     * @brief 将自己注册NFPRoxyAgentServer,然后由NFProxyAgentServer转发到其他NFWorkServer业务服务器
     * @param unLinkId
     * @return
     */
    int RegisterProxyAgentServer(uint64_t unLinkId);

    ////////////////////////////////test send msg/////////////////////////////////////////////////
    int TestSendProxyMsgToOtherServer(uint64_t dstBusId);
    int OnHandleTestOtherSendMsg(uint64_t unLinkId, NFDataPackage& packet);
public:
    std::vector<uint32_t> m_clientMsgToServerMap;
};
