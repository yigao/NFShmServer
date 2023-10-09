#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_LVATT_NUM 128

class MofaLvattDesc : public NFIDescStore
{
public:
	MofaLvattDesc();
	virtual ~MofaLvattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaLvatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaLvatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaLvatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaLvatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaLvattDesc, proto_ff_s::E_MofaLvatt_s, E_MofaLvatt, MAX_MOFA_LVATT_NUM);
DECLARE_IDCREATE(MofaLvattDesc);
};
