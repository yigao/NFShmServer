#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_JMMERGEUP_NUM 32

class XiuzhenJmmergeupDesc : public NFIDescTemplate<XiuzhenJmmergeupDesc, proto_ff_s::E_XiuzhenJmmergeup_s, EOT_CONST_XIUZHEN_JMMERGEUP_DESC_ID, MAX_XIUZHEN_JMMERGEUP_NUM>
{
public:
	XiuzhenJmmergeupDesc();
	virtual ~XiuzhenJmmergeupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
