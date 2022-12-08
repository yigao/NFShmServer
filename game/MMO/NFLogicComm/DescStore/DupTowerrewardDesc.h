#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::duptowerReward_s* GetDesc(int id) const;
	proto_ff_s::duptowerReward_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::duptowerReward_s, duptowerReward, MAX_DUP_TOWERREWARD_NUM);
DECLARE_IDCREATE(DupTowerrewardDesc);
};
