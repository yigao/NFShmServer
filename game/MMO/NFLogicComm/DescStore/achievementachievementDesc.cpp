// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomDesc.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoomDesc.cpp
//
// -------------------------------------------------------------------------

#include "achievementachievementDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(achievementachievementDesc, EOT_CONST_achievementachievement_DESC_ID, NFShmObj)

achievementachievementDesc::achievementachievementDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

achievementachievementDesc::~achievementachievementDesc()
{

}

int achievementachievementDesc::CreateInit()
{
    Initialize();
    return 0;
}

int achievementachievementDesc::ResumeInit()
{
    return 0;
}

int achievementachievementDesc::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_achievementachievement table;
    NFResTable* pResTable = pDB->GetTable(GetFileName());
    CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

    int iRet = 0;
    iRet = pResTable->FindAllRecord(GetDBName(), &table);
    CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

    CreateInit();

    if ((table.achievementachievement_list_size() < 0) || (table.achievementachievement_list_size() > (int)(m_astDesc.GetSize())))
    {
        NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.achievementachievement_list_size());
        return -2;
    }

    for (int i = 0; i < table.achievementachievement_list_size(); i++)
    {
        const proto_ff::achievementachievement& desc = table.achievementachievement_list(i);
        auto pDesc = m_astDesc.Insert(desc.achievementid());
        CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.achievementid());
        pDesc->read_from_pbmsg(desc);
    }

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.achievementachievement_list_size());
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
    return 0;
}

int achievementachievementDesc::CheckWhenAllDataLoaded()
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");

    return 0;
}

const proto_ff_s::achievementachievement_s *achievementachievementDesc::GetDesc(int id) const {
    return m_astDesc.Find(id);
}

proto_ff_s::achievementachievement_s *achievementachievementDesc::GetDesc(int id) {
    return m_astDesc.Find(id);
}

