#include "JinglianDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(JinglianDescEx, EOT_CONST_JINGLIAN_DESC_EX_ID, NFShmObj)

JinglianDescEx::JinglianDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

JinglianDescEx::~JinglianDescEx()
{
}

int JinglianDescEx::CreateInit()
{
	return 0;
}

int JinglianDescEx::ResumeInit()
{
	return 0;
}

int JinglianDescEx::Load()
{
	return 0;
}

int JinglianDescEx::PrepareReload()
{
	return 0;
}

int JinglianDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

