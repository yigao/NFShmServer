#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_SETUP_NUM 16

class MofaSetupDesc : public NFIDescTemplate<MofaSetupDesc, proto_ff_s::E_MofaSetup_s, EOT_CONST_MOFA_SETUP_DESC_ID, MAX_MOFA_SETUP_NUM>
{
public:
	MofaSetupDesc();
	virtual ~MofaSetupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
