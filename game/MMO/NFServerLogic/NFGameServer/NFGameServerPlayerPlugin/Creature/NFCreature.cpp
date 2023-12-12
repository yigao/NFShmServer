// -------------------------------------------------------------------------
//    @FileName         :    NFCreature.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreature
//
// -------------------------------------------------------------------------

#include "NFCreature.h"

#include <NFLogicCommon/NFEventDefine2.h>

#include "Scene/NFGrid.h"
#include "Scene/NFScene.h"
#include "NFComm/NFCore/NFTime.h"
#include "ClientServerCmd.pb.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "Scene/NFSceneMgr.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFCreatureMgr.h"
#include "NFBattlePlayer.h"
#include "NFLogicCommon/NFCharactorDefine.h"
#include "NFLogicCommon/Attr/NFAttrMgr.h"
#include "Player.pb.h"
#include "proto_svr_event.pb.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "NFGameCommon/NFMath.h"

const uint32_t g_constSendClientCreatureNum = 50;  //每条消息最大人数数据控制,以免视野人数过多，造成消息长度大于底层控制长度

bool CreatureState::EnterState(proto_ff::ECState state)
{
    if (!ECState_IsValid(state)) return false;
    if (nullptr == m_pCreature) return false;
    if (BState(state)) return false;
    m_laststate = m_curstate;
    m_curstate = state;
    if (CREATURE_PLAYER == m_pCreature->Kind())
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, m_pCreature->Cid(), "[logic] CreatureState::EnterState...cid:{}, m_curstate:{}, m_laststate:{} ", m_pCreature->Cid(),
                   m_curstate, m_laststate);
    }

    m_pCreature->OnChangeState(m_curstate, m_laststate);
    return true;
}

NFCreature::NFCreature()
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

NFCreature::~NFCreature()
{
}

int NFCreature::CreateInit()
{
    m_cid = GetGlobalId();     //生物实例id
    m_kind = 0;     //实体类型
    m_sceneId = 0;                //场景id
    m_mapId = 0;                  //地图模板id
    m_sightRange = 0;                //可见视野范围长度
    m_fRadius = 0;                    //人物半径

    m_seeInterval = 0;                //视野更新间隔(毫秒)
    m_lastSeeTime = 0;                //上次更新视野时间
    m_lastUpdateNineTime = 0;        //上次更新9宫格时间
    m_destory = false;            //是否要回收
    m_bCanBeSeen = false;        //是否被见
    m_state.Init(this);

    return 0;
}

int NFCreature::ResumeInit()
{
    return 0;
}

int NFCreature::Init()
{
    m_pFightAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeFightAttrObj(EAttrType::common);
    m_pAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeAttrObj(EAttrType::common);
    return 0;
}

int NFCreature::UnInit()
{
    if (nullptr != m_pFightAttr)
    {
        NFAttrMgr::Instance(m_pObjPluginManager)->FreeFightAttrObj(m_pFightAttr);
        m_pFightAttr = nullptr;
    }
    if (nullptr != m_pAttr)
    {
        NFAttrMgr::Instance(m_pObjPluginManager)->FreeAttrObj(m_pAttr);
        m_pAttr = nullptr;
    }

    m_attrCache.clear();
    m_attrBroadCache.clear();

    return true;
}

int NFCreature::Update(uint64_t tick)
{
    return 0;
}

void NFCreature::SetPos(const NFPoint3<float> &pos)
{
    NFScene *pScene = GetScene();
    NFGrid *pGrid = nullptr;
    bool isSameGrid = false;
    if (!pScene || IsDestory())
    {
        return;
    }


    NFPoint2<uint32_t> newLittleGrid;
    newLittleGrid.x = pos.x / 3;
    newLittleGrid.y = pos.z / 3;
    //
    pGrid = pScene->MoveInScene(this, pos, isSameGrid);
    if (pGrid)
    {
        SetGrid(pGrid);
        m_pos = pos;
        //
        m_lastUpdateNineTime = NFTime::Now().UnixSec();
        bool needSyncPos = false;
        if (!isSameGrid)
        {
            UpdateNineGridLst();
            needSyncPos = true;
        }
        else
        {
            if (m_littleGrid != newLittleGrid)
            {
                m_littleGrid = newLittleGrid;
                UpdateSeeLst();
                needSyncPos = true;
            }
        }

        if (needSyncPos && Kind() == CREATURE_PLAYER)
        {
            proto_ff::SyncScenePos syncPos;
            syncPos.set_map_id(m_mapId);
            syncPos.set_scene_id(m_sceneId);
            NFLogicCommon::NFPoint3ToProto(m_pos, *syncPos.mutable_pos());
            FireLogic(EVENT_SYNC_SCENE_POS, Kind(), GetRoleId(), syncPos);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_cid, "[logic] Creature::SetPos can not find pGrid..cid:{},pos:{}, curpos:{}  ", m_cid, pos.ToString(), m_pos.ToString());
    }
}

void NFCreature::SetDir(const NFPoint3<float> &point)
{
    float length = point.length();
    if (length - 0.0001 > 0)
    {
        m_dir = point / length;
    }
}

NFGrid *NFCreature::GetGrid()
{
    NFScene *pScene = GetScene();
    if (pScene)
    {
        return pScene->GetGrid(m_gridPos.x, m_gridPos.y);
    }
    return NULL;
}

void NFCreature::SetGrid(NFGrid *pGrid)
{
    if (pGrid != nullptr)
    {
        m_gridPos = pGrid->GetGridPos();
    }
    else
    {
        m_gridPos = {0, 0};
    }
}

NFScene *NFCreature::GetScene()
{
    if (m_sceneId == 0)
    {
        return NULL;
    }

    return dynamic_cast<NFScene *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_GAME_SCENE_ID, m_sceneId));
}

float NFCreature::GetSpeed()
{
    int64_t speed = GetAttr(proto_ff::A_SPEED);
    float tmpSpeed = speed / 1000.0f;
    return tmpSpeed;
}

bool NFCreature::EnterNormalState()
{
    return m_state.EnterState(proto_ff::state_normal);
}

bool NFCreature::EnterDeadState()
{
    return m_state.EnterState(proto_ff::state_dead);
}

bool NFCreature::EnterReliveState()
{
    if (!m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(proto_ff::state_normal);
}

bool NFCreature::EnterSeatState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(proto_ff::state_seat);
}

bool NFCreature::LeaveSeatState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(proto_ff::state_normal);
}

bool NFCreature::EnterFightState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(proto_ff::state_fight);
}

bool NFCreature::LeaveFigthState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    if (!m_state.BState(proto_ff::state_fight)) return false;
    return m_state.EnterState(proto_ff::state_normal);
}

