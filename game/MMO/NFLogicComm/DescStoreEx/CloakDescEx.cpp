#include "CloakDescEx.h"

CloakDescEx::CloakDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

CloakDescEx::~CloakDescEx()
{
}

int CloakDescEx::CreateInit()
{
	return 0;
}

int CloakDescEx::ResumeInit()
{
	return 0;
}

int CloakDescEx::Load()
{
	return 0;
}

int CloakDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

