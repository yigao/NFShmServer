// -------------------------------------------------------------------------
//    @FileName         :    NFBagPage.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFBagPage
//
// -------------------------------------------------------------------------

#include "NFBagPage.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "Package.pb.h"
#include "Player/NFPlayer.h"
#include "ClientServerCmd.pb.h"

NFBagPage::NFBagPage(NFIPluginManager *pPluginManager) : NFObject(pPluginManager)
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

int NFBagPage::CreateInit()
{
    m_grids.CreateInit();
    m_nLastSortTime = 0;
    m_nExpandNum = 0;
    m_nOpenGrid = 0;
    m_initGrid = 0;
    m_maxGrid = 0;
    m_nPackageType = 0;
    m_pMaster = NULL;
    return 0;
}

int NFBagPage::ResumeInit()
{
    return 0;
}

NFBagPage::~NFBagPage()
{

}

int NFBagPage::InitGrid(NFPlayer *pMaster, uint32_t nPackageType, uint32_t nInitGrid, uint32_t nMaxGrid)
{
    CHECK_NULL(pMaster);
    NF_ASSERT(nMaxGrid >= nInitGrid && nMaxGrid <= STORAGE_PACKAGE_MAX_GRID_NUM);
    m_pMaster = pMaster;
    m_nLastSortTime = 0;
    m_nExpandNum = 0;
    m_nOpenGrid = nInitGrid;
    m_nPackageType = nPackageType;
    m_initGrid = nInitGrid;
    m_maxGrid = nMaxGrid;

    m_grids.CreateInit();
    m_grids.resize(m_nOpenGrid);
    return 0;
}

int NFBagPage::Init(const proto_ff::RoleDBUnitBagData &dbData)
{
    const proto_ff::BagDBSimpleData &refSimpleData = dbData.simple();
    m_nExpandNum = refSimpleData.expand_num();
    m_nOpenGrid += m_nExpandNum;
    m_grids.CreateInit();
    m_grids.resize(m_nOpenGrid);

    int32_t partSize = dbData.parts_size();

    for (int32_t i = 0; i < partSize; ++i)
    {
        const proto_ff::BagItemsDBData &refdbItemData = dbData.parts(i);
        int32_t partItemSize = refdbItemData.data_size();
        for (int32_t j = 0; j < partItemSize; ++j)
        {
            const proto_ff::ItemProtoInfo &protoItem = refdbItemData.data(j);
            auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(protoItem.item_id());
            if (nullptr == pItemCfg)
            {
                auto pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(protoItem.item_id());
                if (nullptr == pEquipCfg)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackageBag::Init..nullptr == pEquipCfg....cid:{},itemid:{} ", m_pMaster->GetRoleId(),
                               protoItem.item_id());
                    continue;
                }
            }

            int index = SetItemByIndex(protoItem.index(), protoItem);
            CHECK_EXPR_ASSERT(index == protoItem.index(), -1, "");
        }
    }
    return 0;
}

int NFBagPage::UnInit()
{
    return 0;
}

int NFBagPage::SaveDB(proto_ff::RoleDBUnitBagData &dbData)
{
    proto_ff::BagDBSimpleData *pSimpleData = dbData.mutable_simple();
    pSimpleData->set_package_type(m_nPackageType);
    pSimpleData->set_expand_num(m_nExpandNum);
    proto_ff::BagItemsDBData *pPartItems = dbData.add_parts();
    for (int i = 0; i < (int) m_nOpenGrid; i++)
    {
        if (pPartItems->data_size() >= 10)
        {
            pPartItems = dbData.add_parts();
        }
        NFGridItem *pItem = GetItemByIndex(i);
        if (pItem)
        {
            proto_ff::ItemProtoInfo *pItemInfo = pPartItems->add_data();
            pItem->write_to_pbmsg(*pItemInfo);
        }
    }

    return 0;
}

int NFBagPage::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return 0;
}

//能否添加物品
bool NFBagPage::CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx)
{
    VEC_ITEM_PROTO_EX vecOutProtoEx;
    vecOutProtoEx.clear();
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(vecProtoItemsEx, vecOutProtoEx);

    LIST_ITEM lstItem;
    lstItem.clear();
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItem;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapLabelVecProtoEx;
    MergePackageItemList(lstItem, vecOutProtoEx, mapOutLabelItem, mapLabelVecProtoEx);

    MAP_UINT16_INT64 mapGridAddNum;
    MAP_INDEX_ITEM_PROTO_EX mapIndexProtoEx;
    return CanPackageAddItem(mapOutLabelItem, mapLabelVecProtoEx, mapGridAddNum, mapIndexProtoEx);
}

//是否能添加物品
bool NFBagPage::CanAddItem(LIST_ITEM &lstItem)
{
    LIST_ITEM lstOutItem;
    lstOutItem.clear();
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(lstItem, lstOutItem);

    VEC_ITEM_PROTO_EX vecInProtoEx;
    MAP_LABEL_LIST_ITEM_EX mapOutLabelItemEx;
    MAP_LABEL_VEC_ITEM_PROTO_EX mapOutLabelVecPorotEx;
    MergePackageItemList(lstOutItem, vecInProtoEx, mapOutLabelItemEx, mapOutLabelVecPorotEx);

    MAP_UINT16_INT64 mapOutGridResultNum;
    MAP_INDEX_ITEM_PROTO_EX mapOutNewIdxItemProtoEx;
    return CanPackageAddItem(mapOutLabelItemEx, mapOutLabelVecPorotEx, mapOutGridResultNum, mapOutNewIdxItemProtoEx);
}
//能否添加进背包
bool NFBagPage::CanPackageAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx,
                                  MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx)
{
    return CanBagAddItem(mapInLabelItem, mapInLabelVecItemProtoEx, mapOutGridAddNum, mapOutNewIdxItemProtoEx);
}

