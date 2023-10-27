#include "FacadeDescEx.h"

FacadeDescEx::FacadeDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FacadeDescEx::~FacadeDescEx()
{
}

int FacadeDescEx::CreateInit()
{
	return 0;
}

int FacadeDescEx::ResumeInit()
{
	return 0;
}

int FacadeDescEx::Load()
{
	return 0;
}

int FacadeDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

