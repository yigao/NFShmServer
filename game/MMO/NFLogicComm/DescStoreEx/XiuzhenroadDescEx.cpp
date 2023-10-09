#include "XiuzhenroadDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(XiuzhenroadDescEx, EOT_CONST_XIUZHENROAD_DESC_EX_ID, NFShmObj)

XiuzhenroadDescEx::XiuzhenroadDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenroadDescEx::~XiuzhenroadDescEx()
{
}

int XiuzhenroadDescEx::CreateInit()
{
	return 0;
}

int XiuzhenroadDescEx::ResumeInit()
{
	return 0;
}

int XiuzhenroadDescEx::Load()
{
	return 0;
}

int XiuzhenroadDescEx::PrepareReload()
{
	return 0;
}

int XiuzhenroadDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

