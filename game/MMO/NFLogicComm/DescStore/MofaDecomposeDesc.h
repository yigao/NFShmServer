#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_DECOMPOSE_NUM 8

class MofaDecomposeDesc : public NFIDescTemplate<MofaDecomposeDesc, proto_ff_s::E_MofaDecompose_s, EOT_CONST_MOFA_DECOMPOSE_DESC_ID, MAX_MOFA_DECOMPOSE_NUM>
{
public:
	MofaDecomposeDesc();
	virtual ~MofaDecomposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
