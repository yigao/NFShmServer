// -------------------------------------------------------------------------
//    @FileName         :    NFSnsPartModule.h
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsPartModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"


class NFSnsPartModule : public NFIDynamicModule
{
public:
    NFSnsPartModule(NFIPluginManager *p);

    virtual ~NFSnsPartModule();

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
    virtual int RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo);
    virtual int RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo);
private:
    std::vector<uint32_t> m_clientMsgToPartMap;
    std::vector<uint32_t> m_serverMsgToPartMap;
};