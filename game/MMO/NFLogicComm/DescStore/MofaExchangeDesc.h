#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_EXCHANGE_NUM 32

class MofaExchangeDesc : public NFIDescTemplate<MofaExchangeDesc, proto_ff_s::E_MofaExchange_s, EOT_CONST_MOFA_EXCHANGE_DESC_ID, MAX_MOFA_EXCHANGE_NUM>
{
public:
	MofaExchangeDesc();
	virtual ~MofaExchangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
