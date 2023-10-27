#include "MarryDescEx.h"

MarryDescEx::MarryDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MarryDescEx::~MarryDescEx()
{
}

int MarryDescEx::CreateInit()
{
	return 0;
}

int MarryDescEx::ResumeInit()
{
	return 0;
}

int MarryDescEx::Load()
{
	return 0;
}

int MarryDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

