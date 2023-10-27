#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_NAME_NUM 8

class MofaNameDesc : public NFIDescTemplate<MofaNameDesc, proto_ff_s::E_MofaName_s, EOT_CONST_MOFA_NAME_DESC_ID, MAX_MOFA_NAME_NUM>
{
public:
	MofaNameDesc();
	virtual ~MofaNameDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
