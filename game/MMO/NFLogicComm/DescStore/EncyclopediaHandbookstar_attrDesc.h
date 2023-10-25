#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_HANDBOOKSTAR_ATTR_NUM 256

class EncyclopediaHandbookstar_attrDesc : public NFIDescStore
{
public:
	EncyclopediaHandbookstar_attrDesc();
	virtual ~EncyclopediaHandbookstar_attrDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaHandbookstar_attr_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaHandbookstar_attr_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaHandbookstar_attr_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaHandbookstar_attr_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaHandbookstar_attrDesc, proto_ff_s::E_EncyclopediaHandbookstar_attr_s, E_EncyclopediaHandbookstar_attr, MAX_ENCYCLOPEDIA_HANDBOOKSTAR_ATTR_NUM);
DECLARE_IDCREATE_GLOBAL(EncyclopediaHandbookstar_attrDesc);
};
