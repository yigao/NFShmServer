// -------------------------------------------------------------------------
//    @FileName         :    NFLogicGMModule.h
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicGMModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "Player/NFPlayer.h"

class NFLogicGMModule : public NFIDynamicModule
{
public:
    explicit NFLogicGMModule(NFIPluginManager *p);

    virtual ~NFLogicGMModule();

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
public:
    int GetItem(NFPlayer* pPlayer, const std::vector<std::string>& args);
    //升到指定等级
    int UpgradeLevel(NFPlayer* pPlayer, const std::vector<std::string>& args);
    //增加经验
    int AddExp(NFPlayer* pPlayer, const std::vector<std::string>& args);
    //添加金币
    int AddGold(NFPlayer* pPlayer, const std::vector<std::string>& args);
    //添加钻石
    int AddDia(NFPlayer* pPlayer, const std::vector<std::string>& args);
    //添加绑钻
    int AddBdDia(NFPlayer* pPlayer, const std::vector<std::string>& args);
    //添加魔晶
    int AddMagic(NFPlayer* pPlayer, const std::vector<std::string>& args);
};