//能否添加到背包
bool NFBagPage::CanBagAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx,
                              MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx)
{
    //每个标签页剩余格子数
    MAP_INT8_VEC_UINT32 mapLabelVecGrid;
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
        VEC_UINT32 *pLabelNewGrid = nullptr;
        auto iterLabelGrid = mapLabelVecGrid.find(byLabel);
        if (iterLabelGrid == mapLabelVecGrid.end())
        {
            VEC_UINT32 vecNewGrid;
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
        VEC_UINT32 &vecEmptyGrid = *pLabelNewGrid;

        //统计每个标签页剩余可叠加的物品数量
        LIST_ITEM_EX::iterator iterInItem = lstInItemEx.begin();
        for (; iterInItem != lstInItemEx.end(); ++iterInItem)
        {
            SItem &item = (*iterInItem);
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
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::CanPackageAddItem..unbind....addNum > 0...addNum:{} ", addNum);
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
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::CanPackageAddItem..bind....addNum > 0...addNum:{} ", addNum);
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
                        auto iterVec = vecEmptyGrid.begin();
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
                        auto iterVec = vecEmptyGrid.begin();
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
        VEC_UINT32 *pLabelNewGrid = nullptr;
        auto iterLabelGrid = mapLabelVecGrid.find(byLabel);
        if (iterLabelGrid == mapLabelVecGrid.end())
        {
            VEC_UINT32 vecNewGrid;
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
        VEC_UINT32 &vecEmptyGrid = *pLabelNewGrid;
        if (vecEmptyGrid.size() < vecNoPileProtoEx.size())
        {
            return false; //格子不够
        }
        VEC_ITEM_PROTO_EX::iterator iterNewProto = vecNoPileProtoEx.begin();
        for (; iterNewProto != vecNoPileProtoEx.end(); ++iterNewProto)
        {
            proto_ff::ItemProtoInfo &proto = (*iterNewProto);
            VEC_UINT32::iterator iter = vecEmptyGrid.begin();
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
        if (!NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(lstNewItem, vecNewProtoEx, itemCond, false))
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

int NFBagPage::AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind/* = (int8_t)EBindState::EBindState_no*/)
{
    LIST_ITEM lstItem;
    SItem item;
    item.nItemID = nItemID;
    item.nNum = nNum;
    item.byBind = byBind;
    lstItem.push_back(item);
    return AddItem(lstItem, sourceParam);
}

int NFBagPage::AddItem(const LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update/* = true*/, bool tip/* = true*/)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(lstItem, lstOutItem, mapAttr);

    //
    VEC_ITEM_PROTO_EX vecProtoTmpEx;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::Instance(m_pObjPluginManager)->CalcGridNeed(lstOutItem, vecProtoTmpEx, nopileNeed, pileNeed);
    VEC_UINT32 vecEmpty;
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
    return true;
}

NFGridItem *NFBagPage::GetItemByIndex(uint32_t nIndex)
{
    CHECK_EXPR(nIndex < (uint32_t) m_grids.size(), NULL, "index error:{}", nIndex);

    if (m_grids[nIndex].base.item_id > 0)
    {
        return &m_grids[nIndex];
    }

    return NULL;
}

uint32_t NFBagPage::GetEmptyGrid(VEC_UINT32 &vecGrid)
{
    vecGrid.clear();
    for (int i = 0; i < (int) m_grids.size(); i++)
    {
        if (GetItemByIndex(i) == nullptr)
            vecGrid.push_back(i);
    }
    return (uint32_t) vecGrid.size();
}


void NFBagPage::MergePackageItemList(const LIST_ITEM &inlstItem, const VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem,
                                     MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx)
{
    return MergeItemList(inlstItem, vecinProtoEx, mapOutLabelItem, mapOutLabelVecItemProtoEx);
}

//合并物品列表
void NFBagPage::MergeItemList(const LIST_ITEM &inlstItem, const VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem,
                              MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx)
{
    mapOutLabelItem.clear();
    mapOutLabelVecItemProtoEx.clear();
    //
    MAP_LABEL_LIST_ITEM_EX mapLabelNoPileItemEx;//不可堆叠物品
    mapLabelNoPileItemEx.clear();
    for (auto iter = inlstItem.begin(); iter != inlstItem.end(); ++iter)
    {
        auto &in = (*iter);
        if (in.nItemID == 0)
        {
            continue;
        }
        // 新项目这里有修改TODO
        // 	if (g_GetItemCfgMgr()->IsNautralBind(in.nItemID))
        //		in.byBind = EBindState_bind;

        uint8_t byType = proto_ff::EItemType_None;
        int8_t byBind = (int8_t) EBindState::EBindState_no;
        int64_t maxPile = 0;
        uint8_t byLabel = 1;
        auto *pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(in.nItemID);
        if (nullptr == pItemCfg)
        {
            auto *pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(in.nItemID);
            if (nullptr == pEquipCfg)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] nullptr == pEquipCfg, itemid:{} ", in.nItemID);
                continue;
            }
            byType = proto_ff::EItemType_Equip;
            byBind = NFItemMgr::Instance(m_pObjPluginManager)->BindStateByWay(pEquipCfg, in.byBind);
            maxPile = NFItemMgr::Instance(m_pObjPluginManager)->ItemMaxPile(pEquipCfg);
        }
        else
        {
            byType = pItemCfg->m_itemtype;
            byBind = NFItemMgr::Instance(m_pObjPluginManager)->BindStateByWay(pItemCfg, in.byBind);
            maxPile = NFItemMgr::Instance(m_pObjPluginManager)->ItemMaxPile(pItemCfg);
        }

        if (byBind != (int8_t) EBindState::EBindState_no && byBind != (int8_t) EBindState::EBindState_bind)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList bind state error ,itemid[{}],num[{}], bybind[{}] ", in.nItemID, in.nNum, byBind);
            continue;
        }

        if (maxPile <= 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList maxPile error ,itemid[{}],num[{}], bybind[{}], maxPile:{} ", in.nItemID, in.nNum,
                       byBind,
                       maxPile);
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
                SItem equip;
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
            SItem &out = (*iterout);
            if (out.nItemID == in.nItemID && out.byBind == byBind)
            {
                out.nNum += in.nNum;
                bFlag = true;
                break;
            }
        }

        if (!bFlag)
        {
            SItem itemEx;
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
            SItem &itemEx = (*iterEx);
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
        //g_GetDropMgr()->GetItemCond(dynamic_cast<Player*>(m_pMaster), itemCond);
        NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(lstNoPileItem, *pVecProtoEx, itemCond, false);
    }

    for (auto iterProto = vecinProtoEx.begin(); iterProto != vecinProtoEx.end(); ++iterProto)
    {
        const proto_ff::ItemProtoInfo &proto = (*iterProto);
        //
        uint8_t byType = proto_ff::EItemType_None;
        int8_t byBind = (int8_t) EBindState::EBindState_no;
        int64_t maxPile = 0;
        uint8_t byLabel = 1;
        auto *pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(proto.item_id());
        if (nullptr == pItemCfg)
        {
            auto *pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(proto.item_id());
            if (nullptr == pEquipCfg)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] nullptr == pEquipCfg, itemid:{} ", proto.item_id());
                continue;
            }
            byType = proto_ff::EItemType_Equip;
            byBind = NFItemMgr::Instance(m_pObjPluginManager)->BindStateByWay(pEquipCfg, proto.bind());
            maxPile = NFItemMgr::Instance(m_pObjPluginManager)->ItemMaxPile(pEquipCfg);
        }
        else
        {
            byType = pItemCfg->m_itemtype;
            byBind = NFItemMgr::Instance(m_pObjPluginManager)->BindStateByWay(pItemCfg, proto.bind());
            maxPile = NFItemMgr::Instance(m_pObjPluginManager)->ItemMaxPile(pItemCfg);
        }
        //
        if (byBind != (int8_t) EBindState::EBindState_no && byBind != (int8_t) EBindState::EBindState_bind)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList bind state error ,itemid[{}],num[{}], bybind[{}] ", proto.item_id(),
                       proto.item_num(), byBind);
            continue;
        }
        if (maxPile <= 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] MergeItemList maxPile error ,itemid[{}],num[{}], bybind[{}], maxPile:{} ", proto.item_id(),
                       proto.item_num(),
                       byBind, maxPile);
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
                SItem &out = (*iterout);
                if (out.nItemID == proto.item_id() && out.byBind == byBind)
                {
                    out.nNum += proto.item_num();
                    bFlag = true;
                    break;
                }
            }
            if (!bFlag)
            {
                SItem item;
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

//添加背包物品
bool NFBagPage::AddPackageItem(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx,
                               const VEC_ITEM_PROTO_EX &vecProtoTipItemsEx, bool update)
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

        for (int i = 0; i < (int) vecItemProEx.size(); ++i)
        {
            proto_ff::ItemProtoInfo &proto = vecItemProEx[i];
            uint16_t idx = proto.index();
            if (idx < m_nOpenGrid)
            {
                if (nullptr == GetItemByIndex(idx))
                {
                    if (idx == SetItemByIndex(idx, proto))
                    {
                        NFGridItem *pItem = GetItemByIndex(idx);
                        CHECK_EXPR_ASSERT(pItem, false, "");
                        AddPackageUpdateInfo(pItem, protoUpdateRet);
                    }
                    else
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::AddPackageItem... SetItemByPackageType failed...idx:%d,itemid:%lu ",
                                   idx, proto.item_id());
                    }
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::AddPackageItem... SetItemByPackageType failed...idx:%d,itemid:%lu ",
                           idx, proto.item_id());
            }
        }
    }

    MAP_UINT16_INT64::iterator iterGrid = mapOutGridAddNum.begin();
    for (; iterGrid != mapOutGridAddNum.end(); ++iterGrid)
    {
        uint16_t idx = iterGrid->first;
        int64_t addNum = iterGrid->second;
        NFGridItem *pItem = GetItemByIndex(idx);
        if (nullptr == pItem)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::AddPackageItem...GetItemByPackageType is nullptr ....idx:{}", idx);
            continue;
        }
        pItem->base.item_num += (addNum);

        //m_setIdxRecord.insert(idx);
        AddPackageUpdateInfo(pItem, protoUpdateRet);
    }

    if (update)
    {
        if (vecProtoTipItemsEx.size() > 0)
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

//更新背包
void NFBagPage::UpdatePackageInfo(proto_ff::NotifyPackageUpdate &protoUpdate)
{
    if (protoUpdate.item_list_size() > 0)
    {
        protoUpdate.set_package_type(m_nPackageType);
        m_pMaster->SendMsgToClient(proto_ff::NOTIFY_PACKAGE_UPDATE, protoUpdate);
    }
}

//添加背包更新信息
bool NFBagPage::AddPackageUpdateInfo(NFGridItem *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel /*= false*/)
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

//设置更新信息
bool NFBagPage::SetUpdateItemInfo(NFGridItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel /*= false*/)
{
    if (bDel)
    {
        return NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, protoItemInfo, 0);
    }
    return NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, protoItemInfo);

}

