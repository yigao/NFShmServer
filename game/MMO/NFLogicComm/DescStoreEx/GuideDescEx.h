#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class GuideDescEx : public NFShmObjGlobalTemplate<GuideDescEx, EOT_CONST_GUIDE_DESC_EX_ID, NFIDescStoreEx>
{
public:
	GuideDescEx();
	virtual ~GuideDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
};
