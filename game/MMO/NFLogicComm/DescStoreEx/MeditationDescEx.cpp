#include "MeditationDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(MeditationDescEx, EOT_CONST_MEDITATION_DESC_EX_ID, NFShmObj)

MeditationDescEx::MeditationDescEx():NFIDescStoreEx()
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

int MeditationDescEx::PrepareReload()
{
	return 0;
}

int MeditationDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