bool NFCreature::EnterTransState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    if (m_state.BState(proto_ff::state_trans)) return false;
    return m_state.EnterState(proto_ff::state_trans);
}

bool NFCreature::LeaveTransState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    if (!m_state.BState(proto_ff::state_trans)) return false;
    return m_state.EnterState(proto_ff::state_normal);
}

bool NFCreature::LeaveState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(proto_ff::state_normal);
}

bool NFCreature::BState(proto_ff::ECState state)
{
    return m_state.BState(state);
}

uint8_t NFCreature::GetState()
{
    return m_state.GetState();
}

void NFCreature::SetState(proto_ff::ECState state)
{
    m_state.SetState(state);
}

void NFCreature::OnChangeState(uint8_t curstate, uint8_t laststate)
{
    //通知客户端状态改变
    proto_ff::CreatureStateBroadRsp rsp;
    rsp.set_cid(Cid());
    rsp.set_curstate(curstate);
    rsp.set_beforestate(laststate);
    BroadCast(proto_ff::CREATURE_STATE_BROAD, rsp, true);
}


//添加属性
bool NFCreature::AddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource /*= nullptr*/, bool syn /*= false*/)
{
    if (!AddAttrCache(ANum, attrValue, pSource))
    {
        return false;
    }

    if (syn)
    {
        //同步客户端
        SynAttrToClient();
    }

    return true;
}

//添加属性 不同步到客户端
bool NFCreature::AddAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource /*= nullptr*/)
{
    if (nullptr == m_pAttr || 0 == attrValue) return false;
    if (!CanAddAttr(ANum, attrValue, pSource)) return false;
    //
    int64_t oldVal = m_pAttr->GetAttr(ANum);
    if (proto_ff::A_CUR_HP == ANum && attrValue > 0)
    {
        int64_t maxhp = GetAttr(proto_ff::A_MAX_HP);
        if (oldVal >= maxhp) return true;
        int64_t limitval = maxhp - oldVal;
        if (attrValue > limitval) attrValue = limitval;
        if (0 == attrValue) return true;
    }
    bool chgflag = false;//属性值是否有改变
    bool ret = m_pAttr->AddAttr(ANum, attrValue, &chgflag);
    if (!ret) return false;
    //属性值未改变
    if (!chgflag) return true;
    //
    int64_t newVal = m_pAttr->GetAttr(ANum);

    //计算属性
    CalcAttr(ANum);
    //
    OnAddAttr(ANum, oldVal, attrValue, newVal, pSource);
    //属性改变
    OnAttrChange(ANum, oldVal, newVal, pSource);
    
    return true;
}

//设置属性
bool NFCreature::SetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource /*= nullptr*/, bool syn /*= false*/)
{
    if (!SetAttrCache(ANum, attrValue, pSource))
    {
        return false;
    }
    if (syn)
    {
        /*	if (m_creatureKind == CREATURE_PLAYER && pSource != nullptr && ((ANum == A_CUR_HP)||(ANum == A_MAX_HP) ))
            {
                LogInfoFmtPrint(" Creature::SetAttr cid:%llu source:%d param1:%llu param2:%llu param3:%llu", m_Cid, (int)pSource->source, pSource->param1, pSource->param2, pSource->param3);
            }	*/
        //同步客户端
        SynAttrToClient();
    }
    return true;
}

//设置属性 不同步客户端
bool NFCreature::SetAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource/* = nullptr*/)
{
    if (nullptr == m_pAttr || attrValue < 0) return false;
    if (!CanSetAttr(ANum, attrValue, pSource)) return false;
    int64_t oldVal = m_pAttr->GetAttr(ANum);
    if (proto_ff::A_CUR_HP == ANum)
    {
        int64_t maxhp = GetAttr(proto_ff::A_MAX_HP);
        if (attrValue > maxhp) attrValue = maxhp;
    }
    bool chgflag = false;
    bool ret = m_pAttr->SetAttr(ANum, attrValue, &chgflag);
    if (!ret) return false;
    //属性值未改变
    if (!chgflag) return true;
    
    int64_t newVal = m_pAttr->GetAttr(ANum);
    //计算属性
    CalcAttr(ANum);
    //
    OnSetAttr(ANum, oldVal, attrValue, newVal, pSource);
    //
    OnAttrChange(ANum, oldVal, newVal, pSource);
    //
    return true;
}

//计算属性
void NFCreature::CalcAttr(uint32_t ANum)
{
    if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(ANum))
    {
        if (m_attrCache.size() >= m_attrCache.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_attrCache Space Not Enough");
            return;
        }
        m_attrCache[ANum] = GetAttr(ANum);
    }

    if (NFAttrMgr::Instance(m_pObjPluginManager)->IsBroadClient(ANum))
    {
        if (m_attrBroadCache.size() >= m_attrBroadCache.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_attrBroadCache Space Not Enough");
            return;
        }
        m_attrBroadCache[ANum] = GetAttr(ANum);
    }
}

//计算属性组属性 主要是把属性组中的属性汇总到总属性中 ANum:属性组中的属性ID
void NFCreature::CalcAttrGroup(uint32_t attrgroup, uint32_t ANum, MAP_UINT32_INT64 &mapchg)
{
    if (nullptr == m_pFightAttr) return;
    if (attrgroup <= 0)   return;
    if (ANum > 0)
    {
        m_pFightAttr->CalcAttr(ANum, mapchg);
    }
    else
    {
        m_pFightAttr->CalcAttr(mapchg);
    }
    for (auto& iter : mapchg)
    {
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(iter.first))
            m_attrCache[iter.first] = iter.second;
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsBroadClient(iter.first))
            m_attrBroadCache[iter.first] = iter.second;
    }
}

//属性改变
void NFCreature::OnAttrChange(int32_t ANum, int64_t oldVal, int64_t newVal, SCommonSource *pSource)
{
/*    if (A_CUR_HP == ANum)
    {
        BuffPart* pbuffpart = dynamic_cast<BuffPart*>(GetPart(PART_BUFF));
        if (nullptr != pbuffpart) pbuffpart->OnHpChange(oldVal, newVal, GetAttr(A_MAX_HP));
    }*/
}

//获取属性值
int64_t NFCreature::GetAttr(uint32_t ANum)
{

    if (NFAttrMgr::Instance(m_pObjPluginManager)->ValidFightAttrId(ANum))
    {
        if (nullptr != m_pFightAttr)
        {
            return m_pFightAttr->GetAttr(ANum);
        }
    }
    else
    {
        if (nullptr != m_pAttr)
        {
            return m_pAttr->GetAttr(ANum);
        }
    }

    return 0;
}


int64_t NFCreature::GetAttrGroup(uint32_t attrGroup, uint32_t ANum)
{
    if (nullptr != m_pFightAttr)
    {
        return m_pFightAttr->GetAttrGroup(attrGroup, ANum);
    }
    return 0;
}

