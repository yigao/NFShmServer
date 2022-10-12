#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/warland_s.h"

#define MAX_WARLAND_RANKREWARD_NUM 20

class WarlandRankrewardDesc : public NFIDescStore
{
public:
	WarlandRankrewardDesc(NFIPluginManager* pPluginManager);
	virtual ~WarlandRankrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::warlandrankreward_s* GetDesc(int id) const;
	proto_ff_s::warlandrankreward_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::warlandrankreward_s, MAX_WARLAND_RANKREWARD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::warlandrankreward_s, MAX_WARLAND_RANKREWARD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::warlandrankreward_s, warlandrankreward, MAX_WARLAND_RANKREWARD_NUM);
DECLARE_IDCREATE(WarlandRankrewardDesc);
};
