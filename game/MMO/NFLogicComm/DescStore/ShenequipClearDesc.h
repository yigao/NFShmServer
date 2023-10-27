#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_CLEAR_NUM 128

class ShenequipClearDesc : public NFIDescTemplate<ShenequipClearDesc, proto_ff_s::E_ShenequipClear_s, EOT_CONST_SHENEQUIP_CLEAR_DESC_ID, MAX_SHENEQUIP_CLEAR_NUM>
{
public:
	ShenequipClearDesc();
	virtual ~ShenequipClearDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