//获取该组所有属性值
void NFCreature::GetAttrGroup(uint32_t attrGroup, MAP_UINT32_INT64 &mapattr)
{
    if (nullptr != m_pFightAttr)
    {
        m_pFightAttr->GetAttrGroup(attrGroup, mapattr);
    }
}

// 清除属性组
bool NFCreature::ClearAttrGroup(uint32_t attrGroup, SCommonSource *pSource, bool syn)
{
    if (!ClearAttrGroupCache(attrGroup, pSource))
    {
        return false;
    }
    if (syn)
    {
        SynAttrToClient();
    }
    return true;
}

bool NFCreature::ClearAttrGroupCache(uint32_t attrGroup, SCommonSource *pSource)
{
    if (nullptr == m_pFightAttr) return false;
    MAP_UINT32_INT64 maptemp;
    bool ret = m_pFightAttr->ClearAttrGroup(attrGroup, &maptemp);
    if (!ret) return false;
    if (maptemp.empty()) return true;
    //
    MAP_UINT32_INT64 mapoldchg;
    for (auto &itertemp : maptemp)
    {
        mapoldchg[itertemp.first] = m_pFightAttr->GetAttr(itertemp.first);
    }
    //
    MAP_UINT32_INT64 mapnewchg;
    CalcAttrGroup(attrGroup, 0, mapnewchg);
    //
    for (auto &iterold: mapoldchg)
    {
        auto iternew = mapnewchg.find(iterold.first);
        if (iternew != mapnewchg.end() && iternew->second != iterold.second)
        {
            OnAttrChange(iterold.first, iterold.second, iternew->second, pSource);
        }
    }
    return true;
}

//增加属性组属性
bool NFCreature::AddAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource, bool syn)
{
    if (!AddAttrGroupCache(attrGroup, ANum, val, pSource))
    {
        return false;
    }
    if (syn)
    {
        SynAttrToClient();
    }
    return true;
}

bool NFCreature::AddAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource)
{
    if (nullptr == m_pFightAttr) return false;
    bool chgflag = false;
    int64_t oldval = m_pFightAttr->GetAttrGroup(attrGroup, ANum);
    bool ret = m_pFightAttr->AddAttrGroup(attrGroup, ANum, val, &chgflag);
    if (!ret) return false;
    if (!chgflag) return true;
    //
    MAP_UINT32_INT64 mapchg;
    CalcAttrGroup(attrGroup, ANum, mapchg);
    //
    int64_t newval = m_pFightAttr->GetAttrGroup(attrGroup, ANum);
    if (oldval != newval)
    {
        OnAttrChange(ANum, oldval, newval, pSource);
    }
    return true;
}

//设置属性组属性
bool NFCreature::SetAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource, bool syn)
{
    if (!SetAttrGroupCache(attrGroup, ANum, val, pSource))
    {
        return false;
    }
    if (syn)
    {
        SynAttrToClient();
    }
    return true;
}

bool NFCreature::SetAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource)
{
    if (nullptr == m_pFightAttr) return false;
    bool chgflag = false;
    int64_t oldval = m_pFightAttr->GetAttr(ANum);
    bool ret = m_pFightAttr->SetAttrGroup(attrGroup, ANum, val, &chgflag);
    if (!ret) return false;
    if (!chgflag) return true;
    //
    MAP_UINT32_INT64 mapchg;
    CalcAttrGroup(attrGroup, ANum, mapchg);
    //
    int64_t newval = m_pFightAttr->GetAttr(ANum);
    if (oldval != newval)
    {
        OnAttrChange(ANum, oldval, newval, pSource);
    }
    return true;
}

//设置属性组所有属性
bool NFCreature::SetAttrGroup(uint32_t attrGroup, const MAP_UINT32_INT64& mapattr, SCommonSource* pSource, bool syn)
{
    if (!SetAttrGroupCache(attrGroup, mapattr, pSource))
    {
        return false;
    }
    if (syn)
    {
        SynAttrToClient();
    }
    return true;
}

bool NFCreature::SetAttrGroupCache(uint32_t attrGroup, const MAP_UINT32_INT64& mapattr, SCommonSource* pSource)
{
    if (nullptr == m_pFightAttr) return false;
    MAP_UINT32_INT64 maptemp;
    bool ret = m_pFightAttr->SetAttrGroup(attrGroup, mapattr, &maptemp);
    if (!ret) return false;
    if (maptemp.empty()) return true;
    //
    MAP_UINT32_INT64 mapold;
    for (auto &itertemp : maptemp)
    {
        mapold[itertemp.first] = m_pFightAttr->GetAttr(itertemp.first);
    }
    MAP_UINT32_INT64 mapchg;
    CalcAttrGroup(attrGroup, 0, mapchg);
    //
    for (auto &iterchg : mapchg)
    {
        int64_t oldval = 0;
        auto iterold = mapold.find(iterchg.first);
        if (iterold != mapold.end()) oldval = iterold->second;
        if (oldval != iterchg.second)
        {
            OnAttrChange(iterchg.first, oldval, iterchg.second, pSource);
        }
    }
    return true;
}

void NFCreature::SynAttrToClient()
{
    if (!m_attrBroadCache.empty())
    {
        proto_ff::CreatureAttrBroadRsp rsp;
        rsp.set_cid(Cid());
        for (auto &iter: m_attrBroadCache)
        {
            proto_ff::Attr64 *proto = rsp.add_attr();
            if (nullptr != proto)
            {
                proto->set_id(iter.first);
                proto->set_value(iter.second);
            }
        }
        BroadCast(proto_ff::CREATURE_ATTR_BROAD, rsp, true);
        m_attrBroadCache.clear();
    }
}


