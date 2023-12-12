#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_SWEEPMONSTERNUM_NUM 64

class DupSweepmonsternumDesc : public NFIDescTemplate<DupSweepmonsternumDesc, proto_ff_s::E_DupSweepmonsternum_s, EOT_CONST_DUP_SWEEPMONSTERNUM_DESC_ID, MAX_DUP_SWEEPMONSTERNUM_NUM>
{
public:
	DupSweepmonsternumDesc();
	virtual ~DupSweepmonsternumDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
