#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ui_s.h"

#define MAX_UI_EFFECT_NUM 128

class UiEffectDesc : public NFIDescStore
{
public:
	UiEffectDesc();
	virtual ~UiEffectDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_UiEffect_s* GetDesc(int64_t id) const;
	proto_ff_s::E_UiEffect_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_UiEffect_s* GetDescByIndex(int index) const;
	proto_ff_s::E_UiEffect_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(UiEffectDesc, proto_ff_s::E_UiEffect_s, E_UiEffect, MAX_UI_EFFECT_NUM);
DECLARE_IDCREATE(UiEffectDesc);
};
