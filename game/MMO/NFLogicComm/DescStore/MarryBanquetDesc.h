#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/marry_s.h"

#define MAX_MARRY_BANQUET_NUM 20

class MarryBanquetDesc : public NFIDescStore
{
public:
	MarryBanquetDesc(NFIPluginManager* pPluginManager);
	virtual ~MarryBanquetDesc();
	const proto_ff_s::marrybanquet_s* GetDesc(int id) const;
	proto_ff_s::marrybanquet_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::marrybanquet_s, MAX_MARRY_BANQUET_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::marrybanquet_s, MAX_MARRY_BANQUET_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::marrybanquet_s, marrybanquet, MAX_MARRY_BANQUET_NUM);
DECLARE_IDCREATE(MarryBanquetDesc);
};
