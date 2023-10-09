#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_PROP_NUM 512

class ConflatePropDesc : public NFIDescStore
{
public:
	ConflatePropDesc();
	virtual ~ConflatePropDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateProp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateProp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateProp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateProp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflatePropDesc, proto_ff_s::E_ConflateProp_s, E_ConflateProp, MAX_CONFLATE_PROP_NUM);
DECLARE_IDCREATE(ConflatePropDesc);
};
