#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_TASK_NUM 32

class BattlepassTaskDesc : public NFIDescStore
{
public:
	BattlepassTaskDesc();
	virtual ~BattlepassTaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BattlepassTask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BattlepassTask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BattlepassTask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BattlepassTask_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BattlepassTaskDesc, proto_ff_s::E_BattlepassTask_s, E_BattlepassTask, MAX_BATTLEPASS_TASK_NUM);
DECLARE_IDCREATE(BattlepassTaskDesc);
};
