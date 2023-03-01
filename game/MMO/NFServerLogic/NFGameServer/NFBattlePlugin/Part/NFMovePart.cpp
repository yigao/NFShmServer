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
    return 0;
}

int NFMovePart::ResumeInit()
{
    return 0;
}

int NFMovePart::Init(NFCreature *pMaster, uint32_t partType, const proto_ff::RoleEnterSceneData &data)
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

int NFMovePart::BroadcastMove(uint64_t cid, const NFPoint3<float>& pos, const NFPoint3<float>& speed, const NFPoint3<float>& dir, bool selfFlag/* = false*/)
{
    NFCreature *pMaster = GetMaster();
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");

    proto_ff::MoveBroadRsp rsp;
    rsp.set_cid(cid);

    proto_ff::Vector3PB* protoPos = rsp.mutable_pos();
    if (nullptr != protoPos)
    {
        protoPos->set_x(pos.x);
        protoPos->set_y(pos.y);
        protoPos->set_z(pos.z);
    }

    proto_ff::Vector2PB* protoSpeed = rsp.mutable_speed();
    if (nullptr != protoSpeed)
    {
        protoSpeed->set_x(speed.x);
        protoSpeed->set_y(speed.z);
    }

    proto_ff::Vector2PB* protoDir = rsp.mutable_dir();
    if (nullptr != protoDir)
    {
        protoDir->set_x(dir.x);
        protoDir->set_y(dir.z);
    }

    return pMaster->BroadCast(proto_ff::MOVE_BROAD_RSP, rsp, selfFlag);
}

int NFMovePart::TransScene(uint64_t sceneId, const NFPoint3<float>& dstPos, uint64_t mapId, STransParam &transParam)
{
    bool result = false;
    bool retCode = false;
    ERetCode ret = RET_SUCCESS;
    {
        uint64_t curSceneId = m_pMaster->GetSceneId();
        uint64_t curMapId = m_pMaster->GetMapId();
        if (m_pMaster->Kind() != CREATURE_PLAYER)
        {
            LogErrFmtPrint("[logic] MovePart::TransScene...creature kind can not trans scene, this creature cannt, type:%d, cid:%lu", m_pMaster->Kind(), m_pMaster->Cid());
            return false;
        }
        Point3<float> outPos(0.0, 0.0, 0.0);
        //这里，如果在副本里用传送点，会从传送点配置中读一个地图ID，此时sceneid实际上是地图ID,这里加sceneId == m_pMaster->GetMapId() 只是为了在副本内可传送功能 add by wangxx
        //判断是否在同一个逻辑服里
        Scene* pScene = g_GetSceneMgr()->GetScene(sceneId);
        if (nullptr != pScene)
        {
            //同一逻辑服则直接进入场景
            if (m_pMaster->GetScene() && (curSceneId == sceneId || curMapId == sceneId))
            {
                //传送同一个场景，直接设置坐标
                //
                Map *pMap = g_GetMapMgr()->GetMap(pScene->GetMapId());
                if (nullptr == pMap)
                {
                    LogErrFmtPrint("[logic] MovePart::TransScene can not find map cfg  cid=%lu,sceneid=%lu,despos(%f,%f,%f),map:%lu", m_pMaster->Cid(), sceneId, dstPos.x, dstPos.y, dstPos.z, pScene->GetMapId());
                    ret = RET_SCENE_CAN_NOT_TRAN;
                    return false;
                }
                if (!pMap->FindNearestPos(dstPos.x, dstPos.z, dstPos.y, &outPos.x, &outPos.z, &outPos.y, nullptr))
                {
                    //坐标无效
                    LogErrFmtPrint("[logic] MovePart::TransScene FindNearestPos failed..  cid=%lu,sceneid=%lu,despos(%f,%f,%f),outpos:%f,%f,%f", m_pMaster->Cid(), sceneId, dstPos.x, dstPos.y, dstPos.z, outPos.x, outPos.y, outPos.z);
                    ret = RET_SCENE_INVALID_DST_POS;
                    return false;
                }
                //当前场景内，直接瞬移，上面已经校验过坐标，这里就不再校验了
                int32_t teleType = 0;
                if (!Teleporting(dstPos, teleType, false))
                {
                    LogErrFmtPrint("[logic] MovePart::TransScene same scene failed  cid=%lu,sceneid=%lu,despos(%f,%f,%f),outpos:%f,%f,%f", m_pMaster->Cid(), sceneId, dstPos.x, dstPos.y, dstPos.z, outPos.x, outPos.y, outPos.z);
                }
                else
                {
                    OnTransSuccess(transParam);
                }
            }
            else
            {

                //检查玩家是否能从当前场景切换到其他场景去
                if (!m_pMaster->CanTrans(ret, sceneId, mapId, dstPos, outPos, transParam))
                {
                    LogErrFmtPrint("[logic] MovePart::TransScene..... !m_pMaster->CanTrans()....sceneid:%lu, mapid:%lu, curscene:%lu, cid:%lu,ret:%d,outpos:%f,%f,%f ", sceneId, mapId, curSceneId, m_pMaster->Cid(), ret, outPos.x, outPos.y, outPos.z);
                    goto Exit0;
                }

                //传送不同场景，则需要走下面流程
                if (!TransSceneInLogic(pScene, dstPos, transParam))
                {
                    LogErrFmtPrint("[logic] MovePart::TransScene failed....cid:%lu ,cursceneid:%lu, dstsceneid:%lu ,dstmapid:%lu,outpos:%f,%f,%f ",
                                   m_pMaster->Cid(), m_pMaster->GetSceneId(), pScene->GetSceneId(), pScene->GetMapId(), outPos.x, outPos.y, outPos.z);
                }
                else
                {
                    OnTransSuccess(transParam);
                }
            }
        }
        else
        {

            //检查玩家是否能从当前场景切换到其他场景去
            if (!m_pMaster->CanTrans(ret, sceneId, mapId, dstPos, outPos, transParam))
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
            }

        } // end of if (nullptr != pScene)
    } // end of ERetCode ret = RET_SUCCESS;
    //
    result = true;
    Exit0:
    if (retResult)
    {
        *retResult = ret;
    }
    return result;
}
