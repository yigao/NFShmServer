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

NFGrid::NFGrid(const NFGrid& grid)
{
    if (this != &grid)
    {
        m_cidList = grid.m_cidList;
        m_gridPos = grid.m_gridPos;
    }
}

int NFGrid::CreateInit()
{
    return 0;
}

int NFGrid::ResumeInit()
{
    return 0;
}

int NFGrid::AddCreature(NFIPluginManager *pPluginManager, NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    m_cidList.AddNode(pPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature);
    return 0;
}

int NFGrid::RemoveCreature(NFIPluginManager *pPluginManager, NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    m_cidList.RemoveNode(pPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature);
    return 0;
}

int NFGrid::UnInit(NFIPluginManager *pPluginManager)
{
    NFCreature* pCreature = m_cidList.GetHeadNodeObj(pPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
    NFCreature* pLastCreautre = NULL;
    while(pCreature)
    {
        pLastCreautre = pCreature;
        pCreature = m_cidList.GetNextNodeObj(pPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature);
        m_cidList.RemoveNode(pPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pLastCreautre);
    }
    return 0;
}

