#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Nickgod_s.h"

#define MAX_NICKGOD_PRIVILEGE_NUM 16

class NickgodPrivilegeDesc : public NFIDescTemplate<NickgodPrivilegeDesc, proto_ff_s::E_NickgodPrivilege_s, EOT_CONST_NICKGOD_PRIVILEGE_DESC_ID, MAX_NICKGOD_PRIVILEGE_NUM>
{
public:
	NickgodPrivilegeDesc();
	virtual ~NickgodPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};