// -------------------------------------------------------------------------
//    @FileName         :    NFPackagePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackagePart
//
// -------------------------------------------------------------------------

#include "NFPackagePart.h"
#include "DescStore/ConstantConstantDesc.h"
#include "Player/NFMallPart.h"

NFPackagePart::NFPackagePart()
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

NFPackagePart::~NFPackagePart()
{
}

int NFPackagePart::CreateInit()
{
    return 0;
}

int NFPackagePart::ResumeInit()
{
    return 0;
}

int NFPackagePart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    m_commonBag.Init(this, pMaster);
    m_storeageBag.Init(this, pMaster);
    m_mountEggBag.Init(this, pMaster);
    m_petEggBag.Init(this, pMaster);
    m_deityBag.Init(this, pMaster);
    m_handBookBag.Init(this, pMaster);
    m_beastEquipBag.Init(this, pMaster);
    m_longHunEquipBag.Init(this, pMaster);
    m_findTreasureBag.Init(this, pMaster);
    m_bigDragonBag.Init(this, pMaster);
    m_shengjiAqBag.Init(this, pMaster);
    m_shengjiLjBag.Init(this, pMaster);
    m_godEvilBag.Init(this, pMaster);
    m_starBag.Init(this, pMaster);
    m_turnBag.Init(this, pMaster);
    m_mountKunBag.Init(this, pMaster);
    m_yaoKunBag.Init(this, pMaster);
    m_moFaBag.Init(this, pMaster);
    m_hunguBag.Init(this, pMaster);
    m_runeBag.Init(this, pMaster);
    return NFPart::Init(pMaster, partType, dbData);
}

int NFPackagePart::UnInit()
{
    return NFPart::UnInit();
}

int NFPackagePart::LoadFromDB(const proto_ff::RoleDBData &dbData)
{
    if (dbData.has_bag())
    {
        const proto_ff::RoleDBBagData &data = dbData.bag();
        for (int i = 0; i < data.bags_size(); i++)
        {
            const proto_ff::RoleDBUnitBagData &unitBag = data.bags(i);
            const proto_ff::BagDBSimpleData &unitBagSimple = unitBag.simple();
            NFPackageBag *pBag = GetPackageByType(unitBagSimple.package_type());
            if (pBag)
            {
                pBag->LoadFromDB(&unitBag);
            }
        }
    }
    return 0;
}

int NFPackagePart::InitConfig(const proto_ff::RoleDBData &data)
{
    return NFPart::InitConfig(data);
}

int NFPackagePart::SaveDB(proto_ff::RoleDBData &dbData)
{
    proto_ff::RoleDBBagData *pItemPackageData = dbData.mutable_bag();
    if (pItemPackageData == nullptr)
    {
        return false;
    }
    
    for (int nPackageType = proto_ff::EPackageType_Common; nPackageType < proto_ff::EPackageType_Limit; nPackageType++)
    {
        NFPackageBag *pBag = GetPackageByType(nPackageType);
        if (pBag)
        {
            proto_ff::RoleDBUnitBagData *pBagDB = pItemPackageData->add_bags();
            if (pBagDB)
            {
                pBag->Save(*pBagDB);
            }
        }
    }
    
    return true;
}

int NFPackagePart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFPackagePart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

int NFPackagePart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_PACKAGE_INFO_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_PACKAGE_USE);
    RegisterClientMessage(proto_ff::CLIENT_PACKAGE_SORT_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_PACKAGE_SELL);
    RegisterClientMessage(proto_ff::CLIENT_STORAGE_OPERATE_REQ);
    RegisterClientMessage(proto_ff::PACKAGE_EXPAND_REQ);
    return 0;
}

int NFPackagePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_PACKAGE_INFO_REQ:
        {
            PackageInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_PACKAGE_USE:
        {
            ItemUse(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_PACKAGE_SORT_REQ:
        {
            ItemSort(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_PACKAGE_SELL:
        {
            ItemSell(msgId, packet);
            break;
        }
        case proto_ff::PACKAGE_EXPAND_REQ:
        {
            ExpandReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFPackagePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

uint32_t NFPackagePart::GetLastErrorCode()
{
    return m_nLastErrorCode;
}

uint32_t NFPackagePart::GetPackageNotSpaceErrorCode(uint32_t nPackageType)
{
    uint32_t nRetCode = proto_ff::RET_SUCCESS;
    
    switch (nPackageType)
    {
        case proto_ff::EPackageType_Storage:
        {
            nRetCode = proto_ff::RET_PACKAGE_STORAGE_SPACE_NOT_ENOUGH;
            break;
        }
        default:
        {
            nRetCode = proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH;
            break;
        }
    }
    
    return nRetCode;
}

int64_t NFPackagePart::GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    NFPackageBag *pBag = GetItemPackageBag(nItemID);
    if (pBag)
    {
        return pBag->GetItemNum(nItemID, nUnBindNum, nBindNum);
    }
    return 0;
}

bool NFPackagePart::HasItem(LIST_ITEM &lstItem)
{
    map<uint32_t, LIST_ITEM> itemGroups;
    
    for (auto iter = lstItem.begin(); iter != lstItem.end(); iter++)
    {
        uint32_t nPackageType = GetItemPackageType(iter->nItemID);
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
        else
        {
            return false;
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->HasItem(it->second))
        {
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    NFPackageBag *pBag = GetItemPackageBag(nItemID);
    if (pBag)
    {
        return pBag->RemoveItem(nItemID, nNum, sourceParam, byBind);
    }
    return false;
}

bool NFPackagePart::RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    if (!HasItem(lstItem))
    {
        return false;
    }
    
    map<uint32_t, LIST_ITEM> itemGroups;
    
    for (auto iter = lstItem.begin(); iter != lstItem.end(); iter++)
    {
        uint32_t nPackageType = GetItemPackageType(iter->nItemID);
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->RemoveItem(it->second, sourceParam))
        {
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::RemoveItem(uint32_t nPackageType, LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveItem(lstItem, sourceParam);
    }
    return false;
}

bool NFPackagePart::RemoveItemByIndex(uint32_t nPackageType, uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveItemByIndex(nIndex, nNum, sourceParam);
    }
    return false;
}

bool NFPackagePart::RemoveItem(uint32_t nPackageType, MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveItem(mapIndexItem, sourceParam);
    }
    return false;
}

bool NFPackagePart::CanAddItem(LIST_ITEM &lstItem)
{
    uint32_t nPackageType = proto_ff::EPackageType_Common;
    std::unordered_map<uint32_t, LIST_ITEM> itemGroups;
    
    for (auto iter = lstItem.begin(); iter != lstItem.end(); iter++)
    {
        nPackageType = GetItemPackageType(iter->nItemID);
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->CanAddItem(it->second))
        {
            nPackageType = pBag->GetPackageType();
            m_nLastErrorCode = GetPackageNotSpaceErrorCode(nPackageType);
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx)
{
    uint32_t nPackageType = proto_ff::EPackageType_Common;
    map<uint32_t, VEC_ITEM_PROTO_EX> itemGroups;
    
    for (auto iter = vecProtoItemsEx.begin(); iter != vecProtoItemsEx.end(); iter++)
    {
        nPackageType = GetItemPackageType(iter->item_id());
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->CanAddItem(it->second))
        {
            nPackageType = pBag->GetPackageType();
            m_nLastErrorCode = GetPackageNotSpaceErrorCode(nPackageType);
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    NFPackageBag *pBag = GetItemPackageBag(nItemID);
    if (pBag)
    {
        bool bRet = pBag->AddItem(nItemID, nNum, sourceParam, byBind);
        if (!bRet)
        {
            m_nLastErrorCode = GetPackageNotSpaceErrorCode(pBag->GetPackageType());
        }
        return bRet;
    }
    return false;
}

bool NFPackagePart::AddItem(LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update, bool tip)
{
    if (!CanAddItem(lstItem))
    {
        return false;
    }
    
    map<uint32_t, LIST_ITEM> itemGroups;
    
    for (auto iter = lstItem.begin(); iter != lstItem.end(); iter++)
    {
        uint32_t nPackageType = GetItemPackageType(iter->nItemID);
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->AddItem(it->second, sourceParam, update, tip))
        {
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::AddItem(VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update, bool tip)
{
    VEC_ITEM_PROTO_EX vecProtoEx;
    vecProtoEx.clear();
    VEC_ITEM_PROTO::iterator iter = vecProtoItems.begin();
    for (; iter != vecProtoItems.end(); ++iter)
    {
        proto_ff::ItemProtoInfo *proto = (*iter);
        if (nullptr != proto)
        {
            proto_ff::ItemProtoInfo protoEx(*proto);
            vecProtoEx.push_back(protoEx);
        }
    }
    
    if (!CanAddItem(vecProtoEx))
    {
        return false;
    }
    
    return AddItem(vecProtoEx, sourceParam, update);
}

bool NFPackagePart::AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update, bool tip)
{
    if (!CanAddItem(vecProtoItemsEx))
    {
        return false;
    }
    
    map<uint32_t, VEC_ITEM_PROTO_EX> itemGroups;
    
    for (auto iter = vecProtoItemsEx.begin(); iter != vecProtoItemsEx.end(); iter++)
    {
        uint32_t nPackageType = GetItemPackageType(iter->item_id());
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->AddItem(it->second, sourceParam, update, tip))
        {
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::AddItemEx(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam)
{
    if (!CanAddItem(vecProtoItemsEx))
    {
        return false;
    }
    
    map<uint32_t, VEC_ITEM_PROTO_EX> itemGroups;
    
    for (auto iter = vecProtoItemsEx.begin(); iter != vecProtoItemsEx.end(); iter++)
    {
        uint32_t nPackageType = GetItemPackageType(iter->item_id());
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->AddItemEx(it->second, sourceParam))
        {
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update, bool tip)
{
    if (!CanAddItem(vecProtoItemsEx))
    {
        return false;
    }
    
    map<uint32_t, VEC_ITEM_PROTO_EX> itemGroups;
    
    for (auto iter = vecProtoItemsEx.begin(); iter != vecProtoItemsEx.end(); iter++)
    {
        uint32_t nPackageType = GetItemPackageType(iter->item_id());
        if (IsValidPackage(nPackageType))
        {
            itemGroups[nPackageType].push_back(*iter);
        }
    }
    
    for (auto it = itemGroups.begin(); it != itemGroups.end(); it++)
    {
        NFPackageBag *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
        {
            return false;
        }
        if (!pBag->AddItem(it->second, vecProtoItemsOut, sourceParam, update, tip))
        {
            return false;
        }
    }
    
    return true;
}

bool NFPackagePart::ClearPackage()
{
    for (int i = proto_ff::EPackageType_Common; i < proto_ff::EPackageType_Limit; i++)
    {
        NFPackageBag *pBag = GetPackageByType(i);
        if (pBag)
        {
            pBag->ClearPackage();
        }
    }
    
    return true;
}

int32_t NFPackagePart::Expand(int32_t &nNum)
{
    NFPackageBag *pBag = GetPackageByType(proto_ff::EPackageType_Common);
    if (pBag)
    {
        pBag->Expand(nNum);
    }
    return proto_ff::RET_FAIL;
}

int32_t NFPackagePart::ExpandStorage(int32_t &nNum)
{
    NFPackageBag *pBag = GetPackageByType(proto_ff::EPackageType_Storage);
    if (pBag)
    {
        pBag->Expand(nNum);
    }
    return proto_ff::RET_FAIL;
}

NFItem *NFPackagePart::GetItem(uint16_t nIndex)
{
    return GetPackageItemByIndex(proto_ff::EPackageType_Common, nIndex);
}

NFItem *NFPackagePart::GetItem(uint32_t packageType, uint16_t nIndex)
{
    return GetPackageItemByIndex(packageType, nIndex);
}

NFItem *NFPackagePart::GetPackageItemByIndex(uint32_t nPackageType, uint32_t nIndex)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->GetItemByIndex(nIndex);
    }
    return nullptr;
}

NFItem *NFPackagePart::GetFirstItemById(uint32_t nPackageType, uint64_t item_id)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->GetFirstItemById(item_id);
    }
    return nullptr;
}

bool NFPackagePart::RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam)
{
    NFPackageBag *pBag = GetPackageByType(proto_ff::EPackageType_Common);
    if (pBag)
    {
        return pBag->RemoveAllByType(itemSubType, sourceParam);
    }
    return false;
}

bool NFPackagePart::RemoveAllByType(uint32_t nPackageType, int32_t itemSubType, SCommonSource &sourceParam)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveAllByType(itemSubType, sourceParam);
    }
    return false;
}

int32_t NFPackagePart::UseItem(NFItem *pItem, int64_t &nNum, proto_ff::UseItemArgProto &protoArg)
{
    int32_t nRetCode = proto_ff::RET_FAIL;
    if (nullptr == pItem)
    {
        return proto_ff::RET_FAIL;
    }
    else if ((int64_t) pItem->GetNum() < nNum)
    {
        //数量不够 RET_PACKAGE_ITEM_NUM_LACK
        return proto_ff::RET_PACKAGE_ITEM_NUM_LACK;
    }
    else
    {
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(pItem->GetItemID());
        if (nullptr == pItemCfg)
        {
            //物品不存在
            return proto_ff::RET_PACKAGE_ITEM_NOT_EXITS;
        }
        else
        {
            //具体物品的使用逻辑，后面添加
/*            nRetCode = g_GetItemUseMgr()->UseItem(pItem, nNum, m_pMaster, protoArg);
            if (proto_ff::RET_SUCCESS == nRetCode || proto_ff::RET_PACKAGE_USE_ITEM_NOT_REMOVE == nRetCode)
            {
                //使用物品事件
                ItemUseEvent useEvent;
                useEvent.itemId = pItemCfg->id;
                useEvent.num = nNum;
                g_GetEvent()->FireExecute(EVENT_ITEM_USE, m_pMaster->Cid(), CREATURE_PLAYER, &useEvent, sizeof(ItemUseEvent));
            }*/
        }
    }
    
    return nRetCode;
}

int32_t NFPackagePart::UseItem(uint16_t nIndex, int64_t &nNum, proto_ff::UseItemArgProto &protoArg)
{
    NFItem *pItem = GetItemByPackageType(proto_ff::EPackageType_Common, nIndex);
    if (nullptr == pItem)
    {
        return proto_ff::RET_PACKAGE_ITEM_NOT_EXITS;
    }
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(pItem->GetItemID());
    if (nullptr == pItemCfg)
    {
        //物品不存在
        return proto_ff::RET_PACKAGE_ITEM_NOT_EXITS;
    }
    
    int32_t ret = UseItem(pItem, nNum, protoArg);
    if (proto_ff::RET_SUCCESS != ret && proto_ff::RET_PACKAGE_USE_ITEM_NOT_REMOVE != ret)
    {
        return ret;
    }
    //减物品
    if (ret != proto_ff::RET_PACKAGE_USE_ITEM_NOT_REMOVE)
    {
        SCommonSource sourceParam;
        sourceParam.src = S_USE_ITEM;
        sourceParam.param1 = pItemCfg->m_id;
        RemoveItemByIndex(proto_ff::EPackageType_Common, nIndex, nNum, sourceParam);
    }
    
    return proto_ff::RET_SUCCESS;
}

void NFPackagePart::AllOpenGrid(uint32_t nPackageType)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->AllOpenGrid();
    }
}

bool NFPackagePart::GetEmptyGrid(uint32_t nPackageType, VEC_UINT16 &vecGrid)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->GetEmptyGrid(vecGrid) > 0;
    }
    return false;
}

