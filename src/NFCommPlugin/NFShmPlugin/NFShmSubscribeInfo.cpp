// -------------------------------------------------------------------------
//    @FileName         :    NFShmSubcribeInfo.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmSubcribeInfo.h
//
// -------------------------------------------------------------------------

#include "NFShmSubscribeInfo.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFShmSubscribeInfo, EOT_TYPE_SUBSCRIBEINFO_OBJ, NFShmObj)

NFShmSubscribeInfo::NFShmSubscribeInfo(NFIPluginManager* pPluginManager): NFShmObj(pPluginManager)
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

int NFShmSubscribeInfo::CreateInit()
{
    pSink = NULL;
    nRefCount = 0;
    bRemoveFlag = false;
    return 0;
}

int NFShmSubscribeInfo::ResumeInit()
{
    return 0;
}

/**
*@brief 增加引用
*/
void NFShmSubscribeInfo::Add()
{
    nRefCount++;
}

/**
*@brief 减少引用
*/
void NFShmSubscribeInfo::Sub()
{
    --nRefCount;
}