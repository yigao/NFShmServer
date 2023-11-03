// -------------------------------------------------------------------------
//    @FileName         :    NFPackageBag.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageBag
//
// -------------------------------------------------------------------------

#include "NFPackageBag.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "Player/NFPlayer.h"
#include "DescStore/RoleExpDesc.h"

NFPackageBag::NFPackageBag()
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

NFPackageBag::~NFPackageBag()
{
}

int NFPackageBag::CreateInit()
{
    m_nLastSortTime = 0;                        //上次整理的时间
    m_nExpandNum = 0;                            //扩展格子数
    m_nOpenGrid = 0;                            //背包开启格子数
    m_nPackageType = 0;
    
    m_initGrid = 0;                                //初始化格子大小
    m_maxGrid = 0;                                //最大格子大小
    m_pMaster = NULL;
    return 0;
}

int NFPackageBag::ResumeInit()
{
    return 0;
}

uint64_t NFPackageBag::calcDynExp(int32_t type, int32_t num)
{
    uint64_t exp = 0;
    int32_t lv = m_pMaster->GetAttr(proto_ff::A_LEVEL);
    //int32_t lv =  type == 1? m_pMaster->GetAttr(proto_ff::A_LEVEL): g_GetGlobalMgr()->GetWorldLv(m_pMaster->GetZid());
    
    auto pCfg = RoleExpDesc::Instance()->GetDesc(lv);
    CHECK_EXPR(pCfg, 0, "");
    exp = pCfg->m_exp * num * 1.0 / 10000;
    
    return exp;
}

int NFPackageBag::Init(NFShmObj *pShmObj, NFPlayer *pMaster)
{
    InitShmObj(pShmObj);
    m_pMaster = pMaster;
    m_setIdxRecord.clear();
    return 0;
}

int64_t NFPackageBag::GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    uint32_t attrId = 0;
    if (NFItemMgr::IsVirItem(nItemID, attrId))
    {
        return m_pMaster->GetAttr(attrId);
    }
    
    return GetPackageItemNum(nItemID, nUnBindNum, nBindNum);
}

int64_t NFPackageBag::GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    ORDER_MAP_UINT16_INT64 mapUnbindGridHas;
    ORDER_MAP_UINT16_INT64 mapBindGridHas;
    return GetPackageItemNum(nItemID, nUnBindNum, nBindNum, mapUnbindGridHas, mapBindGridHas);
}

int64_t NFPackageBag::GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    for (uint16_t i = 0; i < m_nOpenGrid; ++i)
    {
        NFItem *pItem = GetItemByIndex(i);
        if (nullptr != pItem && nItemID == pItem->GetItemID())
        {
            int8_t byBind = pItem->GetBind();
            if ((uint8_t) EBindState::EBindState_no == byBind)
            {
                nUnBindNum += pItem->GetNum();
                mapUnbindGridHas[pItem->GetIndex()] = pItem->GetNum();
            }
            else if ((uint8_t) EBindState::EBindState_bind == byBind)
            {
                nBindNum += pItem->GetNum();
                mapBindGridHas[pItem->GetIndex()] = pItem->GetNum();
            }
        }
    }
    return (nUnBindNum + nBindNum);
}

const NFItem *NFPackageBag::GetItem(uint16_t nIndex)
{
    return GetItemByIndex(nIndex);
}

NFItem *NFPackageBag::GetFirstItemById(uint64_t item_id)
{
    for (int i = 0; i < m_nOpenGrid; i++)
    {
        NFItem *pItem = GetItemByIndex(i);
        if (pItem && pItem->GetItemID() == item_id)
            return pItem;
    }
    return nullptr;
}

const NFItem *NFPackageBag::GetItemByType(int32_t itemSubType)
{
    for (int i = 0; i < m_nOpenGrid; i++)
    {
        NFItem *pItem = GetItemByIndex(i);
        if (nullptr != pItem && pItem->GetItemID() > 0)
        {
            auto pItemCfg = ItemItemDesc::Instance()->GetDesc(pItem->GetItemID());
            if (nullptr != pItemCfg && itemSubType == pItemCfg->m_subType)
            {
                return pItem;
            }
        }
    }
    return nullptr;
}

bool NFPackageBag::HasItem(const LIST_ITEM &lstItem)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    ProcessItem(lstItem, lstOutItem, mapAttr);
    //
    if (!m_pMaster->EnoughVirAttr(mapAttr))
    {
        return false;
    }
    //
    ORDER_MAP_UINT16_INT64 mapGridReduceNum;
    if (!HasPackageItem(lstOutItem, mapGridReduceNum))
    {
        return false;
    }
    
    return true;
}

bool NFPackageBag::HasPackageItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return HasBagItem(lstItem, mapGridReduceNum);
}

bool NFPackageBag::HasPackageItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return HasBagItem(mapIdxNum, mapGridReduceNum);
}