//获取某个物品剩余可叠加的数量
int64_t NFBagPage::GetItemLeftPile(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas,
                                   ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    nUnBindNum = 0;
    nBindNum = 0;
    mapUnbindGridHas.clear();
    mapBindGridHas.clear();

    int64_t stackLimit = 1;
    uint8_t byLabel = 1;
    auto *pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(nItemID);
    if (nullptr == pItemCfg)
    {
        auto *pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(nItemID);
        if (nullptr == pEquipCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] GetItemLeftPile...can not find item cfg ...nItemID[{}] ", nItemID);
            return 0;
        }
        //装备是不允许有叠加的，所以这里直接返回
        return 0;
    }
    else
    {
        stackLimit = NFItemMgr::Instance(m_pObjPluginManager)->ItemMaxPile(pItemCfg);
    }

    return GetLabelItemLeftPile(byLabel, nItemID, stackLimit, nUnBindNum, nBindNum, mapUnbindGridHas, mapBindGridHas);
}

//获取某个标签内物品剩余可叠加数量
int64_t NFBagPage::GetLabelItemLeftPile(uint8_t byLabel, uint64_t nItemID, int64_t stackLimit, int64_t &nUnBindNum, int64_t &nBindNum,
                                        ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    nUnBindNum = 0;
    nBindNum = 0;
    mapUnbindGridHas.clear();
    mapBindGridHas.clear();

    //
    for (size_t i = 0; i < (size_t) m_grids.size(); ++i)
    {
        NFGridItem *pItem = GetItemByIndex(i);
        if (nullptr != pItem && nItemID == pItem->base.item_id)
        {
            int8_t byBind = pItem->base.bind;
            int64_t nPile = (int64_t) pItem->base.item_num;
            if (nPile < stackLimit)
            {
                if ((uint8_t) EBindState::EBindState_no == byBind)
                {
                    nUnBindNum += (stackLimit - nPile);
                    mapUnbindGridHas[pItem->base.index] = nPile;
                }
                else if ((uint8_t) EBindState::EBindState_bind == byBind)
                {
                    nBindNum += (stackLimit - nPile);
                    mapBindGridHas[pItem->base.index] = nPile;
                }
            }
        }
    }
    return (nUnBindNum + nBindNum);
}

