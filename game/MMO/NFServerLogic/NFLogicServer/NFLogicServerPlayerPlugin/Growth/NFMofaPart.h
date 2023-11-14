// -------------------------------------------------------------------------
//    @FileName         :    NFMofaPart.h
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFMofaPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/Item/NFItem.h"
#include "NFLogicCommon/Item/NFDressEquip.hpp"
#include "DescStore/MofaYuansuDesc.h"
#include "DescStore/MofaLvattDesc.h"
#include "DescStore/MofaZyattDesc.h"
#include "DescStore/MofaZyjxattDesc.h"
#include "DescStore/MofaZyjxzfattDesc.h"
#include "DescStore/MofaSetupDesc.h"

#define MAFA_SLOT_MAX_EQUIP_NUM 3

enum
{
    MoFa_EQUIP_SLOT_STATUS_NONE = 0,
    MoFa_EQUIP_SLOT_STATUS_UNLOCK = 1,
};

class MoFaEquipSlotInfo : public NFEquipSlotInfo
{
public:
    MoFaEquipSlotInfo()
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
    
    ~MoFaEquipSlotInfo()
    {
    
    }
    
    int CreateInit()
    {
        m_awaken_lv = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool ReadFromPB(const proto_ff::EquipSlotInfo &proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::ReadFromPB(proto), false, "");
        m_awaken_lv = proto.awaken_lv();
        return true;
    }
    
    virtual bool WriteToPB(proto_ff::EquipSlotInfo &proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::WriteToPB(proto), false, "");
        proto.set_awaken_lv(m_awaken_lv);
        return true;
    }

public:
    uint32_t m_awaken_lv;
};

/**
 * @brief 阵眼
 */
class MoFaEquipSlot
{
public:
    MoFaEquipSlot()
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
    
    ~MoFaEquipSlot()
    {
    
    }
    
