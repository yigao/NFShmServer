// -------------------------------------------------------------------------
//    @FileName         :    NFMovePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-1
//    @Email			:    445267987@qq.com
//    @Module           :    NFMovePart
//
// -------------------------------------------------------------------------

#include "NFMovePart.h"
#include "ClientServerCmd.pb.h"
#include "Move.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "Creature/NFCreature.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "NFLogicCommon/NFGameMath.h"
#include "Map/NFMap.h"
#include "Map/NFMapMgr.h"
#include "Scene/NFSceneMgr.h"
#include "Scene/NFScene.h"
#include "Scene.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMovePart, EOT_NFMovePart_ID, NFBattlePart)

NFMovePart::NFMovePart()
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

NFMovePart::~NFMovePart()
{
}

int NFMovePart::CreateInit()
{
    m_lastclientMoveTick = 0;
    m_moveTick = 0;
    m_waitLoadMapId = 0;
    m_timerIdMove = INVALID_ID;
    m_timerIdLoadMapTimeout = INVALID_ID;
    return 0;
}

int NFMovePart::ResumeInit()
{
    return 0;
}

int NFMovePart::Init(const proto_ff::RoleEnterSceneData &data)
{
    return 0;
}

int NFMovePart::UnInit()
{
    return 0;
}

int NFMovePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_MOVE_REQ:
        {
            ClientMoveReq(msgId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_masterCid, "msgId:{} Not Handle", msgId);
            break;
        }
    }
    return 0;
}

int NFMovePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFBattlePart::OnHandleServerMessage(msgId, packet);
}

