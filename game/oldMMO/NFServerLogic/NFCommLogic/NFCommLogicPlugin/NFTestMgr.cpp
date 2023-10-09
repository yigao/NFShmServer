// -------------------------------------------------------------------------
//    @FileName         :    NFTestMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestMgr
//
// -------------------------------------------------------------------------

#include "NFTestMgr.h"
#include "NFComm/NFCore/NFCommon.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTestMgr, EOT_NFTestMgr_ID, NFShmObj)

NFTestMgr::NFTestMgr()
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

NFTestMgr::~NFTestMgr()
{
}

int NFTestMgr::CreateInit()
{
    return 0;
}

int NFTestMgr::ResumeInit()
{
    return 0;
}

int NFTestMgr::OnTimer(int timeId, int callcount)
{
    return 0;
}
