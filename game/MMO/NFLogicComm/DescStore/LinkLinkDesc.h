#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Link_s.h"

#define MAX_LINK_LINK_NUM 512

class LinkLinkDesc : public NFIDescTemplate<LinkLinkDesc, proto_ff_s::E_LinkLink_s, EOT_CONST_LINK_LINK_DESC_ID, MAX_LINK_LINK_NUM>
{
public:
	LinkLinkDesc();
	virtual ~LinkLinkDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
