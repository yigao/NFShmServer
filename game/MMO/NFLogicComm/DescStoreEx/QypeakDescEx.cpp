#include "QypeakDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(QypeakDescEx, EOT_CONST_QYPEAK_DESC_EX_ID, NFShmObj)

QypeakDescEx::QypeakDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

QypeakDescEx::~QypeakDescEx()
{
}

int QypeakDescEx::CreateInit()
{
	return 0;
}

int QypeakDescEx::ResumeInit()
{
	return 0;
}

int QypeakDescEx::Load()
{
	return 0;
}

int QypeakDescEx::PrepareReload()
{
	return 0;
}

int QypeakDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

