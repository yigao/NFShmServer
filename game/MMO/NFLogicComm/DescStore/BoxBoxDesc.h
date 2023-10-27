#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Box_s.h"

#define MAX_BOX_BOX_NUM 4096

class BoxBoxDesc : public NFIDescTemplate<BoxBoxDesc, proto_ff_s::E_BoxBox_s, EOT_CONST_BOX_BOX_DESC_ID, MAX_BOX_BOX_NUM>
{
public:
	BoxBoxDesc();
	virtual ~BoxBoxDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
