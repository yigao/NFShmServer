#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Encyclopedia_s.h"

#define MAX_ENCYCLOPEDIA_BEASTEXPAND_NUM 8

class EncyclopediaBeastexpandDesc : public NFIDescStore
{
public:
	EncyclopediaBeastexpandDesc();
	virtual ~EncyclopediaBeastexpandDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EncyclopediaBeastexpand_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EncyclopediaBeastexpand_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EncyclopediaBeastexpand_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EncyclopediaBeastexpand_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EncyclopediaBeastexpandDesc, proto_ff_s::E_EncyclopediaBeastexpand_s, E_EncyclopediaBeastexpand, MAX_ENCYCLOPEDIA_BEASTEXPAND_NUM);
DECLARE_IDCREATE(EncyclopediaBeastexpandDesc);
};
