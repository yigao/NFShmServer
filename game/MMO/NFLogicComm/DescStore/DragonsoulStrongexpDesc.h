#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_STRONGEXP_NUM 2048

class DragonsoulStrongexpDesc : public NFIDescStore
{
public:
	DragonsoulStrongexpDesc();
	virtual ~DragonsoulStrongexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulStrongexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulStrongexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulStrongexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulStrongexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulStrongexpDesc, proto_ff_s::E_DragonsoulStrongexp_s, E_DragonsoulStrongexp, MAX_DRAGONSOUL_STRONGEXP_NUM);
DECLARE_IDCREATE(DragonsoulStrongexpDesc);
};