bool NFPackageBag::HasBagItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    mapGridReduceNum.clear();
    
    MAP_UINT64_INT64 mapHasUnBind;        //非绑定物品
    MAP_UINT64_INT64 mapHasBind;        //绑定物品
    mapHasUnBind.clear();
    mapHasBind.clear();
    
    
    //记录物品对应的可堆叠格子当前有的绑定数量
    ORDER_MAP_UINT64_ORDER_MAP_UINT16_INT64 mapItemBindGridHas;
    mapItemBindGridHas.clear();
    //记录物品对应的可堆叠格子当前有的非绑定数量
    ORDER_MAP_UINT64_ORDER_MAP_UINT16_INT64 mapItemUnbindGridHas;
    mapItemUnbindGridHas.clear();
    
    LIST_ITEM::const_iterator iter = lstItem.begin();
    for (; iter != lstItem.end(); ++iter)
    {
        const SItem &item = (*iter);
        if (item.nNum <= 0)
        {
            continue;
        }
        
        MAP_UINT64_INT64::iterator iterUnbind = mapHasUnBind.find(item.nItemID);
        if (iterUnbind == mapHasUnBind.end())
        {
            int64_t nUnBindNum = 0;
            int64_t nBindNum = 0;
            ORDER_MAP_UINT16_INT64 mapUnbindHas;
            ORDER_MAP_UINT16_INT64 mapBindHas;
            mapUnbindHas.clear();
            mapBindHas.clear();
            GetPackageItemNum(item.nItemID, nUnBindNum, nBindNum, mapUnbindHas, mapBindHas);
            //
            mapHasUnBind[item.nItemID] = nUnBindNum;
            mapHasBind[item.nItemID] = nBindNum;
            mapItemBindGridHas[item.nItemID] = mapBindHas;
            mapItemUnbindGridHas[item.nItemID] = mapUnbindHas;
        }
        
        if ((int8_t) EBindState::EBindState_no == item.byBind)
        {
            if (mapHasUnBind[item.nItemID] < item.nNum)
            {
                //数量不够
                return false;
            }
            //总数量和非绑定数量变化
            mapHasUnBind[item.nItemID] -= item.nNum;
            //
            int64_t reduceNum = item.nNum;
            ORDER_MAP_UINT16_INT64 &mapUnbindHas = mapItemUnbindGridHas[item.nItemID];
            ORDER_MAP_UINT16_INT64::iterator iterHas = mapUnbindHas.begin();
            for (; iterHas != mapUnbindHas.end(); ++iterHas)
            {
                uint16_t idx = iterHas->first;
                int64_t canReduceNum = iterHas->second;
                if (canReduceNum <= 0)
                {
                    continue;
                }
                int64_t idxReduce = 0;
                if (canReduceNum >= reduceNum)
                {
                    iterHas->second -= reduceNum;
                    idxReduce = reduceNum;
                    reduceNum = 0;
                }
                else
                {
                    reduceNum -= canReduceNum;
                    idxReduce = canReduceNum;
                    iterHas->second -= canReduceNum;
                }
                
                if (idxReduce > 0)
                {
                    ORDER_MAP_UINT16_INT64::iterator iterReduce = mapGridReduceNum.find(idx);
                    if (iterReduce != mapGridReduceNum.end())
                    {
                        iterReduce->second += idxReduce;
                    }
                    else
                    {
                        mapGridReduceNum[idx] = idxReduce;
                    }
                }
                
                if (reduceNum <= 0)
                {
                    break;
                }
            }
        }
        else if ((int8_t) EBindState::EBindState_bind == item.byBind)
        {
            if (mapHasBind[item.nItemID] < item.nNum)
            {
                //数量不够
                return false;
            }
            //总数量和绑定数量变化
            mapHasBind[item.nItemID] -= item.nNum;
            
            int64_t reduceNum = item.nNum;
            ORDER_MAP_UINT16_INT64 &mapBindHas = mapItemBindGridHas[item.nItemID];
            ORDER_MAP_UINT16_INT64::iterator iterHas = mapBindHas.begin();
            for (; iterHas != mapBindHas.end(); ++iterHas)
            {
                uint16_t idx = iterHas->first;
                int64_t canReduceNum = iterHas->second;
                if (canReduceNum <= 0)
                {
                    continue;
                }
                int64_t idxReduce = 0;
                if (canReduceNum >= reduceNum)
                {
                    iterHas->second -= reduceNum;
                    idxReduce = reduceNum;
                    reduceNum = 0;
                }
                else
                {
                    reduceNum -= canReduceNum;
                    idxReduce = canReduceNum;
                    iterHas->second -= canReduceNum;
                }
                
                if (idxReduce > 0)
                {
                    ORDER_MAP_UINT16_INT64::iterator iterReduce = mapGridReduceNum.find(idx);
                    if (iterReduce != mapGridReduceNum.end())
                    {
                        iterReduce->second += idxReduce;
                    }
                    else
                    {
                        mapGridReduceNum[idx] = idxReduce;
                    }
                }
                
                if (reduceNum <= 0)
                {
                    break;
                }
            }
        }
        else
        {
            int64_t nTempNum = item.nNum;
            //先扣除绑定，后非绑定
            if (mapHasBind[item.nItemID] > 0)
            {
                int64_t reduceNum = 0;
                if (mapHasBind[item.nItemID] >= nTempNum)
                {
                    mapHasBind[item.nItemID] -= nTempNum;
                    reduceNum = nTempNum;
                    nTempNum = 0;
                }
                else
                {
                    nTempNum -= mapHasBind[item.nItemID];
                    reduceNum = mapHasBind[item.nItemID];
                    mapHasBind[item.nItemID] = 0;
                }
                
                if (reduceNum > 0)
                {
                    ORDER_MAP_UINT16_INT64 &mapBindHas = mapItemBindGridHas[item.nItemID];
                    ORDER_MAP_UINT16_INT64::iterator iterHas = mapBindHas.begin();
                    for (; iterHas != mapBindHas.end(); ++iterHas)
                    {
                        uint16_t idx = iterHas->first;
                        int64_t canReduceNum = iterHas->second;
                        if (canReduceNum <= 0)
                        {
                            continue;
                        }
                        int64_t idxReduce = 0;
                        if (canReduceNum >= reduceNum)
                        {
                            iterHas->second -= reduceNum;
                            idxReduce = reduceNum;
                            reduceNum = 0;
                        }
                        else
                        {
                            reduceNum -= canReduceNum;
                            idxReduce = canReduceNum;
                            iterHas->second -= canReduceNum;
                        }
                        
                        if (idxReduce > 0)
                        {
                            ORDER_MAP_UINT16_INT64::iterator iterReduce = mapGridReduceNum.find(idx);
                            if (iterReduce != mapGridReduceNum.end())
                            {
                                iterReduce->second += idxReduce;
                            }
                            else
                            {
                                mapGridReduceNum[idx] = idxReduce;
                            }
                        }
                        
                        if (reduceNum <= 0)
                        {
                            break;
                        }
                    }
                }
            }
            if (nTempNum > 0)
            {
                if (mapHasUnBind[item.nItemID] > 0)
                {
                    int64_t reduceNum = 0;
                    if (mapHasUnBind[item.nItemID] >= nTempNum)
                    {
                        mapHasUnBind[item.nItemID] -= nTempNum;
                        reduceNum = nTempNum;
                        nTempNum = 0;
                    }
                    else
                    {
                        nTempNum -= mapHasUnBind[item.nItemID];
                        reduceNum = mapHasUnBind[item.nItemID];
                        mapHasUnBind[item.nItemID] = 0;
                    }
                    
                    if (reduceNum > 0)
                    {
                        ORDER_MAP_UINT16_INT64 &mapUnbindHas = mapItemUnbindGridHas[item.nItemID];
                        ORDER_MAP_UINT16_INT64::iterator iterHas = mapUnbindHas.begin();
                        for (; iterHas != mapUnbindHas.end(); ++iterHas)
                        {
                            uint16_t idx = iterHas->first;
                            int64_t canReduceNum = iterHas->second;
                            if (canReduceNum <= 0)
                            {
                                continue;
                            }
                            int64_t idxReduce = 0;
                            if (canReduceNum >= reduceNum)
                            {
                                iterHas->second -= reduceNum;
                                idxReduce = reduceNum;
                                reduceNum = 0;
                                
                            }
                            else
                            {
                                reduceNum -= canReduceNum;
                                idxReduce = canReduceNum;
                                iterHas->second -= canReduceNum;
                            }
                            
                            if (idxReduce > 0)
                            {
                                ORDER_MAP_UINT16_INT64::iterator iterReduce = mapGridReduceNum.find(idx);
                                if (iterReduce != mapGridReduceNum.end())
                                {
                                    iterReduce->second += idxReduce;
                                }
                                else
                                {
                                    mapGridReduceNum[idx] = idxReduce;
                                }
                            }
                            
                            if (reduceNum <= 0)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            if (nTempNum > 0)
            {
                //还有剩余的，//数量不够
                return false;
            }
        }
    }
    return true;
}

bool NFPackageBag::HasBagItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    mapGridReduceNum.clear();
    
    MAP_UINT16_INT64::const_iterator iter = mapIdxNum.begin();
    for (; iter != mapIdxNum.end(); ++iter)
    {
        uint16_t nIndex = iter->first;
        int64_t nNum = iter->second;
        if (nNum <= 0)
        {
            continue;
        }
        NFItem *pItem = GetItemByIndex(nIndex);
        if (nullptr == pItem || pItem->GetNum() < (uint64_t) nNum)
        {
            mapGridReduceNum.clear();
            return false;
        }
        mapGridReduceNum[nIndex] = nNum;
    }
    return true;
}

bool NFPackageBag::RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    LIST_ITEM lstItem;
    lstItem.clear();
    SItem item;
    item.nItemID = nItemID;
    item.nNum = nNum;
    item.byBind = byBind;
    lstItem.push_back(item);
    return RemoveItem(lstItem, sourceParam);
}

bool NFPackageBag::RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    ProcessItem(lstItem, lstOutItem, mapAttr);
    //
    if (!m_pMaster->EnoughVirAttr(mapAttr))
    {
        return false;
    }
    
    ORDER_MAP_UINT16_INT64 mapGridReduceNum;
    mapGridReduceNum.clear();
    if (!HasPackageItem(lstOutItem, mapGridReduceNum))
    {
        return false;
    }
    //因为上面判断过，这里直接扣除属性
    m_pMaster->AddVirAttr(mapAttr, true, &sourceParam, true);
    
    //因为上面判断过，所以这里直接移除物品
    MAP_UINT64_INT64 mapItemNum;
    mapItemNum.clear();
    RemovePackageItem(mapGridReduceNum, mapItemNum);
    //
    SetPackageSaveFlag(true);
    //
    OnRemoveItemEvent(mapItemNum, sourceParam);
    
    //物品流水日志
    ItemLog(mapItemNum, sourceParam);
    
    return true;
}

bool NFPackageBag::RemoveItemByIndex(uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam)
{
    MAP_UINT16_INT64 mapIndex;
    mapIndex.clear();
    mapIndex[nIndex] = nNum;
    return RemoveItem(mapIndex, sourceParam);
}

bool NFPackageBag::RemoveItem(MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam)
{
    ORDER_MAP_UINT16_INT64 mapIdxReduceNum;
    mapIdxReduceNum.clear();
    if (!HasPackageItem(mapIndexItem, mapIdxReduceNum))
    {
        return false;
    }
    MAP_UINT64_INT64 mapItemNum;
    mapItemNum.clear();
    RemovePackageItem(mapIdxReduceNum, mapItemNum);
    //
    SetPackageSaveFlag(true);
    //
    OnRemoveItemEvent(mapItemNum, sourceParam);
    
    //物品流水日志
    ItemLog(mapItemNum, sourceParam);
    return true;
}

bool NFPackageBag::RemovePackageItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum)
{
    return RemoveBagItem(mapGridReduceNum, mapItemNum);
}

bool NFPackageBag::RemoveBagItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum)
{
    proto_ff::NotifyPackageUpdate protoRet;
    ORDER_MAP_UINT16_INT64::iterator iterIdx = mapGridReduceNum.begin();
    for (; iterIdx != mapGridReduceNum.end(); ++iterIdx)
    {
        uint16_t idx = iterIdx->first;
        int64_t reduceNum = iterIdx->second;
        if (reduceNum <= 0)
        {
            continue;
        }
        
        NFItem *pItem = GetItemByIndex(idx);
        if (nullptr == pItem)
        {
            continue;
        }
        
        pItem->AddNum(-reduceNum);
        
        AddPackageUpdateInfo(pItem, protoRet);
        
        bool flag = true;
        uint64_t nItemId = pItem->GetItemID();
        if (0 == pItem->GetNum())
        {
            if (idx == SetItemByIndex(idx, NFItem()))
            {
            }
            else
            {
                flag = false;
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::RemoveBagItem....SetItemByPackageType failed...idx:%d, byPackageType:%d ", idx, m_nPackageType);
            }
        }
        if (flag)
        {
            mapItemNum[nItemId] += reduceNum;
        }
    }
    
    UpdatePackageInfo(protoRet);
    
    return true;
}

bool NFPackageBag::CanAddItem(LIST_ITEM &lstItem)
{
    LIST_ITEM lstOutItem;
    lstOutItem.clear();
    MAP_UINT32_INT64 mapAttr;
    ProcessItem(lstItem, lstOutItem, mapAttr, true);
    
    VEC_ITEM_PROTO_EX vecInProtoEx;
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItemEx;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapOutLabelVecPorotEx;
    MergePackageItemList(lstOutItem, vecInProtoEx, mapOutLabelItemEx, mapOutLabelVecPorotEx);
    
    MAP_UINT16_INT64 mapOutGridResultNum;
    MAP_INDEX_ITEM_PROTO_EX mapOutNewIdxItemProtoEx;
    return CanPackageAddItem(mapOutLabelItemEx, mapOutLabelVecPorotEx, mapOutGridResultNum, mapOutNewIdxItemProtoEx);
}

