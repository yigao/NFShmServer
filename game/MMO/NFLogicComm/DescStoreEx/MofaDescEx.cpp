#include "MofaDescEx.h"

MofaDescEx::MofaDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MofaDescEx::~MofaDescEx()
{
}

int MofaDescEx::CreateInit()
{
	return 0;
}

int MofaDescEx::ResumeInit()
{
	return 0;
}

int MofaDescEx::Load()
{
	return 0;
}

int MofaDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

