#include "AudioDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(AudioDescEx, EOT_CONST_AUDIO_DESC_EX_ID, NFShmObj)

AudioDescEx::AudioDescEx():NFIDescStoreEx()
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

int AudioDescEx::PrepareReload()
{
	return 0;
}

int AudioDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

