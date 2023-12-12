#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragonsoul_s.h"

#define MAX_DRAGONSOUL_OFFEREXP_NUM 4

class DragonsoulOfferexpDesc : public NFIDescTemplate<DragonsoulOfferexpDesc, proto_ff_s::E_DragonsoulOfferexp_s, EOT_CONST_DRAGONSOUL_OFFEREXP_DESC_ID, MAX_DRAGONSOUL_OFFEREXP_NUM>
{
public:
	DragonsoulOfferexpDesc();
	virtual ~DragonsoulOfferexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