bool NFPackageBag::CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx)
{
    VEC_ITEM_PROTO_EX vecOutProtoEx;
    vecOutProtoEx.clear();
    MAP_UINT32_INT64 mapAttr;
    ProcessItem(vecProtoItemsEx, vecOutProtoEx, mapAttr, true);
    
    LIST_ITEM lstItem;
    lstItem.clear();
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItem;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapLabelVecProtoEx;
    MergePackageItemList(lstItem, vecOutProtoEx, mapOutLabelItem, mapLabelVecProtoEx);
    
    MAP_UINT16_INT64 mapGridAddNum;
    MAP_INDEX_ITEM_PROTO_EX mapIndexProtoEx;
    return CanPackageAddItem(mapOutLabelItem, mapLabelVecProtoEx, mapGridAddNum, mapIndexProtoEx);
}

bool NFPackageBag::CanPackageAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, NFPackageBag::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx)
{
    return CanBagAddItem(mapInLabelItem, mapInLabelVecItemProtoEx, mapOutGridAddNum, mapOutNewIdxItemProtoEx);
}

bool NFPackageBag::CanBagAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, NFPackageBag::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx)
{
    //每个标签页剩余格子数
    MAP_INT8_VEC_UINT16 mapLabelVecGrid;
    mapLabelVecGrid.clear();
    //out 参数先clear
    mapOutNewIdxItemProtoEx.clear();
    mapOutGridAddNum.clear();
    //统计每个标签页可堆叠物品的数量（绑定，非绑定，总数量）
    MAP_INT8_MAP_UINT64_INT64 mapLabelUnbindItem;
    MAP_INT8_MAP_UINT64_INT64 mapLabelBindItem;
    //可堆叠的物品，把可堆叠的格子放满之后，还需要新的格子
    MAP_INDEX_ITEM mapIndexItem;
    mapIndexItem.clear();
    
    
    //记录物品对应的可堆叠格子当前有的绑定数量
    ORDER_MAP_UINT64_ORDER_MAP_UINT16_INT64 mapItemBindGridHas;
    mapItemBindGridHas.clear();
    //记录物品对应的可堆叠格子当前有的非绑定数量
    ORDER_MAP_UINT64_ORDER_MAP_UINT16_INT64 mapItemUnbindGridHas;
    mapItemUnbindGridHas.clear();
    
    //标签页可堆叠物品处理
    MAP_LABEL_LIST_ITEM_EX::iterator iterLabel = mapInLabelItem.begin();
    for (; iterLabel != mapInLabelItem.end(); ++iterLabel)
    {
        int8_t byLabel = iterLabel->first;
        LIST_ITEM_EX &lstInItemEx = iterLabel->second;
        //label 物品数量（绑定）
        MAP_UINT64_INT64 *pLabelBindItem = nullptr;
        MAP_INT8_MAP_UINT64_INT64::iterator iterLabelB = mapLabelBindItem.find(byLabel);
        if (iterLabelB == mapLabelBindItem.end())
        {
            MAP_UINT64_INT64 mapBindItem;
            mapLabelBindItem[byLabel] = mapBindItem;
            pLabelBindItem = &mapLabelBindItem[byLabel];
        }
        else
        {
            pLabelBindItem = &iterLabelB->second;
        }
        //label 物品数量（非绑定）
        MAP_UINT64_INT64 *pLabelUnbindItem = nullptr;
        MAP_INT8_MAP_UINT64_INT64::iterator iterLabelC = mapLabelUnbindItem.find(byLabel);
        if (iterLabelC == mapLabelUnbindItem.end())
        {
            MAP_UINT64_INT64 mapUnbindItem;
            mapLabelUnbindItem[byLabel] = mapUnbindItem;
            pLabelUnbindItem = &mapLabelUnbindItem[byLabel];
        }
        else
        {
            pLabelUnbindItem = &iterLabelC->second;
        }
        //标签页剩余格子数
        VEC_UINT16 *pLabelNewGrid = nullptr;
        MAP_INT8_VEC_UINT16::iterator iterLabelGrid = mapLabelVecGrid.find(byLabel);
        if (iterLabelGrid == mapLabelVecGrid.end())
        {
            VEC_UINT16 vecNewGrid;
            vecNewGrid.clear();
            GetEmptyGrid(vecNewGrid);
            mapLabelVecGrid[byLabel] = vecNewGrid;
            pLabelNewGrid = &mapLabelVecGrid[byLabel];
        }
        else
        {
            pLabelNewGrid = &iterLabelGrid->second;
        }
        
        //
        MAP_UINT64_INT64 &mapUnBind = *pLabelUnbindItem;
        MAP_UINT64_INT64 &mapBind = *pLabelBindItem;
        VEC_UINT16 &vecEmptyGrid = *pLabelNewGrid;
        
        //统计每个标签页剩余可叠加的物品数量
        LIST_ITEM_EX::iterator iterInItem = lstInItemEx.begin();
        for (; iterInItem != lstInItemEx.end(); ++iterInItem)
        {
            SItemEx &item = (*iterInItem);
            MAP_UINT64_INT64::iterator iterBind = mapBind.find(item.nItemID);
            if (iterBind == mapBind.end())
            {
                int64_t unbindNum = 0;
                int64_t bindNum = 0;
                //VEC_PACKAGE_ITEM vecUnbindItem;
                //vecUnbindItem.clear();
                //VEC_PACKAGE_ITEM vecBindItem;
                //vecBindItem.clear();
                ORDER_MAP_UINT16_INT64 mapUnbindGridHas;
                mapUnbindGridHas.clear();
                ORDER_MAP_UINT16_INT64 mapBindGridHas;
                mapBindGridHas.clear();
                GetItemLeftPile(item.nItemID, unbindNum, bindNum, /*vecUnbindItem, vecBindItem,*/ mapUnbindGridHas, mapBindGridHas);
                //
                mapUnBind[item.nItemID] = unbindNum;
                mapBind[item.nItemID] = bindNum;
                mapItemBindGridHas[item.nItemID] = mapBindGridHas;
                mapItemUnbindGridHas[item.nItemID] = mapUnbindGridHas;
            }
            
            //增加的数量是否能放到 可堆叠的物品格子中
            int64_t nLeft = 0;
            int64_t addNum = 0;
            if ((int8_t) EBindState::EBindState_no == item.byBind)
            {
                if (mapUnBind[item.nItemID] >= item.nNum)
                {
                    mapUnBind[item.nItemID] -= item.nNum;
                    addNum = item.nNum;
                }
                else
                {
                    nLeft = item.nNum - mapUnBind[item.nItemID];
                    addNum = mapUnBind[item.nItemID];
                    mapUnBind[item.nItemID] = 0;
                }
                if (addNum > 0)
                {
                    ORDER_MAP_UINT16_INT64 &mapUnbindGridHas = mapItemUnbindGridHas[item.nItemID];
                    ORDER_MAP_UINT16_INT64::iterator iterHas = mapUnbindGridHas.begin();
                    for (; iterHas != mapUnbindGridHas.end(); ++iterHas)
                    {
                        uint16_t idx = iterHas->first;
                        int64_t has = iterHas->second;
                        int64_t canAddNum = item.stackNum - has;
                        if (canAddNum <= 0)
                        {
                            continue;
                        }
                        int64_t idxAdd = 0;
                        if (canAddNum >= addNum)
                        {
                            iterHas->second += addNum;
                            idxAdd = addNum;
                            addNum = 0;
                        }
                        else
                        {
                            addNum -= canAddNum;
                            idxAdd = canAddNum;
                            iterHas->second += canAddNum;
                        }
                        
                        if (idxAdd > 0)
                        {
                            MAP_UINT16_INT64::iterator iterAdd = mapOutGridAddNum.find(idx);
                            if (iterAdd != mapOutGridAddNum.end())
                            {
                                iterAdd->second += idxAdd;
                            }
                            else
                            {
                                mapOutGridAddNum[idx] = idxAdd;
                            }
                        }
                        
                        if (addNum <= 0)
                        {
                            break;
                        }
                    }
                    
                    if (addNum > 0)
                    {
                        //正常不会走到这里，做一次打印，便于以后定位
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::CanPackageAddItem..unbind....addNum > 0...addNum:%ld ", addNum);
                    }
                }
                
            }
            else if ((int8_t) EBindState::EBindState_bind == item.byBind)
            {
                if (mapBind[item.nItemID] >= item.nNum)
                {
                    mapBind[item.nItemID] -= item.nNum;
                    addNum = item.nNum;
                }
                else
                {
                    nLeft = item.nNum - mapBind[item.nItemID];
                    addNum = mapBind[item.nItemID];
                    mapBind[item.nItemID] = 0;
                }
                if (addNum > 0)
                {
                    ORDER_MAP_UINT16_INT64 &mapBindGridHas = mapItemBindGridHas[item.nItemID];
                    ORDER_MAP_UINT16_INT64::iterator iterHas = mapBindGridHas.begin();
                    for (; iterHas != mapBindGridHas.end(); ++iterHas)
                    {
                        uint16_t idx = iterHas->first;
                        int64_t has = iterHas->second;
                        int64_t canAddNum = item.stackNum - has;
                        if (canAddNum <= 0)
                        {
                            continue;
                        }
                        int64_t idxAdd = 0;
                        if (canAddNum >= addNum)
                        {
                            idxAdd = addNum;
                            iterHas->second += addNum;
                            addNum = 0;
                        }
                        else
                        {
                            addNum -= canAddNum;
                            idxAdd = canAddNum;
                            iterHas->second += canAddNum;
                        }
                        
                        if (idxAdd > 0)
                        {
                            MAP_UINT16_INT64::iterator iterAdd = mapOutGridAddNum.find(idx);
                            if (iterAdd != mapOutGridAddNum.end())
                            {
                                iterAdd->second += idxAdd;
                            }
                            else
                            {
                                mapOutGridAddNum[idx] = idxAdd;
                            }
                        }
                        
                        if (addNum <= 0)
                        {
                            break;
                        }
                    }
                    if (addNum > 0)
                    {
                        //正常不会走到这里，做一次打印，便于以后定位
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::CanPackageAddItem..bind....addNum > 0...addNum:%ld ", addNum);
                    }
                }
                
            }
            
            if (nLeft > 0) //可堆叠的格子放完之后剩下的数量
            {
                int64_t stackLimit = item.stackNum;
                MAP_INDEX_ITEM::iterator iterMap = mapIndexItem.begin();
                for (; iterMap != mapIndexItem.end(); ++iterMap)
                {
                    SItem &itemex = iterMap->second;
                    if (itemex.nItemID == item.nItemID && itemex.byBind == item.byBind && itemex.nNum < stackLimit)
                    {
                        if (itemex.nNum + nLeft <= stackLimit)
                        {
                            itemex.nNum += nLeft;
                            nLeft = 0;
                        }
                        else
                        {
                            int64_t nCnt = stackLimit - itemex.nNum;
                            nLeft -= nCnt;
                            itemex.nNum = stackLimit;
                        }
                    }
                    if (nLeft <= 0)
                    {
                        break;
                    }
                } // end of for (; iterMap != mapIndexItem.end(); ++iter)
                
                if (nLeft > 0) //需要额外分配格子
                {
                    int64_t nCount = 0;  //需要的格子数
                    int64_t nNumEx = 0;  //物品额外剩余数量
                    nCount = nLeft / stackLimit;
                    nNumEx = nLeft % stackLimit;
                    //实际需要格子数
                    int64_t nRealCount = nCount;
                    if (nNumEx > 0)
                    {
                        nRealCount += 1;
                    }
                    if ((int64_t) vecEmptyGrid.size() < nRealCount)
                    {
                        //格子不够
                        return false;
                    }
                    for (int64_t i = 0; i < nCount; ++i)
                    {
                        VEC_UINT16::iterator iterVec = vecEmptyGrid.begin();
                        uint16_t idx = (*iterVec);
                        SItem newitem;
                        newitem.nItemID = item.nItemID;
                        newitem.byBind = item.byBind;
                        newitem.nNum = stackLimit;
                        //
                        mapIndexItem[idx] = newitem;
                        vecEmptyGrid.erase(iterVec);
                    }
                    if (nNumEx > 0)
                    {
                        //只有可堆叠的才会走到这里
                        VEC_UINT16::iterator iterVec = vecEmptyGrid.begin();
                        uint16_t idx = (*iterVec);
                        SItem newitem;
                        newitem.nItemID = item.nItemID;
                        newitem.byBind = item.byBind;
                        newitem.nNum = nNumEx;
                        //
                        mapIndexItem[idx] = newitem;
                        vecEmptyGrid.erase(iterVec);
                    }
                } // end of if (nLeft > 0)
            } // if (nLeft > 0)
        } //end of for (; iterInItem != lstInItemEx.end(); ++iterInItem)
        
    } // end of for (; iterLabel != mapInLabelItem.end(); ++iterLabel)
    
    //标签页不可堆叠物品处理
    MAP_LABEL_VEC_ITEM_PROTO_EX::iterator iterNoPile = mapInLabelVecItemProtoEx.begin();
    for (; iterNoPile != mapInLabelVecItemProtoEx.end(); ++iterNoPile)
    {
        int8_t byLabel = iterNoPile->first;
        VEC_ITEM_PROTO_EX &vecNoPileProtoEx = iterNoPile->second;
        //标签页剩余格子数
        VEC_UINT16 *pLabelNewGrid = nullptr;
        MAP_INT8_VEC_UINT16::iterator iterLabelGrid = mapLabelVecGrid.find(byLabel);
        if (iterLabelGrid == mapLabelVecGrid.end())
        {
            VEC_UINT16 vecNewGrid;
            vecNewGrid.clear();
            GetEmptyGrid(vecNewGrid);
            mapLabelVecGrid[byLabel] = vecNewGrid;
            pLabelNewGrid = &mapLabelVecGrid[byLabel];
        }
        else
        {
            pLabelNewGrid = &iterLabelGrid->second;
        }
        
        
        //
        VEC_UINT16 &vecEmptyGrid = *pLabelNewGrid;
        if (vecEmptyGrid.size() < vecNoPileProtoEx.size())
        {
            return false; //格子不够
        }
        VEC_ITEM_PROTO_EX::iterator iterNewProto = vecNoPileProtoEx.begin();
        for (; iterNewProto != vecNoPileProtoEx.end(); ++iterNewProto)
        {
            proto_ff::ItemProtoInfo &proto = (*iterNewProto);
            VEC_UINT16::iterator iter = vecEmptyGrid.begin();
            uint16_t idx = (*iter);
            vecEmptyGrid.erase(iter);
            mapOutNewIdxItemProtoEx[idx] = proto;
            
        }
    }
    
    if (mapIndexItem.size() > 0)
    {
        VEC_UINT16 vecNewItemGrid;
        vecNewItemGrid.clear();
        LIST_ITEM lstNewItem;
        lstNewItem.clear();
        MAP_INDEX_ITEM::iterator iterNew = mapIndexItem.begin();
        for (; iterNew != mapIndexItem.end(); ++iterNew)
        {
            vecNewItemGrid.push_back(iterNew->first);
            lstNewItem.push_back(iterNew->second);
        }
        VEC_ITEM_PROTO_EX vecNewProtoEx;
        vecNewProtoEx.clear();
        SItemCond itemCond;
        //g_GetDropMgr()->GetItemCond(dynamic_cast<Player*>(m_pMaster), itemCond);
        if (!NFItemMgr::CreateItem(lstNewItem, vecNewProtoEx, itemCond, false))
        {
            return false;
        }
        if (vecNewProtoEx.size() > vecNewItemGrid.size())
        {
            return false;
        }
        //设置索引
        VEC_ITEM_PROTO_EX::iterator iterProto = vecNewProtoEx.begin();
        for (; iterProto != vecNewProtoEx.end(); ++iterProto)
        {
            proto_ff::ItemProtoInfo &proto = (*iterProto);
            VEC_UINT16::iterator iter = vecNewItemGrid.begin();
            uint16_t idx = (*iter);
            mapOutNewIdxItemProtoEx[idx] = proto;
            vecNewItemGrid.erase(iter);
        }
    }
    
    return true;
}

