#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/combine_s.h"

#define MAX_COMBINE_RANKUP_NUM 40

class CombineRankupDesc : public NFIDescStore
{
public:
	CombineRankupDesc(NFIPluginManager* pPluginManager);
	virtual ~CombineRankupDesc();
	const proto_ff_s::combinerankUp_s* GetDesc(int id) const;
	proto_ff_s::combinerankUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::combinerankUp_s, MAX_COMBINE_RANKUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::combinerankUp_s, MAX_COMBINE_RANKUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::combinerankUp_s, combinerankUp, MAX_COMBINE_RANKUP_NUM);
DECLARE_IDCREATE(CombineRankupDesc);
};