int32_t NFPackagePart::GetEmptyGrid(uint32_t nPackageType)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->GetEmptyGrid();
    }
    return 0;
}

uint16_t NFPackagePart::SetItemByIndex(uint32_t nPackageType, uint16_t nIndex, const NFItem &item)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->SetItemByIndex(nIndex, item);
    }
    return 0;
}

uint16_t NFPackagePart::SetItemByIndex(uint32_t nPackageType, uint16_t nIndex, const NFItem *pItem)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->SetItemByIndex(nIndex, pItem);
    }
    return 0;
}

void NFPackagePart::ItemSortByPackageType(uint32_t nPackageType)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->SortItem();
    }
}

void NFPackagePart::SendUpdatePackageByIndex(uint32_t nPackageType, NFItem *pItem, bool bDel)
{
    proto_ff::NotifyPackageUpdate update_ret;
    AddPackageUpdateInfo(pItem, update_ret, bDel);
    //更新背包
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->UpdatePackageInfo(update_ret);
    }
}

bool NFPackagePart::AddPackageUpdateInfo(NFItem *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel)
{
    if (nullptr == pItem)
    {
        return false;
    }
    proto_ff::ItemProtoInfo *protoItemInfo = ret.add_item_list();
    if (nullptr != protoItemInfo)
    {
        SetUpdateItemInfo(pItem, protoItemInfo, bDel);
    }
    return true;
}

