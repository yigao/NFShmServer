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

bool NFFuncUnLockDescStoreEx::IsNeedReload()
{
    CHECK_DESC_RELOADING(FunctionunlockFunctionunlockDesc);
    return false;
}

int NFFuncUnLockDescStoreEx::PrepareReload()
{
    m_mapUnlockCfg.clear();
    return 0;
}

int NFFuncUnLockDescStoreEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR_ASSERT(FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetFileName());

    auto mapUnlockCfg = FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_NULL(mapUnlockCfg);

    for (int i = 0; i < (int) mapUnlockCfg->size(); i++)
    {
        auto &tInfo = mapUnlockCfg->at(i);

        auto iter = m_mapUnlockCfg.find(tInfo.m_opentype);
        if (iter == m_mapUnlockCfg.end())
        {
            CHECK_EXPR_ASSERT(m_mapUnlockCfg.size() < m_mapUnlockCfg.max_size(), -1, "m_mapUnlockCfg.Insert Failed, Not Enought Space, openType:{}", tInfo.m_opentype);

            auto& openTypeMap = m_mapUnlockCfg[tInfo.m_opentype];

            CHECK_EXPR_ASSERT(openTypeMap.size() < openTypeMap.max_size(), -1, "openTypeMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_openval);
            auto &openvalSet = openTypeMap[tInfo.m_openval];

            CHECK_EXPR_ASSERT(openvalSet.size() < openvalSet.max_size(), -1, "openvalSet Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_functionid);
            openvalSet.insert(tInfo.m_functionid);
        }
        else
        {
            auto& openTypeMap = m_mapUnlockCfg[tInfo.m_opentype];
            auto openval_iter = openTypeMap.find(tInfo.m_openval);
            if (openval_iter == openTypeMap.end())
            {
                CHECK_EXPR_ASSERT(openTypeMap.size() < openTypeMap.max_size(), -1, "openTypeMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_openval);
                auto& openvalSet = openTypeMap[tInfo.m_openval];

                CHECK_EXPR_ASSERT(openvalSet.size() < openvalSet.max_size(), -1, "openvalSet Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_functionid);
                openvalSet.insert(tInfo.m_functionid);
            }
            else
            {
                auto& openvalMap = openTypeMap[tInfo.m_openval];

                CHECK_EXPR_ASSERT(openvalMap.size() < openvalMap.max_size(), -1, "openvalMap Insert Failed, Not Enought Space, m_openval:{}", tInfo.m_functionid);
                openvalMap.insert(tInfo.m_functionid);
            }
        }
    }

    for (auto itercfg = m_mapUnlockCfg.begin(); itercfg != m_mapUnlockCfg.end(); itercfg++)
    {
        uint32_t opentype = itercfg->first;
        auto& openTypeMap= itercfg->second;
        if (FUNCTION_UNLOCK_TYPE_LEVEL == opentype
            || FUNCTION_UNLOCK_TYPE_TRANSFER == opentype
            || FUNCTION_UNLOCK_TYPE_PAYRMB == opentype
            || FUNCTION_UNLOCK_TYPE_VIP_LEV == opentype
                )
        {
            for (auto iterlv = openTypeMap.begin(); iterlv != openTypeMap.end(); iterlv++)
            {
                uint64_t lev = iterlv->first;
                auto& setLevFunc = iterlv->second;
                //
                auto mapTmpm_openvalue = &m_mapUnlockCfg[opentype];
                if (mapTmpm_openvalue != NULL)
                {
                    for (auto itertmp_open = mapTmpm_openvalue->begin(); itertmp_open != mapTmpm_openvalue->end(); itertmp_open++)
                    {
                        if (itertmp_open->first >= lev)
                        {
                            continue;
                        }

                        auto& setTmpFunc = itertmp_open->second;
                        for (auto itertmp_func = setTmpFunc.begin(); itertmp_func != setTmpFunc.end(); itertmp_func++)
                        {
                            uint64_t m_functionid = *itertmp_func;
                            auto pFuncValue = setLevFunc.find(m_functionid);
                            if (pFuncValue == setLevFunc.end())
                            {
                                CHECK_EXPR_ASSERT(setLevFunc.size() < setLevFunc.max_size(), -1, "setLevFunc Insert Failed, Not Enought Space, "
                                                                                                 "m_openval:{}", m_functionid);
                                setLevFunc.insert(m_functionid);
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
NFShmHashSet<uint64_t,  MAX_FUNC_UNLOCK_OPEN_VAL_FUNC_NUM> *
NFFuncUnLockDescStoreEx::GetUnlockFunctionList(uint32_t nType, uint64_t nValue, bool externFlag/* = false*/)
{
    auto type_iter = m_mapUnlockCfg.find(nType);
    if (type_iter == m_mapUnlockCfg.end())
    {
        return nullptr;
    }

    auto pTypeMap = &type_iter->second;
    auto value_iter = pTypeMap->find(nValue);
    if (value_iter == pTypeMap->end())
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
                for (auto iter = pTypeMap->begin(); iter != pTypeMap->end(); ++iter)
                {
                    if (iter->first <= nValue)
                    {
                        return &iter->second;
                    }
                }
            }
        }


        return nullptr;
    }

    return &value_iter->second;
}

