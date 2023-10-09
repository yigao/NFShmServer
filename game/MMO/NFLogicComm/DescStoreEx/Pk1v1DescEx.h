#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class Pk1v1DescEx : public NFIDescStoreEx
{
public:
	Pk1v1DescEx();
	virtual ~Pk1v1DescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(Pk1v1DescEx)
DECLARE_IDCREATE(Pk1v1DescEx)
};
