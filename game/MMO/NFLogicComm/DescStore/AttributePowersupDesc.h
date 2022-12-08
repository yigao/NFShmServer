#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/attribute_s.h"

#define MAX_ATTRIBUTE_POWERSUP_NUM 200

class AttributePowersupDesc : public NFIDescStore
{
public:
	AttributePowersupDesc();
	virtual ~AttributePowersupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::attributepowersup_s* GetDesc(int id) const;
	proto_ff_s::attributepowersup_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::attributepowersup_s, attributepowersup, MAX_ATTRIBUTE_POWERSUP_NUM);
DECLARE_IDCREATE(AttributePowersupDesc);
};
