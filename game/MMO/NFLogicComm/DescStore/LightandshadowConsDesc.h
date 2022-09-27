#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/lightAndShadow_s.h"

#define MAX_LIGHTANDSHADOW_CONS_NUM 20

class LightandshadowConsDesc : public NFIDescStore
{
public:
	LightandshadowConsDesc(NFIPluginManager* pPluginManager);
	virtual ~LightandshadowConsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::lightAndShadowcons_s* GetDesc(int id) const;
	proto_ff_s::lightAndShadowcons_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::lightAndShadowcons_s, MAX_LIGHTANDSHADOW_CONS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::lightAndShadowcons_s, MAX_LIGHTANDSHADOW_CONS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::lightAndShadowcons_s, lightAndShadowcons, MAX_LIGHTANDSHADOW_CONS_NUM);
DECLARE_IDCREATE(LightandshadowConsDesc);
};
