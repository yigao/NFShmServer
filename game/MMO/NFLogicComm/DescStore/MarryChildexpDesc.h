#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CHILDEXP_NUM 32

class MarryChildexpDesc : public NFIDescTemplate<MarryChildexpDesc, proto_ff_s::E_MarryChildexp_s, EOT_CONST_MARRY_CHILDEXP_DESC_ID, MAX_MARRY_CHILDEXP_NUM>
{
public:
	MarryChildexpDesc();
	virtual ~MarryChildexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
