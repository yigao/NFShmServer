#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Wordshout_s.h"

#define MAX_WORDSHOUT_SHOUT_NUM 8

class WordshoutShoutDesc : public NFIDescTemplate<WordshoutShoutDesc, proto_ff_s::E_WordshoutShout_s, EOT_CONST_WORDSHOUT_SHOUT_DESC_ID, MAX_WORDSHOUT_SHOUT_NUM>
{
public:
	WordshoutShoutDesc();
	virtual ~WordshoutShoutDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
