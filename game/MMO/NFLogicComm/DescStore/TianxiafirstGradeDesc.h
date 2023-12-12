#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_GRADE_NUM 32

class TianxiafirstGradeDesc : public NFIDescTemplate<TianxiafirstGradeDesc, proto_ff_s::E_TianxiafirstGrade_s, EOT_CONST_TIANXIAFIRST_GRADE_DESC_ID, MAX_TIANXIAFIRST_GRADE_NUM>
{
public:
	TianxiafirstGradeDesc();
	virtual ~TianxiafirstGradeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
