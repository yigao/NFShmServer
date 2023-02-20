// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerBase.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerBase
//
// -------------------------------------------------------------------------

#include "NFPlayerBase.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFLogicCommon/NFAttrMgr.h"

NFPlayerBase::NFPlayerBase()
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

NFPlayerBase::~NFPlayerBase()
{
}

int NFPlayerBase::CreateInit()
{
    m_isInited = false;
    m_transNum = 0;
    m_uid = 0;
    m_cid = 0;
    m_proxyId = 0;

    m_status = PLAYER_STATUS_NONE;
    m_curObjCreateTime = NFTime::Now().UnixSec();
    m_createTime = 0;
    m_diconnectTime = 0;
    m_logoutTime = 0;
    m_loginTime = 0;
    m_isDisconnect = false;

    m_lastSendSaveRoleDetailTime = 0;
    m_roleDetailSavedSeq = 0;
    m_roleDetailSavingDBTime = 0;
    m_disonnectType = 0;

    m_color = 0;		//模型颜色
    m_sceneId = 0;      //场景id
    m_mapId = 0;       //地图模板id
    m_pos.CreateInit();
    m_lastMapId = 0;               //上个地图ID
    m_lastSceneId = 0;             //上个场景ID
    m_lastPos.CreateInit();        //上个地图坐标

    m_curstate = 0;
    m_laststate = 0;
    return 0;
}

int NFPlayerBase::ResumeInit()
{
    return 0;
}

int NFPlayerBase::GetTransNum() const
{
    return m_transNum;
}

/**
 * @brief 当前玩家正在使用的trans数量 +1
 */
void NFPlayerBase::IncreaseTransNum()
{
    m_transNum++;
}

/**
 * @brief 当前玩家正在使用的trans数量 -1
 */
void NFPlayerBase::DecreaseTransNum()
{
    m_transNum--;
    if(m_transNum < 0)
    {
        m_transNum = 0;
    }
}

uint64_t NFPlayerBase::GetCid() const
{
    return m_cid;
}

uint64_t NFPlayerBase::Cid() const
{
    return m_cid;
}

void NFPlayerBase::SetCid(uint64_t roleId)
{
    m_cid = roleId;
}

uint64_t NFPlayerBase::GetUid() const
{
    return m_uid;
}

void NFPlayerBase::SetUid(uint64_t uid)
{
    m_uid = uid;
}

uint64_t NFPlayerBase::GetDisonnectType() const
{
    return m_disonnectType;
}

void NFPlayerBase::SetDisconnectType(uint32_t type)
{
    m_disonnectType = type;
}

void NFPlayerBase::SetLastSendRoleDetailSavedTime(uint64_t time)
{
    m_lastSendSaveRoleDetailTime = time;
}

void NFPlayerBase::SetRoleDetailSavedSeq(uint32_t seq)
{
    if (seq >= m_roleDetailSavedSeq)
    {
        m_roleDetailSavedSeq = seq;
    }
}

bool NFPlayerBase::IsRoleDetailNeedSave() const
{
    if (!IsRoleDetailSaved() && NFTime::Now().UnixSec() >= (m_lastSendSaveRoleDetailTime + PLAYER_ONLINESYN_TIME_GAP))
    {
        return true;
    }

    return false;
}

uint64_t NFPlayerBase::GetRoleDetailSavingDBTime() const
{
    return m_roleDetailSavingDBTime;
}

void NFPlayerBase::SetRoleDetailSavingDBTime(uint64_t dwTime)
{
    m_roleDetailSavingDBTime = dwTime;
}

bool NFPlayerBase::IsRoleDetailSaved() const
{
    return GetCurRoleDetailSeq() == m_roleDetailSavedSeq;
}

uint32_t NFPlayerBase::GetCurRoleDetailSeq() const
{
    return GetCurSeq();
}

bool NFPlayerBase::IsRoleDetailNowSaving() const
{
    return (m_roleDetailSavingDBTime != 0) && (m_roleDetailSavingDBTime + TRANS_ACTIVE_TIMEOUT + 5 >= NFTime::Now().UnixSec());
}

PLAYER_STATUS NFPlayerBase::GetStatus() const
{
    return m_status;
}

void NFPlayerBase::SetStatus(PLAYER_STATUS status)
{
    m_status = status;
}

uint64_t NFPlayerBase::GetLastLogoutTime() const
{
    return m_logoutTime;
}

