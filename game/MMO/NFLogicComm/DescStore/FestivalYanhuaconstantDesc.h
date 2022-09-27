#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/festival_s.h"

#define MAX_FESTIVAL_YANHUACONSTANT_NUM 20

class FestivalYanhuaconstantDesc : public NFIDescStore
{
public:
	FestivalYanhuaconstantDesc(NFIPluginManager* pPluginManager);
	virtual ~FestivalYanhuaconstantDesc();
	const proto_ff_s::festivalyanhuaConstant_s* GetDesc(int id) const;
	proto_ff_s::festivalyanhuaConstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::festivalyanhuaConstant_s, MAX_FESTIVAL_YANHUACONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::festivalyanhuaConstant_s, MAX_FESTIVAL_YANHUACONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::festivalyanhuaConstant_s, festivalyanhuaConstant, MAX_FESTIVAL_YANHUACONSTANT_NUM);
DECLARE_IDCREATE(FestivalYanhuaconstantDesc);
};
