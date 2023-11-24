// -------------------------------------------------------------------------
//    @FileName         :    NFGrid.h
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrid
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmStaticList.hpp"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include "NFGameCommon/NFPoint2.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

#define NF_SCENE_GRID_MAX_CREATURE_NUM 20

class NFCreature;

class NFGrid : public NFShmObjTemplate<NFGrid, EOT_SCENE_GRID_ID, NFShmObj>
{
public:
    NFGrid();
    
    virtual ~NFGrid();
    
    int CreateInit();
    
    int ResumeInit();

public:
    int Init(uint32_t x, uint32_t y);
    int UnInit();
public:
    /**
     * @brief
     * @param pCreature
     */
    int AddCreature(NFCreature *pCreature);
    
    /**
     * @brief
     * @param pCreature
     */
    int RemoveCreature(NFCreature *pCreature);

public:
    void SetGridPos(NFPoint2<uint32_t> gridPos) { m_gridPos = gridPos; }
    
    bool IsSame(NFPoint2<uint32_t> pos) { return pos == m_gridPos; }
    
    const NFPoint2<uint32_t> &GetGridPos() const { return m_gridPos; }
    
    NFShmNodeObjMultiList<NFCreature> &GetCidList() { return m_cidList; }

private:
    NFShmNodeObjMultiList<NFCreature> m_cidList;
    NFPoint2<uint32_t> m_gridPos;
};