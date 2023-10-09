#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class XiuzhenworldDescEx : public NFIDescStoreEx
{
public:
	XiuzhenworldDescEx();
	virtual ~XiuzhenworldDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(XiuzhenworldDescEx)
DECLARE_IDCREATE(XiuzhenworldDescEx)
};
