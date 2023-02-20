// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#include "NFMissionPart.h"
#include "DescStoreEx/NFMissionDescStoreEx.h"
#include "Player/NFPlayer.h"
#include "NFPackagePart.h"
#include "DescStore/EquipEquipDesc.h"
#include "Mission.pb.h"
#include "ClientServerCmd.pb.h"
#include "Event.pb.h"
#include "NFLogicCommon/NFEventDefine.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMissionPart, EOT_LOGIC_MISSION_PART_ID, NFShmObj)

NFMissionPart::NFMissionPart()
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

NFMissionPart::~NFMissionPart()
{
}

int NFMissionPart::CreateInit()
{
    return 0;
}

int NFMissionPart::ResumeInit()
{
    return 0;
}

int NFMissionPart::RetisterClientMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMissionPart::RetisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMissionPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFMissionPart::UnInit()
{
    return NFPart::UnInit();
}

int NFMissionPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    return NFPart::SaveDB(dbData);
}

int NFMissionPart::OnLogin()
{

    return 0;
}

int NFMissionPart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

int NFMissionPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFMissionPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

//最近提交列表里面是否有指定类型的任务
bool NFMissionPart::HaveRecentSubmit(int32_t missionType)
{
    auto iter = _mapRecentSubmit.find(missionType);
    return (iter != _mapRecentSubmit.end()) ? true : false;
}

//根据任务类型获取当前任务列表中存在的数量
int32_t NFMissionPart::MissionNumByType(int32_t missionType)
{
    int32_t num = 0;
    auto iter = _playerTrackMissionMap.begin();
    for (; iter != _playerTrackMissionMap.end(); ++iter)
    {
        uint64_t missionId = iter->second.missionId;
        const DyMissionInfo *pDyMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetDyMissionCfgInfo(missionId);
        if (nullptr != pDyMissionInfo)
        {
            if ((uint32_t) missionType == pDyMissionInfo->kind)
            {
                num++;
            }
        }
        else
        {
            MissionInfo *pMissionCfgInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(missionId);
            if (nullptr != pMissionCfgInfo)
            {
                if ((uint32_t) missionType == pMissionCfgInfo->kind)
                {
                    num++;
                }
            }
        }
    }
    return num;
}

bool NFMissionPart::HaveAccpet(const uint64_t &missionId)
{
    if (_playerTrackMissionMap.find(missionId) != _playerTrackMissionMap.end())
    {
        return true;
    }

    return false;
}

//是否已经提交过的任务
bool NFMissionPart::HaveSubmited(uint64_t missionId)
{
    auto iter = _setAlreadySubmit.find(missionId);
    return (iter != _setAlreadySubmit.end()) ? true : false;
}


