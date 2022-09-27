#include "NoticeNoticeDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(NoticeNoticeDesc, EOT_CONST_NOTICE_NOTICE_DESC_ID, NFShmObj)

NoticeNoticeDesc::NoticeNoticeDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NoticeNoticeDesc::~NoticeNoticeDesc()
{
}

int NoticeNoticeDesc::CreateInit()
{
	Initialize();
	return 0;
}

int NoticeNoticeDesc::ResumeInit()
{
	return 0;
}

int NoticeNoticeDesc::Load(NFResDB *pDB)
{
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
	CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_noticenotice table;
	NFResTable* pResTable = pDB->GetTable(GetFileName());
	CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

	int iRet = 0;
	iRet = pResTable->FindAllRecord(GetDBName(), &table);
	CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

	//NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

	if ((table.noticenotice_list_size() < 0) || (table.noticenotice_list_size() > (int)(m_astDesc.GetSize())))
	{
		NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.noticenotice_list_size());
		return -2;
	}

	for (int i = 0; i < table.noticenotice_list_size(); i++)
	{
		const proto_ff::noticenotice& desc = table.noticenotice_list(i);
		auto pDesc = m_astDesc.Insert(desc.noticeid());
		CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.noticeid());
		pDesc->read_from_pbmsg(desc);
	}

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.noticenotice_list_size());
	return 0;
	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
}

int NoticeNoticeDesc::CheckWhenAllDataLoaded()
{
	return 0;
}

const proto_ff_s::noticenotice_s * NoticeNoticeDesc::GetDesc(int id) const
{
	return m_astDesc.Find(id);
}

proto_ff_s::noticenotice_s * NoticeNoticeDesc::GetDesc(int id)
{
	return m_astDesc.Find(id);
}