int NFCreature::BroadCast(uint32_t nMsgId, const google::protobuf::Message &xData, bool IncludeMyself /*= false*/)
{
    if (CREATURE_PLAYER == m_kind && !IsCanSendMessage())
    {
        return -1;
    }

    MAP_UINT32_MAP_UINT32_SET_UINT64 mapZidGateRoleId;
    uint64_t uid = 0;
    uint32_t gateId = 0;
    uint32_t zid = 0;

    //MAP_UINT32_LST_UINT32 gateClientsMap;
    if (IncludeMyself && m_kind == CREATURE_PLAYER)
    {
        zid = GetZid();
        gateId = GetProxyId();
        uid = GetUid();
        if (gateId > 0)
            mapZidGateRoleId[zid][gateId].insert(uid);
    }

    if (Kind() == CREATURE_PLAYER)
    {
        for (auto iter = m_visionData.m_doublePVPSeeLst.begin(); iter != m_visionData.m_doublePVPSeeLst.end(); iter++)
        {
            NFCreatureVisionDataNode *pData = &(*iter);
            if (pData)
            {
                NFScene* pScene = GetScene();
                if (nullptr != pScene)
                {
                    NFCreature* pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
                    if (nullptr != pCreature && pCreature->Kind() == CREATURE_PLAYER)
                    {
                        NFBattlePlayer *pPlayer = dynamic_cast<NFBattlePlayer *>(pCreature);
                        if (pPlayer && pPlayer->IsCanSendMessage())
                        {
                            zid = pPlayer->GetZid();
                            gateId = pPlayer->GetProxyId();
                            uid= pPlayer->GetUid();
                            if (gateId > 0)
                                mapZidGateRoleId[zid][gateId].insert(uid);
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (auto iter = m_visionData.m_doublePVMSeeLst.begin(); iter != m_visionData.m_doublePVMSeeLst.end(); iter++)
        {
            NFCreatureVisionDataNode *pData = &(*iter);
            if (pData)
            {
                NFScene* pScene = GetScene();
                if (nullptr != pScene)
                {
                    NFCreature* pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
                    if (nullptr != pCreature)
                    {
                        NFBattlePlayer *pPlayer = dynamic_cast<NFBattlePlayer *>(pCreature);
                        if (pPlayer && pPlayer->IsCanSendMessage())
                        {
                            zid = pPlayer->GetZid();
                            gateId = pPlayer->GetProxyId();
                            uid = pPlayer->GetUid();
                            if (gateId > 0)
                                mapZidGateRoleId[zid][gateId].insert(uid);
                        }
                    }
                }
            }
        }
    }

    if (mapZidGateRoleId.empty())
    {
        return 0;
    }

    for (auto &iter: mapZidGateRoleId)
    {
        for (auto &itergate: iter.second)
        {
            SendRedirectMsgToClient(iter.first, itergate.first, itergate.second, nMsgId, xData);
        }
    }

    return 0;
}

int NFCreature::SendRedirectMsgToClient(uint32_t zid, uint32_t gateId, const std::unordered_set<uint64_t>& set, uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendRedirectMsgToProxyServer(NF_ST_GAME_SERVER, gateId, set, nMsgId, xData);
    return 0;
}

int NFCreature::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    if (!IsCanSendMessage())
    {
        return -1;
    }

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_GAME_SERVER, GetProxyId(), NF_MODULE_CLIENT, nMsgId, xData, GetUid());
    return 0;
}

int NFCreature::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_GAME_SERVER, nMsgId, xData, GetUid(), GetRoleId());
    return 0;
}

int NFCreature::SendTransToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t reqTransId, uint32_t rspTransId)
{
    FindModule<NFIServerMessageModule>()->SendTransToSnsServer(NF_ST_GAME_SERVER, nMsgId, xData, reqTransId, rspTransId);
    return 0;
}

int NFCreature::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_GAME_SERVER, nMsgId, xData, GetUid(),
                                                               GetRoleId());
    return 0;
}

int NFCreature::SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t reqTransId, uint32_t rspTransId)
{
    FindModule<NFIServerMessageModule>()->SendTransToWorldServer(NF_ST_GAME_SERVER, nMsgId, xData, reqTransId, rspTransId);
    return 0;
}

int NFCreature::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_GAME_SERVER, GetLogicId(), nMsgId, xData, GetRoleId());
    return 0;
}

int NFCreature::SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t reqTransId, uint32_t rspTransId)
{
    FindModule<NFIServerMessageModule>()->SendTransToLogicServer(NF_ST_GAME_SERVER, GetLogicId(), nMsgId, xData, reqTransId, rspTransId);
    return 0;
}

int NFCreature::SendMsgToCenterServer(uint32_t nMsgId, const google::protobuf::Message& xData)
{
    FindModule<NFIServerMessageModule>()->SendMsgToCenterServer(NF_ST_GAME_SERVER, nMsgId, xData, GetRoleId());
    return 0;
}

int NFCreature::SendTransToCenterServer(uint32_t nMsgId, const google::protobuf::Message& xData, uint32_t reqTransId, uint32_t rspTransId)
{
    FindModule<NFIServerMessageModule>()->SendTransToCenterServer(NF_ST_GAME_SERVER, nMsgId, xData, reqTransId, rspTransId);
    return 0;
}

int NFCreature::FireLogic(uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message, bool self/* = false*/)
{
    return FireBroadcast(NF_ST_GAME_SERVER, NF_ST_LOGIC_SERVER, GetLogicId(), nEventID, bySrcType, nSrcID, message, self);
}

void NFCreature::OnDead(uint64_t killerCid, bool isSync, int64_t lastDamage)
{
    if (EnterDeadState())
    {
        m_attrBroadCache[proto_ff::A_CUR_HP] = 0;
        if (isSync)
        {
            SynAttrToClient();
        }
    }
}

void NFCreature::OnRevive(int64_t curhp)
{
    EnterReliveState();
    //通知状态变化


    /*if (Kind() == CREATURE_PLAYER)
    {
        LogDebugFmtPrint("Creature::OnRevive playercid:%lu curState:%d,curHp:%ld -- 1", GetCid(), GetCurState(), GetAttr(A_CUR_HP));
    }
    bool bEnterRelive = EnterReliveState();
    if (Kind() == CREATURE_PLAYER)
    {
        LogDebugFmtPrint("Creature::OnRevive playercid:%lu curState:%u,curHp:%ld  bEnterRelive:%d -- 2", GetCid(), GetCurState(), GetAttr(A_CUR_HP), bEnterRelive);
    }

    m_attrBroadcastClient.set_cid(m_Cid);
    m_attrBroadcastClient.set_curstate(GetCurState());
    BroadCastData(LOGIC_TO_CLIENT_CREATURE_SYN_ATTR_ALL, (ProtoBufBase*)&m_attrBroadcastClient, true);*/
}

void NFCreature::FindCreatureInScene(LIST_UINT64 &clist)
{
    NFScene *pScene = GetScene();
    if (pScene == NULL) return;

    if (m_sightRange <= 0) return;

    pScene->FindCreatureInScene(clist, m_pos, m_sightRange);
}

void NFCreature::FindCreatureInScene(SET_Creature &setcreature)
{
    NFScene *pScene = GetScene();
    if (pScene == NULL) return;

    if (m_sightRange <= 0) return;

    pScene->FindCreatureInScene(setcreature, m_pos, m_sightRange);
}

void NFCreature::FindSeeListInNineGride(NFCreature *pSrc, std::vector<NFCreature *> *clist, NFPoint3<float> &sorPos)
{
    NFScene *pScene = GetScene();
    if (pScene == NULL) return;

    //找出格子周围的玩家列表
    pScene->FindSeeLstInNineGrid(pSrc, clist, m_pos);
}

