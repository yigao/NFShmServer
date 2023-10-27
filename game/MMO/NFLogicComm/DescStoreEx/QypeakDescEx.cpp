#include "QypeakDescEx.h"

QypeakDescEx::QypeakDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

QypeakDescEx::~QypeakDescEx()
{
}

int QypeakDescEx::CreateInit()
{
	return 0;
}

int QypeakDescEx::ResumeInit()
{
	return 0;
}

int QypeakDescEx::Load()
{
	return 0;
}

int QypeakDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