int NFBagPage::SetItemByIndex(uint32_t nIndex, NFGridItem *pItem)
{
    if (nIndex < (uint32_t) m_grids.size())
    {
        if (pItem)
        {
            m_grids[nIndex] = *pItem;
        }
        else
        {
            m_grids[nIndex] = NFGridItem();
        }
        return nIndex;
    }
    return -1;
}

int NFBagPage::SetItemByIndex(uint32_t nIndex, const proto_ff::ItemProtoInfo &protoItem)
{
    CHECK_EXPR(nIndex < (uint32_t) m_grids.size(), NULL, "index error:{}", nIndex);
    m_grids[nIndex].read_from_pbmsg(protoItem);
    return nIndex;
}

int64_t NFBagPage::GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    uint32_t attrId = 0;
    if (NFItemMgr::Instance(m_pObjPluginManager)->IsVirItem(nItemID, attrId))
    {
        return m_pMaster->GetAttr(attrId);
    }

    return GetPackageItemNum(nItemID, nUnBindNum, nBindNum);
}

int64_t NFBagPage::GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    ORDER_MAP_UINT16_INT64 mapUnbindGridHas;
    ORDER_MAP_UINT16_INT64 mapBindGridHas;
    return GetPackageItemNum(nItemID, nUnBindNum, nBindNum, mapUnbindGridHas, mapBindGridHas);
}

int64_t NFBagPage::GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas,
                                     ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    for (uint16_t i = 0; i < m_nOpenGrid; ++i)
    {
        NFGridItem *pItem = GetItemByIndex(i);
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

bool NFBagPage::HasItem(LIST_ITEM &lstItem)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(lstItem, lstOutItem, mapAttr);
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

bool NFBagPage::HasPackageItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return HasBagItem(lstItem, mapGridReduceNum);
}

bool NFBagPage::HasPackageItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return HasBagItem(mapIdxNum, mapGridReduceNum);
}

bool NFBagPage::HasBagItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
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

bool NFBagPage::HasBagItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
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
        NFGridItem *pItem = GetItemByIndex(nIndex);
        if (nullptr == pItem || pItem->GetNum() < (uint64_t) nNum)
        {
            mapGridReduceNum.clear();
            return false;
        }
        mapGridReduceNum[nIndex] = nNum;
    }
    return true;
}

bool NFBagPage::RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
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

bool NFBagPage::RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(lstItem, lstOutItem, mapAttr);
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
    MarkDirty();
    //
    OnRemoveItemEvent(mapItemNum, sourceParam);

    //物品流水日志
    ItemLog(mapItemNum, sourceParam);

    return true;
}

bool NFBagPage::RemoveItemByIndex(uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam)
{
    MAP_UINT16_INT64 mapIndex;
    mapIndex.clear();
    mapIndex[nIndex] = nNum;
    return RemoveItem(mapIndex, sourceParam);
}

bool NFBagPage::RemoveItem(MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam)
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
    MarkDirty();
    //
    OnRemoveItemEvent(mapItemNum, sourceParam);

    //物品流水日志
    ItemLog(mapItemNum, sourceParam);
    return true;
}

bool NFBagPage::RemovePackageItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum)
{
    return RemoveBagItem(mapGridReduceNum, mapItemNum);
}

bool NFBagPage::RemoveBagItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum)
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
        NFGridItem *pItem = GetItemByIndex(idx);
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
            if (idx == SetItemByIndex(idx, nullptr))
            {
            }
            else
            {
                flag = false;
                //LogErrFmtPrint("[logic] PackagePart::RemoveBagItem....SetItemByPackageType failed...idx:%d, byPackageType:%d ", idx, byPackageType);
            }
        }
        if (flag)
        {
            MAP_UINT64_INT64::iterator iterItem = mapItemNum.find(nItemId);
            if (iterItem != mapItemNum.end())
            {
                iterItem->second += reduceNum;
            }
            else
            {
                mapItemNum[nItemId] = reduceNum;
            }
        }
    }

    UpdatePackageInfo(protoRet);

    return true;
}

