#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Collect_s.h"

#define MAX_COLLECT_ATTRIBUTETPYE_NUM 256

class CollectAttributetpyeDesc : public NFIDescStore
{
public:
	CollectAttributetpyeDesc();
	virtual ~CollectAttributetpyeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_CollectAttributetpye_s* GetDesc(int64_t id) const;
	proto_ff_s::E_CollectAttributetpye_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_CollectAttributetpye_s* GetDescByIndex(int index) const;
	proto_ff_s::E_CollectAttributetpye_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(CollectAttributetpyeDesc, proto_ff_s::E_CollectAttributetpye_s, E_CollectAttributetpye, MAX_COLLECT_ATTRIBUTETPYE_NUM);
DECLARE_IDCREATE(CollectAttributetpyeDesc);
};
