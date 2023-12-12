#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Escort_s.h"

#define MAX_ESCORT_ESCORT_NUM 8

class EscortEscortDesc : public NFIDescTemplate<EscortEscortDesc, proto_ff_s::E_EscortEscort_s, EOT_CONST_ESCORT_ESCORT_DESC_ID, MAX_ESCORT_ESCORT_NUM>
{
public:
	EscortEscortDesc();
	virtual ~EscortEscortDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
