// -------------------------------------------------------------------------
//    @FileName         :    NFPath.h
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFPath
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "NFComm/NFShmStl/NFShmVector.h"

#define MAX_PATH_POINT_COUNT 50

class NFPath
{
public:
    NFPath();

    virtual ~NFPath();

    int CreateInit();

    int ResumeInit();

public:
    bool Init(VEC_POINT3 &path, NFPoint3<float> &curPos);

    bool GetLeftPath(VEC_POINT3 &leftPath);

    void UnInit();

    void Clear();

    bool MapPathDistanceToPoint(float setpDistance, NFPoint3<float> &retPos);

public:
    NFShmVector<NFPoint3<float>, MAX_PATH_POINT_COUNT> m_path;                        //路径
    uint32_t m_nextIndex;                   //下一步的路径点下标
};