// -------------------------------------------------------------------------
//    @FileName         :    NFPetPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPetPart
//
// -------------------------------------------------------------------------

#include "NFPetPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPetPart, EOT_LOGIC_PART_ID+PART_PET, NFPart)

NFPetPart::NFPetPart()
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

NFPetPart::~NFPetPart()
{
}

int NFPetPart::CreateInit()
{
    return 0;
}

int NFPetPart::ResumeInit()
{
    return 0;
}
