#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_CHARGEUP_NUM 8

class NickgodChargeupDesc : public NFIDescTemplate<NickgodChargeupDesc, proto_ff_s::E_NickgodChargeup_s, EOT_CONST_NICKGOD_CHARGEUP_DESC_ID, MAX_NICKGOD_CHARGEUP_NUM>
{
public:
	NickgodChargeupDesc();
	virtual ~NickgodChargeupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
