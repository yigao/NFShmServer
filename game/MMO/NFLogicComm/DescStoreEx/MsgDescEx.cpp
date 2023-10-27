#include "MsgDescEx.h"

MsgDescEx::MsgDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MsgDescEx::~MsgDescEx()
{
}

int MsgDescEx::CreateInit()
{
	return 0;
}

int MsgDescEx::ResumeInit()
{
	return 0;
}

int MsgDescEx::Load()
{
	return 0;
}

int MsgDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

