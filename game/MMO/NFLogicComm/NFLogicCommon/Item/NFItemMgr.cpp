// -------------------------------------------------------------------------
//    @FileName         :    NFItemMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemMgr
//
// -------------------------------------------------------------------------

#include "NFItemMgr.h"
#include "DescStoreEx/ItemDescEx.h"

bool NFItemMgr::IsVirItem(uint64_t itemId)
{
    return (ItemDescEx::Instance()->AttrIdByItem(itemId) > 0);
}

bool NFItemMgr::IsVirItem(uint64_t itemId, uint32_t &attrId)
{
    uint32_t attr = ItemDescEx::Instance()->AttrIdByItem(itemId);
    if (attr > 0)
    {
        attrId = attr;
        return true;
    }
    return false;
}

void NFItemMgr::FilterVirItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem, MAP_UINT32_INT64 &mapAttr)
{
    uint32_t attrId = 0;
    for (auto iter = lstItem.begin(); iter != lstItem.end(); ++iter)
    {
        const SItem &item = (*iter);
        attrId = 0;
        if (IsVirItem(item.nItemID, attrId))
        {
            if (item.nNum > 0)
            {
                mapAttr[attrId] += item.nNum;
            }
        }
        else
        {
            lstOutItem.push_back(item);
        }
    }
}

void NFItemMgr::FilterVirItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem)
{
    MAP_UINT32_INT64 mapAttr;
    FilterVirItem(lstItem, lstOutItem, mapAttr);
}

void NFItemMgr::FilterVirItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr)
{
    uint32_t attrId = 0;
    for (auto iter = vecProtoItemsEx.begin(); iter != vecProtoItemsEx.end(); ++iter)
    {
        const proto_ff::ItemProtoInfo &proto = (*iter);
        
        attrId = 0;
        if (IsVirItem(proto.item_id(), attrId))
        {
            if (proto.item_num() > 0)
            {
                mapAttr[attrId] += proto.item_num();
            }
        }
        else
        {
            vecOutProtoItemsEx.push_back(proto);
        }
    }
}

void NFItemMgr::FilterVirItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx)
{
    MAP_UINT32_INT64 mapAttr;
    FilterVirItem(vecProtoItemsEx, vecOutProtoItemsEx, mapAttr);
}

bool NFItemMgr::IsDynExpItem(uint64_t itemId)
{
    return ItemDescEx::Instance()->IsDynExpItem(itemId);
}

uint64_t NFItemMgr::GetItemFight(NFItem *pItem, int32_t level)
{
    return pItem->GetItemFight(level);
}

bool NFItemMgr::SetItemProtoInfo(NFItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, int64_t nNum)
{
    CHECK_EXPR(pItem, false, "");
    CHECK_EXPR(protoItemInfo, false, "");
    
    pItem->ToItemProto(*protoItemInfo);
    if (0 == nNum)
    {
        protoItemInfo->set_item_num(0);
    }
    else if (nNum > 0)
    {
        if ((uint32_t) nNum > pItem->GetNum())
        {
            protoItemInfo->set_item_num(pItem->GetNum());
        }
        else
        {
            protoItemInfo->set_item_num(nNum);
        }
    }
    else
    {
        //默认为小于0，这时候取传入物品参数pItem的数量
        protoItemInfo->set_item_num(pItem->GetNum());
    }
    
    return true;
}

int8_t NFItemMgr::BindStateByWay(uint64_t nItemId, int8_t byBind, int8_t bindWay)
{
    //非绑定状态才需要默认绑定规则处理
    if ((int8_t) EBindState::EBindState_bind == byBind)
    {
        return byBind;
    }
    
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(nItemId);
    if (nullptr == pItemCfg)
    {
        auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(nItemId);
        if (nullptr == pEquipCfg)
        {
            //物品不存在的时候返回 传入的绑定状态
            return byBind;
        }
        //需要根据获得途径 确定绑定状态，暂时使用配置表中的默认绑定字段
        return BindStateByWay(pEquipCfg, byBind, bindWay);
    }
    //
    return BindStateByWay(pItemCfg, byBind, bindWay);
}

