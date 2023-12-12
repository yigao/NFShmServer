#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_SUBTYPE_NUM 128

class ConflateSubtypeDesc : public NFIDescTemplate<ConflateSubtypeDesc, proto_ff_s::E_ConflateSubtype_s, EOT_CONST_CONFLATE_SUBTYPE_DESC_ID, MAX_CONFLATE_SUBTYPE_NUM>
{
public:
	ConflateSubtypeDesc();
	virtual ~ConflateSubtypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
