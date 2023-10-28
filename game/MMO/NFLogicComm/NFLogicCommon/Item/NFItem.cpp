// -------------------------------------------------------------------------
//    @FileName         :    NFItem.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFItem
//
// -------------------------------------------------------------------------

#include "NFItem.h"
#include "DescStore/EncyclopediaEquipexpvalueDesc.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/EquipAttributeDesc.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFCommonApi.h"

NFItem::NFItem()
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

NFItem::~NFItem()
{
}

int NFItem::CreateInit()
{
    m_nIndex = 0;              //索引
    m_nItemID = 0;             //物品ID
    m_nNum = 0;                //物品数量
    m_byBind = 0;                //绑定状态
    m_byType = 0;               //类型
    m_nLevel = 0;              //等级 预留(装备里，这个等级是玩家等级)
    m_nExpiredTime = 0;        //过期时间,0,永不过期
    //道具也有评分，放在基类里
    
    m_stronglv = 0;                //强化等级(给天神神饰装备 神兽装备 不灭星辰 坐骑化鲲装备用)
    m_strongExp = 0;            //强化等级经验(神兽装备 不灭星辰用 坐骑化鲲装备当做突破的经验)
    m_strongWearQuality = 0;    //强化阶级(给天神神饰装备 神兽装备 不灭星辰 坐骑化鲲装备用)
    m_strongWearQualityExp = 0; //强化阶级经验(给龙魂 不灭星辰用 坐骑化鲲装备当做突破星星的数目)(神魔装备)
    m_awaken_lv = 0;            //觉醒等级(坐骑化鲲装备里的突破)
    return 0;
}

int NFItem::ResumeInit()
{
    return 0;
}

bool NFItem::IsExpire() const
{
    if (m_nExpiredTime != 0 && m_nExpiredTime < NFTime::Now().UnixSec())
    {
        return true;
    }
    return false;
}

bool NFItem::AddNum(int64_t nAddNum)
{
    if (nAddNum > 0)
    {
        if (UINT64_MAX - m_nNum < (uint64_t) nAddNum)
        {
            m_nNum = UINT32_MAX;
            //数量超过 需要打印警告日志
            NFLogError(NF_LOG_SYSTEMLOG, 0, ":AddNum....num > UINT32_MAX...nAddNum:{},m_nNum:{}", nAddNum, m_nNum);
        }
        else
        {
            m_nNum += nAddNum;
        }
    }
    else
    {
        if (((int64_t) m_nNum + (int64_t) nAddNum) >= 0)
        {
            m_nNum += nAddNum;
        }
        else
        {
            m_nNum = 0;
        }
    }
    
    return true;
}

