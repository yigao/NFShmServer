#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GFLVLUP_NUM 16384

class XiuzhenGflvlupDesc : public NFIDescStore
{
public:
	XiuzhenGflvlupDesc();
	virtual ~XiuzhenGflvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenGflvlup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenGflvlup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenGflvlup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenGflvlup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenGflvlupDesc, proto_ff_s::E_XiuzhenGflvlup_s, E_XiuzhenGflvlup, MAX_XIUZHEN_GFLVLUP_NUM);
DECLARE_IDCREATE(XiuzhenGflvlupDesc);
};
