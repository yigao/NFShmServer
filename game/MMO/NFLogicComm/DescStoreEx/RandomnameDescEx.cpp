#include "RandomnameDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(RandomnameDescEx, EOT_CONST_RANDOMNAME_DESC_EX_ID, NFShmObj)

RandomnameDescEx::RandomnameDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

RandomnameDescEx::~RandomnameDescEx()
{
}

int RandomnameDescEx::CreateInit()
{
	return 0;
}

int RandomnameDescEx::ResumeInit()
{
	return 0;
}

int RandomnameDescEx::Load()
{
	return 0;
}

int RandomnameDescEx::PrepareReload()
{
	return 0;
}

int RandomnameDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

