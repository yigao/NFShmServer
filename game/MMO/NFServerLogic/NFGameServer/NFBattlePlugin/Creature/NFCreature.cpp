// -------------------------------------------------------------------------
//    @FileName         :    NFCreature.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreature
//
// -------------------------------------------------------------------------

#include "NFCreature.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFCreature, EOT_GAME_CREATURE_ID, NFShmObj)

NFCreature::NFCreature() : NFShmObj()
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

NFCreature::~NFCreature()
{
}

int NFCreature::CreateInit()
{
    m_cid = 0;
    m_kind = 0;
    m_mapId = 0;
    m_sceneId = 0;

    return 0;
}

int NFCreature::ResumeInit()
{
    return 0;
}

uint64_t NFCreature::GetCid() const
{
    return m_cid;
}

void NFCreature::SetCid(uint64_t cid)
{
    m_cid = cid;
}

uint32_t NFCreature::GetKind() const
{
    return m_kind;
}

void NFCreature::SetKind(uint32_t kind)
{
    m_kind = kind;
}

uint64_t NFCreature::GetMapId() const
{
    return m_mapId;
}

void NFCreature::SetMapId(uint64_t mapId)
{
    m_mapId = mapId;
}

uint64_t NFCreature::GetSceneId() const
{
    return m_sceneId;
}

void NFCreature::SetSceneId(uint64_t sceneId)
{
    m_sceneId = sceneId;
}