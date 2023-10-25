#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Washparty_s.h"

#define MAX_WASHPARTY_EXP_NUM 512

class WashpartyExpDesc : public NFIDescStore
{
public:
	WashpartyExpDesc();
	virtual ~WashpartyExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WashpartyExp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WashpartyExp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WashpartyExp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WashpartyExp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WashpartyExpDesc, proto_ff_s::E_WashpartyExp_s, E_WashpartyExp, MAX_WASHPARTY_EXP_NUM);
DECLARE_IDCREATE_GLOBAL(WashpartyExpDesc);
};
