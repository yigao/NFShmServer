#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_BIGYANHUA_NUM 20

class FestivalMuban_bigyanhuaDesc : public NFIDescStore
{
public:
	FestivalMuban_bigyanhuaDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_bigyanhuaDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_bigyanhua_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_bigyanhua_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_bigyanhua_s, MAX_FESTIVAL_MUBAN_BIGYANHUA_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_bigyanhua_s, MAX_FESTIVAL_MUBAN_BIGYANHUA_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_bigyanhua_s, festivalmuban_bigyanhua, MAX_FESTIVAL_MUBAN_BIGYANHUA_NUM);
DECLARE_IDCREATE(FestivalMuban_bigyanhuaDesc);
};
