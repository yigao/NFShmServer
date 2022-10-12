#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/effect_s.h"

#define MAX_EFFECT_EFFECT_NUM 2000

class EffectEffectDesc : public NFIDescStore
{
public:
	EffectEffectDesc(NFIPluginManager* pPluginManager);
	virtual ~EffectEffectDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::effecteffect_s* GetDesc(int id) const;
	proto_ff_s::effecteffect_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::effecteffect_s, MAX_EFFECT_EFFECT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::effecteffect_s, MAX_EFFECT_EFFECT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::effecteffect_s, effecteffect, MAX_EFFECT_EFFECT_NUM);
DECLARE_IDCREATE(EffectEffectDesc);
};