void NFMissionPart::CheckTrunkMission(bool notify/* = true*/)
{
    if ((_mapRecentSubmit.size() <= 0 && _playerTrackMissionMap.size() <= 0) ||
        ((!HaveRecentSubmit(MISSION_TYPE_ID_TRUNK)) && (MissionNumByType(MISSION_TYPE_ID_TRUNK) <= 0)))
    {
        //最近提交任务列表为空,并且已接取任务列表也为空
        //最近提交任务列表不为空，并且最近提交任务列表中没有主线任务，并且已接取任务列表也为空中也没有主线任务

        auto &mapFirst = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetFirstMission();
        for (auto iterFirt = mapFirst.begin(); iterFirt != mapFirst.end(); ++iterFirt)
        {
            auto &setMission = iterFirt->second;
            for (auto iterMission = setMission.begin(); iterMission != setMission.end(); ++iterMission)
            {
                uint64_t missionid = (*iterMission);
                MissionInfo *pMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(missionid);
                if (nullptr == pMissionInfo)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "CheckTrunkMission 11 nullptr == pMissionInfo cid:{}, missionid:{} ",
                               m_pMaster->GetCid(),
                               missionid);
                    continue;
                }
                if (HaveAccpet(missionid))
                {
                    continue;
                }
                if (HaveSubmited(missionid))
                {
                    continue;
                }
                int32_t ret = OnAccept(missionid, notify);
                if (proto_ff::RET_SUCCESS != ret)
                {
                    if (MISSION_TYPE_ID_TRUNK == pMissionInfo->kind)
                    {
                        MMOLOG_FMT_ERROR("MissionPart::CheckTrunkMission11...OnAccept failed...cid:%lu,kind:%d,mission:%lu,ret:%d ", m_pMaster->Cid(),
                                         pMissionInfo->kind, missionid, ret);
                    }
                }
                else
                {
                    LogDebugFmtPrint("MissionPart::CheckTrunkMission11...accept mission...cid:%lu,kind:%d, mission:%lu,ret:%d ", m_pMaster->Cid(),
                                     pMissionInfo->kind, missionid, ret);
                }
            }
        }
    }
    else
    {
        MAP_INT32_SET_UINT64::iterator iterRecent = _mapRecentSubmit.begin();
        for (; iterRecent != _mapRecentSubmit.end(); ++iterRecent)
        {
            SET_UINT64 &setMission = iterRecent->second;
            SET_UINT64::iterator iterMission = setMission.begin();
            for (; iterMission != setMission.end(); ++iterMission)
            {
                uint64_t missionid = (*iterMission);
                MissionInfo *pMissionInfo = g_GetMissionManager()->GetMissionCfgInfo(missionid);
                if (nullptr == pMissionInfo)
                {
                    LogErrFmtPrint("[logic] MissionPart::CheckTrunkMission nullptr == pMissionInfo cid:%lu, missionid:%lu ", m_pMaster->Cid(),
                                   missionid);
                    continue;
                }
                uint64_t backMissionid = pMissionInfo->backTaskId;
                if (backMissionid > 0)
                {
                    MissionInfo *pBackMissionInfo = g_GetMissionManager()->GetMissionCfgInfo(backMissionid);
                    if (nullptr == pBackMissionInfo)
                    {
                        LogErrFmtPrint("[logic] MissionPart::CheckTrunkMission nullptr == pBackMissionInfo cid:%lu, missionid:%lu,backMissionid:%lu ",
                                       m_pMaster->Cid(), missionid, backMissionid);
                        continue;
                    }
                    //
                    if (HaveAccpet(backMissionid))
                    {
                        //LogErrFmtPrint("[logic] MissionPart::CheckTrunkMission backMissionid have accept cid:%lu, missionid:%lu,backMissionid:%lu ", m_pMaster->GetCid(), missionid, backMissionid);
                        continue;
                    }
                    if (HaveSubmited(backMissionid))
                    {
                        continue;
                    }
                    if (MISSION_TYPE_ID_TRUNK == pBackMissionInfo->kind)
                    {
                        if (MissionNumByType(MISSION_TYPE_ID_TRUNK) > 0)
                        {
                            continue;
                        }
                    }
                    int32_t ret = g_GetMissionManager()->OnAccept(dynamic_cast<Player *>(m_pMaster), backMissionid, notify);
                    if (RET_SUCCESS != ret)
                    {
                        MMOLOG_FMT_ERROR("MissionPart::CheckTrunkMission...OnAccept failed...cid:%lu,mission:%lu,backMissionid:%lu,ret:%d ",
                                         m_pMaster->Cid(), missionid, backMissionid, ret);
                    }
                    else
                    {
                        LogDebugFmtPrint("MissionPart::CheckTrunkMission...accept mission...cid:%lu,kind:%d, mission:%lu,backMissionid:%lu,ret:%d ",
                                         m_pMaster->Cid(), pBackMissionInfo->kind, missionid, backMissionid, ret);
                    }
                }
            }
        }
    }
}

