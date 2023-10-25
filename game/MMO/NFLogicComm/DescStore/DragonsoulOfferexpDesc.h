#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_OFFEREXP_NUM 4

class DragonsoulOfferexpDesc : public NFIDescStore
{
public:
	DragonsoulOfferexpDesc();
	virtual ~DragonsoulOfferexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonsoulOfferexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonsoulOfferexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonsoulOfferexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonsoulOfferexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonsoulOfferexpDesc, proto_ff_s::E_DragonsoulOfferexp_s, E_DragonsoulOfferexp, MAX_DRAGONSOUL_OFFEREXP_NUM);
DECLARE_IDCREATE_GLOBAL(DragonsoulOfferexpDesc);
};
