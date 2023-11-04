#include "FunctionunlockDescEx.h"
#include <vector>

FunctionunlockDescEx::FunctionunlockDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FunctionunlockDescEx::~FunctionunlockDescEx()
{
}

int FunctionunlockDescEx::CreateInit()
{
	return 0;
}

int FunctionunlockDescEx::ResumeInit()
{
	return 0;
}

int FunctionunlockDescEx::Load()
{
    auto mapUnlockCfg = FunctionunlockFunctionunlockDesc::Instance()->GetResDescPtr();
    for (auto iterator = mapUnlockCfg->begin(); iterator != mapUnlockCfg->end(); ++iterator)
    {
        auto& tInfo = iterator->second;
        auto iter = m_mapUnlockCfg.find(tInfo.m_openType);
        if (iter == m_mapUnlockCfg.end())
        {
            SET_UINT64 tvec;
            tvec.insert(tInfo.m_functionId);
            
            ORDER_MAP_UINT64_SET_UINT64 tmap;
            tmap[tInfo.m_openVal] = tvec;
            
            m_mapUnlockCfg[tInfo.m_openType] = tmap;
        }
        else
        {
            ORDER_MAP_UINT64_SET_UINT64& tmap = iter->second;
            auto it =  tmap.find(tInfo.m_openVal);
            if (it == tmap.end())
            {
                SET_UINT64 tvec;
                tvec.insert(tInfo.m_functionId);
                tmap[tInfo.m_openVal] = tvec;
            }
            else
            {
                SET_UINT64& tvec = it->second;
                tvec.insert(tInfo.m_functionId);
            }
        }
    }
    //
    ORDER_MAP_UINT32_ORDER_MAP_UINT64_SET_UINT64 mapUnlockTmp = m_mapUnlockCfg;
    for (auto &itercfg : m_mapUnlockCfg)
    {
        uint32_t opentype = itercfg.first;
        ORDER_MAP_UINT64_SET_UINT64 &mapOpenValue = itercfg.second;
        if (FUNCTION_UNLOCK_TYPE_LEVEL == opentype
            || FUNCTION_UNLOCK_TYPE_TRANSFER == opentype
            || FUNCTION_UNLOCK_TYPE_PAYRMB == opentype
            || FUNCTION_UNLOCK_TYPE_VIP_LEV == opentype
            )
        {
            for (auto &iterlv : mapOpenValue)
            {
                uint64_t lev = iterlv.first;
                SET_UINT64 &setLevFunc = iterlv.second;
                //
                auto itertmp = mapUnlockTmp.find(opentype);
                if (itertmp != mapUnlockTmp.end())
                {
                    ORDER_MAP_UINT64_SET_UINT64 &mapTmpOpenValue = itertmp->second;
                    for (auto itertmp_open : mapTmpOpenValue)
                    {
                        if (itertmp_open.first >= lev)
                        {
                            continue;
                        }
                        SET_UINT64 &setTmpFunc = itertmp_open.second;
                        for (auto itertmp_func : setTmpFunc)
                        {
                            setLevFunc.insert(itertmp_func);
                        }
                    }
                }
            }
        }
    }
	return 0;
}

int FunctionunlockDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

//根据解锁类型和解锁值 获取对应的功能列表
const SET_UINT64* FunctionunlockDescEx::GetUnlockFunctionList(uint32_t nType, uint64_t nValue, bool externFlag/* = false*/)
{
    auto iter = m_mapUnlockCfg.find(nType);
    if (iter == m_mapUnlockCfg.end())
    {
        return nullptr;
    }
    
    ORDER_MAP_UINT64_SET_UINT64& tmap = iter->second;
    auto it =  tmap.find(nValue);
    if (it == tmap.end())
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
                auto iterf = tmap.rbegin();
                for (; iterf != tmap.rend(); ++iterf)
                {
                    if (iterf->first <= nValue)
                    {
                        return &iterf->second;
                    }
                }
            }
            
            
        }
        
        
        return nullptr;
    }
    
    return &(it->second);
}

