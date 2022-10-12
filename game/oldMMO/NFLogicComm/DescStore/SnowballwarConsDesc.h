#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/snowballWar_s.h"

#define MAX_SNOWBALLWAR_CONS_NUM 20

class SnowballwarConsDesc : public NFIDescStore
{
public:
	SnowballwarConsDesc(NFIPluginManager* pPluginManager);
	virtual ~SnowballwarConsDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::snowballWarcons_s* GetDesc(int id) const;
	proto_ff_s::snowballWarcons_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::snowballWarcons_s, MAX_SNOWBALLWAR_CONS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::snowballWarcons_s, MAX_SNOWBALLWAR_CONS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::snowballWarcons_s, snowballWarcons, MAX_SNOWBALLWAR_CONS_NUM);
DECLARE_IDCREATE(SnowballwarConsDesc);
};
