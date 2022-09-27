#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/combine_s.h"

#define MAX_COMBINE_QUALITYUP_NUM 300

class CombineQualityupDesc : public NFIDescStore
{
public:
	CombineQualityupDesc(NFIPluginManager* pPluginManager);
	virtual ~CombineQualityupDesc();
	const proto_ff_s::combinequalityUp_s* GetDesc(int id) const;
	proto_ff_s::combinequalityUp_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::combinequalityUp_s, MAX_COMBINE_QUALITYUP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::combinequalityUp_s, MAX_COMBINE_QUALITYUP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::combinequalityUp_s, combinequalityUp, MAX_COMBINE_QUALITYUP_NUM);
DECLARE_IDCREATE(CombineQualityupDesc);
};
