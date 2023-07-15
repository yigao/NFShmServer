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
#include "Player/NFPlayerMgr.h"
#include "ServerInternal2.pb.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "ServerInternalCmd.pb.h"
#include "Scene.pb.h"
#include "DescStoreEx/NFMapDescStoreEx.h"
#include "ClientServerCmd.pb.h"
#include "DescStore/AreaAreaDesc.h"

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
    m_transType = 0;
    m_transId = 0;
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
        case proto_ff::WORLD_TO_LOGIC_GET_MAP_INFO_RSP:
        {
            return OnHandleGetMapInfoRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransTransScene::OnHandleWorldEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::WorldToLogicEnterSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);
    CHECK_EXPR(m_mapId == xData.map_id(), -1, "");

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv enter scene from world server, mapId:{} sceneId:{} retCode:{}", m_mapId, m_sceneId, xData.ret_code());

    if (xData.ret_code() != proto_ff::RET_SUCCESS)
    {
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
        pPlayer->SetGameId(0);
        pPlayer->SetMapId(pPlayer->GetLastMapId());
        pPlayer->SetSceneId(pPlayer->GetLastSceneId());
        pPlayer->SetPos(pPlayer->GetLastPos());
    }
    else {
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_Gameing);
        pPlayer->SetGameId(xData.game_id());
        pPlayer->SetMapId(xData.map_id());
        pPlayer->SetSceneId(xData.scene_id());
        NFPoint3<float> pos(xData.pos());
        pPlayer->SetPos(pos);
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransTransScene::OnHandleWorldLeaveSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::WorldToLogicLeaveSceneRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
    pPlayer->SetGameId(0);

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv leave scene from world server, mapId:{} sceneId:{} retCode:{}", m_mapId, m_sceneId, xData.ret_code());
    if (m_reqTransId > 0)
    {
        proto_ff::NotifyLogicLeaveGameRsp2 rspMsg;
        rspMsg.set_cid(pPlayer->GetRoleId());
        rspMsg.set_uid(pPlayer->GetUid());

        pPlayer->SendTransToWorldServer(proto_ff::NOTIFY_LOGIC_LEAVE_GAME_RSP, rspMsg, GetGlobalId(), m_reqTransId);
    }

    if (m_cmd == proto_ff::CLIENT_SCENE_TRANS_REQ)
    {
        SendEnterScene();
    }
    else if (m_cmd == proto_ff::NOTIFY_LOGIC_LEAVE_GAME_REQ){
        SetFinished(0);
    }
    else {
        SetFinished(0);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransTransScene::OnHandleGetMapInfoRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::LogicToWorldGetMapInfoRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    uint64_t srcMapId = xData.src_map_id();
    uint32_t srcGameId = xData.src_game_id();
    uint32_t dstGameId = xData.dst_game_id();
    uint32_t curGameId = xData.cur_game_id();

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "recv get map info from world server, mapId:{} sceneId:{} dstGameId:{}", m_mapId, m_sceneId, dstGameId);
    if (m_cmd == proto_ff::CLIENT_SCENE_TRANS_REQ)
    {
        if (curGameId != pPlayer->GetGameId())
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "world server role game id:{} != logic server role game id:{}", curGameId, pPlayer->GetGameId());
        }

        if (curGameId > 0 && curGameId != srcGameId)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "world server role game id:{} != the game id:{} of role map:{}", curGameId, pPlayer->GetGameId(), srcMapId);
        }

        NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "trans scene to world server, mapId:{} sceneId:{} dstGameId:{}", m_mapId, m_sceneId, dstGameId);
        if (pPlayer->GetGameId() <= 0)
        {
            SendEnterScene();
        }
        else if (pPlayer->GetGameId() > 0 && pPlayer->GetGameId() == dstGameId)
        {
            SendEnterScene();
        }
        else if (pPlayer->GetGameId() > 0 && pPlayer->GetGameId() != dstGameId)
        {
            SendLeaveScene();
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
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

int NFTransTransScene::TransScene(uint64_t mapId, uint32_t transType, uint64_t dstId)
{
    m_mapId = mapId;
    m_transType = transType;
    m_transId = dstId;

    NFPlayer *pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);
    //
    if (ETransMapType_None == transType) //出生点传送
    {
        //随机出生点
        const NFPoint3<float>* pBornCfg = NFMapDescStoreEx::Instance(m_pObjPluginManager)->RandBornPoint(m_mapId);
        if (nullptr == pBornCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "ClientTransSceneReq..RandBornPoint failed...cid:{}, mapid:{} ", m_roleId, m_mapId);

            return proto_ff::RET_SCENE_CAN_NOT_TRAN;
        }

        m_pos = *pBornCfg;
    }
    else if (ETransMapType_Point == transType)
    {
        auto pPointLoc = NFMapDescStoreEx::Instance(m_pObjPluginManager)->GetPointCfg(m_transId);
        if (nullptr == pPointLoc)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "[logic] MovePart::ClientTransSceneReq...nullptr == pPointLoc..cid:{}, transId:{} ", m_roleId, m_transId);

            //传送参数错误
            return proto_ff::RET_SCENE_TRANS_PARAM_ERROR;
        }

        if (pPointLoc->vecposcfg.size() <= 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "ClientTransSceneReq...pPathLoc->vecposcfg.size() <= 0..cid:{},m_mapId:{}, transId:{} ", m_roleId, pPointLoc->mapid, m_transId);
            //传送参数错误
            return proto_ff::RET_SCENE_TRANS_PARAM_ERROR;
        }

        uint32_t isize = (uint32_t)pPointLoc->vecposcfg.size();
        uint32_t idx = NFRandInt((uint32_t)0, isize);
        m_pos = pPointLoc->vecposcfg.at(idx).m_pos;
        //
        m_mapId = pPointLoc->mapid;
    }
    else if (ETransMapType_Area == transType)
    {
        auto pAreaCfg = AreaAreaDesc::Instance(m_pObjPluginManager)->GetDesc(m_transId);
        if (nullptr == pAreaCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "ClientTransSceneReq...nullptr == pAreaCfg..cid:{},transId:{} ", m_roleId, m_transId);
            //传送参数错误
            return proto_ff::RET_SCENE_TRANS_PARAM_ERROR;
        }

        m_mapId = pAreaCfg->m_belongtosceneid;

        //区域内随机一个坐标
        if (!NFMapDescStoreEx::Instance(m_pObjPluginManager)->RandPosInArea(m_transId, m_pos))
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "[logic] MovePart::ClientTransSceneReq...RandPosInArea failed..cid:%lu, mapid:%lu, transId:%lu ", m_roleId, m_mapId, m_transId);

            return proto_ff::RET_SCENE_TRANS_PARAM_ERROR;
        }
    }
    else
    {
        //传送参数错误
        return proto_ff::RET_SCENE_TRANS_PARAM_ERROR;
    }

    auto pMapCfg = MapMapDesc::Instance(m_pObjPluginManager)->GetDesc(m_mapId);
    if (nullptr == pMapCfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "ClientTransSceneReq..nullptr == pMapCfg...cid:{}, mapid:{} ", m_roleId, m_mapId);
        //动态地图不能传送
        return proto_ff::RET_SCENE_DST_NOT_EXIST;
    }

    if (pPlayer->GetAttr(proto_ff::A_LEVEL) < pMapCfg->m_levellimit)
    {
        return proto_ff::RET_LEVEL_LACK;
    }

    //
    if (NFMapDescStoreEx::Instance(m_pObjPluginManager)->IsDynamic(pMapCfg->m_mapid)) //动态地图不允许用这个协议传送
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "[logic] MovePart::ClientTransSceneReq..dstmap is dynamic...cid:%lu, mapid:%lu ", m_roleId, m_mapId);

        //动态地图不能传送
        return proto_ff::RET_SCENE_CAN_NOT_TRAN;
    }

    //特殊的活动的静态地图只能通过活动那边进入，不允许通过普通的切换地图协议传送地图
    if (NFMapDescStoreEx::Instance(m_pObjPluginManager)->IsActSpecMap(pMapCfg->m_mapid))
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_roleId, "ClientTransSceneReq..dstmap is special act map...cid:{}, mapid:{},maptype:{} ", m_roleId, m_mapId, pMapCfg->m_maptype);
        //不能传送
        return proto_ff::RET_SCENE_CAN_NOT_TRAN;
    }

    m_sceneId = m_mapId;

    SendGetMapInfoReq();
    return 0;
}

