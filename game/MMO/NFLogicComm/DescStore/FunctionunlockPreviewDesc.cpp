#include "FunctionunlockPreviewDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

FunctionunlockPreviewDesc::FunctionunlockPreviewDesc()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

FunctionunlockPreviewDesc::~FunctionunlockPreviewDesc()
{
}

int FunctionunlockPreviewDesc::CreateInit()
{
	return 0;
}

int FunctionunlockPreviewDesc::ResumeInit()
{
	return 0;
}

int FunctionunlockPreviewDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FunctionunlockPreviewDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_FunctionunlockPreview table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.e_functionunlockpreview_list_size() < 0) || (table.e_functionunlockpreview_list_size() > (int)(m_astDescMap.max_size())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.e_functionunlockpreview_list_size());
		return -2;
	}

	m_minId = INVALID_ID;
	for (int i = 0; i < (int)table.e_functionunlockpreview_list_size(); i++)
	{
		const proto_ff::E_FunctionunlockPreview& desc = table.e_functionunlockpreview_list(i);
		if (desc.has_m_functionid() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}

		if (m_minId == INVALID_ID)
		{
			m_minId = desc.m_functionid();
		}
		else
		{
			if (desc.m_functionid() < m_minId)
			{
				m_minId = desc.m_functionid();
			}
		}

		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		if (m_astDescMap.find(desc.m_functionid()) != m_astDescMap.end())
		{
			if (IsReloading())
			{
				auto pDesc = GetDesc(desc.m_functionid());
				NF_ASSERT_MSG(pDesc, "the desc:{} Reload, GetDesc Failed!, id:{}", GetClassName(), desc.m_functionid());
				pDesc->read_from_pbmsg(desc);
			}
			else
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "the desc:{} id:{} exist", GetClassName(), desc.m_functionid());
			}
			continue;
		}
		CHECK_EXPR_ASSERT(m_astDescMap.size() < m_astDescMap.max_size(), -1, "m_astDescMap Space Not Enough");
		auto pDesc = &m_astDescMap[desc.m_functionid()];
		CHECK_EXPR_ASSERT(pDesc, -1, "m_astDescMap Insert Failed desc.id:{}", desc.m_functionid());
		pDesc->read_from_pbmsg(desc);
		CHECK_EXPR_ASSERT(GetDesc(desc.m_functionid()) == pDesc, -1, "GetDesc != pDesc, id:{}", desc.m_functionid());
	}

	for(int i = 0; i < (int)m_astDescIndex.size(); i++)
	{
		m_astDescIndex[i] = INVALID_ID;
	}

	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		int64_t index = (int64_t)iter->first - (int64_t)m_minId;
		if (index >= 0 && index < (int64_t)m_astDescIndex.size())
		{
			m_astDescIndex[index] = iter.m_curNode->m_self;
			CHECK_EXPR_ASSERT(iter == m_astDescMap.get_iterator(m_astDescIndex[index]), -1, "index error");
			CHECK_EXPR_ASSERT(GetDesc(iter->first) == &iter->second, -1, "GetDesc != iter->second, id:{}", iter->first);
		}
	}
	m_FunctionidIndexMap.clear();
	for(auto iter = m_astDescMap.begin(); iter != m_astDescMap.end(); iter++)
	{
		auto pDesc = &iter->second;
		CHECK_EXPR_ASSERT(m_FunctionidIndexMap.find(pDesc->m_functionId) == m_FunctionidIndexMap.end(), -1, "unique index:functionId repeat key:{}", pDesc->m_functionId);
		auto key_iter = m_FunctionidIndexMap.emplace_hint(pDesc->m_functionId, iter->first);
		CHECK_EXPR_ASSERT(key_iter != m_FunctionidIndexMap.end(), -1, "m_FunctionidIndexMap.emplace_hint Failed pDesc->m_functionId:{}, space not enough", pDesc->m_functionId);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.e_functionunlockpreview_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int FunctionunlockPreviewDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::E_FunctionunlockPreview_s* FunctionunlockPreviewDesc::GetDescByFunctionid(int64_t Functionid) const
{
	auto iter = m_FunctionidIndexMap.find(Functionid);
	if(iter != m_FunctionidIndexMap.end())
	{
		return GetDesc(iter->second);
	}
	return nullptr;
}