void NFCreature::FindDoubleSeeListInNineGride(NFCreature *pSrc, vector<NFCreature *> &clist, NFPoint3<float> &sorPos)
{
    NFScene *pScene = GetScene();
    if (pScene == NULL) return;

    //找出格子周围玩家与非玩家生物列表
    pScene->FindDoubleSeeLstInNineGrid(pSrc, clist, m_pos);
}

void NFCreature::SimpleAddPVPSeeLst(int releation, NFCreature *pCreature)
{
    if (pCreature == nullptr) return;
    if (m_visionData.m_doublePVPSeeLst.size() >= m_visionData.m_doublePVPSeeLst.max_size()) return;
    if (pCreature->m_visionData.m_doublePVPSeeLst.size() >= pCreature->m_visionData.m_doublePVPSeeLst.max_size()) return;
    int pos = m_visionData.AddPVPSeeList(pCreature);
    if (pos == -1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_visionData.AddPVPSeeList failed!");
        return;
    }

    int pos2 = pCreature->GetVisionData().AddPVPSeeList(this);
    if (pos2 == -1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().AddPVPSeeList failed!");
        m_visionData.DelPVPSeeList(pos);
        return;
    }

    auto iter = m_visionData.m_doublePVPSeeLst.GetIterator(pos);
    NF_ASSERT(iter != m_visionData.m_doublePVPSeeLst.end());
    iter->nMeInHisVisionPos = pos2;

    auto iter2 = pCreature->GetVisionData().m_doublePVPSeeLst.GetIterator(pos2);
    NF_ASSERT(iter2 != pCreature->GetVisionData().m_doublePVPSeeLst.end());
    iter2->nMeInHisVisionPos = pos;
}

void NFCreature::SimplePVMAddSeeLst(NFCreature *pCreature)
{
    if (pCreature == nullptr) return;
    if (m_visionData.m_doublePVMSeeLst.size() >= m_visionData.m_doublePVMSeeLst.max_size()) return;
    if (pCreature->m_visionData.m_doublePVMSeeLst.size() >= pCreature->m_visionData.m_doublePVMSeeLst.max_size()) return;

    int pos = m_visionData.AddPVMSeeList(pCreature);
    if (pos == -1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_visionData.AddPVMSeeList failed!");
        return;
    }

    int pos2 = pCreature->GetVisionData().AddPVMSeeList(this);
    if (pos2 == -1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().AddPVMSeeList failed!");
        m_visionData.DelPVMSeeList(pos);
        return;
    }

    auto iter = m_visionData.m_doublePVMSeeLst.GetIterator(pos);
    NF_ASSERT(iter != m_visionData.m_doublePVMSeeLst.end());
    iter->nMeInHisVisionPos = pos2;

    auto iter2 = pCreature->GetVisionData().m_doublePVMSeeLst.GetIterator(pos2);
    NF_ASSERT(iter2 != pCreature->GetVisionData().m_doublePVMSeeLst.end());
    iter2->nMeInHisVisionPos = pos;

    if (this->Kind() != CREATURE_PLAYER && m_visionData.m_doublePVMSeeLst.size() == 1)
    {
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_MONSTER_BEEN_FIRST_PLAYER_SEE, 0, m_cid, event);
    }

    if (pCreature->Kind() != CREATURE_PLAYER && pCreature->GetVisionData().m_doublePVMSeeLst.size() == 1)
    {
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_MONSTER_BEEN_FIRST_PLAYER_SEE, 0, pCreature->Cid(), event);
    }
}

void NFCreature::ReplacePVPSeeList(int relation, NFCreature *pCreature, vector<NFCreature *> &notifyBeenSeeLst)
{
    if (relation >= NEW_SEE_VISION_LESS_HALF_OF_HALF_MAX_SIGHT_RANGE)
    {
        return;
    }

    auto replace = pCreature->GetVisionData().m_doublePVPSeeLst.rend();
    for (auto iter = pCreature->GetVisionData().m_doublePVPSeeLst.rbegin();
         iter != pCreature->GetVisionData().m_doublePVPSeeLst.rend(); iter++)
    {
        NFCreatureVisionDataNode *pData = &(*iter);
        if (pData)
        {
            NFCreature *pOther = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
            if (pOther && pOther != pCreature)
            {
                float otherDict = NFMath::NFPoint2LengthSquare(pCreature->GetPos(), pOther->GetPos());
                if (otherDict > (MAX_CHARACTER_SINGLERANGE_SQUARE / 4.0f))
                {
                    replace = iter;
                    break;
                }
            }
        }
    }

    if (replace != pCreature->GetVisionData().m_doublePVPSeeLst.rend())
    {
        NFCreatureVisionDataNode *pData = &(*replace);
        if (pData)
        {
            NFCreature *pOther = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
            //这里先发送摧毁， 在摧毁， pOther可能不存在, pData可能被摧毁
            if (pOther)
            {
                proto_ff::CreatureDestoryData CreatureDestoryData;
                CreatureDestoryData.add_cids(pCreature->Cid());
                pOther->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, CreatureDestoryData);


                CreatureDestoryData.Clear();
                CreatureDestoryData.add_cids(pOther->Cid());
                pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, CreatureDestoryData);


                pCreature->DelPVPSeeLst(replace.base().m_node->m_self, pOther);

                SimpleAddPVPSeeLst(relation, pCreature);
                notifyBeenSeeLst.push_back(pCreature);
                proto_ff::CreatureCreateData CreatureCreatureData;
                GetVisibleDataToClient(CreatureCreatureData);
                pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, CreatureCreatureData);
            }
        }
    }
}

void NFCreature::AddPVPSeeLst(int relation, NFCreature *pCreature, vector<NFCreature *> &vecBeen)
{
    if (nullptr == pCreature) return;
    if (m_visionData.m_doublePVPSeeLst.size() >= m_visionData.m_doublePVPSeeLst.max_size()) return;
    if (pCreature->m_visionData.m_doublePVPSeeLst.size() < pCreature->m_visionData.m_doublePVPSeeLst.max_size())
    {
        SimpleAddPVPSeeLst(relation, pCreature);
        vecBeen.push_back(pCreature);

        if (pCreature->Kind() == CREATURE_PLAYER)
        {
            proto_ff::CreatureCreateData CreatureCreatureData;
            GetVisibleDataToClient(CreatureCreatureData);
            pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, CreatureCreatureData);
        }
    }
    else
    {
        ReplacePVPSeeList(relation, pCreature, vecBeen);
    }
}

