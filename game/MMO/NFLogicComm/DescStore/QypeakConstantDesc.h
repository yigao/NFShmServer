#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qypeak_s.h"

#define MAX_QYPEAK_CONSTANT_NUM 2

class QypeakConstantDesc : public NFIDescStore
{
public:
	QypeakConstantDesc();
	virtual ~QypeakConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_QypeakConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_QypeakConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_QypeakConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_QypeakConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(QypeakConstantDesc, proto_ff_s::E_QypeakConstant_s, E_QypeakConstant, MAX_QYPEAK_CONSTANT_NUM);
DECLARE_IDCREATE(QypeakConstantDesc);
};
