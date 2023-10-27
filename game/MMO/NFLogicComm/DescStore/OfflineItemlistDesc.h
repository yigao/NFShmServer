#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Offline_s.h"

#define MAX_OFFLINE_ITEMLIST_NUM 32

class OfflineItemlistDesc : public NFIDescTemplate<OfflineItemlistDesc, proto_ff_s::E_OfflineItemlist_s, EOT_CONST_OFFLINE_ITEMLIST_DESC_ID, MAX_OFFLINE_ITEMLIST_NUM>
{
public:
	OfflineItemlistDesc();
	virtual ~OfflineItemlistDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
