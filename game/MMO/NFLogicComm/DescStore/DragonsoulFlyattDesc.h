#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_FLYATT_NUM 128

class DragonsoulFlyattDesc : public NFIDescTemplate<DragonsoulFlyattDesc, proto_ff_s::E_DragonsoulFlyatt_s, EOT_CONST_DRAGONSOUL_FLYATT_DESC_ID, MAX_DRAGONSOUL_FLYATT_NUM>
{
public:
	DragonsoulFlyattDesc();
	virtual ~DragonsoulFlyattDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
