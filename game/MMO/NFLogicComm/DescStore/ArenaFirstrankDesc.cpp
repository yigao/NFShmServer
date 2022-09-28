#include "ArenaFirstrankDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(ArenaFirstrankDesc, EOT_CONST_ARENA_FIRSTRANK_DESC_ID, NFShmObj)

ArenaFirstrankDesc::ArenaFirstrankDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

ArenaFirstrankDesc::~ArenaFirstrankDesc()
{
}

int ArenaFirstrankDesc::CreateInit()
{
	Initialize();
	return 0;
}

int ArenaFirstrankDesc::ResumeInit()
{
	return 0;
}

int ArenaFirstrankDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_arenafirstrank table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", table.Utf8DebugString());

	if ((table.arenafirstrank_list_size() < 0) || (table.arenafirstrank_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "Invalid TotalNum:{}", table.arenafirstrank_list_size());
		return -2;
	}

	for (int i = 0; i < table.arenafirstrank_list_size(); i++)
	{
		const proto_ff::arenafirstrank& desc = table.arenafirstrank_list(i);
		if (desc.has_rankdown() == false && desc.ByteSize() == 0)
		{
			NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "the desc no value, {}", desc.Utf8DebugString());
			continue;
		}
		//NFLogTrace(NF_LOG_SYSTEMLOG, 0, "{}", desc.Utf8DebugString());
		auto pDesc = m_astDesc.Insert(desc.rankdown());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.rankdown());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load {}, num={}", iRet, table.arenafirstrank_list_size());
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
	return 0;
}

int ArenaFirstrankDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::arenafirstrank_s * ArenaFirstrankDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::arenafirstrank_s * ArenaFirstrankDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

