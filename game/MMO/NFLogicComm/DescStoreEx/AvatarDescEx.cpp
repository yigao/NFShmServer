#include "AvatarDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(AvatarDescEx, EOT_CONST_AVATAR_DESC_EX_ID, NFShmObj)

AvatarDescEx::AvatarDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AvatarDescEx::~AvatarDescEx()
{
}

int AvatarDescEx::CreateInit()
{
	return 0;
}

int AvatarDescEx::ResumeInit()
{
	return 0;
}

int AvatarDescEx::Load()
{
	return 0;
}

int AvatarDescEx::PrepareReload()
{
	return 0;
}

int AvatarDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