int8_t NFItemMgr::BindStateByWay(const proto_ff_s::E_ItemItem_s *pItemCfg, int8_t byBind, int8_t bindWay)
{
    if ((int8_t) EBindState::EBindState_bind == byBind)
    {
        return byBind;
    }
    if (nullptr != pItemCfg && pItemCfg->m_bindType)
    {
        return (int8_t) EBindState::EBindState_bind;
    }
    return byBind;
}

int8_t NFItemMgr::BindStateByWay(const proto_ff_s::E_EquipEquip_s *pEquipCfg, int8_t byBind, int8_t bindWay)
{
    if ((int8_t) EBindState::EBindState_bind == byBind)
    {
        return byBind;
    }
    if (nullptr != pEquipCfg && pEquipCfg->m_isCanbind)
    {
        return (int8_t) EBindState::EBindState_bind;
    }
    return byBind;
}

bool NFItemMgr::ItemMaxPile(uint64_t itemId, int64_t& maxPile)
{
    maxPile = 1;
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(itemId);
    if (nullptr == pItemCfg)
    {
        auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(itemId);
        if (pEquipCfg == nullptr)
        {
            return false;
        }
        maxPile = ItemMaxPile(pEquipCfg);
    }
    else
    {
        maxPile = ItemMaxPile(pItemCfg);
    }
    return true;
}

int64_t NFItemMgr::ItemMaxPile(const proto_ff_s::E_ItemItem_s *pItemCfg)
{
    int64_t maxPile = 1;
    if (nullptr != pItemCfg)
    {
        if (IsVirItem(pItemCfg->m_id))
        {
            //虚拟物品,对叠数是int64_t 类型上限
            maxPile = INT64_MAX;
        }
        else
        {
            maxPile = (pItemCfg->m_stackLimit < 1) ? 1 : pItemCfg->m_stackLimit;
        }
    }
    return maxPile;
}

int64_t NFItemMgr::ItemMaxPile(const proto_ff_s::E_EquipEquip_s *pEquipCfg)
{
    int64_t maxPile = 1;
    if (nullptr != pEquipCfg)
    {
        maxPile = 1;//装备默认为1
    }
    return maxPile;
}

bool NFItemMgr::ValidBindWay(int8_t bindWay)
{
    if (bindWay > EItemBindWay_None && bindWay < EItemBindWay_Limit)
    {
        return true;
    }
    return false;
}

bool NFItemMgr::ValidForbidType(int8_t forbidType)
{
    if (forbidType > EItemForbidType_None && forbidType < EItemForbidType_Limit)
    {
        return true;
    }
    return false;
}

bool NFItemMgr::ValidInitAttrType(int8_t initAttrType)
{
    return (initAttrType > (int8_t) EInitAttrType::None && initAttrType < (int8_t) EInitAttrType::Limit);
}

bool NFItemMgr::CanTrade(uint64_t itemId, int8_t byInBind)
{
    /*
    绑定的 不可交易
    未绑定的  可交易
    */
    return ((int8_t) EBindState::EBindState_no == byInBind);
}

bool NFItemMgr::CanSell(uint64_t itemId, int8_t byInBind)
{
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(itemId);
    if (pItemCfg == NULL)
    {
        return false;
    }
    
    if (pItemCfg->m_sellPrice <= 0)
    {
        return false;
    }
    
    return true;
}

bool NFItemMgr::IsTaskItem(uint64_t itemId)
{
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(itemId);
    if (nullptr != pItemCfg && proto_ff::EItemType_Task == pItemCfg->m_itemType)
    {
        return true;
    }
    return false;
}

