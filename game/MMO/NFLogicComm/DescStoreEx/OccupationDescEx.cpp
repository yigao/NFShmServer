#include "OccupationDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(OccupationDescEx, EOT_CONST_OCCUPATION_DESC_EX_ID, NFShmObj)

OccupationDescEx::OccupationDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

OccupationDescEx::~OccupationDescEx()
{
}

int OccupationDescEx::CreateInit()
{
	return 0;
}

int OccupationDescEx::ResumeInit()
{
	return 0;
}

int OccupationDescEx::Load()
{
	return 0;
}

int OccupationDescEx::PrepareReload()
{
	return 0;
}

int OccupationDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

