// -------------------------------------------------------------------------
//    @FileName         :    NFItemDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    22-12-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFItemDescStoreEx.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "DescStore/ItemItemDesc.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "DescStore/ConditionConditionDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "NFLogicCommon/PackageDefine.h"
#include "DescStore/FashionFashionDesc.h"
#include "DescStore/DupGroupDesc.h"
#include "DescStore/SkillSkillDesc.h"
#include "DescStore/EquipEquipDesc.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFItemDescStoreEx, EOT_ITEM_CONFIG_DESCEX_ID, NFShmObj)

NFItemDescStoreEx::NFItemDescStoreEx()
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

NFItemDescStoreEx::~NFItemDescStoreEx()
{
}

int NFItemDescStoreEx::CreateInit()
{
    return 0;
}

int NFItemDescStoreEx::ResumeInit()
{
    return 0;
}

int NFItemDescStoreEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR_ASSERT(ItemItemDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      ItemItemDesc::Instance(m_pObjPluginManager)->GetFileName());

    CHECK_EXPR_ASSERT(ConditionConditionDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      ConditionConditionDesc::Instance(m_pObjPluginManager)->GetFileName());

    Initialize();

    ProcessItem();

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFItemDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}

int NFItemDescStoreEx::ProcessItem()
{
    auto &itemArray = ItemItemDesc::Instance(m_pObjPluginManager)->GetResDesc();

    for (int i = 0; i < (int) itemArray.size(); i++)
    {
        auto &itemCfg = itemArray[i];
        if (itemCfg.m_bindtype == 1)
        {
            auto pValue = m_setNaturalBind.Find(itemCfg.m_id);
            if (pValue == NULL)
            {
                pValue = m_setNaturalBind.Insert(itemCfg.m_id);
                CHECK_EXPR_ASSERT(pValue, -1, "m_setNaturalBind Insert Failed, Not Enough Space");
            }
        }

        //使用条件
        std::string strcond = itemCfg.m_usecondition.ToString();
        if (strcond.length() > 0)
        {
            SET_INT64 setCond;
            setCond.clear();
            NFCommonApi::SplitStrToSetInt(strcond, ",", &setCond);
            for (auto itercond = setCond.begin(); itercond != setCond.end(); ++itercond)
            {
                int64_t cond = (*itercond);
                //校验条件表
                auto pCondCfg = ConditionConditionDesc::Instance(m_pObjPluginManager)->GetDesc(cond);
                CHECK_EXPR_ASSERT(pCondCfg, -1, "itemid:{} cond:{}", itemCfg.m_id, cond);
            }

            if (setCond.size() > 0)
            {
                auto pCondMap = m_mapItemUseCond.Find(itemCfg.m_id);
                if (pCondMap == NULL)
                {
                    pCondMap = m_mapItemUseCond.Insert(itemCfg.m_id);
                    CHECK_EXPR_ASSERT(pCondMap, -1, "m_mapItemUseCond.Insert Failed! No Enough Space!");
                }

                for (auto itercond = setCond.begin(); itercond != setCond.end(); ++itercond)
                {
                    int64_t cond = (*itercond);
                    auto pValue = pCondMap->Find(cond);
                    if (pValue == NULL)
                    {
                        pValue = pCondMap->Insert(cond);
                        CHECK_EXPR_ASSERT(pValue, -1, "pCondMap.Insert Failed! No Enough Space!");
                    }
                }
            }
        }

        //地图限制
        if (itemCfg.m_uselimit.ToString().length() > 0)
        {
            SET_INT64 setmap;
            setmap.clear();
            NFCommonApi::SplitStrToSetInt(itemCfg.m_uselimit.ToString(), ",", &setmap);
            auto pItemMap = m_mapItemMapLimit.Find(itemCfg.m_id);
            if (pItemMap == NULL)
            {
                pItemMap = m_mapItemMapLimit.Insert(itemCfg.m_id);
                CHECK_EXPR_ASSERT(pItemMap, -1, "m_mapItemMapLimit.Insert Failed, Not Enough Space");
                for (auto iter = setmap.begin(); iter != setmap.end(); ++iter)
                {
                    auto pValue = pItemMap->Find(*iter);
                    if (pValue == NULL)
                    {
                        pValue = pItemMap->Insert(*iter);
                        CHECK_EXPR_ASSERT(pValue, -1, "pItemMap.Insert Failed, Not Enough Space");
                    }
                }
            }
        }

        //职业限制 0通用职业，1战士，2法师，3刺客，4射手
        SET_INT32 setProfLimit;
        setProfLimit.clear();
        string profreq = itemCfg.m_profession.ToString();
        NFCommonApi::SplitStrToSetInt(profreq, ",", &setProfLimit);
        if (setProfLimit.empty()) setProfLimit.insert(0);
        SET_INT32::iterator iterProf = setProfLimit.find(0);
        if (iterProf == setProfLimit.end())
        {
            auto pProfMap = m_mapItemProfLimit.Find(itemCfg.m_id);
            if (pProfMap == NULL)
            {
                pProfMap = m_mapItemProfLimit.Insert(itemCfg.m_id);
                CHECK_EXPR_ASSERT(pProfMap, -1, "m_mapItemProfLimit.Insert Failed!, Not Enough Space");
            }

            for (auto iter = setProfLimit.begin(); iter != setProfLimit.end(); ++iter)
            {
                auto pValue = pProfMap->Find(*iter);
                if (pValue == NULL)
                {
                    pValue = pProfMap->Insert(*iter);
                    CHECK_EXPR_ASSERT(pValue, -1, "pProfMap->Insert Failed!, Not Enough Space");
                }
            }
        }

        VEC_INT64 vecParam;
        vecParam.clear();
        string strParam = itemCfg.m_functionvalue.ToString();
        if (itemCfg.m_functiontype <= (int32_t) EItemFuncType::EItemFuncType_None
            || itemCfg.m_functiontype >= (int32_t) EItemFuncType::EItemFuncType_Limit
                )
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....func type error ....itemid:{}, functype:{} ", itemCfg.m_id,
                       itemCfg.m_functiontype);
        }
        if ((int32_t) EItemFuncType::EItemFuncType_NoFunc != itemCfg.m_functiontype)
        {
            /*
                m_functiontype=1 属性ID，数值类型（1，固定值；2，百分比），数值
                m_functiontype=6 属性ID，数值（固定值）
                m_functiontype=7
                m_functiontype=9 关联宝箱表boxID
                m_functiontype=15
                m_functiontype=19 目标资金，初始资金
                m_functiontype=21 时装ID
                m_functiontype=24
                m_functiontype=26 关联激活的坐骑id,有效时间（填写小时，永久填写-1）
                m_functiontype=28 魅力值（int数值）
                m_functiontype=30 有效时间（填写小时，永久填写-1）
                m_functiontype=33 烟花对应的特效表id,烟花类型（1，全服烟花；2，场景烟花）
                m_functiontype=34 副本组ID
                m_functiontype=41 属性ID,属性VALUE,属性ID,属性VALUE,属性ID,属性VALUE[...]
            */

            NFCommonApi::SplitStrToVecInt(strParam, ";", &vecParam);
            if ((int32_t) EItemFuncType::EItemFuncType_ModifyAttr == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 3)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process....vecParam.size() < 3....itemid:{}, functype:{} ", itemCfg.m_id,
                               itemCfg.m_functiontype);
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_AttachAttr == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process11....vecParam.size() < 2....itemid:{}, functype:{} ", itemCfg.m_id,
                               itemCfg.m_functiontype);
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_Certificat == itemCfg.m_functiontype)
            {
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_Box == itemCfg.m_functiontype)
            {
                //宝箱
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process33....vecParam.size() < 1....itemid:{}, functype:{} ", itemCfg.m_id,
                               itemCfg.m_functiontype);
                    //return false;
                }
                else
                {
                    int32_t isize = vecParam.size();
                    for (int32_t i = 0; i < isize; ++i)
                    {
/*                        uint64_t boxId = vecParam.at(i);
						const BoxBoxCfgInfo *pBoxCfg = g_GetBoxBoxCfgTable()->GetBoxBoxCfgInfo(boxId);
						if (nullptr == pBoxCfg)
						{
							LogErrFmtPrint("[common] ItemCfg::Process33....nullptr == pBoxCfg....itemid:%lu, functype:%d,boxid:%lu ", itemCfg.m_id, itemCfg.m_functiontype,boxId);
							return false;
						}*/
                    }
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_ExpandPackage == itemCfg.m_functiontype)
            {

            }
            else if ((int32_t) EItemFuncType::EItemFuncType_BigHorn == itemCfg.m_functiontype)
            {

            }
            else if ((int32_t) EItemFuncType::EItemFuncType_RunBusiness == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process95....vecParam.size() < 2....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_Fashion == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process97....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                else
                {
                    uint64_t fashionId = vecParam.at(0);
                    auto *pFashionCfg = FashionFashionDesc::Instance(m_pObjPluginManager)->GetDesc(fashionId);
                    if (nullptr == pFashionCfg)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0,
                                   "[common] ItemCfg::Process97....nullptr == pFashionCfg....itemid:{}, functype:{}, strParam:{},fashionId:{} ",
                                   itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str(), fashionId);
                        return -1;
                    }
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_ActiveFomula == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process102....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_Rose == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process103....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_HangCard == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process105....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_SpecialEffect == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process106....vecParam.size() < 2....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    //return false;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_DupItem == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process107....vecParam.size() < 2....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                uint64_t dupgroupId = vecParam.at(0);
                auto pGroupCfg = DupGroupDesc::Instance(m_pObjPluginManager)->GetDesc(dupgroupId);
                if (nullptr == pGroupCfg)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[common] ItemCfg::Process108....nullptr == pGroupCfg....itemid:{}, functype:{},dupgroupId:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, dupgroupId, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_Virtual == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process109....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                uint32_t attrId = (uint32_t) vecParam.at(0);
