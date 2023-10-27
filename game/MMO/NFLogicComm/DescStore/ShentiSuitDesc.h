#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_SUIT_NUM 128

class ShentiSuitDesc : public NFIDescTemplate<ShentiSuitDesc, proto_ff_s::E_ShentiSuit_s, EOT_CONST_SHENTI_SUIT_DESC_ID, MAX_SHENTI_SUIT_NUM>
{
public:
	ShentiSuitDesc();
	virtual ~ShentiSuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
