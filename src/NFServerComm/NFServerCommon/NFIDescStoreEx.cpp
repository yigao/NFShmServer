// -------------------------------------------------------------------------
//    @FileName         :    NFIDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFIDescStoreEx.h"

NFIDescStoreEx::NFIDescStoreEx()
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

NFIDescStoreEx::~NFIDescStoreEx()
{
}

int NFIDescStoreEx::CreateInit()
{
    m_bValid = false;
    m_bIsLoaded = false;
    m_bIsChecked = false;
    return 0;
}

int NFIDescStoreEx::ResumeInit()
{
    return 0;
}

int NFIDescStoreEx::Load()
{
    return 0;
}

int NFIDescStoreEx::Reload()
{
    PrepareReload();
    int iRetCode = Load();
    return iRetCode;
}

int NFIDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}
