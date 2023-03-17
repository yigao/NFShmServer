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
	const proto_ff_s::E_AttributePowersup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AttributePowersup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AttributePowersup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AttributePowersup_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AttributePowersupDesc, proto_ff_s::E_AttributePowersup_s, E_AttributePowersup, MAX_ATTRIBUTE_POWERSUP_NUM);
DECLARE_IDCREATE(AttributePowersupDesc);
};
