#include "PeractivityPeractivityDesc.h"
#include "FunctionunlockFunctionunlockDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

PeractivityPeractivityDesc::PeractivityPeractivityDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

PeractivityPeractivityDesc::~PeractivityPeractivityDesc()
{
}

int PeractivityPeractivityDesc::CreateInit()
{
	return 0;
}

int PeractivityPeractivityDesc::ResumeInit()
{
	return 0;
}

int PeractivityPeractivityDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "PeractivityPeractivityDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_PeractivityPeractivity table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_peractivityperactivity_list_size() < 0) || (table.e_peractivityperactivity_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_peractivityperactivity_list_size());
		return -2;
	}

	for (int i = 0; i < (int)table.e_peractivityperactivity_list_size(); i++)
	{
		const proto_ff::E_PeractivityPeractivity& desc = table.e_peractivityperactivity_list(i);
		if (desc.has_m_activeid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_activeid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_activeid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_activeid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_activeid());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() >= m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_activeid()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_activeid());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_activeid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_activeid());
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_peractivityperactivity_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int PeractivityPeractivityDesc::CheckWhenAllDataLoaded()
{
	int result = 0;
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		CHECK_EXPR_MSG_RESULT((pDesc->m_functionID <= 0 || FunctionunlockFunctionunlockDesc::Instance()->GetDesc(pDesc->m_functionID)), result, "can't find the functionID:{} in the  excel:functionunlock sheet:functionUnlock", pDesc->m_functionID);
	}
	return result;
}

