#include "DragonsoulDescEx.h"

DragonsoulDescEx::DragonsoulDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DragonsoulDescEx::~DragonsoulDescEx()
{
}

int DragonsoulDescEx::CreateInit()
{
	return 0;
}

int DragonsoulDescEx::ResumeInit()
{
	return 0;
}

int DragonsoulDescEx::Load()
{
	return 0;
}

int DragonsoulDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

