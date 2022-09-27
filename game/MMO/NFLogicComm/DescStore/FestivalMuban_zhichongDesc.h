#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_ZHICHONG_NUM 200

class FestivalMuban_zhichongDesc : public NFIDescStore
{
public:
	FestivalMuban_zhichongDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_zhichongDesc();
	const proto_ff_s::festivalmuban_zhichong_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_zhichong_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_zhichong_s, MAX_FESTIVAL_MUBAN_ZHICHONG_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_zhichong_s, MAX_FESTIVAL_MUBAN_ZHICHONG_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_zhichong_s, festivalmuban_zhichong, MAX_FESTIVAL_MUBAN_ZHICHONG_NUM);
DECLARE_IDCREATE(FestivalMuban_zhichongDesc);
};
