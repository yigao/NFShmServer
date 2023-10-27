#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_GRADE_NUM 32

class EquipGradeDesc : public NFIDescTemplate<EquipGradeDesc, proto_ff_s::E_EquipGrade_s, EOT_CONST_EQUIP_GRADE_DESC_ID, MAX_EQUIP_GRADE_NUM>
{
public:
	EquipGradeDesc();
	virtual ~EquipGradeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
