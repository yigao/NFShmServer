#include "AiDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(AiDescEx, EOT_CONST_AI_DESC_EX_ID, NFShmObj)

AiDescEx::AiDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AiDescEx::~AiDescEx()
{
}

int AiDescEx::CreateInit()
{
	return 0;
}

int AiDescEx::ResumeInit()
{
	return 0;
}

int AiDescEx::Load()
{
	return 0;
}

int AiDescEx::PrepareReload()
{
	return 0;
}

int AiDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

