#include "PetDescEx.h"

PetDescEx::PetDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PetDescEx::~PetDescEx()
{
}

int PetDescEx::CreateInit()
{
	return 0;
}

int PetDescEx::ResumeInit()
{
	return 0;
}

int PetDescEx::Load()
{
	return 0;
}

int PetDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

