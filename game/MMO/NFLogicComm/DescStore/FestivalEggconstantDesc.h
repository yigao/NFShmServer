#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_EGGCONSTANT_NUM 20

class FestivalEggconstantDesc : public NFIDescStore
{
public:
	FestivalEggconstantDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalEggconstantDesc();
	const proto_ff_s::festivaleggConstant_s* GetDesc(int id) const;
	proto_ff_s::festivaleggConstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivaleggConstant_s, MAX_FESTIVAL_EGGCONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivaleggConstant_s, MAX_FESTIVAL_EGGCONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivaleggConstant_s, festivaleggConstant, MAX_FESTIVAL_EGGCONSTANT_NUM);
DECLARE_IDCREATE(FestivalEggconstantDesc);
};