bool NFPackageBag::AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    LIST_ITEM lstItem;
    lstItem.clear();
    SItem item;
    item.nItemID = nItemID;
    item.nNum = nNum;
    item.byBind = byBind;
    lstItem.push_back(item);
    return AddItem(lstItem, sourceParam);
}

bool NFPackageBag::AddItem(LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update, bool tip)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    ProcessItem(lstItem, lstOutItem, mapAttr, true);
    //
    VEC_ITEM_PROTO_EX vecProtoTmpEx;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::CalcGridNeed(lstOutItem, vecProtoTmpEx, nopileNeed, pileNeed);
    VEC_UINT16 vecEmpty;
    GetEmptyGrid(vecEmpty);
    if (nopileNeed > (uint32_t) vecEmpty.size())
    {
        return false;
    }
    
    VEC_ITEM_PROTO_EX vecInProtoEx;
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItemEx;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapOutLabelVecPorotEx;
    MergePackageItemList(lstOutItem, vecInProtoEx, mapOutLabelItemEx, mapOutLabelVecPorotEx);
    
    MAP_UINT16_INT64 mapOutGridAddNum;
    MAP_INDEX_ITEM_PROTO_EX mapOutNewIdxItemProtoEx;
    if (!CanPackageAddItem(mapOutLabelItemEx, mapOutLabelVecPorotEx, mapOutGridAddNum, mapOutNewIdxItemProtoEx))
    {
        return false;
    }
    //先清空索引记录
    ClearIdxRecord();
    //已经判断过了，这里直接添加物品
    VEC_ITEM_PROTO_EX vecTipProtoEx;
    vecTipProtoEx.clear();
    if (tip)
    {
        for (auto iter = lstOutItem.begin(); iter != lstOutItem.end(); iter++)
        {
            proto_ff::ItemProtoInfo info;
            info.set_item_id(iter->nItemID);
            info.set_item_num(iter->nNum);
            vecTipProtoEx.push_back(info);
        }
    }
    AddPackageItem(mapOutGridAddNum, mapOutNewIdxItemProtoEx, vecTipProtoEx, update);
    //添加属性
    m_pMaster->AddVirAttr(mapAttr, false, &sourceParam, true);
    //
    SetPackageSaveFlag(true);
    //增加物品，触发事件
    OnAddItemEvent(mapOutGridAddNum, mapOutNewIdxItemProtoEx, sourceParam);
    //物品流水日志
    ItemLog(mapOutGridAddNum, mapOutNewIdxItemProtoEx, sourceParam);
    return true;
}

