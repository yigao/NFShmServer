#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEASTEXP_NUM 256

class EncyclopediaBeastexpDesc : public NFIDescStore
{
public:
	EncyclopediaBeastexpDesc();
	virtual ~EncyclopediaBeastexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaBeastexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaBeastexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaBeastexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaBeastexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaBeastexpDesc, proto_ff_s::E_EncyclopediaBeastexp_s, E_EncyclopediaBeastexp, MAX_ENCYCLOPEDIA_BEASTEXP_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaBeastexpDesc);
};
