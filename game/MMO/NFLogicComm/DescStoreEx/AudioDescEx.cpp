#include "AudioDescEx.h"

AudioDescEx::AudioDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AudioDescEx::~AudioDescEx()
{
}

int AudioDescEx::CreateInit()
{
	return 0;
}

int AudioDescEx::ResumeInit()
{
	return 0;
}

int AudioDescEx::Load()
{
	return 0;
}

int AudioDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