bool NFItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum/* = 1*/, int8_t byBind /* = (uint8_t)EBindState::EBindState_no*/)
{
    m_nIndex = nIndex;
    m_nItemID = nItemID;
    m_nNum = nNum;
    m_byBind = byBind;
    
    auto pItemCfg = GetItemCfg();
    if (pItemCfg)
    {
        m_byType = pItemCfg->m_itemtype;
        m_nLevel = pItemCfg->m_level;
        if (pItemCfg->m_time > 0)
        {
            m_nExpiredTime = NFTime::Now().UnixSec() + pItemCfg->m_time;
        }
        
        return true;
    }
    
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:%lu not find, not item, not equp", nItemID);
    
    if (!(pEquipCfg->m_type == proto_ff::EPackageType_shenji_aq ||
        pEquipCfg->m_type == proto_ff::EPackageType_shenji_lj ||
        pEquipCfg->m_type == proto_ff::EPackageType_turn ||
        pEquipCfg->m_type == proto_ff::EPackageType_YaoHun
    ))
    {
        auto pEquipAttrCfg = GetEquipAttributeCfg();
        CHECK_EXPR(pEquipAttrCfg, false, "itemId:%lu attrId:%d find", nItemID, pEquipCfg->m_attributeid);
    }
    
    m_nLevel = pEquipCfg->m_level;
    if (pEquipCfg->m_time > 0)
    {
        m_nExpiredTime = NFTime::Now().UnixSec() + pEquipCfg->m_time;
    }
    
    CHECK_EXPR(genBaseAttr(itemCond), false, "");
    CHECK_EXPR(genGodPinAttr(itemCond), false, "");
    CHECK_EXPR(genGodZunAttr(itemCond), false, "");
    
    //神机装备处理
    if (pEquipCfg->m_type == proto_ff::EPackageType_shenji_aq || pEquipCfg->m_type == proto_ff::EPackageType_shenji_lj)
    {
/*        stBestEQCfgEx* pBestCfg = g_GetBestEQCfg()->GetEquipCfg(pEquipCfg->id);
        chk_err_rv(pBestCfg, false, "[logic] CEquip::Init itemId:%lu shenji not find", nItemID);
        m_makeid = g_GetBestEQCfg()->GetMakeId(pBestCfg->m_pCfg->grade, pBestCfg->m_pCfg->quality, pBestCfg->m_pCfg->star);
        m_state = 0;*/
    }
    else if (pEquipCfg->m_type == proto_ff::EPackageType_Longhun)
    {
        m_stronglv = 1;
        m_strongWearQuality = 1;
        m_strongExp = 0;
        m_awaken_lv = 0;
    }
    else if (pEquipCfg->m_type == proto_ff::EPackageType_BeastEquip)
    {
        m_stronglv = 1;
        m_strongWearQuality = pEquipCfg->m_wearquality;
        m_strongExp = 0;
        auto pBlueAttrCfg = EncyclopediaEquipexpvalueDesc::Instance()->GetDesc(m_nItemID);
        if (pBlueAttrCfg)
        {
            uint32_t blueNum = pBlueAttrCfg->m_goldattall >= pBlueAttrCfg->m_goldatt ? (pBlueAttrCfg->m_goldattall - pBlueAttrCfg->m_goldatt) : 0;
            if (blueNum > 0)
            {
                std::vector<std::pair<uint32_t, uint32_t>> vec;
                for (int i = 0; i < (int) pBlueAttrCfg->m_beaststar.size(); i++)
                {
                    if (pBlueAttrCfg->m_beaststar[i].m_att > 0)
                    {
                        vec.push_back(std::make_pair(pBlueAttrCfg->m_beaststar[i].m_att, pBlueAttrCfg->m_beaststar[i].m_num));
                    }
                }
                
                std::random_shuffle(vec.begin(), vec.end());
                vec.resize(vec.size() < (uint32_t) blueNum ? vec.size() : blueNum);
                for (int i = 0; i < (int) vec.size(); i++)
                {
                    m_miscAttr[vec[i].first] = vec[i].second;
                }
            }
            
            if (pBlueAttrCfg->m_goldatt > 0)
            {
                std::vector<std::pair<uint32_t, uint32_t>> vec;
                for (int i = 0; i < (int) pBlueAttrCfg->m_goldstar.size(); i++)
                {
                    if (pBlueAttrCfg->m_goldstar[i].m_att > 0)
                    {
                        vec.push_back(std::make_pair(pBlueAttrCfg->m_goldstar[i].m_att, pBlueAttrCfg->m_goldstar[i].m_num));
                    }
                }
                
                std::random_shuffle(vec.begin(), vec.end());
                vec.resize(vec.size() < (uint32_t) pBlueAttrCfg->m_goldatt ? vec.size() : pBlueAttrCfg->m_goldatt);
                
                for (int i = 0; i < (int) vec.size(); i++)
                {
                    m_godAttr[vec[i].first] = vec[i].second;
                }
            }
        }
    }
    else if (pEquipCfg->m_type == proto_ff::EPackageType_DeityEquip)
    {
        m_stronglv = 0;
        m_strongWearQuality = pEquipCfg->m_wearquality;
    }
    else if (pEquipCfg->m_type == proto_ff::EPackageType_MountKun)
    {
        m_stronglv = 0;
        m_strongWearQuality = 0;
        m_awaken_lv = 0;
        m_strongWearQualityExp = 0;
    }
    else if (pEquipCfg->m_type == proto_ff::EPackageType_star)
    {
        m_stronglv = 1;
        m_strongWearQuality = 1;
        m_strongExp = 0;
        m_strongWearQualityExp = 0;
    }
        //神魔装备
    else if (proto_ff::EPackageType_GodEvil == pEquipCfg->m_type)
    {
        m_stronglv = 0;
        m_strongExp = 0;
        m_strongWearQualityExp = 0;
        //m_make_time = itemCond.makeTime;
        //m_make_name = itemCond.makeName;
    }
    
    GenBaseScore();
    m_strongWearQualityExp = 0;
    
    return true;
}

void NFItem::UnInit()
{
    m_nIndex = 0;
    m_nItemID = 0;
    m_nNum = 0;
    m_byBind = (uint8_t) EBindState::EBindState_no;
    m_byType = 0;
    m_nLevel = 0;
    m_nExpiredTime = 0;
}

