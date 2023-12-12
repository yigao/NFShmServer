#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CHILD_NUM 16

class MarryChildDesc : public NFIDescTemplate<MarryChildDesc, proto_ff_s::E_MarryChild_s, EOT_CONST_MARRY_CHILD_DESC_ID, MAX_MARRY_CHILD_NUM>
{
public:
	MarryChildDesc();
	virtual ~MarryChildDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
