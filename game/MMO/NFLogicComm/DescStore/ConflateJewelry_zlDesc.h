#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_JEWELRY_ZL_NUM 64

class ConflateJewelry_zlDesc : public NFIDescTemplate<ConflateJewelry_zlDesc, proto_ff_s::E_ConflateJewelry_zl_s, EOT_CONST_CONFLATE_JEWELRY_ZL_DESC_ID, MAX_CONFLATE_JEWELRY_ZL_NUM>
{
public:
	ConflateJewelry_zlDesc();
	virtual ~ConflateJewelry_zlDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