const proto_ff_s::E_EquipEquip_s *NFItem::GetEquipCfg() const
{
    return EquipEquipDesc::Instance()->GetDesc(m_nItemID);
}

const proto_ff_s::E_ItemItem_s *NFItem::GetItemCfg() const
{
    return ItemItemDesc::Instance()->GetDesc(m_nItemID);
}

const proto_ff_s::E_EquipAttribute_s *NFItem::GetEquipAttributeCfg() const
{
    auto pEquipCfg = GetEquipCfg();
    if (pEquipCfg)
    {
        return EquipAttributeDesc::Instance()->GetDesc(pEquipCfg->m_attributeid);
    }
    return NULL;
}

bool NFItem::SetItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    m_nIndex = protoItem.index();
    m_nItemID = protoItem.item_id();
    m_nNum = protoItem.item_num();
    m_byBind = protoItem.bind();
    m_nLevel = protoItem.level();
    m_nExpiredTime = protoItem.expiretime();
    
    auto pEquipCfg = GetEquipCfg();
    if (pEquipCfg)
    {
        if (!(pEquipCfg->m_type == proto_ff::EPackageType_shenji_aq ||
            pEquipCfg->m_type == proto_ff::EPackageType_shenji_lj ||
            pEquipCfg->m_type == proto_ff::EPackageType_turn
        ))
        {
            auto pEquipAttrCfg = GetEquipAttributeCfg();
            CHECK_EXPR(pEquipAttrCfg, false, "[logic] CEquip::SetItemProto itemId:{} attrId:{} find", m_nItemID, pEquipCfg->m_attributeid);
        }
    }
    
    //基础属性
    uint16_t baseSize = protoItem.base_size();
    for (uint16_t i = 0; i < baseSize; ++i)
    {
        const proto_ff::Attr& attr = protoItem.base(i);
        m_baseAttr[attr.id()] = attr.value();
    }
    //星级属性
    uint16_t refineSize = protoItem.refine_size();
    for (uint16_t i = 0; i < refineSize; ++i)
    {
        const proto_ff::Attr& attr = protoItem.refine(i);
        proto_ff_s::Attr_s tstar;
        tstar.id = attr.id();
        tstar.value = attr.value();
        m_starAttr.push_back(tstar);
    }
    
    //蓝星属性
    uint16_t blueSize = protoItem.blue_size();
    for (uint16_t i = 0; i < blueSize; ++i)
    {
        const proto_ff::BlueStarAttr& attr = protoItem.blue(i);
        proto_ff_s::BlueStarAttr_s t;
        t.id = attr.id();
        t.value = attr.value();
        t.lv_part = attr.lv_part();
        m_blueAttr[t.id] = t;
    }
    
    //仙尊属性
    uint16_t godSize = protoItem.god_size();
    for (uint16_t i = 0; i < godSize; ++i)
    {
        const proto_ff::Attr& attr = protoItem.god(i);
        m_godAttr[attr.id()] = attr.value();
    }
    
    uint16_t miscSize = protoItem.misc_size();
    for (uint16_t i = 0; i < miscSize; ++i)
    {
        const proto_ff::Attr& attr = protoItem.misc(i);
        m_miscAttr[attr.id()] = attr.value();
    }
    
    m_stronglv = protoItem.strong_lv();
    m_strongExp = protoItem.strong_exp();
    m_strongWearQuality = protoItem.strong_wear_quality();
    m_strongWearQualityExp = protoItem.strong_wear_quality_exp();
    m_awaken_lv = protoItem.awaken_lv();
    return true;
}

void NFItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    if (pEquipAttrCfg == NULL)
        return;
    
    for (auto &e : m_baseAttr)
    {
        attrs[e.first] += e.second;
    }
    
    for (auto &e : m_starAttr)
    {
        attrs[e.id] += e.value;
    }
    
    for (auto &e : m_godAttr)
    {
        attrs[e.first] += e.second;
    }
    
    if (pEquipAttrCfg)
    {
/*        MAP_INT32_INT32 *specAttr = g_GetEquipCfg()->GetSpecAttr(pEquipAttrCfg->m_specid, m_speclv);
        if (specAttr)
        {
            for (auto &e : *specAttr)
            {
                attrs[e.first] += e.second;
            }
        }*/
    }
    
    for (auto &e : m_blueAttr)
    {
        attrs[e.first] += e.second.value * floor(level / e.second.lv_part);
    }
}

