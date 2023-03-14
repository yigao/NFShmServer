// -------------------------------------------------------------------------
//    @FileName         :    NFPackagePart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackagePart
//
// -------------------------------------------------------------------------

#include "NFPackagePart.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "ClientServerCmd.pb.h"
#include "Player/NFPlayer.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "ClientServer.pb.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "Event.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPackagePart, EOT_LOGIC_PACKAGE_PART_ID, NFPart)

NFPackagePart::NFPackagePart() : NFPart(), m_commonBag(m_pObjPluginManager), m_storageBag(m_pObjPluginManager)
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

int NFPackagePart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_PACKAGE_INFO_REQ, PART_PACKAGE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_PACKAGE_USE, PART_PACKAGE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_PACKAGE_SORT_REQ, PART_PACKAGE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_STORAGE_OPERATE_REQ, PART_PACKAGE);
    return 0;
}

int NFPackagePart::RegisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFPackagePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_PACKAGE_INFO_REQ:
        {
            OnHandlePackageInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_PACKAGE_USE:
        {
            OnHandlePackageUseItem(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_PACKAGE_SORT_REQ:
        {
            OnHandlePackageSortItem(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_STORAGE_OPERATE_REQ:
        {
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetRoleId(), "package:{} not handle", packet.ToString());
            break;
        }
    }
    return 0;
}

int NFPackagePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

NFBagPage *NFPackagePart::GetPackageByType(uint32_t nPackageType)
{
    if (nPackageType == proto_ff::EPackageType_Common)
    {
        return &m_commonBag;
    }
    else if (nPackageType == proto_ff::EPackageType_Storage)
    {
        return &m_storageBag;
    }
    return NULL;
}

NFBagPage *NFPackagePart::GetPackageByItemID(uint64_t nItemID)
{
    uint32_t packageType = GetItemPackageType(nItemID);
    return GetPackageByType(packageType);
}

NFBagPage *NFPackagePart::GetItemPackageBag(uint64_t nItemID)
{
    uint32_t packageType = GetItemPackageType(nItemID);
    return GetPackageByType(packageType);
}

uint32_t NFPackagePart::GetItemPackageType(uint64_t nItemID)
{
    uint32_t nPackageType = proto_ff::EPackageType_None;
    auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(nItemID);
    if (pItemCfg == NULL)
    {
        auto pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(nItemID);
        if (nullptr == pEquipCfg)
        {
            return proto_ff::EPackageType_None;
        }
        return proto_ff::EPackageType_Common;
    }

    switch (pItemCfg->m_itemtype)
    {
        case proto_ff::EItemType_Material:
            nPackageType = proto_ff::EPackageType_Common;
            break;
        case proto_ff::EItemType_Other:
            nPackageType = proto_ff::EPackageType_Common;
            break;
            /*case EItemType_Task:
                nPackageType = EPackageType_Task;
                break;
            case EItemType_Star:
                nPackageType = EPackageType_Star;
                break;
            case EItemType_Soul:
                nPackageType = EPackageType_Soul;
                break;
            case EItemType_FaiMateri:
                nPackageType = EPackageType_FaiMateri;
                break;
            case EItemType_FaiCrystal:
                nPackageType = EPackageType_FaiCrystal;
                break;
            case EItemType_Symbol:
                nPackageType = EPackageType_Symbol;
                break;
            case EItemType_BossIdentify:
                nPackageType = EPackageType_BossIdentify;
                break;
            case EItemType_FaiIdentify:
                nPackageType = EPackageType_FaiIdentify;
                break;*/
        default:
            break;
    }

    return nPackageType;
}

bool NFPackagePart::AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    auto pBag = GetItemPackageBag(nItemID);
    if (pBag)
    {
        bool bRet = pBag->AddItem(nItemID, nNum, sourceParam, byBind);
        return bRet;
    }
    return false;
}

int NFPackagePart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    m_commonBag.InitGrid(pMaster, proto_ff::EPackageType_Common, COMMON_PACKAGE_INIT_GRID_NUM, COMMON_PACKAGE_MAX_GRID_NUM);
    m_storageBag.InitGrid(pMaster, proto_ff::EPackageType_Storage, STORAGE_PACKAGE_INIT_GRID_NUM, STORAGE_PACKAGE_MAX_GRID_NUM);
    if (dbData.has_bag())
    {
        for (int i = 0; i < (int) dbData.bag().bags_size(); i++)
        {
            const ::proto_ff::RoleDBUnitBagData &bagData = dbData.bag().bags(i);
            const ::proto_ff::BagDBSimpleData &simple_data = bagData.simple();
            if (simple_data.package_type() == proto_ff::EPackageType_Common)
            {
                m_commonBag.Init(bagData);
            }
            else if (simple_data.package_type() == proto_ff::EPackageType_Storage)
            {
                m_storageBag.Init(bagData);
            }
        }
    }

    return 0;
}

