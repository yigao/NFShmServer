#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_COMMON_NUM 512

class MarryCommonDesc : public NFIDescTemplate<MarryCommonDesc, proto_ff_s::E_MarryCommon_s, EOT_CONST_MARRY_COMMON_DESC_ID, MAX_MARRY_COMMON_NUM>
{
public:
	MarryCommonDesc();
	virtual ~MarryCommonDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
