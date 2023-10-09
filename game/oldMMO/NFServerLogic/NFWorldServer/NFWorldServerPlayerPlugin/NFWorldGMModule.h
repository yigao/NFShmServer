// -------------------------------------------------------------------------
//    @FileName         :    NFGMModule.h
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFGMModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFLogicCommon/NFComTypeDefine.h"

class NFWorldGMModule : public NFIDynamicModule
{
public:
    explicit NFWorldGMModule(NFIPluginManager *p);

    virtual ~NFWorldGMModule();

    virtual bool Awake() override;
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
     * @brief 处理GM信息
     * @param msgId
     * @param packet
     * @param unlinkId
     * @param uid
     * @return
     */
    int OnHandleClientGMMsg(uint32_t msgId, NFDataPackage& packet, uint64_t unlinkId, uint64_t uid);

    /**
     * @brief
     * @param uid
     * @param roleId
     * @param cmd
     * @param vecarg
     * @return
     */
    int GMMsgHandler(uint64_t uid, uint64_t roleId, const std::string& cmd, const VEC_STRING& vecarg);
};