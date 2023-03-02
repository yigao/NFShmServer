#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ui_s.h"

#define MAX_UI_EFFECT_NUM 20

class UiEffectDesc : public NFIDescStore
{
public:
	UiEffectDesc();
	virtual ~UiEffectDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_UiEffect_s* GetDesc(int64_t id) const;
	proto_ff_s::E_UiEffect_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_UiEffect_s* GetDescByIndex(int index) const;
	proto_ff_s::E_UiEffect_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_UiEffect_s, E_UiEffect, MAX_UI_EFFECT_NUM);
DECLARE_IDCREATE(UiEffectDesc);
};
