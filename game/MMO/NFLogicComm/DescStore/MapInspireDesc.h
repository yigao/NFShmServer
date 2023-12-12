#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_INSPIRE_NUM 8

class MapInspireDesc : public NFIDescTemplate<MapInspireDesc, proto_ff_s::E_MapInspire_s, EOT_CONST_MAP_INSPIRE_DESC_ID, MAX_MAP_INSPIRE_NUM>
{
public:
	MapInspireDesc();
	virtual ~MapInspireDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
