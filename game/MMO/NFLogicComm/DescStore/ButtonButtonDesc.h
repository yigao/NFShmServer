#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Button_s.h"

#define MAX_BUTTON_BUTTON_NUM 64

class ButtonButtonDesc : public NFIDescTemplate<ButtonButtonDesc, proto_ff_s::E_ButtonButton_s, EOT_CONST_BUTTON_BUTTON_DESC_ID, MAX_BUTTON_BUTTON_NUM>
{
public:
	ButtonButtonDesc();
	virtual ~ButtonButtonDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
