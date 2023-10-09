#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_NAME_NUM 8

class DragonsoulNameDesc : public NFIDescStore
{
public:
	DragonsoulNameDesc();
	virtual ~DragonsoulNameDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulName_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulName_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulName_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulName_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulNameDesc, proto_ff_s::E_DragonsoulName_s, E_DragonsoulName, MAX_DRAGONSOUL_NAME_NUM);
DECLARE_IDCREATE(DragonsoulNameDesc);
};
