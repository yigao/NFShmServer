#include "Pk1v1DescEx.h"

Pk1v1DescEx::Pk1v1DescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

Pk1v1DescEx::~Pk1v1DescEx()
{
}

int Pk1v1DescEx::CreateInit()
{
	return 0;
}

int Pk1v1DescEx::ResumeInit()
{
	return 0;
}

int Pk1v1DescEx::Load()
{
	return 0;
}

int Pk1v1DescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

