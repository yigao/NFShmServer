// -------------------------------------------------------------------------
//    @FileName         :    NFGVBPDataPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGVBPDataPart
//
// -------------------------------------------------------------------------

#include "NFGVBPDataPart.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGVBPDataPart, EOT_LOGIC_PART_ID+PART_GVBPData, NFPart)

NFGVBPDataPart::NFGVBPDataPart()
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

NFGVBPDataPart::~NFGVBPDataPart()
{
}

int NFGVBPDataPart::CreateInit()
{
    return 0;
}

int NFGVBPDataPart::ResumeInit()
{
    return 0;
}
