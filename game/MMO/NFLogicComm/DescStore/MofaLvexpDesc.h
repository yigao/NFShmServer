#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_LVEXP_NUM 128

class MofaLvexpDesc : public NFIDescTemplate<MofaLvexpDesc, proto_ff_s::E_MofaLvexp_s, EOT_CONST_MOFA_LVEXP_DESC_ID, MAX_MOFA_LVEXP_NUM>
{
public:
	MofaLvexpDesc();
	virtual ~MofaLvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
