// -------------------------------------------------------------------------
//    @FileName         :    NFAchievementPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAchievementPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFAchievementPart : public NFShmObjTemplate<NFAchievementPart, EOT_LOGIC_PART_ID + PART_ACHIEVEMENT, NFPart>
{

public:
    NFAchievementPart();
    
    virtual ~NFAchievementPart();
    
    int CreateInit();
    
    int ResumeInit();

public:
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData);
    
    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();

public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData& data) { return 0; }
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData& data) { return 0; }
    
    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData& dbData) { return 0; }
    
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }
    
    virtual int OnLogin(proto_ff::PlayerInfoRsp& playerInfo) { return 0; }
    
    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }
    
    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }
    
    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }
    
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }
    
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }
    
    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto& outproto) { return 0; }

public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet);
    
    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet);
public:
    /**
     * @brief
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleAchievementInfoReq(uint32_t msgId, NFDataPackage& packet);
public:
    void SendAchievementInfo();
public:
    void OnCommonAddNum(int32_t num, int32_t eventType) { }
    
    void OnCommonAddNum(int32_t num, int32_t param1, int32_t eventType) { }
    
    void OnCommonAddNumWithLess(int32_t num, int32_t param1, int32_t eventType) { }
    
    void OnCommonAddNumWithLess(int32_t num, int32_t param1, int32_t param2, int32_t eventType) { }
    
    void OnCommonAddNumWithLess(int32_t num, int32_t param1, int32_t param2, int32_t param3, int32_t eventType) { }
    
    void OnCommonFinishNum(int32_t num, int32_t eventType) { }
    
    void OnCommonFinishNum(int32_t num, int32_t param, int32_t eventType) { }
    
    void OnCommonFinishNum(int32_t num, int32_t param1, int32_t param2, int32_t eventType) { }
    
    void OnCommonFinishNum(int32_t num, int32_t param1, int32_t param2, int32_t param3, int32_t eventType) { }
    
    void OnCommonFinishNumWithLess(int32_t num, int32_t param, int32_t eventType) { }
    
    void OnCommonFinishNumWithLess(int32_t num, int32_t param1, int32_t param2, int32_t eventType) { }
    
    void OnCommonFinishNumWithLess(int32_t num, int32_t param1, int32_t param2, int param3, int32_t eventType) { }
    
    void OnCommonClear(int32_t eventType) { }
private:
    std::unordered_map<int64_t, proto_ff::OneAchievementData> m_achMap;
    std::unordered_map<int64_t, proto_ff::OneAchievementData> m_achTotalMap;
};