int32_t NFMissionPart::OnAccept(uint64_t missionId, bool notify)
{
    //接取任务
    MissionInfo *pMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(missionId);
    if (nullptr == pMissionInfo)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "OnAccept Have Not MissionID={} Config, Please Check Mission Config", missionId);
        return proto_ff::RET_MISSION_NOT_EXIST;
    }

    int32_t ret = CanAccept(missionId);
    if (proto_ff::RET_SUCCESS != ret)
    {
        return ret;
    }

    if (_playerTrackMissionMap.size() >= _playerTrackMissionMap.max_size())
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "_playerTrackMissionMap Space Noet Enough.......");
        return proto_ff::RET_FAIL;
    }

    //添加到可接列表中来
    MissionTrack *pMissionTrack = &_playerTrackMissionMap[missionId];
    if (nullptr == pMissionTrack)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "[logic] OnAccept MissionID={}, Allcol MissionTrackObj is nullptr", missionId);
        return proto_ff::RET_FAIL;
    }

    //填充完成条件信息 多任务条件

    //接取任务获取中间道具
    AddReward(pMissionInfo->missionId, pMissionInfo->kind, pMissionInfo->receAdd);
    //填充任务数据信息
    pMissionTrack->missionId = missionId;
    pMissionTrack->dynamicId = missionId; //主支线任务动态任务ID和配置ID一样
    pMissionTrack->acceptMissionTime = NFTime::Now().UnixSec();
    pMissionTrack->status = MISSION_E_ACCEPTED;
    if (proto_ff::RET_SUCCESS != OnExtractCond(pMissionInfo, pMissionTrack))
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "[logic] OnAccept MissionID={}, OnExtractCond failed...", missionId);
        return proto_ff::RET_FAIL;
    }

    MarkDirty();

    //通知接取状态
    if (notify)
    {
        UpdateMissionProgress(missionId);
    }

    //接取任务事件
    proto_ff::AcceptTaskEvent acceptEvent;
    acceptEvent.set_cid(m_pMaster->Cid());
    acceptEvent.set_taskid(missionId);
    acceptEvent.set_tasktype(pMissionInfo->kind);
    FireExecute(NF_ST_LOGIC_SERVER, EVENT_ACCEPT_TASK, m_pMaster->Cid(), CREATURE_PLAYER, acceptEvent);

    //判断任务是否完成
    bool isCompletedFlag = true;
    for (uint32_t i = 0; i < pMissionTrack->items.size(); i++)
    {
        if (!pMissionTrack->items[i].completedFlag)
        {
            isCompletedFlag = false;
            break;
        }
    }

    //如果已经完成
    if (isCompletedFlag)
    {
        //如果可以完成
        pMissionTrack->status = MISSION_E_COMPLETION;
    }
    else //没有完成的条件才会注册事件
    {
        //添加任务掉落处理
        OnAddMissionDrop(pMissionTrack, pMissionInfo->progressLev);
        //注册事件
        for (uint32_t i = 0; i < pMissionTrack->items.size(); i++)
        {
            if (!pMissionTrack->items[i].completedFlag)
            {
                int32_t relEvent = MISSION_COND_TYPE_TO_EVENT(pMissionTrack->items[i].type);
                RegisterEvent(relEvent, pMissionTrack->dynamicId, pMissionInfo->progressLev);
            }
        }
    }

    //如果任务已接取就完成需要 再次通知客户端
    if (isCompletedFlag && notify)
    {
        UpdateMissionProgress(missionId);
    }

    OnAccept(missionId, pMissionInfo->kind);

    //日志

    return proto_ff::RET_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////

void NFMissionPart::RegisterEvent(uint32_t eventType, uint64_t missionId, int32_t progressLev)
{
    auto iter = _eventTabal.find(eventType);
    if (iter != _eventTabal.end())
    {
        auto &mapLevMission = iter->second;
        auto iterLv = mapLevMission.find(progressLev);
        if (iterLv != mapLevMission.end())
        {
            if (iterLv->second.size() >= iterLv->second.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_eventTabal iterLv->second Space Not Enough");
            }
            iterLv->second.insert(missionId);
        }
        else
        {
            if (iterLv->second.size() >= iterLv->second.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_eventTabal mapLevMission Space Not Enough");
            }
            mapLevMission[progressLev].insert(missionId);
        }
    }
    else
    {
        if (_eventTabal.size() >= _eventTabal.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_eventTabal Space Not Enough");
        }
        _eventTabal[eventType][progressLev].insert(missionId);
    }
}

void NFMissionPart::RemoveEvent(uint64_t missionId)
{
    auto iter = _eventTabal.begin();
    while (iter != _eventTabal.end())
    {
        auto &mapLevMission = iter->second;
        auto iterLv = mapLevMission.begin();
        while (iterLv != mapLevMission.end())
        {
            auto &setMission = iterLv->second;
            auto iterMission = setMission.find(missionId);
            if (iterMission != setMission.end())
            {
                setMission.erase(iterMission);
                if (setMission.size() <= 0)
                {
                    iterLv = mapLevMission.erase(iterLv);
                    continue;
                }
            }
            ++iterLv;
        }
        if (mapLevMission.size() <= 0)
        {
            iter = _eventTabal.erase(iter);
            continue;
        }
        ++iter;
    }
}

