#include "ItemDescEx.h"
#include "DescStore/BoxBoxDesc.h"
#include "DescStore/SkillSkillDesc.h"
#include "DescStore/ConflatePropDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/ConditionConditionDesc.h"
#include "DescStore/EquipStoveexpDesc.h"
#include "DescStore/AvatarChangeDesc.h"
#include "NFComm/NFCore/NFRandom.hpp"

ItemDescEx::ItemDescEx()
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

ItemDescEx::~ItemDescEx()
{
}

int ItemDescEx::CreateInit()
{
    m_virMinId = 0;
    return 0;
}

int ItemDescEx::ResumeInit()
{
    return 0;
}

int ItemDescEx::Load()
{
    if (!Process())
    {
        return -1;
    }
    if (!ProcessTSActive())
    {
        return -1;
    }
    return 0;
}

int ItemDescEx::CheckWhenAllDataLoaded()
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_mapItemFunc Space Use, size:{} max_size:{} calc:{}", m_mapItemFunc.size(), m_mapItemFunc.max_size(), (double)m_mapItemFunc.size() * 100 / m_mapItemFunc.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_mapItemProfLimit Space Use, size:{} max_size:{} calc:{}", m_mapItemProfLimit.size(), m_mapItemProfLimit.max_size(), (double)m_mapItemProfLimit.size() * 100 / m_mapItemProfLimit.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_mapItemOrCdGroup Space Use, size:{} max_size:{} calc:{}", m_mapItemOrCdGroup.size(), m_mapItemOrCdGroup.max_size(), (double)m_mapItemOrCdGroup.size() * 100 / m_mapItemOrCdGroup.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_setNaturalBind Space Use, size:{} max_size:{} calc:{}", m_setNaturalBind.size(), m_setNaturalBind.max_size(), (double)m_setNaturalBind.size() * 100 / m_setNaturalBind.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_mapDecompose Space Use, size:{} max_size:{} calc:{}", m_mapDecompose.size(), m_mapDecompose.max_size(), (double)m_mapDecompose.size() * 100 / m_mapDecompose.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_mapEquipSmelt Space Use, size:{} max_size:{} calc:{}", m_mapEquipSmelt.size(), m_mapEquipSmelt.max_size(), (double)m_mapEquipSmelt.size() * 100 / m_mapEquipSmelt.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_mapItemUseCond Space Use, size:{} max_size:{} calc:{}", m_mapItemUseCond.size(), m_mapItemUseCond.max_size(), (double)m_mapItemUseCond.size() * 100 / m_mapItemUseCond.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_replaceItem Space Use, size:{} max_size:{} calc:{}", m_replaceItem.size(), m_replaceItem.max_size(), (double)m_replaceItem.size() * 100 / m_replaceItem.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_ts_active_id Space Use, size:{} max_size:{} calc:{}", m_ts_active_id.size(), m_ts_active_id.max_size(), (double)m_ts_active_id.size() * 100 / m_ts_active_id.max_size());
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_dynexp_items Space Use, size:{} max_size:{} calc:{}", m_dynexp_items.size(), m_dynexp_items.max_size(), (double)m_dynexp_items.size() * 100 / m_dynexp_items.max_size());
    
    return 0;
}

const NFShmVector<int64_t, MAX_ITEM_FUNC_PARAM_NUM> *ItemDescEx::GetItemFuncParamCfg(uint64_t nItemId)
{
    auto iter = m_mapItemFunc.find(nItemId);
    return (iter != m_mapItemFunc.end()) ? &iter->second : nullptr;
}

int32_t ItemDescEx::GetItemOrGroupCd(uint64_t itemId_cdGroup)
{
    auto iter = m_mapItemOrCdGroup.find(itemId_cdGroup);
    return (iter != m_mapItemOrCdGroup.end()) ? iter->second : 0;
}

bool ItemDescEx::IsNautralBind(uint64_t nItemId)
{
    return m_setNaturalBind.find(nItemId) != m_setNaturalBind.end();
}

bool ItemDescEx::IsMatchProf(uint64_t itemid, uint8_t prof)
{
    if (0 == prof) //0 表示 通用职业，通用职业和任何物品都匹配
    {
        return true;
    }
    auto iter = m_mapItemProfLimit.find(itemid);
    if (iter == m_mapItemProfLimit.end()) //找不到表示物品是 通用职业
    {
        return true;
    }
    
    auto &setProf = iter->second;
    if (setProf.find(0) != setProf.end()) return true;
    
    auto iterProf = setProf.find(prof);
    return (iterProf != setProf.end()) ? true : false;
}

