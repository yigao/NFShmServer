#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Link_s.h"

#define MAX_LINK_IMAGELINK_NUM 64

class LinkImagelinkDesc : public NFIDescTemplate<LinkImagelinkDesc, proto_ff_s::E_LinkImagelink_s, EOT_CONST_LINK_IMAGELINK_DESC_ID, MAX_LINK_IMAGELINK_NUM>
{
public:
	LinkImagelinkDesc();
	virtual ~LinkImagelinkDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
