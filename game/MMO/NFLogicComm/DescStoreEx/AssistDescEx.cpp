#include "AssistDescEx.h"

AssistDescEx::AssistDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AssistDescEx::~AssistDescEx()
{
}

int AssistDescEx::CreateInit()
{
	return 0;
}

int AssistDescEx::ResumeInit()
{
	return 0;
}

int AssistDescEx::Load()
{
	return 0;
}

int AssistDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

