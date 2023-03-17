// -------------------------------------------------------------------------
//    @FileName         :    NFItemDefine.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemDefine
//
// -------------------------------------------------------------------------

#include "NFItemDefine.h"
#include "DescStore/ItemItemDesc.h"
#include "NFComm/NFCore/NFTime.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/EquipAttributeDesc.h"
#include "NFComTypeDefine.h"
#include "NFComm/NFCore/NFCommonApi.h"

NFGridItem::NFGridItem()
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

NFGridItem::~NFGridItem()
{

}

int NFGridItem::CreateInit()
{
    return 0;
}

int NFGridItem::ResumeInit()
{
    return 0;
}

bool NFGridItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    base.index = nIndex;
    base.item_id = nItemID;
    base.item_num = nNum;
    base.bind = byBind;

    auto pItemCfg = ItemItemDesc::GetDescStore()->GetDesc(nItemID);
    if (pItemCfg)
    {
        base.type = pItemCfg->m_itemtype;
        base.level = pItemCfg->m_level;
        if (pItemCfg->m_time > 0)
        {
            base.expireTime = NFTime::Now().UnixSec() + pItemCfg->m_time;
        }
    }
    else
    {
        auto *pEquipCfg = EquipEquipDesc::GetDescStore()->GetDesc(nItemID);
        if (pEquipCfg)
        {
            base.type = proto_ff::EItemType_Equip;
            auto pEquipAttrCfg = EquipAttributeDesc::GetDescStore()->GetDesc(pEquipCfg->m_attributeid);
            CHECK_EXPR(pEquipAttrCfg, false, "[logic] CEquip::Init itemId:{} attrId:{} find", nItemID, pEquipCfg->m_attributeid);
            base.level = pEquipCfg->m_level;
            if (pEquipCfg->m_time > 0)
            {
                base.expireTime = NFTime::Now().UnixSec() + pItemCfg->m_time;
            }

            CHECK_EXPR(genBaseAttr(itemCond), -1, "");
            CHECK_EXPR(genGodPinAttr(itemCond), -1, "");
            CHECK_EXPR(genGodZunAttr(itemCond), -1, "");
            CHECK_EXPR(genSpecialAttr(itemCond), -1, "");

            if (pEquipCfg->m_position >= proto_ff::EDeityEquipPos_start &&
                pEquipCfg->m_position < proto_ff::EDeityEquipPos_start + proto_ff::EDeityEquipPos_limit)
            {
                equip_ext.strong_lv = 0;
                equip_ext.strong_wear_quality = pEquipCfg->m_wearquality;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "itemid:{} not item and not equip", nItemID);
            return false;
        }
    }

    return true;
}

proto_ff_s::E_ItemItem_s *NFGridItem::GetItemCfg()
{
    return ItemItemDesc::GetDescStore()->GetDesc(base.item_id);
}

proto_ff_s::E_EquipEquip_s *NFGridItem::GetEquipCfg()
{
    return EquipEquipDesc::GetDescStore()->GetDesc(base.item_id);
}

proto_ff_s::E_EquipAttribute_s *NFGridItem::GetEquipAttrCfg()
{
    auto pEquipCfg = GetEquipCfg();
    if (pEquipCfg)
    {
        return EquipAttributeDesc::GetDescStore()->GetDesc(pEquipCfg->m_attributeid);
    }

    return nullptr;
}

