#include "CloudpeakDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(CloudpeakDescEx, EOT_CONST_CLOUDPEAK_DESC_EX_ID, NFShmObj)

CloudpeakDescEx::CloudpeakDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

CloudpeakDescEx::~CloudpeakDescEx()
{
}

int CloudpeakDescEx::CreateInit()
{
	return 0;
}

int CloudpeakDescEx::ResumeInit()
{
	return 0;
}

int CloudpeakDescEx::Load()
{
	return 0;
}

int CloudpeakDescEx::PrepareReload()
{
	return 0;
}

int CloudpeakDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

