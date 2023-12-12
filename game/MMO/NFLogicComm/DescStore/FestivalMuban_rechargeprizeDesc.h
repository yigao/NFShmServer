#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RECHARGEPRIZE_NUM 2

class FestivalMuban_rechargeprizeDesc : public NFIDescTemplate<FestivalMuban_rechargeprizeDesc, proto_ff_s::E_FestivalMuban_rechargeprize_s, EOT_CONST_FESTIVAL_MUBAN_RECHARGEPRIZE_DESC_ID, MAX_FESTIVAL_MUBAN_RECHARGEPRIZE_NUM>
{
public:
	FestivalMuban_rechargeprizeDesc();
	virtual ~FestivalMuban_rechargeprizeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
