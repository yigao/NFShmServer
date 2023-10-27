#include "WashpartyDescEx.h"

WashpartyDescEx::WashpartyDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

WashpartyDescEx::~WashpartyDescEx()
{
}

int WashpartyDescEx::CreateInit()
{
	return 0;
}

int WashpartyDescEx::ResumeInit()
{
	return 0;
}

int WashpartyDescEx::Load()
{
	return 0;
}

int WashpartyDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

