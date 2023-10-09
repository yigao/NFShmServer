// -------------------------------------------------------------------------
//    @FileName         :    NFNavMeshInfo.h
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFNavMeshInfo
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Detour/Include/DetourNavMesh.h"
#include "Detour/Include/DetourNavMeshQuery.h"

class NFNavMeshInfo
{
public:
    NFNavMeshInfo();

    virtual ~NFNavMeshInfo();

    int CreateInit();

    int ResumeInit();

public:
    dtNavMesh* pdtNavMesh;
    dtNavMeshQuery* pdtNavMeshQuery;
};