void NFPackagePart::UpdatePackage(uint32_t nPackageType, proto_ff::NotifyPackageUpdate &ret)
{
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->UpdatePackageInfo(ret);
    }
}

NFItem *NFPackagePart::GetItemByPackageType(int8_t byPackageType, uint16_t nIndex)
{
    NFPackageBag *pBag = GetPackageByType(byPackageType);
    if (pBag)
    {
        return pBag->GetItemByIndex(nIndex);
    }
    
    return nullptr;
}

uint16_t NFPackagePart::SetItemByPackageType(int8_t byPackageType, uint16_t nIndex, const NFItem &item)
{
    NFPackageBag *pBag = GetPackageByType(byPackageType);
    if (pBag)
    {
        return pBag->SetItemByIndex(nIndex, item);
    }
    return 0;
}

bool NFPackagePart::ValidIndexByPackageType(uint16_t nIndex, int8_t byPackageType)
{
    NFPackageBag *pBag = GetPackageByType(byPackageType);
    if (pBag)
    {
        return pBag->ValidIndex(nIndex);
    }
    
    return false;
}

bool NFPackagePart::ValidPackageType(int8_t byPackageType)
{
    if (byPackageType > proto_ff::EPackageType_None && byPackageType < proto_ff::EPackageType_Limit)
    {
        return true;
    }
    return false;
}

