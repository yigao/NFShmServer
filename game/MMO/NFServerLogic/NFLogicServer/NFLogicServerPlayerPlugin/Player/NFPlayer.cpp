// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.cpp
//
// -------------------------------------------------------------------------

#include "NFPlayer.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFPlayerMgr.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "AllProtocol.h"
#include "NFLogicCommon/Attr/NFAttrMgr.h"
#include "Facade/NFGrowPart.h"
#include "NFGodEvilPart.h"
#include "NFGameCommon/NFMath.h"
#include "DescStoreEx/RoleDescEx.h"
#include "NFVipPart.h"
#include "Skill/NFSkillPart.h"
#include "Facade/NFPetPart.h"
#include "DescStore/AttributeAttributeDesc.h"
#include "NFComm/NFCore/NFTimeUtility.h"
#include "Skill/NFBuffPart.h"
#include "Achievement/NFAchievementPart.h"
#include "NFRankPart.h"
#include "DescStoreEx/AchievementDescEx.h"

NFPlayer::NFPlayer()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFPlayer::~NFPlayer()
{

}

int NFPlayer::CreateInit()
{
    m_cid = 0;
    m_uid = 0;
    m_zid = 0;
    
    ///////////////////////////
    m_iStatus = proto_ff::PLAYER_STATUS_NONE;
    m_lastDiconnectTime = 0;
    m_lastCreateTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;
    m_lastSavingDBTime = 0;
    m_iTransNum = 0;
    m_saveDBTimer = INVALID_ID;
    m_pPart.resize(PART_MAX);
    /////////////////////////
    
    m_gameId = 0;
    m_proxyId = 0;
    m_snsId = 0;
    m_worldId = 0;
    
    //////////////////////
    m_sceneId = 0;//场景id
    m_mapId = 0;//地图模板id
    m_lastSceneId = 0;             //上个场景ID
    m_lastMapId = 0;               //上个地图ID
    m_color = 0;                    //模型颜色
    m_createTime = 0;                    //创建时间（UTC时间）
    m_createZeroTime = 0;                //创角那一天的0点时间(UTC时间）
    m_loginTime = 0;                    //上一次登陆的时间（UTC时间）
    m_logoutTime = 0;                //上一次下线时间（UTC时间）
    m_totalLoginDay = 0;
    m_loginDayTime = 0;
    
    m_dayPrestige = 0;            //今日获得的声望
    m_resetPrestige = 0;        //今日获得声望重置时间
    m_lastHpTick = 0;                //上一次同步HP的时间
    m_memCount = 0;                    //队伍成员数量(有队伍才有效，用于计算队伍经验加成)
    m_headFlag = 0;                //玩家头顶显示掉落归属标记
    m_subpackType = 0;            //分包类型 1 小包，2 大包
    m_subpackFetch = 0;            //是否领取分包奖励 0 未领取，1 已领取
    
    m_state = proto_ff::state_init;
    
    m_calcfight = false;        //是否需要计算战力
    m_petFight = 0;             //宠物系统的战斗力(只是缓存在玩家身上)
    m_calcpetfight = false;     //是否需要计算宠物系统的战斗力
    return 0;
}

int NFPlayer::ResumeInit()
{
    return 0;
}

int NFPlayer::OnTimer(int timeId, int callcount)
{
    if (timeId == m_saveDBTimer)
    {
        SaveToDB();
    }
    return 0;
}

void NFPlayer::Tick()
{
    switch (m_iStatus)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t) NFTime::Now().UnixSec() - m_lastCreateTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;
            
            if (m_iTransNum > 0 || FindModule<NFICoroutineModule>()->IsExistUserCo(m_cid))
            {
                if ((uint64_t) NFTime::Now().UnixSec() - m_lastCreateTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }
            
            if (IsInBattle())
            {
                if ((uint64_t) NFTime::Now().UnixSec() - m_lastCreateTime < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }
            
            SetStatus(proto_ff::PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetCid(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_DEAD", GetCid());
        }
            break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
            Update();
        }
            break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t) NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;
            
            if (m_iTransNum > 0 || FindModule<NFICoroutineModule>()->IsExistUserCo(m_cid))
            {
                if ((uint64_t) NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }
            
            if (IsInBattle() || IsInTransSceneing())
            {
                if ((uint64_t) NFTime::Now().UnixSec() - GetLastDisconnectTime() < LOGIC_PLAYER_CLIENT_DISCONNECT_WAITTIME_IN_GAME)
                    break;
            }
            
            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogtouTime(NFTime::Now().UnixSec());
            MarkDirty();
            NFLogInfo(NF_LOG_SYSTEMLOG, GetCid(), "player:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetCid());
        }
            break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (FindModule<NFICoroutineModule>()->IsExistUserCo(m_cid))
            {
                break;
            }
            
            if (!IsUrgentNeedSave())
            {
                if (m_iTransNum <= 0)
                {
                    OnLogout();
                }
            } else if (!IsInSaving())
            {
                if ((m_lastSavingDBTime + LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME < (uint64_t) NFTime::Now().UnixSec() &&
                    m_lastSavingDBTime + 86400 > (uint64_t) NFTime::Now().UnixSec()) || m_pObjPluginManager->IsServerStopping())
                {
                    SendTransToDB(TRANS_SAVEROLEDETAIL_LOGOUT);
                }
            }
            break;
        }
    }
}

int NFPlayer::Init(const proto_ff::RoleDBData &dbData)
{
    SetStatus(proto_ff::PLAYER_STATUS_NONE);
    m_pFightAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeFightAttrObj(EAttrType::role);
    CHECK_NULL(m_pFightAttr);
    m_pAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeAttrObj(EAttrType::role);
    CHECK_NULL(m_pAttr);
    
    LoadFromDB(dbData);
    InitConfig(dbData);
    std::vector<NFPart *> vec;
    
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        m_pPart[i] = CreatePart(i, dbData);
        if (nullptr == m_pPart[i])
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Create Part Failed, playerId:{} part:{}", m_cid, i);
            for (int i = 0; i < (int) vec.size(); i++)
            {
                FindModule<NFISharedMemModule>()->DestroyObj(vec[i]);
            }
            return proto_ff::RET_FAIL;
        }
        vec.push_back(m_pPart[i].GetPoint());
    }
    
    /**
     * @brief
     */
    uint32_t startMS = NFRandInt(1000, LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000);
    m_saveDBTimer = SetTimer(LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME * 1000, 0, 0, 0, 0, startMS);
    
    return 0;
}

int NFPlayer::UnInit()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            RecylePart(m_pPart[i]);
        }
    }
    
    NFAttrMgr::Instance(m_pObjPluginManager)->FreeFightAttrObj(m_pFightAttr);
    NFAttrMgr::Instance(m_pObjPluginManager)->FreeAttrObj(m_pAttr);
    
    return 0;
}

int NFPlayer::LoadFromDB(const proto_ff::RoleDBData &data)
{
    ReadBaseData(data);
    return 0;
}

int NFPlayer::InitConfig(const proto_ff::RoleDBData &data)
{
    return 0;
}

