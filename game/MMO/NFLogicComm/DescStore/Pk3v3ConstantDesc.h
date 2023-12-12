#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_CONSTANT_NUM 2

class Pk3v3ConstantDesc : public NFIDescTemplate<Pk3v3ConstantDesc, proto_ff_s::E_Pk3v3Constant_s, EOT_CONST_PK3V3_CONSTANT_DESC_ID, MAX_PK3V3_CONSTANT_NUM>
{
public:
	Pk3v3ConstantDesc();
	virtual ~Pk3v3ConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
