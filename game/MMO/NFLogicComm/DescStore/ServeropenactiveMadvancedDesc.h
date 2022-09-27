#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_MADVANCED_NUM 160

class ServeropenactiveMadvancedDesc : public NFIDescStore
{
public:
	ServeropenactiveMadvancedDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactiveMadvancedDesc();
	const proto_ff_s::serveropenactivemAdvanced_s* GetDesc(int id) const;
	proto_ff_s::serveropenactivemAdvanced_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemAdvanced_s, MAX_SERVEROPENACTIVE_MADVANCED_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactivemAdvanced_s, MAX_SERVEROPENACTIVE_MADVANCED_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactivemAdvanced_s, serveropenactivemAdvanced, MAX_SERVEROPENACTIVE_MADVANCED_NUM);
DECLARE_IDCREATE(ServeropenactiveMadvancedDesc);
};
