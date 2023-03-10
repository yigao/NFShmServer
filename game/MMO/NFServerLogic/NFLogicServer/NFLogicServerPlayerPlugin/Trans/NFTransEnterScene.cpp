// -------------------------------------------------------------------------
//    @FileName         :    NFTransEnterScene.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransEnterScene
//
// -------------------------------------------------------------------------

#include "NFTransEnterScene.h"
#include "ServerInternalCmd2.pb.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Player/NFPlayer.h"
#include "ServerInternal2.pb.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransEnterScene, EOT_TRANS_LOGIC_ENTER_SCENE, NFTransBase)

NFTransEnterScene::NFTransEnterScene() : NFTransPlayerBase()
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

NFTransEnterScene::~NFTransEnterScene()
{
}

int NFTransEnterScene::CreateInit()
{
    m_mapId = 0;
    m_sceneId = 0;
    return 0;
}

int NFTransEnterScene::ResumeInit()
{
    return 0;
}

int NFTransEnterScene::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    return 0;
}

int NFTransEnterScene::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    switch(nMsgId)
    {
        case proto_ff::WORLD_TO_LOGIC_ENTER_SCENE_RSP:
        {
            return OnHandleWorldEnterSceneRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransEnterScene::OnHandleWorldEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
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
        NFPoint3<float> pos;
        pos.x = xData.pos().x();
        pos.y = xData.pos().y();
        pos.z = xData.pos().z();
        pPlayer->SetPos(pos);
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransEnterScene::InitStaticMapInfo()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    m_mapId = pPlayer->GetMapId();
    m_sceneId = pPlayer->GetSceneId();
    m_pos = pPlayer->GetPos();
    return 0;
}

int NFTransEnterScene::TransScene(uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos)
{
    m_mapId = mapId;
    m_sceneId = sceneId;
    m_pos = pos;

    return SendEnterScene();
}

int NFTransEnterScene::SendEnterScene()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    proto_ff::LogicToWorldEnterSceneReq xMsg;
    xMsg.set_role_id(m_roleId);
    xMsg.set_map_id(m_mapId);
    xMsg.set_scene_id(m_sceneId);
    xMsg.mutable_pos()->set_x(m_pos.x);
    xMsg.mutable_pos()->set_y(m_pos.y);
    xMsg.mutable_pos()->set_z(m_pos.z);
    pPlayer->SetEnterSceneProto(*xMsg.mutable_data());

    pPlayer->SendTransToWorldServer(proto_ff::LOGIC_TO_WORLD_ENTER_SCENE_REQ, xMsg, GetGlobalID());
    return 0;
}
