// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/Item/NFDressEquip.hpp>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFEquipSlot : public NFEquipSlotInfo
{
public:
    NFEquipSlot()
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
    
    ~NFEquipSlot()
    {
    
    }
    
    int CreateInit()
    {
        m_stronglv = 0;
        m_total_score = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool ReadFromPB(const proto_ff::EquipSlotInfo& proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::ReadFromPB(proto), false, "");
        m_stronglv = proto.stronglv();
        m_total_score = proto.total_score();
        return true;
    }
    
    virtual bool WriteToPB(proto_ff::EquipSlotInfo& proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::WriteToPB(proto), false, "");
        proto.set_stronglv(m_stronglv);
        proto.set_total_score(m_total_score);
        return true;
    }

public:
    uint32_t m_stronglv;
    uint32_t m_total_score;
};

class NFEquipPart : public NFShmObjTemplate<NFEquipPart, EOT_LOGIC_PART_ID + PART_EQUIP, NFPart>
{
public:
    typedef NFDressEquipInfo<NFEquip, NFEquipSlot, proto_ff::EEquipPos_limit - 1, proto_ff::EEquipPos_m_weapon> NFEquipVec;
    
    struct stEquipLvAttrInfo
    {
        int32_t type;
        int32_t id;
    };
public:
    NFEquipPart();
    
    virtual ~NFEquipPart();
    
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
    virtual int OnLogin();
    
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
     * @brief 发送所有装备
     */
    void SendAllEquip();
    void SendLvAttr();
public:
    int32_t GetStrongLvNum(int32_t level) { return 0; }

public:
    NFEquipVec& GetEquip() { return m_equips; }
    
    const NFEquipVec& GetEquip() const { return m_equips; }

private:
    NFEquipVec m_equips;
    std::map<int32_t, stEquipLvAttrInfo> m_lvAttr;                        //type->等级加成属性
    uint32_t m_stoveLevel;                               //熔炉等级
    uint64_t m_stoveExp;                               //熔炉经验
    MAP_INT32_INT64 m_mapStoveAttr;//熔炉带来的属性
};