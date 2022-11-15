// -------------------------------------------------------------------------
//    @FileName         :    NFShmEventMgr.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmEventMgr
//
// -------------------------------------------------------------------------

#include "NFShmEventMgr.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFShmSubscribeInfo, EOT_TYPE_EVENT_MGR, NFShmObj)

NFShmEventMgr::NFShmEventMgr(NFIPluginManager* pPluginManager):NFShmObj(pPluginManager)
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

int NFShmEventMgr::CreateInit()
{
    return 0;
}

int NFShmEventMgr::ResumeInit()
{
    return 0;
}
