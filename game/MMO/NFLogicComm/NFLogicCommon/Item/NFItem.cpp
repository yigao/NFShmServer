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
#include "NFLogicCommon/NFCharactorDefine.h"

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
    
    m_baseAttrPercent = 0;
    m_starAttrPercent = 0;
    m_godAttrPercent = 0;
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
        m_byType = pItemCfg->m_itemType;
        m_nLevel = pItemCfg->m_level;
        if (pItemCfg->m_time > 0)
        {
            m_nExpiredTime = NFTime::Now().UnixSec() + pItemCfg->m_time;
        }
        
        return true;
    }
    
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    
    if (!(pEquipCfg->m_type == proto_ff::EPackageType_shenji_aq ||
        pEquipCfg->m_type == proto_ff::EPackageType_shenji_lj ||
        pEquipCfg->m_type == proto_ff::EPackageType_turn ||
        pEquipCfg->m_type == proto_ff::EPackageType_YaoHun
    ))
    {
        auto pEquipAttrCfg = GetEquipAttributeCfg();
        CHECK_EXPR(pEquipAttrCfg, false, "itemId:{} attrId:%d find", nItemID, pEquipCfg->m_attributeID);
    }
    
    m_nLevel = pEquipCfg->m_level;
    if (pEquipCfg->m_time > 0)
    {
        m_nExpiredTime = NFTime::Now().UnixSec() + pEquipCfg->m_time;
    }
    
    CHECK_EXPR(genBaseAttr(itemCond), false, "");
    CHECK_EXPR(genGodPinAttr(itemCond), false, "");
    CHECK_EXPR(genGodZunAttr(itemCond), false, "");
    
    GenBaseScore();
    
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
        return EquipAttributeDesc::Instance()->GetDesc(pEquipCfg->m_attributeID);
    }
    return NULL;
}

bool NFItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
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
            CHECK_EXPR(pEquipAttrCfg, false, "[logic] CEquip::FromItemProto itemId:{} attrId:{} find", m_nItemID, pEquipCfg->m_attributeID);
        }
        
        m_baseAttrPercent = protoItem.base_attr_percent();
        m_starAttrPercent = protoItem.star_attr_percent();
        m_godAttrPercent = protoItem.star_attr_percent();
    }
    
    return true;
}

bool NFItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    SaveDB(protoItem);
    
    auto pEquipCfg = GetEquipCfg();
    if (pEquipCfg)
    {
        MAP_INT32_INT32 baseAttr = GetBaseAttr();
        for (auto iter = baseAttr.begin(); iter != baseAttr.end(); iter++)
        {
            auto pBase = protoItem.add_base();
            pBase->set_id(iter->first);
            pBase->set_value(iter->second);
        }
        
        VEC_STAR_ATTR starAttr = GetStarAttr();
        for (int i = 0; i < (int) starAttr.size(); i++)
        {
            auto pStar = protoItem.add_refine();
            pStar->set_id(starAttr[i].id);
            pStar->set_value(starAttr[i].value);
        }
        
        MAP_BLUE_ATTR blueAttr = GetBlueAttr();
        for (auto iter = blueAttr.begin(); iter != blueAttr.end(); iter++)
        {
            auto pBlue = protoItem.add_blue();
            pBlue->set_id(iter->second.id);
            pBlue->set_value(iter->second.value);
            pBlue->set_lv_part(iter->second.lv_part);
        }
        
        MAP_INT32_INT32 godAttr = GetGodAttr();
        for (auto iter = godAttr.begin(); iter != godAttr.end(); iter++)
        {
            auto pBase = protoItem.add_god();
            pBase->set_id(iter->first);
            pBase->set_value(iter->second);
        }
    }
    return true;
}

bool NFItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    protoItem.set_index(m_nIndex);
    protoItem.set_item_id(m_nItemID);
    protoItem.set_item_num(m_nNum);
    protoItem.set_bind(m_byBind);
    protoItem.set_level(m_nLevel);
    protoItem.set_expiretime(m_nExpiredTime);
    
    auto pEquipCfg = GetEquipCfg();
    if (pEquipCfg)
    {
        protoItem.set_base_attr_percent(m_baseAttrPercent);
        protoItem.set_star_attr_percent(m_starAttrPercent);
        protoItem.set_star_attr_percent(m_godAttrPercent);
    }
    
    return true;
}

void NFItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    if (pEquipAttrCfg == NULL)
        return;
    
    MAP_INT32_INT32 baseAttr = GetBaseAttr();
    VEC_STAR_ATTR starAttr = GetStarAttr();
    MAP_BLUE_ATTR blueAttr = GetBlueAttr();
    MAP_INT32_INT32 godAttr = GetGodAttr();
    
    for (auto &e : baseAttr)
    {
        attrs[e.first] += e.second;
    }
    
    for (auto &e : starAttr)
    {
        attrs[e.id] += e.value;
    }
    
    for (auto &e : godAttr)
    {
        attrs[e.first] += e.second;
    }
    
    for (auto &e : blueAttr)
    {
        attrs[e.first] += e.second.value * floor(level / e.second.lv_part);
    }
}

MAP_INT32_INT32 NFItem::GetBaseAttr()
{
    MAP_INT32_INT32 mapAttr;
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, mapAttr, "");
    
    for (auto &e : pEquipAttrCfg->m_attribute)
    {
        int32_t attrId = e.m_type;
        CHECK_CONTINUE(attrId != proto_ff::A_NONE);
        //暂时处理普通生成
        if (m_baseAttrPercent > 0)
        {
            mapAttr[attrId] += e.m_valueMin + ((double) m_baseAttrPercent / (double) TEN_THOUSAND) * (e.m_valueMax - e.m_valueMin);
        }
    }
    
    return mapAttr;
}

bool NFItem::genBaseAttr(SItemCond &itemCond)
{
    if (itemCond.inittype == EInitAttrType::Common)
    {
        m_baseAttrPercent = NFRandomInt(1, TEN_THOUSAND);
    }
    
    return true;
}

VEC_STAR_ATTR NFItem::GetStarAttr()
{
    VEC_STAR_ATTR attrMap;
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, attrMap, "");
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, attrMap, "");
    
    //1:生成星级属性
    uint32_t starLv = pEquipCfg->m_star;
    if (starLv > pEquipAttrCfg->m_star_Library.size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "equipId:{} star:{} error", m_nItemID, starLv);
        return attrMap;
    }
    
    for (uint32_t i = 0; i < starLv; i++)
    {
        std::string starLibary = pEquipAttrCfg->m_star_Library.at(i).data();
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
            return attrMap;
        }
        
        stStarAttr t;
        t.id = vecStarInt.at(0);
        t.value = vecStarInt.at(1) + ((double) m_starAttrPercent / (double) TEN_THOUSAND) * (vecStarInt.at(2) - vecStarInt.at(1));
        attrMap.push_back(t);
    }
    return attrMap;
}

MAP_BLUE_ATTR NFItem::GetBlueAttr()
{
    MAP_BLUE_ATTR attrMap;
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, attrMap, "");
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, attrMap, "");
    
    //2:生成蓝星属性
    int32_t blueStar = pEquipAttrCfg->m_blueStarNum;
    
    VEC_INT32 vecBlueAttrType;
    VEC_INT32 vecBlueAttrLevel;
    VEC_INT32 vecBlueAttrValue;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_blueStar_type.data(), ";", &vecBlueAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_blueStar_lv.data(), ";", &vecBlueAttrLevel);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_blueStar_number.data(), ";", &vecBlueAttrValue);
    
    CHECK_EXPR(vecBlueAttrType.size() == vecBlueAttrLevel.size(), attrMap, "CEquip::genGodPinAttr blue star equipId:{} failed", m_nItemID);
    CHECK_EXPR(vecBlueAttrLevel.size() == vecBlueAttrValue.size(), attrMap, "CEquip::genGodPinAttr blue star equipId:{} failed", m_nItemID);
    CHECK_EXPR(vecBlueAttrType.size() >= (uint32_t) blueStar, attrMap, "CEquip::genGodPinAttr blue star equipId:{} failed", m_nItemID);
    
    for (int32_t i = 0; i < blueStar; i++)
    {
        CHECK_EXPR(vecBlueAttrType.size(), attrMap, "CEquip::genGodPinAttr blue star equipId : {} failed", m_nItemID);
        
        stBlueAttr t;
        t.id = vecBlueAttrType.at(i);
        t.value = vecBlueAttrValue.at(i);
        t.lv_part = vecBlueAttrLevel.at(i);
        CHECK_EXPR(t.id != proto_ff::A_NONE, attrMap, "CEquip::genGodPinAttr blue star equipId : {} failed attrid:0", m_nItemID);
        
        attrMap[t.id] = t;
    }
    
    return attrMap;
}

bool NFItem::genGodPinAttr(SItemCond &itemCond)
{
    m_starAttrPercent = NFRandomInt(1, TEN_THOUSAND);
    return true;
}

