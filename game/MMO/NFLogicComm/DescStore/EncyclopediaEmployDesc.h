#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_EMPLOY_NUM 128

class EncyclopediaEmployDesc : public NFIDescStore
{
public:
	EncyclopediaEmployDesc();
	virtual ~EncyclopediaEmployDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaEmploy_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaEmploy_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaEmploy_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaEmploy_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaEmployDesc, proto_ff_s::E_EncyclopediaEmploy_s, E_EncyclopediaEmploy, MAX_ENCYCLOPEDIA_EMPLOY_NUM);
DECLARE_IDCREATE(EncyclopediaEmployDesc);
};