int NFMovePart::RetisterClientMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMovePart::RetisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMovePart::ClientMoveReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::MoveReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");

    //客户端当前位置
    NFPoint3<float> pos(req.pos().x(), req.pos().y(), req.pos().z());
    //校验客户端坐标
    NFPoint3<float> clientPos = pos;

    //客户端一帧的速度
    NFPoint3<float> speed(req.speed().x(), 0.0f, req.speed().y());

    //停止的速度,主要用来和客户端速度比较
    NFPoint3<float> zerospeed(0.0f, 0.0f, 0.0f);

    //客户端方向
    NFPoint3<float> dir(req.dir().x(), 0.0f, req.dir().y());

    //玩家速度
    float fspeed = pMaster->GetSpeed();

    //玩家当前坐标
    NFPoint3<float> curPos = pMaster->GetPos();

    //客户端是否停止移动
    bool stopMoveFlag = false;
    //客户端是否是原地跑动
    bool inplaceFlag = false;
    //
    uint64_t mapId = pMaster->GetMapId();
    //
    if (zerospeed == speed) //速度为0，表示停止移动
    {
        //停止移动
        stopMoveFlag = true;
    }
    else if (clientPos == m_lastClientPos)
    {
        /* 客户端坐标和最近一次发上来的客户端坐标一样，表示客户端在原地跑动
           这种情况是玩家在阻挡点原地跑动，其他客户端看到这个玩家 也是要原地跑动
        */
        inplaceFlag = true;
    }
    else
    {
        //启动模拟移动定时器
        if (m_timerIdMove != INVALID_ID)
        {
            m_timerIdMove = SetTimer(INTERVAL_MOVE_TIME, 0, 0, 0, 0, 0);
            if (m_timerIdMove != INVALID_ID)
            {
                //设置服务器最近一次移动的时间，定时器初次设置的时候需要设置这个时间
                m_moveTick = NFTime::Now().UnixMSec();

                //发送开始移动事件
                proto_ff::NFEventNoneData startEvent;
                FireExecute(NF_ST_GAME_SERVER, EVENT_START_MOVE, pMaster->Kind(), pMaster->Cid(), startEvent);
            }
            else
            {
                float lenspeed = speed.length();
                NFLogError(NF_LOG_SYSTEMLOG, m_masterCid,
                           "ClientMoveReq...SetTimer failed...cid:{}, pos:{},{},{},curPos:{},{},{}, fpeed:{},speed:{},{},{}, lenspeed:{}",
                           m_masterCid, pos.x, pos.y, pos.z, curPos.x, curPos.y, curPos.z, fspeed, speed.x, speed.y, speed.z, lenspeed);
                return -1;
            }
        }
    }
    //
    m_lastclientMoveTick = NFTime::Now().UnixMSec();
    m_lastClientPos = clientPos;
    if (!stopMoveFlag) //非停止移动的时候，需要设置客户端速度
    {
        SetClientSpeed(speed);
    }
    else
    {
        //停止移动的时候校验一次坐标
        NFPoint3<float> nearpos = pos;
        NFPoint3<float> rightpos = m_lastrightpos;
        NFMap *pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        if (nullptr != pMap)
        {
            NFPoint3<float> tempos;
            if (!pMap->FindNearestPos(nearpos.x, nearpos.z, nearpos.y, &tempos.x, &tempos.z, &tempos.y, nullptr))
            {
                NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                           "[logic] MovePart::ClientMoveReq check move failed,reset pos...cid:{},stopMoveFlag:{},inplaceFlag:{},clientPos:{},{},{}, curpos:{},{},{},mapId:{}, rightpos:{},{},{}  ",
                           pMaster->Cid(), stopMoveFlag, inplaceFlag, clientPos.x, clientPos.y, clientPos.z, curPos.x, curPos.y, curPos.z, mapId,
                           rightpos.x, rightpos.y, rightpos.z);
                //客户端当前位置无效，取上一次正确的坐标
                pos = rightpos;
            }
            else
            {
                pos = tempos;
                rightpos = tempos;
                m_lastrightpos = tempos;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                       "ClientMoveReq check move failed,reset pos...can not find map config,cid:{},stopMoveFlag:{},inplaceFlag:{}, clientPos:{},{},{}, curpos:{},{},{},mapId:{}, clpos:{},{},{}  ",
                       pMaster->Cid(), stopMoveFlag, inplaceFlag, clientPos.x, clientPos.y, clientPos.z, curPos.x, curPos.y, curPos.z, mapId,
                       rightpos.x, rightpos.y, rightpos.z);
            pos = rightpos;
        }
    }

    //设置坐标
    pMaster->SetPos(pos);
    //如果是停止移动，直接取消定时器就行，客户端发送停止移动消息期间，服务器有可能还在模拟移动
    if (stopMoveFlag && m_timerIdMove != INVALID_ID)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
    }

    //设置最近一次的方向
    m_lastDir = dir;
    //设置最近一次客户端发上来的坐标
    m_lastClientPos = clientPos;

    BroadcastMove(pMaster->Cid(), pos, speed, dir, true);
    //
    if (stopMoveFlag)
    {
        proto_ff::NFEventNoneData stopMoveEvent;
        FireExecute(NF_ST_GAME_SERVER, EVENT_END_MOVE, pMaster->Kind(), pMaster->Cid(), stopMoveEvent);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

void NFMovePart::SetClientSpeed(const NFPoint3<float> &speed)
{
    m_clientSpeed = speed;
    float len = m_clientSpeed.length();
    if (len > EPS)
    {
        m_clientUnitVector = m_clientSpeed / len;
    }
}

int NFMovePart::BroadcastMove(uint64_t cid, const NFPoint3<float> &pos, const NFPoint3<float> &speed, const NFPoint3<float> &dir,
                              bool selfFlag/* = false*/)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");

    proto_ff::MoveBroadRsp rsp;
    rsp.set_cid(cid);

    proto_ff::Vector3PB *protoPos = rsp.mutable_pos();
    if (nullptr != protoPos)
    {
        protoPos->set_x(pos.x);
        protoPos->set_y(pos.y);
        protoPos->set_z(pos.z);
    }

    proto_ff::Vector2PB *protoSpeed = rsp.mutable_speed();
    if (nullptr != protoSpeed)
    {
        protoSpeed->set_x(speed.x);
        protoSpeed->set_y(speed.z);
    }

    proto_ff::Vector2PB *protoDir = rsp.mutable_dir();
    if (nullptr != protoDir)
    {
        protoDir->set_x(dir.x);
        protoDir->set_y(dir.z);
    }

    return pMaster->BroadCast(proto_ff::MOVE_BROAD_RSP, rsp, selfFlag);
}

