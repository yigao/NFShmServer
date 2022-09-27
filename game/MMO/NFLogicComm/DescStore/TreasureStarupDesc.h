#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/treasure_s.h"

#define MAX_TREASURE_STARUP_NUM 20

class TreasureStarupDesc : public NFIDescStore
{
public:
	TreasureStarupDesc(NFIPluginManager* pPluginManager);
	virtual ~TreasureStarupDesc();
	const proto_ff_s::treasurestarUp_s* GetDesc(int id) const;
	proto_ff_s::treasurestarUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::treasurestarUp_s, MAX_TREASURE_STARUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::treasurestarUp_s, MAX_TREASURE_STARUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::treasurestarUp_s, treasurestarUp, MAX_TREASURE_STARUP_NUM);
DECLARE_IDCREATE(TreasureStarupDesc);
};
