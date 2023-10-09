#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_ATT_NUM 2048

class AncientgodAttDesc : public NFIDescStore
{
public:
	AncientgodAttDesc();
	virtual ~AncientgodAttDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodAtt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodAtt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodAtt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodAtt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodAttDesc, proto_ff_s::E_AncientgodAtt_s, E_AncientgodAtt, MAX_ANCIENTGOD_ATT_NUM);
DECLARE_IDCREATE(AncientgodAttDesc);
};