int NFPackagePart::UnInit()
{
    return NFPart::UnInit();
}

bool NFPackagePart::IsValidPackage(uint32_t nPackageType)
{
    return nPackageType > proto_ff::EPackageType_None && nPackageType < proto_ff::EPackageType_Limit;
}

//是否能添加物品
bool NFPackagePart::CanAddItem(const LIST_ITEM &lstItem)
{
    uint32_t nPackageType = proto_ff::EPackageType_Common;
    map<uint32_t, LIST_ITEM> itemGroups;

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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->CanAddItem(it->second))
        {
            //nPackageType = pBag->GetPackageType();
            //m_nLastErrorCode = GetPackageNotSpaceErrorCode(nPackageType);
            return false;
        }
    }

    return true;
}
//能否添加物品
bool NFPackagePart::CanAddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx)
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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->CanAddItem(it->second))
        {
            //nPackageType = pBag->GetPackageType();
            //m_nLastErrorCode = GetPackageNotSpaceErrorCode(nPackageType);
            return false;
        }
    }

    return true;
}

//添加物品 nGetType : 物品来源（暂时没有）
bool NFPackagePart::AddItem(const LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update /*= true*/, bool tip /*= true*/)
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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->AddItem(it->second, sourceParam, update, tip))
            return false;
    }

    return true;
}

int NFPackagePart::SaveDB(proto_ff::RoleDBData &dbData)
{
    m_commonBag.SaveDB(*dbData.mutable_bag()->add_bags());
    m_storageBag.SaveDB(*dbData.mutable_bag()->add_bags());
    return 0;
}

int NFPackagePart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

uint32_t NFPackagePart::GetCurRoleDetailSeq() const
{
    uint32_t seq = GetCurSeq();
    seq += m_commonBag.GetCurSeq();
    seq += m_storageBag.GetCurSeq();
    return seq;
}

bool NFPackagePart::AddItem(const VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update, bool tip)
{
    VEC_ITEM_PROTO_EX vecProtoEx;
    vecProtoEx.clear();
    for (auto iter = vecProtoItems.begin(); iter != vecProtoItems.end(); ++iter)
    {
        proto_ff::ItemProtoInfo *proto = (*iter);
        if (nullptr != proto)
        {
            proto_ff::ItemProtoInfo protoEx(*proto);
            vecProtoEx.push_back(protoEx);
        }
    }

    if (!CanAddItem(vecProtoEx))
        return false;

    return AddItem(vecProtoEx, sourceParam, update);
}

bool NFPackagePart::AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update, bool tip)
{
    if (!CanAddItem(vecProtoItemsEx))
        return false;

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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->AddItem(it->second, sourceParam, update, tip))
            return false;
    }

    return true;
}

bool NFPackagePart::AddItemEx(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam)
{
    if (!CanAddItem(vecProtoItemsEx))
        return false;

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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->AddItemEx(it->second, sourceParam))
            return false;
    }

    return true;
}

bool
NFPackagePart::AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, const VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update,
                       bool tip)
{
    if (!CanAddItem(vecProtoItemsEx))
        return false;

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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->AddItem(it->second, vecProtoItemsOut, sourceParam, update, tip))
            return false;
    }

    return true;
}

int64_t NFPackagePart::GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    NFBagPage *pBag = GetItemPackageBag(nItemID);
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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->HasItem(it->second))
            return false;
    }

    return true;
}

bool NFPackagePart::RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    NFBagPage *pBag = GetItemPackageBag(nItemID);
    if (pBag)
    {
        return pBag->RemoveItem(nItemID, nNum, sourceParam, byBind);
    }
    return false;
}

bool NFPackagePart::RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    if (!HasItem(lstItem))
        return false;


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
        NFBagPage *pBag = GetPackageByType(it->first);
        if (pBag == nullptr)
            return false;
        if (!pBag->RemoveItem(it->second, sourceParam))
            return false;
    }

    return true;
}

bool NFPackagePart::RemoveItem(uint32_t nPackageType, LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    NFBagPage *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveItem(lstItem, sourceParam);
    }
    return false;
}

bool NFPackagePart::RemoveItemByIndex(uint32_t nPackageType, uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam)
{
    NFBagPage *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveItemByIndex(nIndex, nNum, sourceParam);
    }
    return false;
}

bool NFPackagePart::RemoveItem(uint32_t nPackageType, MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam)
{
    NFBagPage *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveItem(mapIndexItem, sourceParam);
    }
    return false;
}