int NFPlayer::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin(playerInfo);
        }
    }
    return 0;
}

int NFPlayer::OnLogin()
{
    SetStatus(proto_ff::PLAYER_STATUS_ONLINE);
    m_loginTime = NFTime::Now().UnixSec();
    MarkDirty();
    
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin();
        }
    }
    return 0;
}

int NFPlayer::OnLogout()
{
    m_logoutTime = NFTime::Now().UnixSec();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogout();
        }
    }
    
    SetStatus(proto_ff::PLAYER_STATUS_DEAD);
    return 0;
}

int NFPlayer::OnDisconnect()
{
    m_lastDiconnectTime = NFTime::Now().UnixSec();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnDisconnect();
        }
    }
    return 0;
}

int NFPlayer::OnReconnect()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnReconnect();
        }
    }
    return 0;
}

int NFPlayer::Update()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->Update();
        }
    }
    return 0;
}

int NFPlayer::SaveDB(proto_ff::RoleDBData &data)
{
    data.set_cid(GetCid());
    data.set_uid(GetUid());
    data.set_zid(GetZid());
    SetBaseData(data);
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->SaveDB(data);
        }
    }
    return 0;
}

int NFPlayer::DailyZeroUpdate()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->DailyZeroUpdate();
        }
    }
    return 0;
}

int NFPlayer::WeekZeroUpdate()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->WeekZeroUpdate();
        }
    }
    return 0;
}

int NFPlayer::MonthZeroUpdate()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->MonthZeroUpdate();
        }
    }
    return 0;
}

void NFPlayer::IncreaseTransNum()
{
    ++m_iTransNum;
}

void NFPlayer::DecreaseTransNum()
{
    --m_iTransNum;
    if (m_iTransNum < 0)
    {
        m_iTransNum = 0;
    }
}

int NFPlayer::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    CHECK_EXPR(m_proxyId > 0, -1, "player disconnect, SendMsgToClient msgId:{} msgData:{}", nMsgId, xData.DebugString());
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_LOGIC_SERVER, m_proxyId, nMsgId, xData, m_uid);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_cid, "SendMsgToClient msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_LOGIC_SERVER, nMsgId, xData, m_cid);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_cid, "SendMsgToSnsServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, nMsgId, xData, m_cid);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_cid, "SendMsgToWorldServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

int NFPlayer::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    int iRet = FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_LOGIC_SERVER, GetGameId(), nMsgId, xData, m_cid);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_cid, "SendMsgToGameServer msgId:{} msgData:{} iRet:{}", nMsgId, xData.DebugString(), GetErrorStr(iRet));
    return iRet;
}

bool NFPlayer::IsNeedSave()
{
    if (IsUrgentNeedSave())
    {
        return true;
    }
    
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i] && m_pPart[i]->IsUrgentNeedSave())
        {
            return true;
        }
    }
    
    return false;
}

int NFPlayer::SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason, bool bForce)
{
    if (IsNeedSave())
    {
        if (bForce || NFTime::Now().UnixSec() - m_lastSavingDBTime >= LOGIC_SERVER_SAVE_PLAYER_TO_DB_TIME)
        {
            SendTransToDB(iReason);
        }
    }
    return 0;
}

int NFPlayer::SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason)
{
    NFTransSaveDB *pSave = (NFTransSaveDB *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_SAVE_PLAYER);
    CHECK_EXPR(pSave, -1, "Create Trans:NFTransSaveDB Failed! ");
    
    pSave->Init(this, 0);
    int iRet = pSave->SaveDB(iReason);
    if (iRet != 0)
    {
        pSave->SetFinished(iRet);
    }
    
    return iRet;
}

int NFPlayer::OnSaveDB(bool success, uint32_t seq)
{
    m_lastSavingDBTime = 0;
    if (success && seq == GetAllSeq())
    {
        ClearAllSeq();
    }
    return 0;
}

uint32_t NFPlayer::GetAllSeq()
{
    uint32_t seq = GetCurSeq();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            seq += m_pPart[i]->GetCurSeq();
        }
    }
    return seq;
}

void NFPlayer::ClearAllSeq()
{
    ClearUrgent();
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->ClearUrgent();
        }
    }
}

NFPart *NFPlayer::GetPart(uint32_t partType)
{
    if (partType > PART_NONE && partType < (uint32_t) m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }
    
    return NULL;
}

const NFPart *NFPlayer::GetPart(uint32_t partType) const
{
    if (partType > PART_NONE && partType < (uint32_t) m_pPart.size())
    {
        return m_pPart[partType].GetPoint();
    }
    
    return NULL;
}

NFPart *NFPlayer::CreatePart(uint32_t partType)
{
    NFPart *pPart = dynamic_cast<NFPart *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_LOGIC_PART_ID + partType));
    if (pPart)
    {
        pPart->SetPartType(partType);
    }
    return pPart;
}

NFPart *NFPlayer::CreatePart(uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart *pPart = CreatePart(partType);
    if (pPart)
    {
        int iRet = pPart->Init(this, partType, dbData);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}::Init Failed", pPart->GetClassName());
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
            return NULL;
        }
    } else
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Create Part Failed, partType Not Handle:{}", partType);
    }
    return pPart;
}

