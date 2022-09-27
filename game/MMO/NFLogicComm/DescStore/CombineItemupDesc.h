#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/combine_s.h"

#define MAX_COMBINE_ITEMUP_NUM 60

class CombineItemupDesc : public NFIDescStore
{
public:
	CombineItemupDesc(NFIPluginManager* pPluginManager);
	virtual ~CombineItemupDesc();
	const proto_ff_s::combineitemUp_s* GetDesc(int id) const;
	proto_ff_s::combineitemUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::combineitemUp_s, MAX_COMBINE_ITEMUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::combineitemUp_s, MAX_COMBINE_ITEMUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::combineitemUp_s, combineitemUp, MAX_COMBINE_ITEMUP_NUM);
DECLARE_IDCREATE(CombineItemupDesc);
};
