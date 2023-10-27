#include "MeditationDescEx.h"

MeditationDescEx::MeditationDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MeditationDescEx::~MeditationDescEx()
{
}

int MeditationDescEx::CreateInit()
{
	return 0;
}

int MeditationDescEx::ResumeInit()
{
	return 0;
}

int MeditationDescEx::Load()
{
	return 0;
}

int MeditationDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

