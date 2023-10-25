#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class Pk3v3DescEx : public NFIDescStoreEx
{
public:
	Pk3v3DescEx();
	virtual ~Pk3v3DescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(Pk3v3DescEx)
DECLARE_IDCREATE_GLOBAL(Pk3v3DescEx)
};
