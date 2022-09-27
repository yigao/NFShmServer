#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/gm5Help_s.h"

#define MAX_GM5HELP_CONS_NUM 20

class Gm5helpConsDesc : public NFIDescStore
{
public:
	Gm5helpConsDesc(NFIPluginManager* pPluginManager);
	virtual ~Gm5helpConsDesc();
	const proto_ff_s::gm5Helpcons_s* GetDesc(int id) const;
	proto_ff_s::gm5Helpcons_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::gm5Helpcons_s, MAX_GM5HELP_CONS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::gm5Helpcons_s, MAX_GM5HELP_CONS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::gm5Helpcons_s, gm5Helpcons, MAX_GM5HELP_CONS_NUM);
DECLARE_IDCREATE(Gm5helpConsDesc);
};