int NFMovePart::TransScene(uint64_t sceneId, const NFPoint3<float> &dstPos, uint64_t mapId, STransParam &transParam)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");

    int ret = proto_ff::RET_SUCCESS;
    {
        uint64_t curSceneId = pMaster->GetSceneId();
        uint64_t curMapId = pMaster->GetMapId();
        if (pMaster->Kind() != CREATURE_PLAYER)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "TransScene...creature kind can not trans scene, this creature cannt, type:{}, cid:{}",
                       pMaster->Kind(), pMaster->Cid());
            return proto_ff::RET_FAIL;
        }

        NFPoint3<float> outPos(0.0, 0.0, 0.0);

        //这里，如果在副本里用传送点，会从传送点配置中读一个地图ID，此时sceneid实际上是地图ID,这里加sceneId == m_pMaster->GetMapId() 只是为了在副本内可传送功能 add by wangxx
        //判断是否在同一个逻辑服里
        NFScene *pScene = NFSceneMgr::Instance(m_pObjPluginManager)->GetScene(sceneId);
        if (nullptr != pScene)
        {
            //同一逻辑服则直接进入场景
            if (pMaster->GetScene() && (curSceneId == sceneId || curMapId == sceneId))
            {
                //传送同一个场景，直接设置坐标
                //
                NFMap *pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(pScene->GetMapId());
                if (nullptr == pMap)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                               "[logic] MovePart::TransScene can not find map cfg  cid={},sceneid={},despos({},{},{}),map:{}", pMaster->Cid(),
                               sceneId, dstPos.x, dstPos.y, dstPos.z, pScene->GetMapId());
                    return proto_ff::RET_SCENE_CAN_NOT_TRAN;
                }

                if (!pMap->FindNearestPos(dstPos.x, dstPos.z, dstPos.y, &outPos.x, &outPos.z, &outPos.y, nullptr))
                {
                    //坐标无效
                    NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                               "[TransScene FindNearestPos failed..  cid={},sceneid={},despos({},{},{}),outpos:{},{},{}", pMaster->Cid(), sceneId,
                               dstPos.x, dstPos.y, dstPos.z, outPos.x, outPos.y, outPos.z);
                    return proto_ff::RET_SCENE_INVALID_DST_POS;
                }

                //当前场景内，直接瞬移，上面已经校验过坐标，这里就不再校验了
                int32_t teleType = 0;
                ret = Teleporting(dstPos, teleType, false);
                if (ret != proto_ff::RET_SUCCESS)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "TransScene same scene failed  cid={},sceneid={},despos({},{},{}),outpos:{},{},{}",
                               pMaster->Cid(), sceneId, dstPos.x, dstPos.y, dstPos.z, outPos.x, outPos.y, outPos.z);
                }
                else
                {
                    OnTransSuccess(transParam);
                }
            }
            else
            {
                ret = pMaster->CanTrans(sceneId, mapId, dstPos, outPos, transParam);
                //检查玩家是否能从当前场景切换到其他场景去
                if (ret != proto_ff::RET_SUCCESS)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                               "TransScene..... CanTrans() Fail....sceneid:{}, mapid:{}, curscene:{}, cid:{},ret:{},outpos:{},{},{} ",
                               sceneId, mapId, curSceneId, pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                    return ret;
                }

                //传送不同场景，则需要走下面流程
                ret = TransSceneInLogic(pScene, dstPos, transParam);
                if (ret != proto_ff::RET_SUCCESS)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                               "TransScene..... TransSceneInLogic Fail....sceneid:{}, mapid:{}, curscene:{}, cid:{},ret:{},outpos:{},{},{} ",
                               sceneId, mapId, curSceneId, pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                }
                else
                {
                    OnTransSuccess(transParam);
                }
            }
        }
        else
        {

/*            //检查玩家是否能从当前场景切换到其他场景去
            if (!pMaster->CanTrans(ret, sceneId, mapId, dstPos, outPos, transParam))
            {
                LogErrFmtPrint("[logic] MovePart::TransScene..... change logic !m_pMaster->CanTrans()....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%u, cid:%lu,ret:%d ,outpos:%f,%f,%f ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                goto Exit0;
            }
            //
            LogicCreatureTransSceneReq req;
            req.set_cursceneid(curSceneId);
            req.set_dstsceneid(sceneId);
            req.set_srclogicid(g_GetLogicService()->GetID());
            CreatureTransParam *protoParam = req.mutable_param();
            if (nullptr == protoParam)
            {
                LogErrFmtPrint("[logic] MovePart::TransScene..... nullptr == protoParam....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%lu, cid:%lu,ret:%d ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret);
                return false;
            }
            SceneTransParam *protoTypeParam = protoParam->mutable_trans_param();
            if (nullptr == protoTypeParam)
            {
                LogErrFmtPrint("[logic] MovePart::TransScene..... nullptr == protoParam....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%lu, cid:%lu,ret:%d ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret);
                return false;
            }
            protoParam->set_kind(m_pMaster->Kind());
            protoParam->set_cid(m_pMaster->Cid());
            protoTypeParam->set_trans_val(transParam.transVal);
            protoTypeParam->set_src_map(transParam.srcMapId);
            protoTypeParam->set_trans_type(transParam.transType);

            if (!m_pMaster->ChangeLogic(sceneId, mapId, dstPos, *protoParam))
            {
                LogErrFmtPrint("[logic] MovePart::TransScene..... m_pMaster->ChangeLogic failed....sceneid:%lu, mapid:%lu, curscene:%lu,curMapId:%lu, cid:%lu,ret:%d ", sceneId, mapId, curSceneId, curMapId, m_pMaster->Cid(), ret);
                return false;
            }
            if (CREATURE_PLAYER == m_pMaster->Kind())
            {
                CreatureTransLogicDBReq dbReq;
                string strData = req.SerializeAsString();
                if (strData.empty())
                {
                    //出错LogicCreatureTransSceneReq
                    m_pMaster->ChangeLogicFail();
                    goto Exit0;
                }
                dbReq.set_trans_data(strData);
                retCode = g_GetLogicService()->SendDB(DB_CREATURE_TRANS_SCENE_REQ, &dbReq,m_pMaster->GetZid());
                if (!retCode)
                {
                    //出错
                    m_pMaster->ChangeLogicFail();
                    goto Exit0;
                }
            }
            else
            {
                //非玩家，直接发送到中心服
                retCode = g_GetLogicService()->SendCenter(LOGIC_CREATURE_TRANS_SCENE_REQ_CENTER, &req, m_pMaster->GetZid());
                if (!retCode)
                {
                    m_pMaster->ChangeLogicFail();
                }
                MMOLOG_PROCESS_ERROR(retCode);
            }*/

        } // end of if (nullptr != pScene)
    } // end of ERetCode ret = RET_SUCCESS;
    //

    return ret;
}

