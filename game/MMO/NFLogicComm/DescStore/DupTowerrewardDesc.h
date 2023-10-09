#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_TOWERREWARD_NUM 256

class DupTowerrewardDesc : public NFIDescStore
{
public:
	DupTowerrewardDesc();
	virtual ~DupTowerrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupTowerreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupTowerreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupTowerreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupTowerreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupTowerrewardDesc, proto_ff_s::E_DupTowerreward_s, E_DupTowerreward, MAX_DUP_TOWERREWARD_NUM);
DECLARE_IDCREATE(DupTowerrewardDesc);
};
