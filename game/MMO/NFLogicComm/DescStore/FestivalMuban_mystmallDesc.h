#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_MYSTMALL_NUM 8

class FestivalMuban_mystmallDesc : public NFIDescTemplate<FestivalMuban_mystmallDesc, proto_ff_s::E_FestivalMuban_mystmall_s, EOT_CONST_FESTIVAL_MUBAN_MYSTMALL_DESC_ID, MAX_FESTIVAL_MUBAN_MYSTMALL_NUM>
{
public:
	FestivalMuban_mystmallDesc();
	virtual ~FestivalMuban_mystmallDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
