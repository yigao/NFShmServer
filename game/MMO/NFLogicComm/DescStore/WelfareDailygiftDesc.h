#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_DAILYGIFT_NUM 16

class WelfareDailygiftDesc : public NFIDescTemplate<WelfareDailygiftDesc, proto_ff_s::E_WelfareDailygift_s, EOT_CONST_WELFARE_DAILYGIFT_DESC_ID, MAX_WELFARE_DAILYGIFT_NUM>
{
public:
	WelfareDailygiftDesc();
	virtual ~WelfareDailygiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
