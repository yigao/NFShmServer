#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GMtools_s.h"

#define MAX_GMTOOLS_GIFT_NUM 20

class GmtoolsGiftDesc : public NFIDescStore
{
public:
	GmtoolsGiftDesc(NFIPluginManager* pPluginManager);
	virtual ~GmtoolsGiftDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::GMtoolsgift_s* GetDesc(int id) const;
	proto_ff_s::GMtoolsgift_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::GMtoolsgift_s, MAX_GMTOOLS_GIFT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::GMtoolsgift_s, MAX_GMTOOLS_GIFT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::GMtoolsgift_s, GMtoolsgift, MAX_GMTOOLS_GIFT_NUM);
DECLARE_IDCREATE(GmtoolsGiftDesc);
};
