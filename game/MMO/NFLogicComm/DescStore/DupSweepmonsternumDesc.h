#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dup_s.h"

#define MAX_DUP_SWEEPMONSTERNUM_NUM 60

class DupSweepmonsternumDesc : public NFIDescStore
{
public:
	DupSweepmonsternumDesc();
	virtual ~DupSweepmonsternumDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DupSweepmonsternum_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupSweepmonsternum_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupSweepmonsternum_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupSweepmonsternum_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DupSweepmonsternumDesc, proto_ff_s::E_DupSweepmonsternum_s, E_DupSweepmonsternum, MAX_DUP_SWEEPMONSTERNUM_NUM);
DECLARE_IDCREATE(DupSweepmonsternumDesc);
};
