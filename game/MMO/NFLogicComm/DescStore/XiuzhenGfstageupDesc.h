#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_GFSTAGEUP_NUM 64

class XiuzhenGfstageupDesc : public NFIDescTemplate<XiuzhenGfstageupDesc, proto_ff_s::E_XiuzhenGfstageup_s, EOT_CONST_XIUZHEN_GFSTAGEUP_DESC_ID, MAX_XIUZHEN_GFSTAGEUP_NUM>
{
public:
	XiuzhenGfstageupDesc();
	virtual ~XiuzhenGfstageupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
