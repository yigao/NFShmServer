// -------------------------------------------------------------------------
//    @FileName         :    NFDeityPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDeityPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "DescStore/AvatarChangeDesc.h"
#include "NFLogicCommon/Item/NFDressEquip.hpp"
#include "DescStore/AttributeAttributeDesc.h"
#include "DescStore/EquipStrongDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/AvatarValueDesc.h"
#include "DescStore/AvatarDisplayDesc.h"
#include "DescStore/AvatarEquipsuitDesc.h"
#include "DescStore/AvatarBattleslotDesc.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "ClientServer.pb.h"
#include "DescStoreEx/EquipDescEx.h"

#define MAX_DEITY_BATTLE_SLOT_NUM 4
#define MAX_DEITY_SKILL_NUM 5
#define MAX_DEITY_FRAGMENT_NUM 3

class NFDeityEquipSlot : public NFEquipSlotInfo
{
public:
    NFDeityEquipSlot()
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
    
    ~NFDeityEquipSlot()
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
    
    virtual bool ReadFromPB(const proto_ff::EquipSlotInfo &proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::ReadFromPB(proto), false, "");
        m_stronglv = proto.stronglv();
        m_total_score = proto.total_score();
        return true;
    }
    
    virtual bool WriteToPB(proto_ff::EquipSlotInfo &proto)
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

struct DeityBattleSlot : public NFRawShmObj
{
public:
    DeityBattleSlot()
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
    
    ~DeityBattleSlot()
    {
    
    }
    
    int CreateInit()
    {
        m_curState = 0;
        m_deityId = 0;
        m_id = 0;
        m_enterWarTime = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    void ReadFromPB(const proto_ff::DeityBattleSlotData &data)
    {
        m_curState = data.cur_state();
        m_deityId = data.deity_id();
        m_id = data.id();
        m_enterWarTime = data.enter_war_time();
    }
    
    void WriteToPB(proto_ff::DeityBattleSlotData *pData) const
    {
        pData->set_id(m_id);
        pData->set_cur_state(m_curState);
        pData->set_deity_id(m_deityId);
        pData->set_enter_war_time(m_enterWarTime);
    }
    
    uint64_t GetLeftWarTime() const
    {
        if (m_curState == proto_ff::DEITY_BATTLE_SLOT_STATE_USING && m_deityId > 0 && m_enterWarTime > 0)
        {
            auto pFantasyCfg = AvatarChangeDesc::Instance()->GetDesc(m_deityId);
            if (pFantasyCfg == NULL)
            {
                return 0;
            }
            
            int64_t allTime = pFantasyCfg->m_avatarCD;
            int64_t useTime = NFTime::Now().UnixSec() - m_enterWarTime;
            if (useTime >= allTime)
            {
                return 0;
            }
            else
            {
                return allTime - useTime;
            }
        }
        
        return 0;
    }
    
    virtual int OnTimer(int timeId, int callcount);
    
    uint32_t m_curState;
    int64_t m_deityId;
    uint32_t m_id;
    int64_t m_enterWarTime;
};

#define FANTASY_DEITY_MAX_SKILL_NUM 5

struct FantasyDeityData
{
public:
    FantasyDeityData()
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
    
    ~FantasyDeityData()
    {
    
    }
    
