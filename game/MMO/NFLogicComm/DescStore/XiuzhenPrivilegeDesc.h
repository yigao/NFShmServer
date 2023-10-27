#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_PRIVILEGE_NUM 8

class XiuzhenPrivilegeDesc : public NFIDescTemplate<XiuzhenPrivilegeDesc, proto_ff_s::E_XiuzhenPrivilege_s, EOT_CONST_XIUZHEN_PRIVILEGE_DESC_ID, MAX_XIUZHEN_PRIVILEGE_NUM>
{
public:
	XiuzhenPrivilegeDesc();
	virtual ~XiuzhenPrivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