int NFPlayer::RecylePart(NFPart *pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

int NFPlayer::EnterGame()
{
    if (FindModule<NFICoroutineModule>()->IsInCoroutine())
    {
        return EnterScene(m_mapId, m_sceneId, m_pos);
    }
    else {
        int rpcId = MakeCoroutine([this]{
            EnterScene(m_mapId, m_sceneId, m_pos);
        });
        CHECK_EXPR(rpcId != INVALID_ID, -1, "MakeCoroutine Failed");
    }
    
    return 0;
}

int NFPlayer::OnPrevLogin()
{
    //设置一次状态
    m_attrCache.clear();
    m_attrBroadCache.clear();
    SetState(proto_ff::state_normal);
    //计算战力
    CalcFight(false);
    //计算宠物系统战力
    CalcPetFight(false);
    //计算世界等级经验加成
    CalcWorldLvExpAdd();
    uint64_t curTime = NFTime::Now().UnixSec();
    if (m_loginDayTime <= 0 || !NFTimeUtility::CheckSameDay(curTime, m_loginDayTime))
    {
        m_loginDayTime = curTime;
        m_totalLoginDay += 1;
        MarkDirty();
    }
    //设置当前血量
    int64_t maxhp = GetAttr(proto_ff::A_MAX_HP);
    if (maxhp <= 0) maxhp = 1;
    SetAttr(proto_ff::A_CUR_HP, maxhp);
    
    //NotifyPlayerInfo();
    return 0;
}

int NFPlayer::NotifyPlayerInfo()
{
    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_NULL(pServerConfig);
    
    proto_ff::PlayerInfoRsp rsp;
    rsp.set_cid(Cid());
    rsp.set_name(GetName());
    rsp.set_zid(GetZid());
    rsp.set_opentime(pServerConfig->GetOpenTime());
    rsp.set_createtime(m_createTime);
    rsp.set_state(GetState());
/*    rsp.set_marry_dst_name(GetMarryDstName());
    rsp.set_tour_state(g_GetGMarryMgr()->GetTourState(m_Cid, m_sceneId));*/
    rsp.set_marry_dst_name("");
    rsp.set_tour_state(0);
    rsp.set_strguidelines(m_strGuidelines.c_str());
    rsp.set_vip_hide(0);
    //rsp.set_vip_hide(GetVipHide());
    rsp.set_subpack_type(m_subpackType);
    rsp.set_subpack_fetch(m_subpackFetch);
/*    rsp.set_world_lv(g_GetGlobalMgr()->GetWorldLv(m_zid));
    rsp.set_world_lv_4(g_GetGlobalMgr()->Get4CrossWorldLv(m_zid));
    rsp.set_world_lv_8(g_GetGlobalMgr()->Get8CrossWorldLv(m_zid));
    rsp.set_world_lv_16(g_GetGlobalMgr()->GetCrossWorldLv());
    rsp.set_is_merge(g_GetLogicService()->IsMerged(m_zid));*/
    rsp.set_world_lv(450);
    rsp.set_world_lv_4(450);
    rsp.set_world_lv_8(450);
    rsp.set_world_lv_16(450);
    rsp.set_is_merge(0);
    //
    for (uint32_t j = 1; j < proto_ff::A_COMMON_END; j++)
    {
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(j))
        {
            proto_ff::Attr64 *pAttr = rsp.add_attr();
            if (nullptr != pAttr)
            {
                pAttr->set_id(j);
                pAttr->set_value(GetAttr(j));
            }
        }
    }
    rsp.set_mapid(m_mapId);
    NFLogicCommon::NFPoint3ToProto(m_pos, *rsp.mutable_pos());
    
    //其他部件客户端数据 这里统一改到 Player.cpp LoginGame接口中了
    for (size_t i = 0; i < PART_MAX; i++)
    {
        if (m_pPart[i])
        {
            m_pPart[i]->OnLogin(rsp);
        }
    }
    
    //外观的数据获取要放到 m_pPart[i]->OnLogin(rsp) 后面
    proto_ff::RoleFacadeProto *protofacade = rsp.mutable_facade();
    if (nullptr != protofacade)
    {
        SetFacadeProto(*protofacade);
    }
    
    SendMsgToClient(proto_ff::CLIENT_PLAYER_INFO_RSP, rsp);
    return 0;
}

int NFPlayer::LoginSns()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_NULL(pConfig);
    
    proto_ff::LTSLoginReq cgMsg;
    cgMsg.set_cid(GetCid());
    cgMsg.set_uid(GetUid());
    cgMsg.set_zid(GetZid());
    SetBaseData(cgMsg.mutable_base());
    cgMsg.set_proxy_id(GetProxyId());
    cgMsg.set_logic_id(pConfig->GetBusId());
    cgMsg.set_game_id(GetGameId());
    
    proto_ff::STLLoginRsp rspMsg;
    int iRet = GetRpcService<proto_ff::LTS_LOGIN_RPC>(NF_ST_SNS_SERVER, GetSnsId(), cgMsg, rspMsg);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, GetCid(), "role:{}, GetRpcService<proto_ff::CLIENT_ENTER_GAME_REQ> err:{} , enter game faile!", GetCid(), GetErrorStr(iRet));
        return iRet;
    }
    
    if (rspMsg.ret() != proto_ff::RET_SUCCESS)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, GetCid(), "role:{}, GetRpcService<proto_ff::LTS_LOGIN_RPC> err:{} , enter game faile!", GetCid(), GetErrorStr(rspMsg.ret()));
        return rspMsg.ret();
    }
    return 0;
}

void NFPlayer::SetFacadeProto(proto_ff::RoleFacadeProto &outproto)
{
    static int32_t effectFacadeParts[] = {
        PART_GROW,
        PART_FACADE,
        PART_MOUNT,
        PART_BUFF,
        PART_TITLE,
        PART_DRAGON,
    };
    
    for (uint32_t i = 0; i < ARRAYSIZE(effectFacadeParts); i++)
    {
        NFPart *pPart = GetPart(effectFacadeParts[i]);
        if (pPart)
        {
            pPart->FillFacadeProto(outproto);
        }
    }
    
    //
    outproto.set_color(m_color);
    outproto.set_prof((int32_t) GetAttr(proto_ff::A_PROF));
}

void NFPlayer::SetHeadProto(proto_ff::RoleHeadPicProto &outproto)
{
    outproto.set_prof((int32_t) GetAttr(proto_ff::A_PROF));
    NFGrowPart *pPart = dynamic_cast<NFGrowPart *>(GetPart(PART_GROW));
    if (nullptr != pPart)
        pPart->FillHeadProto(outproto);
}

//////////////////////////////////////////////////////////////////////////
//增加属性 主要是为了增加虚拟物品相关的属性 costFlag:是否是扣除属性
void NFPlayer::AddVirAttr(MAP_UINT32_INT64 &mapAttr, bool costFlag/* = false*/, SCommonSource *pSource /*= nullptr*/, bool syn/* = false*/)
{
    MAP_UINT32_INT64::iterator iter = mapAttr.begin();
    for (; iter != mapAttr.end(); ++iter)
    {
        int64_t addVal = iter->second;
        if (costFlag)
        {
            addVal = -iter->second;
        }
/*		if (A_FIELD_EXP == iter->first)
		{
			//领域经验的，历史原因，特殊处理下
			FieldPart *pFieldPart = dynamic_cast<FieldPart*>(GetPart(PART_FIELD));
			if (nullptr != pFieldPart)
			{
				bool result = pFieldPart->addExp(addVal);
				if (result && addVal > 0)
				{
					if (addVal >= INT64_MAX)
					{
						LogWarningFmtPrint("Player::OnAddAttr....attrValue >= INT64_MAX...cid:%lu,anum:%d,value:%ld", m_Cid, iter->first, addVal);
					}
					LIST_ITEM lstItem;
					lstItem.clear();
					SItem item;
					item.nItemID = g_GetItemCfgMgr()->ItemIdByAttrId(A_FIELD_EXP);
					item.nNum = addVal;
					SyncShowToClient(EClientShowType_Virtual, 0, lstItem);
				}
			}
		}
		else*/
        {
            AddAttr(iter->first, addVal, pSource, syn);
        }
    }
}

//属性是否足够，主要是为了属性虚拟物品的判断
bool NFPlayer::EnoughVirAttr(MAP_UINT32_INT64 &mapAttr)
{
    MAP_UINT32_INT64::iterator iter = mapAttr.begin();
    for (; iter != mapAttr.end(); ++iter)
    {
/*		if (A_FIELD_EXP == iter->first)
		{
			//领域经验的，历史原因，特殊处理下
			FieldPart *pFieldPart = dynamic_cast<FieldPart*>(GetPart(PART_FIELD));
			if (nullptr == pFieldPart || (int64_t)pFieldPart->getExp() < iter->second)
			{
				return false;
			}
		}
		else*/ if (GetAttr(iter->first) < iter->second)
        {
            return false;
        }
    }
    return true;
}

