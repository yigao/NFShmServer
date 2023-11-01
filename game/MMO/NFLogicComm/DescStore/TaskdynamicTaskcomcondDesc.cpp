#include "TaskdynamicTaskcomcondDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

TaskdynamicTaskcomcondDesc::TaskdynamicTaskcomcondDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskdynamicTaskcomcondDesc::~TaskdynamicTaskcomcondDesc()
{
}

int TaskdynamicTaskcomcondDesc::CreateInit()
{
	return 0;
}

int TaskdynamicTaskcomcondDesc::ResumeInit()
{
	return 0;
}

int TaskdynamicTaskcomcondDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "TaskdynamicTaskcomcondDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_TaskdynamicTaskcomcond table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_taskdynamictaskcomcond_list_size() < 0) || (table.e_taskdynamictaskcomcond_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_taskdynamictaskcomcond_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_taskdynamictaskcomcond_list_size(); i++)
	{
		const proto_ff::E_TaskdynamicTaskcomcond& desc = table.e_taskdynamictaskcomcond_list(i);
		if (desc.m_comcondid() == 0 || desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_comcondid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_comcondid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_comcondid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_comcondid());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_comcondid()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_comcondid());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_comcondid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_comcondid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_taskdynamictaskcomcond_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int TaskdynamicTaskcomcondDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