int
NFMovePart::Teleporting(const NFPoint3<float> dstPos, int32_t type /*= (int32_t) proto_ff::MoveTeleportRsp_Type_common*/, bool checkpos /*= true*/)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    //校验坐标的正确性
    NFPoint3<float> pos = dstPos;
    if (checkpos)
    {
        uint64_t mapId = pMaster->GetMapId();
        NFMap *pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        if (nullptr != pMap)
        {
            if (!pMap->FindNearestPos(pos.x, pos.z, pos.y, &pos.x, &pos.z, &pos.y, nullptr))
            {
                NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "Teleporting pMap->FindNearestPos failed...cid:{}, mapid:{}, type:{},pos:[{},{},{}] ",
                           pMaster->Cid(), mapId, (int32_t) type, pos.x, pos.y, pos.z);
                return proto_ff::RET_FAIL;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "Teleporting can not find map cfg...cid:{}, mapid:{}, type:{},pos:[{},{},{}] ",
                       pMaster->Cid(), mapId, (int32_t) type, pos.x, pos.y, pos.z);
            return proto_ff::RET_FAIL;
        }
    }

    //正在模拟移动的，先停止模拟移动
    if (m_timerIdMove != INVALID_ID)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
        //清空路径
        m_curMovePath.Clear();
    }

    //设置坐标
    pMaster->SetPos(pos);

    //广播通知
    proto_ff::MoveTeleportRsp notify;
    notify.set_type(type);
    notify.set_cid(pMaster->Cid());
    proto_ff::Vector3PB *proto = notify.mutable_pos();
    if (nullptr != proto)
    {
        proto->set_x(pos.x);
        proto->set_y(pos.y);
        proto->set_z(pos.z);
    }

    pMaster->BroadCast(proto_ff::MOVE_TELEPORT_RSP, notify, true);
    //
    if (CREATURE_PLAYER == pMaster->Kind())
    {
        //发送瞬移事件, 目前只用到玩家的瞬移
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_TELEPORT_MOVE, pMaster->Kind(), pMaster->Cid(), event);
    }

    return proto_ff::RET_SUCCESS;
}