MAP_INT32_INT32 NFItem::GetGodAttr()
{
    MAP_INT32_INT32 mapAttr;
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, mapAttr, "");
    auto pEquipAttrCfg = GetEquipAttributeCfg();
    CHECK_EXPR(pEquipAttrCfg, mapAttr, "");
    
    VEC_INT32 vecAttrType;
    VEC_INT32 vecAttrMin;
    VEC_INT32 vecAttrMax;
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godAttribute_type.data(), ",", &vecAttrType);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godAttribute_valueMin.data(), ",", &vecAttrMin);
    NFCommonApi::SplitStrToVecInt(pEquipAttrCfg->m_godAttribute_valueMax.data(), ",", &vecAttrMax);
    int32_t typeSize = vecAttrType.size();
    int32_t minSize = vecAttrMin.size();
    int32_t maxSize = vecAttrMax.size();
    
    if (typeSize != minSize || typeSize != maxSize)
        return mapAttr;
    
    for (int32_t i = 0; i < typeSize; i++)
    {
        mapAttr[vecAttrType[i]] += vecAttrMin[i] + ((double) m_godAttrPercent / (double) TEN_THOUSAND) * (vecAttrMax[i] - vecAttrMin[i]);
    }
    return mapAttr;
}

bool NFItem::genGodZunAttr(SItemCond &itemCond)
{
    m_godAttrPercent = NFRandomInt(1, TEN_THOUSAND);
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

bool NFDeityItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    
    CHECK_EXPR(pEquipCfg->m_type == proto_ff::EPackageType_DeityEquip, false, "");
    m_deityEquip.m_stronglv = 0;
    m_deityEquip.m_strongWearQuality = pEquipCfg->m_wearQuality;
    return true;
}

void NFDeityItem::UnInit()
{
    NFItem::UnInit();
}

bool NFDeityItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    CHECK_EXPR(NFItem::FromItemProto(protoItem), false, "");
    m_deityEquip.m_stronglv = protoItem.strong_lv();
    m_deityEquip.m_strongWearQuality = protoItem.strong_wear_quality();
    return true;
}

bool NFDeityItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFDeityItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::SaveDB(protoItem);
    protoItem.set_strong_lv(m_deityEquip.m_stronglv);
    protoItem.set_strong_wear_quality(m_deityEquip.m_strongWearQuality);
    return true;
}

void NFDeityItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    return NFItem::GetAllAttr(attrs, level);
}

bool NFBeastItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    
    CHECK_EXPR(pEquipCfg->m_type == proto_ff::EPackageType_BeastEquip, false, "");
    
    m_beastEquip.m_stronglv = 1;
    m_beastEquip.m_strongWearQuality = pEquipCfg->m_wearQuality;
    m_beastEquip.m_strongExp = 0;
    auto pBlueAttrCfg = EncyclopediaEquipexpvalueDesc::Instance()->GetDesc(m_nItemID);
    if (pBlueAttrCfg)
    {
        uint32_t blueNum = pBlueAttrCfg->m_goldAttAll >= pBlueAttrCfg->m_goldAtt ? (pBlueAttrCfg->m_goldAttAll - pBlueAttrCfg->m_goldAtt) : 0;
        if (blueNum > 0)
        {
            std::vector<std::pair<uint32_t, uint32_t>> vec;
            for (int i = 0; i < (int) pBlueAttrCfg->m_beastStar.size(); i++)
            {
                if (pBlueAttrCfg->m_beastStar[i].m_att > 0)
                {
                    vec.push_back(std::make_pair(pBlueAttrCfg->m_beastStar[i].m_att, pBlueAttrCfg->m_beastStar[i].m_num));
                }
            }
            
            std::random_shuffle(vec.begin(), vec.end());
            vec.resize(vec.size() < (uint32_t) blueNum ? vec.size() : blueNum);
            for (int i = 0; i < (int) vec.size(); i++)
            {
                m_beastEquip.m_blueAttr[vec[i].first] = vec[i].second;
            }
        }
        
        if (pBlueAttrCfg->m_goldAtt > 0)
        {
            std::vector<std::pair<uint32_t, uint32_t>> vec;
            for (int i = 0; i < (int) pBlueAttrCfg->m_goldStar.size(); i++)
            {
                if (pBlueAttrCfg->m_goldStar[i].m_att > 0)
                {
                    vec.push_back(std::make_pair(pBlueAttrCfg->m_goldStar[i].m_att, pBlueAttrCfg->m_goldStar[i].m_num));
                }
            }
            
            std::random_shuffle(vec.begin(), vec.end());
            vec.resize(vec.size() < (uint32_t) pBlueAttrCfg->m_goldAtt ? vec.size() : pBlueAttrCfg->m_goldAtt);
            
            for (int i = 0; i < (int) vec.size(); i++)
            {
                m_beastEquip.m_godAttr[vec[i].first] = vec[i].second;
            }
        }
    }
    return true;
}

