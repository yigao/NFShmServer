// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomMgr
//
// -------------------------------------------------------------------------

#include "NFWorldRoomMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "DescStore/FishRoomDesc.h"

NFWorldRoomMgr::NFWorldRoomMgr()
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

NFWorldRoomMgr::~NFWorldRoomMgr()
{
}

int NFWorldRoomMgr::CreateInit()
{
    m_inited = false;
    return 0;
}

int NFWorldRoomMgr::ResumeInit()
{
    return 0;
}

NFWorldRoom *NFWorldRoomMgr::CreateRoom(uint32_t id)
{
    CHECK_EXPR(id > 0, NULL, "id:{} not right", id);

    NFWorldRoom* pRoom = NFWorldRoom::GetObjByHashKey(m_pObjPluginManager, id);
    CHECK_EXPR(pRoom == NULL, NULL, "Room:{} Exist", id);

    pRoom = NFWorldRoom::CreateObjByHashKey(m_pObjPluginManager, id);
    CHECK_EXPR(pRoom, NULL, "NFWorldRoom::CreateObjByHashKey id:{} Failed", id);
    pRoom->m_id = id;

    pRoom = NFWorldRoom::GetObjByHashKey(m_pObjPluginManager, id);
    CHECK_EXPR(pRoom, NULL, "NFWorldRoom::GetObjByHashKey id:{} Failed", id);

    return pRoom;
}

NFWorldRoom *NFWorldRoomMgr::GetRoom(uint32_t gameId, uint32_t roomId)
{
    auto pConfig = FishRoomDesc::Instance()->GetDescByGameidRoomid(gameId, roomId);
    if (pConfig)
    {
        return NFWorldRoom::GetObjByHashKey(m_pObjPluginManager, pConfig->m_id);
    }
    return nullptr;
}

int NFWorldRoomMgr::CreateRoom()
{
    if (m_inited) return 0;

    auto& allDesc = FishRoomDesc::Instance()->GetResDesc();
    for(auto iter = allDesc.begin(); iter != allDesc.end(); ++iter)
    {
        auto pDesc = &iter->second;
        CHECK_EXPR(pDesc == FishRoomDesc::Instance()->GetDescByGameidRoomid(pDesc->m_gameId, pDesc->m_roomId), -1, "");
        NFWorldRoom* pRoom = CreateRoom(pDesc->m_id);
        CHECK_EXPR(pRoom, -1, "Create Room:{} Failed!", pDesc->m_id);
        pRoom->m_gameId = pDesc->m_gameId;
        pRoom->m_roomId = pDesc->m_roomId;
    }
    m_inited = true;
    return 0;
}
