#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_LVATT_NUM 128

class MofaLvattDesc : public NFIDescTemplate<MofaLvattDesc, proto_ff_s::E_MofaLvatt_s, EOT_CONST_MOFA_LVATT_DESC_ID, MAX_MOFA_LVATT_NUM>
{
public:
	MofaLvattDesc();
	virtual ~MofaLvattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
