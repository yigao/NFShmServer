#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Attribute_s.h"

#define MAX_ATTRIBUTE_POWERSUP_NUM 128

class AttributePowersupDesc : public NFIDescStore
{
public:
	AttributePowersupDesc();
	virtual ~AttributePowersupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AttributePowersup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AttributePowersup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AttributePowersup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AttributePowersup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AttributePowersupDesc, proto_ff_s::E_AttributePowersup_s, E_AttributePowersup, MAX_ATTRIBUTE_POWERSUP_NUM);
DECLARE_IDCREATE(AttributePowersupDesc);
};
