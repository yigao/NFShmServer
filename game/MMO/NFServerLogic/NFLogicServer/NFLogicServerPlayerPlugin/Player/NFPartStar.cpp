// -------------------------------------------------------------------------
//    @FileName         :    NFPartStar.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPartStar
//
// -------------------------------------------------------------------------

#include "NFPartStar.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPartStar, EOT_NFPartStar_ID, NFPart
)

NFPartStar::NFPartStar()
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

NFPartStar::~NFPartStar()
{
}

int NFPartStar::CreateInit()
{
    return 0;
}

int NFPartStar::ResumeInit()
{
    return 0;
}