    int CreateInit()
    {
        m_id = 0;
        m_level = 0;
        m_star = 0;
        m_exp = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    bool ReadFromPB(const proto_ff::DeityFantasyData &data)
    {
        m_id = data.fantasy_id();
        m_level = data.fantasy_lev();
        m_exp = data.fantasy_lev_exp();
        m_star = data.fantasy_star();
        for (int i = 0; i < (int) data.skill_data_size(); i++)
        {
            m_mapSkill[data.skill_data(i).skill_id()] = data.skill_data(i).skill_state();
        }
        
        for (int32_t i = 0; i < data.equip_data().infos_size(); i++)
        {
            const proto_ff::EquipInfo &equipProto = data.equip_data().infos(i);
            int32_t pos = equipProto.slot().slot_pos();
            CHECK_EXPR(m_equips.ValidPos(pos), false, "pos:%d error", pos);
            auto pDressEquip = m_equips.GetEquip(pos);
            CHECK_EXPR(pDressEquip, false, "pos:%d not find equip", pos);
            pDressEquip->ReadFromPB(equipProto);
        }
        
        for (int i = 0; i < (int) data.equip_suit_data_size(); i++)
        {
            const ::proto_ff::DeityEquipSuitData &suitData = data.equip_suit_data(i);
            m_equipSuit.emplace(suitData.id(), suitData.state());
        }
        return true;
    }
    
    bool WriteToPB(NFPlayer *pMaster, proto_ff::DeityFantasyData *pData)
    {
        pData->set_fantasy_id(m_id);
        pData->set_fantasy_lev(m_level);
        pData->set_fantasy_lev_exp(m_exp);
        pData->set_fantasy_star(m_star);
        for (auto iter = m_mapSkill.begin(); iter != m_mapSkill.end(); iter++)
        {
            auto pSkillData = pData->add_skill_data();
            if (pSkillData)
            {
                pSkillData->set_skill_id(iter->first);
                pSkillData->set_skill_state(iter->second);
            }
        }
        
        for (int32_t i = proto_ff::EDeityEquipPos_start; i < proto_ff::EDeityEquipPos_start + proto_ff::EDeityEquipPos_limit; i++)
        {
            auto pDressEquip = m_equips.GetEquip(i);
            CHECK_EXPR(pDressEquip, false, "");
            pDressEquip->WriteToPB(*pData->mutable_equip_data()->add_infos());
        }
        
        for (auto iter = m_equipSuit.begin(); iter != m_equipSuit.end(); iter++)
        {
            auto pSuit = pData->add_equip_suit_data();
            pSuit->set_id(iter->first);
            pSuit->set_state(iter->second);
        }
        
        pData->set_fantasy_fight(GetFightValue(pMaster));
        return true;
    }
    
    void calcDressAttr(NFPlayer *pMaster, MAP_INT32_INT64 &outAttr)                        //计算身上穿戴的属性
    {
        int32_t lv = pMaster->GetAttr(proto_ff::A_LEVEL);
        MAP_INT32_INT32 partAttr;
        for (int i = 0; i < (int) m_equips.m_equips.size(); i++)
        {
            NFItem *pE = &m_equips.m_equips[i].m_equip;
            pE->GetAllAttr(partAttr, lv);
            
            for (auto &e1 : partAttr)
            {
                outAttr[e1.first] += e1.second;
            }
            partAttr.clear();
        }
    }
    
    void calcStrongAttr(MAP_INT32_INT64 &outAttr)                        //计算强化属性加成
    {
        for (int i = 0; i < (int) m_equips.m_equips.size(); i++)
        {
            NFItem *pE = &m_equips.m_equips[i].m_equip;
            CHECK_CONTINUE(pE->GetItemID() > 0);
            auto pEquipCfg = pE->GetEquipCfg();
            CHECK_EXPR_CONTINUE(pE, "")
            int32_t slotLv = m_equips.m_equips[i].m_slot.m_stronglv;
            CHECK_EXPR_CONTINUE(slotLv != 0, "");
            
            int32_t pos = pEquipCfg->m_position;
            int32_t wearQuality = pEquipCfg->m_wearQuality;
            stEquipStrongCfg* pEquipStrongCfg = EquipDescEx::Instance()->GetStrongCfg(EQUIP_STRONG_ID(pos,wearQuality));
            CHECK_EXPR_CONTINUE(pEquipStrongCfg, "");
            
            for (auto& e1 : pEquipStrongCfg->attr)
            {
                outAttr[e1.attrId] += e1.param0 * slotLv * slotLv + e1.param1 * slotLv + e1.param2;
            }
        }
    }
    
    void calcSuitAttr(MAP_INT32_INT64 &outAttr)                        //计算强化属性加成
    {
        for (auto iter = m_equipSuit.begin(); iter != m_equipSuit.end(); iter++)
        {
            if (iter->second == proto_ff::EDeityEquipSuitStatus_ACTIVE)
            {
                auto pCfgInfo = AvatarEquipsuitDesc::Instance()->GetDesc(iter->first);
                if (pCfgInfo)
                {
                    for (int i = 0; i < (int) pCfgInfo->m_Attribute.size(); i++)
                    {
                        auto &attr = pCfgInfo->m_Attribute[i];
                        if (attr.m_type > 0 && attr.m_value > 0)
                        {
                            outAttr[attr.m_type] += attr.m_value;
                        }
                    }
                }
            }
        }
    }
    
    void calcAdvanceAttr(MAP_INT32_INT64 &outAttr)
    {
        auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(m_id);
        if (pFantasyInfo)
        {
            ProcessAdvanceAttr(pFantasyInfo->m_UpLvType, m_level, outAttr);
            ProcessAdvanceAttr(pFantasyInfo->m_starUpAttributeId, m_star, outAttr);
        }
    }
    
    bool ProcessAdvanceAttr(int32_t upLvType, int32_t level, MAP_INT32_INT64 allAttr)
    {
        auto pCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(upLvType, level);
        CHECK_EXPR(pCfg, false, "upLvType:{} level:{}", upLvType, level);
        for (int i = 0; i < (int) pCfg->m_Attribute.size(); i++)
        {
            int nAttrId = pCfg->m_Attribute.at(i).m_type;
            if (nAttrId > 0)
            {
                int64_t nAttrValue = pCfg->m_Attribute.at(i).m_value;
                allAttr[nAttrId] += nAttrValue;
            }
        }
        
        return true;
    }
    
    double GetFightValue(NFPlayer *pMaster)
    {
        double nFightTotal = 0;
        MAP_INT32_INT64 allAttr;
        
        //计算身上的装备属性
        MAP_INT32_INT64 advnceAttr;
        calcAdvanceAttr(advnceAttr);
        MergeAttr(advnceAttr, allAttr);
        
        //计算身上的装备属性
        MAP_INT32_INT64 dressAttr;
        calcDressAttr(pMaster, dressAttr);
        MergeAttr(dressAttr, allAttr);
        
        //计算强化加成
        MAP_INT32_INT64 strongAttr;
        calcStrongAttr(strongAttr);
        MergeAttr(strongAttr, allAttr);
        
        //计算suit加成
        MAP_INT32_INT64 suitAttr;
        calcSuitAttr(suitAttr);
        MergeAttr(suitAttr, allAttr);
        
        for (auto &e : allAttr)
        {
            auto pCfg = AttributeAttributeDesc::Instance()->GetDesc(e.first);
            if (pCfg)
            {
                nFightTotal += e.second * pCfg->m_power;
            }
        }
        
        return nFightTotal;
    }
    
    void MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst)
    {
        for (auto &e : src)
        {
            dst[e.first] += e.second;
        }
    }
    
