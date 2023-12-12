#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Escort_s.h"

#define MAX_ESCORT_CONST_NUM 8

class EscortConstDesc : public NFIDescTemplate<EscortConstDesc, proto_ff_s::E_EscortConst_s, EOT_CONST_ESCORT_CONST_DESC_ID, MAX_ESCORT_CONST_NUM>
{
public:
	EscortConstDesc();
	virtual ~EscortConstDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
