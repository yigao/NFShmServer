#include "AiDescEx.h"

AiDescEx::AiDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AiDescEx::~AiDescEx()
{
}

int AiDescEx::CreateInit()
{
	return 0;
}

int AiDescEx::ResumeInit()
{
	return 0;
}

int AiDescEx::Load()
{
	return 0;
}

int AiDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

