#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_FLY_NUM 32

class DragonsoulFlyDesc : public NFIDescTemplate<DragonsoulFlyDesc, proto_ff_s::E_DragonsoulFly_s, EOT_CONST_DRAGONSOUL_FLY_DESC_ID, MAX_DRAGONSOUL_FLY_NUM>
{
public:
	DragonsoulFlyDesc();
	virtual ~DragonsoulFlyDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
