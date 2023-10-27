#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Teleport_s.h"

#define MAX_TELEPORT_TELEPORT_NUM 16

class TeleportTeleportDesc : public NFIDescTemplate<TeleportTeleportDesc, proto_ff_s::E_TeleportTeleport_s, EOT_CONST_TELEPORT_TELEPORT_DESC_ID, MAX_TELEPORT_TELEPORT_NUM>
{
public:
	TeleportTeleportDesc();
	virtual ~TeleportTeleportDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