void NFBagPage::OnRemoveItemEvent(MAP_UINT64_INT64 &mapItemNum, SCommonSource &sourceParam)
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

void NFBagPage::AddCollectItem(const proto_ff::ItemProtoInfo &itemProto, VEC_ITEM_PROTO_EX &vCollectItems)
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

void NFBagPage::CollectItemEvent(VEC_ITEM_PROTO_EX &vCollectItems, SCommonSource &sourceParam, int32_t nOperateType)
{
    /*
    if (vCollectItems.size() == 0)
    {
        return;
    }
    MissionPart *pPart = static_cast<MissionPart*>(m_pMaster->GetPart(PART_MISSION));
    if (nullptr != pPart)
    {
        auto iter = vCollectItems.begin();
        for (; iter != vCollectItems.end(); ++iter)
        {
            ItemProtoInfo& proto = *iter;
            ItemChangeEvent itemChangeEvent;
            itemChangeEvent.itemId = proto.item_id();
            itemChangeEvent.itemNum = proto.item_num();
            itemChangeEvent.changeType = sourceParam.source;
            itemChangeEvent.opetateType = nOperateType;
            itemChangeEvent.itemSource = sourceParam;
            itemChangeEvent.equipLinks.push_back(proto);

            g_GetEvent()->FireExecute(EVENT_ITEM_CHANGE, m_pMaster->GetCid(), CREATURE_PLAYER, &itemChangeEvent, sizeof(ItemChangeEvent));
        }
    }
    */
}

void NFBagPage::ItemLog(MAP_UINT16_INT64 &items, NFBagPage::MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &source)
{
    //移除背包物品
    //g_GetGLogInnerMgr()->ItemParam(dynamic_cast<Player*>(m_pMaster), items, false, source);
}

void NFBagPage::ItemLog(MAP_UINT64_INT64 &items, SCommonSource &source)
{
    //获得物品
/*    MAP_UINT64_INT64 mapItemNum;
    MAP_UINT16_INT64::iterator iter = items.begin();
    for (; iter != items.end(); ++iter)
    {
        CItemBase *pItem = GetItemByIndex(iter->first);
        if (nullptr == pItem)
        {
            continue;
        }
        MAP_UINT64_INT64::iterator iterItem = mapItemNum.find(pItem->GetItemID());
        if (iterItem != mapItemNum.end())
        {
            iterItem->second += iter->second;
        }
        else
        {
            mapItemNum[pItem->GetItemID()] = iter->second;
        }
    }
    //
    MAP_INDEX_ITEM_PROTO_EX::iterator iterIdx = mapOutNewIdxItemProtoEx.begin();
    for (; iterIdx != mapOutNewIdxItemProtoEx.end(); ++iterIdx)
    {
        const ItemProtoInfo &proto = iterIdx->second;
        MAP_UINT64_INT64::iterator iterItem = mapItemNum.find(proto.item_id());
        if (iterItem != mapItemNum.end())
        {
            iterItem->second += proto.item_num();
        }
        else
        {
            mapItemNum[proto.item_id()] = proto.item_num();
        }
    }*/
    //
//	g_GetGLogInnerMgr()->ItemParam(dynamic_cast<Player*>(m_pMaster), mapItemNum, true, source);
}

bool NFBagPage::AddItem(const VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update, bool tip)
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
    return AddItem(vecProtoEx, sourceParam, update);
}

bool NFBagPage::AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update, bool tip)
{
    VEC_ITEM_PROTO_EX vecOutProtoItemEx;
    vecOutProtoItemEx.clear();
    MAP_UINT32_INT64 mapAttr;
    mapAttr.clear();
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(vecProtoItemsEx, vecOutProtoItemEx, mapAttr);
    //
    LIST_ITEM lstTmpItem;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::Instance(m_pObjPluginManager)->CalcGridNeed(lstTmpItem, vecOutProtoItemEx, nopileNeed, pileNeed);
    VEC_UINT32 vecEmpty;
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
    //ClearIdxRecord();
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
    MarkDirty();
    //增加物品，触发事件
    //OnAddItemEvent(mapGridAddNum, mapIndexProtoEx, sourceParam);
    //物品流水日志
    ItemLog(mapGridAddNum, mapIndexProtoEx, sourceParam);
    return true;
}

bool NFBagPage::AddItemEx(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam)
{
    VEC_ITEM_PROTO_EX vecOutProtoItemEx;
    vecOutProtoItemEx.clear();
    MAP_UINT32_INT64 mapAttr;
    mapAttr.clear();
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(vecProtoItemsEx, vecOutProtoItemEx, mapAttr);
    //
    LIST_ITEM lstTmpItem;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::Instance(m_pObjPluginManager)->CalcGridNeed(lstTmpItem, vecOutProtoItemEx, nopileNeed, pileNeed);
    VEC_UINT32 vecEmpty;
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
    //ClearIdxRecord();
    //前面已经判断过，直接增加
    AddPackageItem(mapGridAddNum, mapIndexProtoEx, vecOutProtoItemEx, true);
    //添加属性
    m_pMaster->AddVirAttr(mapAttr, false, &sourceParam, true);
    //
    MarkDirty();
    //增加物品，触发事件
    //OnAddItemEvent(mapGridAddNum, mapIndexProtoEx, sourceParam);
    //物品流水日志
    ItemLog(mapGridAddNum, mapIndexProtoEx, sourceParam);
    return true;
}