//增加属性
bool NFPlayer::AddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource/* = nullptr*/, bool syn/* = false*/)
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

//增加属性 不同步到客户端
bool NFPlayer::AddAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource /*= nullptr*/)
{
    if (nullptr == m_pAttr || 0 == attrValue) return false;
    if (!CanAddAttr(ANum, attrValue, pSource)) return false;
    if (proto_ff::A_GODEVIL_EXP == ANum)
    {
        NFGodEvilPart *pgodevil = dynamic_cast<NFGodEvilPart *>(GetPart(PART_GODEVIL));
        if (nullptr != pgodevil)
        {
            pgodevil->OnAddExp(attrValue);
            if (0 == attrValue) return true;
        }
    } else if (proto_ff::A_GOD_META_EXP == ANum)
    {//神元经验
        //if(0 != GMAOnAttriAdd(this,attrValue) )
        //    return true;
    } else if (proto_ff::A_FACTION_BUILD == ANum)
    {
        //if (attrValue > 0 ) g_GetGFactionMgr()->AddExp(Cid(), (uint32_t)GetAttr(A_FACTION_ID), (uint32_t)attrValue,GetZid());
        return true;
    } else if (proto_ff::A_FACTION_TRIBUTE == ANum)
    {
        //if (attrValue > 0)  g_GetGFactionMgr()->AddTribute(Cid(), (uint32_t)GetAttr(A_FACTION_ID), (int32_t)attrValue, GetZid());
        //return true;
    } else if (proto_ff::A_PRESTIGE == ANum)
    {
        //OnAddPrestige(attrValue,pSource);
        
        if (0 == attrValue) return true;
    } else if (proto_ff::A_MAGIC == ANum)
    {
        if (attrValue > 0)
        {
            AddAttr(proto_ff::A_MAGIC_SUM, attrValue);
        }
    }
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
    //
    /* int64_t src = 0;
     int64_t p1 = 0;
     int64_t p2 = 0;
     int64_t p3 = 0;
     if (nullptr != pSource)
     {
         src = pSource->src;
         p1 = pSource->param1;
         p2 = pSource->param2;
         p3 = pSource->param3;
     }
     if (CREATURE_PET == Kind() && A_CUR_HP == ANum)
     {
         LogDebugFmtPrint("[logic] Creature::AddAttrCache....pet cost hp...cid:%lu, oldval:%ld, newval:%ld, src:%d, p1:%ld,p2:%ld,p3:%ld ",Cid(),oldVal,newVal,src,p1,p2,p3);
     }*/
    //计算属性
    CalcAttr(ANum);
    //
    OnAddAttr(ANum, oldVal, attrValue, newVal, pSource);
    //属性改变
    OnAttrChange(ANum, oldVal, newVal, pSource);
    
    return true;
}

//能否增加属性
bool NFPlayer::CanAddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource/* = nullptr*/)
{
    //达到最高等级之后, 玩家不在加经验了
    if (proto_ff::A_EXP == ANum)
    {
        if (attrValue < 0) //经验不允许减少
        {
            int32_t source = 0;
            int64_t param1 = 0;
            int64_t param2 = 0;
            if (nullptr != pSource)
            {
                source = pSource->src;
                param1 = pSource->param1;
                param2 = pSource->param2;
            }
            
            NFLogError(NF_LOG_SYSTEMLOG, 0, "attrValue < 0..cid:{},attrValue:{},source:{},param1:{},param2:{}", Cid(), attrValue, source, param1, param2);
            
            return false;
        }
        
        if (m_pAttr->GetAttr(proto_ff::A_LEVEL) >= RoleDescEx::Instance()->MaxLevel())
        {
            return false;
        }
    } else if (proto_ff::A_LEVEL == ANum || proto_ff::A_PROF == ANum)
    {
        //等级，不允许直接增加，只能增加经验那里计算得到
        //性别，职业 角色出生就确定了，后期不允许调用增加属性接口 修改
        return false;
    }
    
    return true;
}

//增加属性处理
void NFPlayer::OnAddAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource/* = nullptr*/)
{
    if (proto_ff::A_EXP == ANum) //经验
    {
        CheckExp(oldVal, pSource);
    } else if (proto_ff::A_CUR_HP == ANum)
    {
        if (GetAttr(proto_ff::A_CUR_HP) <= 0)
        {
            //玩家死亡
/*            uint64_t killerCid = 0;
            uint64_t skillId = 0;
            if (nullptr != pSource)
            {
                killerCid = pSource->killerCid;
                skillId = pSource->skillId;
            }*/
            //
            //OnDead(killerCid, skillId,true, oldVal);
        }
    } else if (proto_ff::A_GOLD == ANum)
    {
    
    } else if (proto_ff::A_MAGIC_SUM == ANum)
    {
/*        RankPart* pRankPart = dynamic_cast<RankPart*>(GetPart(PART_RANK));
        if (pRankPart)
        {
            pRankPart->UpdateRank(RANK_TYPE_YUANMAO_SUM, newVal);
        }
        
        MagicSumChangeEvent event;
        event.sum = newVal;
        g_GetEvent()->FireExecute(EVENT_MAGIC_SUM_CHANGE, Cid(), Kind(), &event, sizeof(MagicSumChangeEvent));*/
    }
    
    
    //处理虚拟物品的tip提示
    if (proto_ff::A_EXP != ANum && attrValue > 0)//经验的再ChekExp中已经处理了，这里过滤下
    {
        if (pSource && !pSource->bTips)
        {
            //do nothing
        } else
        {
/*            uint64_t virItemId = g_GetItemCfgMgr()->ItemIdByAttrId(ANum);
            if (virItemId > 0)
            {
                if (attrValue >= INT64_MAX)
                {
                    LogWarningFmtPrint("Player::OnAddAttr....attrValue >= INT64_MAX...cid:%lu,anum:%d,value:%ld", m_Cid, ANum, attrValue);
                }
                //
                LIST_ITEM lstItem;
                lstItem.clear();
                SItem item;
                item.nItemID = virItemId;
                item.nNum = attrValue;
                lstItem.push_back(item);
                SyncShowToClient(EClientShowType::Virtual, 0, lstItem);
            }*/
        }
    }
    
    if (IsNeeSaveAttr(ANum)) MarkDirty();
    
    //内部日志
    if (proto_ff::A_DIA == ANum || proto_ff::A_BD_DIA == ANum || proto_ff::A_GOLD == ANum || proto_ff::A_ARENA_COIN == ANum || proto_ff::A_PRESTIGE == ANum || proto_ff::A_MAGIC == ANum)
    {
        //GAoLogMgr::Currency(this, ANum, (newVal - oldVal));
    }
}

