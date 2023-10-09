#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMLVLUP_NUM 8192

class XiuzhenJmlvlupDesc : public NFIDescStore
{
public:
	XiuzhenJmlvlupDesc();
	virtual ~XiuzhenJmlvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenJmlvlup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenJmlvlup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenJmlvlup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenJmlvlup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenJmlvlupDesc, proto_ff_s::E_XiuzhenJmlvlup_s, E_XiuzhenJmlvlup, MAX_XIUZHEN_JMLVLUP_NUM);
DECLARE_IDCREATE(XiuzhenJmlvlupDesc);
};
