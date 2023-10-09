#include "SensitivewordDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(SensitivewordDescEx, EOT_CONST_SENSITIVEWORD_DESC_EX_ID, NFShmObj)

SensitivewordDescEx::SensitivewordDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SensitivewordDescEx::~SensitivewordDescEx()
{
}

int SensitivewordDescEx::CreateInit()
{
	return 0;
}

int SensitivewordDescEx::ResumeInit()
{
	return 0;
}

int SensitivewordDescEx::Load()
{
	return 0;
}

int SensitivewordDescEx::PrepareReload()
{
	return 0;
}

int SensitivewordDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

