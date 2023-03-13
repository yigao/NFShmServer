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
#include "DescStoreEx/NFMapDescStoreEx.h"
#include "DescStore/AreaAreaDesc.h"
#include "Creature/NFBattlePlayer.h"
#include "ClientServer.pb.h"

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
        case proto_ff::CLIENT_LOAD_MAP_FINISH:
        {
            ClientLoadMapFinshReq(msgId, packet);
            break;
        }
            ////////////////////////////////////冥想数据///////////////////////////////////////
        case proto_ff::CLIENT_TO_LOGIC_PLAYER_SEAT_REQ:
        {
            ClientSeatReq(msgId, packet);
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

int NFMovePart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_MOVE_REQ, BATTLE_PART_MOVE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_LOAD_MAP_FINISH, BATTLE_PART_MOVE);

    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_PLAYER_SEAT_REQ, BATTLE_PART_MOVE);

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
        if (m_timerIdMove == INVALID_ID)
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
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

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
            return proto_ff::RET_FAIL;
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

int NFMovePart::TransSceneInLogic(NFScene *pDstScene, NFPoint3<float> transPos, STransParam &transParam)
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
        NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "TransSceneInLogic failed....cid:{} ,cursceneid:{}, curmapid:{}, dstsceneid:{} ,dstmapid:{} ",
                   pMaster->Cid(), pMaster->GetSceneId(), pMaster->GetMapId(), pDstScene->GetSceneId(), pDstScene->GetMapId());
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

    return proto_ff::RET_SUCCESS;
}

int NFMovePart::OnTimer(int timeId, int callcount)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    if (timeId == m_timerIdMove)
    {
        OnMoveTimer();
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

int NFMovePart::OnMoveTimer()
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    uint64_t curtick = NFTime::Now().UnixMSec();
    int64_t intertick = curtick - m_moveTick;
    //
    if (CREATURE_PLAYER == pMaster->Kind())
    {
        bool stopFlag = false;
        uint64_t interMSec = curtick - m_lastclientMoveTick;
        //超过6秒还没收到的客户端移动的消息消息，自动停止
        //避免客户端没有发停止过来，服务器一直走下去
        if (interMSec >= INTERVAL_CLIENT_MOVE_TIMEOUT)
        {
            stopFlag = true;
            NFLogError(NF_LOG_SYSTEMLOG, m_masterCid,
                       "MovePart::ClientMoveTimer...move timeout...auto stop move cid:{},m_clientMoveTime:{},tick:{},interMSec:{},intertick:{}",
                       pMaster->Cid(), m_lastclientMoveTick, curtick, interMSec, intertick);
        }
        //
        MoveBySimulate(intertick, stopFlag);
    }
    else
    {

        MoveByPath(intertick);
    }

    //设置服务器移动时间
    m_moveTick = curtick;
    //停止移动的话，需要发送事件
    if (m_timerIdMove == INVALID_ID)
    {
        //发送停止移动事件
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_END_MOVE, pMaster->Kind(), pMaster->Cid(), event);
    }

    return 0;
}

