#include "Pk3v3DescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(Pk3v3DescEx, EOT_CONST_PK3V3_DESC_EX_ID, NFShmObj)

Pk3v3DescEx::Pk3v3DescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

Pk3v3DescEx::~Pk3v3DescEx()
{
}

int Pk3v3DescEx::CreateInit()
{
	return 0;
}

int Pk3v3DescEx::ResumeInit()
{
	return 0;
}

int Pk3v3DescEx::Load()
{
	return 0;
}

int Pk3v3DescEx::PrepareReload()
{
	return 0;
}

int Pk3v3DescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

