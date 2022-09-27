#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/duplicate_s.h"

#define MAX_DUPLICATE_SWEEPMONSTERNUM_NUM 100

class DuplicateSweepmonsternumDesc : public NFIDescStore
{
public:
	DuplicateSweepmonsternumDesc(NFIPluginManager* pPluginManager);
	virtual ~DuplicateSweepmonsternumDesc();
	const proto_ff_s::duplicatesweepmonsterNum_s* GetDesc(int id) const;
	proto_ff_s::duplicatesweepmonsterNum_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::duplicatesweepmonsterNum_s, MAX_DUPLICATE_SWEEPMONSTERNUM_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::duplicatesweepmonsterNum_s, MAX_DUPLICATE_SWEEPMONSTERNUM_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::duplicatesweepmonsterNum_s, duplicatesweepmonsterNum, MAX_DUPLICATE_SWEEPMONSTERNUM_NUM);
DECLARE_IDCREATE(DuplicateSweepmonsternumDesc);
};
