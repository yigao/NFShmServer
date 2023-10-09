#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STRENGTITEL_NUM 64

class ShentiStrengtitelDesc : public NFIDescStore
{
public:
	ShentiStrengtitelDesc();
	virtual ~ShentiStrengtitelDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiStrengtitel_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiStrengtitel_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiStrengtitel_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiStrengtitel_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiStrengtitelDesc, proto_ff_s::E_ShentiStrengtitel_s, E_ShentiStrengtitel, MAX_SHENTI_STRENGTITEL_NUM);
DECLARE_IDCREATE(ShentiStrengtitelDesc);
};
