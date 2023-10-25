#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_LGLVLUP_NUM 1024

class XiuzhenLglvlupDesc : public NFIDescStore
{
public:
	XiuzhenLglvlupDesc();
	virtual ~XiuzhenLglvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenLglvlup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenLglvlup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenLglvlup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenLglvlup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenLglvlupDesc, proto_ff_s::E_XiuzhenLglvlup_s, E_XiuzhenLglvlup, MAX_XIUZHEN_LGLVLUP_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenLglvlupDesc);
};
