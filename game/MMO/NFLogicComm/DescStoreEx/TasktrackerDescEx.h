#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class TasktrackerDescEx : public NFIDescStoreEx
{
public:
	TasktrackerDescEx();
	virtual ~TasktrackerDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(TasktrackerDescEx)
DECLARE_IDCREATE(TasktrackerDescEx)
};