bool NFItemMgr::CreateItem(const LIST_ITEM &lstItem, VEC_PACKAGE_ITEM &vecItems, SItemCond &itemCond, bool bMerge)
{
    if (!ValidInitAttrType((int8_t) itemCond.inittype))
    {
        return false;
    }
    
    if (lstItem.size() <= 0)
    {
        return true;
    }
    
    LIST_ITEM lstOutItem;
    if (bMerge)
    {
        MergeItem(lstItem, lstOutItem);
    }
    else
    {
        lstOutItem = lstItem;
    }
    
    for (auto iter = lstOutItem.begin(); iter != lstOutItem.end(); ++iter)
    {
        SItem &item = (*iter);
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(item.nItemID);
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(item.nItemID);
            if (nullptr == pEquipCfg)
            {
                continue;
            }
        }
        
        NFItem *pItemObj = MakeItemObj(item.nItemID);
        if (nullptr == pItemObj)
        {
            continue;
        }
        
        if (!pItemObj->Init(0, item.nItemID, itemCond, item.nNum, item.byBind))
        {
            FreeItemObj(pItemObj);
            continue;
        }
        vecItems.push_back(pItemObj);
    }
    
    return true;
}

bool NFItemMgr::CheckItem(const VEC_ITEM_PROTO_EX &vecProtoItems)
{
    for (auto iter = vecProtoItems.begin(); iter != vecProtoItems.end(); ++iter)
    {
        const proto_ff::ItemProtoInfo &proto = (*iter);
        if (!proto.has_item_id() || !proto.has_item_num() || (proto.item_num() < 0))
        {
            return false;
        }
        
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(proto.item_id());
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(proto.item_id());
            if (nullptr == pEquipCfg)
            {
                return false;
            }
            
            if (proto.item_num() != 1)//装备的数量必须为1
            {
                return false;
            }
        }
    }
    return true;
}

NFItem *NFItemMgr::MakeItemObj(uint64_t nItemId)
{
    NFItem *pItem = nullptr;
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(nItemId);
    if (pItemCfg)
    {
        //int32_t itemType = pItemCfg->itemType;
        pItem = new NFItem();
        if (nullptr == pItem)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[common] ItemMgr::MakeItemObj...nullptr == pItem nItemId:%lu", nItemId);
            return nullptr;
        }
        pItem->SetType(pItemCfg->m_itemType);
        return pItem;
    }
    
    auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(nItemId);
    if (pEquipCfg)
    {
        //神机装备处理
        if (pEquipCfg->m_type == proto_ff::EPackageType_shenji_aq || pEquipCfg->m_type == proto_ff::EPackageType_shenji_lj)
        {
            pItem = new NFShengjiItem();
        }
        else if (pEquipCfg->m_type == proto_ff::EPackageType_Longhun)
        {
            pItem = new NFLongHunItem();
        }
        else if (pEquipCfg->m_type == proto_ff::EPackageType_BeastEquip)
        {
            pItem = new NFBeastItem();
        }
        else if (pEquipCfg->m_type == proto_ff::EPackageType_DeityEquip)
        {
            pItem = new NFDeityItem();
        }
        else if (pEquipCfg->m_type == proto_ff::EPackageType_MountKun)
        {
            pItem = new NFMountKunItem();
        }
        else if (pEquipCfg->m_type == proto_ff::EPackageType_star)
        {
            pItem = new NFStarItem();
        }
        //神魔装备
        else if (pEquipCfg->m_type == proto_ff::EPackageType_GodEvil)
        {
            pItem = new NFGodEvilItem();
        }
        else {
            pItem = new NFItem();
        }
        
        if (pItem)
        {
            pItem->SetType(proto_ff::EItemType_Equip);
        }
    }
    return pItem;
}

bool NFItemMgr::FreeItemObj(NFItem *pItemObj)
{
    NF_SAFE_DELETE(pItemObj);
    return true;
}

