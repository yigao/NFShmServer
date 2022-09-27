#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_SCSB_NUM 20

class FestivalMuban_scsbDesc : public NFIDescStore
{
public:
	FestivalMuban_scsbDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_scsbDesc();
	const proto_ff_s::festivalmuban_scsb_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_scsb_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_scsb_s, MAX_FESTIVAL_MUBAN_SCSB_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_scsb_s, MAX_FESTIVAL_MUBAN_SCSB_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_scsb_s, festivalmuban_scsb, MAX_FESTIVAL_MUBAN_SCSB_NUM);
DECLARE_IDCREATE(FestivalMuban_scsbDesc);
};
