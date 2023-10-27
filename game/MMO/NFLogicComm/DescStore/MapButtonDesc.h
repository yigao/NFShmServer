#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_BUTTON_NUM 32

class MapButtonDesc : public NFIDescTemplate<MapButtonDesc, proto_ff_s::E_MapButton_s, EOT_CONST_MAP_BUTTON_DESC_ID, MAX_MAP_BUTTON_NUM>
{
public:
	MapButtonDesc();
	virtual ~MapButtonDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
