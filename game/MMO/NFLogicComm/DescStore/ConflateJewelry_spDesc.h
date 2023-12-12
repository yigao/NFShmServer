#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_JEWELRY_SP_NUM 32

class ConflateJewelry_spDesc : public NFIDescTemplate<ConflateJewelry_spDesc, proto_ff_s::E_ConflateJewelry_sp_s, EOT_CONST_CONFLATE_JEWELRY_SP_DESC_ID, MAX_CONFLATE_JEWELRY_SP_NUM>
{
public:
	ConflateJewelry_spDesc();
	virtual ~ConflateJewelry_spDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
