#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_EscortConst_s* GetDesc(int id) const;
	proto_ff_s::E_EscortConst_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EscortConst_s, E_EscortConst, MAX_ESCORT_CONST_NUM);
DECLARE_IDCREATE(EscortConstDesc);
};
