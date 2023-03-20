// -------------------------------------------------------------------------
//    @FileName         :    NFEquipDefine.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipDefine
//
// -------------------------------------------------------------------------

#include "NFEquipDefine.h"


int stEquipSlotInfo::unpack(const proto_ff::EquipSlotInfo &proto)
{
    vec_stone.clear();
    vec_stone.resize(vec_stone.max_size());

    slot_pos = proto.slot_pos();
    total_score = proto.total_score();
    stronglv = proto.stronglv();
    stone_pay_slot_open = proto.stone_pay_slot_open();
    suitLv = proto.suitlv();
    for (int32_t i = 0; i < proto.stones_size(); i++)
    {
        stStoneSlotInfo t;
        t.pos = proto.stones(i).stone_pos();
        t.stone_id = proto.stones(i).stoneid();
        vec_stone[t.pos] = t;
    }

    for (int32_t i = 0; i < (int32_t)vec_stone.size(); i++)
    {
        vec_stone[i].pos = i;
    }

    for (int32_t i = 0; i < proto.washs_size(); i++)
    {
        const proto_ff::WashSlotInfo& ref = proto.washs(i);

        stWashSlotInfo w;
        w.slot = ref.slot();
        w.quality = ref.quality();
        w.lock = ref.lock();
        w.id = ref.id();
        w.value = ref.value();
        vec_wash[w.slot] = w;
    }

    return 0;
}

int stEquipSlotInfo::pack(proto_ff::EquipSlotInfo *pProto, bool clientFalg)
{
    pProto->set_slot_pos(slot_pos);
    pProto->set_total_score(total_score);
    pProto->set_stronglv(stronglv);
    pProto->set_stone_pay_slot_open(stone_pay_slot_open);
    pProto->set_suitlv(suitLv);
    int32_t addNum = clientFalg ? 1 : 0;
    for (auto& e : vec_stone)
    {
        proto_ff::StoneSlotInfo* pSlotProto = pProto->add_stones();
        if (pSlotProto)
        {
            pSlotProto->set_stone_pos(e.pos + addNum);
            pSlotProto->set_stoneid(e.stone_id);
        }
    }

    for (auto& e : vec_wash)
    {
        proto_ff::WashSlotInfo* pWashProto = pProto->add_washs();
        if (pWashProto)
        {
            pWashProto->set_slot(e.slot);
            pWashProto->set_quality(e.quality);
            pWashProto->set_lock(e.lock);
            pWashProto->set_id(e.id);
            pWashProto->set_value(e.value);
        }
    }

    return 0;
}

void stEquipSlotInfo::initStone()
{
    vec_stone.clear();
    vec_stone.resize(MAX_STONE_SLOT);
    for (int32_t i = 0; i < (int32_t)vec_stone.size(); i++)
    {
        vec_stone[i].pos = i;
        vec_stone[i].stone_id = 0;
    }
}

void stEquipSlotInfo::initWash()
{
    vec_wash.clear();
    vec_wash.resize(MAX_WASH_SLOT);
    for (int32_t i = 0; i < (int32_t)vec_wash.size(); i++)
    {
        vec_wash[i].slot = i;
        vec_wash[i].quality = 0;
        vec_wash[i].lock = 0;
        vec_wash[i].id = 0;
        vec_wash[i].value = 0;
    }
}

int32_t stEquipSlotInfo::GetWashReachQulity()
{
    auto iter = std::min_element(vec_wash.begin(), vec_wash.end(),
                                 [](stWashSlotInfo& l, stWashSlotInfo& r) {return l.quality < r.quality; });
    return iter->quality;
}

int stDressEquipInfo::unpack(const proto_ff::EquipInfo &proto)
{
    pos = proto.pos();
    const proto_ff::ItemProtoInfo& protoItem = proto.equip();

    int ret = 0;
    if (protoItem.item_id() > 0)
    {
        ret = m_equip.read_from_pbmsg(protoItem);
        CHECK_EXPR(ret == 0, ret, "stDressEquipInfo::unpack item_id:{} SetItemProto failed", protoItem.item_id());
    }

    ret = slot.unpack(proto.slot());
    CHECK_EXPR(ret == 0, ret, "slot::unpack item_id:{} SetItemProto failed", protoItem.item_id());

    return true;
}

int stDressEquipInfo::pack(proto_ff::EquipInfo *pProto, bool clientFalg)
{
    CHECK_NULL(pProto);
    pProto->set_pos(pos);
    if (m_equip.GetItemID() > 0)
    {
        m_equip.write_to_pbmsg(*pProto->mutable_equip());
    }
    slot.pack(pProto->mutable_slot(),clientFalg);
    return 0;
}
