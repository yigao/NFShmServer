#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godGM_s.h"

#define MAX_GODGM_GODGM_NUM 20

class GodgmGodgmDesc : public NFIDescStore
{
public:
	GodgmGodgmDesc(NFIPluginManager* pPluginManager);
	virtual ~GodgmGodgmDesc();
	const proto_ff_s::godGMgodGM_s* GetDesc(int id) const;
	proto_ff_s::godGMgodGM_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::godGMgodGM_s, MAX_GODGM_GODGM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::godGMgodGM_s, MAX_GODGM_GODGM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::godGMgodGM_s, godGMgodGM, MAX_GODGM_GODGM_NUM);
DECLARE_IDCREATE(GodgmGodgmDesc);
};
