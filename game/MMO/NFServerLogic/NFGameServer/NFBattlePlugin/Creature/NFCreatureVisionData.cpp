// -------------------------------------------------------------------------
//    @FileName         :    NFCreatureVisionData.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreatureVisionData
//
// -------------------------------------------------------------------------

#include "NFCreatureVisionData.h"
#include "NFCreature.h"

NFCreatureVisionDataNode::NFCreatureVisionDataNode()
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

NFCreatureVisionDataNode::~NFCreatureVisionDataNode()
{

}

int NFCreatureVisionDataNode::CreateInit()
{
    creatureGlobalId = -1;
    nMeInHisVisionPos = -1;
    return 0;
}

int NFCreatureVisionDataNode::ResumeInit()
{
    return 0;
}

NFCreatureVisionData::NFCreatureVisionData()
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

NFCreatureVisionData::~NFCreatureVisionData()
{
}

int NFCreatureVisionData::CreateInit()
{
    chVisionUnitType = (int8_t) EVisionFlag::NONE;
    return 0;
}

int NFCreatureVisionData::ResumeInit()
{
    return 0;
}

int NFCreatureVisionData::AddPVPSeeList(NFCreature *pCreature)
{
    CHECK_EXPR(pCreature != NULL, -1, "pCreature == NULL");
    auto iter = m_doublePVPSeeLst.insert(m_doublePVPSeeLst.end());
    if (iter == m_doublePVPSeeLst.end())
    {
        return -1;
    }

    iter->creatureGlobalId = pCreature->GetGlobalID();
    NF_ASSERT(iter.m_node);
    return iter.m_node->m_self;
}

int NFCreatureVisionData::AddPVMSeeList(NFCreature *pCreature)
{
    CHECK_EXPR(pCreature != NULL, -1, "pCreature == NULL");
    auto iter = m_doublePVMSeeLst.insert(m_doublePVMSeeLst.end());
    if (iter == m_doublePVMSeeLst.end())
    {
        return -1;
    }

    iter->creatureGlobalId = pCreature->GetGlobalID();
    NF_ASSERT(iter.m_node);
    return iter.m_node->m_self;
}

bool NFCreatureVisionData::DelPVMSeeList(int pos)
{
    if (pos >= 0)
    {
        auto iter = m_doublePVPSeeLst.GetIterator(pos);
        m_doublePVPSeeLst.erase(iter);
        return true;
    }
    return false;
}

bool NFCreatureVisionData::DelPVPSeeList(int pos)
{
    if (pos >= 0)
    {
        auto iter = m_doublePVMSeeLst.GetIterator(pos);
        m_doublePVMSeeLst.erase(iter);
        return true;
    }
    return false;
}
