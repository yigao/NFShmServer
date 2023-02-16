#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GMCommand_s.h"

#define MAX_GMCOMMAND_GMCOMMAND_NUM 40

class GmcommandGmcommandDesc : public NFIDescStore
{
public:
	GmcommandGmcommandDesc();
	virtual ~GmcommandGmcommandDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GmcommandGmcommand_s* GetDesc(int id) const;
	proto_ff_s::E_GmcommandGmcommand_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GmcommandGmcommand_s, GMCommandGMCommand, MAX_GMCOMMAND_GMCOMMAND_NUM);
DECLARE_IDCREATE(GmcommandGmcommandDesc);
};
