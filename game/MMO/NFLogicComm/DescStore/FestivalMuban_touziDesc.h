#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_TOUZI_NUM 400

class FestivalMuban_touziDesc : public NFIDescStore
{
public:
	FestivalMuban_touziDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_touziDesc();
	const proto_ff_s::festivalmuban_touzi_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_touzi_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_touzi_s, MAX_FESTIVAL_MUBAN_TOUZI_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_touzi_s, MAX_FESTIVAL_MUBAN_TOUZI_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_touzi_s, festivalmuban_touzi, MAX_FESTIVAL_MUBAN_TOUZI_NUM);
DECLARE_IDCREATE(FestivalMuban_touziDesc);
};