bool NFPackageBag::AddItem(VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update, bool tip)
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
    return AddItem(vecProtoEx, sourceParam, update);
}

bool NFPackageBag::AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update, bool tip)
{
    VEC_ITEM_PROTO_EX vecOutProtoItemEx;
    vecOutProtoItemEx.clear();
    MAP_UINT32_INT64 mapAttr;
    mapAttr.clear();
    //g_GetItemMgr()->FilterVirItem(vecProtoItemsEx, vecOutProtoItemEx, mapAttr);
    ProcessItem(vecProtoItemsEx, vecOutProtoItemEx, mapAttr, true);
    //
    LIST_ITEM lstTmpItem;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::CalcGridNeed(lstTmpItem, vecOutProtoItemEx, nopileNeed, pileNeed);
    VEC_UINT16 vecEmpty;
    GetEmptyGrid(vecEmpty);
    if (nopileNeed > (uint32_t) vecEmpty.size())
    {
        return false;
    }
    //
    LIST_ITEM lstItem;
    lstItem.clear();
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItem;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapLabelVecProtoEx;
    MergePackageItemList(lstItem, vecOutProtoItemEx, mapOutLabelItem, mapLabelVecProtoEx);
    
    MAP_UINT16_INT64 mapGridAddNum;
    MAP_INDEX_ITEM_PROTO_EX mapIndexProtoEx;
    if (!CanPackageAddItem(mapOutLabelItem, mapLabelVecProtoEx, mapGridAddNum, mapIndexProtoEx))
    {
        return false;
    }
    //清空
    ClearIdxRecord();
    //前面已经判断过，直接增加
    VEC_ITEM_PROTO_EX vecTipProtoEx;
    vecTipProtoEx.clear();
    if (tip)
    {
        vecTipProtoEx = vecOutProtoItemEx;
    }
    AddPackageItem(mapGridAddNum, mapIndexProtoEx, vecTipProtoEx, update);
    //添加属性
    m_pMaster->AddVirAttr(mapAttr, false, &sourceParam, true);
    //
    SetPackageSaveFlag(true);
    //增加物品，触发事件
    OnAddItemEvent(mapGridAddNum, mapIndexProtoEx, sourceParam);
    //物品流水日志
    ItemLog(mapGridAddNum, mapIndexProtoEx, sourceParam);
    return true;
}

bool NFPackageBag::AddItemEx(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam)
{
    VEC_ITEM_PROTO_EX vecOutProtoItemEx;
    vecOutProtoItemEx.clear();
    MAP_UINT32_INT64 mapAttr;
    mapAttr.clear();
    //g_GetItemMgr()->FilterVirItem(vecProtoItemsEx, vecOutProtoItemEx, mapAttr);
    ProcessItem(vecProtoItemsEx, vecOutProtoItemEx, mapAttr, true);
    //
    LIST_ITEM lstTmpItem;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::CalcGridNeed(lstTmpItem, vecOutProtoItemEx, nopileNeed, pileNeed);
    VEC_UINT16 vecEmpty;
    GetEmptyGrid(vecEmpty);
    if (nopileNeed > (uint32_t) vecEmpty.size())
    {
        return false;
    }
    //
    LIST_ITEM lstItem;
    lstItem.clear();
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItem;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapLabelVecProtoEx;
    MergePackageItemList(lstItem, vecOutProtoItemEx, mapOutLabelItem, mapLabelVecProtoEx);
    
    MAP_UINT16_INT64 mapGridAddNum;
    MAP_INDEX_ITEM_PROTO_EX mapIndexProtoEx;
    if (!CanPackageAddItem(mapOutLabelItem, mapLabelVecProtoEx, mapGridAddNum, mapIndexProtoEx))
    {
        return false;
    }
    //清空
    ClearIdxRecord();
    //前面已经判断过，直接增加
    AddPackageItem(mapGridAddNum, mapIndexProtoEx, vecOutProtoItemEx, true);
    //添加属性
    m_pMaster->AddVirAttr(mapAttr, false, &sourceParam, true);
    //
    SetPackageSaveFlag(true);
    //增加物品，触发事件
    OnAddItemEvent(mapGridAddNum, mapIndexProtoEx, sourceParam);
    //物品流水日志
    ItemLog(mapGridAddNum, mapIndexProtoEx, sourceParam);
    return true;
}

bool NFPackageBag::AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update, bool tip)
{
    VEC_ITEM_PROTO_EX vecOutProtoItemsEx;
    MAP_UINT32_INT64 mapAttr;
    //g_GetItemMgr()->FilterVirItem(vecProtoItemsEx, vecOutProtoItemsEx, mapAttr);
    ProcessItem(vecProtoItemsEx, vecOutProtoItemsEx, mapAttr, true);
    
    LIST_ITEM lstTmpItem;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::CalcGridNeed(lstTmpItem, vecOutProtoItemsEx, nopileNeed, pileNeed);
    VEC_UINT16 vecEmpty;
    GetEmptyGrid(vecEmpty);
    if (nopileNeed > (uint32_t) vecEmpty.size())
    {
        return false;
    }
    
    LIST_ITEM lstItem;
    lstItem.clear();
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItem;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapLabelVecProtoEx;
    MergePackageItemList(lstItem, vecOutProtoItemsEx, mapOutLabelItem, mapLabelVecProtoEx);
    
    MAP_UINT16_INT64 mapGridAddNum;
    MAP_INDEX_ITEM_PROTO_EX mapIndexProtoEx;
    if (!CanPackageAddItem(mapOutLabelItem, mapLabelVecProtoEx, mapGridAddNum, mapIndexProtoEx))
    {
        return false;
    }
    //清空
    ClearIdxRecord();
    //前面已经判断过，直接增加
    VEC_ITEM_PROTO_EX vecTipProtoEx;
    vecTipProtoEx.clear();
    if (tip)
    {
        vecTipProtoEx = vecOutProtoItemsEx;
    }
    AddPackageItem(mapGridAddNum, mapIndexProtoEx, vecOutProtoItemsEx, update);
    //添加属性
    m_pMaster->AddVirAttr(mapAttr, false, &sourceParam, true);
    //
    SetPackageSaveFlag(true);
    //增加物品，触发事件
    OnAddItemEvent(mapGridAddNum, mapIndexProtoEx, sourceParam);
    //填充传出参数
    OnAddItemParam(mapGridAddNum, mapIndexProtoEx, vecProtoItemsOut);
    //物品流水日志
    ItemLog(mapGridAddNum, mapIndexProtoEx, sourceParam);
    return true;
}

bool NFPackageBag::AddPackageItem(MAP_UINT16_INT64 &mapOutGridAddNum, NFPackageBag::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, const VEC_ITEM_PROTO_EX &vecProtoTipItemsEx, bool update)
{
    proto_ff::NotifyPackageUpdate protoUpdateRet;
    if (mapOutNewIdxItemProtoEx.size() > 0)
    {
        VEC_ITEM_PROTO_EX vecItemProEx;
        vecItemProEx.clear();
        MAP_INDEX_ITEM_PROTO_EX::iterator iterProto = mapOutNewIdxItemProtoEx.begin();
        for (; iterProto != mapOutNewIdxItemProtoEx.end(); ++iterProto)
        {
            uint16_t idx = iterProto->first;
            proto_ff::ItemProtoInfo &proto = iterProto->second;
            proto.set_index(idx);
            vecItemProEx.push_back(proto);
        }
        
        VEC_PACKAGE_ITEM vecItems;
        vecItems.clear();
        if (!NFItemMgr::CreateItem(vecItemProEx, vecItems))
        {
            return false;
        }
        VEC_PACKAGE_ITEM::iterator iterItem = vecItems.begin();
        while (iterItem != vecItems.end())
        {
            NFItem *pItem = (*iterItem);
            if (nullptr != pItem)
            {
                uint16_t idx = pItem->GetIndex();
                if (idx >= m_nOpenGrid)
                {
                    ++iterItem;
                    continue;
                }
                if (nullptr == GetItemByIndex(idx))
                {
                    if (idx == SetItemByIndex(idx, *pItem))
                    {
                        iterItem = vecItems.erase(iterItem);
                        
                        m_setIdxRecord.insert(idx);
                        AddPackageUpdateInfo(pItem, protoUpdateRet);
                        
                        continue;
                    }
                    else
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::AddPackageItem... SetItemByPackageType failed...idx:%d,itemid:%lu ", idx, pItem->GetItemID());
                    }
                }
            } // end of if (nullptr != pItem)
            
            ++iterItem;
        }
        
        //回收失败的物品
        VEC_PACKAGE_ITEM::iterator iterDel = vecItems.begin();
        for (; iterDel != vecItems.end(); ++iterDel)
        {
            NFItem *pDelItem = (*iterDel);
            NFItemMgr::FreeItemObj(pDelItem);
        }
    }
    
    MAP_UINT16_INT64::iterator iterGrid = mapOutGridAddNum.begin();
    for (; iterGrid != mapOutGridAddNum.end(); ++iterGrid)
    {
        uint16_t idx = iterGrid->first;
        int64_t addNum = iterGrid->second;
        NFItem *pItem = GetItemByIndex(idx);
        if (nullptr == pItem)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::AddPackageItem...GetItemByPackageType is nullptr ....idx:%d", idx);
            continue;
        }
        pItem->AddNum(addNum);
        
        m_setIdxRecord.insert(idx);
        AddPackageUpdateInfo(pItem, protoUpdateRet);
        
    }
    
    if (update)
    {
        if (vecProtoTipItemsEx.size() > 0 && (m_nPackageType != proto_ff::EPackageType_FindTreasure && m_nPackageType != proto_ff::EPackageType_BigDragon))
        {
            //使用另外的获得物品提示
            proto_ff::MutItemTipProto *protoMutTip = protoUpdateRet.mutable_item_tip();
            if (nullptr != protoMutTip)
            {
                VEC_ITEM_PROTO_EX::const_iterator iterTip = vecProtoTipItemsEx.begin();
                for (; iterTip != vecProtoTipItemsEx.end(); ++iterTip)
                {
                    const proto_ff::ItemProtoInfo &protoItem = (*iterTip);
                    proto_ff::ItemTipProto *protoTip = protoMutTip->add_mut_tip();
                    if (nullptr != protoTip)
                    {
                        protoTip->set_item_id(protoItem.item_id());
                        protoTip->set_item_num(protoItem.item_num());
                    }
                }
            }
        }
        
        //更新背包
        UpdatePackageInfo(protoUpdateRet);
        
    }
    
    return true;
}

