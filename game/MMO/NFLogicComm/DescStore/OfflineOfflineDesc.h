#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Offline_s.h"

#define MAX_OFFLINE_OFFLINE_NUM 2048

class OfflineOfflineDesc : public NFIDescTemplate<OfflineOfflineDesc, proto_ff_s::E_OfflineOffline_s, EOT_CONST_OFFLINE_OFFLINE_DESC_ID, MAX_OFFLINE_OFFLINE_NUM>
{
public:
	OfflineOfflineDesc();
	virtual ~OfflineOfflineDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