bool NFBagPage::AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, const VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update,
                        bool tip)
{
    VEC_ITEM_PROTO_EX vecOutProtoItemsEx;
    MAP_UINT32_INT64 mapAttr;
    NFItemMgr::Instance(m_pObjPluginManager)->FilterVirItem(vecProtoItemsEx, vecOutProtoItemsEx, mapAttr);
    //
    LIST_ITEM lstTmpItem;
    uint32_t pileNeed = 0;
    uint32_t nopileNeed = 0;
    NFItemMgr::Instance(m_pObjPluginManager)->CalcGridNeed(lstTmpItem, vecOutProtoItemsEx, nopileNeed, pileNeed);
    VEC_UINT32 vecEmpty;
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
    //ClearIdxRecord();
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
    MarkDirty();
    //增加物品，触发事件
    //OnAddItemEvent(mapGridAddNum, mapIndexProtoEx, sourceParam);
    //填充传出参数
    //OnAddItemParam(mapGridAddNum, mapIndexProtoEx, vecProtoItemsOut);
    //物品流水日志
    ItemLog(mapGridAddNum, mapIndexProtoEx, sourceParam);
    return true;
}

void NFBagPage::SendPackageInfoToClient()
{
    proto_ff::PackageInfoRsp proto;
    proto.set_package_type(m_nPackageType);
    proto.set_init_all_grid(m_initGrid);
    proto.set_expand_grid(m_nExpandNum);
    proto.set_max_grid(m_maxGrid);

    for (uint16_t i = 0; i < m_nOpenGrid; ++i)
    {
        NFGridItem *pItem = GetItemByIndex(i);
        if (nullptr != pItem)
        {
            proto_ff::ItemProtoInfo *protoInfo = proto.add_item_list();
            if (nullptr != protoInfo)
            {
                SetUpdateItemInfo(pItem, protoInfo);
            }
        }
    }

    m_pMaster->SendMsgToClient(proto_ff::CLIENT_PACKAGE_INFO_RSP, proto);
}

