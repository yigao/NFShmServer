#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_CONST_NUM 20

class EscortConstDesc : public NFIDescStore
{
public:
	EscortConstDesc();
	virtual ~EscortConstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EscortConst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EscortConst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EscortConst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EscortConst_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(EscortConstDesc, proto_ff_s::E_EscortConst_s, E_EscortConst, MAX_ESCORT_CONST_NUM);
DECLARE_IDCREATE(EscortConstDesc);
};
