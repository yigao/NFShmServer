// -------------------------------------------------------------------------
//    @FileName         :    NFDressEquip.hpp
//    @Author           :    gaoyi
//    @Date             :    23-11-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFDressEquip
//
// -------------------------------------------------------------------------

#pragma once

#include "NFItem.h"
#include "NFItemMgr.h"

class NFEquipSlotInfo
{
public:
    NFEquipSlotInfo()
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
    
    int CreateInit()
    {
        m_slot_pos = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual ~NFEquipSlotInfo()
    {
    
    }
    
    virtual bool ReadFromPB(const proto_ff::EquipSlotInfo &proto)
    {
        m_slot_pos = proto.slot_pos();
        return true;
    }
    
    virtual bool WriteToPB(proto_ff::EquipSlotInfo& proto)
    {
        proto.set_slot_pos(m_slot_pos);
        return true;
    }
public:
    int8_t m_slot_pos; //槽位
};

//穿戴的装备信息及该槽位的信息
template<class ItemType, class SlotType>
class NFEquipInfo
{
public:
    NFEquipInfo()
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
    
    ~NFEquipInfo()
    {
    
    }
    
    int CreateInit()
    {
        m_pos = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    bool ReadFromPB(const proto_ff::EquipInfo &proto)
    {
        m_pos = proto.pos();
        const proto_ff::ItemProtoInfo &protoItem = proto.equip();
        bool ret = m_slot.ReadFromPB(proto.slot());
        CHECK_EXPR(ret, false, "item_id:%lu slot ReadFomPB failed", protoItem.item_id());
        if (protoItem.item_id() > 0)
        {
            ret = m_equip.FromItemProto(protoItem);
            CHECK_EXPR(ret, false, "item_id:%lu FromItemProto failed", protoItem.item_id());
        }
        
        return true;
    }
    
    bool WriteToPB(proto_ff::EquipInfo &proto)
    {
        proto.set_pos(m_pos);
        if (m_equip.GetItemID() > 0)
        {
            NFItemMgr::SetItemProtoInfo(&m_equip, proto.mutable_equip());
        }
        
        m_slot.WriteToPB(*proto.mutable_slot());
        return true;
    }

public:
    int8_t m_pos;
    ItemType m_equip;
    SlotType m_slot;
};

//已穿戴的装备
template<class ItemType, class SlotType, int slotNum, int startPos>
class NFDressEquipInfo
{
public:
    NFDressEquipInfo()
    {
        m_equips.resize(slotNum);
        for (int32_t i = 0; i < (int) m_equips.size(); i++)
        {
            m_equips[i].m_slot.m_slot_pos = startPos + i;
            m_equips[i].m_pos = i;
        }
    }
    
    ~NFDressEquipInfo()
    {
    
    }
    
    bool ValidPos(int32_t pos)
    {
        if (pos >= startPos && pos < startPos + m_equips.size())
        {
            return true;
        }
        return false;
    }
    
    NFEquipInfo<ItemType, SlotType>* GetEquip(int32_t pos)
    {
        CHECK_EXPR(ValidPos(pos), nullptr, "pos:{} error", pos);
        return &m_equips[pos-startPos];
    }
public:
    NFShmVector<NFEquipInfo<ItemType, SlotType>, slotNum> m_equips;
};