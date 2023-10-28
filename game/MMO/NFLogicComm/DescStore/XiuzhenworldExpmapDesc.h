#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenworld_s.h"

#define MAX_XIUZHENWORLD_EXPMAP_NUM 8

class XiuzhenworldExpmapDesc : public NFIDescTemplate<XiuzhenworldExpmapDesc, proto_ff_s::E_XiuzhenworldExpmap_s, EOT_CONST_XIUZHENWORLD_EXPMAP_DESC_ID, MAX_XIUZHENWORLD_EXPMAP_NUM>
{
public:
	XiuzhenworldExpmapDesc();
	virtual ~XiuzhenworldExpmapDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
