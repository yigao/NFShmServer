// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFRoleDescStoreEx.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "common_logic.pb.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFLogicCommon/NFMath.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "DescStore/RoleExpDesc.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRoleDescStoreEx, EOT_ROLE_CONFIG_DESCEX_ID, NFShmObj)

NFRoleDescStoreEx::NFRoleDescStoreEx()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFRoleDescStoreEx::~NFRoleDescStoreEx()
{
}

int NFRoleDescStoreEx::CreateInit()
{
    m_maxLevel = 0;
    return 0;
}

int NFRoleDescStoreEx::ResumeInit()
{
    return 0;
}

int NFRoleDescStoreEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR_ASSERT(RoleExpDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      RoleExpDesc::Instance(m_pObjPluginManager)->GetFileName());

    Initialize();

    auto &mapResDesc = RoleExpDesc::Instance(m_pObjPluginManager)->GetResDesc();
    for (int i = 0; i < (int) mapResDesc.GetSize(); i++)
    {
        auto pDesc = &mapResDesc[i];
        if (pDesc)
        {
            if (pDesc->lv > (int32_t)m_maxLevel)
            {
                m_maxLevel = pDesc->lv;
            }
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFRoleDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}
