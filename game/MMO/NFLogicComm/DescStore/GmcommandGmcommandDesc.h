#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gmcommand_s.h"

#define MAX_GMCOMMAND_GMCOMMAND_NUM 64

class GmcommandGmcommandDesc : public NFIDescStore
{
public:
	GmcommandGmcommandDesc();
	virtual ~GmcommandGmcommandDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GmcommandGmcommand_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GmcommandGmcommand_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GmcommandGmcommand_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GmcommandGmcommand_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GmcommandGmcommandDesc, proto_ff_s::E_GmcommandGmcommand_s, E_GmcommandGmcommand, MAX_GMCOMMAND_GMCOMMAND_NUM);
DECLARE_IDCREATE_GLOBAL(GmcommandGmcommandDesc);
};
