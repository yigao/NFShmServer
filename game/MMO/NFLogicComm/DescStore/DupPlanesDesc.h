#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_PLANES_NUM 64

class DupPlanesDesc : public NFIDescTemplate<DupPlanesDesc, proto_ff_s::E_DupPlanes_s, EOT_CONST_DUP_PLANES_DESC_ID, MAX_DUP_PLANES_NUM>
{
public:
	DupPlanesDesc();
	virtual ~DupPlanesDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
