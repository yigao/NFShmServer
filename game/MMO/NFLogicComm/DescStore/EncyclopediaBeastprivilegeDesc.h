#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEASTPRIVILEGE_NUM 4

class EncyclopediaBeastprivilegeDesc : public NFIDescStore
{
public:
	EncyclopediaBeastprivilegeDesc();
	virtual ~EncyclopediaBeastprivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaBeastprivilege_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaBeastprivilege_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaBeastprivilege_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaBeastprivilege_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaBeastprivilegeDesc, proto_ff_s::E_EncyclopediaBeastprivilege_s, E_EncyclopediaBeastprivilege, MAX_ENCYCLOPEDIA_BEASTPRIVILEGE_NUM);
DECLARE_IDCREATE(EncyclopediaBeastprivilegeDesc);
};
