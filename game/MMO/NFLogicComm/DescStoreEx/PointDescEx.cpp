#include "PointDescEx.h"

PointDescEx::PointDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PointDescEx::~PointDescEx()
{
}

int PointDescEx::CreateInit()
{
	return 0;
}

int PointDescEx::ResumeInit()
{
	return 0;
}

int PointDescEx::Load()
{
	return 0;
}

int PointDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

