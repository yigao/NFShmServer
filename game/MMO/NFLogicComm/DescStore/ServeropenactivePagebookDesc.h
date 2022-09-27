#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/serveropenactive_s.h"

#define MAX_SERVEROPENACTIVE_PAGEBOOK_NUM 20

class ServeropenactivePagebookDesc : public NFIDescStore
{
public:
	ServeropenactivePagebookDesc(NFIPluginManager* pPluginManager);
	virtual ~ServeropenactivePagebookDesc();
	const proto_ff_s::serveropenactivepageBook_s* GetDesc(int id) const;
	proto_ff_s::serveropenactivepageBook_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::serveropenactivepageBook_s, MAX_SERVEROPENACTIVE_PAGEBOOK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::serveropenactivepageBook_s, MAX_SERVEROPENACTIVE_PAGEBOOK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::serveropenactivepageBook_s, serveropenactivepageBook, MAX_SERVEROPENACTIVE_PAGEBOOK_NUM);
DECLARE_IDCREATE(ServeropenactivePagebookDesc);
};
