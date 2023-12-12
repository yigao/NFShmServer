#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_STARCOLLECT_NUM 1024

class AncientgodStarcollectDesc : public NFIDescTemplate<AncientgodStarcollectDesc, proto_ff_s::E_AncientgodStarcollect_s, EOT_CONST_ANCIENTGOD_STARCOLLECT_DESC_ID, MAX_ANCIENTGOD_STARCOLLECT_NUM>
{
public:
	AncientgodStarcollectDesc();
	virtual ~AncientgodStarcollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
