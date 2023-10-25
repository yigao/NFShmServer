#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_COMPOSE_NUM 128

class ShentiComposeDesc : public NFIDescStore
{
public:
	ShentiComposeDesc();
	virtual ~ShentiComposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiCompose_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiCompose_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiCompose_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiCompose_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiComposeDesc, proto_ff_s::E_ShentiCompose_s, E_ShentiCompose, MAX_SHENTI_COMPOSE_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiComposeDesc);
};