//设置属性
bool NFPlayer::SetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource/* = nullptr*/, bool syn /*= false*/)
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
bool NFPlayer::SetAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource/* = nullptr*/)
{
    if (nullptr == m_pAttr || attrValue < 0) return false;
    if (!CanSetAttr(ANum, attrValue, pSource)) return false;
    if (proto_ff::A_FACTION_BUILD == ANum) return true;
    if (proto_ff::A_GODEVIL_EXP == ANum)
    {
        NFGodEvilPart *pgodevil = dynamic_cast<NFGodEvilPart *>(GetPart(PART_GODEVIL));
        if (nullptr != pgodevil)
        {
            pgodevil->OnSetExp(attrValue);
            if (attrValue < 0) return true;
        }
    }
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

//能否设置属性
bool NFPlayer::CanSetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource/* = nullptr*/)
{
    //达到最高等级之后, 玩家不在加经验了
    if (proto_ff::A_EXP == ANum)
    {
        if (attrValue < 0)
        {
            int32_t source = 0;
            int64_t param1 = 0;
            int64_t param2 = 0;
            if (nullptr != pSource)
            {
                source = pSource->src;
                param1 = pSource->param1;
                param2 = pSource->param2;
            }
            NFLogError(NF_LOG_SYSTEMLOG, 0, "cid:{},attrValue:{},source:{},param1:{},param2:{}", Cid(), attrValue, source, param1, param2);
            //
            return false;
        }
        
        if (m_pAttr->GetAttr(proto_ff::A_LEVEL) >= RoleDescEx::Instance()->MaxLevel())
        {
            return false;
        }
    }
    
    return true;
}

//设置属性处理
void NFPlayer::OnSetAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource/* = nullptr*/)
{
    if (proto_ff::A_EXP == ANum) //经验
    {
        CheckExp(oldVal, pSource);
    } else if (proto_ff::A_VIP_LEVEL == ANum)
    {
        if (oldVal != newVal)
        {
            proto_ff::CenterRoleProto proto;
            proto.set_vip_level(newVal);
            SynAttrToSns(proto);
        }
    } else if (proto_ff::A_CUR_HP == ANum)
    {
        if (m_pAttr->GetAttr(proto_ff::A_CUR_HP) <= 0)
        {
            //玩家死亡
/*            uint64_t killerCid = 0;
            if (nullptr != pSource)
            {
                killerCid = pSource->killerCid;
            }*/
            //
            //OnDead(killerCid, true, oldVal);
        }
    } else if (proto_ff::A_CAMP_ID == ANum)
    {
        //TLogDebug("cid:", Cid(), ",kind:", Kind(), ",cfgid:", GetCfgId(), ",camp:", GetAttr(A_CAMP_ID));
    }
    if (IsNeeSaveAttr(ANum)) MarkDirty();
}

//获取该组属性值
int64_t NFPlayer::GetAttrGroup(uint32_t attrGroup, uint32_t ANum)
{
    if (nullptr != m_pFightAttr) return m_pFightAttr->GetAttrGroup(attrGroup, ANum);
    return 0;
}

//获取该组所有属性值
void NFPlayer::GetAttrGroup(uint32_t attrGroup, MAP_UINT32_INT64 &mapattr)
{
    if (nullptr != m_pFightAttr) m_pFightAttr->GetAttrGroup(attrGroup, mapattr);
}

//清除某一组属性
bool NFPlayer::ClearAttrGroup(uint32_t attrGroup, SCommonSource *pSource/* = nullptr*/, bool syn/* = false*/)
{
    if (!ClearAttrGroupCache(attrGroup, pSource)) return false;
    if (syn) SynAttrToClient();
    return true;
}

bool NFPlayer::ClearAttrGroupCache(uint32_t attrGroup, SCommonSource *pSource/* = nullptr*/)
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
    for (auto &iterold : mapoldchg)
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
bool NFPlayer::AddAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource/* = nullptr*/, bool syn/* = false*/)
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

bool NFPlayer::AddAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource/* = nullptr*/)
{
    if (nullptr == m_pFightAttr) return false;
    bool chgflag = false;
    int64_t oldval = m_pFightAttr->GetAttr(ANum);
    bool ret = m_pFightAttr->AddAttrGroup(attrGroup, ANum, val, &chgflag);
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

//设置属性组属性
bool NFPlayer::SetAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource/* = nullptr*/, bool syn/* = false*/)
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

bool NFPlayer::SetAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource/* = nullptr*/)
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
bool NFPlayer::SetAttrGroup(uint32_t attrGroup, const MAP_UINT32_INT64 &mapattr, SCommonSource *pSource/* = nullptr*/, bool syn/* = false*/)
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

bool NFPlayer::SetAttrGroupCache(uint32_t attrGroup, const MAP_UINT32_INT64 &mapattr, SCommonSource *pSource/* = nullptr*/)
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

//计算属性
void NFPlayer::CalcAttr(uint32_t ANum)
{
    if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(ANum))
        m_attrCache[ANum] = GetAttr(ANum);
    if (NFAttrMgr::Instance(m_pObjPluginManager)->IsBroadClient(ANum))
        m_attrBroadCache[ANum] = GetAttr(ANum);
}

//计算属性组属性 主要是把属性组中的属性汇总到总属性中 ANum:属性组中的属性ID
void NFPlayer::CalcAttrGroup(uint32_t attrgroup, uint32_t ANum, MAP_UINT32_INT64 &mapchg)
{
    if (nullptr == m_pFightAttr) return;
    if (attrgroup <= 0) return;
    if (ANum > 0)
    {
        m_pFightAttr->CalcAttr(ANum, mapchg);
    } else
    {
        m_pFightAttr->CalcAttr(mapchg);
    }
    for (auto &iter : mapchg)
    {
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsSynClient(iter.first))
            m_attrCache[iter.first] = iter.second;
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsBroadClient(iter.first))
            m_attrBroadCache[iter.first] = iter.second;
    }
}

//获取属性值
int64_t NFPlayer::GetAttr(uint32_t ANum)
{
    if (NFAttrMgr::Instance(m_pObjPluginManager)->ValidFightAttrId(ANum))
    {
        if (nullptr != m_pFightAttr) return m_pFightAttr->GetAttr(ANum);
    } else if (nullptr != m_pAttr)
    {
        return m_pAttr->GetAttr(ANum);
    }
    return 0;
}

//获取所有属性组属性之和
void NFPlayer::GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr)
{
    if (nullptr != m_pFightAttr) m_pFightAttr->GetAttrGroupTotal(mapattr);
}

