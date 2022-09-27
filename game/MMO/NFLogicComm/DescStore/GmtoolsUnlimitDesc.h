#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GMtools_s.h"

#define MAX_GMTOOLS_UNLIMIT_NUM 20

class GmtoolsUnlimitDesc : public NFIDescStore
{
public:
	GmtoolsUnlimitDesc(NFIPluginManager* pPluginManager);
	virtual ~GmtoolsUnlimitDesc();
	const proto_ff_s::GMtoolsunlimit_s* GetDesc(int id) const;
	proto_ff_s::GMtoolsunlimit_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::GMtoolsunlimit_s, MAX_GMTOOLS_UNLIMIT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::GMtoolsunlimit_s, MAX_GMTOOLS_UNLIMIT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::GMtoolsunlimit_s, GMtoolsunlimit, MAX_GMTOOLS_UNLIMIT_NUM);
DECLARE_IDCREATE(GmtoolsUnlimitDesc);
};
