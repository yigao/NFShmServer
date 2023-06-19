// -------------------------------------------------------------------------
//    @FileName         :    NFTestObj.cpp
//    @Author           :    gaoyi
//    @Date             :    23-6-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestObj
//
// -------------------------------------------------------------------------

#include "NFTestObj.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTestObj, EOT_NFTestObj_ID, NFShmObj)

NFTestObj::NFTestObj()
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

NFTestObj::~NFTestObj()
{
}

int NFTestObj::CreateInit()
{
    id = 0;
    return 0;
}

int NFTestObj::ResumeInit()
{
    return 0;
}
