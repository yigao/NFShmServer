// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomDesc.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoomDesc.cpp
//
// -------------------------------------------------------------------------

#include "NFConstDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFConstDesc, EOT_CONST_CONFIG_DESC_ID, NFShmObj)

NFConstDesc::NFConstDesc(NFIPluginManager* pPluginManager):NFIDescStore(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFConstDesc::~NFConstDesc()
{

}

int NFConstDesc::CreateInit()
{
    Initialize();
    return 0;
}

int NFConstDesc::ResumeInit()
{
    return 0;
}

int NFConstDesc::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

	NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "NFConstDesc::Load() strFileName = {}", GetFileName());

	proto_ff::Sheet_ConstDesc table;
    NFResTable* pResTable = pDB->GetTable(GetFileName());
    CHECK_EXPR(pResTable != NULL, -1, "pTable == NULL, GetTable:{} Error", GetFileName());

    int iRet = 0;
    iRet = pResTable->FindAllRecord(GetDBName(), &table);
    CHECK_EXPR(iRet == 0, -1, "FindAllRecord Error:{}", GetFileName());

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "{}", table.Utf8DebugString());

    CreateInit();

    if ((table.constdesc_list_size() < 0) || (table.constdesc_list_size() > (int)(m_astDesc.GetSize())))
    {
        NFLogError(NF_LOG_COMM_LOGIC_PLUGIN, 0, "Invalid TotalNum:{}", table.constdesc_list_size());
        return -2;
    }

    for (int i = 0; i < table.constdesc_list_size(); i++)
    {
        const proto_ff::ConstDesc& desc = table.constdesc_list(i);
        auto pDesc = m_astDesc.Insert(desc.id());
        CHECK_EXPR(pDesc, -1, "m_astDesc.Insert Failed desc.id:{}", desc.id());
        pDesc->read_from_pbmsg(desc);
    }

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "load {}, num={}", iRet, table.constdesc_list_size());
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");
    return 0;
}

int NFConstDesc::CheckWhenAllDataLoaded()
{
    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--begin--");

    NFLogTrace(NF_LOG_COMM_LOGIC_PLUGIN, 0, "--end--");

    return 0;
}

const proto_ff_s::ConstDesc_s *NFConstDesc::GetDesc(int id) const {
    return m_astDesc.Find(id);
}

proto_ff_s::ConstDesc_s *NFConstDesc::GetDesc(int id) {
    return m_astDesc.Find(id);
}