void NFPackagePart::FirstLogin()
{

}

void NFPackagePart::StorageOperate(const char *data, uint32_t len)
{

}

bool NFPackagePart::SetUpdateItemInfo(NFItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel)
{
    if (bDel)
    {
        return NFItemMgr::SetItemProtoInfo(pItem, protoItemInfo, 0);
    }
    return NFItemMgr::SetItemProtoInfo(pItem, protoItemInfo);
}

void NFPackagePart::ClearIdxRecord()
{
    m_setIdxRecord.clear();
}

SET_UINT16 &NFPackagePart::GetIdxRecord()
{
    return m_setIdxRecord;
}

void NFPackagePart::OnUseItem(uint64_t nItemId, uint32_t num)
{

}

bool NFPackagePart::AddItemAttr(uint64_t nItemId, uint32_t nTimes)
{
    return false;
}

void NFPackagePart::SetPackageSaveFlag(bool saveFlag)
{
    MarkDirty();
}

bool NFPackagePart::IsValidPackage(uint32_t nPackageType)
{
    return nPackageType > proto_ff::EPackageType_None && nPackageType < proto_ff::EPackageType_Limit;
}

NFPackageBag *NFPackagePart::GetPackageByItemID(uint64_t nItemID)
{
    uint32_t nPackageType = GetItemPackageType(nItemID);
    return GetPackageByType(nPackageType);
}

