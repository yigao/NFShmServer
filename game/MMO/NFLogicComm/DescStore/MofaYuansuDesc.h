#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_YUANSU_NUM 64

class MofaYuansuDesc : public NFIDescTemplate<MofaYuansuDesc, proto_ff_s::E_MofaYuansu_s, EOT_CONST_MOFA_YUANSU_DESC_ID, MAX_MOFA_YUANSU_NUM>
{
public:
	MofaYuansuDesc();
	virtual ~MofaYuansuDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
