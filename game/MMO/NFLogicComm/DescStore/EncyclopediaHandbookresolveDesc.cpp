#include "EncyclopediaHandbookresolveDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

EncyclopediaHandbookresolveDesc::EncyclopediaHandbookresolveDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

EncyclopediaHandbookresolveDesc::~EncyclopediaHandbookresolveDesc()
{
}

int EncyclopediaHandbookresolveDesc::CreateInit()
{
	return 0;
}

int EncyclopediaHandbookresolveDesc::ResumeInit()
{
	return 0;
}

int EncyclopediaHandbookresolveDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "EncyclopediaHandbookresolveDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_EncyclopediaHandbookresolve table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_encyclopediahandbookresolve_list_size() < 0) || (table.e_encyclopediahandbookresolve_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_encyclopediahandbookresolve_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_encyclopediahandbookresolve_list_size(); i++)
	{
		const proto_ff::E_EncyclopediaHandbookresolve& desc = table.e_encyclopediahandbookresolve_list(i);
		if (desc.m_handbookquality() == 0 || desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_handbookquality()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_handbookquality());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_handbookquality());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_handbookquality());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_handbookquality()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_handbookquality());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_handbookquality()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_handbookquality());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_encyclopediahandbookresolve_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int EncyclopediaHandbookresolveDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