bool NFItemMgr::CreateItem(const LIST_ITEM &lstItem, VEC_ITEM_PROTO_EX &vecProtoEx, SItemCond &itemCond, bool bMerge)
{
    VEC_PACKAGE_ITEM vecItems;
    vecItems.clear();
    if (!CreateItem(lstItem, vecItems, itemCond, bMerge))
    {
        return false;
    }
    
    VEC_PACKAGE_ITEM::iterator iter = vecItems.begin();
    while (iter != vecItems.end())
    {
        NFItem *pItem = (*iter);
        proto_ff::ItemProtoInfo proto;
        if (SetItemProtoInfo(pItem, &proto))
        {
            vecProtoEx.push_back(proto);
        }
        iter = vecItems.erase(iter);
        FreeItemObj(pItem);
    }
    
    return true;
}

bool NFItemMgr::CreateItem(const VEC_ITEM_PROTO &vecProtoItems, VEC_PACKAGE_ITEM &vecItems)
{
    VEC_ITEM_PROTO_EX vecProtoItemEx;
    vecProtoItemEx.clear();
    for (auto iter = vecProtoItems.begin(); iter != vecProtoItems.end(); ++iter)
    {
        proto_ff::ItemProtoInfo *proto = (*iter);
        vecProtoItemEx.push_back(*proto);
    }
    return CreateItem(vecProtoItemEx, vecItems);
}

bool NFItemMgr::CreateItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_PACKAGE_ITEM &vecItems)
{
    if (!CheckItem(vecProtoItemsEx))
    {
        return false;
    }
    for (auto iter = vecProtoItemsEx.begin(); iter != vecProtoItemsEx.end(); ++iter)
    {
        const proto_ff::ItemProtoInfo &protoItem = (*iter);
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(protoItem.item_id());
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(protoItem.item_id());
            if (nullptr == pEquipCfg)
            {
                continue;
            }
        }
        
        NFItem *pItemObj = MakeItemObj(protoItem.item_id());
        if (nullptr == pItemObj)
        {
            continue;
        }
        
        if (!pItemObj->FromItemProto(protoItem))
        {
            FreeItemObj(pItemObj);
            continue;
        }
        vecItems.push_back(pItemObj);
    }
    return true;
}

void NFItemMgr::MergeItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem)
{
    for (auto iter = lstItem.begin(); iter != lstItem.end(); ++iter)
    {
        const SItem &item = (*iter);
        if (item.nItemID == 0)
        {
            continue;
        }
        int64_t stackLimit = 1;
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(item.nItemID);
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(item.nItemID);
            if (nullptr == pEquipCfg)
            {
                continue;
            }
            stackLimit = ItemMaxPile(pEquipCfg);
        }
        else
        {
            stackLimit = ItemMaxPile(pItemCfg);
        }
        
        int64_t nCount = item.nNum;
        for (auto iterout = lstOutItem.begin(); iterout != lstOutItem.end(); ++iterout)
        {
            SItem &itemout = (*iterout);
            if (itemout.nItemID == item.nItemID
                && itemout.byBind == item.byBind
                && itemout.nNum < stackLimit
                )
            {
                int64_t nCanAdd = stackLimit - itemout.nNum;
                if (nCount <= nCanAdd)
                {
                    itemout.nNum += nCount;
                    nCount = 0;
                }
                else
                {
                    itemout.nNum += nCanAdd;
                    nCount -= nCanAdd;
                }
            }
        }
        //
        if (nCount > 0)
        {
            int64_t nCnt = nCount / stackLimit;
            int64_t nExt = nCount % stackLimit;
            int64_t nMaxPile = stackLimit;
            for (int64_t i = 0; i < nCnt; ++i)
            {
                SItem newitem;
                newitem.nItemID = item.nItemID;
                newitem.nNum = nMaxPile;
                newitem.byBind = item.byBind;
                lstOutItem.push_back(newitem);
            }
            if (nExt > 0)
            {
                SItem newitem;
                newitem.nItemID = item.nItemID;
                newitem.nNum = nExt;
                newitem.byBind = item.byBind;
                lstOutItem.push_back(newitem);
            }
            nCount = 0;
        }
    }
}