int NFGridItem::read_from_pbmsg(const proto_ff::ItemProtoInfo &protoItem)
{
    base.index = protoItem.index();
    base.item_id = protoItem.item_id();
    base.item_num = protoItem.item_num();
    base.bind = protoItem.bind();
    base.level = protoItem.level();
    base.expireTime = protoItem.expiretime();

    NF_ASSERT((int) protoItem.base_size() <= (int) equip_ext.base.max_size());
    for (int i = 0; i < (int) protoItem.base_size(); i++)
    {
        const ::proto_ff::Attr &attr = protoItem.base(i);
        equip_ext.base.emplace(attr.id(), attr.value());
    }

    NF_ASSERT((int) protoItem.refine_size() <= (int) equip_ext.star.max_size());
    for (int i = 0; i < (int) protoItem.refine_size(); i++)
    {
        const ::proto_ff::Attr &attr = protoItem.refine(i);
        proto_ff_s::Attr_s attr_s;
        attr_s.read_from_pbmsg(attr);
        equip_ext.star.push_back(attr_s);
    }

    NF_ASSERT((int) protoItem.blue_size() <= (int) equip_ext.blue.max_size());
    for (int i = 0; i < (int) protoItem.blue_size(); i++)
    {
        const ::proto_ff::BlueStarAttr &attr = protoItem.blue(i);
        ::proto_ff_s::BlueStarAttr_s attr_s;
        attr_s.read_from_pbmsg(attr);
        equip_ext.blue.emplace(attr_s.id, attr_s);
    }

    NF_ASSERT((int) protoItem.god_size() <= (int) equip_ext.god.max_size());
    for (int i = 0; i < (int) protoItem.god_size(); i++)
    {
        const ::proto_ff::Attr &attr = protoItem.god(i);
        equip_ext.god.emplace(attr.id(), attr.value());
    }

    NF_ASSERT((int) protoItem.special_size() <= (int) equip_ext.special.max_size());
    for (int i = 0; i < (int) protoItem.special_size(); i++)
    {
        const ::proto_ff::Attr &attr = protoItem.special(i);
        equip_ext.special.emplace(attr.id(), attr.value());
    }

    equip_ext.strong_lv = protoItem.strong_lv();
    equip_ext.strong_wear_quality = protoItem.strong_wear_quality();

    auto pItemCfg = ItemItemDesc::GetDescStore()->GetDesc(base.item_id);
    if (pItemCfg)
    {
        base.type = pItemCfg->m_itemtype;
    }
    else
    {
        auto *pEquipCfg = EquipEquipDesc::GetDescStore()->GetDesc(base.item_id);
        if (pEquipCfg)
        {
            base.type = proto_ff::EItemType_Equip;
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "the id:{} not item and not equip", base.item_id);
            return -1;
        }
    }
    return 0;
}

int NFGridItem::write_to_pbmsg(proto_ff::ItemProtoInfo &protoItem)
{
    protoItem.set_index(base.index);
    protoItem.set_item_id(base.item_id);
    protoItem.set_item_num(base.item_num);
    protoItem.set_bind(base.bind);
    protoItem.set_level(base.level);
    protoItem.set_expiretime(base.expireTime);

    for (auto iter = equip_ext.base.begin(); iter != equip_ext.base.end(); iter++)
    {
        auto pAttr = protoItem.add_base();
        pAttr->set_id(iter->first);
        pAttr->set_value(iter->second);
    }

    for (int i = 0; i < (int) equip_ext.star.size(); i++)
    {
        equip_ext.star[i].write_to_pbmsg(*protoItem.add_refine());
    }

    for (auto iter = equip_ext.blue.begin(); iter != equip_ext.blue.end(); iter++)
    {
        iter->second.write_to_pbmsg(*protoItem.add_blue());
    }

    for (auto iter = equip_ext.god.begin(); iter != equip_ext.god.end(); iter++)
    {
        auto pAttr = protoItem.add_base();
        pAttr->set_id(iter->first);
        pAttr->set_value(iter->second);
    }

    for (auto iter = equip_ext.special.begin(); iter != equip_ext.special.end(); iter++)
    {
        auto pAttr = protoItem.add_base();
        pAttr->set_id(iter->first);
        pAttr->set_value(iter->second);
    }

    protoItem.set_strong_lv(equip_ext.strong_lv);
    protoItem.set_strong_wear_quality(equip_ext.strong_wear_quality);
    return 0;
}

uint16_t NFGridItem::GetIndex() const
{
    return base.index;
}

uint64_t NFGridItem::GetItemID() const
{
    return base.item_id;
}

uint64_t NFGridItem::GetNum() const
{
    return base.item_num;
}

int8_t NFGridItem::GetBind() const
{
    return base.bind;
}

uint8_t NFGridItem::GetType() const
{
    return base.type;
}

uint32_t NFGridItem::GetLevel() const
{
    return base.level;
}

int64_t NFGridItem::GetExpireTime() const
{
    return base.expireTime;
}

void NFGridItem::SetIndex(uint16_t nIndex)
{
    base.index = nIndex;
}

void NFGridItem::SetType(uint8_t type)
{
    base.type = type;
}

void NFGridItem::SetBind(int8_t byBind)
{
    base.bind = byBind;
}

void NFGridItem::SetNum(uint64_t nNum)
{
    base.item_num = nNum;
}

void NFGridItem::SetLevel(uint32_t nLevel)
{
    base.level = nLevel;
}

void NFGridItem::SetExpireTime(int64_t tick)
{
    base.expireTime = tick;
}

bool NFGridItem::AddNum(int64_t nAddNum)
{
    if (nAddNum > 0)
    {
        if (UINT32_MAX - base.item_num < (uint64_t) nAddNum)
        {
            base.item_num = UINT32_MAX;
            //数量超过 需要打印警告日志
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] CItemBase::AddNum....num > UINT32_MAX...nAddNum:%lu,m_nNum:%lu", nAddNum, base.item_num);
        }
        else
        {
            base.item_num += nAddNum;
        }
    }
    else
    {
        if (((int64_t) base.item_num + (int64_t) nAddNum) >= 0)
        {
            base.item_num += nAddNum;
        }
        else
        {
            base.item_num = 0;
        }
    }

    return true;
}