//属性改变
void NFPlayer::OnAttrChange(int32_t ANum, int64_t oldVal, int64_t newVal, SCommonSource *pSource/* = nullptr*/)
{
    int64_t attrValue = newVal - oldVal;
    //判断属性改变引起的vip变化
    NFVipPart *pVipPart = dynamic_cast<NFVipPart *>(GetPart(PART_VIP));
    if (pVipPart)
    {
        pVipPart->DoAttrChange(ANum, newVal, attrValue, pSource);
    }
    if (ANum > proto_ff::A_NONE && ANum < proto_ff::A_BASE_END && m_pFightAttr->GetFightChg())
    {
        auto pcfg = AttributeAttributeDesc::Instance()->GetDesc(ANum);
        if (nullptr != pcfg && pcfg->m_power > EPS)
        {
            //SetCalcFight(true);
        }
    }
    if (proto_ff::A_CUR_HP == ANum)
    {
        uint64_t nowTick = NFTime::Tick();
        if (m_lastHpTick == 0 || (nowTick - m_lastHpTick) > (2 * 1000))
        {
            if (GetAttr(proto_ff::A_TEAM_ID) > 0)
            {
                proto_ff::CenterRoleProto proto;
                proto.set_hp(GetAttr(proto_ff::A_CUR_HP));
                SynAttrToSns(proto);
            }
        }
        //
        if (attrValue < 0)
        {
            NFSkillPart *pskill = dynamic_cast<NFSkillPart *>(GetPart(PART_SKILL));
            if (nullptr != pskill) pskill->OnHpChange(oldVal, newVal, GetAttr(proto_ff::A_MAX_HP));
        }
        
    }
    if (proto_ff::A_MAX_HP == ANum)
    {
        if (GetAttr(proto_ff::A_TEAM_ID) > 0)
        {
            proto_ff::CenterRoleProto proto;
            proto.set_max_hp(GetAttr(proto_ff::A_MAX_HP));
            SynAttrToSns(proto);
        }
    }
    if (proto_ff::PT_STAGE == ANum)
    {
        proto_ff::CenterRoleProto proto;
        proto.set_pt_stage(GetAttr(proto_ff::PT_STAGE));
        SynAttrToSns(proto);
    }
    if (proto_ff::A_ATK == ANum)
    {
        NFPetPart *pPetPart = dynamic_cast<NFPetPart *>(GetPart(PART_PET));
        if (pPetPart)
        {
            pPetPart->OnChgAttr();
        }
    }
}

void NFPlayer::SynAttrToClient()
{
    if (!m_attrCache.empty())
    {
        proto_ff::CreatureAttrSyn rsp;
        rsp.set_cid(Cid());
        string strlog;
        for (auto &iter : m_attrCache)
        {
            proto_ff::Attr64 *proto = rsp.add_attr();
            if (nullptr != proto)
            {
                proto->set_id(iter.first);
                proto->set_value(iter.second);
            }
        }
        NFLogDebug(NF_LOG_SYSTEMLOG, Cid(), "[logic] SynAttrToClient...cid:%lu, attr:%s", Cid(), rsp.DebugString());
        SendMsgToClient(proto_ff::CREATURE_ATTR_SYN, rsp);
        m_attrCache.clear();
    }
    
    if (!m_attrBroadCache.empty())
    {
        proto_ff::CreatureAttrBroadRsp rsp;
        rsp.set_cid(Cid());
        for (auto &iter : m_attrBroadCache)
        {
            proto_ff::Attr64 *proto = rsp.add_attr();
            if (nullptr != proto)
            {
                proto->set_id(iter.first);
                proto->set_value(iter.second);
            }
        }
        SendMsgToGameServer(proto_ff::CREATURE_ATTR_BROAD, rsp);
        m_attrBroadCache.clear();
    }
}

//检查经验值
void NFPlayer::CheckExp(int64_t oldexp, SCommonSource *pSource)
{
}

//是否是需要保存的属性
bool NFPlayer::IsNeeSaveAttr(uint32_t ANum)
{
    bool save = false;
    switch (ANum)
    {
        case proto_ff::A_LEVEL:
        case proto_ff::A_PROF:
        case proto_ff::A_EXP:
        case proto_ff::A_FIGHT:
        case proto_ff::A_VIP_LEVEL:
        case proto_ff::A_HANGUP_TIME:
        case proto_ff::A_GOLD:
        case proto_ff::A_DIA:
        case proto_ff::A_BD_DIA:
        case proto_ff::A_MAGIC:
        case proto_ff::A_PRESTIGE:
        case proto_ff::A_CONTRI:
        case proto_ff::A_ARENA_COIN:
        case proto_ff::A_GODEVIL_LEV:
        case proto_ff::A_GODEVIL_EXP:
        case proto_ff::A_BEST_AQ:
        case proto_ff::A_BEST_LJ:
        case proto_ff::A_MAGIC_SUM:
        case proto_ff::A_ACH_POINT:
        case proto_ff::A_FACTION_BUILD:
        case proto_ff::A_HOLYBEAST_BUILD:
        case proto_ff::A_BATTLEPASS_XIANCE:
        case proto_ff::A_BATTLEPASS_BAODING:
        case proto_ff::A_FINDTREASURE_SHENGJIFU:
        case proto_ff::A_FINDTREASURE_BATTLE_SOUL:save = true;
            break;
        default:break;
    }
    return save;
}

void NFPlayer::SynAttrToSns(const proto_ff::CenterRoleProto &proto)
{
    proto_ff::SynAttrToCenterRsp rsp;
    rsp.set_cid(Cid());
    rsp.mutable_info()->CopyFrom(proto);
    SendMsgToSnsServer(proto_ff::SYN_ATTR_TO_CENTER_RSP, rsp);
}

