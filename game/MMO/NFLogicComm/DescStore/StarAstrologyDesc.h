#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/star_s.h"

#define MAX_STAR_ASTROLOGY_NUM 20

class StarAstrologyDesc : public NFIDescStore
{
public:
	StarAstrologyDesc(NFIPluginManager* pPluginManager);
	virtual ~StarAstrologyDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::starastrology_s* GetDesc(int id) const;
	proto_ff_s::starastrology_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::starastrology_s, MAX_STAR_ASTROLOGY_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::starastrology_s, MAX_STAR_ASTROLOGY_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::starastrology_s, starastrology, MAX_STAR_ASTROLOGY_NUM);
DECLARE_IDCREATE(StarAstrologyDesc);
};
