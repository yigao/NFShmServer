#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mofa_s.h"

#define MAX_MOFA_SETUP_NUM 16

class MofaSetupDesc : public NFIDescStore
{
public:
	MofaSetupDesc();
	virtual ~MofaSetupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MofaSetup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MofaSetup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MofaSetup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MofaSetup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MofaSetupDesc, proto_ff_s::E_MofaSetup_s, E_MofaSetup, MAX_MOFA_SETUP_NUM);
DECLARE_IDCREATE(MofaSetupDesc);
};
