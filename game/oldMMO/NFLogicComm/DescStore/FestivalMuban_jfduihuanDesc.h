#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_MUBAN_JFDUIHUAN_NUM 20

class FestivalMuban_jfduihuanDesc : public NFIDescStore
{
public:
	FestivalMuban_jfduihuanDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalMuban_jfduihuanDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::festivalmuban_JFduihuan_s* GetDesc(int id) const;
	proto_ff_s::festivalmuban_JFduihuan_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_JFduihuan_s, MAX_FESTIVAL_MUBAN_JFDUIHUAN_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalmuban_JFduihuan_s, MAX_FESTIVAL_MUBAN_JFDUIHUAN_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalmuban_JFduihuan_s, festivalmuban_JFduihuan, MAX_FESTIVAL_MUBAN_JFDUIHUAN_NUM);
DECLARE_IDCREATE(FestivalMuban_jfduihuanDesc);
};
