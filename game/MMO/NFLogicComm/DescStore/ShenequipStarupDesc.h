#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenequip_s.h"

#define MAX_SHENEQUIP_STARUP_NUM 128

class ShenequipStarupDesc : public NFIDescTemplate<ShenequipStarupDesc, proto_ff_s::E_ShenequipStarup_s, EOT_CONST_SHENEQUIP_STARUP_DESC_ID, MAX_SHENEQUIP_STARUP_NUM>
{
public:
	ShenequipStarupDesc();
	virtual ~ShenequipStarupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
