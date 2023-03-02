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
	const proto_ff_s::E_ButtonButton_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ButtonButton_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ButtonButton_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ButtonButton_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_ButtonButton_s, E_ButtonButton, MAX_BUTTON_BUTTON_NUM);
DECLARE_IDCREATE(ButtonButtonDesc);
};