bool NFBagPage::RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam)
{
    MAP_UINT16_INT64 mapIdxNum;
    mapIdxNum.clear();
    for (int i = 0; i < (int) m_grids.size(); ++i)
    {
        NFGridItem *pItemBase = GetItemByIndex(i);
        if (nullptr != pItemBase)
        {
            auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(pItemBase->GetItemID());
            if (nullptr != pItemCfg && itemSubType == pItemCfg->m_subtype)
            {
                mapIdxNum[pItemBase->GetIndex()] = pItemBase->GetNum();
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

bool NFBagPage::RemoveAllByItemID(uint64_t nItemID, SCommonSource &sourceParam)
{
    MAP_UINT16_INT64 mapIdxNum;
    mapIdxNum.clear();
    for (int i = 0; i < (int) m_grids.size(); ++i)
    {
        NFGridItem *pItemBase = GetItemByIndex(i);
        if (nullptr != pItemBase && pItemBase->GetItemID() == nItemID)
        {
            mapIdxNum[pItemBase->GetIndex()] = pItemBase->GetNum();
        }
    }
    if (mapIdxNum.size() > 0)
    {
        RemoveItem(mapIdxNum, sourceParam);
        return true;
    }
    return false;
}

bool NFBagPage::SortItem()
{
    uint64_t curTime = NFTime::Now().UnixSec();
    if (curTime - m_nLastSortTime <= 3 && (m_nPackageType == proto_ff::EPackageType_Common || m_nPackageType == proto_ff::EPackageType_Storage)) //冷却
    {
        return false;
    }

    proto_ff::PackageSortRsp rsp;
    rsp.set_package_type(m_nPackageType);
    rsp.set_retcode(proto_ff::RET_SUCCESS);
    if (!BagItemSort())
    {
        rsp.set_retcode(proto_ff::RET_FAIL);
    }
    else
    {
        //整理完了之后，把所有的物品在此发给客户端
        m_nLastSortTime = NFTime::Now().UnixSec();
        for (uint16_t j = 0; j <= m_nOpenGrid; ++j)
        {
            NFGridItem *pItem = GetItemByIndex(j);
            if (nullptr != pItem)
            {
                proto_ff::ItemProtoInfo *proto = rsp.add_item_list();
                if (nullptr != proto)
                {
                    SetUpdateItemInfo(pItem, proto);
                }
            }
        }
        MarkDirty();
    }

    m_pMaster->SendMsgToClient(proto_ff::CLIENT_PACKAGE_SORT_RSP, rsp);

    return true;
}

bool NFBagPage::BagItemSort()
{
    uint64_t cid = m_pMaster->GetRoleId();
    //装备>材料>杂物
    VEC_PACKAGE_ITEM vecMaterial;
    VEC_PACKAGE_ITEM vecSundry;
    VEC_ITEM_PROTO_EX vecEquipProtoEx;
    VEC_ITEM_PROTO_EX vecStarProtoEx;
    VEC_ITEM_PROTO_EX vecGodhoodProtoEx;

    for (uint16_t i = 0; i < m_nOpenGrid; ++i)
    {
        NFGridItem *pItem = GetItemByIndex(i);
        if (nullptr == pItem)
        {
            continue;
        }
        auto pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(pItem->GetItemID());
        if (nullptr != pEquipCfg)
        {
            //装备
            proto_ff::ItemProtoInfo equipProto;
            if (NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, &equipProto))
            {
                vecEquipProtoEx.push_back(equipProto);
            }
        }
        else
        {
            auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(pItem->GetItemID());
            if (nullptr != pItemCfg && proto_ff::EItemType_Material == pItemCfg->m_itemtype)
            {
                //材料
                vecMaterial.push_back(*pItem);
            }
            else if (nullptr != pItemCfg && (int32_t) EItemFuncType::EItemFuncType_Fashion == pItemCfg->m_functiontype)
            {
                //时装解锁类物品，需要跟装备一起排序，所以，这里加到装备vector中
                proto_ff::ItemProtoInfo proto;
                if (NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, &proto))
                {
                    vecEquipProtoEx.push_back(proto);
                }
            }
/*            else if (nullptr != pItemCfg && proto_ff::EItemType_Star == pItemCfg->m_itemtype)
            {
                //命星
                proto_ff::ItemProtoInfo proto;
                if (NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, &proto))
                {
                    vecStarProtoEx.push_back(proto);
                }
            }
            else if (pItemCfg && pItemCfg->m_itemtype == proto_ff::EItemType_Soul)
            {
                //神格
                proto_ff::ItemProtoInfo proto;
                if (NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, &proto))
                {
                    vecGodhoodProtoEx.push_back(proto);
                }
            }*/
            else
            {
                //杂物
                vecSundry.push_back(*pItem);
            }
        }
    }

    //装备索引
    VEC_PACKAGE_ITEM vecEquipItems;
    bool retC = NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(vecEquipProtoEx, vecEquipItems);

    //命星
    VEC_PACKAGE_ITEM vecStarItems;
    bool retD = NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(vecStarProtoEx, vecStarItems);

    //神格
    VEC_PACKAGE_ITEM vecGodhoodItems;
    bool retE = NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(vecGodhoodProtoEx, vecGodhoodItems);

    //材料
    VEC_PACKAGE_ITEM vecMaterialItems;
    VEC_ITEM_PROTO_EX vecMaterialProto;

    //堆叠合并
    PileMerge(vecMaterial, vecMaterialProto);
    bool retA = NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(vecMaterialProto, vecMaterialItems);

    //杂物
    VEC_PACKAGE_ITEM vecSundryItems;
    VEC_ITEM_PROTO_EX vecSundryProtoEx;
    //堆叠合并
    PileMerge(vecSundry, vecSundryProtoEx);
    bool retB = NFItemMgr::Instance(m_pObjPluginManager)->CreateItem(vecSundryProtoEx, vecSundryItems);

    //判断创建物品的结果
    if (!retA || !retB || !retC || !retD || !retE) //创建物品失败，需要回收物品
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::BagItemSort....!retA || !retB.....cid:{}, byPackageType:{} ", cid, m_nPackageType);
        return false;
    }

    //先清空包裹内所有的格子，然后按装备，材料，杂物的顺序设置物品
    for (uint16_t j = 0; j < m_nOpenGrid; ++j)
    {
        NFGridItem *pItem = GetItemByIndex(j);
        if (nullptr == pItem)
        {
            continue;
        }
        //先设置格子为空，然后回收物品
        uint16_t idx = pItem->GetIndex();
        SetItemByIndex(idx, nullptr);
        //回收物品
    }

    //排序
    std::sort(std::begin(vecEquipItems), std::end(vecEquipItems),
              std::bind(&NFItemMgr::CompareEquipFunc, NFItemMgr::Instance(m_pObjPluginManager), std::placeholders::_1, std::placeholders::_2));
    std::sort(std::begin(vecMaterialItems), std::end(vecMaterialItems),
              std::bind(&NFItemMgr::CompareMaterialFunc, NFItemMgr::Instance(m_pObjPluginManager), std::placeholders::_1, std::placeholders::_2));
    std::sort(std::begin(vecSundryItems), std::end(vecSundryItems),
              std::bind(&NFItemMgr::CompareSundryFunc, NFItemMgr::Instance(m_pObjPluginManager), std::placeholders::_1, std::placeholders::_2));
    std::sort(std::begin(vecStarItems), std::end(vecStarItems),
              std::bind(&NFItemMgr::CompareStarFunc, NFItemMgr::Instance(m_pObjPluginManager), std::placeholders::_1, std::placeholders::_2));
    std::sort(std::begin(vecGodhoodItems), std::end(vecGodhoodItems),
              std::bind(&NFItemMgr::CompareGodhoodFunc, NFItemMgr::Instance(m_pObjPluginManager), std::placeholders::_1, std::placeholders::_2));

    //需要回收的物品
    VEC_PACKAGE_ITEM vecDelItem;
    vecDelItem.clear();
    //设置 装备，材料，杂物
    uint16_t idxEquip = 0; //从开始索引开始
    for (VEC_PACKAGE_ITEM::iterator iterEquip = vecEquipItems.begin(); iterEquip != vecEquipItems.end(); ++iterEquip)
    {
        NFGridItem *pItem = &(*iterEquip);
        if (nullptr != pItem)
        {
            pItem->SetIndex(idxEquip);
            if (idxEquip != SetItemByIndex(idxEquip, pItem))
            {
                //失败，需要回收
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[logic] PackagePart::BagItemSort....equip SetItemByPackageType failed..cid:{}, idx:{}, byPackageType:{} ", cid, idxEquip,
                           m_nPackageType);
            }
            else
            {
                ++idxEquip;
            }
        }
    }

    //材料
    uint16_t idxMaterial = idxEquip;
    for (VEC_PACKAGE_ITEM::iterator iterMt = vecMaterialItems.begin(); iterMt != vecMaterialItems.end(); ++iterMt)
    {
        NFGridItem *pItem = &(*iterMt);
        if (nullptr != pItem)
        {
            pItem->SetIndex(idxMaterial);
            if (idxMaterial != SetItemByIndex(idxMaterial, pItem))
            {
                //失败，需要回收
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[logic] PackagePart::BagItemSort....material SetItemByPackageType failed..cid:{}, idx:{}, byPackageType:{} ", cid,
                           idxMaterial, m_nPackageType);
            }
            else
            {
                ++idxMaterial;
            }
        }
    }

    //杂物
    uint16_t idxSundry = idxMaterial;//sundryStartIdx;
    VEC_PACKAGE_ITEM::iterator iterSd = vecSundryItems.begin();
    for (; iterSd != vecSundryItems.end(); ++iterSd)
    {
        NFGridItem *pItem = &(*iterSd);
        if (nullptr != pItem)
        {
            pItem->SetIndex(idxSundry);
            if (idxSundry != SetItemByIndex(idxSundry, pItem))
            {
                //失败，需要回收
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[logic] PackagePart::BagItemSort....sundry SetItemByIndex failed..cid:{}, idx:{}, byPackageType:{} ", cid,
                           idxSundry, m_nPackageType);
            }
            else
            {
                ++idxSundry;
            }
        }
    }

    //命星
    uint16_t idxStar = idxSundry; //从开始索引开始
    VEC_PACKAGE_ITEM::iterator iterStar = vecStarItems.begin();
    for (; iterStar != vecStarItems.end(); ++iterStar)
    {
        NFGridItem *pItem = &(*iterStar);
        if (nullptr != pItem)
        {
            pItem->SetIndex(idxStar);
            if (idxStar != SetItemByIndex(idxStar, pItem))
            {
                //失败，需要回收
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[logic] PackagePart::BagItemSort....star SetItemByPackageType failed..cid:{}, idx:{}, byPackageType:{} ", cid,
                           idxStar, m_nPackageType);
            }
            else
            {
                ++idxStar;
            }
        }
    }

    //神格
    uint16_t idxGodhood = idxStar; //从开始索引开始
    VEC_PACKAGE_ITEM::iterator iterGodhood = vecGodhoodItems.begin();
    for (; iterGodhood != vecGodhoodItems.end(); ++iterGodhood)
    {
        NFGridItem *pItem = &(*iterGodhood);
        if (nullptr != pItem)
        {
            pItem->SetIndex(idxGodhood);
            if (idxGodhood != SetItemByIndex(idxGodhood, pItem))
            {
                //失败，需要回收
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[logic] PackagePart::BagItemSort....star SetItemByPackageType failed..cid:{}, idx:{}, byPackageType:{} ", cid,
                           idxStar, m_nPackageType);
            }
            else
            {
                ++idxGodhood;
            }
        }
    }

    return true;
}

