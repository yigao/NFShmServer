#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_ITEMDROP_NUM 4

class MapItemdropDesc : public NFIDescTemplate<MapItemdropDesc, proto_ff_s::E_MapItemdrop_s, EOT_CONST_MAP_ITEMDROP_DESC_ID, MAX_MAP_ITEMDROP_NUM>
{
public:
	MapItemdropDesc();
	virtual ~MapItemdropDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
