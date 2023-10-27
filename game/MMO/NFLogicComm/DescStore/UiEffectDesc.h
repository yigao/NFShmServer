#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ui_s.h"

#define MAX_UI_EFFECT_NUM 128

class UiEffectDesc : public NFIDescTemplate<UiEffectDesc, proto_ff_s::E_UiEffect_s, EOT_CONST_UI_EFFECT_DESC_ID, MAX_UI_EFFECT_NUM>
{
public:
	UiEffectDesc();
	virtual ~UiEffectDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