    uint64_t m_id;
    uint32_t m_level;
    uint64_t m_exp;
    uint32_t m_star;
    NFShmHashMap<uint64_t, uint32_t, FANTASY_DEITY_MAX_SKILL_NUM> m_mapSkill;        //技能数据
public:
    NFDressEquipInfo<NFDeityEquip, NFDeityEquipSlot, proto_ff::EDeityEquipPos_limit, proto_ff::EDeityEquipPos_start> m_equips;                                    //已穿戴的装备
    NFShmHashMap<uint64_t, uint32_t, MAX_AVATAR_EQUIPSUIT_NUM> m_equipSuit;
};

class NFDeityPart : public NFShmObjTemplate<NFDeityPart, EOT_LOGIC_PART_ID + PART_DEITY, NFPart>
{
public:
    NFDeityPart();
    
    virtual ~NFDeityPart();
    
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
    
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData &data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData &data);
    
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
    virtual int OnLogin() { return 0; }
    
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo) { return 0; }
    
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
    virtual int DailyZeroUpdate();
    
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
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto &outproto);
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
    void ActiveDefaultDeity(bool bSync);
    const proto_ff_s::E_AvatarDisplay_s* GetDefaultDeityDisplay();
    void ActiveDefaultBattleSlot();
    int GetSkillLev(int64_t skillId);
    void SetSkillInfo(int64_t skillId, uint32_t lev);
    void checkBattleSlot(uint32_t lev);
public:
    void SendDeityInfo();
    void SendDeaityFantasyInfo();
public:
public:
    bool ProcessAdvanceAttr(MAP_INT32_FLOAT& outAttr);
    bool calcValueAttr(int32_t upLvType, int32_t level, MAP_INT32_FLOAT& outAttr);
    bool AddFragmentAttr(MAP_INT32_FLOAT& outAttr);
    bool AddFragmentAttr(int64_t fragmentId, int32_t nTimes, MAP_INT32_FLOAT& outAttr);
    int64_t GetFightValue();
    int32_t CalFantasyLevelNeedItemNum(uint32_t type, uint32_t lev, int32_t addExp);