int NFPackagePart::OnHandlePackageInfo(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::PackageInfoReq msgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, msgReq);
    int32_t nPackageType = msgReq.package_type();
    NFBagPage *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->SendPackageInfoToClient();
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFPackagePart::OnHandlePackageUseItem(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
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

    auto pItem = GetPackageItemByIndex(proto_ff::EPackageType_Common, nIndex);
    if (nullptr == pItem)
    {
        return -1;
    }

    auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(pItem->GetItemID());
    if (nullptr == pItemCfg)
    {
        //物品不存在
        return -1;
    }

    int32_t ret = UseItem(nIndex, nNum, protoArg);
    if (proto_ff::RET_PACKAGE_WAITING != ret)
    {
        proto_ff::PackageUseRet rsp;
        rsp.set_retcode(ret);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_PACKAGE_USE, rsp);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

const NFGridItem *NFPackagePart::GetPackageItemByIndex(uint32_t nPackageType, uint32_t nIndex)
{
    NFBagPage *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->GetItemByIndex(nIndex);
    }
    return nullptr;
}

const NFGridItem *NFPackagePart::GetItem(uint16_t nIndex)
{
    return GetPackageItemByIndex(proto_ff::EPackageType_Common, nIndex);
}

bool NFPackagePart::RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam)
{
    return m_commonBag.RemoveAllByType(itemSubType, sourceParam);
}

bool NFPackagePart::RemoveAllByType(uint32_t nPackageType, int32_t itemSubType, SCommonSource &sourceParam)
{
    NFBagPage *pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        return pBag->RemoveAllByType(itemSubType, sourceParam);
    }
    return false;
}

int32_t NFPackagePart::UseItem(NFGridItem *pItem, int64_t &nNum, proto_ff::UseItemArgProto &protoArg)
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
        auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(pItem->GetItemID());
        if (nullptr == pItemCfg)
        {
            //物品不存在
            return proto_ff::RET_PACKAGE_ITEM_NOT_EXITS;
        }
        else
        {
            //具体物品的使用逻辑，后面添加
            nRetCode = 0; //g_GetItemUseMgr()->UseItem(pItem/*->GetItemID()*/, nNum, m_pMaster, protoArg);
            if (proto_ff::RET_SUCCESS == nRetCode || proto_ff::RET_PACKAGE_USE_ITEM_NOT_REMOVE == nRetCode)
            {
                //使用物品事件
                proto_ff::ItemUseEvent useEvent;
                useEvent.set_itemid(pItemCfg->m_id);
                useEvent.set_num(nNum);
                FireExecute(NF_ST_LOGIC_SERVER, EVENT_ITEM_USE, m_pMaster->GetRoleId(), CREATURE_PLAYER, useEvent);
            }
        }
    }

    return nRetCode;
}

int32_t NFPackagePart::UseItem(uint16_t nIndex, int64_t &nNum, proto_ff::UseItemArgProto &protoArg)
{
    NFGridItem *pItem = GetItemByPackageType(proto_ff::EPackageType_Common, nIndex);
    if (nullptr == pItem)
    {
        return proto_ff::RET_PACKAGE_ITEM_NOT_EXITS;
    }

    auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(pItem->GetItemID());
    if (nullptr == pItemCfg)
    {
        //物品不存在
        return proto_ff::RET_PACKAGE_ITEM_NOT_EXITS;
    }
/*    if (pItemCfg->dayUse)
    {
        if (m_mapDayUseItemTimes[TimeUtility::GetLocalDay()][pItemCfg->id] >= (uint64_t)pItemCfg->dayUse)
        {
            return RET_PACKAGE_ITEM_USE_LIMIT;
        }
        int64_t nNumMax = pItemCfg->dayUse - m_mapDayUseItemTimes[TimeUtility::GetLocalDay()][pItemCfg->id];
        if (nNum > nNumMax)
        {
            nNum = nNumMax;
        }
    }*/

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
/*    if (pItemCfg->dayUse)
    {
        m_mapDayUseItemTimes[TimeUtility::GetLocalDay()][pItemCfg->id] += nNum;
        UpdateDayUseItemInfo();
    }*/

    return proto_ff::RET_SUCCESS;
}

NFGridItem *NFPackagePart::GetItemByPackageType(int8_t byPackageType, uint16_t nIndex)
{
    NFBagPage *pBag = GetPackageByType(byPackageType);
    if (pBag)
    {
        return pBag->GetItemByIndex(nIndex);
    }

    return nullptr;
}

uint16_t NFPackagePart::SetItemByPackageType(int8_t byPackageType, uint16_t nIndex, NFGridItem *pItem)
{
    NFBagPage *pBag = GetPackageByType(byPackageType);
    if (pBag)
    {
        return pBag->SetItemByIndex(nIndex, pItem);
    }
    return 0;
}

int NFPackagePart::OnHandlePackageSortItem(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::PackageSortReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    uint32_t nPackageType = req.package_type();
    NFBagPage* pBag = GetPackageByType(nPackageType);
    if (pBag)
    {
        pBag->SortItem();
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    return 0;
}