void NFCreature::AddPVMSeeLst(NFCreature *pCreature, vector<NFCreature *> &vecBeen)
{
    if (pCreature == nullptr) return;
    if (m_visionData.m_doublePVMSeeLst.size() >= m_visionData.m_doublePVMSeeLst.max_size()) return;
    if (pCreature->m_visionData.m_doublePVMSeeLst.size() >= pCreature->m_visionData.m_doublePVMSeeLst.max_size()) return;

    SimplePVMAddSeeLst(pCreature);

    vecBeen.push_back(pCreature);

    if (pCreature->Kind() == CREATURE_PLAYER)
    {
        proto_ff::CreatureCreateData CreatureCreatureData;
        GetVisibleDataToClient(CreatureCreatureData);
        pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, CreatureCreatureData);
    }
}

int NFCreature::DelPVMSeeLst(int delpos, NFCreature *pOther)
{
    CHECK_EXPR(delpos >= 0 && delpos < (int) m_visionData.m_doublePVMSeeLst.max_size(), -1, "delpos:{}", delpos);

    auto delIter = m_visionData.m_doublePVMSeeLst.GetIterator(delpos);
    CHECK_EXPR(delIter != m_visionData.m_doublePVMSeeLst.end(), -1, "delIter == m_visionData.m_doublePVMSeeLst.end()");
    auto nextPos = delIter.m_node->m_next;

    auto *pData = &(*delIter);
    if (pData)
    {
        if (pData->nMeInHisVisionPos >= 0)
        {
            if (pOther)
            {
                auto pOtherIter = pOther->GetVisionData().m_doublePVMSeeLst.GetIterator(pData->nMeInHisVisionPos);
                if (pOtherIter != pOther->GetVisionData().m_doublePVMSeeLst.end()
                    && pOtherIter->creatureCid == Cid()
                    && pOtherIter->nMeInHisVisionPos == delpos
                    && pOther->GetVisionData().DelPVMSeeList(pData->nMeInHisVisionPos))
                {
                    pData->nMeInHisVisionPos = -1;
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVMSeeLst.Delete 0 failed!");
                }
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVMSeeLst.Delete 1 failed!");
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVMSeeLst.Delete 2 failed!");
    }

    if (m_visionData.DelPVMSeeList(delpos) == false)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVMSeeLst.Delete 3 failed!");
    }

    if (this->Kind() != CREATURE_PLAYER && m_visionData.m_doublePVMSeeLst.size() == 0)
    {
        proto_ff::NFEventNoneData event;
        FireExecute(NF_ST_GAME_SERVER, EVENT_MONSTER_NO_PLAYER_SEE, 0, Cid(), event);
    }

    if (pOther)
    {
        if (pOther->Kind() != CREATURE_PLAYER && pOther->GetVisionData().m_doublePVMSeeLst.size() == 0)
        {
            proto_ff::NFEventNoneData event;
            FireExecute(NF_ST_GAME_SERVER, EVENT_MONSTER_NO_PLAYER_SEE, 0, pOther->Cid(), event);
        }
    }

    return nextPos;
}

int NFCreature::DelPVPSeeLst(int delpos, NFCreature *pOther)
{
    CHECK_EXPR(delpos >= 0 && delpos < (int) m_visionData.m_doublePVPSeeLst.max_size(), -1, "delpos:{}", delpos);

    auto delIter = m_visionData.m_doublePVPSeeLst.GetIterator(delpos);
    CHECK_EXPR(delIter != m_visionData.m_doublePVPSeeLst.end(), -1, "delIter == m_visionData.m_doublePVPSeeLst.end()");
    auto nextPos = delIter.m_node->m_next;

    auto *pData = &(*delIter);
    if (pData)
    {
        if (pData->nMeInHisVisionPos)
        {
            if (pOther)
            {
                auto pOtherIter = pOther->GetVisionData().m_doublePVPSeeLst.GetIterator(pData->nMeInHisVisionPos);
                if (pOtherIter != pOther->GetVisionData().m_doublePVPSeeLst.end()
                    && pOtherIter->creatureCid == Cid()
                    && pOtherIter->nMeInHisVisionPos == delpos
                    && pOther->GetVisionData().DelPVPSeeList(pData->nMeInHisVisionPos))
                {
                    pData->nMeInHisVisionPos = -1;
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVPSeeLst.Delete 0 failed!");
                }
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVPSeeLst.Delete 1 failed!");
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVPSeeLst.Delete 2 failed!");
    }

    if (m_visionData.DelPVPSeeList(delpos) == false)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "pCreature->GetVisionData().m_doublePVPSeeLst.Delete 3 failed!");
    }

    OnDelPVPSeeLst(pOther);

    return nextPos;
}

bool NFCreature::ViewFliter(NFCreature *pCreature, float dict)
{
    if (pCreature == nullptr || GetScene() != pCreature->GetScene())
    {
        return true;
    }

    if (dict > MAX_CHARACTER_SINGLERANGE_SQUARE)
    {
        return true;
    }

    if (!GetCanBeSeenFlag() || !pCreature->GetCanBeSeenFlag())
    {
        return true;
    }


    return false;
}

void NFCreature::SetCanBeSeenFlag(bool isCanBeSeen)
{
    m_bCanBeSeen = isCanBeSeen;
}

bool NFCreature::GetCanBeSeenFlag()
{
    return m_bCanBeSeen;
}

//判断是否能发送消息
bool NFCreature::IsCanSendMessage()
{
    return false;
}

void NFCreature::GetSeeLst(vector<uint64_t> &vec)
{
    if (Kind() == CREATURE_PLAYER)
    {
        for (auto iter = m_visionData.m_doublePVPSeeLst.begin(); iter != m_visionData.m_doublePVPSeeLst.end(); iter++)
        {
            vec.push_back(iter->creatureCid);
        }
    }
    for (auto iter = m_visionData.m_doublePVMSeeLst.begin(); iter != m_visionData.m_doublePVMSeeLst.end(); iter++)
    {
        vec.push_back(iter->creatureCid);
    }
}

void NFCreature::GetCreatureList(vector<NFCreature *> &vec)
{
    if (Kind() == CREATURE_PLAYER)
    {
        for (auto iter = m_visionData.m_doublePVPSeeLst.begin(); iter != m_visionData.m_doublePVPSeeLst.end(); iter++)
        {
            NFCreature *pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(iter->creatureCid);
            if (pCreature)
            {
                vec.push_back(pCreature);
            }
        }
    }
    for (auto iter = m_visionData.m_doublePVMSeeLst.begin(); iter != m_visionData.m_doublePVMSeeLst.end(); iter++)
    {
        NFCreature *pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(iter->creatureCid);
        if (pCreature)
        {
            vec.push_back(pCreature);
        }
    }
}

void NFCreature::UpdateSeeLst()
{
    m_lastSeeTime = NFTime::Now().UnixSec();
    //根据提供的坐标位置，找对应场景里的生物
    std::vector<NFCreature *> newPVPSeeLst[NEW_SEE_VISION_MAX];
    std::vector<NFCreature *> newPVMSeeLst;
    std::vector<NFCreature *> oldSeeLst;
    std::vector<NFCreature *> notifyBeenSeeLst;
    proto_ff::CreatureCreateData createData;
    proto_ff::CreatureDestoryData destoryData;
    NFCreature *pCreature = nullptr;

    for (int i = 0; i < NEW_SEE_VISION_MAX; i++)
    {
        newPVPSeeLst[i].clear();
    }

    newPVMSeeLst.clear();
    notifyBeenSeeLst.clear();
    createData.Clear();
    destoryData.Clear();
    oldSeeLst.clear();

    for (auto iter = m_visionData.m_doublePVMSeeLst.begin(); iter != m_visionData.m_doublePVMSeeLst.end();)
    {
        NFCreatureVisionDataNode *pData = &(*iter);
        if (pData)
        {
            pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
            if (pCreature)
            {
                //这里是人跟怪的视野列表，人和怪以及怪和人是没有视野范围的，所以这里不需要计算距离
                float dict = NFMath::NFPoint2LengthSquare(GetPos(), pCreature->GetPos());
                if (!ViewFliter(pCreature, dict))
                {
                    pCreature->GetVisionData().chVisionUnitType = (int8_t) EVisionFlag::ALREADY;
                    oldSeeLst.push_back(pCreature);
                }
                else
                {
                    destoryData.add_cids(pCreature->Cid());
                    if (pCreature->Kind() == CREATURE_PLAYER)
                    {
                        proto_ff::CreatureDestoryData CreatureDestoryData;
                        CreatureDestoryData.add_cids(m_cid);
                        pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, CreatureDestoryData);
                    }
                    int pos = DelPVMSeeLst(iter.m_node->m_self, pCreature);
                    iter = m_visionData.m_doublePVMSeeLst.GetIterator(pos);
                    continue;
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_visionData.m_doubleSeeLst can't find the creature cid:{} in the scene!",
                           pData->creatureCid);
                int pos = DelPVMSeeLst(iter.m_node->m_self, pCreature);
                iter = m_visionData.m_doublePVMSeeLst.GetIterator(pos);
                continue;
            }
        }

        iter++;
    }

    if (Kind() == CREATURE_PLAYER)
    {
        for (auto iter = m_visionData.m_doublePVPSeeLst.begin(); iter != m_visionData.m_doublePVPSeeLst.end();)
        {
            NFCreatureVisionDataNode *pData = &(*iter);
            if (pData)
            {
                pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
                if (pCreature && pCreature->Kind() == CREATURE_PLAYER)
                {
                    float dict = NFMath::NFPoint2LengthSquare(GetPos(), pCreature->GetPos());
                    if (!ViewFliter(pCreature, dict))
                    {
                        pCreature->GetVisionData().chVisionUnitType = (int8_t) EVisionFlag::ALREADY;
                        oldSeeLst.push_back(pCreature);
                    }
                    else
                    {
                        destoryData.add_cids(pCreature->Cid());
                        if (pCreature->Kind() == CREATURE_PLAYER)
                        {
                            proto_ff::CreatureDestoryData CreatureDestoryData;
                            CreatureDestoryData.add_cids(m_cid);
                            pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, CreatureDestoryData);
                        }

                        int pos = DelPVPSeeLst(iter.m_node->m_self, pCreature);
                        iter = m_visionData.m_doublePVPSeeLst.GetIterator(pos);
                        continue;
                    }
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_visionData.m_doublePVPSeeLst can't find the pos in the scene!");
                    int pos = DelPVPSeeLst(iter.m_node->m_self, pCreature);
                    iter = m_visionData.m_doublePVPSeeLst.GetIterator(pos);
                    continue;
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, Cid(), "m_visionData.m_doublePVPSeeLst.GetObject failed!");
            }
            iter++;
        }

        if (m_visionData.m_doublePVPSeeLst.size() < m_visionData.m_doublePVPSeeLst.max_size())
        {
            FindSeeListInNineGride(this, newPVPSeeLst, GetPos());
            for (int i = NEW_SEE_VISION_SPECIAL_RELATIONSHIP; i < NEW_SEE_VISION_MAX; i++)
            {
                for (auto it = newPVPSeeLst[i].begin(); it != newPVPSeeLst[i].end(); it++)
                {
                    pCreature = *it;
                    if (pCreature && pCreature->Cid() != m_cid)
                    {
                        AddPVPSeeLst(i, pCreature, notifyBeenSeeLst);
                        if (m_visionData.m_doublePVPSeeLst.size() >= m_visionData.m_doublePVPSeeLst.max_size())
                        {
                            break;
                        }
                    }
                }
            }
        }
    } // end of if (CreatureKind() == CREATURE_PLAYER)

    FindDoubleSeeListInNineGride(this, newPVMSeeLst, GetPos());
    for (auto it = newPVMSeeLst.begin(); it != newPVMSeeLst.end(); it++)
    {
        pCreature = *it;
        if (pCreature && pCreature->Cid() != m_cid)
        {
            AddPVMSeeLst(pCreature, notifyBeenSeeLst);
        }
    }

    for (int i = 0; i < (int) oldSeeLst.size(); i++)
    {
        oldSeeLst[i]->GetVisionData().chVisionUnitType = (int8_t) EVisionFlag::NONE;
    }

    //这里通知客户端删除生物 并且做视野移除
    if (Kind() == CREATURE_PLAYER && destoryData.cids_size() > 0)
    {
        SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, destoryData);
    }

    //有新的生物进入视野
    if (Kind() == CREATURE_PLAYER && !notifyBeenSeeLst.empty())
    {
        uint32_t count = 0;
        uint32_t maxlen = (uint32_t) (MAX_CLIENT_NET_PACK_LENGTH - 2048);
        //先让客户端创建生物实体，再执行该生物的被见逻辑
        for (auto iter = notifyBeenSeeLst.begin(); iter != notifyBeenSeeLst.end(); iter++)
        {
            //通知自己的角色属性信息
            pCreature = *iter;

            //再将对方加入到我自己的视野中
            if (pCreature)
            {
                pCreature->GetVisibleDataToClient(createData);
            }
            count++;
            if ((createData.ByteSize() >= (int32_t) maxlen)
                || (count >= g_constSendClientCreatureNum)
                    )
            {
                SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, createData);
                createData.Clear();
                count = 0;
            }
        }

        size_t createDataSize = createData.ByteSize();
        if (createDataSize > 0)
        {
            if (createDataSize >= MAX_CLIENT_NET_PACK_LENGTH)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "[logic] Creature::UpdateSeeLst...createData.ByteSize() >= MAX_CLIENT_NET_PACK_LENGTH..cid:{},kind:{},bytes:{}",
                           m_cid, m_kind, createDataSize);
            }

            SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, createData);
        }
    }
}

