#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_TABLE_NUM 16

class EncyclopediaTableDesc : public NFIDescStore
{
public:
	EncyclopediaTableDesc();
	virtual ~EncyclopediaTableDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaTable_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaTable_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaTable_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaTable_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaTableDesc, proto_ff_s::E_EncyclopediaTable_s, E_EncyclopediaTable, MAX_ENCYCLOPEDIA_TABLE_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaTableDesc);
};
