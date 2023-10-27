#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_LOCKSKILL_NUM 8

class MarryLockskillDesc : public NFIDescTemplate<MarryLockskillDesc, proto_ff_s::E_MarryLockskill_s, EOT_CONST_MARRY_LOCKSKILL_DESC_ID, MAX_MARRY_LOCKSKILL_NUM>
{
public:
	MarryLockskillDesc();
	virtual ~MarryLockskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
