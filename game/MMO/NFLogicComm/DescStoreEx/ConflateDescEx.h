#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class ConflateDescEx : public NFIDescStoreEx
{
public:
	ConflateDescEx();
	virtual ~ConflateDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(ConflateDescEx)
DECLARE_IDCREATE_GLOBAL(ConflateDescEx)
};
