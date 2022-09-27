#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/warland_s.h"

#define MAX_WARLAND_MULTIKILL_NUM 20

class WarlandMultikillDesc : public NFIDescStore
{
public:
	WarlandMultikillDesc(NFIPluginManager* pPluginManager);
	virtual ~WarlandMultikillDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::warlandmultiKill_s* GetDesc(int id) const;
	proto_ff_s::warlandmultiKill_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::warlandmultiKill_s, MAX_WARLAND_MULTIKILL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::warlandmultiKill_s, MAX_WARLAND_MULTIKILL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::warlandmultiKill_s, warlandmultiKill, MAX_WARLAND_MULTIKILL_NUM);
DECLARE_IDCREATE(WarlandMultikillDesc);
};
