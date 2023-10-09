#include "MapDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(MapDescEx, EOT_CONST_MAP_DESC_EX_ID, NFShmObj)

MapDescEx::MapDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

MapDescEx::~MapDescEx()
{
}

int MapDescEx::CreateInit()
{
	return 0;
}

int MapDescEx::ResumeInit()
{
	return 0;
}

int MapDescEx::Load()
{
	return 0;
}

int MapDescEx::PrepareReload()
{
	return 0;
}

int MapDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

