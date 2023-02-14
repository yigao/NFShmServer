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

        auto pOpenTypeMap = m_mapUnlockCfg.Find(tInfo.openType);
        if (pOpenTypeMap == NULL)
        {
            pOpenTypeMap = m_mapUnlockCfg.Insert(tInfo.openType);
            CHECK_EXPR_ASSERT(pOpenTypeMap, -1, "m_mapUnlockCfg.Insert Failed, Not Enought Space, openType:{}", tInfo.openType);

            auto pOpenValMap = pOpenTypeMap->Insert(tInfo.openVal);
            CHECK_EXPR_ASSERT(pOpenValMap, -1, "pOpenTypeMap Insert Failed, Not Enought Space, openVal:{}", tInfo.openVal);

            auto pFuncValue = pOpenValMap->Insert(tInfo.functionId);
            CHECK_EXPR_ASSERT(pFuncValue, -1, "pOpenValMap Insert Failed, Not Enought Space, openVal:{}", tInfo.functionId);
        }
        else
        {
            auto pOpenValMap = pOpenTypeMap->Find(tInfo.openVal);
            if (pOpenValMap == NULL)
            {
                auto pOpenValMap = pOpenTypeMap->Insert(tInfo.openVal);
                CHECK_EXPR_ASSERT(pOpenValMap, -1, "pOpenTypeMap Insert Failed, Not Enought Space, openVal:{}", tInfo.openVal);

                auto pFuncValue = pOpenValMap->Insert(tInfo.functionId);
                CHECK_EXPR_ASSERT(pFuncValue, -1, "pOpenValMap Insert Failed, Not Enought Space, openVal:{}", tInfo.functionId);
            }
            else
            {
                auto pFuncValue = pOpenValMap->Find(tInfo.functionId);
                if (pFuncValue == NULL)
                {
                    auto pFuncValue = pOpenValMap->Insert(tInfo.functionId);
                    CHECK_EXPR_ASSERT(pFuncValue, -1, "pOpenValMap Insert Failed, Not Enought Space, openVal:{}", tInfo.functionId);
                }
            }
        }
    }

    //
    for (auto itercfg = m_mapUnlockCfg.Begin(); itercfg != m_mapUnlockCfg.End(); itercfg++)
    {
        uint32_t opentype = *(itercfg->first);
        auto mapOpenValue = itercfg->second;
        if (FUNCTION_UNLOCK_TYPE_LEVEL == opentype
            || FUNCTION_UNLOCK_TYPE_TRANSFER == opentype
            || FUNCTION_UNLOCK_TYPE_PAYRMB == opentype
            || FUNCTION_UNLOCK_TYPE_VIP_LEV == opentype
                )
        {
            for (auto iterlv = mapOpenValue->Begin(); iterlv != mapOpenValue->End(); iterlv++)
            {
                uint64_t lev = *(iterlv->first);
                auto setLevFunc = iterlv->second;
                //
                auto mapTmpOpenValue = m_mapUnlockCfg.Find(opentype);
                if (mapTmpOpenValue != NULL)
                {
                    for (auto itertmp_open = mapTmpOpenValue->Begin(); itertmp_open != mapTmpOpenValue->End(); itertmp_open++)
                    {
                        if (*(itertmp_open->first) >= lev)
                        {
                            continue;
                        }
                        auto setTmpFunc = itertmp_open->second;
                        for (auto itertmp_func = setTmpFunc->Begin(); itertmp_func != setTmpFunc->End(); itertmp_func++)
                        {
                            uint64_t functionId = *(itertmp_func->first);
                            auto pFuncValue = setLevFunc->Find(functionId);
                            if (pFuncValue == NULL)
                            {
                                pFuncValue = setLevFunc->Insert(functionId);
                                CHECK_EXPR_ASSERT(pFuncValue, -1, "pOpenValMap Insert Failed, Not Enought Space, openVal:{}", functionId);
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

