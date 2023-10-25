#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_LOCKSKILL_NUM 8

class MarryLockskillDesc : public NFIDescStore
{
public:
	MarryLockskillDesc();
	virtual ~MarryLockskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryLockskill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryLockskill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryLockskill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryLockskill_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryLockskillDesc, proto_ff_s::E_MarryLockskill_s, E_MarryLockskill, MAX_MARRY_LOCKSKILL_NUM);
DECLARE_IDCREATE_GLOBAL(MarryLockskillDesc);
};
