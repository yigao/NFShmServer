#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Headportrait_s.h"

#define MAX_HEADPORTRAIT_HEAD_NUM 64

class HeadportraitHeadDesc : public NFIDescTemplate<HeadportraitHeadDesc, proto_ff_s::E_HeadportraitHead_s, EOT_CONST_HEADPORTRAIT_HEAD_DESC_ID, MAX_HEADPORTRAIT_HEAD_NUM>
{
public:
	HeadportraitHeadDesc();
	virtual ~HeadportraitHeadDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
