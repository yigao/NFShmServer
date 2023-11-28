// -------------------------------------------------------------------------
//    @FileName         :    NFGrid.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrid
//
// -------------------------------------------------------------------------

#include "NFGrid.h"
#include "Creature/NFCreature.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Creature/NFCreatureMgr.h"

NFGrid::NFGrid()
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

NFGrid::~NFGrid()
{

}

int NFGrid::CreateInit()
{
    m_cidList.InitShmObj(this);
    return 0;
}

int NFGrid::ResumeInit()
{
    return 0;
}

int NFGrid::AddCreature(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    m_cidList.AddNode(NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature);
    return 0;
}

int NFGrid::RemoveCreature(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    m_cidList.RemoveNode(NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature);
    return 0;
}

int NFGrid::Init(uint32_t x, uint32_t y)
{
    m_gridPos.x = x;
    m_gridPos.y = y;
    return 0;
}

int NFGrid::UnInit()
{
    NFCreature* pCreature = m_cidList.GetHeadNodeObj(NF_CREATURE_NODE_LIST_GRID_INDEX);
    NFCreature* pLastCreautre = NULL;
    while(pCreature)
    {
        pLastCreautre = pCreature;
        pCreature = m_cidList.GetNextNodeObj(NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature);
        m_cidList.RemoveNode(NF_CREATURE_NODE_LIST_GRID_INDEX, pLastCreautre);
    }
    return 0;
}

