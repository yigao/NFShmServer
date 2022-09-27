#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/star_s.h"

#define MAX_STAR_EXP_NUM 2000

class StarExpDesc : public NFIDescStore
{
public:
	StarExpDesc(NFIPluginManager* pPluginManager);
	virtual ~StarExpDesc();
	const proto_ff_s::starexp_s* GetDesc(int id) const;
	proto_ff_s::starexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::starexp_s, MAX_STAR_EXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::starexp_s, MAX_STAR_EXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::starexp_s, starexp, MAX_STAR_EXP_NUM);
DECLARE_IDCREATE(StarExpDesc);
};
