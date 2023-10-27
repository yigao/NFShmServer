#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Box_s.h"

#define MAX_BOX_BOXDATA_NUM 4096

class BoxBoxdataDesc : public NFIDescTemplate<BoxBoxdataDesc, proto_ff_s::E_BoxBoxdata_s, EOT_CONST_BOX_BOXDATA_DESC_ID, MAX_BOX_BOXDATA_NUM>
{
public:
	BoxBoxdataDesc();
	virtual ~BoxBoxdataDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
