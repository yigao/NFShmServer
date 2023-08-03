// -------------------------------------------------------------------------
//    @FileName         :    NFCGameRoomModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGameRoomModule
//
// -------------------------------------------------------------------------

#include "NFCGameRoomModule.h"
#include "DescStoreEx/GameRoomDescEx.h"
#include "Room/NFGameRoomMgr.h"
#include "Player/NFGamePlayerMgr.h"


NFCGameRoomModule::NFCGameRoomModule(NFIPluginManager* p): NFFishDynamicModule(p)
{

}

NFCGameRoomModule::~NFCGameRoomModule()
{
}

bool NFCGameRoomModule::Awake()
{
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_CS_MSG_DeskListReq>(NF_ST_GAME_SERVER, this, &NFCGameRoomModule::OnHandleDeskListReq);
    return true;
}

bool NFCGameRoomModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCGameRoomModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCGameRoomModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleClientMessage(msgId, packet, param1, param2);
}

int NFCGameRoomModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleServerMessage(msgId, packet, param1, param2);
}

int NFCGameRoomModule::OnHandleDeskListReq(proto_ff::DeskListReq &request, proto_ff::DeskListRsp &respone, uint64_t playerId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    auto roomConfig = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc(request.game_id(), request.room_id());
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", request.game_id(), request.room_id());
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    uint32_t autoChairId = roomConfig->m_auto_chair;// 1;// 1-显示桌子列表  0-不显示桌子列表

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "======> playerId = {} , autoChairId = {}", playerId, autoChairId);

    NFGameRoom *pRoom = NFGameRoomMgr::Instance(m_pObjPluginManager)->GetGameRoom(request.game_id(), request.room_id());
    CHECK_EXPR(pRoom, -1, "pRoom == NULL for game_id = {} , room_id = {}", request.game_id() , request.room_id());

    NFGamePlayer *pPlayer = NFGamePlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer)
    {
        if (pPlayer->GetGameId() == request.game_id() && pPlayer->GetRoomId() == request.room_id() && pPlayer->GetDeskId() >= 0 && pPlayer->GetChairId() >= 0)
        {
            respone.set_result(0);

            proto_ff::GameDeskInfo* pDeskInfo = respone.add_desks();
            pDeskInfo->set_desk_id(pPlayer->GetDeskId()+1);
            pDeskInfo->set_desk_name("deskName");
            pDeskInfo->set_desk_status(0);
            pDeskInfo->set_chair_count(1);

            //自动选一个座位并保留 todo

            proto_ff::GameChairInfo* pChairInfo = pDeskInfo->add_chairs();
            pChairInfo->set_chair_id(pPlayer->GetChairId()+1);
            pChairInfo->set_chair_status(0);

            return 0;
        }
    }
    else
    {
        pPlayer = NFGamePlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(playerId);
        CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Create Player Failed, playerId:{}", playerId);

        pPlayer->SetClearFlag(false);
        pPlayer->SetOnline(true);
        pPlayer->SetOfflineTime(0);
        pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());
    }

    pRoom->OnHandleReqDeskList(playerId, autoChairId, respone);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}



