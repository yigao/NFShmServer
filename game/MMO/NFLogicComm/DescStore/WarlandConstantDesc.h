#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/warland_s.h"

#define MAX_WARLAND_CONSTANT_NUM 20

class WarlandConstantDesc : public NFIDescStore
{
public:
	WarlandConstantDesc(NFIPluginManager* pPluginManager);
	virtual ~WarlandConstantDesc();
	const proto_ff_s::warlandconstant_s* GetDesc(int id) const;
	proto_ff_s::warlandconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::warlandconstant_s, MAX_WARLAND_CONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::warlandconstant_s, MAX_WARLAND_CONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::warlandconstant_s, warlandconstant, MAX_WARLAND_CONSTANT_NUM);
DECLARE_IDCREATE(WarlandConstantDesc);
};
