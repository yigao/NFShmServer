#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYJXATT_NUM 128

class MofaZyjxattDesc : public NFIDescTemplate<MofaZyjxattDesc, proto_ff_s::E_MofaZyjxatt_s, EOT_CONST_MOFA_ZYJXATT_DESC_ID, MAX_MOFA_ZYJXATT_NUM>
{
public:
	MofaZyjxattDesc();
	virtual ~MofaZyjxattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
