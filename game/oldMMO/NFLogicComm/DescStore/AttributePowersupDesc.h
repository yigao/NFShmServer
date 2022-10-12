#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/attribute_s.h"

#define MAX_ATTRIBUTE_POWERSUP_NUM 200

class AttributePowersupDesc : public NFIDescStore
{
public:
	AttributePowersupDesc(NFIPluginManager* pPluginManager);
	virtual ~AttributePowersupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::attributepowersup_s* GetDesc(int id) const;
	proto_ff_s::attributepowersup_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::attributepowersup_s, MAX_ATTRIBUTE_POWERSUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::attributepowersup_s, MAX_ATTRIBUTE_POWERSUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::attributepowersup_s, attributepowersup, MAX_ATTRIBUTE_POWERSUP_NUM);
DECLARE_IDCREATE(AttributePowersupDesc);
};
