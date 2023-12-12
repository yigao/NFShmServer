#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_JACKPOT_NUM 64

class WelfareJackpotDesc : public NFIDescTemplate<WelfareJackpotDesc, proto_ff_s::E_WelfareJackpot_s, EOT_CONST_WELFARE_JACKPOT_DESC_ID, MAX_WELFARE_JACKPOT_NUM>
{
public:
	WelfareJackpotDesc();
	virtual ~WelfareJackpotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
