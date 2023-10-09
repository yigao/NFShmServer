#include "AttributeDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(AttributeDescEx, EOT_CONST_ATTRIBUTE_DESC_EX_ID, NFShmObj)

AttributeDescEx::AttributeDescEx():NFIDescStoreEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

AttributeDescEx::~AttributeDescEx()
{
}

int AttributeDescEx::CreateInit()
{
	return 0;
}

int AttributeDescEx::ResumeInit()
{
	return 0;
}

int AttributeDescEx::Load()
{
	return 0;
}

int AttributeDescEx::PrepareReload()
{
	return 0;
}

int AttributeDescEx::CheckWhenAllDataLoaded()
{
	return 0;
}

