#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_TOWERREWARD_NUM 256

class DupTowerrewardDesc : public NFIDescTemplate<DupTowerrewardDesc, proto_ff_s::E_DupTowerreward_s, EOT_CONST_DUP_TOWERREWARD_DESC_ID, MAX_DUP_TOWERREWARD_NUM>
{
public:
	DupTowerrewardDesc();
	virtual ~DupTowerrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
