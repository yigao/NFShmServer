#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_HOLE_NUM 16

class DragonsoulHoleDesc : public NFIDescStore
{
public:
	DragonsoulHoleDesc();
	virtual ~DragonsoulHoleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulHole_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulHole_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulHole_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulHole_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulHoleDesc, proto_ff_s::E_DragonsoulHole_s, E_DragonsoulHole, MAX_DRAGONSOUL_HOLE_NUM);
DECLARE_IDCREATE_GLOBAL(DragonsoulHoleDesc);
};
