#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEAST_NUM 32

class EncyclopediaBeastDesc : public NFIDescStore
{
public:
	EncyclopediaBeastDesc();
	virtual ~EncyclopediaBeastDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaBeast_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaBeast_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaBeast_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaBeast_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaBeastDesc, proto_ff_s::E_EncyclopediaBeast_s, E_EncyclopediaBeast, MAX_ENCYCLOPEDIA_BEAST_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaBeastDesc);
};