bool ItemDescEx::IsNotAllowMap(uint64_t itemid, uint64_t mapid)
{
    auto iter = m_mapItemMapLimit.find(itemid);
    if (iter == m_mapItemMapLimit.end())
    {
        return false;
    }
    auto &setmap = iter->second;
    auto iterf = setmap.find(mapid);
    return (iterf != setmap.end()) ? true : false;
}

uint64_t ItemDescEx::RandDeComposeEquip(int64_t star, int64_t rank, int64_t qua, int64_t prof, int64_t pos)
{
    uint64_t key = DE_COMPOSE_KEY(star,rank,qua,prof,pos);
    auto iter = m_mapDecompose.find(key);
    if (iter != m_mapDecompose.end())
    {
        auto &setEquip = iter->second;
        uint32_t isize = (uint32_t)setEquip.size();
        if (isize > 0)
        {
            uint32_t rnd = NFRandInt((uint32_t)0, isize);//0 - (isize -1)
            auto iterEquip = setEquip.begin();
            for (uint32_t i = 0; i < rnd; ++i)
            {
                ++iterEquip;
            }
            //校验下
            
            uint64_t itemid = (*setEquip.begin());
            if (iterEquip != setEquip.end())
            {
                itemid = (*iterEquip);
            }
            return itemid;
        }
    }
    return 0;
}

uint32_t ItemDescEx::AttrIdByItem(uint64_t itemId)
{
    int64_t offset = (int64_t)itemId - (int64_t)m_virMinId;
    if (offset > 0 && offset < VIR_ITEM_ID_MAX_OFFSET) return m_virOffset[offset];
    return 0;
}

uint64_t ItemDescEx::ItemIdByAttrId(uint32_t attrId)
{
    if (attrId <= 0 || attrId >= proto_ff::A_COMMON_END) return 0;
    uint16_t offset = m_virAttr[attrId];
    if (offset > 0) return (uint64_t)(m_virMinId + offset);
    return 0;
}

const NFShmHashMap<uint64_t, uint64_t, 10> *ItemDescEx::GetItemFixAttr(uint64_t nItemId)
{
    auto iter = m_mapFixAttr.find(nItemId);
    if (iter == m_mapFixAttr.end())
        return nullptr;
    return &iter->second;
}

const NFShmHashMap<uint64_t, uint64_t, MAX_EQUIP_SMELT_EQUIP_MAX_ITEM_NUM> *ItemDescEx::GetSmeltMaterialCfg(uint64_t equipid)
{
    auto iter = m_mapEquipSmelt.find(equipid);
    return (iter != m_mapEquipSmelt.end()) ? &iter->second : nullptr;
}

bool ItemDescEx::CheckItemUseCond(uint64_t itemid, proto_ff::StatisticDataProto &proto)
{
    auto iterItem = m_mapItemUseCond.find(itemid);
    if (iterItem == m_mapItemUseCond.end())
    {
        return true;
    }
    auto &setCond = iterItem->second; //每个条件之间为或关系
    if (setCond.size() <= 0)
    {
        return true;
    }
    bool result = true;
    auto itercond = setCond.begin();
    for (; itercond != setCond.end(); ++itercond)
    {
        int64_t condid = (*itercond);
        auto pCondCfg = ConditionConditionDesc::Instance()->GetDesc(condid);
        if (nullptr == pCondCfg)
        {
            continue;
        }
        if (CheckItemUseCond(pCondCfg,proto))
        {
            return true;
        }
        result = false;
    }
    //
    return result;
}

bool ItemDescEx::CheckItemUseCond(const proto_ff_s::E_ConditionCondition_s *pCondCfg, proto_ff::StatisticDataProto &proto)
{
    if (nullptr == pCondCfg)
    {
        return false;
    }

/*
	1.等级
	2.今日充值金额
	3.历史充值总额
	4.历史登陆天数
	*/
    
    bool result = true;
    //条件列表中条件之间是并且的关系
    for (auto iter = pCondCfg->m_condition.begin(); iter != pCondCfg->m_condition.end(); ++iter)
    {
        const proto_ff_s::E_ConditionConditionConditionDesc_s &info = (*iter);
        if (1 == info.m_Type)
        {
            result = (proto.level() >= info.m_Param);
        }
        else if (2 == info.m_Type)
        {
            result = (proto.today_rmb() >= (uint32_t)info.m_Param);
        }
        else if (3 == info.m_Type)
        {
            result = (proto.total_rmb() >= (uint32_t)info.m_Param);
        }
        else if (4 == info.m_Type)
        {
            result = (proto.total_login_day() >= (uint32_t)info.m_Param);
        }
        if (!result)
        {
            return false;
        }
    }
    return result;
}

