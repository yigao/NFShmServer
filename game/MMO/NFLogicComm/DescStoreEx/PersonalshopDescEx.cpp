#include "PersonalshopDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(PersonalshopDescEx, EOT_CONST_PERSONALSHOP_DESC_EX_ID, NFShmObj)

PersonalshopDescEx::PersonalshopDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PersonalshopDescEx::~PersonalshopDescEx()
{
}

int PersonalshopDescEx::CreateInit()
{
	return 0;
}

int PersonalshopDescEx::ResumeInit()
{
	return 0;
}

int PersonalshopDescEx::Load()
{
	return 0;
}

int PersonalshopDescEx::PrepareReload()
{
	return 0;
}

int PersonalshopDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

