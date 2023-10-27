#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_DESTROYITEM_NUM 256

class MapDestroyitemDesc : public NFIDescTemplate<MapDestroyitemDesc, proto_ff_s::E_MapDestroyitem_s, EOT_CONST_MAP_DESTROYITEM_DESC_ID, MAX_MAP_DESTROYITEM_NUM>
{
public:
	MapDestroyitemDesc();
	virtual ~MapDestroyitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
