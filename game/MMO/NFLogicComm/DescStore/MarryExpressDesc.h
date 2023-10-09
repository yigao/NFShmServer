#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_EXPRESS_NUM 1024

class MarryExpressDesc : public NFIDescStore
{
public:
	MarryExpressDesc();
	virtual ~MarryExpressDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryExpress_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryExpress_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryExpress_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryExpress_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryExpressDesc, proto_ff_s::E_MarryExpress_s, E_MarryExpress, MAX_MARRY_EXPRESS_NUM);
DECLARE_IDCREATE(MarryExpressDesc);
};
