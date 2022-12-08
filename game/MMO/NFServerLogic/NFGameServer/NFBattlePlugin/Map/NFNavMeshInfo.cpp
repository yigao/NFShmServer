// -------------------------------------------------------------------------
//    @FileName         :    NFNavMeshInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFNavMeshInfo
//
// -------------------------------------------------------------------------

#include "NFNavMeshInfo.h"

NFNavMeshInfo::NFNavMeshInfo()
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

NFNavMeshInfo::~NFNavMeshInfo()
{
}

int NFNavMeshInfo::CreateInit()
{
    pdtNavMesh = NULL;
    pdtNavMeshQuery = NULL;
    return 0;
}

int NFNavMeshInfo::ResumeInit()
{
    pdtNavMesh = NULL;
    pdtNavMeshQuery = NULL;
    return 0;
}
