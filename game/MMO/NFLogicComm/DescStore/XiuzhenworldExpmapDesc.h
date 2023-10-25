#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenworld_s.h"

#define MAX_XIUZHENWORLD_EXPMAP_NUM 16

class XiuzhenworldExpmapDesc : public NFIDescStore
{
public:
	XiuzhenworldExpmapDesc();
	virtual ~XiuzhenworldExpmapDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenworldExpmap_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenworldExpmap_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenworldExpmap_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenworldExpmap_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenworldExpmapDesc, proto_ff_s::E_XiuzhenworldExpmap_s, E_XiuzhenworldExpmap, MAX_XIUZHENWORLD_EXPMAP_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenworldExpmapDesc);
};
