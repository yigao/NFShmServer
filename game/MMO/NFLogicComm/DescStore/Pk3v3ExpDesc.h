#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_EXP_NUM 1024

class Pk3v3ExpDesc : public NFIDescTemplate<Pk3v3ExpDesc, proto_ff_s::E_Pk3v3Exp_s, EOT_CONST_PK3V3_EXP_DESC_ID, MAX_PK3V3_EXP_NUM>
{
public:
	Pk3v3ExpDesc();
	virtual ~Pk3v3ExpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
