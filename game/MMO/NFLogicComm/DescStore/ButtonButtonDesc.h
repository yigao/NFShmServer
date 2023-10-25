#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Button_s.h"

#define MAX_BUTTON_BUTTON_NUM 64

class ButtonButtonDesc : public NFIDescStore
{
public:
	ButtonButtonDesc();
	virtual ~ButtonButtonDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ButtonButton_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ButtonButton_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ButtonButton_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ButtonButton_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ButtonButtonDesc, proto_ff_s::E_ButtonButton_s, E_ButtonButton, MAX_BUTTON_BUTTON_NUM);
DECLARE_IDCREATE_GLOBAL(ButtonButtonDesc);
};