int32_t ItemDescEx::GetEquipStoveExp(int32_t wearQuality, int32_t quality)
{
    auto pDesc = EquipStoveexpDesc::Instance()->GetDescByWearqualityQuality(wearQuality, quality);
    if (pDesc)
    {
        return pDesc->m_exp;
    }
    return 0;
}

bool ItemDescEx::replaceItem(uint64_t itemId, int32_t num, uint64_t &outItemId, int32_t &outNum)
{
    auto iter = m_replaceItem.find(itemId);
    if (iter == m_replaceItem.end()) return false;
    outItemId = iter->second.first;
    outNum = iter->second.second * num;
    return true;
}

bool ItemDescEx::IsTianShenActiveNum(const proto_ff_s::E_ItemItem_s *itemCfg)
{
    CHECK_EXPR(itemCfg, false, "");
    if (itemCfg->m_itemType == 3 && itemCfg->m_subType == 56) //天神激活物品
    {
        return true;
    }
    return false;
}

int32_t ItemDescEx::GetTianShenId(uint64_t itemId)
{
    auto iter = m_ts_active_id.find(itemId);
    return iter != m_ts_active_id.end() ? iter->second : 0;
}

bool ItemDescEx::IsDynExpItem(uint64_t itemId)
{
    auto iter = m_dynexp_items.find(itemId);
    return iter != m_dynexp_items.end();
}

int32_t ItemDescEx::GetDynExpType(uint64_t itemId)
{
    auto iter = m_dynexp_items.find(itemId);
    return iter != m_dynexp_items.end() ? iter->second : 0;
}