bool NFPlayer::ReadBaseData(const proto_ff::RoleDBData &proto)
{
    m_cid = proto.cid();
    m_uid = proto.uid();
    m_zid = proto.zid();
    //
    m_createTime = proto.base().createtime();
    m_createZeroTime = NFTime::GetZeroTime(m_createTime);
    m_logoutTime = proto.base().logouttime();
    m_loginTime = proto.base().logintime();
    m_totalLoginDay = proto.base().login_day();
    m_loginDayTime = proto.base().login_day_time();
    //
    m_name = proto.base().name();
    m_pAttr->SetAttr(proto_ff::A_PROF, proto.base().prof());
    m_pAttr->SetAttr(proto_ff::A_LEVEL, proto.base().level());
    m_pAttr->SetAttr(proto_ff::A_EXP, proto.base().exp());
    m_pAttr->SetAttr(proto_ff::A_CUR_HP, proto.base().hp());
    m_pAttr->SetAttr(proto_ff::A_FIGHT, proto.base().fight());
    m_pAttr->SetAttr(proto_ff::A_VIP_LEVEL, proto.base().vip_level());
    m_pAttr->SetAttr(proto_ff::A_HANGUP_TIME, proto.base().hanguptime());
    m_pAttr->SetAttr(proto_ff::A_GOLD, proto.base().gold());
    m_pAttr->SetAttr(proto_ff::A_DIA, proto.base().dia());
    m_pAttr->SetAttr(proto_ff::A_BD_DIA, proto.base().bdia());
    m_pAttr->SetAttr(proto_ff::A_MAGIC, proto.base().magic());
    m_pAttr->SetAttr(proto_ff::A_PRESTIGE, proto.base().prestige());
    m_pAttr->SetAttr(proto_ff::A_CONTRI, proto.base().contri());
    m_pAttr->SetAttr(proto_ff::A_ARENA_COIN, proto.base().arenacoin());
    m_pAttr->SetAttr(proto_ff::A_GODEVIL_LEV, proto.base().godevil_level());
    m_pAttr->SetAttr(proto_ff::A_GODEVIL_EXP, proto.base().godevil_exp());
    m_pAttr->SetAttr(proto_ff::A_BEST_AQ, proto.base().best_aq());
    m_pAttr->SetAttr(proto_ff::A_BEST_LJ, proto.base().best_lj());
    m_pAttr->SetAttr(proto_ff::A_BATTLEPASS_XIANCE, proto.base().battlepass_xiance());
    m_pAttr->SetAttr(proto_ff::A_BATTLEPASS_BAODING, proto.base().battlepass_baoding());
    m_pAttr->SetAttr(proto_ff::A_FINDTREASURE_SHENGJIFU, proto.base().findtreasure_shengfu());
    m_pAttr->SetAttr(proto_ff::A_FINDTREASURE_BATTLE_SOUL, proto.base().findtreasure_battlesoul());
    m_pAttr->SetAttr(proto_ff::A_HOLYBEAST_BUILD, proto.base().holybeast_build());
    m_pAttr->SetAttr(proto_ff::A_MAGIC_SUM, proto.base().magic_sum());
    m_dayPrestige = proto.base().day_prestige();
    m_resetPrestige = proto.base().prestige_time();
    uint64_t curtime = NFTime::Now().UnixSec();
    if (!NFTimeUtility::IsSameDayStd(curtime, m_resetPrestige))
    {
        m_dayPrestige = 0;
        m_resetPrestige = curtime;
        MarkDirty();
    }
    //
    if (proto.base().has_facade())
    {
        m_color = proto.base().facade().color();
    }
    if (proto.base().has_relive())
    {
        m_relive.read_from_pbmsg(proto.base().relive());
    }
    
    m_sceneId = proto.base().enter_scene_id();
    m_mapId = proto.base().enter_map_id();
    m_pos.x = proto.base().enterposx();
    m_pos.y = proto.base().enterposy();
    m_pos.z = proto.base().enterposz();
    
    m_lastMapId = proto.base().lastmapid();
    m_lastSceneId = proto.base().lastsceneid();
    m_lastPos.x = proto.base().lastposx();
    m_lastPos.y = proto.base().lastposy();
    m_lastPos.z = proto.base().lastposz();
    
    m_strGuidelines = proto.base().guide();
    m_subpackType = proto.base().subpack_type();
    m_subpackFetch = proto.base().subpack_fetch();
    
    return true;
}

void NFPlayer::SetBaseData(proto_ff::RoleDBBaseData *protobase)
{
    if (nullptr != protobase)
    {
        protobase->set_name(m_name.c_str());
        protobase->set_level(m_pAttr->GetAttr(proto_ff::A_LEVEL));
        protobase->set_prof(m_pAttr->GetAttr(proto_ff::A_PROF));
        protobase->set_exp(m_pAttr->GetAttr(proto_ff::A_EXP));
        protobase->set_hp(m_pAttr->GetAttr(proto_ff::A_CUR_HP));
        protobase->set_fight(m_pAttr->GetAttr(proto_ff::A_FIGHT));
        protobase->set_vip_level(m_pAttr->GetAttr(proto_ff::A_VIP_LEVEL));
        protobase->set_hanguptime(m_pAttr->GetAttr(proto_ff::A_HANGUP_TIME));
        protobase->set_state(GetState());
        //
        protobase->set_gold(m_pAttr->GetAttr(proto_ff::A_GOLD));
        protobase->set_dia(m_pAttr->GetAttr(proto_ff::A_DIA));
        protobase->set_bdia(m_pAttr->GetAttr(proto_ff::A_BD_DIA));
        protobase->set_magic(m_pAttr->GetAttr(proto_ff::A_MAGIC));
        protobase->set_prestige(m_pAttr->GetAttr(proto_ff::A_PRESTIGE));
        protobase->set_contri(m_pAttr->GetAttr(proto_ff::A_CONTRI));
        protobase->set_arenacoin(GetAttr(proto_ff::A_ARENA_COIN));
        protobase->set_godevil_level(GetAttr(proto_ff::A_GODEVIL_LEV));
        protobase->set_godevil_exp(GetAttr(proto_ff::A_GODEVIL_EXP));
        protobase->set_best_aq(GetAttr(proto_ff::A_BEST_AQ));
        protobase->set_best_lj(GetAttr(proto_ff::A_BEST_LJ));
        protobase->set_pt_stage(GetAttr(proto_ff::PT_STAGE));
        
        protobase->set_battlepass_xiance(GetAttr(proto_ff::A_BATTLEPASS_XIANCE));
        protobase->set_battlepass_baoding(GetAttr(proto_ff::A_BATTLEPASS_BAODING));
        protobase->set_findtreasure_shengfu(GetAttr(proto_ff::A_FINDTREASURE_SHENGJIFU));
        protobase->set_findtreasure_battlesoul(GetAttr(proto_ff::A_FINDTREASURE_BATTLE_SOUL));
        protobase->set_holybeast_build(GetAttr(proto_ff::A_HOLYBEAST_BUILD));
        
        protobase->set_magic_sum(GetAttr(proto_ff::A_MAGIC_SUM));
        
        //
        protobase->set_createtime(m_createTime);
        protobase->set_logintime(m_loginTime);
        protobase->set_logouttime(m_loginTime);
        protobase->set_login_day(m_totalLoginDay);
        protobase->set_login_day_time(m_loginDayTime);
        //
        protobase->set_enter_scene_id(m_sceneId);
        protobase->set_enter_map_id(m_mapId);
        protobase->set_enterposx(m_pos.x);
        protobase->set_enterposy(m_pos.y);
        protobase->set_enterposz(m_pos.z);
        protobase->set_lastsceneid(m_lastSceneId);
        protobase->set_lastmapid(m_lastMapId);
        protobase->set_lastposx(m_lastPos.x);
        protobase->set_lastposy(m_lastPos.y);
        protobase->set_lastposz(m_lastPos.z);
        
        protobase->set_day_prestige(m_dayPrestige);
        protobase->set_prestige_time(m_resetPrestige);
        
        protobase->set_guide(m_strGuidelines.c_str());
        protobase->set_subpack_type(m_subpackType);
        protobase->set_subpack_fetch(m_subpackFetch);
        
        //填充基础数据外观
        proto_ff::RoleFacadeProto* pFacadeProto = protobase->mutable_facade();
        if (nullptr != pFacadeProto)
        {
            SetFacadeProto(*pFacadeProto);
        }
        //
        proto_ff::RoleReliveProto *protorelive = protobase->mutable_relive();
        if (nullptr != protorelive)
        {
            m_relive.write_to_pbmsg(*protorelive);
        }
    }
}

void NFPlayer::SetBaseData(proto_ff::RoleDBData &proto)
{
    proto_ff::RoleDBBaseData *protobase =  proto.mutable_base();
    SetBaseData(protobase);
}

