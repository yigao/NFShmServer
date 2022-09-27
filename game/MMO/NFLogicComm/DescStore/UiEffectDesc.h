#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/ui_s.h"

#define MAX_UI_EFFECT_NUM 200

class UiEffectDesc : public NFIDescStore
{
public:
	UiEffectDesc(NFIPluginManager* pPluginManager);
	virtual ~UiEffectDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::uieffect_s* GetDesc(int id) const;
	proto_ff_s::uieffect_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::uieffect_s, MAX_UI_EFFECT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::uieffect_s, MAX_UI_EFFECT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::uieffect_s, uieffect, MAX_UI_EFFECT_NUM);
DECLARE_IDCREATE(UiEffectDesc);
};
