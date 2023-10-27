#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_LGLVLUP_NUM 1024

class XiuzhenLglvlupDesc : public NFIDescTemplate<XiuzhenLglvlupDesc, proto_ff_s::E_XiuzhenLglvlup_s, EOT_CONST_XIUZHEN_LGLVLUP_DESC_ID, MAX_XIUZHEN_LGLVLUP_NUM>
{
public:
	XiuzhenLglvlupDesc();
	virtual ~XiuzhenLglvlupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
