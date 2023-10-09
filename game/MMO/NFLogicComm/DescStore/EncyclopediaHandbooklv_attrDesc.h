#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKLV_ATTR_NUM 256

class EncyclopediaHandbooklv_attrDesc : public NFIDescStore
{
public:
	EncyclopediaHandbooklv_attrDesc();
	virtual ~EncyclopediaHandbooklv_attrDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaHandbooklv_attr_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaHandbooklv_attr_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaHandbooklv_attr_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaHandbooklv_attr_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaHandbooklv_attrDesc, proto_ff_s::E_EncyclopediaHandbooklv_attr_s, E_EncyclopediaHandbooklv_attr, MAX_ENCYCLOPEDIA_HANDBOOKLV_ATTR_NUM);
DECLARE_IDCREATE(EncyclopediaHandbooklv_attrDesc);
};