NFPackageBag *NFPackagePart::GetItemPackageBag(uint64_t nItemID)
{
    uint32_t nPackageType = GetItemPackageType(nItemID);
    return GetPackageByType(nPackageType);
}

uint32_t NFPackagePart::GetItemPackageType(uint64_t nItemID)
{
    uint32_t nPackageType = proto_ff::EPackageType_None;
    auto *pItemCfg = ItemItemDesc::Instance()->GetDesc(nItemID);
    if (nullptr == pItemCfg)
    {
        auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(nItemID);
        if (nullptr == pEquipCfg)
        {
            return proto_ff::EPackageType_None;
        }
        return pEquipCfg->m_type;
    }
    
    switch (pItemCfg->m_itemType)
    {
        case proto_ff::EItemType_Material:
            nPackageType = proto_ff::EPackageType_Common;
            break;
        case proto_ff::EItemType_Other:
            nPackageType = proto_ff::EPackageType_Common;
            break;
        case proto_ff::EItemType_Task:
            nPackageType = proto_ff::EPackageType_Common;
            break;
        case proto_ff::EItemType_MountEgg:
            nPackageType = proto_ff::EPackageType_MountEgg;
            break;
        case proto_ff::EItemType_PetEgg:
            nPackageType = proto_ff::EPackageType_PetEgg;
            break;
        case proto_ff::EItemType_HandBook:
            nPackageType = proto_ff::EPackageType_HandBook;
            break;
        default:
            nPackageType = proto_ff::EPackageType_Common;
            break;
    }
    
    return nPackageType;
}

NFPackageBag *NFPackagePart::GetPackageByType(uint32_t nPackageType)
{
    if (!IsValidPackage(nPackageType)) { return nullptr; }
    switch (nPackageType)
    {
        case proto_ff::EPackageType_Common:
            return &m_commonBag;
        case proto_ff::EPackageType_Storage:
            return &m_storeageBag;
        case proto_ff::EPackageType_DeityEquip:
            return &m_deityBag;
        case proto_ff::EPackageType_MountEgg:
            return &m_mountEggBag;
        case proto_ff::EPackageType_PetEgg:
            return &m_petEggBag;
        case proto_ff::EPackageType_HandBook:
            return &m_handBookBag;
        case proto_ff::EPackageType_BeastEquip:
            return &m_beastEquipBag;
        case proto_ff::EPackageType_Longhun:
            return &m_longHunEquipBag;
        case proto_ff::EPackageType_FindTreasure:
            return &m_findTreasureBag;
        case proto_ff::EPackageType_BigDragon:
            return &m_bigDragonBag;
        case proto_ff::EPackageType_shenji_aq:
            return &m_shengjiAqBag;
        case proto_ff::EPackageType_shenji_lj:
            return &m_shengjiLjBag;
        case proto_ff::EPackageType_GodEvil:
            return &m_godEvilBag;
        case proto_ff::EPackageType_star:
            return &m_starBag;
        case proto_ff::EPackageType_turn:
            return &m_turnBag;
        case proto_ff::EPackageType_MountKun:
            return &m_mountKunBag;
        case proto_ff::EPackageType_YaoHun:
            return &m_yaoKunBag;
        case proto_ff::EPackageType_MoFa:
            return &m_moFaBag;
        case proto_ff::EPackageType_hungu:
            return &m_hunguBag;
        case proto_ff::EPackageType_rune:
            return &m_runeBag;
        default:
            break;
    }
    return nullptr;
}

int NFPackagePart::PackageInfo(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::PackageInfoReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    int32_t nPackageType = req.package_type();
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->SendPackageInfoToClient();
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "nPackageType:{} not exist", nPackageType);
    }
    return 0;
}

int NFPackagePart::ItemSort(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::PackageSortReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    uint32_t nPackageType = req.package_type();
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->SortItem();
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "nPackageType:{} not exist", nPackageType);
    }
    
    return 0;
}

