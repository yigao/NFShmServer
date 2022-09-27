#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_CZFANZUAN_NUM 20

class FestivalMuban_czfanzuanDesc : public NFIDescStore
{
public:
	FestivalMuban_czfanzuanDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_czfanzuanDesc();
	const proto_ff_s::festivalmuban_CZfanzuan_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_CZfanzuan_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_CZfanzuan_s, MAX_FESTIVAL_MUBAN_CZFANZUAN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_CZfanzuan_s, MAX_FESTIVAL_MUBAN_CZFANZUAN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_CZfanzuan_s, festivalmuban_CZfanzuan, MAX_FESTIVAL_MUBAN_CZFANZUAN_NUM);
DECLARE_IDCREATE(FestivalMuban_czfanzuanDesc);
};
