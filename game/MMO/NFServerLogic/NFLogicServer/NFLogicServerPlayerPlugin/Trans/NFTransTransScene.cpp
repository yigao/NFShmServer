// -------------------------------------------------------------------------
//    @FileName         :    NFTransEnterScene.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransEnterScene
//
// -------------------------------------------------------------------------

#include "NFTransTransScene.h"
#include "ServerInternalCmd2.pb.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Player/NFPlayer.h"
#include "ServerInternal2.pb.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "ServerInternalCmd.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransTransScene, EOT_TRANS_LOGIC_TRANS_SCENE, NFTransBase)

NFTransTransScene::NFTransTransScene() : NFTransPlayerBase()
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

NFTransTransScene::~NFTransTransScene()
{
}

int NFTransTransScene::CreateInit()
{
    m_mapId = 0;
    m_sceneId = 0;
    return 0;
}

int NFTransTransScene::ResumeInit()
{
    return 0;
}

int NFTransTransScene::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    return 0;
}

int NFTransTransScene::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    m_cmd = nMsgId;
    switch(nMsgId)
    {
        case proto_ff::WORLD_TO_LOGIC_ENTER_SCENE_RSP:
        {
            return OnHandleWorldEnterSceneRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        case proto_ff::WORLD_TO_LOGIC_LEAVE_SCENE_RSP:
        {
            return OnHandleWorldLeaveSceneRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransTransScene::OnHandleWorldEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicEnterSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);
    CHECK_EXPR(m_mapId == xData.map_id(), -1, "");

    if (xData.ret_code() != proto_ff::RET_SUCCESS)
    {
        pPlayer->SetGameId(0);
        pPlayer->SetMapId(pPlayer->GetLastMapId());
        pPlayer->SetSceneId(pPlayer->GetLastSceneId());
        pPlayer->SetPos(pPlayer->GetLastPos());
    }
    else {
        pPlayer->SetGameId(xData.game_id());
        pPlayer->SetMapId(xData.map_id());
        pPlayer->SetSceneId(xData.scene_id());
        NFPoint3<float> pos(xData.pos());
        pPlayer->SetPos(pos);
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransTransScene::OnHandleWorldLeaveSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToLogicLeaveSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    pPlayer->SetGameId(0);

    if (m_reqTransId > 0)
    {
        proto_ff::NotifyLogicLeaveGameRsp2 rspMsg;
        rspMsg.set_cid(pPlayer->GetRoleId());
        rspMsg.set_uid(pPlayer->GetUid());

        pPlayer->SendTransToWorldServer(proto_ff::NOTIFY_LOGIC_LEAVE_GAME_RSP, rspMsg, GetGlobalID(), m_reqTransId);
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransTransScene::InitStaticMapInfo(uint64_t mapId, uint64_t scenceId, const NFPoint3<float> &dstPos)
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    m_mapId = mapId;
    m_sceneId = scenceId;
    m_pos = dstPos;
    return 0;
}

int NFTransTransScene::TransScene(uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos)
{
    m_mapId = mapId;
    m_sceneId = sceneId;
    m_pos = pos;

    return SendEnterScene();
}

int NFTransTransScene::SendEnterScene()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    proto_ff::LogicToWorldEnterSceneReq xMsg;
    xMsg.set_role_id(m_roleId);
    xMsg.set_map_id(m_mapId);
    xMsg.set_scene_id(m_sceneId);
    m_pos.ToProto(*xMsg.mutable_pos());
    pPlayer->SetEnterSceneProto(*xMsg.mutable_data());

    pPlayer->SendTransToWorldServer(proto_ff::LOGIC_TO_WORLD_ENTER_SCENE_REQ, xMsg, GetGlobalID());
    return 0;
}

int NFTransTransScene::SendLeaveScene()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    proto_ff::LogicToWorldLeaveSceneReq xMsg;
    xMsg.set_role_id(m_roleId);
    xMsg.set_map_id(m_mapId);
    xMsg.set_scene_id(m_sceneId);
    xMsg.set_game_id(pPlayer->GetGameId());
    m_pos.ToProto(*xMsg.mutable_pos());

    pPlayer->SendTransToWorldServer(proto_ff::LOGIC_TO_WORLD_LEAVE_SCENE_REQ, xMsg, GetGlobalID());
    return 0;
}
