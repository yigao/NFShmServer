#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_CONSTANT_NUM 2

class NickgodConstantDesc : public NFIDescTemplate<NickgodConstantDesc, proto_ff_s::E_NickgodConstant_s, EOT_CONST_NICKGOD_CONSTANT_DESC_ID, MAX_NICKGOD_CONSTANT_NUM>
{
public:
	NickgodConstantDesc();
	virtual ~NickgodConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
