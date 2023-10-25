#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKFATE_NUM 128

class EncyclopediaHandbookfateDesc : public NFIDescStore
{
public:
	EncyclopediaHandbookfateDesc();
	virtual ~EncyclopediaHandbookfateDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaHandbookfate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaHandbookfate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaHandbookfate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaHandbookfate_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaHandbookfateDesc, proto_ff_s::E_EncyclopediaHandbookfate_s, E_EncyclopediaHandbookfate, MAX_ENCYCLOPEDIA_HANDBOOKFATE_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaHandbookfateDesc);
};
