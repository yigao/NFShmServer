#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GFSTAGEUP_NUM 64

class XiuzhenGfstageupDesc : public NFIDescStore
{
public:
	XiuzhenGfstageupDesc();
	virtual ~XiuzhenGfstageupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenGfstageup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenGfstageup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenGfstageup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenGfstageup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenGfstageupDesc, proto_ff_s::E_XiuzhenGfstageup_s, E_XiuzhenGfstageup, MAX_XIUZHEN_GFSTAGEUP_NUM);
DECLARE_IDCREATE(XiuzhenGfstageupDesc);
};