uint16_t NFBagPage::PileMerge(VEC_PACKAGE_ITEM vecItems, VEC_ITEM_PROTO_EX &vecPileProtoEx)
{
    VEC_ITEM_PROTO_EX vecSrcItems;
    MAP_ITEM_PROTO_EX mapDstItems;
    vecSrcItems.clear();
    mapDstItems.clear();
    uint16_t startIdx = 1;
    //
    VEC_PACKAGE_ITEM::iterator iterItem = vecItems.begin();
    for (; iterItem != vecItems.end(); ++iterItem)
    {
        NFGridItem *pItem = &(*iterItem);
        if (nullptr == pItem)
        {
            continue;
        }
        proto_ff::ItemProtoInfo proto;
        if (NFItemMgr::Instance(m_pObjPluginManager)->SetItemProtoInfo(pItem, &proto))
        {
            vecSrcItems.push_back(proto);
        }
    }


    //按标签格子顺序合并堆叠数
    uint16_t nNewIdx = startIdx;
    VEC_ITEM_PROTO_EX::iterator iterSrc = vecSrcItems.begin();
    while (iterSrc != vecSrcItems.end())
    {
        proto_ff::ItemProtoInfo &srcProto = (*iterSrc);
        if (srcProto.item_num() <= 0)
        {
            ++iterSrc;
            continue;
        }

        auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(srcProto.item_id());
        if (nullptr == pItemCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] PackagePart::PileMerge ...nullptr == pItemCfg ..itemid:{} ", srcProto.item_id());
            ++iterSrc;
            continue;
        }
        int64_t stackLimit = NFItemMgr::Instance(m_pObjPluginManager)->ItemMaxPile(pItemCfg);
        if (mapDstItems.size() == 0 || stackLimit <= 1)
        {
            srcProto.set_index(nNewIdx);
            mapDstItems[nNewIdx++] = srcProto;
            ++iterSrc;
            continue;
        }

        MAP_ITEM_PROTO_EX::iterator iterDst = mapDstItems.begin();
        for (; iterDst != mapDstItems.end(); ++iterDst)
        {
            proto_ff::ItemProtoInfo &dstProto = iterDst->second;
            int64_t dstNum = dstProto.item_num();
            uint64_t dstItemID = dstProto.item_id();

            if (dstNum < stackLimit && dstItemID == srcProto.item_id() && dstProto.bind() == srcProto.bind())
            {
                int64_t nLeftPileNum = stackLimit - dstNum;
                int64_t nPileNum = srcProto.item_num();
                if (nLeftPileNum >= nPileNum)
                {

                    dstNum += nPileNum;
                    nPileNum -= nPileNum;
                }
                else
                {
                    dstNum += nLeftPileNum;
                    nPileNum -= nLeftPileNum;
                }

                dstProto.set_item_num(dstNum);
                srcProto.set_item_num(nPileNum);
            }
            if (srcProto.item_num() == 0)
            {
                //格子已经为空了
                break;
            }
        } // end of for (; iterDst != mapDstItems.end(); ++iterDst)

        if (srcProto.item_num() > 0)
        {
            proto_ff::ItemProtoInfo newProto(srcProto);
            newProto.set_index(nNewIdx);
            mapDstItems[nNewIdx++] = newProto;
        }

        ++iterSrc;
    }

    MAP_ITEM_PROTO_EX::iterator iterPile = mapDstItems.begin();
    for (; iterPile != mapDstItems.end(); ++iterPile)
    {
        //uint16_t idx = iterPile->first;
        proto_ff::ItemProtoInfo &proto = iterPile->second;
        vecPileProtoEx.push_back(proto);
    }

    //返回最后一个索引，nNewIdx
    return (nNewIdx - 1);
}


