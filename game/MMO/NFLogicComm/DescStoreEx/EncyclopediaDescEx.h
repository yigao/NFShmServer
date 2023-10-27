#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class EncyclopediaDescEx : public NFShmObjGlobalTemplate<EncyclopediaDescEx, EOT_CONST_ENCYCLOPEDIA_DESC_EX_ID, NFIDescStoreEx>
{
public:
	EncyclopediaDescEx();
	virtual ~EncyclopediaDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
};
