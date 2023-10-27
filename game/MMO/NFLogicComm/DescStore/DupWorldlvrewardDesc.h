#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_WORLDLVREWARD_NUM 32

class DupWorldlvrewardDesc : public NFIDescTemplate<DupWorldlvrewardDesc, proto_ff_s::E_DupWorldlvreward_s, EOT_CONST_DUP_WORLDLVREWARD_DESC_ID, MAX_DUP_WORLDLVREWARD_NUM>
{
public:
	DupWorldlvrewardDesc();
	virtual ~DupWorldlvrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