int NFMovePart::OnTransSuccess(STransParam &transParam)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");

    if (CREATURE_PLAYER != pMaster->Kind())
    {
        return -1;
    }
    /*if (ETransType_Teleport ==  transParam.transType)
    {
        const STeleCfg *pTeleCfg = g_GetMapCfg()->GetTeleCfg(transParam.transVal);
        if (nullptr == pTeleCfg)
        {
            return;
        }
        PackagePart *pPackage = dynamic_cast<PackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
        if (nullptr == pPackage)
        {
            LogErrFmtPrint("[logic] MovePart::OnTransSuccess...cid:%lu, transtype:%d, transval:%ld", m_pMaster->GetCid(), transParam.transType,transParam.transVal);
            return;
        }
        LIST_ITEM lstItem;
        for (auto &iter : pTeleCfg->mapItem)
        {
            SItem item;
            item.nItemID = iter.first;
            item.nNum = iter.second;
            item.byBind = (int8_t)EBindState::EBindState_all;
            lstItem.push_back(item);
        }
        SCommonSource src;
        src.source = S_Teleport;
        src.param1 = transParam.transVal;
        //在传送地图的时候已经判断过背包，这里直接扣除
        pPackage->RemoveItem(lstItem, src);
    }*/
    return 0;
}

int NFMovePart::TransSceneInLogic(NFScene* pDstScene, NFPoint3<float> transPos, STransParam& transParam)
{
    CHECK_NULL(pDstScene);
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    //
    if (CREATURE_PLAYER == pMaster->Kind())
    {
        pMaster->SetCanBeSeenFlag(false);
    }

    //这里先通知客户端加载，再发送场景其它数据
    proto_ff::NotifyLoadMap notifyLoad;
    notifyLoad.set_mapid(pDstScene->GetMapId());
    proto_ff::Vector3PB *prtopos = notifyLoad.mutable_pos();
    prtopos->set_x(transPos.x);
    prtopos->set_y(transPos.y);
    prtopos->set_z(transPos.z);
    pMaster->SendMsgToClient(proto_ff::NOTIFY_CLIENT_LOAD_MAP, notifyLoad);
    //

    if (pMaster->EnterScene(pDstScene->GetSceneId(), transPos, transParam) != proto_ff::RET_SUCCESS)  //到这里是已经进场景了，如果进入失败，则说明玩家信息有误。
    {
        if (CREATURE_PLAYER == pMaster->Kind())
        {
            pMaster->SetCanBeSeenFlag(true);
        }

        //通知前端切场景失败
        proto_ff::TransSceneRsp transRsp;
        transRsp.set_retcode(proto_ff::RET_SCENE_DST_NOT_EXIST);
        transRsp.set_mapid(pDstScene->GetMapId());
        pMaster->SendMsgToClient(proto_ff::NOTIFY_CLIENT_TRANS_SCENE_RSP, notifyLoad);
        NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "TransSceneInLogic failed....cid:{} ,cursceneid:{}, curmapid:{}, dstsceneid:{} ,dstmapid:{} ", pMaster->Cid(), pMaster->GetSceneId(), pMaster->GetMapId(), pDstScene->GetSceneId(), pDstScene->GetMapId());
        return proto_ff::RET_FAIL;
    }
    else
    {
        if (m_timerIdLoadMapTimeout != INVALID_ID)
        {
            DeleteTimer(m_timerIdLoadMapTimeout);
        }

        m_waitLoadMapId = pDstScene->GetMapId();
        m_timerIdLoadMapTimeout = SetTimer(INTERVAL_LOAD_MAP_TIMEOUT, 1, 0, 0, 0, 0);
    }

    return  proto_ff::RET_SUCCESS;
}

int NFMovePart::OnTimer(int timeId, int callcount)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    if (timeId == m_timerIdMove)
    {

    }
    else if (timeId == m_timerIdLoadMapTimeout)
    {
        if (m_waitLoadMapId > 0)
        {
            m_waitLoadMapId = 0;
            m_timerIdLoadMapTimeout = INVALID_ID;
            if (!pMaster->GetCanBeSeenFlag())
            {
                pMaster->SetCanBeSeenFlag(true);
                pMaster->UpdateNineGridLst();
            }
        }
    }
    return 0;
}