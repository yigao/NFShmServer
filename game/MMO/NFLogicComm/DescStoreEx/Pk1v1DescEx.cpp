#include "Pk1v1DescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(Pk1v1DescEx, EOT_CONST_PK1V1_DESC_EX_ID, NFShmObj)

Pk1v1DescEx::Pk1v1DescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

Pk1v1DescEx::~Pk1v1DescEx()
{
}

int Pk1v1DescEx::CreateInit()
{
	return 0;
}

int Pk1v1DescEx::ResumeInit()
{
	return 0;
}

int Pk1v1DescEx::Load()
{
	return 0;
}

int Pk1v1DescEx::PrepareReload()
{
	return 0;
}

int Pk1v1DescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

