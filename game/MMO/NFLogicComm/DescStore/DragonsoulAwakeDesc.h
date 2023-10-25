#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_AWAKE_NUM 16

class DragonsoulAwakeDesc : public NFIDescStore
{
public:
	DragonsoulAwakeDesc();
	virtual ~DragonsoulAwakeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulAwake_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulAwake_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulAwake_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulAwake_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulAwakeDesc, proto_ff_s::E_DragonsoulAwake_s, E_DragonsoulAwake, MAX_DRAGONSOUL_AWAKE_NUM);
DECLARE_IDCREATE_GLOBAL(DragonsoulAwakeDesc);
};
