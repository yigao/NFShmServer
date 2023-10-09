#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_AWAKEN_NUM 512

class EquipimproveAwakenDesc : public NFIDescStore
{
public:
	EquipimproveAwakenDesc();
	virtual ~EquipimproveAwakenDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipimproveAwaken_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipimproveAwaken_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipimproveAwaken_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipimproveAwaken_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipimproveAwakenDesc, proto_ff_s::E_EquipimproveAwaken_s, E_EquipimproveAwaken, MAX_EQUIPIMPROVE_AWAKEN_NUM);
DECLARE_IDCREATE(EquipimproveAwakenDesc);
};