bool NFItem::genBaseAttr(SItemCond &itemCond)
{
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, false, "");
    
    for (auto &e : pEquipAttrCfg->m_attribute)
    {
        int32_t attrId = e.m_type;
        CHECK_CONTINUE(attrId != proto_ff::A_NONE);
        //暂时处理普通生成
        if (itemCond.inittype == EInitAttrType::Common)
        {
            m_baseAttr[attrId] += NFRandomInt(e.m_valuemin, e.m_valuemax);
        }
    }
    
    return true;
}

bool NFItem::genGodPinAttr(SItemCond &itemCond)
{
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "");
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, false, "");
    
    //1:生成星级属性
    m_starAttr.clear();
    uint32_t starLv = pEquipCfg->m_star;
    if (starLv > pEquipAttrCfg->m_star_library.size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "equipId:{} star:{} error", m_nItemID, starLv);
        return false;
    }
    
    for (uint32_t i = 0; i < starLv; i++)
    {
        std::string starLibary = pEquipAttrCfg->m_star_library.at(i).data();
        if (starLibary.empty())
            continue;
        VEC_STRING starStr;
        NFCommonApi::SplitStr(starLibary, "|", &starStr);
        int32_t randx = NFRandInt((int) 0, (int) starStr.size());
        std::string tmpAttrStr = starStr.at(randx);
        VEC_INT32 vecStarInt;
        NFCommonApi::SplitStrToVecInt(tmpAttrStr, ";", &vecStarInt);
        if (vecStarInt.size() != 3)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CEquip::genGodPinAttr equipId:{} star:{} error 11", m_nItemID, starLv);
            return false;
        }
        
        proto_ff_s::Attr_s t;
        t.id = vecStarInt.at(0);
        t.value = NFRandomInt(vecStarInt.at(1), vecStarInt.at(2));
        m_starAttr.push_back(t);
    }
    
    //2:生成蓝星属性
    int32_t blueStar = pEquipAttrCfg->m_bluestarnum;
    
    VEC_INT32 vecBlueAttrType;
    VEC_INT32 vecBlueAttrLevel;
    VEC_INT32 vecBlueAttrValue;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_bluestar_type.data(), ";", &vecBlueAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_bluestar_lv.data(), ";", &vecBlueAttrLevel);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_bluestar_number.data(), ";", &vecBlueAttrValue);
    
    CHECK_EXPR(vecBlueAttrType.size() == vecBlueAttrLevel.size(), false, "CEquip::genGodPinAttr blue star equipId:{} failed", m_nItemID);
    CHECK_EXPR(vecBlueAttrLevel.size() == vecBlueAttrValue.size(), false, "CEquip::genGodPinAttr blue star equipId:{} failed", m_nItemID);
    CHECK_EXPR(vecBlueAttrType.size() >= (uint32_t) blueStar, false, "CEquip::genGodPinAttr blue star equipId:{} failed", m_nItemID);
    
    for (int32_t i = 0; i < blueStar; i++)
    {
        CHECK_EXPR(vecBlueAttrType.size(), false, "CEquip::genGodPinAttr blue star equipId : {} failed", m_nItemID);
        
        proto_ff_s::BlueStarAttr_s t;
        t.id = vecBlueAttrType.at(i);
        t.value = vecBlueAttrValue.at(i);
        t.lv_part = vecBlueAttrLevel.at(i);
        CHECK_EXPR(t.id != proto_ff::A_NONE, false, "CEquip::genGodPinAttr blue star equipId : {} failed attrid:0", m_nItemID);
        
        m_blueAttr[t.id] = t;
    }
    
    return true;
}

bool NFItem::genGodZunAttr(SItemCond &itemCond)
{
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "");
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, false, "");
    
    VEC_INT32 vecAttrType;
    VEC_INT32 vecAttrMin;
    VEC_INT32 vecAttrMax;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godattribute_type.data(), ",", &vecAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godattribute_valuemin.data(), ",", &vecAttrMin);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godattribute_valuemax.data(), ",", &vecAttrMax);
    int32_t typeSize = vecAttrType.size();
    int32_t minSize = vecAttrMin.size();
    int32_t maxSize = vecAttrMax.size();
    
    if (typeSize != minSize || typeSize != maxSize)
        return false;
    
    for (int32_t i = 0; i < typeSize; i++)
    {
        m_godAttr[vecAttrType[i]] += NFRandomInt(vecAttrMin[i], vecAttrMax[i]);
    }
    
    return true;
}

