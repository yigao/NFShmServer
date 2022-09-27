#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_LEIXIAO_NUM 80

class FestivalMuban_leixiaoDesc : public NFIDescStore
{
public:
	FestivalMuban_leixiaoDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_leixiaoDesc();
	const proto_ff_s::festivalmuban_leixiao_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_leixiao_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_leixiao_s, MAX_FESTIVAL_MUBAN_LEIXIAO_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_leixiao_s, MAX_FESTIVAL_MUBAN_LEIXIAO_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_leixiao_s, festivalmuban_leixiao, MAX_FESTIVAL_MUBAN_LEIXIAO_NUM);
DECLARE_IDCREATE(FestivalMuban_leixiaoDesc);
};
