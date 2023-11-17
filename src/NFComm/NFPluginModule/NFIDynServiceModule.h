// -------------------------------------------------------------------------
//    @FileName         :    NFIDynServiceModule.h
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDynServiceModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"


class NFIDysServiceModule : public NFIDynamicModule
{
public:
    NFIDysServiceModule(NFIPluginManager *p);

    virtual ~NFIDysServiceModule();

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

    /** 处理服务器之间的rpc，这里负责转发玩家part的rpc
     * @brief
     * @param msgId
     * @param pRequest
     * @param pRespone
     * @param param1
     * @param param2
     * @return
     */
    virtual int OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1, uint64_t param2) override;
public:
    virtual int RegisterClientMessage(NF_SERVER_TYPES serverType, uint32_t nMsgID, uint32_t serviceId, bool createCo);
    virtual int RegisterServerMessage(NF_SERVER_TYPES serverType, uint32_t nMsgID, uint32_t serviceId, bool createCo);

    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    int AddServiceRpc(NF_SERVER_TYPES serverType, BaseType* pBase, int (BaseType::*handleRecieve)(RequestType& request, ResponeType& respone), uint32_t serviceId, bool createCo = false)
    {
        CHECK_EXPR_ASSERT(msgId < m_rpcMsgToServiceMap.size(), -1, "");
        AddRpcService<msgId, RequestType, ResponeType>(serverType, createCo);
        m_rpcMsgToServiceMap[msgId].first = serviceId;
        m_rpcMsgToServiceMap[msgId].second = new NFCDynamicRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return 0;
    }
protected:
    std::vector<uint32_t> m_clientMsgToServiceMap;
    std::vector<uint32_t> m_serverMsgToServiceMap;
    std::vector<std::pair<uint32_t, NFIDynamicRpcService*>> m_rpcMsgToServiceMap;
};