int NFTransTransScene::SendGetMapInfoReq()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    if (pPlayer->IsInTransSceneing())
    {
        return proto_ff::RET_FAIL;
    }

    proto_ff::LogicToWorldGetMapInfoReq xMsg;
    xMsg.set_dst_map_id(m_mapId);
    xMsg.set_src_map_id(pPlayer->GetMapId());
    xMsg.set_role_id(m_roleId);

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send get map info to world server, mapId:{} sceneId:{}", m_mapId, m_sceneId);
    pPlayer->SendTransToWorldServer(proto_ff::LOGIC_TO_WORLD_GET_MAP_INFO_REQ, xMsg, GetGlobalId());
    return 0;
}

int NFTransTransScene::SendEnterScene()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    if (pPlayer->IsInTransSceneing())
    {
        return proto_ff::RET_FAIL;
    }

    pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_Entering);

    proto_ff::LogicToWorldEnterSceneReq xMsg;
    xMsg.set_role_id(m_roleId);
    xMsg.set_map_id(m_mapId);
    xMsg.set_scene_id(m_sceneId);
    m_pos.ToProto(*xMsg.mutable_pos());
    xMsg.set_src_map_id(pPlayer->GetMapId());
    xMsg.set_src_scene_id(pPlayer->GetSceneId());
    xMsg.set_trans_type(m_transType);
    pPlayer->SetEnterSceneProto(*xMsg.mutable_data());

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send enter scene to world server, mapId:{} sceneId:{}", m_mapId, m_sceneId);
    pPlayer->SendTransToWorldServer(proto_ff::LOGIC_TO_WORLD_ENTER_SCENE_REQ, xMsg, GetGlobalId());

    return 0;
}