void NFPackageBag::OnAddItemEvent(MAP_UINT16_INT64 &mapOutGridAddNum, NFPackageBag::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &sourceParam)
{
    //增加物品，触发事件
    VEC_ITEM_PROTO_EX vCollectItems;
    
    MAP_UINT16_INT64::iterator iterAdd = mapOutGridAddNum.begin();
    for (; iterAdd != mapOutGridAddNum.end(); ++iterAdd)
    {
        NFItem *pItem = GetItemByIndex(iterAdd->first);
        if (nullptr != pItem)
        {
            proto_ff::ItemProtoInfo proto;
            if (NFItemMgr::SetItemProtoInfo(pItem, &proto))
            {
                AddCollectItem(proto, vCollectItems);
            }
        }
    }
    MAP_INDEX_ITEM_PROTO_EX::iterator iterProto = mapOutNewIdxItemProtoEx.begin();
    for (; iterProto != mapOutNewIdxItemProtoEx.end(); ++iterProto)
    {
        proto_ff::ItemProtoInfo &proto = iterProto->second;
        AddCollectItem(proto, vCollectItems);
    }
    
    //计算道具数量变化的数量
    iterAdd = mapOutGridAddNum.begin();
    for (; iterAdd != mapOutGridAddNum.end(); ++iterAdd)
    {
        NFItem *pItem = GetItemByIndex(iterAdd->first);
        if (pItem)
        {
            for (size_t i = 0; i < vCollectItems.size(); ++i)
            {
                if (vCollectItems[i].item_id() == pItem->GetItemID())
                {
                    vCollectItems[i].set_item_chg_count(vCollectItems[i].item_chg_count() + iterAdd->second);
                    break;
                }
            }
        }
    }
    CollectItemEvent(vCollectItems, sourceParam, EItemOpetateType_Add);
}

void NFPackageBag::OnAddItemParam(MAP_UINT16_INT64 &mapOutGridAddNum, NFPackageBag::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, VEC_ITEM_PROTO_EX &vecProtoExParam)
{
    MAP_UINT16_INT64::iterator iterGrid = mapOutGridAddNum.begin();
    for (; iterGrid != mapOutGridAddNum.end(); ++iterGrid)
    {
        uint16_t idx = iterGrid->first;
        //int32_t num = iterGrid->second;
        NFItem *pItem = GetItemByIndex(idx);
        if (nullptr != pItem)
        {
            proto_ff::ItemProtoInfo proto;
            if (NFItemMgr::SetItemProtoInfo(pItem, &proto))
            {
                vecProtoExParam.push_back(proto);
            }
        }
    }
    MAP_INDEX_ITEM_PROTO_EX::iterator iterProto = mapOutNewIdxItemProtoEx.begin();
    for (; iterProto != mapOutNewIdxItemProtoEx.end(); ++iterProto)
    {
        uint16_t idx = iterProto->first;
        proto_ff::ItemProtoInfo &proto = iterProto->second;
        //
        proto_ff::ItemProtoInfo protoParam(proto);
        protoParam.set_index(idx);
        vecProtoExParam.push_back(protoParam);
    }
}

bool NFPackageBag::ClearPackage()
{
    //
    ORDER_MAP_UINT16_INT64 mapGridReduceNum;
    mapGridReduceNum.clear();
    for (size_t i = 0; i <= m_nOpenGrid; ++i)
    {
        NFItem *pItem = GetItemByIndex(i);
        if (nullptr != pItem)
        {
            mapGridReduceNum[i] = pItem->GetNum();
        }
    }
    //移除物品
    MAP_UINT64_INT64 mapItemNum;
    return RemoveBagItem(mapGridReduceNum, mapItemNum);
}

int32_t NFPackageBag::Expand(int32_t &nNum)
{
    if (m_nOpenGrid >= GetMaxGridNum())
    {
        return proto_ff::RET_PACKAGE_EXPAND_LIMIT;
    }
    int16_t nLefNum = GetMaxGridNum() - m_nOpenGrid;
    if (nNum >= nLefNum)
    {
        nNum = nLefNum;
    }
    m_nExpandNum += nNum;
    m_nOpenGrid += nNum;
    SetPackageSaveFlag(true);
    return proto_ff::RET_SUCCESS;
}

int32_t NFPackageBag::GetMaxGridNum()
{
    return m_maxGrid;
}

int64_t NFPackageBag::GetItemLeftPile(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    nUnBindNum = 0;
    nBindNum = 0;
    mapUnbindGridHas.clear();
    mapBindGridHas.clear();
    
    int64_t stackLimit = 1;
    uint8_t byLabel = 1;
    auto pItemCfg = ItemItemDesc::Instance()->GetDesc(nItemID);
    if (nullptr == pItemCfg)
    {
        auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(nItemID);
        if (nullptr == pEquipCfg)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] GetItemLeftPile...can not find item cfg ...nItemID[%lu] ", nItemID);
            return 0;
        }
        //装备是不允许有叠加的，所以这里直接返回
        return 0;
    }
    else
    {
        stackLimit = NFItemMgr::ItemMaxPile(pItemCfg);
    }
    
    return GetLabelItemLeftPile(byLabel, nItemID, stackLimit, nUnBindNum, nBindNum, mapUnbindGridHas, mapBindGridHas);
}

int64_t NFPackageBag::GetLabelItemLeftPile(uint8_t byLabel, uint64_t nItemID, int64_t stackLimit, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    nUnBindNum = 0;
    nBindNum = 0;
    mapUnbindGridHas.clear();
    mapBindGridHas.clear();
    
    //
    for (size_t i = 0; i < m_nOpenGrid; ++i)
    {
        NFItem *pItem = GetItemByIndex(i);
        if (nullptr != pItem && nItemID == pItem->GetItemID())
        {
            int8_t byBind = pItem->GetBind();
            int64_t nPile = (int64_t) pItem->GetNum();
            if (nPile < stackLimit)
            {
                if ((uint8_t) EBindState::EBindState_no == byBind)
                {
                    nUnBindNum += (stackLimit - nPile);
                    mapUnbindGridHas[pItem->GetIndex()] = nPile;
                }
                else if ((uint8_t) EBindState::EBindState_bind == byBind)
                {
                    nBindNum += (stackLimit - nPile);
                    mapBindGridHas[pItem->GetIndex()] = nPile;
                }
            }
        }
    }
    return (nUnBindNum + nBindNum);
}

bool NFPackageBag::RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam)
{
    MAP_UINT16_INT64 mapIdxNum;
    mapIdxNum.clear();
    for (int i = 0; i < m_nOpenGrid; i++)
    {
        NFItem*pItem = GetItemByIndex(i);
        if (nullptr != pItem)
        {
            auto pItemCfg = ItemItemDesc::Instance()->GetDesc(pItem->GetItemID());
            if (nullptr != pItemCfg && itemSubType == pItemCfg->m_subType)
            {
                mapIdxNum[pItem->GetIndex()] = pItem->GetNum();
            }
        }
    }
    if (mapIdxNum.size() > 0)
    {
        RemoveItem(mapIdxNum, sourceParam);
        return true;
    }
    return false;
}

bool NFPackageBag::RemoveAllByItemID(uint64_t nItemID, SCommonSource &sourceParam)
{
    MAP_UINT16_INT64 mapIdxNum;
    mapIdxNum.clear();
    for (int i = 0; i < m_nOpenGrid; i++)
    {
        NFItem*pItem = GetItemByIndex(i);
        if (nullptr != pItem && pItem->GetItemID() == nItemID)
        {
            mapIdxNum[pItem->GetIndex()] = pItem->GetNum();
        }
    }
    
    if (mapIdxNum.size() > 0)
    {
        RemoveItem(mapIdxNum, sourceParam);
        return true;
    }
    return false;
}

void NFPackageBag::AllOpenGrid()
{
    if (GetMaxGridNum() - m_nOpenGrid)
    {
        int32_t nLeftNum = GetMaxGridNum() - m_nOpenGrid;
        Expand(nLeftNum);
    }
}

uint32_t NFPackageBag::GetEmptyGrid(VEC_UINT16 &vecGrid)
{
    vecGrid.clear();
    for (int i = 0; i < m_nOpenGrid; i++)
    {
        if (GetItemByIndex(i))
            vecGrid.push_back(i);
    }
    return (uint32_t) vecGrid.size();
}

