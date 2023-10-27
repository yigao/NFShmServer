#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_MIBAO_NUM 32

class WelfareMibaoDesc : public NFIDescTemplate<WelfareMibaoDesc, proto_ff_s::E_WelfareMibao_s, EOT_CONST_WELFARE_MIBAO_DESC_ID, MAX_WELFARE_MIBAO_NUM>
{
public:
	WelfareMibaoDesc();
	virtual ~WelfareMibaoDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
