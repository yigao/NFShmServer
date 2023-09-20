// -------------------------------------------------------------------------
//    @FileName         :    NFFishDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFFishDescStoreEx.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishDescStoreEx, EOT_NFFishDescStoreEx_ID, NFShmObj)

NFFishDescStoreEx::NFFishDescStoreEx()
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

NFFishDescStoreEx::~NFFishDescStoreEx()
{
}

int NFFishDescStoreEx::CreateInit()
{
    return 0;
}

int NFFishDescStoreEx::ResumeInit()
{
    return 0;
}

int NFFishDescStoreEx::Load()
{
    return 0;
}

int NFFishDescStoreEx::PrepareReload()
{
    return 0;
}

int NFFishDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}
