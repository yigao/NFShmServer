#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_GROUPTYPE_NUM 64

class ConflateGrouptypeDesc : public NFIDescTemplate<ConflateGrouptypeDesc, proto_ff_s::E_ConflateGrouptype_s, EOT_CONST_CONFLATE_GROUPTYPE_DESC_ID, MAX_CONFLATE_GROUPTYPE_NUM>
{
public:
	ConflateGrouptypeDesc();
	virtual ~ConflateGrouptypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
