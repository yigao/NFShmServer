#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/randomname_s.h"

#define MAX_RANDOMNAME_WOMANSECOND_NUM 40

class RandomnameWomansecondDesc : public NFIDescStore
{
public:
	RandomnameWomansecondDesc(NFIPluginManager* pPluginManager);
	virtual ~RandomnameWomansecondDesc();
	const proto_ff_s::randomnamewomansecond_s* GetDesc(int id) const;
	proto_ff_s::randomnamewomansecond_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::randomnamewomansecond_s, MAX_RANDOMNAME_WOMANSECOND_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::randomnamewomansecond_s, MAX_RANDOMNAME_WOMANSECOND_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::randomnamewomansecond_s, randomnamewomansecond, MAX_RANDOMNAME_WOMANSECOND_NUM);
DECLARE_IDCREATE(RandomnameWomansecondDesc);
};
