#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Waremblem_s.h"

#define MAX_WAREMBLEM_WAREMBLEM_NUM 64

class WaremblemWaremblemDesc : public NFIDescStore
{
public:
	WaremblemWaremblemDesc();
	virtual ~WaremblemWaremblemDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WaremblemWaremblem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WaremblemWaremblem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WaremblemWaremblem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WaremblemWaremblem_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WaremblemWaremblemDesc, proto_ff_s::E_WaremblemWaremblem_s, E_WaremblemWaremblem, MAX_WAREMBLEM_WAREMBLEM_NUM);
DECLARE_IDCREATE_GLOBAL(WaremblemWaremblemDesc);
};