//模拟客户端移动(玩家移动) intertick: 间隔时间，单位：毫秒,  stopFlag:是否停止移动
int NFMovePart::MoveBySimulate(int64_t intertick, bool stopFlag /*= false*/)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    //间隔时间
    float ftick = intertick / 1000.0f;
    //坐标
    NFPoint3<float> curpos = pMaster->GetPos();
    NFPoint3<float> oldpos = curpos;
    //
    if (stopFlag)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
        m_curMovePath.Clear();
    }
    //
    if (intertick > 0)
    {
        curpos = curpos + m_clientUnitVector * ftick * pMaster->GetSpeed();
    }

    NFLogDebug(NF_LOG_SYSTEMLOG, pMaster->Cid(), "[logic] MovePart::MoveBySimulate..ftick:{},stopFlag:{},oldpos:[{},{},{}],curpos:[{},{},{}]", ftick,
               stopFlag, oldpos.x, oldpos.y, oldpos.z, curpos.x, curpos.y, curpos.z);
    //
    if (stopFlag) //如果是停止移动，服务器需要校验下最终的坐标
    {
        NFPoint3<float> zerospeed(0.0f, 0.0f, 0.0f);
        NFPoint3<float> newpos = curpos;
        uint64_t mapid = pMaster->GetMapId();
        NFMap *pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapid);
        if (nullptr != pMap)
        {
            if (!pMap->FindNearestPos(curpos.x, curpos.z, curpos.y, &curpos.x, &curpos.z, &curpos.y, nullptr))
            {
                //找不到可行走的点，直接设置为上一次客户端正确的坐标
                NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                           "MoveBySimulate  FindNearestPos failed cid:{},intertick:{},ftick:{},oldpos:{},{},{}, newpos:{},{},{},  curpos:{},{},{}, m_clientUnitVector:{},{},{},fspeed:{},rightpos:{},{},{}",
                           pMaster->Cid(), intertick, ftick, oldpos.x, oldpos.y, oldpos.z, newpos.x, newpos.y, newpos.z, curpos.x, curpos.y, curpos.z,
                           m_clientUnitVector.x, m_clientUnitVector.y, m_clientUnitVector.z, pMaster->GetSpeed(), m_lastrightpos.x,
                           m_lastrightpos.y, m_lastrightpos.z);
                curpos = m_lastrightpos;
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                       "[logic] MoveBySimulate  not find map cfg cid:{}, mapid:{}, intertick:{},ftick:{},oldpos:{},{},{}, curpos:{},{},{}, m_clientUnitVector:{},{},{},fspeed:{}, rightpos:[{},{},{}]",
                       pMaster->Cid(), mapid, intertick, ftick, oldpos.x, oldpos.y, oldpos.z, curpos.x, curpos.y, curpos.z, m_clientUnitVector.x,
                       m_clientUnitVector.y, m_clientUnitVector.z, pMaster->GetSpeed(), m_lastrightpos.x, m_lastrightpos.y, m_lastrightpos.z);
            curpos = m_lastClientPos;
        }

        if (intertick > 0) //有移动间隔才会计算朝向
        {
            //计算朝向
            m_lastDir = CalDir(curpos, oldpos);
        }

        //广播通知停止移动
        BroadcastMove(pMaster->Cid(), curpos, zerospeed, m_lastDir, true);
        //停止移动时的坐标是校验过的，肯定是正确的，把上一次客户端正确的坐标设置为当前坐标
        m_lastrightpos = curpos;
        //设置坐标
        pMaster->SetPos(curpos);
    }
    else if (intertick > 0) //有移动间隔才会设置当前坐标
    {
        pMaster->SetPos(curpos);
    }

    return 0;
}

//计算朝向
NFPoint3<float> NFMovePart::CalDir(const NFPoint3<float> &dstpos, const NFPoint3<float> &srcpos)
{
    NFPoint3<float> dir = dstpos - srcpos;
    dir.y = 0;
    return dir;
}

//通过路径移动 intertick: 间隔时间，单位：毫秒
int NFMovePart::MoveByPath(int64_t intertick, bool stopFlag)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    NFPoint3<float> oldpos = pMaster->GetPos();

    //通过移动距离确定路径上的坐标
    if (intertick > 0)
    {
        //间隔时间
        float fsec = intertick / 1000.0f;
        //间隔时间内移动的距离
        float fdis = fsec * pMaster->GetSpeed();
        NFPoint3<float> retpos;
        //
        bool reachFlag = m_curMovePath.MapPathDistanceToPoint(fdis, retpos);

        //新的朝向和朝向点
        NFPoint3<float> newdir = CalDir(retpos, oldpos);
        NFPoint3<float> newdot = CalDotByDir(newdir);
        bool broadFlag = false;//是否需要广播客户端
        //这里是计算生物朝向是否有改变，具体的计算方式保持和客户端一致
        float fdiff = newdot.x * m_lastDirDot.x + newdot.z * m_lastDirDot.z;
        if (fdiff < 1.0f)
        {
            //朝向有改变，需要广播通知给客户端
            broadFlag = true;
        }
        //计算新的速度
        NFPoint3<float> newspeed(0.0f, 0.0f, 0.0f);
        if (reachFlag || stopFlag)
        {
            broadFlag = true; //停止移动或者已达到目标点，需要广播
            DeleteTimer(m_timerIdMove);
            m_timerIdMove = INVALID_ID;
            //清空路径
            m_curMovePath.Clear();
        }
        else
        {
            //新速度
            newspeed = CalSpeedByDot(newdot, 1.0f, pMaster->GetSpeed());
        }

        //广播通知
        if (broadFlag)
        {
            BroadcastMove(pMaster->Cid(), retpos, newspeed, newdir, true);
        }

        //LogDebugFmtPrint("[logic] MovePart::MoveByPath....cid:%lu,intertick:%ld, newspeed:%f,%f,%f, retpos:%f,%f,%f",m_pMaster->Cid(), intertick,newspeed.x,newspeed.y,newspeed.z,retpos.x,retpos.y,retpos.z);
        //设置新的朝向
        m_lastDir = newdir;
        //设置新的朝向点
        m_lastDirDot = newdot;
        //设置新的速度
        SetClientSpeed(newspeed);
        //设置坐标
        pMaster->SetPos(retpos);
    }
    else if (stopFlag)
    {
        DeleteTimer(m_timerIdMove);
        m_timerIdMove = INVALID_ID;
        //清空路径
        m_curMovePath.Clear();

        //间隔时间为0，表示没有移动，直接广播停止即可
        NFPoint3<float> zerospeed(0.0f, 0.0f, 0.0f);
        BroadcastMove(pMaster->Cid(), oldpos, zerospeed, m_lastDir, true);
        //
        //LogDebugFmtPrint("[logic] MovePart::MoveByPath 111....cid:%lu,intertick:%ld, newspeed:%f,%f,%f, retpos:%f,%f,%f", m_pMaster->Cid(), intertick, zerospeed.x, zerospeed.y, zerospeed.z, oldpos.x, oldpos.y, oldpos.z);
    }

    return 0;
}

