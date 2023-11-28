#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_MYSTMALL_MALL_NUM 32

class FestivalMuban_mystmall_mallDesc : public NFIDescTemplate<FestivalMuban_mystmall_mallDesc, proto_ff_s::E_FestivalMuban_mystmall_mall_s, EOT_CONST_FESTIVAL_MUBAN_MYSTMALL_MALL_DESC_ID, MAX_FESTIVAL_MUBAN_MYSTMALL_MALL_NUM>
{
public:
	FestivalMuban_mystmall_mallDesc();
	virtual ~FestivalMuban_mystmall_mallDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
