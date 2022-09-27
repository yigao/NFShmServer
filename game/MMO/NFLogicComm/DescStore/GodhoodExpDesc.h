#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godHood_s.h"

#define MAX_GODHOOD_EXP_NUM 300

class GodhoodExpDesc : public NFIDescStore
{
public:
	GodhoodExpDesc(NFIPluginManager* pPluginManager);
	virtual ~GodhoodExpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::godHoodexp_s* GetDesc(int id) const;
	proto_ff_s::godHoodexp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::godHoodexp_s, MAX_GODHOOD_EXP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::godHoodexp_s, MAX_GODHOOD_EXP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::godHoodexp_s, godHoodexp, MAX_GODHOOD_EXP_NUM);
DECLARE_IDCREATE(GodhoodExpDesc);
};
