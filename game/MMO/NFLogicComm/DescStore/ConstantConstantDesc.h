#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/constant_s.h"

#define MAX_CONSTANT_CONSTANT_NUM 300

class ConstantConstantDesc : public NFIDescStore
{
public:
	ConstantConstantDesc();
	virtual ~ConstantConstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::constantconstant_s* GetDesc(int id) const;
	proto_ff_s::constantconstant_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::constantconstant_s, constantconstant, MAX_CONSTANT_CONSTANT_NUM);
DECLARE_IDCREATE(ConstantConstantDesc);
};
