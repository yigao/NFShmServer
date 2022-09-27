#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_LEICHONG_NUM 800

class FestivalMuban_leichongDesc : public NFIDescStore
{
public:
	FestivalMuban_leichongDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_leichongDesc();
	const proto_ff_s::festivalmuban_leichong_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_leichong_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_leichong_s, MAX_FESTIVAL_MUBAN_LEICHONG_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_leichong_s, MAX_FESTIVAL_MUBAN_LEICHONG_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_leichong_s, festivalmuban_leichong, MAX_FESTIVAL_MUBAN_LEICHONG_NUM);
DECLARE_IDCREATE(FestivalMuban_leichongDesc);
};
