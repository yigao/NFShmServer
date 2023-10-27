#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_PREFIXNAME_NUM 16

class GodevilPrefixnameDesc : public NFIDescTemplate<GodevilPrefixnameDesc, proto_ff_s::E_GodevilPrefixname_s, EOT_CONST_GODEVIL_PREFIXNAME_DESC_ID, MAX_GODEVIL_PREFIXNAME_NUM>
{
public:
	GodevilPrefixnameDesc();
	virtual ~GodevilPrefixnameDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
