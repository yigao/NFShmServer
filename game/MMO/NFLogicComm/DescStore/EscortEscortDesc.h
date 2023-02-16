#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_ESCORT_NUM 20

class EscortEscortDesc : public NFIDescStore
{
public:
	EscortEscortDesc();
	virtual ~EscortEscortDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EscortEscort_s* GetDesc(int id) const;
	proto_ff_s::E_EscortEscort_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EscortEscort_s, E_EscortEscort, MAX_ESCORT_ESCORT_NUM);
DECLARE_IDCREATE(EscortEscortDesc);
};
