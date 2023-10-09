#include "PointDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(PointDescEx, EOT_CONST_POINT_DESC_EX_ID, NFShmObj)

PointDescEx::PointDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PointDescEx::~PointDescEx()
{
}

int PointDescEx::CreateInit()
{
	return 0;
}

int PointDescEx::ResumeInit()
{
	return 0;
}

int PointDescEx::Load()
{
	return 0;
}

int PointDescEx::PrepareReload()
{
	return 0;
}

int PointDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