public:
    void calcAttr(bool sync);
    void calcDeityAttr(MAP_INT32_INT64& outAttr);
    void MergeAttr(const MAP_INT32_INT64& src, MAP_INT32_INT64& dst);
    void PrintAttr(const MAP_INT32_INT64& attr);
    void calcFantasyAttr(MAP_INT32_INT64& outAttr);						//计算身上穿戴的属性
    bool IsSpecAttr(int32_t spec_attrid);          //是否是特殊属性ID
    int32_t GetComAttrBySpec(int32_t spec_attrid);
public:
    int32_t CalNeedItemNum(int32_t type, uint32_t lev, int32_t addExp);
public:
    int64_t GetCurEnterWarDeity();
public:
    /**
     * 天神信息
     * @param data
     * @param len
     */
    int OnHandleDeityInfoReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神升级请求
     * @param data
     * @param len
     */
    int OnHandleDeityLevelUpReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神出战
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyBattleReq(uint32_t msgId, NFDataPackage &packet);
    int DeityFantasyBattle(uint32_t fantasyId, uint32_t battleSlot);
    
    /**
     * 天神退战
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyQuitBattleReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神神力使用
     * @param data
     * @param len
     */
    int OnHandleDeityFragmentUseReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神幻化信息
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyInfoReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神幻化激活
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyActiveReq(uint32_t msgId, NFDataPackage &packet);
    int ActiveDeityFantasy(uint32_t fantasyId);
    
    /**
     * 天神幻化升级
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyLevelUpReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神幻化升星
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyStarupReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 客户端主动解锁天神战斗槽位
     * @param data
     * @param len
     */
    int OnHandleDeityUnlockBattleSlotReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神参战
     * @param data
     * @param len
     */
    int OnHandleDeityFantasyEnterWarReq(uint32_t msgId, NFDataPackage &packet);
    
    //天神出战成功
    int OnDeityWarSuccess(int64_t deityId);
    
    /**
     * 天神幻化信息
     * @param data
     * @param len
     */
    int OnHandleDeityShowFantasyListReq(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * 天神装备穿戴请求
     * @param data
     * @param len
     */
    int OnHandleDeityEquipDressReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神装备卸下请求
     * @param data
     * @param len
     */
    int OnHandleDeityEquipUndressReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神装备强化
     * @param data
     * @param len
     */
    int OnHandleDeityEquipStrongReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神装备强化进阶
     * @param data
     * @param len
     */
    int OnHandleDeityEquipStrongLvReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神装备套装激活
     * @param data
     * @param len
     */
    int OnHandleDeityEquipSuitActive(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神装备分解
     * @param data
     * @param len
     */
    int OnHandleDeityEquipDecomposeReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * 天神装备拆解
     * @param data
     * @param len
     */
    int OnHandleEquipDisassmbleReq(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * 激活天神，并参战
     * @param deityId
     */
    int ActiveFantasyAndEnterBattle(uint32_t deityId, uint32_t battleSlot);
public:
    bool ValidPos(int32_t pos);
    int calcEquipScore(FantasyDeityData &fantasyData, int32_t pos);
    void SendEquip(FantasyDeityData &fantasyData, int32_t pos);
    int SendDeityShowFantasyList();
    int CheckEquipSuit(FantasyDeityData &fantasyData, bool dress = true);
    bool IsActiveDeity(int64_t id);
    FantasyDeityData* GetFantasyData(uint64_t fantasyId);
    DeityBattleSlot* GetDeityBattleSlot(uint64_t battleSlot);
private:
    int64_t m_nDeityID;//
    int32_t m_nDeityLev;			//
    int64_t m_nDeityExp;
    NFShmHashMap<uint64_t, uint32_t, MAX_DEITY_FRAGMENT_NUM> m_mapFragment;		//数据
    NFShmHashMap<uint64_t, uint32_t, MAX_DEITY_SKILL_NUM> m_mapSkill;		//技能数据
private:
    NFShmHashMap<uint32_t, DeityBattleSlot, MAX_AVATAR_BATTLESLOT_NUM> m_battleDeityList;
    NFShmHashMap<int64_t, FantasyDeityData, MAX_AVATAR_CHANGE_NUM> m_mapFantasyDeity;	//当前拥有的幻化
};