void NFPlayer::SetAttrData(proto_ff::RoleDBData &proto)
{
    proto_ff::AttrDBData *protoattr = proto.mutable_attr();
    if (nullptr != protoattr)
    {
        for (uint32_t i = proto_ff::A_NONE + 1; i < proto_ff::A_FIGHT_END; ++i)
        {
            int64_t val = m_pFightAttr->GetAttr(i);
            if (0 == val) continue;
            proto_ff::Attr64 *protoinfo = protoattr->add_attr_lst();
            if (nullptr != protoinfo)
            {
                protoinfo->set_id(i);
                protoinfo->set_value(val);
            }
        }
    }
}

void NFPlayer::SetEnterSceneProto(proto_ff::RoleEnterSceneData &outproto)
{
    outproto.set_cid(GetCid());
    outproto.set_uid(GetUid());
    outproto.set_zid(GetZid());
    SetBaseData(outproto.mutable_base());
}

proto_ff::ECState NFPlayer::GetState()
{
    return m_state;
}

void NFPlayer::SetState(proto_ff::ECState state)
{
    m_state = state;
}

bool NFPlayer::BState(proto_ff::ECState state)
{
    return m_state == state;
}

//计算战力
void NFPlayer::CalcFight(bool sync)
{
    int64_t fight = 0;
    NFBuffPart* pbuffpart = dynamic_cast<NFBuffPart*>(GetPart(PART_BUFF));
    NFSkillPart* pskillpart = dynamic_cast<NFSkillPart*>(GetPart(PART_SKILL));
    MAP_UINT32_INT64 mapattr;
    m_pFightAttr->GetFightAttr(mapattr);
    //
    for (auto &iter : mapattr)
    {
        auto pcfg = AttributeAttributeDesc::Instance()->GetDesc(iter.first);
        if (nullptr == pcfg || pcfg->m_power <= EPS) continue;
        int64_t value = iter.second;
        if (nullptr != pbuffpart) value += pbuffpart->GetFightAttr(iter.first);
        fight += (int64_t)(pcfg->m_power * value);
    }
    if (nullptr != pskillpart) fight += pskillpart->SkillFight();
    //
    if (fight != m_pAttr->GetAttr(proto_ff::A_FIGHT))
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, GetCid(), "CalcFight....cid:{}, old:{}, new:{}, sync:{} ", Cid(), GetAttr(proto_ff::A_FIGHT), fight, sync);
        SetAttr(proto_ff::A_FIGHT, fight, nullptr, sync);
        NFAchievementPart* pAchPart = dynamic_cast<NFAchievementPart*>(GetPart(PART_ACHIEVEMENT));
        if (pAchPart)
        {
            pAchPart->OnCommonFinishNumWithLess(1, fight, XIUZHENROAD_EVENT_FINISH_FIGHT_VALUE);
        }
        if (sync)
        {
            //同步到中心服
            proto_ff::CenterRoleProto proto;
            proto.set_fight(GetAttr(proto_ff::A_FIGHT));
            SynAttrToSns(proto);
        }
    }
    m_pFightAttr->ClearFightChg();
    SetCalcFight(false);
}

//计算宠物系统的战斗力
void NFPlayer::CalcPetFight(bool sync)
{
    SetCalcPetFight(false);
    int64_t fight = 0;
    MAP_UINT32_INT64 mapattr;
    m_pFightAttr->GetAttrGroup(proto_ff::EAttrGroup_Pet, mapattr);
    for (auto& iter : mapattr)
    {
        auto pcfg = AttributeAttributeDesc::Instance()->GetDesc(iter.first);
        if (nullptr == pcfg || pcfg->m_power <= EPS) continue;
        int64_t value = iter.second;
        fight += (int64_t)(pcfg->m_power * value);
    }
    if (fight != m_petFight)
    {
        m_petFight = fight;
        if (sync)
        {
            //同步宠物系统战斗力
            NFRankPart* pRankPart = dynamic_cast<NFRankPart*>(GetPart(PART_RANK));
            if (pRankPart)
            {
                pRankPart->UpdateRank(RANK_TYPE_PET_FIGHT, m_petFight);
            }
        }
    }
}

void NFPlayer::CalcWorldLvExpAdd()
{

}

void NFPlayer::SyncFacade()
{

}

PLAYER_SCENE_STATE NFPlayer::GetSceneStatus() const
{
    return m_sceneState;
}

void NFPlayer::SetSceneStatus(PLAYER_SCENE_STATE status)
{
    m_sceneState = status;
}

bool NFPlayer::IsInBattle()
{
    return BState(proto_ff::state_fight);
}

bool NFPlayer::IsInTransSceneing()
{
    return m_sceneState == PLAYER_SCENE_STATUS_Entering || m_sceneState == PLAYER_SCENE_STATUS_Leaveing;
}

int NFPlayer::EnterScene(uint64_t mapId, uint64_t sceneId, const NFPoint3<float> &dstPos)
{
    if (IsInTransSceneing())
    {
        return proto_ff::RET_FAIL;
    }
    
    SetSceneStatus(PLAYER_SCENE_STATUS_Entering);
    
    proto_ff::EnterSceneReq req;
    req.set_cid(GetCid());
    req.set_dst_map_id(mapId);
    req.set_dst_scene_id(sceneId);
    NFLogicCommon::NFPoint3ToProto(dstPos, *req.mutable_dst_pos());
    req.set_src_map_id(m_mapId);
    req.set_src_scene_id(m_sceneId);
    NFLogicCommon::NFPoint3ToProto(m_pos, *req.mutable_src_pos());
    SetEnterSceneProto(*req.mutable_data());
    
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_NULL(pConfig);
    
    req.set_proxy_id(GetProxyId());
    req.set_logic_id(pConfig->GetBusId());
    req.set_world_id(GetWorldId());
    req.set_sns_id(GetSnsId());
    
    proto_ff::EnterSceneRsp rsp;
    int iRet = GetRpcService<proto_ff::STS_ENTER_SCENE_REQ>(NF_ST_CENTER_SERVER, 0, req, rsp);
    SetSceneStatus(PLAYER_SCENE_STATUS_NONE);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, GetCid(), "GetRpcService<proto_ff::STS_ENTER_SCENE_REQ> rpc error:{}", GetErrorStr(iRet));
        return iRet;
    }
    
    if (rsp.ret_code() != proto_ff::RET_SUCCESS)
    {
        NFLogError(NF_LOG_SYSTEMLOG, GetCid(), "GetRpcService<proto_ff::STS_ENTER_SCENE_REQ> Failed, return ret_code:{}", GetErrorStr(rsp.ret_code()));
        return rsp.ret_code();
    }
    
    SetSceneStatus(PLAYER_SCENE_STATUS_Gameing);
    
    SetGameId(rsp.game_id());
    m_mapId = rsp.map_id();
    m_sceneId = rsp.scene_id();
    NFLogicCommon::NFPoint3FromProto(m_pos, rsp.pos());
    
    NFLogInfo(NF_LOG_SYSTEMLOG, GetCid(), "Enter Scene Success, MapId:{} SceneId:{}", mapId, sceneId);
    
    return 0;
}