void NFMissionPart::OnEvent(uint32_t eventType, const ExecuteData &data, uint64_t dynamicId /*= 0*/)
{
    Player *pPlayer = dynamic_cast<Player *>(m_pMaster);
    if (nullptr == pPlayer)
    {
        LogErrFmtPrint("MissionPart::OnEvent...nullptr == pPlayer...eventType:%u ", eventType);
        return;
    }
    int32_t level = pPlayer->GetAttr(A_LEVEL);
    EventTabal::iterator iter = _eventTabal.find(eventType);
    if (_eventTabal.end() != iter)
    {
        MAP_INT32_SET_UINT64 &mapLvMission = iter->second;
        MAP_INT32_SET_UINT64::iterator iterLv = mapLvMission.begin();
        for (; iterLv != mapLvMission.end(); ++iterLv)
        {
            SET_UINT64 &setMission = iterLv->second;
            if (iterLv->first <= level)
            {
                if (dynamicId > 0)
                {
                    SET_UINT64::iterator iterMission = setMission.find(dynamicId);
                    if (iterMission != setMission.end())
                    {
                        OnUpdateProgress(pPlayer, (*iterMission), data);
                        break;
                    }
                }
                else
                {
                    SET_UINT64::iterator iterMission = setMission.begin();
                    for (; iterMission != setMission.end(); ++iterMission)
                    {
                        OnUpdateProgress(pPlayer, (*iterMission), data);
                    }
                }
            }
        }
    }
}

//添加任务掉落
int32_t NFMissionPart::OnAddMissionDrop(MissionTrack *pMissionTrack, int32_t progressLev)
{
    CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == NULL");

    uint64_t missionId = pMissionTrack->missionId;
    uint64_t dymissionId = pMissionTrack->dynamicId;

    for (auto iter = pMissionTrack->items.begin(); iter != pMissionTrack->items.end(); ++iter)
    {
        ItemInfo &cond = (*iter);
        if (MISSION_FINISH_TYPE_COLLECT_KILL_MONS == cond.type
            || MISSION_FINISH_TYPE_COLLECT_ITEM == cond.type
                )
        {
            //收集物品		格式 301=物品id=物品数量=生物ID=宝箱id=追踪区域ID（背包中有足够数量，即完成任务）
            //打怪收集		格式 302=物品id=物品数量=生物ID=宝箱id=追踪路径id
            if (!AddMissionDrop(dymissionId, cond.parma1, 0, cond.parma2, progressLev))
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                           "OnAddMissionDrop...pMissionPart->AddMissionDrop failed....cid:{}, missionid:{}, dymissionid:{}, condtype:{},itemid:{},finalvalue:{},param1:{},param2:{},param3:{} ",
                           m_pMaster->Cid(), missionId, dymissionId, cond.type, cond.itemId, cond.finalValue, cond.parma1, cond.parma2, cond.parma3);
            }
        }
    }
    return proto_ff::RET_SUCCESS;
}

bool NFMissionPart::AddMissionDrop(uint64_t dymissionId, uint64_t monsId, uint64_t dropId, uint64_t boxId, int32_t progressLev)
{
    auto iterMons = _mapMissionAllDrop.find(monsId);
    if (iterMons != _mapMissionAllDrop.end())
    {
        MissionDropMap &mapDrop = iterMons->second;
        auto iterMission = mapDrop.find(dymissionId);
        if (iterMission != mapDrop.end())
        {
            return false;
        }
        else
        {
            MissionDrop stDrop;
            stDrop.dropId = dropId;
            stDrop.boxId = boxId;
            stDrop.progressLv = progressLev;
            if (mapDrop.size() >= mapDrop.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapMissionAllDrop mapDrop Space Not Enough");
                return false;
            }
            mapDrop[dymissionId] = stDrop;
        }
    }
    else
    {
        MissionDrop stDrop;
        stDrop.dropId = dropId;
        stDrop.boxId = boxId;
        stDrop.progressLv = progressLev;
        if (_mapMissionAllDrop.size() >= _mapMissionAllDrop.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapMissionAllDrop Space Not Enough");
            return false;
        }
        _mapMissionAllDrop[monsId][dymissionId] = stDrop;
    }
    return true;
}

