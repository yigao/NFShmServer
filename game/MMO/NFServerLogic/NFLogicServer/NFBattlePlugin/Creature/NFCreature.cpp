// -------------------------------------------------------------------------
//    @FileName         :    NFCreature.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreature
//
// -------------------------------------------------------------------------

#include "NFCreature.h"
#include "Scene/NFGrid.h"
#include "Scene/NFScene.h"
#include "NFComm/NFCore/NFTime.h"
#include "CSPlayer.pb.h"
#include "ClientServerCmd.pb.h"
#include "NFLogicCommon/NFAttrMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFCreature, EOT_GAME_CREATURE_ID, NFShmObj)

bool CreatureState::EnterState(NFCreature *pCreature, proto_ff::ECState state)
{
    if (!ECState_IsValid(state)) return false;
    if (nullptr == pCreature) return false;
    if (BState(state)) return false;
    m_laststate = m_curstate;
    m_curstate = state;
    if (CREATURE_PLAYER == pCreature->Kind())
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "[logic] CreatureState::EnterState...cid:{}, m_curstate:{}, m_laststate:{} ", pCreature->Cid(),
                   m_curstate, m_laststate);
    }
    else if (CREATURE_PET == pCreature->Kind())
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "[logic] CreatureState::EnterState pet ...cid:{}, m_curstate:{}, m_laststate:{} ", pCreature->Cid(),
                   m_curstate, m_laststate);
    }
    pCreature->OnChangeState(m_curstate, m_laststate);
    return true;
}

NFCreature::NFCreature() : NFShmObj()
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
    m_cid = 0;     //生物实例id
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

    return 0;
}

int NFCreature::ResumeInit()
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
    //pGrid = pScene->MoveInScene(m_Cid, m_pMyGrid, pos, isSameGrid);
    if (pGrid)
    {
        SetGrid(pGrid);
        m_pos = pos;
        //
        m_lastUpdateNineTime = NFTime::Now().UnixSec();
        if (!isSameGrid)
        {
            //UpdateNineGridLst();
        }
        else
        {
            if (m_littleGrid != newLittleGrid)
            {
                m_littleGrid = newLittleGrid;
                //UpdateSeeLst();
            }
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] Creature::SetPos can not find pGrid..cid:{},pos:{},{},{},  curpos:{},{},{}  ", m_cid, pos.x, pos.y,
                   pos.z, m_pos.x,
                   m_pos.y, m_pos.z);
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

    return dynamic_cast<NFScene *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(m_sceneId, EOT_GAME_SCENE_ID));
}

float NFCreature::GetSpeed()
{
    int64_t speed = GetAttr(proto_ff::A_SPEED);
    float tmpSpeed = speed / 1000.0f;
    return tmpSpeed;
}

bool NFCreature::EnterNormalState()
{
    return m_state.EnterState(this, proto_ff::state_normal);
}

bool NFCreature::EnterDeadState()
{
    return m_state.EnterState(this, proto_ff::state_dead);
}

bool NFCreature::EnterReliveState()
{
    if (!m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(this, proto_ff::state_normal);
}

bool NFCreature::EnterSeatState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(this, proto_ff::state_seat);
}

bool NFCreature::LeaveSeatState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(this, proto_ff::state_normal);
}

bool NFCreature::EnterFightState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(this, proto_ff::state_fight);
}

bool NFCreature::LeaveFigthState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    if (!m_state.BState(proto_ff::state_fight)) return false;
    return m_state.EnterState(this, proto_ff::state_normal);
}

bool NFCreature::LeaveState()
{
    if (m_state.BState(proto_ff::state_dead))return false;
    return m_state.EnterState(this, proto_ff::state_normal);
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
    if (nullptr == m_pFightAttr)
    {
        return;
    }
    if (attrgroup <= 0)
    {
        return;
    }
    if (ANum > 0)
    {
        bool chgflag = false;
        m_pFightAttr->CalcAttr(ANum, &chgflag);
        if (chgflag)
        {
            int64_t val = GetAttr(ANum);
            mapchg[ANum] = val;
            if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(ANum))
                m_attrCache[ANum] = val;
            if (NFAttrMgr::Instance(m_pObjPluginManager)->IsBroadClient(ANum))
                m_attrBroadCache[ANum] = val;
        }
    }
    else
    {
        m_pFightAttr->CalcAttr(mapchg);
        for (auto &iter: mapchg)
        {
            if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(ANum))
                m_attrCache[iter.first] = iter.second;
            if (NFAttrMgr::Instance(m_pObjPluginManager)->IsBroadClient(ANum))
                m_attrBroadCache[iter.first] = iter.second;
        }
    }
}

//属性改变
void NFCreature::OnAttrChange(int32_t ANum, int64_t oldVal, int64_t newVal, SCommonSource* pSource)
{
/*    if (A_CUR_HP == ANum)
    {
        BuffPart* pbuffpart = dynamic_cast<BuffPart*>(GetPart(PART_BUFF));
        if (nullptr != pbuffpart) pbuffpart->OnHpChange(newVal, GetAttr(A_MAX_HP));
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
void NFCreature::GetAttrGroup(uint32_t attrGroup, MAP_UINT32_INT64& mapattr)
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
    bool chgflag = false;
    MAP_UINT32_INT64 mapoldchg;
    m_pFightAttr->GetAttr(mapoldchg);
    bool ret = m_pFightAttr->ClearAttrGroup(attrGroup, &chgflag);
    if (!ret) return false;
    if (!chgflag) return true;
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
    int64_t oldval = m_pFightAttr->GetAttrGroup(attrGroup, ANum);
    bool ret = m_pFightAttr->SetAttrGroup(attrGroup, ANum, val, &chgflag);
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


bool NFCreature::BroadCast(uint32_t nMsgId, const google::protobuf::Message &xData, bool IncludeMyself /*= false*/)
{
    return true;
}

bool NFCreature::SendClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return true;
}