int NFTransTransScene::SendLeaveScene()
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    if (pPlayer->IsInTransSceneing())
    {
        return proto_ff::RET_FAIL;
    }

    pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_Leaveing);

    proto_ff::LogicToWorldLeaveSceneReq xMsg;
    xMsg.set_role_id(m_roleId);
    xMsg.set_map_id(m_mapId);
    xMsg.set_scene_id(m_sceneId);
    xMsg.set_game_id(pPlayer->GetGameId());
    m_pos.ToProto(*xMsg.mutable_pos());

    NFLogDebug(NF_LOG_SYSTEMLOG, m_roleId, "send leave scene to world server, mapId:{} sceneId:{}", m_mapId, m_sceneId);
    pPlayer->SendTransToWorldServer(proto_ff::LOGIC_TO_WORLD_LEAVE_SCENE_REQ, xMsg, GetGlobalId());
    return 0;
}

int NFTransTransScene::HandleTransFinished(int iRunLogicRetCode)
{
    auto pPlayer = GetPlayer();
    CHECK_NULL(pPlayer);

    //超时了，对方服务器可以崩溃了，或服务器异常了
    if (iRunLogicRetCode < 0)
    {
        pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
        pPlayer->SetGameId(0);
    }

    if (m_cmd == proto_ff::CLIENT_SCENE_TRANS_REQ)
    {
        proto_ff::TransSceneRsp transRsp;
        transRsp.set_mapid(m_mapId);
        transRsp.set_retcode(iRunLogicRetCode);
        pPlayer->SendMsgToClient(proto_ff::NOTIFY_CLIENT_TRANS_SCENE_RSP, transRsp);
    }
    else if (m_cmd == proto_ff::WORLD_TO_LOGIC_LOGIN_FINISH_NOTIFY)
    {
        if (iRunLogicRetCode > 0)
        {
            pPlayer->SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
            pPlayer->SetGameId(0);
        }
    }
    else if (m_cmd == proto_ff::NOTIFY_LOGIC_LEAVE_GAME_REQ)
    {
        if (iRunLogicRetCode > 0)
        {
            if (m_reqTransId > 0)
            {
                proto_ff::NotifyLogicLeaveGameRsp2 rspMsg;
                rspMsg.set_cid(pPlayer->GetRoleId());
                rspMsg.set_uid(pPlayer->GetUid());

                pPlayer->SendTransToWorldServer(proto_ff::NOTIFY_LOGIC_LEAVE_GAME_RSP, rspMsg, GetGlobalId(), m_reqTransId);
            }
        }
    }


    return 0;
}
