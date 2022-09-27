#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/combine_s.h"

#define MAX_COMBINE_STARUP_NUM 800

class CombineStarupDesc : public NFIDescStore
{
public:
	CombineStarupDesc(NFIPluginManager* pPluginManager);
	virtual ~CombineStarupDesc();
	const proto_ff_s::combinestarUp_s* GetDesc(int id) const;
	proto_ff_s::combinestarUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::combinestarUp_s, MAX_COMBINE_STARUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::combinestarUp_s, MAX_COMBINE_STARUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::combinestarUp_s, combinestarUp, MAX_COMBINE_STARUP_NUM);
DECLARE_IDCREATE(CombineStarupDesc);
};
