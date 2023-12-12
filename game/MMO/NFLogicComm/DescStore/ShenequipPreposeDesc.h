#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_PREPOSE_NUM 8

class ShenequipPreposeDesc : public NFIDescTemplate<ShenequipPreposeDesc, proto_ff_s::E_ShenequipPrepose_s, EOT_CONST_SHENEQUIP_PREPOSE_DESC_ID, MAX_SHENEQUIP_PREPOSE_NUM>
{
public:
	ShenequipPreposeDesc();
	virtual ~ShenequipPreposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
