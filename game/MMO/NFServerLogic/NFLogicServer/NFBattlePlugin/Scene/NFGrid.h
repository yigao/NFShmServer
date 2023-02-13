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
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmStaticList.hpp"
#include "NFLogicCommon/NFPoint2.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"

#define NF_SCENE_GRID_MAX_CREATURE_NUM 20

class NFCreature;
class NFGrid
{
public:
    NFGrid();

    virtual ~NFGrid();

    int CreateInit();

    int ResumeInit();

public:
    int UnInit(NFIPluginManager *pPluginManager);
public:
    /**
     * @brief
     * @param pCreature
     */
    int AddCreature(NFIPluginManager *pPluginManager, NFCreature* pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemoveCreature(NFIPluginManager *pPluginManager, NFCreature* pCreature);

public:
    void SetGridPos(NFPoint2<uint32_t> gridPos) { m_gridPos = gridPos; }
    bool IsSame(NFPoint2<uint32_t> pos) { return pos == m_gridPos; }
private:
    NFShmNodeObjMultiList<NFCreature> m_cidList;
    NFPoint2<uint32_t> m_gridPos;
};