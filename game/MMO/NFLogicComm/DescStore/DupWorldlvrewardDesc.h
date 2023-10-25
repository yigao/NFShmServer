#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_WORLDLVREWARD_NUM 32

class DupWorldlvrewardDesc : public NFIDescStore
{
public:
	DupWorldlvrewardDesc();
	virtual ~DupWorldlvrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupWorldlvreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupWorldlvreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupWorldlvreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupWorldlvreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupWorldlvrewardDesc, proto_ff_s::E_DupWorldlvreward_s, E_DupWorldlvreward, MAX_DUP_WORLDLVREWARD_NUM);
DECLARE_IDCREATE_GLOBAL(DupWorldlvrewardDesc);
};
