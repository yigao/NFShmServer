#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GB_LVLUP_NUM 2048

class XiuzhenGb_lvlupDesc : public NFIDescStore
{
public:
	XiuzhenGb_lvlupDesc();
	virtual ~XiuzhenGb_lvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenGb_lvlup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenGb_lvlup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenGb_lvlup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenGb_lvlup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenGb_lvlupDesc, proto_ff_s::E_XiuzhenGb_lvlup_s, E_XiuzhenGb_lvlup, MAX_XIUZHEN_GB_LVLUP_NUM);
DECLARE_IDCREATE(XiuzhenGb_lvlupDesc);
};
