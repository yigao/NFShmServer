#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Washparty_s.h"

#define MAX_WASHPARTY_WASHPARTY_NUM 16

class WashpartyWashpartyDesc : public NFIDescStore
{
public:
	WashpartyWashpartyDesc();
	virtual ~WashpartyWashpartyDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WashpartyWashparty_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WashpartyWashparty_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WashpartyWashparty_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WashpartyWashparty_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WashpartyWashpartyDesc, proto_ff_s::E_WashpartyWashparty_s, E_WashpartyWashparty, MAX_WASHPARTY_WASHPARTY_NUM);
DECLARE_IDCREATE_GLOBAL(WashpartyWashpartyDesc);
};
