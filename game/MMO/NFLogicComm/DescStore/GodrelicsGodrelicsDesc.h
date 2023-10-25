#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godrelics_s.h"

#define MAX_GODRELICS_GODRELICS_NUM 16

class GodrelicsGodrelicsDesc : public NFIDescStore
{
public:
	GodrelicsGodrelicsDesc();
	virtual ~GodrelicsGodrelicsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodrelicsGodrelics_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodrelicsGodrelics_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodrelicsGodrelics_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodrelicsGodrelics_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodrelicsGodrelicsDesc, proto_ff_s::E_GodrelicsGodrelics_s, E_GodrelicsGodrelics, MAX_GODRELICS_GODRELICS_NUM);
DECLARE_IDCREATE_GLOBAL(GodrelicsGodrelicsDesc);
};
