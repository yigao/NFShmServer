#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/collect_s.h"

#define MAX_COLLECT_ATTRIBUTETPYE_NUM 200

class CollectAttributetpyeDesc : public NFIDescStore
{
public:
	CollectAttributetpyeDesc();
	virtual ~CollectAttributetpyeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_CollectAttributetpye_s* GetDesc(int id) const;
	proto_ff_s::E_CollectAttributetpye_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_CollectAttributetpye_s, E_CollectAttributetpye, MAX_COLLECT_ATTRIBUTETPYE_NUM);
DECLARE_IDCREATE(CollectAttributetpyeDesc);
};
