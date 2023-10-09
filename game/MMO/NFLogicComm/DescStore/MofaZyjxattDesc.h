#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYJXATT_NUM 64

class MofaZyjxattDesc : public NFIDescStore
{
public:
	MofaZyjxattDesc();
	virtual ~MofaZyjxattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaZyjxatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaZyjxatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaZyjxatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaZyjxatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaZyjxattDesc, proto_ff_s::E_MofaZyjxatt_s, E_MofaZyjxatt, MAX_MOFA_ZYJXATT_NUM);
DECLARE_IDCREATE(MofaZyjxattDesc);
};
