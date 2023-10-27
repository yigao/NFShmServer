#include "HeadportraitDescEx.h"

HeadportraitDescEx::HeadportraitDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

HeadportraitDescEx::~HeadportraitDescEx()
{
}

int HeadportraitDescEx::CreateInit()
{
	return 0;
}

int HeadportraitDescEx::ResumeInit()
{
	return 0;
}

int HeadportraitDescEx::Load()
{
	return 0;
}

int HeadportraitDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