int NFGridItem::genBaseAttr(SItemCond &itemCond)
{
    auto pEquipAttrCfg = GetEquipAttrCfg();
    CHECK_NULL(pEquipAttrCfg);

    for (auto &e: pEquipAttrCfg->m_attribute)
    {
        int32_t attrId = e.m_type;
        CHECK_EXPR_CONTINUE(attrId != proto_ff::A_NONE, "");
        //暂时处理普通生成
        if (itemCond.inittype == EInitAttrType::Common)
        {
            equip_ext.base[attrId] += NFRandomInt(e.m_valuemin, e.m_valuemax);
        }
    }

    return 0;
}

int NFGridItem::genGodPinAttr(SItemCond &itemCond)
{
    RandAttrType randType = RandAttrType_rand;
    auto pEquipCfg = GetEquipCfg();
    CHECK_NULL(pEquipCfg);
    auto pEquipAttrCfg = GetEquipAttrCfg();
    CHECK_NULL(pEquipAttrCfg);

    if (itemCond.inittype == EInitAttrType::Common)
        randType = RandAttrType_rand;

    //1:生成星级属性
    equip_ext.star.clear();
    uint32_t starLv = pEquipCfg->m_star;
    if (starLv > pEquipAttrCfg->m_star_library.size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CEquip::genGodPinAttr equipId:{} star:{} error", base.item_id, starLv);
        return -1;
    }

    for (uint32_t i = 0; i < starLv; i++)
    {
        std::string starLibary = pEquipAttrCfg->m_star_library.at(i).ToString();
        if (starLibary.empty())continue;
        VEC_STRING starStr;
        NFCommonApi::SplitStr(starLibary, "|", &starStr);
        int32_t randx = NFRandInt((int) 0, (int) starStr.size());
        std::string tmpAttrStr = starStr.at(randx);
        VEC_INT32 vecStarInt;
        NFCommonApi::SplitStrToVecInt(tmpAttrStr, ";", &vecStarInt);
        if (vecStarInt.size() != 3)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CEquip::genGodPinAttr equipId:{} star:{} error 11", base.item_id, starLv);
            return false;
        }

        proto_ff_s::Attr_s t;
        t.id = vecStarInt.at(0);
        t.value = NFRandomInt(vecStarInt.at(1), vecStarInt.at(2));
        equip_ext.star.push_back(t);

    }

    //2:生成蓝星属性
    int32_t blueStar = pEquipAttrCfg->m_bluestarnum;

    VEC_INT32 vecBlueAttrType;
    VEC_INT32 vecBlueAttrLevel;
    VEC_INT32 vecBlueAttrValue;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_bluestar_type.ToString(), ",", &vecBlueAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_bluestar_lv.ToString(), ",", &vecBlueAttrLevel);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_bluestar_number.ToString(), ",", &vecBlueAttrValue);

    CHECK_EXPR(vecBlueAttrType.size() == vecBlueAttrLevel.size(), -1, "CEquip::genGodPinAttr blue star equipId:{} failed", base.item_id);
    CHECK_EXPR(vecBlueAttrLevel.size() == vecBlueAttrValue.size(), -1, "CEquip::genGodPinAttr blue star equipId:{} failed", base.item_id);

    for (int32_t i = 0; i < blueStar; i++)
    {
        CHECK_EXPR(vecBlueAttrType.size(), -1, "CEquip::genGodPinAttr blue star equipId :{} failed", base.item_id);
        int32_t index = 0;
        if (randType == RandAttrType_rand)
        {
            index = NFRandInt(0, (int) vecBlueAttrType.size());
        }

        proto_ff_s::BlueStarAttr_s t;
        t.id = vecBlueAttrType.at(index);
        t.value = vecBlueAttrValue.at(index);
        t.lv_part = vecBlueAttrLevel.at(index);
        CHECK_EXPR(t.id != proto_ff::A_NONE, -1, "CEquip::genGodPinAttr blue star equipId :{} failed attrid:0", base.item_id);

        equip_ext.blue[t.id] = t;

        vecBlueAttrType.erase(vecBlueAttrType.begin() + index);
        vecBlueAttrValue.erase(vecBlueAttrValue.begin() + index);
        vecBlueAttrLevel.erase(vecBlueAttrLevel.begin() + index);
    }

    return 0;
}