    int CreateInit()
    {
        m_pos = 0;
        m_status = MoFa_EQUIP_SLOT_STATUS_NONE;
        m_isZuFu = false;
        m_equips.resize(MAFA_SLOT_MAX_EQUIP_NUM);
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    bool ReadFromPB(const proto_ff::MoFaEquipInfo &proto)
    {
        m_pos = proto.pos();
        m_status = proto.status();
        m_isZuFu = proto.is_zufu();
        bool ret = m_slot.ReadFromPB(proto.slot());
        for (int i = 0; i < (int) proto.equip_size(); i++)
        {
            const proto_ff::MoFaEquipProtoInfo &protoItem = proto.equip(i);
            ret = ValidPos(protoItem.pos());
            CHECK_EXPR(ret, false, "unpack pos:%lu failed", protoItem.pos());
            auto &equip = protoItem.equip();
            if (equip.item_id() > 0)
            {
                auto pEquip = &m_equips[protoItem.pos()];
                pEquip->ReadFromPB(equip);
            }
        }
        
        return true;
    }
    
    bool WriteToPB(proto_ff::MoFaEquipInfo *pProto)
    {
        CHECK_EXPR(pProto, false, "");
        pProto->set_pos(m_pos);
        pProto->set_status(m_status);
        pProto->set_is_zufu(m_isZuFu);
        for (int i = 0; i < (int) m_equips.size(); i++)
        {
            auto pEquip = GetEquip(i);
            if (pEquip)
            {
                auto pEquipProto = pProto->add_equip();
                pEquipProto->set_pos(i);
                NFItemMgr::SetItemProtoInfo(pEquip, pEquipProto->mutable_equip());
            }
        }
        m_slot.WriteToPB(*pProto->mutable_slot());
        return true;
    }
    
    bool ValidPos(int32_t pos)
    {
        if (pos >= 0 && pos < (int) m_equips.size())
        {
            return true;
        }
        return false;
    }
    
    NFMoFaEquip *GetEquip(int32_t pos)
    {
        CHECK_EXPR(ValidPos(pos), nullptr, "pos:{}", pos);
        if (m_equips[pos].GetItemID() > 0)
        {
            return &m_equips[pos];
        }
        return nullptr;
    }
    
    void SetEquip(int32_t pos, const NFMoFaEquip &equip)
    {
        if ((ValidPos(pos)))
        {
            m_equips[pos] = equip;
        }
    }
    
    void SetEquip(int32_t pos, const NFMoFaEquip* pEquip)
    {
        if ((ValidPos(pos)))
        {
            if (pEquip)
            {
                m_equips[pos] = *pEquip;
            }
            else {
                m_equips[pos].Clear();
            }
        }
    }
    
    const proto_ff_s::E_MofaSetup_s *GetConfig()
    {
        return MofaSetupDesc::Instance()->GetDesc(m_slot.m_slot_pos);
    }
    
    bool IsCanZufu()
    {
        for (int i = 0; i < (int) m_equips.size(); i++)
        {
            auto pEquip = GetEquip(i);
            if (pEquip == NULL)
            {
                return false;
            }
            
            auto pEqupCfg = pEquip->GetEquipCfg();
            if (pEqupCfg == NULL)
            {
                return false;
            }
            if (pEqupCfg->m_quality < proto_ff::EQuality_red)
            {
                return false;
            }
        }
        
        return true;
    }
    
    int GetCankWakeMaxLv()
    {
        int32_t minLv = -1;
        for (int i = 0; i < (int) m_equips.size(); i++)
        {
            auto pEquip = GetEquip(i);
            if (pEquip == NULL)
            {
                return 0;
            }
            
            if (minLv < 0)
            {
                minLv = pEquip->m_mofa.m_awaken_lv;
            }
            else
            {
                if ((int)pEquip->m_mofa.m_awaken_lv < minLv)
                {
                    minLv = pEquip->m_mofa.m_awaken_lv;
                }
            }
        }
        
        if (minLv < 0)
        {
            minLv = 0;
        }
        
        return minLv;
    }
    
    bool IsCanWake()
    {
        if ((int)m_slot.m_awaken_lv < GetCankWakeMaxLv())
        {
            return true;
        }
        return false;
    }
    
    void calcAttr(MAP_INT32_INT64 &all)
    {
        if (m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
        {
            return;
        }
        
        calcZyAttr(all);
    }
    
    void calcZyAttr(MAP_INT32_INT64 &all)
    {
        auto pSlotCfg = GetConfig();
        if (pSlotCfg == NULL) { return; }
        
        uint32_t wakeLv = m_slot.m_awaken_lv;
        if (wakeLv == 0)
        {
            uint32_t quality = GetQuality();
            auto pAttrCfg = MofaZyattDesc::Instance()->GetDescByAttidQuality(pSlotCfg->m_ZyAtt, quality);
            if (pAttrCfg)
            {
                for (int i = 0; i < (int) pAttrCfg->m_ZY.size(); i++)
                {
                    auto &attrCfg = pAttrCfg->m_ZY[i];
                    if (attrCfg.m_type > 0 && attrCfg.m_value > 0)
                    {
                        if (m_isZuFu)
                        {
                            all[attrCfg.m_type] += attrCfg.m_value * (double) pSlotCfg->m_BlessBonus / F_THOUSAND;
                        }
                        else
                        {
                            all[attrCfg.m_type] += attrCfg.m_value;
                        }
                    }
                }
            }
            
            if (m_isZuFu)
            {
                for (int i = 0; i < (int) pSlotCfg->m_ZF.size(); i++)
                {
                    auto &attrCfg = pSlotCfg->m_ZF[i];
                    if (attrCfg.m_type > 0 && attrCfg.m_value > 0)
                    {
                        all[attrCfg.m_type] += attrCfg.m_value;
                    }
                }
            }
        }
        else
        {
            auto pWakeCfg = MofaZyjxattDesc::Instance()->GetDescByAttidJxlv(pSlotCfg->m_JxZyAtt, wakeLv);
            if (pWakeCfg)
            {
                for (int i = 0; i < (int) pWakeCfg->m_ZyJx.size(); i++)
                {
                    auto &attrCfg = pWakeCfg->m_ZyJx[i];
                    if (attrCfg.m_type > 0 && attrCfg.m_value > 0)
                    {
                        if (m_isZuFu)
                        {
                            all[attrCfg.m_type] += attrCfg.m_value * (double) pSlotCfg->m_JxBlessBonus / F_THOUSAND;
                        }
                        else
                        {
                            all[attrCfg.m_type] += attrCfg.m_value;
                        }
                    }
                }
            }
            
            if (m_isZuFu)
            {
                auto pWakeZuFuCfg = MofaZyjxzfattDesc::Instance()->GetDescByAttidJxlv(pSlotCfg->m_JxBlessAtt, wakeLv);
                if (pWakeZuFuCfg)
                {
                    for (int i = 0; i < (int) pWakeZuFuCfg->m_ZyJxZf.size(); i++)
                    {
                        auto &attrCfg = pWakeZuFuCfg->m_ZyJxZf[i];
                        if (attrCfg.m_type > 0 && attrCfg.m_value > 0)
                        {
                            all[attrCfg.m_type] += attrCfg.m_value;
                        }
                    }
                }
            }
        }
    }
    
    void calcDressAttr(MAP_INT32_INT64 &all)
    {
        for (int i = 0; i < (int) m_equips.size(); i++)
        {
            auto pEquip = GetEquip(i);
            if (pEquip == NULL)
            {
                continue;
            }
            
            auto pEquipCfg = MofaYuansuDesc::Instance()->GetDesc(pEquip->GetItemID());
            if (pEquipCfg == NULL)
            {
                continue;
            }
            
            int32_t awakeLv = pEquip->m_mofa.m_awaken_lv;
            int32_t level = pEquip->m_mofa.m_stronglv;
            if (awakeLv > 0)
            {
                for (int j = 0; j < (int) pEquipCfg->m_attribute.size(); j++)
                {
                    auto &attr = pEquipCfg->m_attribute[j];
                    if (attr.m_type > 0 && attr.m_value > 0)
                    {
                        auto pAttrValueCfg = MofaLvattDesc::Instance()->GetDesc(attr.m_value);
                        if (pAttrValueCfg && level - 1 >= 0 && level - 1 < (int) pAttrValueCfg->m_att.size())
                        {
                            int64_t attrValue = pAttrValueCfg->m_att[level - 1];
                            if (awakeLv - 1 >= 0 && awakeLv - 1 < (int) pEquipCfg->m_awaken.size())
                            {
                                all[attr.m_type] += attrValue * (double) pEquipCfg->m_awaken[awakeLv - 1].m_lvAddratio / F_THOUSAND;
                            }
                            else
                            {
                                all[attr.m_type] += attrValue;
                            }
                        }
                    }
                }
            }
        }
    }
    
    uint32_t GetQuality()
    {
        int32_t minLv = -1;
        for (int i = 0; i < (int) m_equips.size(); i++)
        {
            auto pEquip = GetEquip(i);
            if (pEquip == NULL)
            {
                return 0;
            }
            
            auto pEquipCfg = pEquip->GetEquipCfg();
            if (pEquipCfg == NULL)
            {
                return 0;
            }
            
            if (minLv < 0)
            {
                minLv = pEquipCfg->m_quality;
            }
            else
            {
                if (pEquipCfg->m_quality < minLv)
                {
                    minLv = pEquipCfg->m_quality;
                }
            }
        }
        
        if (minLv < 0)
        {
            minLv = 0;
        }
        
        return minLv;
    }

public:
    int8_t m_pos;
    NFShmVector<NFMoFaEquip, MAFA_SLOT_MAX_EQUIP_NUM> m_equips;
    MoFaEquipSlotInfo m_slot;
    uint32_t m_status;
    bool m_isZuFu;
};

class MoFaSlotVector
{
public:
    MoFaSlotVector()
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
    
    ~MoFaSlotVector()
    {
    
    }
    
    int CreateInit()
    {
        m_equips.resize(proto_ff::EMoFaEquipPos_limit);
        for (int32_t i = proto_ff::EMoFaEquipPos_first; i < proto_ff::EMoFaEquipPos_limit; i++)
        {
            m_equips[i].m_slot.m_slot_pos = proto_ff::EMoFaEquipPos_start + i;
            m_equips[i].m_pos = i;
        }
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    bool ValidPos(int32_t pos)
    {
        if (pos >= proto_ff::EMoFaEquipPos_start && pos < proto_ff::EMoFaEquipPos_start + proto_ff::EMoFaEquipPos_limit)
        {
            return true;
        }
        return false;
    }
    
    MoFaEquipSlot *GetEquip(int32_t pos)
    {
        CHECK_EXPR(ValidPos(pos), nullptr, "pos:{}", pos);
        return &m_equips[pos - proto_ff::EMoFaEquipPos_start];
    }
    
    void calcAttr(MAP_INT32_INT64 &all)
    {
        for (int32_t i = proto_ff::EMoFaEquipPos_first; i < proto_ff::EMoFaEquipPos_limit; i++)
        {
            m_equips[i].calcAttr(all);
        }
    }

public:
    NFShmVector<MoFaEquipSlot, proto_ff::EMoFaEquipPos_limit> m_equips;
};

/**
 * @brief 奇门八卦
 */
class NFMofaPart : public NFShmObjTemplate<NFMofaPart, EOT_LOGIC_PART_ID + PART_MOFA, NFPart>
{
public:
    NFMofaPart();
    
    virtual ~NFMofaPart();
    
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
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto &outproto) { return 0; }

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
    //奇门八卦获取信息
    int OnHandleGetInfoReq(uint32_t msgId, NFDataPackage &packet);
    //带上装备
    int OnHandleDressReq(uint32_t msgId, NFDataPackage &packet);
    //卸载装备
    int OnHandleUnDressReq(uint32_t msgId, NFDataPackage &packet);
    //阵眼祝福
    int OnHandleSlotZuFuReq(uint32_t msgId, NFDataPackage &packet);
    //阵眼觉醒
    int OnHandleSlotWakeReq(uint32_t msgId, NFDataPackage &packet);
    //装备升级
    int OnHandleEquipLvReq(uint32_t msgId, NFDataPackage &packet);
    //装备觉醒
    int OnHandleEquipWakeReq(uint32_t msgId, NFDataPackage &packet);
    //装备一键分解
    int OnHandleDecomposeReq(uint32_t msgId, NFDataPackage &packet);
    //兑换
    int OnHandleExchangeReq(uint32_t msgId, NFDataPackage &packet);
    //奇门八卦
    int OnHandleSlotUnlockReq(uint32_t msgId, NFDataPackage &packet);
public:
    void calcAttr(bool sync);
    void MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst);
    void PrintAttr(const MAP_INT32_INT64 &attr);
    void calcSlotAttr(MAP_INT32_INT64 &all);
private:
    MoFaSlotVector m_slotData;
};