#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYATT_NUM 32

class MofaZyattDesc : public NFIDescStore
{
public:
	MofaZyattDesc();
	virtual ~MofaZyattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaZyatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaZyatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaZyatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaZyatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaZyattDesc, proto_ff_s::E_MofaZyatt_s, E_MofaZyatt, MAX_MOFA_ZYATT_NUM);
DECLARE_IDCREATE_GLOBAL(MofaZyattDesc);
};
