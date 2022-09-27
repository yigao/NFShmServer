#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_LIANXUCZ_NUM 20

class FestivalMuban_lianxuczDesc : public NFIDescStore
{
public:
	FestivalMuban_lianxuczDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_lianxuczDesc();
	const proto_ff_s::festivalmuban_lianxuCZ_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_lianxuCZ_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_lianxuCZ_s, MAX_FESTIVAL_MUBAN_LIANXUCZ_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_lianxuCZ_s, MAX_FESTIVAL_MUBAN_LIANXUCZ_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_lianxuCZ_s, festivalmuban_lianxuCZ, MAX_FESTIVAL_MUBAN_LIANXUCZ_NUM);
DECLARE_IDCREATE(FestivalMuban_lianxuczDesc);
};
