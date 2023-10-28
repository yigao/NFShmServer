// -------------------------------------------------------------------------
//    @FileName         :    NFPracticeTrue.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPracticeTrue
//
// -------------------------------------------------------------------------

#include "NFPracticeTrue.h"

NFPracticeTrue::NFPracticeTrue()
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

NFPracticeTrue::~NFPracticeTrue()
{
}

int NFPracticeTrue::CreateInit()
{
    return 0;
}

int NFPracticeTrue::ResumeInit()
{
    return 0;
}
