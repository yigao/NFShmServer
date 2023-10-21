// -------------------------------------------------------------------------
//    @FileName         :    NFConvoyPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFConvoyPart
//
// -------------------------------------------------------------------------

#include "NFConvoyPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFConvoyPart, EOT_LOGIC_PART_ID+PART_CONVOY, NFPart)

NFConvoyPart::NFConvoyPart()
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

NFConvoyPart::~NFConvoyPart()
{
}

int NFConvoyPart::CreateInit()
{
    return 0;
}

int NFConvoyPart::ResumeInit()
{
    return 0;
}
