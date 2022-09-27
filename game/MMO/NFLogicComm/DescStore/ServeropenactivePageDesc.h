#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_PAGE_NUM 140

class ServeropenactivePageDesc : public NFIDescStore
{
public:
	ServeropenactivePageDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactivePageDesc();
	const proto_ff_s::serveropenactivepage_s* GetDesc(int id) const;
	proto_ff_s::serveropenactivepage_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactivepage_s, MAX_SERVEROPENACTIVE_PAGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactivepage_s, MAX_SERVEROPENACTIVE_PAGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactivepage_s, serveropenactivepage, MAX_SERVEROPENACTIVE_PAGE_NUM);
DECLARE_IDCREATE(ServeropenactivePageDesc);
};
