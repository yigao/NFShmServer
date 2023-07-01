// -------------------------------------------------------------------------
//    @FileName         :    NFTestMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-2-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFTestMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFComm/NFShmStl/NFShmList.h"

class NFTestMgr : public NFShmObj
{
public:
    NFTestMgr();

    virtual ~NFTestMgr();

    int CreateInit();

    int ResumeInit();

    virtual int OnTimer(int timeId, int callcount);
private:
DECLARE_IDCREATE(NFTestMgr)
};