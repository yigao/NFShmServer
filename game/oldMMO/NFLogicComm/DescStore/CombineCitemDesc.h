#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/combine_s.h"

#define MAX_COMBINE_CITEM_NUM 500

class CombineCitemDesc : public NFIDescStore
{
public:
	CombineCitemDesc(NFIPluginManager* pPluginManager);
	virtual ~CombineCitemDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::combinecitem_s* GetDesc(int id) const;
	proto_ff_s::combinecitem_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::combinecitem_s, MAX_COMBINE_CITEM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::combinecitem_s, MAX_COMBINE_CITEM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::combinecitem_s, combinecitem, MAX_COMBINE_CITEM_NUM);
DECLARE_IDCREATE(CombineCitemDesc);
};
