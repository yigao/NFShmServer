#include "DragonsoulDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(DragonsoulDescEx, EOT_CONST_DRAGONSOUL_DESC_EX_ID, NFShmObj)

DragonsoulDescEx::DragonsoulDescEx():NFIDescStoreEx()
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

int DragonsoulDescEx::PrepareReload()
{
	return 0;
}

int DragonsoulDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