void NFCreature::UpdateNineGridLst()
{
    UpdateSeeLst();
}

void NFCreature::SendAllSeeCreatureListToClient()
{
    uint32_t count = 0;
    uint32_t maxlen = (uint32_t) (MAX_CLIENT_NET_PACK_LENGTH - 2048);
    proto_ff::CreatureCreateData createData;
    NFCreature *pCreature = nullptr;
    std::vector<NFCreature *> vList;
    GetCreatureList(vList);
    //先让客户端创建生物实体，再执行该生物的被见逻辑
    for (auto iter = vList.begin(); iter != vList.end(); iter++)
    {
        //通知自己的角色属性信息
        pCreature = *iter;

        //再将对方加入到我自己的视野中
        if (pCreature)
        {
            pCreature->GetVisibleDataToClient(createData);
        }
        count++;
        if (
                (createData.ByteSize() >= (int32_t) maxlen)
                || (count >= g_constSendClientCreatureNum)
                )
        {
            SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, createData);
            createData.Clear();
            count = 0;
        }
    }
    if (createData.ByteSize() > 0)
    {
        if (createData.ByteSize() >= MAX_CLIENT_NET_PACK_LENGTH)
        {
            NFLogError(NF_LOG_SYSTEMLOG, Cid(),
                       "[logic] Creature::SendAllSeeCreatureListToClient...createData.ByteSize() >= MAX_CLIENT_NET_PACK_LENGTH..cid:{},kind:{},bytes:{}",
                       m_cid, m_kind, createData.ByteSize());
        }

        SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_CREATE, createData);
    }
}

