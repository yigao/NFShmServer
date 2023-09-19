#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_GRADE_NUM 40

class EquipGradeDesc : public NFIDescStore
{
public:
	EquipGradeDesc();
	virtual ~EquipGradeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipGrade_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipGrade_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipGrade_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipGrade_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(EquipGradeDesc, proto_ff_s::E_EquipGrade_s, E_EquipGrade, MAX_EQUIP_GRADE_NUM);
DECLARE_IDCREATE(EquipGradeDesc);
};
