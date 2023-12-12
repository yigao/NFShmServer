#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_MALLTYPE_TAB_NUM 16

class MallMalltype_tabDesc : public NFIDescTemplate<MallMalltype_tabDesc, proto_ff_s::E_MallMalltype_tab_s, EOT_CONST_MALL_MALLTYPE_TAB_DESC_ID, MAX_MALL_MALLTYPE_TAB_NUM>
{
public:
	MallMalltype_tabDesc();
	virtual ~MallMalltype_tabDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
