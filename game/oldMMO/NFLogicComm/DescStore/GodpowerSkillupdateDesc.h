#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godpower_s.h"

#define MAX_GODPOWER_SKILLUPDATE_NUM 300

class GodpowerSkillupdateDesc : public NFIDescStore
{
public:
	GodpowerSkillupdateDesc(NFIPluginManager* pPluginManager);
	virtual ~GodpowerSkillupdateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::godpowerskillupdate_s* GetDesc(int id) const;
	proto_ff_s::godpowerskillupdate_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::godpowerskillupdate_s, MAX_GODPOWER_SKILLUPDATE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::godpowerskillupdate_s, MAX_GODPOWER_SKILLUPDATE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::godpowerskillupdate_s, godpowerskillupdate, MAX_GODPOWER_SKILLUPDATE_NUM);
DECLARE_IDCREATE(GodpowerSkillupdateDesc);
};
