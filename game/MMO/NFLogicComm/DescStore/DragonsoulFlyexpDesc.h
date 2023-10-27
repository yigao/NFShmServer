#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_FLYEXP_NUM 64

class DragonsoulFlyexpDesc : public NFIDescTemplate<DragonsoulFlyexpDesc, proto_ff_s::E_DragonsoulFlyexp_s, EOT_CONST_DRAGONSOUL_FLYEXP_DESC_ID, MAX_DRAGONSOUL_FLYEXP_NUM>
{
public:
	DragonsoulFlyexpDesc();
	virtual ~DragonsoulFlyexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
