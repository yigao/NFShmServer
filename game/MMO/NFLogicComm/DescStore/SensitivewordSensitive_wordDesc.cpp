#include "SensitivewordSensitive_wordDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(SensitivewordSensitive_wordDesc, EOT_CONST_SENSITIVEWORD_SENSITIVE_WORD_DESC_ID, NFShmObj)

SensitivewordSensitive_wordDesc::SensitivewordSensitive_wordDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

SensitivewordSensitive_wordDesc::~SensitivewordSensitive_wordDesc()
{
}

int SensitivewordSensitive_wordDesc::CreateInit()
{
	Initialize();
	return 0;
}

int SensitivewordSensitive_wordDesc::ResumeInit()
{
	return 0;
}

int SensitivewordSensitive_wordDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_sensitivewordsensitive_word table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.sensitivewordsensitive_word_list_size() < 0) || (table.sensitivewordsensitive_word_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.sensitivewordsensitive_word_list_size());
		return -2;
	}

	for (int i = 0; i < table.sensitivewordsensitive_word_list_size(); i++)
	{
		const proto_ff::sensitivewordsensitive_word& desc = table.sensitivewordsensitive_word_list(i);
		auto pDesc = m_astDesc.Insert(desc.id());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.sensitivewordsensitive_word_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int SensitivewordSensitive_wordDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::sensitivewordsensitive_word_s * SensitivewordSensitive_wordDesc::CetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::sensitivewordsensitive_word_s * SensitivewordSensitive_wordDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

