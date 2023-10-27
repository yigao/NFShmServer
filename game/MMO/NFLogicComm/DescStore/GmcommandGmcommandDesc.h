#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Gmcommand_s.h"

#define MAX_GMCOMMAND_GMCOMMAND_NUM 64

class GmcommandGmcommandDesc : public NFIDescTemplate<GmcommandGmcommandDesc, proto_ff_s::E_GmcommandGmcommand_s, EOT_CONST_GMCOMMAND_GMCOMMAND_DESC_ID, MAX_GMCOMMAND_GMCOMMAND_NUM>
{
public:
	GmcommandGmcommandDesc();
	virtual ~GmcommandGmcommandDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
