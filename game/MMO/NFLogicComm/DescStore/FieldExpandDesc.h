#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/field_s.h"

#define MAX_FIELD_EXPAND_NUM 60

class FieldExpandDesc : public NFIDescStore
{
public:
	FieldExpandDesc(NFIPluginManager* pPluginManager);
	virtual ~FieldExpandDesc();
	const proto_ff_s::fieldexpand_s* GetDesc(int id) const;
	proto_ff_s::fieldexpand_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::fieldexpand_s, MAX_FIELD_EXPAND_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::fieldexpand_s, MAX_FIELD_EXPAND_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::fieldexpand_s, fieldexpand, MAX_FIELD_EXPAND_NUM);
DECLARE_IDCREATE(FieldExpandDesc);
};