void NFPlayerBase::SetLastLogoutTime(uint64_t lastLogoutTime)
{
    m_logoutTime = lastLogoutTime;
}

bool NFPlayerBase::IsDisconnect() const
{
    return m_isDisconnect;
}

void NFPlayerBase::SetIsDisconnect(bool isDisConnect)
{
    m_isDisconnect = isDisConnect;
    if (m_isDisconnect)
    {
        m_diconnectTime = NFTime::Now().UnixSec();
    }
}

uint64_t NFPlayerBase::GetLastDiconnectTime() const
{
    return m_diconnectTime;
}

int NFPlayerBase::Init(NFIPluginManager* pPluginManager, const ::proto_ff::RoleDBData &dbData)
{
    m_isInited = true;
    m_pFightAttr = NFAttrMgr::Instance(pPluginManager)->MakeFightAttrObj(EAttrType::role);
    m_pAttr = NFAttrMgr::Instance(pPluginManager)->MakeAttrObj(EAttrType::role);
    ReadBaseData(dbData);
    ResetCurSeq();
    return 0;
}

int NFPlayerBase::ReadBaseData(const ::proto_ff::RoleDBData &dbData)
{
    m_cid = dbData.cid();
    m_zid = dbData.zid();
    //
    m_createTime = dbData.base().createtime();
    m_logoutTime = dbData.base().logouttime();
    m_loginTime = dbData.base().logintime();
    //
    m_name = dbData.base().name();
    m_pAttr->SetAttr(proto_ff::A_PROF, dbData.base().prof());
    m_pAttr->SetAttr(proto_ff::A_LEVEL, dbData.base().level());
    m_pAttr->SetAttr(proto_ff::A_EXP, dbData.base().exp());
    m_pAttr->SetAttr(proto_ff::A_CUR_HP, dbData.base().hp());
    m_pAttr->SetAttr(proto_ff::A_FIGHT, dbData.base().fight());
    m_pAttr->SetAttr(proto_ff::A_VIP_LEVEL, dbData.base().vip_level());
    m_pAttr->SetAttr(proto_ff::A_HANGUP_TIME, dbData.base().hanguptime());
    //
    if (dbData.base().has_facade())
    {
        m_color = dbData.base().facade().color();
    }

    m_sceneId = dbData.base().enter_scene_id();
    m_mapId = dbData.base().enter_map_id();
    m_pos.x = dbData.base().enterposx();
    m_pos.y = dbData.base().enterposy();
    m_pos.z = dbData.base().enterposz();

    m_lastMapId = dbData.base().lastmapid();
    m_lastSceneId = dbData.base().lastsceneid();
    m_lastPos.x = dbData.base().lastposx();
    m_lastPos.y = dbData.base().lastposy();
    m_lastPos.z = dbData.base().lastposz();
    return 0;
}

void NFPlayerBase::SetBaseData(proto_ff::RoleDBBaseData* protobase)
{
    if (protobase == NULL) return;

    protobase->set_name(m_name.ToString());
    protobase->set_level(m_pAttr->GetAttr(proto_ff::A_LEVEL));
    protobase->set_prof(m_pAttr->GetAttr(proto_ff::A_PROF));
    protobase->set_exp(m_pAttr->GetAttr(proto_ff::A_EXP));
    protobase->set_hp(m_pAttr->GetAttr(proto_ff::A_CUR_HP));
    protobase->set_fight(m_pAttr->GetAttr(proto_ff::A_FIGHT));
    protobase->set_vip_level(m_pAttr->GetAttr(proto_ff::A_VIP_LEVEL));
    protobase->set_hanguptime(m_pAttr->GetAttr(proto_ff::A_HANGUP_TIME));
    protobase->set_state(GetState());
    //
    protobase->set_createtime(m_createTime);
    protobase->set_logintime(m_loginTime);
    protobase->set_logouttime(m_loginTime);
    //
    protobase->set_enter_scene_id(m_sceneId);
    protobase->set_enter_map_id(m_mapId);
    protobase->set_enterposx(m_pos.x);
    protobase->set_enterposy(m_pos.y);
    protobase->set_enterposz(m_pos.z);
    protobase->set_lastsceneid(m_sceneId);
    protobase->set_lastmapid(m_mapId);
    protobase->set_lastposx(m_pos.x);
    protobase->set_lastposy(m_pos.y);
    protobase->set_lastposz(m_pos.z);

    //填充基础数据外观
    proto_ff::RoleFacadeProto* pFacadeProto = protobase->mutable_facade();
    if (nullptr != pFacadeProto)
    {
        SetFacadeProto(*pFacadeProto);
    }
}

