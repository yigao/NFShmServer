#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/button_s.h"

#define MAX_BUTTON_BUTTON_NUM 80

class ButtonButtonDesc : public NFIDescStore
{
public:
	ButtonButtonDesc();
	virtual ~ButtonButtonDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::buttonbutton_s* GetDesc(int id) const;
	proto_ff_s::buttonbutton_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::buttonbutton_s, buttonbutton, MAX_BUTTON_BUTTON_NUM);
DECLARE_IDCREATE(ButtonButtonDesc);
};
