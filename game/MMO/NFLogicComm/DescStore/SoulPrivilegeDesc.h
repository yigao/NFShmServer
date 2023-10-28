#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_PRIVILEGE_NUM 4

class SoulPrivilegeDesc : public NFIDescTemplate<SoulPrivilegeDesc, proto_ff_s::E_SoulPrivilege_s, EOT_CONST_SOUL_PRIVILEGE_DESC_ID, MAX_SOUL_PRIVILEGE_NUM>
{
public:
	SoulPrivilegeDesc();
	virtual ~SoulPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
