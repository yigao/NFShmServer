// -------------------------------------------------------------------------
//    @FileName         :    GameRoomDescEx.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    GameRoomDescEx
//
// -------------------------------------------------------------------------

#include "GameRoomDescEx.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "DescStore/RoomRoomDesc.h"

IMPLEMENT_IDCREATE_WITHTYPE(GameRoomDescEx, EOT_GameRoomDescEx_ID, NFIDescStore)

GameRoomDescEx::GameRoomDescEx()
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

GameRoomDescEx::~GameRoomDescEx()
{
}

int GameRoomDescEx::CreateInit()
{
    return 0;
}

int GameRoomDescEx::ResumeInit()
{
    return 0;
}

bool GameRoomDescEx::IsNeedReload()
{
    CHECK_DESC_RELOADING(RoomRoomDesc);
    return false;
}

int GameRoomDescEx::PrepareReload()
{
    m_roomIdMap.clear();
    return 0;
}

int GameRoomDescEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR_ASSERT(RoomRoomDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      RoomRoomDesc::Instance(m_pObjPluginManager)->GetFileName());

    auto& mapDesc = RoomRoomDesc::Instance(m_pObjPluginManager)->GetResDesc();

    for (int i = 0; i < (int) mapDesc.size(); i++)
    {
        auto &room = mapDesc[i];
        NF_ASSERT_MSG(!m_roomIdMap.full(), "m_roomIdMap game space not enough");
        NF_ASSERT_MSG(!m_roomIdMap[room.m_gameid].full(), "m_roomIdMap game's room space not enough");
        m_roomIdMap[room.m_gameid][room.m_roomid] = room.m_id;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int GameRoomDescEx::CheckWhenAllDataLoaded()
{
    return 0;
}

uint32_t GameRoomDescEx::GetDescId(uint32_t gameId, uint32_t roomId)
{
    auto iter = m_roomIdMap.find(gameId);
    if (iter != m_roomIdMap.end())
    {
        auto iter2 = iter->second.find(roomId);
        if (iter2 != iter->second.end())
        {
            return iter2->second;
        }
    }
    return 0;
}

const proto_ff_s::E_RoomRoom_s *GameRoomDescEx::GetDesc(uint32_t gameId, uint32_t roomId)
{
    uint32_t id = GetDescId(gameId, roomId);
    if (id > 0)
    {
        return RoomRoomDesc::Instance(m_pObjPluginManager)->GetDesc(id);
    }
    return nullptr;
}