void NFCreature::NoticeNineGridLeave()
{
    if (Kind() == CREATURE_PLAYER)
    {
        for (auto iter = m_visionData.m_doublePVPSeeLst.begin(); iter != m_visionData.m_doublePVPSeeLst.end();)
        {
            NFCreatureVisionDataNode *pData = &(*iter);
            if (pData)
            {
                NFCreature *pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
                if (pCreature)
                {
                    pCreature->GetVisionData().DelPVPSeeList(pData->nMeInHisVisionPos);
                    //通知删除
                    proto_ff::CreatureDestoryData destoryData;
                    destoryData.add_cids(m_cid);
                    pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, destoryData);
                }

                iter = m_visionData.m_doublePVPSeeLst.erase(iter);
                continue;
            }
            else
            {
                iter = m_visionData.m_doublePVPSeeLst.erase(iter);
                continue;
            }
        }
    }

    for (auto iter = m_visionData.m_doublePVMSeeLst.begin(); iter != m_visionData.m_doublePVMSeeLst.end();)
    {
        NFCreatureVisionDataNode *pData = &(*iter);
        if (pData)
        {
            NFCreature *pCreature = NFCreatureMgr::Instance(m_pObjPluginManager)->GetCreature(pData->creatureCid);
            if (pCreature)
            {
                pCreature->GetVisionData().DelPVMSeeList(pData->nMeInHisVisionPos);

                //send event, stop monster ai
                if (pCreature->Kind() != CREATURE_PLAYER && pCreature->GetVisionData().m_doublePVMSeeLst.size() == 0)
                {
                    proto_ff::NFEventNoneData event;
                    FireExecute(NF_ST_GAME_SERVER, EVENT_MONSTER_NO_PLAYER_SEE, 0, pCreature->Cid(), event);
                }

                if (pCreature->Kind() == CREATURE_PLAYER)
                {
                    //通知删除
                    proto_ff::CreatureDestoryData destoryData;
                    destoryData.add_cids(m_cid);
                    pCreature->SendMsgToClient(proto_ff::NOTIFY_CLIENT_CREATURE_DESTORY, destoryData);
                }

            }

            iter = m_visionData.m_doublePVMSeeLst.erase(iter);
            continue;
        }
        else
        {
            iter = m_visionData.m_doublePVMSeeLst.erase(iter);
            continue;
        }
    }
}

//是否可以添加新看到的生物
bool NFCreature::CanAddSeeNewCreature(NFCreature *pCreature, int64_t hateValue)
{
    if (hateValue <= 0) //仇恨值为0
    {
        return false;
    }
    if (nullptr == pCreature)
    {
        return false;
    }

    if (ViewFliter(pCreature, 0)) //视野过滤掉了
    {
        return false;
    }

    return true;
}

int NFCreature::EnterScene(uint64_t sceneId, const NFPoint3<float> &enterPos, const proto_ff::SceneTransParam& transParam)
{
    NFScene *pScene = GetScene();
    if (pScene)
    {
        if (pScene->GetSceneId() == sceneId)
            return proto_ff::RET_FAIL;
        if (pScene->LeaveScene(this) != proto_ff::RET_SUCCESS)
            return proto_ff::RET_FAIL;
    }

    NFScene *pEnterScene = NFSceneMgr::Instance(m_pObjPluginManager)->GetScene(sceneId);
    if (!pEnterScene)
        return proto_ff::RET_FAIL;

    NFGrid *pGrid = pEnterScene->EnterScene(this, enterPos, transParam);
    if (!pGrid)
        return proto_ff::RET_FAIL;

    m_pos = enterPos;
    SetSceneId(sceneId);
    SetMapId(pEnterScene->GetMapId());
    SetGrid(pGrid);

    UpdateNineGridLst();

    proto_ff::EnterSceneEvent enterEvent;
    enterEvent.set_cid(m_cid);
    enterEvent.set_uid(GetUid());
    enterEvent.set_clientid(0);
    enterEvent.set_mapid(m_mapId);
    enterEvent.set_x(enterPos.x * 1000);
    enterEvent.set_y(enterPos.y * 1000);
    enterEvent.set_z(enterPos.z * 1000);
    //enterEvent.transParam = transParam;
    FireExecute(NF_ST_GAME_SERVER, EVENT_ENTER_SCENE, Kind(), m_sceneId, enterEvent);
    //

    proto_ff::ChgSceneEvent chgEvent;
    chgEvent.set_cid(Cid());
    chgEvent.set_enterflag(true);
    FireExecute(NF_ST_GAME_SERVER, EVENT_CHANGE_SCENE, 0, Cid(), chgEvent);

    return proto_ff::RET_SUCCESS;
}

int NFCreature::LeaveScene()
{
    NFScene *pScene = GetScene();

    //场景为空直接返回
    if (!pScene)
        return 0;

    int iRet = pScene->LeaveScene(this);
    if (iRet != proto_ff::RET_SUCCESS)
    {
        return iRet;
    }

    SetSceneId(0);
    SetMapId(0);
    SetGrid(NULL);

    return 0;
}