uint32_t NFItemMgr::CalcGridNeed(const LIST_ITEM &lstItem, const VEC_ITEM_PROTO_EX &vecProtoEx, uint32_t &nNoPileNeed, uint32_t &nPileNeed)
{
    MAP_UINT64_INT64 mapbd;
    MAP_UINT64_INT64 mapunbd;
    MAP_UINT64_INT64 mapmaxpile;
    //
    for (auto &iter : lstItem)
    {
        int64_t maxPile = 0;
        uint8_t byBind = (uint8_t) EBindState::EBindState_no;
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(iter.nItemID);
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(iter.nItemID);
            if (nullptr == pEquipCfg)
            {
                continue;
            }
            byBind = BindStateByWay(pEquipCfg, iter.byBind);
            maxPile = ItemMaxPile(pEquipCfg);
        }
        else
        {
            byBind = BindStateByWay(pItemCfg, iter.byBind);
            maxPile = ItemMaxPile(pItemCfg);
        }
        //
        mapmaxpile[iter.nItemID] = maxPile;
        //
        if (maxPile <= 1)
        {
            nNoPileNeed += iter.nNum;
        }
        else
        {
            if ((uint8_t) EBindState::EBindState_bind == byBind)
            {
                mapbd[iter.nItemID] += iter.nNum;
            }
            else if ((uint8_t) EBindState::EBindState_no == byBind)
            {
                mapunbd[iter.nItemID] += iter.nNum;
            }
        }
    }
    //
    for (auto &iterproto : vecProtoEx)
    {
        int64_t maxPile = 0;
        uint8_t byBind = (uint8_t) EBindState::EBindState_no;
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(iterproto.item_id());
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(iterproto.item_id());
            if (nullptr == pEquipCfg)
            {
                continue;
            }
            byBind = BindStateByWay(pEquipCfg, iterproto.bind());
            maxPile = ItemMaxPile(pEquipCfg);
        }
        else
        {
            byBind = BindStateByWay(pItemCfg, iterproto.bind());
            maxPile = ItemMaxPile(pItemCfg);
        }
        //
        mapmaxpile[iterproto.item_id()] = maxPile;
        //
        if (maxPile <= 1)
        {
            nNoPileNeed += iterproto.item_num();
        }
        else
        {
            if ((uint8_t) EBindState::EBindState_bind == byBind)
            {
                mapbd[iterproto.item_id()] += iterproto.item_num();
            }
            else if ((uint8_t) EBindState::EBindState_no == byBind)
            {
                mapunbd[iterproto.item_id()] += iterproto.item_num();
            }
        }
    }
    //
    for (auto &iterbd : mapbd)
    {
        auto iterf = mapmaxpile.find(iterbd.first);
        if (iterf == mapmaxpile.end())
        {
            continue;
        }
        int64_t maxPile = iterf->second;
        maxPile = (maxPile < 1) ? 1 : maxPile;
        //
        nPileNeed += iterbd.second / maxPile;
    }
    //
    for (auto &iterunbd : mapunbd)
    {
        auto iterf = mapmaxpile.find(iterunbd.first);
        if (iterf == mapmaxpile.end())
        {
            continue;
        }
        int64_t maxPile = iterf->second;
        maxPile = (maxPile < 1) ? 1 : maxPile;
        //
        nPileNeed += iterunbd.second / maxPile;
    }
    
    return (nNoPileNeed + nPileNeed);
}

bool NFItemMgr::GetItemData(uint32_t itemId, uint8_t bindType, uint8_t &outItemType, uint8_t &outBindType, int64_t &maxPile)
{
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(itemId);
    if (nullptr == pItemCfg)
    {
        auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(itemId);
        if (nullptr == pEquipCfg)
        {
            return false;
        }
        
        outItemType = proto_ff::EItemType_Equip;
        outBindType = BindStateByWay(pEquipCfg, bindType);
        maxPile = ItemMaxPile(pEquipCfg);
    }
    else
    {
        outItemType = pItemCfg->m_itemType;
        outBindType = BindStateByWay(pItemCfg, bindType);
        maxPile = ItemMaxPile(pItemCfg);
    }
    return true;
}


