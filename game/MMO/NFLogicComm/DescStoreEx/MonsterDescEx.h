#pragma once

#include <NFGameCommon/NFComTypeDefine.h>

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class MonsterDescEx : public NFShmObjGlobalTemplate<MonsterDescEx, EOT_CONST_MONSTER_DESC_EX_ID, NFIDescStoreEx>
{
public:
	MonsterDescEx();
	virtual ~MonsterDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
public:
	const VEC_INT64* GetTaskTypeMonster(uint32_t taskType) { return NULL; }
};
