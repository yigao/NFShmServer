#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Title_s.h"

#define MAX_TITLE_TYPE_NUM 8

class TitleTypeDesc : public NFIDescTemplate<TitleTypeDesc, proto_ff_s::E_TitleType_s, EOT_CONST_TITLE_TYPE_DESC_ID, MAX_TITLE_TYPE_NUM>
{
public:
	TitleTypeDesc();
	virtual ~TitleTypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
