#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/daily_s.h"

#define MAX_DAILY_CULTIVATE_NUM 40

class DailyCultivateDesc : public NFIDescStore
{
public:
	DailyCultivateDesc();
	virtual ~DailyCultivateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DailyCultivate_s* GetDesc(int id) const;
	proto_ff_s::E_DailyCultivate_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_DailyCultivate_s, E_DailyCultivate, MAX_DAILY_CULTIVATE_NUM);
DECLARE_IDCREATE(DailyCultivateDesc);
};
