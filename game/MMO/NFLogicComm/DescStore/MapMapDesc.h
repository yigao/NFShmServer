#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_MAP_NUM 128

class MapMapDesc : public NFIDescTemplate<MapMapDesc, proto_ff_s::E_MapMap_s, EOT_CONST_MAP_MAP_DESC_ID, MAX_MAP_MAP_NUM>
{
public:
	MapMapDesc();
	virtual ~MapMapDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
