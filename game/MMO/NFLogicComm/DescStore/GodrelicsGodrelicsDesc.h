#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godRelics_s.h"

#define MAX_GODRELICS_GODRELICS_NUM 20

class GodrelicsGodrelicsDesc : public NFIDescStore
{
public:
	GodrelicsGodrelicsDesc();
	virtual ~GodrelicsGodrelicsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodrelicsGodrelics_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodrelicsGodrelics_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodrelicsGodrelics_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodrelicsGodrelics_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GodrelicsGodrelicsDesc, proto_ff_s::E_GodrelicsGodrelics_s, E_GodrelicsGodrelics, MAX_GODRELICS_GODRELICS_NUM);
DECLARE_IDCREATE(GodrelicsGodrelicsDesc);
};
