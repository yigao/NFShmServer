#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godpower_s.h"

#define MAX_GODPOWER_GODPOWER_NUM 20

class GodpowerGodpowerDesc : public NFIDescStore
{
public:
	GodpowerGodpowerDesc(NFIPluginManager* pPluginManager);
	virtual ~GodpowerGodpowerDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::godpowergodpower_s* GetDesc(int id) const;
	proto_ff_s::godpowergodpower_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::godpowergodpower_s, MAX_GODPOWER_GODPOWER_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::godpowergodpower_s, MAX_GODPOWER_GODPOWER_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::godpowergodpower_s, godpowergodpower, MAX_GODPOWER_GODPOWER_NUM);
DECLARE_IDCREATE(GodpowerGodpowerDesc);
};
