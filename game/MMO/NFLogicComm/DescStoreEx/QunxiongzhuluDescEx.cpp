#include "QunxiongzhuluDescEx.h"

QunxiongzhuluDescEx::QunxiongzhuluDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

QunxiongzhuluDescEx::~QunxiongzhuluDescEx()
{
}

int QunxiongzhuluDescEx::CreateInit()
{
	return 0;
}

int QunxiongzhuluDescEx::ResumeInit()
{
	return 0;
}

int QunxiongzhuluDescEx::Load()
{
	return 0;
}

int QunxiongzhuluDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

