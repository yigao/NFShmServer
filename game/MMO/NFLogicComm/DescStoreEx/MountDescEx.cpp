#include "MountDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(MountDescEx, EOT_CONST_MOUNT_DESC_EX_ID, NFShmObj)

MountDescEx::MountDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MountDescEx::~MountDescEx()
{
}

int MountDescEx::CreateInit()
{
	return 0;
}

int MountDescEx::ResumeInit()
{
	return 0;
}

int MountDescEx::Load()
{
	return 0;
}

int MountDescEx::PrepareReload()
{
	return 0;
}

int MountDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

