#include "JinglianDescEx.h"

JinglianDescEx::JinglianDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

JinglianDescEx::~JinglianDescEx()
{
}

int JinglianDescEx::CreateInit()
{
	return 0;
}

int JinglianDescEx::ResumeInit()
{
	return 0;
}

int JinglianDescEx::Load()
{
	return 0;
}

int JinglianDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

