#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYJXZFATT_NUM 64

class MofaZyjxzfattDesc : public NFIDescStore
{
public:
	MofaZyjxzfattDesc();
	virtual ~MofaZyjxzfattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaZyjxzfatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaZyjxzfatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaZyjxzfatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaZyjxzfatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaZyjxzfattDesc, proto_ff_s::E_MofaZyjxzfatt_s, E_MofaZyjxzfatt, MAX_MOFA_ZYJXZFATT_NUM);
DECLARE_IDCREATE(MofaZyjxzfattDesc);
};
