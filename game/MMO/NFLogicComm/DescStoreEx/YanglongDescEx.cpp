#include "YanglongDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(YanglongDescEx, EOT_CONST_YANGLONG_DESC_EX_ID, NFShmObj)

YanglongDescEx::YanglongDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

YanglongDescEx::~YanglongDescEx()
{
}

int YanglongDescEx::CreateInit()
{
	return 0;
}

int YanglongDescEx::ResumeInit()
{
	return 0;
}

int YanglongDescEx::Load()
{
	return 0;
}

int YanglongDescEx::PrepareReload()
{
	return 0;
}

int YanglongDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

