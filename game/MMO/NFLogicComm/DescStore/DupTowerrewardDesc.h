#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dup_s.h"

#define MAX_DUP_TOWERREWARD_NUM 20

class DupTowerrewardDesc : public NFIDescStore
{
public:
	DupTowerrewardDesc();
	virtual ~DupTowerrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DupTowerreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupTowerreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupTowerreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupTowerreward_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DupTowerrewardDesc, proto_ff_s::E_DupTowerreward_s, E_DupTowerreward, MAX_DUP_TOWERREWARD_NUM);
DECLARE_IDCREATE(DupTowerrewardDesc);
};