bool ItemDescEx::Process()
{
    auto pItemMapCfg = ItemItemDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pItemMapCfg, false, "");
    
    MAP_UINT64_UINT32 mapVirtualItemAttr;
    MAP_UINT32_UINT64 mapAttrVirtualItem;
    MAP_UINT32_UINT64 mapDynExpItem;
    uint64_t minVirtualItemId = 0;
    //
    for (auto iter = pItemMapCfg->begin(); iter != pItemMapCfg->end(); ++iter)
    {
        const proto_ff_s::E_ItemItem_s &itemCfg = iter->second;
        if (itemCfg.m_bindType == 1)
            m_setNaturalBind.insert(itemCfg.m_id);
        
        //使用条件
        string strcond = itemCfg.m_usecondition.data();
        if (strcond.length() > 0)
        {
            SET_INT64 setCond;
            setCond.clear();
            NFCommonApi::SplitStrToSetInt(strcond, ",", &setCond);
            for (auto itercond = setCond.begin(); itercond != setCond.end(); ++itercond)
            {
                int64_t cond = (*itercond);
                //校验条件表
                auto pCondCfg =  ConditionConditionDesc::Instance()->GetDesc(cond);
                if (nullptr == pCondCfg)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process...nullptr == pCondCfg...itemid:%lu,cond:%ld",itemCfg.m_id,cond);
                    return false;
                }
            }
            if (setCond.size() > 0)
            {
                m_mapItemUseCond[itemCfg.m_id] = setCond;
            }
        }
        
        //地图限制
        if (itemCfg.m_useLimit.length() > 0)
        {
            SET_INT64 setmap;
            setmap.clear();
            NFCommonApi::SplitStrToSetInt(itemCfg.m_useLimit.data(), ",", &setmap);
            m_mapItemMapLimit[itemCfg.m_id] = setmap;
        }
        
        //职业限制 0通用职业，1战士，2法师，3刺客，4射手
        SET_INT32 setProfLimit;
        setProfLimit.clear();
        string profreq = itemCfg.m_profession.data();
        NFCommonApi::SplitStrToSetInt(profreq, ",", &setProfLimit);
        if (setProfLimit.empty()) setProfLimit.insert(0);
        SET_INT32::iterator iterProf = setProfLimit.find(0);
        if (iterProf == setProfLimit.end())
        {
            m_mapItemProfLimit[itemCfg.m_id] = setProfLimit;
        }
        
        VEC_INT64 vecParam;
        vecParam.clear();
        string strParam = itemCfg.m_functionValue.data();
        if (itemCfg.m_functionType <= (int32_t)EItemFuncType::EItemFuncType_None
            || itemCfg.m_functionType >= (int32_t)EItemFuncType::EItemFuncType_Limit
            )
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....func type error ....itemid:%lu, functype:%d ", itemCfg.m_id, itemCfg.m_functionType);
            //return false;
        }
        if ((int32_t)EItemFuncType::EItemFuncType_NoFunc != itemCfg.m_functionType)
        {
            NFCommonApi::SplitStrToVecInt(strParam, ";", &vecParam);
            if ((int32_t)EItemFuncType::EItemFuncType_ModifyAttr == itemCfg.m_functionType)
            {
                if (vecParam.size() < 3)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....vecParam.size() < 3....itemid:%lu, functype:%d ", itemCfg.m_id,itemCfg.m_functionType);
                    return false;
                }
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_AddAttrForever == itemCfg.m_functionType)
            {
                if (vecParam.size() < 2)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....vecParam.size() <2....itemid:%lu, functype:%d ", itemCfg.m_id, itemCfg.m_functionType);
                    return false;
                }
                int32_t attrId = (int32_t)vecParam.at(0);
                if (attrId <= proto_ff::A_NONE || attrId > proto_ff::A_BASE_END)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....AddAttrForever attrid error....itemid:%lu, functype:%d, strParam:%s,attrId:%u ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str(), attrId);
                    return false;
                }
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_Box == itemCfg.m_functionType
                || (int32_t)EItemFuncType::EItemFuncType_SelectBox == itemCfg.m_functionType
                )
            {
                //宝箱,自选宝箱
                if (vecParam.size() < 1)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....Box item, param count error....itemid:%lu, strParam:%s ", itemCfg.m_id, strParam.c_str());
                    return false;
                }
                int64_t boxId = vecParam.at(0);
                auto pBoxCfg = BoxBoxDesc::Instance()->GetDesc(boxId);
                if (nullptr == pBoxCfg)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....Box item,  can not find box config....itemid:%lu, strParam:%d, boxId:%ld ", itemCfg.m_id, strParam.c_str(), boxId);
                    return false;
                }
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_HangCard == itemCfg.m_functionType)
            {
                if (vecParam.size() < 1)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process105....vecParam.size() < 1....itemid:%lu, functype:%d, strParam:%s ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str());
                    return false;
                }
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_addSkill == itemCfg.m_functionType)
            {
                if (vecParam.size() < 1)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....addskill item, param count error....itemid:%lu, strParam:%s ", itemCfg.m_id, strParam.c_str());
                    return false;
                }
                int64_t skillId = vecParam.at(0);
                auto pskillcfg =  SkillSkillDesc::Instance()->GetDesc(skillId);
                if (nullptr == pskillcfg)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....addskill item, can not find skill config....itemid:%lu, strParam:%s, skillId:%ld ", itemCfg.m_id, strParam.c_str(), skillId);
                    return false;
                }
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_AddVipExp == itemCfg.m_functionType)
            {
                if (vecParam.size() < 1)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....addvipexp item, param count error....itemid:%lu, strParam:%s ", itemCfg.m_id, strParam.c_str());
                    return false;
                }
                int64_t skillId = vecParam.at(0);
                auto pskillcfg =  SkillSkillDesc::Instance()->GetDesc(skillId);
                if (nullptr == pskillcfg)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....addvipexp item, can not find skill config....itemid:%lu, strParam:%s, skillId:%ld ", itemCfg.m_id, strParam.c_str(), skillId);
                    return false;
                }
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_Virtual == itemCfg.m_functionType)
            {
                if (vecParam.size() < 1)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process106....vecParam.size() < 1....itemid:%lu, functype:%d, strParam:%s ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str());
                    return false;
                }
                uint32_t attrId = (uint32_t)vecParam.at(0);
                if (attrId <= proto_ff::A_FIGHT_END || attrId >= proto_ff::A_COMMON_END)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process106....virtual item attrId error....itemid:%lu, functype:%d, strParam:%s,attrId:%u ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str(), attrId);
                    return false;
                }
                MAP_UINT64_UINT32::iterator iterA = mapVirtualItemAttr.find(itemCfg.m_id);
                if (iterA != mapVirtualItemAttr.end())
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process106....repeated virtual item id....itemid:%lu, functype:%d, strParam:%s,attrId:%u ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str(), attrId);
                    return false;
                }
                MAP_UINT32_UINT64::iterator iterB = mapAttrVirtualItem.find(attrId);
                if (iterB != mapAttrVirtualItem.end())
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process106....repeated virtual item attrid....itemid:%lu, functype:%d, strParam:%s,attrId:%u,attr_itemid:%lu ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str(), attrId, iterB->second);
                    return false;
                }
                if (minVirtualItemId <= 0 || (int64_t)minVirtualItemId > itemCfg.m_id) minVirtualItemId = (uint64_t)itemCfg.m_id;
                mapVirtualItemAttr[itemCfg.m_id] = attrId;
                mapAttrVirtualItem[attrId] = itemCfg.m_id;
                
            }
            else if ((int32_t)EItemFuncType::EItemFuncType_dynExp == itemCfg.m_functionType)
            {
                if (vecParam.size() < 1)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::EItemFuncType_dynExp....vecParam.size() < 1....itemid:%lu, functype:%d, strParam:%s ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str());
                    return false;
                }
                int64_t dynExpType = vecParam.at(0);
                if (dynExpType != 1 && dynExpType != 2)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::EItemFuncType_dynExp... type error.....itemid:%lu, functype:%d, strParam:%s ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str());
                    return false;
                }
                auto iter1 = mapDynExpItem.insert(std::make_pair(dynExpType, itemCfg.m_id));
                if (!iter1.second )
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::EItemFuncType_dynExp... repeated error.....itemid:%lu, functype:%d, strParam:%s ", itemCfg.m_id, itemCfg.m_functionType, strParam.c_str());
                    return false;
                }
                m_dynexp_items[itemCfg.m_id] = dynExpType;
            }
        }
        m_mapItemFunc[itemCfg.m_id] = vecParam;
        //物品进背包可以被替换
        if (IsTianShenActiveNum(&itemCfg)) //天神成品
        {
            auto pConflateCfg = ConflatePropDesc::Instance()->GetDesc(itemCfg.m_id);
            if (pConflateCfg && pConflateCfg->m_elem.size()>0)
            {
                std::pair<int32_t, int32_t> t;
                t.first = pConflateCfg->m_elem.at(0).m_id;
                t.second = pConflateCfg->m_elem.at(0).m_num;
                m_replaceItem[itemCfg.m_id] = t;
            }
        }
    }
    //处理虚拟物品对应的属性ID
    m_virMinId = minVirtualItemId;
    if (minVirtualItemId > 0) m_virMinId = minVirtualItemId - 1;
    for (auto &itervir : mapVirtualItemAttr)
    {
        uint64_t itemid = itervir.first;
        uint32_t attrid = itervir.second;
        if (itemid > (m_virMinId + VIR_ITEM_ID_MAX_OFFSET) )
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process201....itemid > (m_virMinId + VIR_ITEM_ID_MAX_OFFSET)....itemid:%lu, m_virMinId:%lu, offset:%u,attrid:%u",itemid,m_virMinId,(uint32_t)VIR_ITEM_ID_MAX_OFFSET, attrid);
            return false;
        }
        uint16_t offset = (uint16_t)(itemid - m_virMinId);
        m_virOffset[offset] = attrid;
        m_virAttr[attrid] = offset;
    }
    
    auto pMapEquip = EquipEquipDesc::Instance()->GetResDescPtr();
    if (pMapEquip)
    {
        for (auto iterEquip = pMapEquip->begin(); iterEquip != pMapEquip->end(); iterEquip++)
        {
            const proto_ff_s::E_EquipEquip_s &info = iterEquip->second;
            //
            if (iterEquip->second.m_isCanbind == 1)
            {
                m_setNaturalBind.insert(iterEquip->first);
            }
            
            //
            int64_t star = info.m_star;
            int64_t rank = info.m_wearQuality;
            int64_t qua = info.m_quality;
            int64_t pos = info.m_position;
            
            //职业限制 0通用职业，1战士，2法师，3刺客，4射手
            SET_INT32 setProfLimit;
            setProfLimit.clear();
            string profreq = iterEquip->second.m_profession.data();
            NFCommonApi::SplitStrToSetInt(profreq, ",", &setProfLimit);
            SET_INT32::iterator iterProf = setProfLimit.find(0);
            if (iterProf == setProfLimit.end())
            {
                m_mapItemProfLimit[iterEquip->second.m_id] = setProfLimit;
                //
                iterProf = setProfLimit.begin();
                for (; iterProf != setProfLimit.end(); ++iterProf)
                {
                    uint64_t decomposeKey = DE_COMPOSE_KEY(star, rank, qua, (*iterProf), pos);
                    auto iterDecompose = m_mapDecompose.find(decomposeKey);
                    if (iterDecompose != m_mapDecompose.end())
                    {
                        iterDecompose->second.insert(info.m_id);
                    }
                    else
                    {
                        SET_UINT64 setEquip;
                        setEquip.insert(info.m_id);
                        m_mapDecompose[decomposeKey] = setEquip;
                    }
                }
            }
            else
            {
                for (int32_t i = proto_ff::ERoleProf_MIN; i <= proto_ff::ERoleProf_MAX; ++i)
                {
                    uint64_t decomposeKey = DE_COMPOSE_KEY(star, rank, qua, i, pos);
                    auto iterDecompose = m_mapDecompose.find(decomposeKey);
                    if (iterDecompose != m_mapDecompose.end())
                    {
                        iterDecompose->second.insert(info.m_id);
                    }
                    else
                    {
                        SET_UINT64 setEquip;
                        setEquip.insert(info.m_id);
                        m_mapDecompose[decomposeKey] = setEquip;
                    }
                }
            }
            
            //熔炼
            string strsmelt = info.m_meltingResult.data();
            if (strsmelt.length() > 0)
            {
                VEC_INT64 vecParam;
                vecParam.clear();
                NFCommonApi::SplitStrToVecInt(strsmelt, ";", &vecParam);
                //
                int32_t isize = (int32_t)vecParam.size();
                if ((isize % 2) != 0)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process...equip smelt format error...(isize % 2) != 0...equipid:%lu,isize:%d,str:%s",info.m_id,isize,strsmelt.c_str());
                    return false;
                }
                VEC_INT64::iterator iterSmelt = vecParam.begin();
                while (iterSmelt != vecParam.end())
                {
                    int64_t itemid = (*iterSmelt);
                    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(itemid);
                    if (nullptr == pItemCfg)
                    {
                        auto pEqupCfg = EquipEquipDesc::Instance()->GetDesc(itemid);
                        if (nullptr == pEqupCfg)
                        {
                            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process...equip smelt can not find item config...nullptr == pEqupCfg...equipid:%lu,itemid:%lu", info.m_id,itemid);
                            return false;
                        }
                    }
                    //
                    int64_t num = 0;
                    //
                    ++iterSmelt;
                    if (iterSmelt != vecParam.end())
                    {
                        num = (*iterSmelt);
                    }
                    if (num <= 0)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process...equip smelt num <= 0...equipid:%lu,itemid:%lu,num:%ld", info.m_id, itemid, num);
                        return false;
                    }
                    //
                    auto iterMlt = m_mapEquipSmelt.find(info.m_id);
                    if (iterMlt != m_mapEquipSmelt.end())
                    {
                        auto &mapSmelt = iterMlt->second;
                        auto iterA = mapSmelt.find(itemid);
                        if (iterA != mapSmelt.end())
                        {
                            iterA->second += num;
                        }
                        else
                        {
                            mapSmelt[itemid] = num;
                        }
                    }
                    else
                    {
                        MAP_UINT64_UINT64 mapSmelt;
                        mapSmelt[itemid] = num;
                        m_mapEquipSmelt[info.m_id] = mapSmelt;
                    }
                    
                    //
                    ++iterSmelt;
                } // end of while (iterSmelt != vecParam.end())
            } // end of if (strsmelt.length() > 0)
            
        }
    }
    
    return true;
}

bool ItemDescEx::ProcessTSActive()
{
    auto pCfgMap = AvatarChangeDesc::Instance()->GetResDescPtr();
    for (auto& e : *pCfgMap)
    {
        m_ts_active_id[e.second.m_activationItem] = e.second.m_id;
    }
    
    return true;
}

