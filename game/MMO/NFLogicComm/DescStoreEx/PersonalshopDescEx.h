#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class PersonalshopDescEx : public NFIDescStoreEx
{
public:
	PersonalshopDescEx();
	virtual ~PersonalshopDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(PersonalshopDescEx)
DECLARE_IDCREATE(PersonalshopDescEx)
};
