#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_ZYJXZFATT_NUM 64

class MofaZyjxzfattDesc : public NFIDescTemplate<MofaZyjxzfattDesc, proto_ff_s::E_MofaZyjxzfatt_s, EOT_CONST_MOFA_ZYJXZFATT_DESC_ID, MAX_MOFA_ZYJXZFATT_NUM>
{
public:
	MofaZyjxzfattDesc();
	virtual ~MofaZyjxzfattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
