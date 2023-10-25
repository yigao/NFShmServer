#include "XiuzhenworldDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE_GLOBAL(XiuzhenworldDescEx, EOT_CONST_XIUZHENWORLD_DESC_EX_ID, NFShmObj)

XiuzhenworldDescEx::XiuzhenworldDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

XiuzhenworldDescEx::~XiuzhenworldDescEx()
{
}

int XiuzhenworldDescEx::CreateInit()
{
	return 0;
}

int XiuzhenworldDescEx::ResumeInit()
{
	return 0;
}

int XiuzhenworldDescEx::Load()
{
	return 0;
}

int XiuzhenworldDescEx::PrepareReload()
{
	return 0;
}

int XiuzhenworldDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

