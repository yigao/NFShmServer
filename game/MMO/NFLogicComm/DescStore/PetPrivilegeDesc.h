#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_PRIVILEGE_NUM 2

class PetPrivilegeDesc : public NFIDescTemplate<PetPrivilegeDesc, proto_ff_s::E_PetPrivilege_s, EOT_CONST_PET_PRIVILEGE_DESC_ID, MAX_PET_PRIVILEGE_NUM>
{
public:
	PetPrivilegeDesc();
	virtual ~PetPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
