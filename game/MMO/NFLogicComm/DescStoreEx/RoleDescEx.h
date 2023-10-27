#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class RoleDescEx : public NFShmObjGlobalTemplate<RoleDescEx, EOT_CONST_ROLE_DESC_EX_ID, NFIDescStoreEx>
{
public:
	RoleDescEx();
	virtual ~RoleDescEx();
	int CreateInit();
	int ResumeInit();
public:
    uint32_t MaxLevel() const { return 1000; }
public:
    virtual int Load() override;
    virtual int CheckWhenAllDataLoaded() override;
};
