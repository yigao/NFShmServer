#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/field_s.h"

#define MAX_FIELD_VALUE_NUM 140

class FieldValueDesc : public NFIDescStore
{
public:
	FieldValueDesc(NFIPluginManager* pPluginManager);
	virtual ~FieldValueDesc();
	const proto_ff_s::fieldvalue_s* GetDesc(int id) const;
	proto_ff_s::fieldvalue_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::fieldvalue_s, MAX_FIELD_VALUE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::fieldvalue_s, MAX_FIELD_VALUE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::fieldvalue_s, fieldvalue, MAX_FIELD_VALUE_NUM);
DECLARE_IDCREATE(FieldValueDesc);
};