int NFGridItem::genGodZunAttr(SItemCond &itemCond)
{
    auto pEquipAttrCfg = GetEquipAttrCfg();
    CHECK_NULL(pEquipAttrCfg);

    VEC_INT32 vecAttrType;
    VEC_INT32 vecAttrMin;
    VEC_INT32 vecAttrMax;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godattribute_type.ToString(), ",", &vecAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godattribute_valuemin.ToString(), ",", &vecAttrMin);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godattribute_valuemax.ToString(), ",", &vecAttrMax);
    int32_t typeSize = vecAttrType.size();
    int32_t minSize = vecAttrMin.size();
    int32_t maxSize = vecAttrMax.size();

    if (typeSize != minSize || typeSize != maxSize) return -1;

    for (int32_t i = 0; i < typeSize; i++)
    {
        equip_ext.god[vecAttrType[i]] += NFRandomInt(vecAttrMin[i], vecAttrMax[i]);
    }

    return 0;
}

int NFGridItem::genSpecialAttr(SItemCond &itemCond)
{
    auto pEquipAttrCfg = GetEquipAttrCfg();
    CHECK_NULL(pEquipAttrCfg);

    //1:生成特殊属性
    int32_t specDown = pEquipAttrCfg->m_specialattributedown;
    int32_t specUp = pEquipAttrCfg->m_specialattributeup;

    int32_t specNum = NFRandomInt(specDown, specUp);
    RandAttrType randType = RandAttrType_rand;

    if (itemCond.inittype == EInitAttrType::Common)
        randType = RandAttrType_rand;


    VEC_INT32 vecSpecAttrType;
    VEC_INT32 vecSpecAttrMin;
    VEC_INT32 vecSpecAttrMax;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_specialattribute_typelibrary.ToString(), ",", &vecSpecAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_specialattribute_valuemin.ToString(), ",", &vecSpecAttrMin);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_specialattribute_valuemax.ToString(), ",", &vecSpecAttrMax);

    bool ret = true;
    for (int32_t i = 0; i < specNum; i++)
    {
        proto_ff::Attr t;
        ret = RandAttr(vecSpecAttrType, vecSpecAttrMin, vecSpecAttrMax, randType, t);
        CHECK_EXPR(ret, -1, " CEquip::genSpecialAttr star equipId:{} failed", base.item_id);
        equip_ext.special[t.id()] += t.value();
    }

    return 0;
}

bool
NFGridItem::RandAttr(VEC_INT32 &vecAttrType, VEC_INT32 &vecAttrMinValue, VEC_INT32 &vecAttrMaxValue, RandAttrType randType, proto_ff::Attr &finAttr)
{
    //随机去重
    CHECK_EXPR(vecAttrType.size() > 0, false, "");
    CHECK_EXPR(vecAttrType.size() == vecAttrMinValue.size(), false, "");
    CHECK_EXPR(vecAttrMinValue.size() == vecAttrMaxValue.size(), false, "");

    int32_t attrIndex = NFRandInt(0, (int) vecAttrType.size());

    finAttr.set_id(vecAttrType.at(attrIndex));

    if (randType == RandAttrType_rand)
    {
        finAttr.set_value(NFRandomInt(vecAttrMinValue.at(attrIndex), vecAttrMaxValue.at(attrIndex)));
    }
    else if (randType == RandAttrType_min)
    {
        finAttr.set_value(vecAttrMinValue.at(attrIndex));
    }
    else if (randType == RandAttrType_max)
    {
        finAttr.set_value(vecAttrMaxValue.at(attrIndex));
    }

    vecAttrType.erase(vecAttrType.begin() + attrIndex);
    vecAttrMinValue.erase(vecAttrMinValue.begin() + attrIndex);
    vecAttrMaxValue.erase(vecAttrMaxValue.begin() + attrIndex);

    return true;
}

bool NFGridItem::IsProf(int32_t profId)
{
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "");

    VEC_INT32 vecProfession;;
    NFCommonApi::SplitStrToVecInt(pEquipCfg->m_profession.ToString(), ",", &vecProfession);
    if (std::find(vecProfession.begin(), vecProfession.end(), profId) == vecProfession.end() &&
        std::find(vecProfession.begin(), vecProfession.end(), 0) == vecProfession.end())
    {
        return false;
    }

    return true;

}

void NFGridItem::GetAllAttr(MAP_INT32_INT32& attrs, int32_t level)
{
    for (auto& e : equip_ext.base)
    {
        attrs[e.first] += e.second;
    }

    for (auto& e : equip_ext.star)
    {
        attrs[e.id] += e.value;
    }

    for (auto& e : equip_ext.god)
    {
        attrs[e.first] += e.second;
    }

    for (auto& e : equip_ext.special)
    {
        attrs[e.first] += e.second;
    }

    for (auto& e : equip_ext.blue)
    {
        attrs[e.first] += e.second.value * floor(level / e.second.lv_part);
    }
}