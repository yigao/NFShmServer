#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_PRERECHARGE_NUM 40

class FestivalMuban_prerechargeDesc : public NFIDescStore
{
public:
	FestivalMuban_prerechargeDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_prerechargeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_prerecharge_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_prerecharge_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_prerecharge_s, MAX_FESTIVAL_MUBAN_PRERECHARGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_prerecharge_s, MAX_FESTIVAL_MUBAN_PRERECHARGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_prerecharge_s, festivalmuban_prerecharge, MAX_FESTIVAL_MUBAN_PRERECHARGE_NUM);
DECLARE_IDCREATE(FestivalMuban_prerechargeDesc);
};