/*				if (attrId <= A_FIGHT_END || attrId >= A_COMMON_END)
				{
					LogErrFmtPrint("[common] ItemCfg::Process110....virtual item attrId error....itemid:%lu, functype:%d, strParam:%s,attrId:%u ", itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str(), attrId);
					return false;
				}*/
                auto pVirtualMap = m_mapVirtualItemAttr.Find(itemCfg.m_id);
                if (pVirtualMap != NULL)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[common] ItemCfg::Process111....repeated virtual item id....itemid:{}, functype:{}, strParam:{},attrId:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str(), attrId);
                    return -1;
                }
                auto pAttrMap = m_mapAttrVirtualItem.Find(attrId);
                if (pAttrMap != NULL)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[common] ItemCfg::Process112....repeated virtual item attrid....itemid:{}, functype:{}, strParam:{},attrId:{},attr_itemid:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str(), attrId, itemCfg.m_id);
                    return -1;
                }

                int ret = 0;
                ret = m_mapVirtualItemAttr.Insert(itemCfg.m_id, attrId);
                CHECK_EXPR_ASSERT(ret >= 0, -1, "m_mapVirtualItemAttr.Insert Failed! Not Enough Space");
                ret = m_mapAttrVirtualItem.Insert(attrId, itemCfg.m_id);
                CHECK_EXPR_ASSERT(ret >= 0, -1, "m_mapAttrVirtualItem.Insert Failed! Not Enough Space");

            }
            else if ((int32_t) EItemFuncType::EItemFuncType_UseContri == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process113....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_FixAttr == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1 || vecParam.size() % 2 != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[common] ItemCfg::Process114....vecParam.size() < 1 || vecParam.size() % 2 != 0....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                auto mapAttr = m_mapFixAttr.Find(itemCfg.m_id);
                if (mapAttr == NULL)
                {
                    mapAttr = m_mapFixAttr.Insert(itemCfg.m_id);
                    CHECK_EXPR_ASSERT(mapAttr, -1, "m_mapFixAttr.Insert Failed, Not Enough Space");
                }

                for (uint32_t i = 0; i < vecParam.size(); i++)
                {
                    if (i + 1 < vecParam.size())
                    {
                        int ret = mapAttr->Insert(vecParam[i], vecParam[i + 1]);
                        CHECK_EXPR_ASSERT(ret >= 0, -1, "mapAttr Insert Failed, Not Enough Space");
                        i++;
                    }
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_RechargeCard == itemCfg.m_functiontype)
            {
                //
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_ExpStone == itemCfg.m_functiontype)
            {
                //
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_CallLeader == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process117....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
/*                int64_t flashid = vecParam.at(0);
				const FlashItemFlashCfgInfo *pFlashItemCfg = g_GetFlashItemFlashCfgTable()->GetFlashItemFlashCfgInfo(flashid);
				if (nullptr == pFlashItemCfg)
				{
					LogErrFmtPrint("[common] ItemCfg::Process117...nullptr == pFlashItemCfg...itemid:%lu,flashid:%ld", itemCfg.m_id,flashid);
					return false;
				}*/
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_AddSkill == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process118....vecParam.size() < 2....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                int64_t skillid = vecParam.at(0);
                int64_t newSkillid = vecParam.at(1);
                auto pSkillCfg = SkillSkillDesc::Instance(m_pObjPluginManager)->GetDesc(skillid);
                if (nullptr == pSkillCfg)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process118...nullptr == pSkillCfg...itemid:{},skillid:{}", itemCfg.m_id,
                               skillid);
                    return -1;
                }
                auto pSkillCfgA = SkillSkillDesc::Instance(m_pObjPluginManager)->GetDesc(newSkillid);
                if (nullptr == pSkillCfgA)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process118...nullptr == pSkillCfgA...itemid:{},skillid:{}", itemCfg.m_id,
                               newSkillid);
                    return -1;
                }
                if (skillid == newSkillid)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process118...skillid == newSkillid...itemid:{},skillid:{}", itemCfg.m_id,
                               skillid);
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_AddMission == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process119....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                int64_t missionid = vecParam.at(0);//这里的任务ID先存起来，到任务管理器初始化时做校验
                if (missionid <= 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process119...missionid <= 0...itemid:{},missionid:{}", itemCfg.m_id, missionid);
                    return -1;
                }
                int ret = m_mapItemAddMissionCheck.Insert(itemCfg.m_id, missionid);
                CHECK_EXPR_ASSERT(ret >= 0, -1, "m_mapItemAddMissionCheck Insert Failed");
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_AddCardTime == itemCfg.m_functiontype)
            {
                if (vecParam.size() != 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process120....vecParam.size() < 2....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_CallTeleport == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process121....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
                int64_t teleportid = vecParam.at(0);
                if (teleportid <= 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process121...teleportid <= 0...itemid:{},teleportid:{}", itemCfg.m_id,
                               teleportid);
                    return -1;
                }
/*				const TeleportTeleportCfgInfo *pTeleCfg = g_GetTeleportTeleportCfgTable()->GetTeleportTeleportCfgInfo(teleportid);
				if (nullptr == pTeleCfg)
				{
					LogErrFmtPrint("[common] ItemCfg::Process121...nullptr == pTeleCfg...itemid:%lu,teleportid:%ld", itemCfg.m_id, teleportid);
					return false;
				}*/
            }
            else if ((int32_t) EItemFuncType::EItemFuncType_Fushi == itemCfg.m_functiontype)
            {
                if (vecParam.size() < 1)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process122....vecParam.size() < 1....itemid:{}, functype:{}, strParam:{} ",
                               itemCfg.m_id, itemCfg.m_functiontype, strParam.c_str());
                    return -1;
                }
            }
        }
        auto pArrayParam = m_mapItemFunc.Find(itemCfg.m_id);
        if (pArrayParam == NULL)
        {
            pArrayParam = m_mapItemFunc.Insert(itemCfg.m_id);
            CHECK_EXPR_ASSERT(pArrayParam, -1, "m_mapItemFunc.Insert Failed! Not Enough Space");
        }

        int ret = pArrayParam->Add(vecParam);
        CHECK_EXPR_ASSERT(ret >= 0, -1, "ArrayParam->Add Failed! Not Enough Space");
    }

    auto pMapEquip = EquipEquipDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    if (pMapEquip)
    {
        for (int i = 0; i < (int) pMapEquip->size(); i++)
        {
            auto &info = pMapEquip->at(i);
            //
            if (info.m_iscanbind == 1)
            {
                auto pValue = m_setNaturalBind.Insert(info.m_id);
                CHECK_EXPR_ASSERT(pValue, -1, "m_setNaturalBind.Insert, Not Enough Space");
            }

            //
            int64_t star = info.m_star;
            int64_t rank = info.m_wearquality;
            int64_t qua = info.m_quality;
            int64_t pos = info.m_position;

            //职业限制 0通用职业，1战士，2法师，3刺客，4射手
            SET_INT32 setProfLimit;
            setProfLimit.clear();
            string profreq = info.m_profession.ToString();
            NFCommonApi::SplitStrToSetInt(profreq, ",", &setProfLimit);
            SET_INT32::iterator iterProf = setProfLimit.find(0);
            if (iterProf == setProfLimit.end())
            {
                auto pProfMap = m_mapItemProfLimit.Insert(info.m_id);
                CHECK_EXPR_ASSERT(pProfMap, -1, "m_mapItemProfLimit.Insert Failed");
                for (auto iter = setProfLimit.begin(); iter != setProfLimit.end(); ++iter)
                {
                    auto pValue = pProfMap->Insert(*iter);
                    CHECK_EXPR_ASSERT(pValue, -1, "pProfMap->Insert Failed");
                }
                //
                iterProf = setProfLimit.begin();
                for (; iterProf != setProfLimit.end(); ++iterProf)
                {
                    uint64_t decomposeKey = DE_COMPOSE_KEY(star, rank, qua, (*iterProf), pos);
                    auto pDecomposeMap = m_mapDecompose.Find(decomposeKey);
                    if (pDecomposeMap != NULL)
                    {
                        auto pValue = pDecomposeMap->Insert(info.m_id);
                        CHECK_EXPR_ASSERT(pValue, -1, "pDecomposeMap.Insert Failed");
                    }
                    else
                    {
                        pDecomposeMap = m_mapDecompose.Insert(decomposeKey);
                        CHECK_EXPR_ASSERT(pDecomposeMap, -1, "m_mapDecompose.Insert Failed");

                        auto pValue = pDecomposeMap->Insert(info.m_id);
                        CHECK_EXPR_ASSERT(pValue, -1, "pDecomposeMap.Insert Failed");
                    }
                }
            }
            else
            {
                for (int32_t i = proto_ff::ERoleProf_MIN; i <= proto_ff::ERoleProf_MAX; ++i)
                {
                    uint64_t decomposeKey = DE_COMPOSE_KEY(star, rank, qua, i, pos);
                    auto pDecomposeMap = m_mapDecompose.Find(decomposeKey);
                    if (pDecomposeMap != NULL)
                    {
                        auto pValue = pDecomposeMap->Insert(info.m_id);
                        CHECK_EXPR_ASSERT(pValue, -1, "pDecomposeMap.Insert Failed");
                    }
                    else
                    {
                        pDecomposeMap = m_mapDecompose.Insert(decomposeKey);
                        CHECK_EXPR_ASSERT(pDecomposeMap, -1, "m_mapDecompose.Insert Failed");

                        auto pValue = pDecomposeMap->Insert(info.m_id);
                        CHECK_EXPR_ASSERT(pValue, -1, "pDecomposeMap.Insert Failed");
                    }

                }
            }

            //熔炼
            string strsmelt = info.m_meltingresult.ToString();
            if (strsmelt.length() > 0)
            {
                VEC_INT64 vecParam;
                vecParam.clear();
                NFCommonApi::SplitStrToVecInt(strsmelt, ",", &vecParam);
                //
                int32_t isize = (int32_t) vecParam.size();
                if ((isize % 2) != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0,
                               "[common] ItemCfg::Process...equip smelt format error...(isize % 2) != 0...equipid:{},isize:{},str:{}", info.m_id, isize,
                               strsmelt.c_str());
                    return -1;
                }
                VEC_INT64::iterator iterSmelt = vecParam.begin();
                while (iterSmelt != vecParam.end())
                {
                    int64_t itemid = (*iterSmelt);
                    auto pItemCfg = ItemItemDesc::Instance(m_pObjPluginManager)->GetDesc(itemid);
                    if (nullptr == pItemCfg)
                    {
                        auto pEqupCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(itemid);
                        if (nullptr == pEqupCfg)
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0,
                                    "[common] ItemCfg::Process...equip smelt can not find item config...nullptr == pEqupCfg...equipid:{},itemid:{}",
                                    info.m_id, itemid);
                            return -1;
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
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] ItemCfg::Process...equip smelt num <= 0...equipid:{},itemid:{},num:{}", info.m_id,
                                   itemid, num);
                        return -1;
                    }
                    //
                    auto pEquipSmeltMap = m_mapEquipSmelt.Find(info.m_id);
                    if (pEquipSmeltMap != NULL)
                    {
                        auto pValue = pEquipSmeltMap->Find(itemid);
                        if (pValue != NULL)
                        {
                            pValue += num;
                        }
                        else
                        {
                            *pValue = num;
                        }
                    }
                    else
                    {
                        pEquipSmeltMap = m_mapEquipSmelt.Insert(info.m_id);
                        CHECK_EXPR_ASSERT(pEquipSmeltMap, -1, "m_mapEquipSmelt.Insert Failed, Not Enough Space");
                        int ret = pEquipSmeltMap->Insert(itemid, num);
                        CHECK_EXPR_ASSERT(ret >= 0, -1, "pEquipSmeltMap->Insert Failed");
                    }

                    //
                    ++iterSmelt;
                } // end of while (iterSmelt != vecParam.end())
            } // end of if (strsmelt.length() > 0)

        }
    }

    return 0;
}

uint32_t NFItemDescStoreEx::AttrIdByItem(uint64_t itemId)
{
    auto pAttr = m_mapVirtualItemAttr.Find(itemId);
    return (pAttr != NULL) ? *pAttr: 0;
}

uint64_t NFItemDescStoreEx::ItemIdByAttrId(uint32_t attrId)
{
    auto pItemId = m_mapAttrVirtualItem.Find(attrId);
    return (pItemId != NULL) ? *pItemId: 0;
}
