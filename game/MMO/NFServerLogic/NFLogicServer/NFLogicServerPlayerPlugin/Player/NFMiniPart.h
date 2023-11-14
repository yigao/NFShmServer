// -------------------------------------------------------------------------
//    @FileName         :    NFMiniPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMiniPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

#define MAX_ARENA_CHALL_RESULT_NUM 50

enum HangUpDropItem
{
    HANG_UP_DROP_NORMAL_TYPE = 1, //1为普通类型道具抽取库
    HANG_UP_DROP_FUSHI_TYPE = 2, //2为极品符石道具抽取库
};

/**
 * @brief 冥想数据
 */
class HangUpData
{
public:
    HangUpData()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    ~HangUpData()
    {
    
    }
    
    int CreateInit()
    {
        m_hangup_time = 0;		//离线到上线挂机时间
        m_login_surplus_hangup_time = 0;
        m_add_hangup_exp = 0;
        m_hangup_before_lv = 0;
        m_hangup_after_lv = 0;
        m_hangup_before_fight = 0;
        m_hangup_after_fight = 0;
        
        m_online_hangup_time = 0; //在线挂机时间
        m_add_online_hangup_exp = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
public:
    // 冥想数据
    int32_t m_hangup_time;		//离线到上线挂机时间
    int32_t m_login_surplus_hangup_time;
    uint64_t m_add_hangup_exp;
    int32_t m_hangup_before_lv;
    int32_t m_hangup_after_lv;
    uint64_t m_hangup_before_fight;
    uint64_t m_hangup_after_fight;
    MAP_INT64_INT32  m_dropItem;
    
    int32_t m_online_hangup_time; //在线挂机时间
    MAP_INT64_INT32  m_onlineDropItem; //在线挂机奖励
    uint64_t m_add_online_hangup_exp;
};

class NFMiniPart : public NFShmObjTemplate<NFMiniPart, EOT_LOGIC_PART_ID+PART_MINI, NFPart>
{
public:
    NFMiniPart();

    virtual ~NFMiniPart();

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
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);
    
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
    virtual int LoadFromDB(const proto_ff::RoleDBData& data);
    
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
    virtual int SaveDB(proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();
    virtual int OnLogin(proto_ff::PlayerInfoRsp& playerInfo);
    
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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * @brief 上线请求冥想数据
     * @return
     */
    int OnHandleLoginHangUpDataReq(uint32_t msgId, NFDataPackage &packet);
public:
    void SendHangupData();
private:
    /**
     * @brief 冥想数据
     */
    HangUpData m_hangUpData;
};