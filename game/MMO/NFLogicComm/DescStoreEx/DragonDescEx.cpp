#include "DragonDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(DragonDescEx, EOT_CONST_DRAGON_DESC_EX_ID, NFShmObj)

DragonDescEx::DragonDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

DragonDescEx::~DragonDescEx()
{
}

int DragonDescEx::CreateInit()
{
	return 0;
}

int DragonDescEx::ResumeInit()
{
	return 0;
}

int DragonDescEx::Load()
{
	return 0;
}

int DragonDescEx::PrepareReload()
{
	return 0;
}

int DragonDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