//删除任务掉落
bool NFMissionPart::DelMissionDrop(uint64_t dymissionId, uint64_t monsId)
{
    MissionAllDropMap::iterator iterMons = _mapMissionAllDrop.find(monsId);
    if (iterMons != _mapMissionAllDrop.end())
    {
        MissionDropMap &mapDrop = iterMons->second;
        MissionDropMap::iterator iterMission = mapDrop.find(dymissionId);
        if (iterMission != mapDrop.end())
        {
            mapDrop.erase(iterMission);
            if (mapDrop.size() <= 0)
            {
                _mapMissionAllDrop.erase(iterMons);
            }
            //
            return true;
        }
    }
    return false;
}

//获取任务掉落
MissionDropMap* NFMissionPart::GetMissionDrop(uint64_t monsterId)
{
    MissionAllDropMap::iterator iterMons = _mapMissionAllDrop.find(monsterId);
    if (iterMons != _mapMissionAllDrop.end())
    {
        return &iterMons->second;
    }

    return NULL;
}

int32_t NFMissionPart::CanAccept(uint64_t missionId)
{
    MissionInfo *pMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(missionId);
    if (nullptr == pMissionInfo)
    {
        return proto_ff::RET_MISSION_NOT_EXIST;
    }

    //是否接取过该任务
    if (HaveAccpet(pMissionInfo->missionId))
    {
        return proto_ff::RET_MISSION_HAVE_ACCEPT;
    }

    //是否已经提交
    if (HaveSubmited(pMissionInfo->missionId))
    {
        return proto_ff::RET_MISSION_ALREADY_SUBMIT;
    }

    //主线任务验证下是否已经接取过主线任务
    if (MISSION_TYPE_ID_TRUNK == pMissionInfo->kind)
    {
        if (MissionNumByType(MISSION_TYPE_ID_TRUNK) > 0)
        {
            return proto_ff::RET_MISSION_HAVE_TYPE_ACCEPT;
        }
    }

    SCanAcceptParam param;
    param.missionId = pMissionInfo->missionId;
    int32_t ret = CanAccept(pMissionInfo->accept, param);
    if (proto_ff::RET_SUCCESS != ret)
    {
        return ret;
    }

    return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::CanAccept(const AcceptInfo &cond, SCanAcceptParam &param)
{
    //前置章节判断（或关系）
    if (cond.setPreOrMission.size() > 0)
    {
        bool haveSubmit = false;
        for (auto iterOr = cond.setPreOrMission.begin(); iterOr != cond.setPreOrMission.end(); ++iterOr)
        {
            uint64_t id = (*iterOr);
            if (HaveSubmited(id))
            {
                haveSubmit = true;
                break;
            }
        }
        if (!haveSubmit)
        {
            return proto_ff::RET_MISSION_GROUP_LIMIT;
        }
    }

    //等级
    if (cond.minLevel > 0 && m_pMaster->GetAttr(proto_ff::A_LEVEL) < cond.minLevel)
    {
        return proto_ff::RET_MISSION_LEVEL_ERROR;
    }

    //职业
    if (cond.profession > 0 && m_pMaster->GetAttr(proto_ff::A_PROF) != cond.profession)
    {
        return proto_ff::RET_MISSION_PROFESSION_LIMIT;
    }

    //前置章节判断（与关系）
    if (cond.setPreAndMission.size() > 0)
    {
        bool haveSubmit = true;
        for (auto iterAnd = cond.setPreAndMission.begin(); iterAnd != cond.setPreAndMission.end(); ++iterAnd)
        {
            const uint64_t id = (*iterAnd);
            if (!HaveSubmited(id))
            {
                haveSubmit = false;
                break;
            }
        }
        if (!haveSubmit)
        {
            return proto_ff::RET_MISSION_GROUP_LIMIT;
        }
    }
    return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::OnExtractCond(MissionInfo *pMissionInfo, MissionTrack *pMissionTrack)
{
    CHECK_EXPR(pMissionInfo, proto_ff::RET_FAIL, "pMissionInfo == Null");
    CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == Null");

    const InterExecute &execute = pMissionInfo->execute;
    for (auto iter = execute.items.begin(); iter != execute.items.end(); ++iter)
    {
        const InterItemPair &inter = (*iter);
        //组合条件
        ItemInfo condItem(inter.itemId, 0, inter.itemCount, false, inter.itemType, inter.parma1, inter.parma2, inter.parma3);
        //条件预更新
        OnPreUpdateProgress(condItem);
        //添加到条件列表中
        if (pMissionTrack->items.size() >= pMissionTrack->items.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "pMissionTrack->items Space Not Enough");
            return proto_ff::RET_FAIL;
        }
        pMissionTrack->items.push_back(condItem);
    }

    return proto_ff::RET_SUCCESS;
}

//条件预判断(有些条件接取任务时就已经完成了)
void NFMissionPart::OnPreUpdateProgress(ItemInfo &cond)
{
    if (cond.completedFlag)
    {
        return;
    }

    int64_t count = 0;
    int32_t event = MISSION_COND_TYPE_TO_EVENT(cond.type);
    if (M_EVENT_COLL_COLLECT_ITEM == event) //收集物品
    {
        //收集物品		格式：3 = 物品id = 所需物品数目 = 怪物id = 掉落包id = 区域id
        NFPackagePart *pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
        if (nullptr != pPackage)
        {
            int64_t bindNum = 0;
            int64_t unbindNum = 0;
            count = pPackage->GetItemNum(cond.itemId, unbindNum, bindNum);
        }
    }
    else if (M_EVENT_EMBLEM_INLAY == event)
    {
    }
    else if (M_EVENT_LADDER == event) //纹章宝库层数(天梯副本)
    {
    }
    else if (M_EVENT_SLOT_STREN == event)
    {
    }
    else if (M_EVENT_INBUFF == event) //处于某种BUFF
    {
    }
    else if (M_EVENT_LEVEL == event) //等级达到多少级
    {
        //升到指定等级	格式: 14=所需等级数值=目标值=0=0=0
        //升级到xx级 ,前端显示 0/1,
        if ((uint64_t) m_pMaster->GetAttr(proto_ff::A_LEVEL) >= cond.itemId)
        {
            count = cond.itemId;
        }
    }
    else if (M_EVENT_JOIN_GUILD == event)
    {

    }
    else if (M_EVENT_TREASURE_LEV == event)
    {
    }
    else if (M_EVENT_PARTNER_RANKLEV == event)
    {
    }
    else if (M_EVENT_WING_LEV == event)
    {
    }
    else if (M_EVENT_SKILL_LEVEL == event)
    {
    }
    else if (M_EVENT_APTITUDE == event)
    {
    }
    else if (M_EVENT_FETCH_OPERATE == event)
    {
    }
    else
    {
        return;
    }

    if (count > 0)
    {
        ExecuteData data(event, cond.itemId, count);
        bool notify = false;
        OnUpdateCondProcess(data, cond, notify);
    }
}

//更新条件进度
void NFMissionPart::OnUpdateCondProcess(const ExecuteData &data, ItemInfo &cond, bool &notify)
{
    int32_t relevent = MISSION_COND_TYPE_TO_EVENT(cond.type);
    if ((uint32_t) relevent != data.type || cond.completedFlag)
    {
        return;
    }
    if (MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type) //提交指定品阶和品质的装备特殊处理下
    {
    }
    else if (M_EVENT_INFINITE_HUNT == relevent)
    {
    }
    else if (M_EVENT_LADDER == relevent)
    {
    }
    else if (M_EVENT_APTITUDE == relevent)
    {

    }
    else if (M_EVENT_SLOT_STREN == relevent)
    {
    }
    else if (M_EVENT_TREASURE_LEV == relevent)
    {
    }
    else if (M_EVENT_PARTNER_RANKLEV == relevent)
    {
    }
    else if (M_EVENT_WING_LEV == relevent)
    {
    }
    else if (cond.itemId != data.id)
    {
        return;
    }

    //
    if (M_EVENT_LEVEL == relevent
        || M_EVENT_TREASURE_LEV == relevent            //宝具等级
        || M_EVENT_PARTNER_RANKLEV == relevent        //契灵等阶
        || M_EVENT_WING_LEV == relevent                //翅膀等级
            )
    {
        //升级到xx级 ,前端显示 0/1,
        //宝具等级 前端显示 0/1,	格式 11501=指定宝具等级=1=linkid=0=0
        //契灵等阶 前端显示 0/1,	格式 11601=指定契灵等阶=1=linkid=0=0
        //翅膀等级 前端显示 0/1,	格式 11701=指定翅膀等级=1=linkid=0=0
        if (data.id >= cond.itemId)
        {
            cond.currentValue = cond.finalValue;
            cond.completedFlag = true;
            notify = true;
        }
    }
    else if (M_EVENT_INFINITE_HUNT == relevent
             || M_EVENT_LADDER == relevent
             || M_EVENT_APTITUDE == relevent
            )
    {
        //单次获得无限狩猎经验 前端显示 0/1
        //纹章宝库层数(天梯) 前端显示 0/1
        //转职资质等级 前端显示 0/1
        if (data.id >= cond.itemId)
        {
            cond.currentValue = cond.finalValue;
            cond.completedFlag = true;
            notify = true;
        }
    }
    else if (M_EVENT_SLOT_STREN == relevent)
    {
        //装备槽位强化等级	格式 11301=0=装备槽位数量=等级=ui编号=0
        if (MISSION_FINISH_TYPE_SLOT_STREN == cond.type)
        {
/*            if (nullptr != pPlayer)
            {
                EquipPart *pPackage = dynamic_cast<EquipPart *>(pPlayer->GetPart(PART_EQUIP));
                if (nullptr != pPackage)
                {
                    int32_t count = pPackage->GetStrongLvNum(cond.parma1);
                    if (count > cond.currentValue)
                    {
                        cond.currentValue = count;
                        notify = true;
                        if (cond.currentValue >= cond.finalValue)
                        {
                            cond.currentValue = cond.finalValue;
                            cond.completedFlag = true;
                        }
                    }
                }
            }*/
        }
    }
    else
    {
        //提交物品的条件，物品扣除来源必须是从任务这边扣除的
        if (MISSION_FINISH_TYPE_SUBMIT_ITEM == cond.type || MISSION_FINISH_TYPE_SUBMIT_EQUIP == cond.type ||
            MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type)
        {
            if (S_MissionSubmitItem != data.source)
            {
                return;
            }

            if (MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type) //提交指定品质的装备时，需要验证
            {
                auto *pEquipCfg = EquipEquipDesc::Instance(m_pObjPluginManager)->GetDesc(data.id);
                if (nullptr != pEquipCfg && pEquipCfg->m_quality >= (int32_t) cond.parma1 && pEquipCfg->m_wearquality >= (int32_t) cond.itemId)
                {
                    //品阶大于等于条件配置值，品质大于等于条件配置值
                }
                else
                {
                    return;
                }
            }
        }
        else if (MISSION_FINISH_TYPE_KILL_MONS_WILD_BOSS == cond.type)
        {
            //野外BOSS需要判断来源
/*            if ((int32_t)EMonsCreateType::MapBoss != data.source)
            {
                return;
            }*/
        }
        else if (MISSION_FINISH_TYPE_KILL_MONS_BARREN_BOSS == cond.type)
        {
            //深渊BOSS需要判断来源
/*			if (EMonsCreateType_BarrenBoss != data.source)
			{
				return;
			}*/
        }


        int32_t currentValue = cond.currentValue + data.count;
        if (currentValue >= 0)
        {
            notify = true;
            if (currentValue >= cond.finalValue)
            {
                cond.currentValue = cond.finalValue;
                cond.completedFlag = true;
            }
            else
            {
                cond.currentValue = currentValue;
                cond.completedFlag = false;
            }
        }
    }
}

int32_t NFMissionPart::OnUpdateProgress(uint64_t missionId, const ExecuteData &data)
{
    return 0;
}

int32_t NFMissionPart::AddReward(uint64_t missionId, int32_t kind, TASK_REWARD &reward, float ration/* = 1*/)
{
    SCommonSource sourceParam;
    sourceParam.src = S_MISSION;
    sourceParam.param1 = missionId;
    //

    LIST_ITEM addItems;
    addItems.clear();
    if (!CanAddReward(missionId, kind, reward, addItems))
    {
        return proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH;
    }

    for (uint32_t i = 0; i < reward.size(); ++i)
    {
        uint32_t rewardType = reward[i].type;
        uint32_t profression = m_pMaster->GetAttr(proto_ff::A_PROF);
        if (reward[i].profession != 0 && profression != reward[i].profession)
        {
            continue;
        }

        if (MISSION_AWARD_SKILL == rewardType)
        {
/*            SkillPart *pSkillPart = dynamic_cast<SkillPart *>(pPlayer->GetPart(PART_SKILL));
            if (nullptr != pSkillPart)
            {
                SCommonSource source;
                if (!pSkillPart->AddSkill(reward[i].id, 1, source, true))
                {
                    LogErrFmtPrint("[logic] MissionManager::AddReward...AddSkill failed...cid:%lu, pre:%s,missionid:%lu", pPlayer->Cid(),
                                   param.strPre.c_str(), param.missionId);
                }
            }*/
        }
        else if (MISSION_AWARD_ATTR == rewardType) //属性奖励
        {
            int64_t value = ceil(reward[i].value * ration);
            //
            m_pMaster->AddAttr(reward[i].id, value, &sourceParam, true);
        }
        else if (MISSION_AWARD_UNION_EXP == rewardType)
        {
        }
        else if (MISSION_AWARD_USE_CONTRI == rewardType)
        {
        }
    }

    //添加物品
    if (addItems.size() > 0)
    {
        NFPackagePart *pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
        NF_ASSERT(pPackage);
        //上面判断过背包，这里直接添加物品
        pPackage->AddItem(addItems, sourceParam);
    }

    return proto_ff::RET_SUCCESS;
}

//是否能增加任务奖励
bool NFMissionPart::CanAddReward(uint64_t missionId, int32_t kind, TASK_REWARD &reward, LIST_ITEM &lstOutItem)
{
    LIST_ITEM addItems;
    addItems.clear();
    for (uint32_t i = 0; i < reward.size(); ++i)
    {
        uint32_t rewardType = reward[i].type;
        uint32_t profression = m_pMaster->GetAttr(proto_ff::A_PROF);

        if (reward[i].profession != 0 && profression != reward[i].profession)
        {
            continue;
        }

        if (MISSION_AWARD_GOODS == rewardType || MISSION_AWARD_EQUIP == rewardType) //装备道具奖励
        {
            SItem item;
            item.nItemID = reward[i].id;
            item.nNum = reward[i].value;
            item.byBind = reward[i].bind;
            addItems.push_back(item);
        }
        else if (MISSION_AWARD_SKILL == rewardType)
        {
/*             const SkillCfg *pSkill = g_GetSkillMgr()->GetCfg(reward[i].id);
           if (nullptr == pSkill)
            {
                LogErrFmtPrint("[logic] MissionManager::CanAddReward nullptr == pSkill  cid:%lu, pre:%s,missionid:%lu", pPlayer->Cid(),
                               param.strPre.c_str(), param.missionId);
                return false;
            }
            SkillPart *pSkillPart = dynamic_cast<SkillPart *>(pPlayer->GetPart(PART_SKILL));
            if (nullptr == pSkillPart)
            {
                LogErrFmtPrint("[logic] MissionManager::CanAddReward nullptr == pSkillPart  cid:%lu, pre:%s,missionid:%lu", pPlayer->Cid(),
                               param.strPre.c_str(), param.missionId);
                return false;
            }*/
        }
    }
    if (addItems.size() > 0)
    {
        NFPackagePart *pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
        NF_ASSERT(pPackage);

        if (!pPackage->CanAddItem(addItems))
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "missionId:{} add items failed.......", missionId);
            return false;
        }

        lstOutItem.insert(lstOutItem.end(), addItems.begin(), addItems.end());
    }
    return true;
}

//更新任务进度
void NFMissionPart::UpdateMissionProgress(uint64_t missionId)
{
    auto missionIte = _playerTrackMissionMap.find(missionId);
    if (missionIte != _playerTrackMissionMap.end())
    {
        proto_ff::GCUpdateMissionStatusNotify notify;
        proto_ff::CMissionTrack *pMissionTrack = notify.add_updatelist();
        if (nullptr != pMissionTrack)
        {
            missionIte->second.SetMissionTrackProto(*pMissionTrack);
            m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_UPDATEMISSIONSTATUSNOTIFY, notify);
        }
    }
}