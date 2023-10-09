#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ranking_s.h"

#define MAX_RANKING_BUTTON_NUM 8

class RankingButtonDesc : public NFIDescStore
{
public:
	RankingButtonDesc();
	virtual ~RankingButtonDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_RankingButton_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RankingButton_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RankingButton_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RankingButton_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(RankingButtonDesc, proto_ff_s::E_RankingButton_s, E_RankingButton, MAX_RANKING_BUTTON_NUM);
DECLARE_IDCREATE(RankingButtonDesc);
};
