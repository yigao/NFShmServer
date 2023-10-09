#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOK_NUM 512

class EncyclopediaHandbookDesc : public NFIDescStore
{
public:
	EncyclopediaHandbookDesc();
	virtual ~EncyclopediaHandbookDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaHandbook_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaHandbook_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaHandbook_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaHandbook_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaHandbookDesc, proto_ff_s::E_EncyclopediaHandbook_s, E_EncyclopediaHandbook, MAX_ENCYCLOPEDIA_HANDBOOK_NUM);
DECLARE_IDCREATE(EncyclopediaHandbookDesc);
};
