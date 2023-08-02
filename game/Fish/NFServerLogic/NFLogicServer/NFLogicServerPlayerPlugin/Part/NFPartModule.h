// -------------------------------------------------------------------------
//    @FileName         :    NFPartModule.h
//    @Author           :    gaoyi
//    @Date             :    22-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFPartModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerLogicMessage/ServerInternal.pb.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFPartModule : public NFIDynamicModule
{
public:
    NFPartModule(NFIPluginManager *p);

    virtual ~NFPartModule();
public:
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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2) override;

    /** 处理服务器之间的rpc，这里负责转发玩家part的rpc
     * @brief
     * @param msgId
     * @param pRequest
     * @param pRespone
     * @param param1
     * @param param2
     * @return
     */
    virtual int OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message* pRequest, google::protobuf::Message* pRespone, uint64_t param1, uint64_t param2) override;
public:
    virtual int RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo);
    virtual int RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo);

    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    int AddPartRpcService(BaseType* pBase, int (BaseType::*handleRecieve)(RequestType* pRequest, ResponeType* pRespone), uint32_t partType, bool createCo = false)
    {
        CHECK_EXPR_ASSERT(msgId < m_rpcMsgToPartMap.size(), -1, "");
        AddRpcService<msgId, RequestType, ResponeType>(NF_ST_LOGIC_SERVER, createCo);
        m_rpcMsgToPartMap[msgId].first = partType;
        m_rpcMsgToPartMap[msgId].second = new NFCDynamicRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return 0;
    }

private:
    std::vector<uint32_t> m_clientMsgToPartMap;
    std::vector<uint32_t> m_serverMsgToPartMap;
    std::vector<std::pair<uint32_t, NFIDynamicRpcService*>> m_rpcMsgToPartMap;
};