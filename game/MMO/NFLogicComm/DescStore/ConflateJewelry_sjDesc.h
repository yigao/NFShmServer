#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_JEWELRY_SJ_NUM 64

class ConflateJewelry_sjDesc : public NFIDescTemplate<ConflateJewelry_sjDesc, proto_ff_s::E_ConflateJewelry_sj_s, EOT_CONST_CONFLATE_JEWELRY_SJ_DESC_ID, MAX_CONFLATE_JEWELRY_SJ_NUM>
{
public:
	ConflateJewelry_sjDesc();
	virtual ~ConflateJewelry_sjDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