int NFPackagePart::ItemSell(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::PackageSellReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    uint32_t nPackageType = req.package_type();
    NFPackageBag *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        if (nPackageType == proto_ff::EPackageType_turn)
        {
            //pBag->ShentiEquipSell(req);
        }
        else
        {
            pBag->ItemSell(req);
        }
    }
    
    return 0;
}

int NFPackagePart::ItemUse(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::PackageUseReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    uint16_t nIndex = (uint16_t) req.index();
    int64_t nNum = 1;
    if (req.has_num())
    {
        nNum = (int64_t) req.num();
    }
    
    proto_ff::UseItemArgProto protoArg;
    int32_t isize = (int32_t) req.item_lst_size();
    for (int32_t i = 0; i < isize; ++i)
    {
        protoArg.add_item_lst(req.item_lst(i));
    }
    
    const NFItem *pItem = GetPackageItemByIndex(proto_ff::EPackageType_Common, nIndex);
    CHECK_NULL(pItem);
    
    int32_t ret = UseItem(nIndex, nNum, protoArg);
    if (proto_ff::RET_PACKAGE_WAITING != ret)
    {
        proto_ff::PackageUseRet rsp;
        rsp.set_retcode(ret);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_PACKAGE_USE, rsp);
    }
    
    return 0;
}

int NFPackagePart::ExpandReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::PackageExpandReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    int32_t packageType = req.package_type();
    int32_t expand_grid = req.expand_grid();
    proto_ff::PackageExpandRsp rsp;
    
    int32_t ret = proto_ff::RET_SUCCESS;
    do
    {
        CHECK_BREAK_VALUE(expand_grid > 0, ret, proto_ff::RET_PARMAR_ERROR);
        auto pCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_ExpandItem);
        CHECK_BREAK_VALUE(pCfg, ret, proto_ff::RET_CONFIG_ERROR);
        auto pReplaceCfg = ConstantConstantDesc::Instance()->GetDesc(proto_ff::EConst_ExpandMallId);
        CHECK_BREAK_VALUE(pReplaceCfg, ret, proto_ff::RET_CONFIG_ERROR);
        uint32_t itemId = pCfg->m_constantdata;
        CHECK_BREAK_VALUE(packageType == proto_ff::EPackageType_Common || packageType == proto_ff::EPackageType_Storage, ret, proto_ff::RET_PARMAR_ERROR);
        NFPackageBag *pBag = GetPackageByType(packageType);
        CHECK_BREAK_VALUE(pBag, ret, proto_ff::RET_FAIL);
        uint16_t nLefNum = pBag->GetMaxGridNum() - pBag->GetOpenGrid();
        CHECK_BREAK_VALUE(nLefNum >= expand_grid, ret, proto_ff::RET_PARMAR_ERROR);
        NFMallPart *pMallPart = dynamic_cast<NFMallPart *>(m_pMaster->GetPart(PART_MALL));
        CHECK_BREAK_VALUE(pMallPart, ret, proto_ff::RET_FAIL);
        int64_t ubd = 0;
        int64_t bd = 0;
        int32_t hasNum = GetItemNum(itemId, ubd, bd);
        int32_t costMallNum = hasNum < expand_grid ? (expand_grid - hasNum) : 0;
        if (costMallNum > 0)
        {
            int64_t price = 0;
            ret = pMallPart->CostMallItem(pReplaceCfg->m_constantdata, costMallNum, price);
            CHECK_BREAK(ret == proto_ff::RET_SUCCESS);
        }
        int32_t cost_expand_grid = expand_grid - costMallNum;
        SCommonSource s;
        if (cost_expand_grid > 0) CHECK_BREAK_VALUE(RemoveItem(itemId, cost_expand_grid, s), ret, proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        pBag->Expand(expand_grid);
        pBag->SendPackageInfoToClient();
        
    }
    while (false);
    
    rsp.set_ret(ret);
    
    m_pMaster->SendMsgToClient(proto_ff::PACKAGE_EXPAND_RSP, rsp);
    
    return 0;
}
