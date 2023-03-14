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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2) override;
public:
    virtual int RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType);
    virtual int RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType);
private:
    std::vector<uint32_t> m_clientMsgToPartMap;
    std::vector<uint32_t> m_serverMsgToPartMap;
};