#include "Pk3v3DescEx.h"

Pk3v3DescEx::Pk3v3DescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

Pk3v3DescEx::~Pk3v3DescEx()
{
}

int Pk3v3DescEx::CreateInit()
{
	return 0;
}

int Pk3v3DescEx::ResumeInit()
{
	return 0;
}

int Pk3v3DescEx::Load()
{
	return 0;
}

int Pk3v3DescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

