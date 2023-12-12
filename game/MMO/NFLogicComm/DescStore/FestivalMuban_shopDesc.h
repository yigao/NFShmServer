#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SHOP_NUM 32

class FestivalMuban_shopDesc : public NFIDescTemplate<FestivalMuban_shopDesc, proto_ff_s::E_FestivalMuban_shop_s, EOT_CONST_FESTIVAL_MUBAN_SHOP_DESC_ID, MAX_FESTIVAL_MUBAN_SHOP_NUM>
{
public:
	FestivalMuban_shopDesc();
	virtual ~FestivalMuban_shopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
