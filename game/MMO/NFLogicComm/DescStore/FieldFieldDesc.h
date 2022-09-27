#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/field_s.h"

#define MAX_FIELD_FIELD_NUM 60

class FieldFieldDesc : public NFIDescStore
{
public:
	FieldFieldDesc(NFIPluginManager* pPluginManager);
	virtual ~FieldFieldDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::fieldfield_s* GetDesc(int id) const;
	proto_ff_s::fieldfield_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::fieldfield_s, MAX_FIELD_FIELD_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::fieldfield_s, MAX_FIELD_FIELD_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::fieldfield_s, fieldfield, MAX_FIELD_FIELD_NUM);
DECLARE_IDCREATE(FieldFieldDesc);
};
