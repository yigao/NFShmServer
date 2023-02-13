// -------------------------------------------------------------------------
//    @FileName         :    NFCreature.h
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreature
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"

enum {
    NF_CREATURE_NODE_LIST_GRID_INDEX = 0,
    NF_CREATURE_NODE_LIST_SCENE_INDEX = 1,
    NF_CREATURE_NODE_LIST_MAX_TYPE_INDEX = 2,
};

class NFGrid;
class NFCreature : public NFShmObj, public NFMultiListNodeObjWithGlobalID<NFCreature, EOT_GAME_CREATURE_ID, NF_CREATURE_NODE_LIST_MAX_TYPE_INDEX>
{
public:
    NFCreature();

    virtual ~NFCreature();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetCid() const;

    void SetCid(uint64_t cid);

    uint32_t GetKind() const;

    void SetKind(uint32_t kind);

    uint64_t GetMapId() const;

    void SetMapId(uint64_t mapId);

    uint64_t GetSceneId() const;

    void SetSceneId(uint64_t sceneId);

private:
    uint64_t m_cid;
    uint32_t m_kind;
    uint64_t m_mapId;
    uint64_t m_sceneId;

DECLARE_IDCREATE(NFCreature)
};