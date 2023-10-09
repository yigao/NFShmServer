#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_STARCOLLECT_NUM 32

class DragonsoulStarcollectDesc : public NFIDescStore
{
public:
	DragonsoulStarcollectDesc();
	virtual ~DragonsoulStarcollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulStarcollect_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulStarcollect_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulStarcollect_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulStarcollect_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulStarcollectDesc, proto_ff_s::E_DragonsoulStarcollect_s, E_DragonsoulStarcollect, MAX_DRAGONSOUL_STARCOLLECT_NUM);
DECLARE_IDCREATE(DragonsoulStarcollectDesc);
};
