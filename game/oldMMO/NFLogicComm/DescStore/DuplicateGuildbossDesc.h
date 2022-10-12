#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_GUILDBOSS_NUM 300

class DuplicateGuildbossDesc : public NFIDescStore
{
public:
	DuplicateGuildbossDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateGuildbossDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::duplicateGuildboss_s* GetDesc(int id) const;
	proto_ff_s::duplicateGuildboss_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicateGuildboss_s, MAX_DUPLICATE_GUILDBOSS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicateGuildboss_s, MAX_DUPLICATE_GUILDBOSS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicateGuildboss_s, duplicateGuildboss, MAX_DUPLICATE_GUILDBOSS_NUM);
DECLARE_IDCREATE(DuplicateGuildbossDesc);
};