void NFPlayerBase::SetBaseData(proto_ff::RoleDBData& proto)
{
    proto_ff::RoleDBBaseData *protobase =  proto.mutable_base();
    if (nullptr != protobase)
    {
        SetBaseData(protobase);
    }
}

void NFPlayerBase::SetFacadeProto(proto_ff::RoleFacadeProto& outproto)
{
    outproto.set_color(m_color);
    return;
}

int NFPlayerBase::UnInit(NFIPluginManager* pPluginManager)
{
    NFAttrMgr::Instance(pPluginManager)->FreeFightAttrObj(m_pFightAttr);
    NFAttrMgr::Instance(pPluginManager)->FreeAttrObj(m_pAttr);
    return 0;
}

int NFPlayerBase::SaveDB(proto_ff::RoleDBData &dbData)
{
    dbData.set_uid(m_uid);
    dbData.set_cid(m_cid);
    dbData.set_zid(m_zid);

    SetBaseData(dbData);

    return 0;
}

uint64_t NFPlayerBase::GetZid() const
{
    return m_zid;
}

void NFPlayerBase::SetZid(uint64_t zid)
{
    m_zid = zid;
}

uint64_t NFPlayerBase::GetChannelId() const
{
    return m_channelId;
}

void NFPlayerBase::SetChannelId(uint64_t channelId)
{
    m_channelId = channelId;
}

uint32_t NFPlayerBase::GetProxyId() const
{
    return m_proxyId;
}

void NFPlayerBase::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint64_t NFPlayerBase::GetMapId() const
{
    return m_mapId;
}

uint64_t NFPlayerBase::GetSceneId() const
{
    return m_sceneId;
}

NFPoint3<float> NFPlayerBase::GetPos() const
{
    return m_pos;
}

void NFPlayerBase::SetMapId(uint64_t mapId)
{
    m_mapId = mapId;
}

void NFPlayerBase::SetSceneId(uint64_t sceneId)
{
    m_sceneId = sceneId;
}

void NFPlayerBase::SetPos(const NFPoint3<float> &pos)
{
    m_pos = pos;
}

std::string NFPlayerBase::GetName() const
{
    return m_name.ToString();
}

void NFPlayerBase::SetName(const string &name)
{
    m_name = name;
}

uint64_t NFPlayerBase::GetLastMapId() const
{
   return m_lastMapId;
}

uint64_t NFPlayerBase::GetLastSceneId() const
{
    return m_lastSceneId;
}

NFPoint3<float> NFPlayerBase::GetLastPos() const
{
    return m_lastPos;
}

void NFPlayerBase::SetLastMapId(uint64_t mapId)
{
    m_lastMapId = mapId;
}

void NFPlayerBase::SetLastSceneId(uint64_t sceneId)
{
    m_lastSceneId = sceneId;
}

void NFPlayerBase::SetLastPos(const NFPoint3<float> &pos)
{
    m_lastPos = pos;
}

bool NFPlayerBase::BState(proto_ff::ECState state)
{
    return (state == m_curstate);
}

uint8_t NFPlayerBase::GetState()
{
    return m_curstate;
}

void NFPlayerBase::SetState(proto_ff::ECState state)
{
    m_curstate = state;
}

bool NFPlayerBase::EnterState(proto_ff::ECState state)
{
    if (!ECState_IsValid(state)) return false;
    if (BState(state)) return false;
    m_laststate = m_curstate;
    m_curstate = state;
    NFLogInfo(NF_LOG_SYSTEMLOG, m_cid, "Player EnterState...m_curstate:{}, m_laststate:{} ", m_curstate, m_laststate);
    OnChangeState(m_curstate, m_laststate);
    return true;
}

//状态改变
void NFPlayerBase::OnChangeState(uint8_t curstate, uint8_t laststate)
{
    //通知客户端状态改变
    proto_ff::CreatureStateBroadRsp rsp;
    rsp.set_cid(GetCid());
    rsp.set_curstate(curstate);
    rsp.set_beforestate(laststate);
    //BroadCast(CREATURE_STATE_BROAD, &rsp, true);
}