//根据计算单位朝向
NFPoint3<float> NFMovePart::CalDotByDir(const NFPoint3<float> &dir)
{
    float flen = CarmackSqrt((dir.x * dir.x + dir.z * dir.z));
    NFPoint3<float> dot; //新的朝向点
    if (flen > EPS)
    {
        dot = dir / flen;
    }
    return dot;
}

//根据朝向点计算速度  dot:朝向点， fsec:间隔时间，单位：秒，  fspeed：速度，单位：m/s
NFPoint3<float> NFMovePart::CalSpeedByDot(const NFPoint3<float> &dot, float fsec, float fspeed)
{
    return (dot * fsec * fspeed);
}

int NFMovePart::ClientLoadMapFinshReq(uint32_t msgId, NFDataPackage &packet)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    if (m_waitLoadMapId <= 0)
    {
        if (m_timerIdLoadMapTimeout != INVALID_ID)
        {
            NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(),
                       "ClientLoadMapFinshReq.... m_waitLoadMapId <= 0....cid:{},m_waitLoadMapId:{},curmap:{},curscene:{},beensee:{} ", pMaster->Cid(),
                       m_waitLoadMapId, pMaster->GetMapId(), pMaster->GetSceneId(), pMaster->GetCanBeSeenFlag());
            return -1;
        }

        return 0;
    }

    NFLogError(NF_LOG_SYSTEMLOG, pMaster->Cid(), "ClientLoadMapFinshReq... cid:{},m_waitLoadMapId:{},curmap:{},curscene:{},beensee:{} ",
               pMaster->Cid(), m_waitLoadMapId, pMaster->GetMapId(), pMaster->GetSceneId(), pMaster->GetCanBeSeenFlag());
    //
    m_waitLoadMapId = 0;
    if (m_timerIdLoadMapTimeout != INVALID_ID)
    {
        DeleteTimer(m_timerIdLoadMapTimeout);
        m_timerIdLoadMapTimeout = INVALID_ID;
    }

    if (!pMaster->GetCanBeSeenFlag())
    {
        pMaster->SetCanBeSeenFlag(true);
        pMaster->UpdateNineGridLst();
    }

    return 0;
}

int NFMovePart::ClientSeatReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::PlayerSeatReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, proto_ff::RET_FAIL, "pMaster == NULL");

    int32_t opt = req.opt();

    proto_ff::PlayerSeatRsp rsp;
    rsp.set_opt(opt);

    if (opt == 1 && !pMaster->BState(proto_ff::state_normal))
    {
        rsp.set_ret(proto_ff::RET_PLAYER_SEAT_STATE_ERROR);
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }

    if (opt != 1 && !pMaster->BState(proto_ff::state_seat))
    {
        rsp.set_ret(proto_ff::RET_PLAYER_SEAT_STATE_ERROR);
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }

    NFScene *pScene = pMaster->GetScene();
    if (nullptr == pScene)
    {
        rsp.set_ret(proto_ff::RET_FAIL);
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }

    uint64_t map_id = pScene->GetMapId();
    auto pMapCfg = MapMapDesc::Instance(m_pObjPluginManager)->GetDesc(map_id);
    if (!pMapCfg)
    {
        rsp.set_ret(proto_ff::RET_FAIL);
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }

    if (opt == 1 && pMapCfg->m_maptype != 1)
    {
        rsp.set_ret(proto_ff::RET_PLAYER_SEAT_MAP_NOT_SEAT);
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
        return -1;
    }

    bool bOpt = true;
    if (opt == 1)
    {
        bOpt = pMaster->EnterSeatState();
    }
    else
    {
        bOpt = pMaster->LeaveSeatState();
    }

    int32_t ret = bOpt ? proto_ff::RET_SUCCESS : proto_ff::RET_FAIL;
    rsp.set_ret(ret);

    rsp.set_exp(0);
    rsp.set_online_hangup_time(0);
    rsp.set_online_all_exp(0);

    pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SEAT_RSP, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}
