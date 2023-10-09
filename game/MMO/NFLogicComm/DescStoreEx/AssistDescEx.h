#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class AssistDescEx : public NFIDescStoreEx
{
public:
	AssistDescEx();
	virtual ~AssistDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(AssistDescEx)
DECLARE_IDCREATE(AssistDescEx)
};
