#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/marry_s.h"

#define MAX_MARRY_TIMES_NUM 20

class MarryTimesDesc : public NFIDescStore
{
public:
	MarryTimesDesc(NFIPluginManager* pPluginManager);
	virtual ~MarryTimesDesc();
	const proto_ff_s::marrytimes_s* GetDesc(int id) const;
	proto_ff_s::marrytimes_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::marrytimes_s, MAX_MARRY_TIMES_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::marrytimes_s, MAX_MARRY_TIMES_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::marrytimes_s, marrytimes, MAX_MARRY_TIMES_NUM);
DECLARE_IDCREATE(MarryTimesDesc);
};
