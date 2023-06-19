// -------------------------------------------------------------------------
//    @FileName         :    NFTestObj.h
//    @Author           :    gaoyi
//    @Date             :    23-6-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestObj
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFTestObj : public NFShmObj
{
public:
    NFTestObj();

    virtual ~NFTestObj();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFTestObj)
public:
    int id;
};