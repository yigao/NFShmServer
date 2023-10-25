#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Waremblem_s.h"

#define MAX_WAREMBLEM_STAR_NUM 256

class WaremblemStarDesc : public NFIDescStore
{
public:
	WaremblemStarDesc();
	virtual ~WaremblemStarDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WaremblemStar_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WaremblemStar_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WaremblemStar_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WaremblemStar_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WaremblemStarDesc, proto_ff_s::E_WaremblemStar_s, E_WaremblemStar, MAX_WAREMBLEM_STAR_NUM);
DECLARE_IDCREATE_GLOBAL(WaremblemStarDesc);
};
