#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Title_s.h"

#define MAX_TITLE_TITLE_NUM 128

class TitleTitleDesc : public NFIDescTemplate<TitleTitleDesc, proto_ff_s::E_TitleTitle_s, EOT_CONST_TITLE_TITLE_DESC_ID, MAX_TITLE_TITLE_NUM>
{
public:
	TitleTitleDesc();
	virtual ~TitleTitleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
