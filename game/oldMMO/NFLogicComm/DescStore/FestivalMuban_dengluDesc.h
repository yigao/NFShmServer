#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_DENGLU_NUM 200

class FestivalMuban_dengluDesc : public NFIDescStore
{
public:
	FestivalMuban_dengluDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_dengluDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_denglu_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_denglu_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_denglu_s, MAX_FESTIVAL_MUBAN_DENGLU_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_denglu_s, MAX_FESTIVAL_MUBAN_DENGLU_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_denglu_s, festivalmuban_denglu, MAX_FESTIVAL_MUBAN_DENGLU_NUM);
DECLARE_IDCREATE(FestivalMuban_dengluDesc);
};
