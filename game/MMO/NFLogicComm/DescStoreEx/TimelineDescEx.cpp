#include "TimelineDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(TimelineDescEx, EOT_CONST_TIMELINE_DESC_EX_ID, NFShmObj)

TimelineDescEx::TimelineDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TimelineDescEx::~TimelineDescEx()
{
}

int TimelineDescEx::CreateInit()
{
	return 0;
}

int TimelineDescEx::ResumeInit()
{
	return 0;
}

int TimelineDescEx::Load()
{
	return 0;
}

int TimelineDescEx::PrepareReload()
{
	return 0;
}

int TimelineDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