void NFItem::GenBaseScore()
{
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, , "");
    if (pEquipCfg->m_type == proto_ff::EPackageType_YaoHun)
    {
        //g_GetPetCfg()->CalcPetWraithScore(pEquipCfg->m_id);
    }
}

bool NFItem::IsProf(int32_t profId) const
{
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "");
    
    VEC_INT32 vecProfession;;
    NFCommonApi::SplitStrToVecInt(pEquipCfg->m_profession.data(), ";", &vecProfession);
    if (std::find(vecProfession.begin(), vecProfession.end(), profId) == vecProfession.end() &&
        std::find(vecProfession.begin(), vecProfession.end(), 0) == vecProfession.end())
    {
        return false;
    }
    
    return true;
}


bool stDressEquipInfo::unpack(const proto_ff::EquipInfo& proto)
{
    pos = proto.pos();
    const proto_ff::ItemProtoInfo& protoItem = proto.equip();
    bool ret = slot.unpack(proto.slot());
    CHECK_EXPR(ret, false, "stDressEquipInfo::unpack item_id:{} slot unpack failed", protoItem.item_id());
    if (protoItem.item_id() > 0)
    {
        ret = m_equip.SetItemProto(protoItem);
        CHECK_EXPR(ret, false, "stDressEquipInfo::unpack item_id:{} SetItemProto failed", protoItem.item_id());
    }
    
    return true;
}

void stDressEquipInfo::pack(proto_ff::EquipInfo* pProto, bool clientFalg/* = false*/)
{
    CHECK_NOT_RET(pProto);
    pProto->set_pos(pos);
    if (m_pEquip)
    {
        g_GetItemMgr()->SetItemProtoInfo(m_pEquip, pProto->mutable_equip());
    }
    slot.pack(pProto->mutable_slot(),clientFalg);
    
}

bool stEquipSlotInfo::unpack(const EquipSlotInfo& proto)
{
    vec_stone.clear();
    vec_stone.resize(MAX_STONE_SLOT);
    
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
    
    for (int32_t i = 0; i < MAX_STONE_SLOT; i++)
    {
        vec_stone[i].pos = i;
    }
    
    for (int32_t i = 0; i < proto.washs_size(); i++)
    {
        const WashSlotInfo& ref = proto.washs(i);
        
        stWashSlotInfo w;
        w.slot = ref.slot();
        w.quality = ref.quality();
        w.lock = ref.lock();
        w.id = ref.id();
        w.value = ref.value();
        vec_wash[w.slot] = w;
    }
    const RefineSlotInfo& refineProto = proto.refine();
    m_refine.refine_lv = refineProto.refine_lv();
    for (int32_t i = 0; i < refineProto.unlocks_size(); i++)
    {
        const ComPair& ref = refineProto.unlocks(i);
        m_refine.unlockMap[ref.key()] = ref.value();
    }
    m_refine.gm_lv = refineProto.gm_lv();
    for (int32_t i = 0; i < refineProto.lock_pos_size(); i++)
    {
        m_refine.lock_pos.insert(refineProto.lock_pos(i));
    }
    
    awaken_lv = proto.awaken_lv();
    awaken_break_flag = proto.awaken_break_flag();
    soaring_lv = proto.soaring_lv();
    quality_lv = proto.quality_lv();
    seal_slots.clear();
    for (int32_t i = 0; i < proto.seal_slots_size(); i++)
    {
        const SealSlotInfo& slotRef = proto.seal_slots(i);
        seal_slots[slotRef.slot()] = slotRef.itemid();
    }
    for (int32_t i = 0; i < proto.active_seal_ids_size(); i++)
    {
        active_seal_ids.insert(proto.active_seal_ids(i));
    }
    
    return true;
}

