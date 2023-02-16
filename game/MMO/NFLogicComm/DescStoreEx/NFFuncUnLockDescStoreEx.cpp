// -------------------------------------------------------------------------
//    @FileName         :    NFFuncUnLockDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFFuncUnLockDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFFuncUnLockDescStoreEx.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "DescStore/FunctionunlockFunctionunlockDesc.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "NFLogicCommon/NFFuncUnLockDefine.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFuncUnLockDescStoreEx, EOT_FUNC_UNLOCK_DESCEX_ID, NFShmObj)

NFFuncUnLockDescStoreEx::NFFuncUnLockDescStoreEx()
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

NFFuncUnLockDescStoreEx::~NFFuncUnLockDescStoreEx()
{
}

int NFFuncUnLockDescStoreEx::CreateInit()
{
    return 0;
}

int NFFuncUnLockDescStoreEx::ResumeInit()
{
    return 0;
}

int NFFuncUnLockDescStoreEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR_ASSERT(FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetFileName());

    Initialize();

    auto mapUnlockCfg = FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_NULL(mapUnlockCfg);

    for (int i = 0; i < (int) mapUnlockCfg->size(); i++)
    {
        auto &tInfo = mapUnlockCfg->at(i);

        auto pOpenTypeMap = m_mapUnlockCfg.Find(tInfo.m_opentype);
        if (pOpenTypeMap == NULL)
        {
            pOpenTypeMap = m_mapUnlockCfg.Insert(tInfo.m_opentype);
            CHECK_EXPR_ASSERT(pOpenTypeMap, -1, "m_mapUnlockCfg.Insert Failed, Not Enought Space, openType:{}", tInfo.m_opentype);

            auto pm_openvalMap = pOpenTypeMap->Insert(tInfo.m_openval);
            CHECK_EXPR_ASSERT(pm_openvalMap, -1, "pOpenTypeMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_openval);

            auto pFuncValue = pm_openvalMap->Insert(tInfo.m_functionid);
            CHECK_EXPR_ASSERT(pFuncValue, -1, "pm_openvalMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_functionid);
        }
        else
        {
            auto pm_openvalMap = pOpenTypeMap->Find(tInfo.m_openval);
            if (pm_openvalMap == NULL)
            {
                auto pm_openvalMap = pOpenTypeMap->Insert(tInfo.m_openval);
                CHECK_EXPR_ASSERT(pm_openvalMap, -1, "pOpenTypeMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_openval);

                auto pFuncValue = pm_openvalMap->Insert(tInfo.m_functionid);
                CHECK_EXPR_ASSERT(pFuncValue, -1, "pm_openvalMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_functionid);
            }
            else
            {
                auto pFuncValue = pm_openvalMap->Find(tInfo.m_functionid);
                if (pFuncValue == NULL)
                {
                    auto pFuncValue = pm_openvalMap->Insert(tInfo.m_functionid);
                    CHECK_EXPR_ASSERT(pFuncValue, -1, "pm_openvalMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_functionid);
                }
            }
        }
    }

    //
    for (auto itercfg = m_mapUnlockCfg.Begin(); itercfg != m_mapUnlockCfg.End(); itercfg++)
    {
        uint32_t opentype = *(itercfg->first);
        auto mapm_openvalue = itercfg->second;
        if (FUNCTION_UNLOCK_TYPE_LEVEL == opentype
            || FUNCTION_UNLOCK_TYPE_TRANSFER == opentype
            || FUNCTION_UNLOCK_TYPE_PAYRMB == opentype
            || FUNCTION_UNLOCK_TYPE_VIP_LEV == opentype
                )
        {
            for (auto iterlv = mapm_openvalue->Begin(); iterlv != mapm_openvalue->End(); iterlv++)
            {
                uint64_t lev = *(iterlv->first);
                auto setLevFunc = iterlv->second;
                //
                auto mapTmpm_openvalue = m_mapUnlockCfg.Find(opentype);
                if (mapTmpm_openvalue != NULL)
                {
                    for (auto itertmp_open = mapTmpm_openvalue->Begin(); itertmp_open != mapTmpm_openvalue->End(); itertmp_open++)
                    {
                        if (*(itertmp_open->first) >= lev)
                        {
                            continue;
                        }
                        auto setTmpFunc = itertmp_open->second;
                        for (auto itertmp_func = setTmpFunc->Begin(); itertmp_func != setTmpFunc->End(); itertmp_func++)
                        {
                            uint64_t m_functionid = *(itertmp_func->first);
                            auto pFuncValue = setLevFunc->Find(m_functionid);
                            if (pFuncValue == NULL)
                            {
                                pFuncValue = setLevFunc->Insert(m_functionid);
                                CHECK_EXPR_ASSERT(pFuncValue, -1, "pm_openvalMap Insert Failed, Not Enought Space, m_openval:{}", m_functionid);
                            }
                        }
                    }
                }
            }
        }
    }


    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFFuncUnLockDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}

//根据解锁类型和解锁值 获取对应的功能列表
NFShmOldHashMap<uint64_t, bool, MAX_FUNC_UNLOCK_OPEN_VAL_FUNC_NUM> *
NFFuncUnLockDescStoreEx::GetUnlockFunctionList(uint32_t nType, uint64_t nValue, bool externFlag/* = false*/)
{
    auto pTypeMap = m_mapUnlockCfg.Find(nType);
    if (pTypeMap == NULL)
    {
        return nullptr;
    }

    auto pValueMap = pTypeMap->Find(nValue);
    if (pValueMap == NULL)
    {
        if (externFlag)
        {
            //等级相关的解锁，如果找不到对应等级解锁的功能ID列表，返回第一个小于对应等级的列表
            if (FUNCTION_UNLOCK_TYPE_LEVEL == nType
                || FUNCTION_UNLOCK_TYPE_TRANSFER == nType
                || FUNCTION_UNLOCK_TYPE_PAYRMB == nType
                || FUNCTION_UNLOCK_TYPE_VIP_LEV == nType
                    )
            {
                //
                for (auto iter = pTypeMap->Begin(); iter != pTypeMap->End(); ++iter)
                {
                    if (*(iter->first) <= nValue)
                    {
                        return iter->second;
                    }
                }
            }
        }


        return nullptr;
    }

    return pValueMap;
}

