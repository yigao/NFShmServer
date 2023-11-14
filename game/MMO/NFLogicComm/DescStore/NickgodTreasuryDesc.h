#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_TREASURY_NUM 16

class NickgodTreasuryDesc : public NFIDescTemplate<NickgodTreasuryDesc, proto_ff_s::E_NickgodTreasury_s, EOT_CONST_NICKGOD_TREASURY_DESC_ID, MAX_NICKGOD_TREASURY_NUM>
{
public:
	NickgodTreasuryDesc();
	virtual ~NickgodTreasuryDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
