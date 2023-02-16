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
	const proto_ff_s::E_DupSweepmonsternum_s* GetDesc(int id) const;
	proto_ff_s::E_DupSweepmonsternum_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_DupSweepmonsternum_s, E_DupSweepmonsternum, MAX_DUP_SWEEPMONSTERNUM_NUM);
DECLARE_IDCREATE(DupSweepmonsternumDesc);
};