uint32_t NFPackageBag::GetEmptyGrid()
{
    int32_t all = 0;
    for (int i = 0; i < m_nOpenGrid; i++)
    {
        if (GetItemByIndex(i))
            all++;
    }
    return all;
}

void NFPackageBag::SetPackageSaveFlag(bool bSave)
{
    NFPart *pPart = m_pMaster->GetPart(PART_PACKAGE);
    if (pPart)
    {
        pPart->MarkDirty();
    }
}

bool NFPackageBag::SetUpdateItemInfo(NFItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel)
{
    if (bDel)
    {
        return NFItemMgr::SetItemProtoInfo(pItem, protoItemInfo, 0);
    }
    return NFItemMgr::SetItemProtoInfo(pItem, protoItemInfo);
}

bool NFPackageBag::AddPackageUpdateInfo(NFItem *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel)
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

void NFPackageBag::UpdatePackageInfo(proto_ff::NotifyPackageUpdate &protoUpdate)
{
    if (protoUpdate.item_list_size() > 0)
    {
        protoUpdate.set_package_type(m_nPackageType);
        m_pMaster->SendMsgToClient(proto_ff::NOTIFY_PACKAGE_UPDATE, protoUpdate);
    }
}

bool NFPackageBag::UpdatePackageExpand()
{
    return true;
}

void NFPackageBag::OnRemoveItemEvent(MAP_UINT64_INT64 &mapItemNum, SCommonSource &sourceParam)
{
    //移除物品 任务事件
    VEC_ITEM_PROTO_EX vCollectItems;
    MAP_UINT64_INT64::iterator iterRemove = mapItemNum.begin();
    for (; iterRemove != mapItemNum.end(); ++iterRemove)
    {
        if (iterRemove->second <= 0)
        {
            continue;
        }
        
        proto_ff::ItemProtoInfo proto;
        proto.set_item_id(iterRemove->first);
        proto.set_item_num(-iterRemove->second);
        AddCollectItem(proto, vCollectItems);
    }
    CollectItemEvent(vCollectItems, sourceParam, EItemOpetateType_Del);
}

void NFPackageBag::AddCollectItem(proto_ff::ItemProtoInfo &itemProto, VEC_ITEM_PROTO_EX &vCollectItems)
{
    for (uint32_t i = 0; i < vCollectItems.size(); ++i)
    {
        proto_ff::ItemProtoInfo &tItemPb = vCollectItems[i];
        if (tItemPb.item_id() == itemProto.item_id())
        {
            uint64_t newNum = tItemPb.item_num() + itemProto.item_num();
            tItemPb.set_item_num(newNum);
            return;
        }
    }
    //没有相同的 插入
    vCollectItems.push_back(itemProto);
}

void NFPackageBag::CollectItemEvent(VEC_ITEM_PROTO_EX &vCollectItems, SCommonSource &sourceParam, int32_t nOperateType)
{

}

void NFPackageBag::ItemLog(MAP_UINT16_INT64 &items, NFPackageBag::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &source)
{

}

void NFPackageBag::ItemLog(MAP_UINT64_INT64 &items, SCommonSource &source)
{

}

void NFPackageBag::ClearIdxRecord()
{
    m_setIdxRecord.clear();
}

SET_UINT16 &NFPackageBag::GetIdxRecord()
{
    return m_setIdxRecord;
}

bool NFPackageBag::SortItem()
{
    return true;
}

bool NFPackageBag::BagItemSort()
{
    return false;
}

void NFPackageBag::ItemSell(proto_ff::PackageSellReq &req)
{

}

uint16_t NFPackageBag::PileMerge(VEC_PACKAGE_ITEM vecItems, VEC_ITEM_PROTO_EX &vecPileProtoEx)
{
    return 0;
}

void NFPackageBag::ProcessItem(const LIST_ITEM &lstItem, LIST_ITEM &outLstItem, MAP_UINT32_INT64 &mapAttr, bool addFlag)
{
    for (auto &e : lstItem)
    {
        const SItem &ref = e;
        uint32_t attrId = 0;
        CHECK_CONTINUE(ref.nItemID > 0 && ref.nNum > 0);
        //1:虚拟物品
        if (NFItemMgr::IsVirItem(ref.nItemID, attrId))
        {
            mapAttr[attrId] += ref.nNum;
        }
            //2:动态经验类
        else if (NFItemMgr::IsDynExpItem(ref.nItemID))
        {
            mapAttr[proto_ff::A_EXP] += calcDynExp(ItemDescEx::Instance()->GetDynExpType(ref.nItemID), ref.nNum);
        }
        else
        {
            bool ret = false;
            do
            {
                CHECK_BREAK(addFlag);
                //替换
                auto pItemCfg = ItemItemDesc::Instance()->GetDesc(ref.nItemID);
                if (ItemDescEx::Instance()->IsTianShenActiveNum(pItemCfg)) //天神激活物品
                {
                    int32_t tianshenId = ItemDescEx::Instance()->GetTianShenId(ref.nItemID);
                    uint64_t replaceItemId = 0;
                    int32_t replaceItemNum = 0;
                    ret = ItemDescEx::Instance()->replaceItem(ref.nItemID, ref.nNum, replaceItemId, replaceItemNum);
                    CHECK_BREAK(ret);
                    auto pDeityPart = dynamic_cast<NFDeityPart*>(m_pMaster->GetPart(PART_DEITY));
                    CHECK_BREAK(pDeityPart);
                    CHECK_BREAK(pDeityPart->IsActiveDeity(tianshenId));
                    CHECK_BREAK(replaceItemId > 0 && replaceItemNum > 0);
                    SItem t;
                    t.nItemID = replaceItemId;
                    t.nNum = replaceItemNum;
                    t.byBind = ref.byBind;
                    outLstItem.push_back(t);
                    ret = true;
                }
                else
                {
                    ret = false;
                }
            } while (false);
            
            if (!ret) {
                outLstItem.push_back(ref);
            }
        }
    }
}

void NFPackageBag::ProcessItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr, bool addFlag)
{
    for (auto& e : vecProtoItemsEx)
    {
        proto_ff::ItemProtoInfo& ref = e;
        uint32_t attrId = 0;
        uint64_t itemId = ref.item_id();
        int32_t itemNum = ref.item_num();
        CHECK_CONTINUE(itemId > 0 && itemNum >0);
        //1:虚拟物品
        if (NFItemMgr::IsVirItem(itemId, attrId))
        {
            mapAttr[attrId] += ref.item_num();
        }//2:动态经验类
        else if (NFItemMgr::IsDynExpItem(itemId))
        {
            mapAttr[proto_ff::A_EXP] += calcDynExp(ItemDescEx::Instance()->GetDynExpType(itemId), itemNum);
        }
        else
        {
            bool ret = false;
            do
            {
                CHECK_BREAK(addFlag);
                //替换
                auto pItemCfg = ItemItemDesc::Instance()->GetDesc(itemId);
                if (ItemDescEx::Instance()->IsTianShenActiveNum(pItemCfg)) //天神激活物品
                {
                    int32_t tianshenId = ItemDescEx::Instance()->GetTianShenId(itemId);
                    uint64_t replaceItemId = 0;
                    int32_t replaceItemNum = 0;
                    ret = ItemDescEx::Instance()->replaceItem(itemId, itemNum, replaceItemId, replaceItemNum);
                    CHECK_BREAK(ret);
                    auto pDeityPart = dynamic_cast<NFDeityPart*>(m_pMaster->GetPart(PART_DEITY));
                    CHECK_BREAK(pDeityPart);
                    CHECK_BREAK(pDeityPart->IsActiveDeity(tianshenId));
                    CHECK_BREAK(replaceItemId > 0 && replaceItemNum > 0);
                    SItemCond c;
                    LIST_ITEM lstItem;
                    SItem t;
                    t.nItemID = replaceItemId;
                    t.nNum = replaceItemNum;
                    t.byBind = ref.bind();
                    lstItem.push_back(t);
                    VEC_ITEM_PROTO_EX v;
                    CHECK_BREAK(NFItemMgr::CreateItem(lstItem, v, c));
                    for (auto& e : v)
                    {
                        vecOutProtoItemsEx.push_back(e);
                    }
                    ret = true;
                }
                else
                {
                    ret = false;
                }
            } while (false);
            
            if (!ret) {
                vecOutProtoItemsEx.push_back(ref);
            }
        }
    }
}

void NFPackageBag::MergePackageItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, NFPackageBag::MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, NFPackageBag::MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx)
{
    return MergeItemList(inlstItem, vecinProtoEx, mapOutLabelItem, mapOutLabelVecItemProtoEx);
}