void stEquipSlotInfo::pack(EquipSlotInfo* pProto, bool clientFalg /*= false*/)
{
    pProto->set_slot_pos(slot_pos);
    pProto->set_total_score(total_score);
    pProto->set_stronglv(stronglv);
    pProto->set_stone_pay_slot_open(stone_pay_slot_open);
    pProto->set_suitlv(suitLv);
    int32_t addNum = clientFalg ? 1 : 0;
    for (auto& e : vec_stone)
    {
        StoneSlotInfo* pSlotProto = pProto->add_stones();
        if (pSlotProto)
        {
            pSlotProto->set_stone_pos(e.pos + addNum);
            pSlotProto->set_stoneid(e.stone_id);
        }
    }
    
    for (auto& e : vec_wash)
    {
        WashSlotInfo* pWashProto = pProto->add_washs();
        if (pWashProto)
        {
            pWashProto->set_slot(e.slot);
            pWashProto->set_quality(e.quality);
            pWashProto->set_lock(e.lock);
            pWashProto->set_id(e.id);
            pWashProto->set_value(e.value);
        }
    }
    
    RefineSlotInfo* pRefine = pProto->mutable_refine();
    if (pRefine)
    {
        pRefine->set_refine_lv(m_refine.refine_lv);
        pRefine->set_gm_lv(m_refine.gm_lv);
        for (auto& e : m_refine.unlockMap)
        {
            ComPair* pUnlockProto = pRefine->add_unlocks();
            if (pUnlockProto)
            {
                pUnlockProto->set_key(e.first);
                pUnlockProto->set_value(e.second);
            }
        }
        for (auto& e : m_refine.lock_pos)
        {
            pRefine->add_lock_pos(e);
        }
    }
    
    pProto->set_awaken_lv(awaken_lv);
    pProto->set_awaken_break_flag(awaken_break_flag);
    pProto->set_soaring_lv(soaring_lv);
    pProto->set_quality_lv(quality_lv);
    for (auto& e : seal_slots)
    {
        SealSlotInfo* pSlotProto = pProto->add_seal_slots();
        if (pSlotProto)
        {
            pSlotProto->set_slot(e.first);
            pSlotProto->set_itemid(e.second);
        }
    }
    for (auto& e : active_seal_ids)
    {
        pProto->add_active_seal_ids(e);
    }
    
}
void stEquipSlotInfo::initStone()
{
    vec_stone.clear();
    vec_stone.resize(MAX_STONE_SLOT);
    for (int32_t i = 0; i < MAX_STONE_SLOT; i++)
    {
        vec_stone[i].pos = i;
        vec_stone[i].stone_id = 0;
    }
    
}
int32_t stEquipSlotInfo::GetWashReachQulity()
{
    auto iter = std::min_element(vec_wash.begin(), vec_wash.end(),
                                 [](stWashSlotInfo& l, stWashSlotInfo& r) {return l.quality < r.quality; });
    return iter->quality;
    
}


void stEquipSlotInfo::initWash()
{
    vec_wash.clear();
    vec_wash.resize(MAX_WASH_SLOT);
    for (int32_t i = 0; i < MAX_WASH_SLOT; i++)
    {
        vec_wash[i].slot = i;
        vec_wash[i].quality = 0;
        vec_wash[i].lock = 0;
        vec_wash[i].id = 0;
        vec_wash[i].value = 0;
    }
    
}

void stEquipSlotInfo::initRefine()
{
    const JinglianSimpleCfgInfo* pCfg = g_GetJinglianSimpleCfgTable()->GetJinglianSimpleCfgInfo(slot_pos);
    chk_ne2(pCfg);
    for (int32_t i = 1; i <= pCfg->default_attrs; i++)
    {
        m_refine.unlockMap[i] = 0;
    }
}


int32_t GetEquipType(int64_t itemId)
{
    const EquipEquipCfgInfo * pEquipCfg = g_GetEquipEquipCfgTable()->GetEquipEquipCfgInfo(itemId);
    chk_ne(pEquipCfg, EEquipType_none);
    
    int32_t pos = pEquipCfg->position;
    auto iter_n = std::find(const_equip_normal.begin(), const_equip_normal.end(), pos);
    if (iter_n != const_equip_normal.end())
        return EEquipType_nomal;
    
    auto iter_x = std::find(const_equip_xq.begin(), const_equip_xq.end(), pos);
    if (iter_x != const_equip_xq.end())
        return EEquipType_xq;
    
    auto iter_y = std::find(const_deity_equip_normal.begin(), const_deity_equip_normal.end(), pos);
    if (iter_y != const_deity_equip_normal.end())
        return EEquipType_deity;
    
    return EEquipType_none;
}

bool IsComEquip(int32_t pos)
{
    auto iter_n = std::find(const_equip_normal.begin(), const_equip_normal.end(), pos);
    return iter_n != const_equip_normal.end();
}
bool IsXQEquip(int32_t pos)
{
    auto iter_n = std::find(const_equip_xq.begin(), const_equip_xq.end(), pos);
    return iter_n != const_equip_xq.end();
}
bool IsMarryEquip(int32_t pos)
{
    return pos == EEquipPos_marry;
}
const VEC_INT32& GetComEquipVecPos()
{
    return const_equip_normal;
}
const VEC_INT32& GetXQEquipVecPos()
{
    return const_equip_xq;
}