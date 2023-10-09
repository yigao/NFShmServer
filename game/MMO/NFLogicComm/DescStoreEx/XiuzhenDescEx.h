#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class XiuzhenDescEx : public NFIDescStoreEx
{
public:
	XiuzhenDescEx();
	virtual ~XiuzhenDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(XiuzhenDescEx)
DECLARE_IDCREATE(XiuzhenDescEx)
};
