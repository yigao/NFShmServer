#include "PetDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(PetDescEx, EOT_CONST_PET_DESC_EX_ID, NFShmObj)

PetDescEx::PetDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PetDescEx::~PetDescEx()
{
}

int PetDescEx::CreateInit()
{
	return 0;
}

int PetDescEx::ResumeInit()
{
	return 0;
}

int PetDescEx::Load()
{
	return 0;
}

int PetDescEx::PrepareReload()
{
	return 0;
}

int PetDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

