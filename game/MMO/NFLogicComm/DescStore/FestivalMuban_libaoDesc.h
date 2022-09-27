#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_LIBAO_NUM 200

class FestivalMuban_libaoDesc : public NFIDescStore
{
public:
	FestivalMuban_libaoDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_libaoDesc();
	const proto_ff_s::festivalmuban_libao_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_libao_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_libao_s, MAX_FESTIVAL_MUBAN_LIBAO_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_libao_s, MAX_FESTIVAL_MUBAN_LIBAO_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_libao_s, festivalmuban_libao, MAX_FESTIVAL_MUBAN_LIBAO_NUM);
DECLARE_IDCREATE(FestivalMuban_libaoDesc);
};
