#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/manor_s.h"

#define MAX_MANOR_BUILDBUFF_NUM 20

class ManorBuildbuffDesc : public NFIDescStore
{
public:
	ManorBuildbuffDesc(NFIPluginManager* pPluginManager);
	virtual ~ManorBuildbuffDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::manorbuildBuff_s* GetDesc(int id) const;
	proto_ff_s::manorbuildBuff_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::manorbuildBuff_s, MAX_MANOR_BUILDBUFF_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::manorbuildBuff_s, MAX_MANOR_BUILDBUFF_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::manorbuildBuff_s, manorbuildBuff, MAX_MANOR_BUILDBUFF_NUM);
DECLARE_IDCREATE(ManorBuildbuffDesc);
};