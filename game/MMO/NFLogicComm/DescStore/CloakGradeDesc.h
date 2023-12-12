#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Cloak_s.h"

#define MAX_CLOAK_GRADE_NUM 32

class CloakGradeDesc : public NFIDescTemplate<CloakGradeDesc, proto_ff_s::E_CloakGrade_s, EOT_CONST_CLOAK_GRADE_DESC_ID, MAX_CLOAK_GRADE_NUM>
{
public:
	CloakGradeDesc();
	virtual ~CloakGradeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
