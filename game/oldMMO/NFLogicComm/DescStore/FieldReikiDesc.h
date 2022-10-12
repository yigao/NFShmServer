#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/field_s.h"

#define MAX_FIELD_REIKI_NUM 200

class FieldReikiDesc : public NFIDescStore
{
public:
	FieldReikiDesc(NFIPluginManager* pPluginManager);
	virtual ~FieldReikiDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::fieldreiki_s* GetDesc(int id) const;
	proto_ff_s::fieldreiki_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::fieldreiki_s, MAX_FIELD_REIKI_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::fieldreiki_s, MAX_FIELD_REIKI_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::fieldreiki_s, fieldreiki, MAX_FIELD_REIKI_NUM);
DECLARE_IDCREATE(FieldReikiDesc);
};
