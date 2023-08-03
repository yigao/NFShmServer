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
    m_cmd = 0;
    m_srcMapId = 0;
    m_srcSceneId = 0;
    m_transType = 0;
    return 0;
}

int NFTransWorldTransScene::ResumeInit()
{
    return 0;
}

int NFTransWorldTransScene::Init(uint64_t roleId, uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos, int reqTransId, uint32_t cmd)
{
    m_roleId = roleId;
    m_mapId = mapId;
    m_sceneId = sceneId;
    m_pos = pos;
    m_reqTransId = reqTransId;
    m_cmd = cmd;
    return 0;
}

int NFTransWorldTransScene::OnHandleTransScene(const proto_ff::LogicToWorldEnterSceneReq& xData)
{
    m_srcMapId = xData.src_map_id();
    m_srcSceneId = xData.src_scene_id();
    m_transType = xData.trans_type();

    NFWorldPlayer *pPlayer = NULL; //NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv enter scene from logic server, mapId:{} sceneId:{} ", m_mapId, m_sceneId);
    bool ret = NFWorldSceneMgr::Instance(m_pObjPluginManager)->IsStaticMapId(m_mapId);
    if (ret)
    {
        uint32_t gameId = NFWorldSceneMgr::Instance(m_pObjPluginManager)->GetStaticMapGameId(m_mapId);
        CHECK_EXPR(gameId > 0, -1, "GetStaticMapGameId Failed, mapId:{}", m_mapId);

        m_gameId = gameId;
        m_logicId = pPlayer->GetLogicId();
        pPlayer->SetGameId(gameId);
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_Entering);

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
        reqMsg.set_src_map_id(m_srcMapId);
        reqMsg.set_src_scene_id(m_srcSceneId);
        reqMsg.set_trans_type(m_transType);

        NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send enter scene to game server, mapId:{} sceneId:{} gameId:{}", m_mapId, m_sceneId, m_gameId);
        pPlayer->SendTransToGameServer(proto_ff::WORLD_TO_GAME_ENTER_SCENE_REQ, reqMsg, GetGlobalId());
    }
    else {
        return -1;
    }

    return 0;
}

int NFTransWorldTransScene::OnHandleLeaveScene(const proto_ff::LogicToWorldLeaveSceneReq& xData)
{
    NFWorldPlayer *pPlayer = NULL; //NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv leave scene from logic server, mapId:{} sceneId:{} ", m_mapId, m_sceneId);
    bool ret = NFWorldSceneMgr::Instance(m_pObjPluginManager)->IsStaticMapId(m_mapId);
    if (ret)
    {
        uint32_t gameId = NFWorldSceneMgr::Instance(m_pObjPluginManager)->GetStaticMapGameId(m_mapId);
        CHECK_EXPR(gameId > 0, -1, "GetStaticMapGameId Failed, mapId:{}", m_mapId);

        if (pPlayer->GetGameId() != xData.game_id() || gameId != xData.game_id())
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "OnHandleLeaveScene role:{} leave scene from gameId:{} is not equal the gameId:{} from the logic, map game id:{}", m_roleId, gameId, xData.game_id(), gameId);
        }

        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_Leaveing);

        proto_ff::WorldToGameLeaveSceneReq reqMsg;
        reqMsg.set_role_id(m_roleId);
        reqMsg.set_map_id(m_mapId);
        reqMsg.set_scene_id(m_sceneId);

        NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send leave scene to game server, mapId:{} sceneId:{} gameId:{}", m_mapId, m_sceneId, gameId);
        pPlayer->SendTransToGameServer(proto_ff::WORLD_TO_GAME_LEAVE_SCENE_REQ, reqMsg, GetGlobalId());
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
        case proto_ff::GAME_TO_WORLD_LEAVE_SCENE_RSP:
        {
            return OnHandleGameLeaveSceneRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransWorldTransScene::OnHandleGameEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::GameToWorldEnterSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldPlayer *pPlayer = NULL; //NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv enter scene from game server, mapId:{} sceneId:{} retCode:{}", m_mapId, m_sceneId, xData.ret_code());
    if (xData.ret_code() != proto_ff::RET_SUCCESS)
    {
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
        pPlayer->SetGameId(0);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, 0);
    }
    else {
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_Gameing);
        m_pos.FromProto(xData.pos());
        pPlayer->SetGameId(m_gameId);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, m_gameId);
    }

    SetFinished(xData.ret_code());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTransWorldTransScene::OnHandleGameLeaveSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::GameToWorldLeaveSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldPlayer *pPlayer = NULL; //NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv leave scene from game server, mapId:{} sceneId:{} retCode:{}", m_mapId, m_sceneId, xData.ret_code());
    if (xData.ret_code() != proto_ff::RET_SUCCESS)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "roleId:{} leave scene rsp err:{}, ", m_roleId, xData.ret_code());
    }

    pPlayer->SetGameId(0);
    pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, 0);


    SetFinished(xData.ret_code());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTransWorldTransScene::OnTransFinished(int iRunLogicRetCode)
{
    NFWorldPlayer *pPlayer = NULL; //NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(m_roleId);
    CHECK_EXPR(pPlayer, -1, "can't find player info, roleId:{}", m_roleId);

    if (iRunLogicRetCode != 0)
    {
        pPlayer->SetGameId(0);
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, 0);
    }

    if (m_cmd == proto_ff::LOGIC_TO_WORLD_ENTER_SCENE_REQ)
    {
        proto_ff::WorldToLogicEnterSceneRsp rspMsg;
        rspMsg.set_ret_code(iRunLogicRetCode);
        rspMsg.set_role_id(m_roleId);
        rspMsg.set_map_id(m_mapId);
        rspMsg.set_scene_id(m_sceneId);
        rspMsg.set_game_id(m_gameId);
        m_pos.ToProto(*rspMsg.mutable_pos());

        NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send enter scene to logic server, mapId:{} sceneId:{}", m_mapId, m_sceneId);
        pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_ENTER_SCENE_RSP, rspMsg, GetGlobalId(), m_reqTransId);
    }
    else if (m_cmd == proto_ff::LOGIC_TO_WORLD_LEAVE_SCENE_REQ)
    {
        proto_ff::WorldToLogicLeaveSceneRsp rspMsg;
        rspMsg.set_ret_code(iRunLogicRetCode);
        rspMsg.set_role_id(m_roleId);
        rspMsg.set_map_id(m_mapId);
        rspMsg.set_scene_id(m_sceneId);

        NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send leave scene to logic server, mapId:{} sceneId:{}", m_mapId, m_sceneId);
        pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_LEAVE_SCENE_RSP, rspMsg, GetGlobalId(), m_reqTransId);
    }

    return 0;
}
