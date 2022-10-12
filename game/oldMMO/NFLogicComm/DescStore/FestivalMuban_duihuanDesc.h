#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_DUIHUAN_NUM 500

class FestivalMuban_duihuanDesc : public NFIDescStore
{
public:
	FestivalMuban_duihuanDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_duihuanDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_duihuan_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_duihuan_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_duihuan_s, MAX_FESTIVAL_MUBAN_DUIHUAN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_duihuan_s, MAX_FESTIVAL_MUBAN_DUIHUAN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_duihuan_s, festivalmuban_duihuan, MAX_FESTIVAL_MUBAN_DUIHUAN_NUM);
DECLARE_IDCREATE(FestivalMuban_duihuanDesc);
};
