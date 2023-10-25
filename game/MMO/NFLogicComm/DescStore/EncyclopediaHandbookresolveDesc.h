#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKRESOLVE_NUM 8

class EncyclopediaHandbookresolveDesc : public NFIDescStore
{
public:
	EncyclopediaHandbookresolveDesc();
	virtual ~EncyclopediaHandbookresolveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaHandbookresolve_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaHandbookresolve_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaHandbookresolve_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaHandbookresolve_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaHandbookresolveDesc, proto_ff_s::E_EncyclopediaHandbookresolve_s, E_EncyclopediaHandbookresolve, MAX_ENCYCLOPEDIA_HANDBOOKRESOLVE_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaHandbookresolveDesc);
};
