#include "EscortDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(EscortDescEx, EOT_CONST_ESCORT_DESC_EX_ID, NFShmObj)

EscortDescEx::EscortDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EscortDescEx::~EscortDescEx()
{
}

int EscortDescEx::CreateInit()
{
	return 0;
}

int EscortDescEx::ResumeInit()
{
	return 0;
}

int EscortDescEx::Load()
{
	return 0;
}

int EscortDescEx::PrepareReload()
{
	return 0;
}

int EscortDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

