// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesc.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameDesc
//
// -------------------------------------------------------------------------

#include "NFGameDesk.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameDesk, EOT_NFGameDesc_ID, NFShmObj)

NFGameDesk::NFGameDesk()
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

NFGameDesk::~NFGameDesk()
{
}

int NFGameDesk::CreateInit()
{
    return 0;
}

int NFGameDesk::ResumeInit()
{
    return 0;
}