void NFBeastItem::UnInit()
{
    NFItem::UnInit();
}

bool NFBeastItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    CHECK_EXPR(NFItem::FromItemProto(protoItem), false, "");
    m_beastEquip.m_stronglv = protoItem.strong_lv();
    m_beastEquip.m_strongWearQuality = protoItem.strong_wear_quality();
    m_beastEquip.m_strongExp = protoItem.strong_exp();
    for (int i = 0; i < (int) protoItem.misc_size(); i++)
    {
        m_beastEquip.m_blueAttr[protoItem.misc(i).id()] = protoItem.misc(i).value();
    }
    for (int i = 0; i < (int) protoItem.god_size(); i++)
    {
        m_beastEquip.m_godAttr[protoItem.god(i).id()] = protoItem.god(i).value();
    }
    return true;
}

bool NFBeastItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFBeastItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::SaveDB(protoItem);
    protoItem.set_strong_lv(m_beastEquip.m_stronglv);
    protoItem.set_strong_wear_quality(m_beastEquip.m_strongWearQuality);
    protoItem.set_strong_exp(m_beastEquip.m_strongExp);
    for (auto iter = m_beastEquip.m_blueAttr.begin(); iter != m_beastEquip.m_blueAttr.end(); iter++)
    {
        auto pAddr = protoItem.add_misc();
        pAddr->set_id(iter->first);
        pAddr->set_value(iter->second);
    }
    for (auto iter = m_beastEquip.m_godAttr.begin(); iter != m_beastEquip.m_godAttr.end(); iter++)
    {
        auto pAddr = protoItem.add_god();
        pAddr->set_id(iter->first);
        pAddr->set_value(iter->second);
    }
    return true;
}

void NFBeastItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool NFLongHunItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    CHECK_EXPR(pEquipCfg->m_type == proto_ff::EPackageType_Longhun, false, "");
    
    m_longHun.m_stronglv = 1;
    m_longHun.m_strongWearQuality = 1;
    m_longHun.m_strongWearQualityExp = 0;
    m_longHun.m_strongExp = 0;
    m_longHun.m_awaken_lv = 0;
    return true;
}

void NFLongHunItem::UnInit()
{
    NFItem::UnInit();
}

bool NFLongHunItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::FromItemProto(protoItem);
    m_longHun.m_stronglv = protoItem.strong_lv();
    m_longHun.m_strongWearQuality = protoItem.strong_wear_quality();
    m_longHun.m_strongWearQualityExp = protoItem.strong_wear_quality_exp();
    m_longHun.m_strongExp = protoItem.strong_exp();
    m_longHun.m_awaken_lv = protoItem.awaken_lv();
    return true;
}

bool NFLongHunItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFLongHunItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::SaveDB(protoItem);
    protoItem.set_strong_lv(m_longHun.m_stronglv);
    protoItem.set_strong_wear_quality(m_longHun.m_strongWearQuality);
    protoItem.set_strong_wear_quality_exp(m_longHun.m_strongWearQualityExp);
    protoItem.set_strong_exp(m_longHun.m_strongExp);
    protoItem.set_awaken_lv(m_longHun.m_awaken_lv);
    return true;
}

void NFLongHunItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool ShengjiItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    CHECK_EXPR(pEquipCfg->m_type == proto_ff::EPackageType_shenji_aq || pEquipCfg->m_type == proto_ff::EPackageType_shenji_lj, false, "");
    
    //神机装备处理
/*        stBestEQCfgEx* pBestCfg = g_GetBestEQCfg()->GetEquipCfg(pEquipCfg->id);
        chk_err_rv(pBestCfg, false, "[logic] CEquip::Init itemId:{} shenji not find", nItemID);
        m_makeid = g_GetBestEQCfg()->GetMakeId(pBestCfg->m_pCfg->grade, pBestCfg->m_pCfg->quality, pBestCfg->m_pCfg->star);
        m_state = 0;*/
    return true;
}

void ShengjiItem::UnInit()
{
    NFItem::UnInit();
}

bool ShengjiItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::FromItemProto(protoItem);
    m_shengji.m_makeid = protoItem.makeid();
    m_shengji.m_state = protoItem.state();
    return true;
}

bool ShengjiItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool ShengjiItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::SaveDB(protoItem);
    protoItem.set_makeid(m_shengji.m_makeid);
    protoItem.set_state(m_shengji.m_state);
    return true;
}

void ShengjiItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool NFGodEvilItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    CHECK_EXPR(proto_ff::EPackageType_GodEvil == pEquipCfg->m_type, false, "itemId:{}", nItemID);
    
    m_godEvil.m_stronglv = 0;
    m_godEvil.m_strongExp = 0;
    m_godEvil.m_strongWearQualityExp = 0;
    m_godEvil.m_make_time = itemCond.makeTime;
    m_godEvil.m_make_name = itemCond.makeName;
    return true;
}

void NFGodEvilItem::UnInit()
{
    NFItem::UnInit();
}

bool NFGodEvilItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::FromItemProto(protoItem);
    m_godEvil.m_stronglv = protoItem.strong_lv();
    m_godEvil.m_strongExp = protoItem.strong_exp();
    m_godEvil.m_strongWearQualityExp = protoItem.strong_wear_quality_exp();
    m_godEvil.m_make_time = protoItem.make_time();
    m_godEvil.m_make_name = protoItem.make_name();
    return true;
}

bool NFGodEvilItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFGodEvilItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::SaveDB(protoItem);
    protoItem.set_strong_lv(m_godEvil.m_stronglv);
    protoItem.set_strong_exp(m_godEvil.m_strongExp);
    protoItem.set_strong_wear_quality_exp(m_godEvil.m_strongWearQualityExp);
    protoItem.set_make_time(m_godEvil.m_make_time);
    protoItem.set_make_name(m_godEvil.m_make_name.data());
    return true;
}

void NFGodEvilItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool NFStarItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    CHECK_EXPR(pEquipCfg->m_type == proto_ff::EPackageType_star, false, "itemId:{}", nItemID);
    
    m_star.m_stronglv = 1;
    m_star.m_strongWearQuality = 1;
    m_star.m_strongExp = 0;
    m_star.m_strongWearQualityExp = 0;
    return true;
}

void NFStarItem::UnInit()
{
    NFItem::UnInit();
}

bool NFStarItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::FromItemProto(protoItem);
    m_star.m_stronglv = protoItem.strong_lv();
    m_star.m_strongWearQuality = protoItem.strong_wear_quality();
    m_star.m_strongExp = protoItem.strong_exp();
    m_star.m_strongWearQualityExp = protoItem.strong_wear_quality_exp();
    return true;
}

bool NFStarItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFStarItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    NFItem::SaveDB(protoItem);
    protoItem.set_strong_lv(m_star.m_stronglv);
    protoItem.set_strong_wear_quality(m_star.m_strongWearQuality);
    protoItem.set_strong_exp(m_star.m_strongExp);
    protoItem.set_strong_wear_quality_exp(m_star.m_strongWearQualityExp);
    return true;
}

void NFStarItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool NFMountKunItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    CHECK_EXPR(pEquipCfg->m_type == proto_ff::EPackageType_MountKun, false, "itemId:{}", nItemID);
    
    m_mountKun.m_stronglv = 0;
    m_mountKun.m_strongWearQuality = 0;
    m_mountKun.m_awaken_lv = 0;
    m_mountKun.m_awaken_exp = 0;
    m_mountKun.m_awaken_star = 0;
    return true;
}

void NFMountKunItem::UnInit()
{
    NFItem::UnInit();
}

bool NFMountKunItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::FromItemProto(protoItem);
}

bool NFMountKunItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFMountKunItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::SaveDB(protoItem);
}

void NFMountKunItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool NFTurnItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    
    return true;
}

void NFTurnItem::UnInit()
{
    NFItem::UnInit();
}

bool NFTurnItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::FromItemProto(protoItem);
}

bool NFTurnItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFTurnItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::SaveDB(protoItem);
}

void NFTurnItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

bool NFYaoHunItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    CHECK_EXPR(NFItem::Init(nIndex, nItemID, itemCond, nNum, byBind), false, "");
    auto pEquipCfg = GetEquipCfg();
    CHECK_EXPR(pEquipCfg, false, "itemId:{} not find, not item, not equp", nItemID);
    
    return true;
}

void NFYaoHunItem::UnInit()
{
    NFItem::UnInit();
}

bool NFYaoHunItem::FromItemProto(const proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::FromItemProto(protoItem);
}

bool NFYaoHunItem::ToItemProto(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::ToItemProto(protoItem);
}

bool NFYaoHunItem::SaveDB(proto_ff::ItemProtoInfo &protoItem)
{
    return NFItem::SaveDB(protoItem);
}

void NFYaoHunItem::GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level)
{
    NFItem::GetAllAttr(attrs, level);
}

