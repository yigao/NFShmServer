// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldTransScene.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldTransScene
//
// -------------------------------------------------------------------------

#include "NFTransWorldTransScene.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "NFWorldSceneMgr.h"
#include "ServerInternalCmd2.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransWorldTransScene, EOT_NFTransWorldTransScene_ID, NFTransBase
)

NFTransWorldTransScene::NFTransWorldTransScene()
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

NFTransWorldTransScene::~NFTransWorldTransScene()
{
}

int NFTransWorldTransScene::CreateInit()
{
    m_roleId = 0;
    m_mapId = 0;
    m_sceneId = 0;
    m_reqTransId = -1;
    m_gameId = 0;
    m_logicId = 0;
    return 0;
}

int NFTransWorldTransScene::ResumeInit()
{
    return 0;
}

int NFTransWorldTransScene::Init(uint64_t roleId, uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos, int reqTransId)
{
    m_roleId = roleId;
    m_mapId = mapId;
    m_sceneId = sceneId;
    m_pos = pos;
    m_reqTransId = reqTransId;
    return 0;
}

int NFTransWorldTransScene::OnHandleTransScene(const proto_ff::LogicToWorldEnterSceneReq& xData)
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    bool ret = NFWorldSceneMgr::Instance(m_pObjPluginManager)->IsStaticMapId(m_mapId);
    if (ret)
    {
        uint32_t gameId = NFWorldSceneMgr::Instance(m_pObjPluginManager)->GetStaticMapGameId(m_mapId);
        CHECK_EXPR(gameId > 0, -1, "GetStaticMapGameId Failed, mapId:{}", m_mapId);

        m_gameId = gameId;
        m_logicId = pPlayer->GetLogicId();
        pPlayer->SetGameId(gameId);

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, gameId);

        proto_ff::WorldToGameEnterSceneReq reqMsg;
        reqMsg.set_role_id(m_roleId);
        reqMsg.set_map_id(m_mapId);
        reqMsg.set_scene_id(m_sceneId);
        reqMsg.set_gate_id(pPlayer->GetProxyId());
        reqMsg.set_logic_id(pPlayer->GetLogicId());
        reqMsg.set_client_id(pPlayer->GetClientId());
        reqMsg.mutable_pos()->CopyFrom(xData.pos());
        reqMsg.mutable_data()->CopyFrom(xData.data());

        pPlayer->SendTransToGameServer(proto_ff::WORLD_TO_GAME_ENTER_SCENE_REQ, reqMsg, GetGlobalID());
    }
    else {
        return -1;
    }

    return 0;
}

int NFTransWorldTransScene::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    switch(nMsgId)
    {
        case proto_ff::GAME_TO_WORLD_ENTER_SCENE_RSP:
        {
            return OnHandleGameEnterSceneRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransWorldTransScene::OnHandleGameEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::GameToWorldEnterSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    if (xData.ret_code() != proto_ff::RET_SUCCESS)
    {
        pPlayer->SetGameId(0);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, 0);
    }
    else {
        pPlayer->SetGameId(m_gameId);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, m_gameId);
    }

    SetFinished(xData.ret_code());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransWorldTransScene::OnTransFinished(int iRunLogicRetCode)
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    if (iRunLogicRetCode != 0)
    {
        pPlayer->SetGameId(0);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, 0);
    }

    proto_ff::WorldToLogicEnterSceneRsp rspMsg;
    rspMsg.set_ret_code(iRunLogicRetCode);
    rspMsg.set_role_id(m_roleId);
    rspMsg.set_map_id(m_mapId);
    rspMsg.set_scene_id(m_sceneId);
    rspMsg.set_game_id(m_gameId);
    rspMsg.mutable_pos()->set_x(m_pos.x);
    rspMsg.mutable_pos()->set_y(m_pos.y);
    rspMsg.mutable_pos()->set_z(m_pos.z);

    pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_ENTER_SCENE_RSP, rspMsg, GetGlobalID(), m_reqTransId);
    return 0;
}