void NFPackageBag::MergeItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, NFPackageBag::MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, NFPackageBag::MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx)
{
    mapOutLabelItem.clear();
    mapOutLabelVecItemProtoEx.clear();
    //
    MAP_LABEL_LIST_ITEM_EX mapLabelNoPileItemEx;//不可堆叠物品
    mapLabelNoPileItemEx.clear();
    LIST_ITEM::iterator iter = inlstItem.begin();
    for (; iter != inlstItem.end(); ++iter)
    {
        SItem &in = (*iter);
        if (in.nItemID == 0)
        {
            continue;
        }
        
        uint8_t byType = proto_ff::EItemType_None;
        int8_t byBind = (int8_t) EBindState::EBindState_no;
        int64_t maxPile = 0;
        uint8_t byLabel = 1;
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(in.nItemID);
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(in.nItemID);
            if (nullptr == pEquipCfg)
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] nullptr == pEquipCfg, itemid:%lu ", in.nItemID);
                continue;
            }
            
            byType = proto_ff::EItemType_Equip;
            byBind = NFItemMgr::BindStateByWay(pEquipCfg, in.byBind);
            maxPile = NFItemMgr::ItemMaxPile(pEquipCfg);
        }
        else
        {
            byType = pItemCfg->m_itemType;
            byBind = NFItemMgr::BindStateByWay(pItemCfg, in.byBind);
            maxPile = NFItemMgr::ItemMaxPile(pItemCfg);
        }
        //
        if (byBind != (int8_t) EBindState::EBindState_no && byBind != (int8_t) EBindState::EBindState_bind)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList bind state error ,itemid[%lu],num[%ld], bybind[%d] ", in.nItemID, in.nNum, byBind);
            continue;
        }
        if (maxPile <= 0)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList maxPile error ,itemid[%lu],num[%ld], bybind[%d], maxPile:%ld ", in.nItemID, in.nNum, byBind, maxPile);
            continue;
        }
        
        LIST_ITEM_EX *pLstLabelItem = nullptr;
        MAP_LABEL_LIST_ITEM_EX::iterator iterLabelItem = mapOutLabelItem.find(byLabel);
        if (iterLabelItem == mapOutLabelItem.end())
        {
            LIST_ITEM_EX lstOutItem;
            lstOutItem.clear();
            mapOutLabelItem[byLabel] = lstOutItem;
            pLstLabelItem = &mapOutLabelItem[byLabel];
        }
        else
        {
            pLstLabelItem = &iterLabelItem->second;
        }
        
        if (proto_ff::EItemType_Equip == byType || 1 == maxPile) //装备或者 不可堆叠物品
        {
            LIST_ITEM_EX *pLstLabelNoPileItem = nullptr;
            MAP_LABEL_LIST_ITEM_EX::iterator iterLabelNoPile = mapLabelNoPileItemEx.find(byLabel);
            if (iterLabelNoPile == mapLabelNoPileItemEx.end())
            {
                LIST_ITEM_EX lstOutItem;
                lstOutItem.clear();
                mapLabelNoPileItemEx[byLabel] = lstOutItem;
                pLstLabelNoPileItem = &mapLabelNoPileItemEx[byLabel];
            }
            else
            {
                pLstLabelNoPileItem = &iterLabelNoPile->second;
            }
            
            for (int64_t i = 0; i < in.nNum; ++i)
            {
                SItemEx equip;
                equip.nItemID = in.nItemID;
                equip.nNum = 1;
                equip.byBind = byBind;
                equip.stackNum = maxPile;
                equip.byType = byType;
                pLstLabelNoPileItem->push_back(equip);
            }
            
            continue;
        }
        
        //非装备并且可堆叠物品
        bool bFlag = false;
        LIST_ITEM_EX::iterator iterout = pLstLabelItem->begin();
        for (; iterout != pLstLabelItem->end(); ++iterout)
        {
            SItemEx &out = (*iterout);
            if (out.nItemID == in.nItemID && out.byBind == byBind)
            {
                out.nNum += in.nNum;
                bFlag = true;
                break;
            }
        }
        if (!bFlag)
        {
            SItemEx itemEx;
            itemEx.nItemID = in.nItemID;
            itemEx.nNum = in.nNum;
            itemEx.byBind = byBind;
            itemEx.stackNum = maxPile;
            itemEx.byType = byType;
            //这里校验下堆叠数
            pLstLabelItem->push_back(itemEx);
            //int32_t isize = pLstLabelItem->size();
            //if (isize > 0)
            //{
            //	isize = isize;
            //}
        }
    } // end of for (; iter != inlstItem.end(); ++iter)
    
    //处理不可堆叠物品
    MAP_LABEL_LIST_ITEM_EX::iterator iterNoPile = mapLabelNoPileItemEx.begin();
    for (; iterNoPile != mapLabelNoPileItemEx.end(); ++iterNoPile)
    {
        uint8_t byLabel = iterNoPile->first;
        LIST_ITEM_EX &lstNoPileItemEx = iterNoPile->second;
        LIST_ITEM lstNoPileItem;
        lstNoPileItem.clear();
        LIST_ITEM_EX::iterator iterEx = lstNoPileItemEx.begin();
        for (; iterEx != lstNoPileItemEx.end(); ++iterEx)
        {
            SItemEx &itemEx = (*iterEx);
            SItem item(itemEx.nItemID, itemEx.nNum, itemEx.byBind);
            lstNoPileItem.push_back(item);
        }
        VEC_ITEM_PROTO_EX *pVecProtoEx = nullptr;
        MAP_LABEL_VEC_ITEM_PROTO_EX::iterator iterA = mapOutLabelVecItemProtoEx.find(byLabel);
        if (iterA == mapOutLabelVecItemProtoEx.end())
        {
            VEC_ITEM_PROTO_EX vecItemProtoA;
            vecItemProtoA.clear();
            mapOutLabelVecItemProtoEx[byLabel] = vecItemProtoA;
            pVecProtoEx = &mapOutLabelVecItemProtoEx[byLabel];
        }
        else
        {
            pVecProtoEx = &iterA->second;
        }
        //
        SItemCond itemCond;
        NFItemMgr::CreateItem(lstNoPileItem, *pVecProtoEx, itemCond, false);
    }
    
    VEC_ITEM_PROTO_EX::iterator iterProto = vecinProtoEx.begin();
    for (; iterProto != vecinProtoEx.end(); ++iterProto)
    {
        const proto_ff::ItemProtoInfo &proto = (*iterProto);
        //
        uint8_t byType = proto_ff::EItemType_None;
        int8_t byBind = (int8_t) EBindState::EBindState_no;
        int64_t maxPile = 0;
        uint8_t byLabel = 1;
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(proto.item_id());
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(proto.item_id());
            if (nullptr == pEquipCfg)
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] nullptr == pEquipCfg, itemid:%lu ", proto.item_id());
                continue;
            }
            
            byType = proto_ff::EItemType_Equip;
            byBind = NFItemMgr::BindStateByWay(pEquipCfg, proto.bind());
            maxPile = NFItemMgr::ItemMaxPile(pEquipCfg);
        }
        else
        {
            byType = pItemCfg->m_itemType;
            byBind = NFItemMgr::BindStateByWay(pItemCfg, proto.bind());
            maxPile = NFItemMgr::ItemMaxPile(pItemCfg);
        }
        //
        if (byBind != (int8_t) EBindState::EBindState_no && byBind != (int8_t) EBindState::EBindState_bind)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList bind state error ,itemid[%lu],num[%ld], bybind[%d] ", proto.item_id(), proto.item_num(), byBind);
            continue;
        }
        if (maxPile <= 0)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList maxPile error ,itemid[%lu],num[%ld], bybind[%d], maxPile:%ld ", proto.item_id(), proto.item_num(), byBind, maxPile);
            continue;
        }
        
        /*
        这里需要处理下 玩家可以改变属性的物品，比如 所有的装备,血包，星魂传送物品，藏宝图，跑商商券等
        此类物品必须是不可堆叠物品
        */
        if (proto_ff::EItemType_Equip == byType || 1 == maxPile)
        {
            proto_ff::ItemProtoInfo newproto(proto);
            newproto.set_bind(byBind);
            //
            VEC_ITEM_PROTO_EX *pVecProtoEx = nullptr;
            MAP_LABEL_VEC_ITEM_PROTO_EX::iterator iterA = mapOutLabelVecItemProtoEx.find(byLabel);
            if (iterA == mapOutLabelVecItemProtoEx.end())
            {
                VEC_ITEM_PROTO_EX vecItemProtoA;
                vecItemProtoA.clear();
                mapOutLabelVecItemProtoEx[byLabel] = vecItemProtoA;
                pVecProtoEx = &mapOutLabelVecItemProtoEx[byLabel];
            }
            else
            {
                pVecProtoEx = &iterA->second;
            }
            pVecProtoEx->push_back(newproto);
        }
        else
        {
            LIST_ITEM_EX *pLstLabelItem = nullptr;
            MAP_LABEL_LIST_ITEM_EX::iterator iterLabelItem = mapOutLabelItem.find(byLabel);
            if (iterLabelItem == mapOutLabelItem.end())
            {
                LIST_ITEM_EX lstOutItem;
                lstOutItem.clear();
                mapOutLabelItem[byLabel] = lstOutItem;
                pLstLabelItem = &mapOutLabelItem[byLabel];
            }
            else
            {
                pLstLabelItem = &iterLabelItem->second;
            }
            //
            bool bFlag = false;
            LIST_ITEM_EX::iterator iterout = pLstLabelItem->begin();
            for (; iterout != pLstLabelItem->end(); ++iterout)
            {
                SItemEx &out = (*iterout);
                if (out.nItemID == proto.item_id() && out.byBind == byBind)
                {
                    out.nNum += proto.item_num();
                    bFlag = true;
                    break;
                }
            }
            if (!bFlag)
            {
                SItemEx item;
                item.nItemID = proto.item_id();
                item.nNum = proto.item_num();
                item.byBind = byBind;
                item.stackNum = maxPile;
                item.byType = byType;
                //这里校验下堆叠数
                pLstLabelItem->push_back(item);
            }
        } // end of if (1 == maxPile)
    } // end of for (; iterProto != vecinProtoEx.end(); ++iterProto)
}
