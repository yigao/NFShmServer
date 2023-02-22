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
    _aryDyIdAlloc.resize(_aryDyIdAlloc.max_size());
    for (int i = 0; i < (int) _aryDyIdAlloc.size(); i++)
    {
        _aryDyIdAlloc[i] = false;
    }
    return 0;
}

int NFMissionPart::ResumeInit()
{
    return 0;
}

int NFMissionPart::RetisterClientMessage(NFIPluginManager *pPluginManager)
{
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_QUERY_MiSSIONLIST, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_NPC_ACCEPTMISSION, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_ABANDONMISSION, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_SUBMITMISSION, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_TALKWITHNPC, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_SUBMITMISSIONGOODS, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_MISSION_ONEKEY_FINISH, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_MISSION_ONCE_FINISH, PART_MISSION);
    RetisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_MISSION_RECV_SPECIAL_REWARD, PART_MISSION);
    return 0;
}

int NFMissionPart::RetisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFMissionPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);

    Subscribe(NF_ST_LOGIC_SERVER, EVENT_ITEM_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_PASS_DUPLICATE, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_ARENA_JOIN, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_ADD_FRIEND, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_STONE_INLAY, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_EQUP_STREN, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_LEVELUP, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_GUILD_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_WING_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_TREASURE_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_PARTNER_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");

    if (dbData.has_task())
    {
        const proto_ff::CharacterDBTaskData &missionDBData = dbData.task();

        //已接任务列表
        uint32_t nAccept = missionDBData.missiontrack_size();
        for (uint32_t i = 0; i < nAccept; ++i)
        {
            const proto_ff::CharacterDBMissionTrack &missionDBTrack = missionDBData.missiontrack(i);
            if (_playerTrackMissionMap.size() >= _playerTrackMissionMap.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "_playerTrackMissionMap Space Not Enough, need size:{}", nAccept);
                continue;
            }
            MissionTrack *pMissionTrack = &_playerTrackMissionMap[missionDBTrack.dynamicid()];
            if (nullptr != pMissionTrack)
            {
                if (!pMissionTrack->CopyFromMissionProto(missionDBTrack))
                {
                    continue;
                }
                uint64_t dynamicId = pMissionTrack->dynamicId;
                //任务进度等级
                int32_t progressLev = 1;
                MissionInfo *pMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(pMissionTrack->missionId);
                if (nullptr != pMissionInfo)
                {
                    progressLev = pMissionInfo->progressLev;
                }
                //检查下任务进度是否已经完成,外网出现过任务进度完成了但是状态没有置为完成状态
                bool completeFlag = true;

                for (auto iterChk = pMissionTrack->items.begin(); iterChk != pMissionTrack->items.end(); ++iterChk)
                {
                    ItemInfo &itemInfo = (*iterChk);
                    if (itemInfo.currentValue >= itemInfo.finalValue)
                    {
                        if (!itemInfo.completedFlag)
                        {
                            itemInfo.currentValue = itemInfo.finalValue;
                            itemInfo.completedFlag = true;
                            MarkDirty();
                        }
                    }
                    else
                    {
                        completeFlag = false;
                    }
                }
                //没有完成的任务才需要注册事件以及添加任务掉落
                if (!completeFlag)
                {
                    //注册事件
                    for (auto iter = pMissionTrack->items.begin(); iter != pMissionTrack->items.end(); ++iter)
                    {
                        ItemInfo &itemInfo = (*iter);
                        if (!itemInfo.completedFlag)
                        {
                            //对已接任务注册事件
                            int32_t relevent = MISSION_COND_TYPE_TO_EVENT(itemInfo.type);
                            RegisterEvent(relevent, dynamicId, progressLev);
                        }
                    }
                    //任务掉落
                    OnAddMissionDrop(pMissionTrack, progressLev);
                }
                else
                {
                    if (pMissionTrack->status != MISSION_E_COMPLETION)
                    {
                        pMissionTrack->status = MISSION_E_COMPLETION;
                    }
                }
                //
                if (ValidDyMissionId(dynamicId))
                {
                    _aryDyIdAlloc[dynamicId] = 1;
                }
            }
        }

        //已经提交的任务列表
        for (uint32_t j = 0; j < (uint32_t) missionDBData.already_submit_size(); ++j)
        {
            if (_setAlreadySubmit.size() >= _setAlreadySubmit.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "_setAlreadySubmit Space Not Enough, need size:{}",
                           missionDBData.already_submit_size());
                continue;
            }

            _setAlreadySubmit.insert(missionDBData.already_submit(j));
        }

        //动态任务次数信息
        uint32_t nDyCnt = missionDBData.dyinfo_size();
        for (uint32_t n = 0; n < nDyCnt; ++n)
        {
            const proto_ff::CharacterDBDyMissionInfo &dyInfo = missionDBData.dyinfo(n);
            if (_mapDyMissionTrack.size() >= _mapDyMissionTrack.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "_mapDyMissionTrack Space Not Enough, need size:{}", nDyCnt);
                continue;
            }
            DyMissionTrack &track = _mapDyMissionTrack[dyInfo.mission_type()];
            track.kind = dyInfo.mission_type();
            track.lastFresh = dyInfo.lastfresh();
            track.acceptNum = dyInfo.accept_num();
            track.bountyParam.ten_status = dyInfo.bounty_param().ten_state();
            track.bountyParam.twenty_status = dyInfo.bounty_param().twenty_state();
        }

        //最近提交的任务列表
        uint32_t nRecentSubmit = missionDBData.recent_submit_size();
        for (uint32_t m = 0; m < nRecentSubmit; ++m)
        {
            const proto_ff::CharacterDBRecentSubmitMission &recent = missionDBData.recent_submit(m);
            auto iter = _mapRecentSubmit.find(recent.mission_type());
            if (iter != _mapRecentSubmit.end())
            {
                if (iter->second.size() >= iter->second.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "_mapRecentSubmit mission_type Space Not Enough....");
                    continue;
                }
                iter->second.insert(recent.mission_id());
            }
            else
            {
                if (_mapRecentSubmit.size() >= _mapRecentSubmit.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "_mapRecentSubmit Space Not Enough....");
                    continue;
                }
                _mapRecentSubmit[recent.mission_type()].insert(recent.mission_id());
            }
        }
    }

    return 0;
}

int NFMissionPart::UnInit()
{
    return NFPart::UnInit();
}

int NFMissionPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    proto_ff::CharacterDBTaskData *pTaskData = dbData.mutable_task();
    pTaskData->Clear();

    //动态任务数据
    for (auto iterDy = _mapDyMissionTrack.begin(); iterDy != _mapDyMissionTrack.end(); ++iterDy)
    {
        DyMissionTrack &info = iterDy->second;
        proto_ff::CharacterDBDyMissionInfo *proto = pTaskData->add_dyinfo();
        if (nullptr != proto)
        {
            proto->set_mission_type(info.kind);
            proto->set_accept_num(info.acceptNum);
            proto->set_lastfresh(info.lastFresh);
            auto pBounty = proto->mutable_bounty_param();
            pBounty->set_ten_state(info.bountyParam.ten_status);
            pBounty->set_twenty_state(info.bountyParam.twenty_status);
        }
    }
    //已接任务列表
    for (PlayerTrackMissionMap::iterator it = _playerTrackMissionMap.begin(); it != _playerTrackMissionMap.end(); ++it)
    {
        auto pSingleMissionTrack = pTaskData->mutable_missiontrack()->Add();
        if (nullptr != pSingleMissionTrack)
        {
            it->second.SetMissionTrackProto(*pSingleMissionTrack);
        }
    }

    //已经提交任务
    for (auto iterAlready = _setAlreadySubmit.begin(); iterAlready != _setAlreadySubmit.end(); ++iterAlready)
    {
        pTaskData->add_already_submit((*iterAlready));
    }

    //最近提交的任务
    for (auto iterRecent = _mapRecentSubmit.begin(); iterRecent != _mapRecentSubmit.end(); ++iterRecent)
    {
        auto &setMission = iterRecent->second;
        for (auto iterMission = setMission.begin(); iterMission != setMission.end(); ++iterMission)
        {
            proto_ff::CharacterDBRecentSubmitMission *pRecentProto = pTaskData->add_recent_submit();
            if (nullptr != pRecentProto)
            {
                pRecentProto->set_mission_type(iterRecent->first);
                pRecentProto->set_mission_id((*iterMission));
            }
        }
    }
    return 0;
}

int NFMissionPart::OnLogin()
{
    CheckTrunkMission();
    return 0;
}

int NFMissionPart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

int NFMissionPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_QUERY_MiSSIONLIST: //任务列表
        {
            SendMissionList(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_NPC_ACCEPTMISSION: //NPC接取任务
        {
            HandleNpcAcceptMission(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_ABANDONMISSION: //放弃任务
        {
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_SUBMITMISSION: //提交任务
        {
            HandleSubmitMission(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_TALKWITHNPC: //NPC对话
        {
            HandleTalkWithNpc(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_SUBMITMISSIONGOODS: //提交物品
        {
            HandleSubmitMissionGoods(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_MISSION_ONEKEY_FINISH: //一键完成诺林冒险
        {
            HandleOnekeyFinishMission(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_MISSION_ONCE_FINISH: //立即完成
        {
            HandleOnceFinishMission(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_MISSION_RECV_SPECIAL_REWARD://领取特殊奖励
        {
            HandleMissionRecvSpecialReward(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
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
                        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "CheckTrunkMission...OnAccept failed...cid:{} ,kind:{},mission:{},ret:{} ",
                                   m_pMaster->Cid(),
                                   pMissionInfo->kind, missionid, ret);
                    }
                }
                else
                {
                    NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(),
                               "MissionPart::CheckTrunkMission...accept mission...cid:{},kind:{}, mission:{},ret:{} ", m_pMaster->Cid(),
                               pMissionInfo->kind, missionid, ret);
                }
            }
        }
    }
    else
    {
        for (auto iterRecent = _mapRecentSubmit.begin(); iterRecent != _mapRecentSubmit.end(); ++iterRecent)
        {
            auto &setMission = iterRecent->second;
            auto iterMission = setMission.begin();
            for (; iterMission != setMission.end(); ++iterMission)
            {
                uint64_t missionid = (*iterMission);
                MissionInfo *pMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(missionid);
                if (nullptr == pMissionInfo)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "CheckTrunkMission nullptr == pMissionInfo cid:{}, missionid:{} ",
                               m_pMaster->Cid(),
                               missionid);
                    continue;
                }

                uint64_t backMissionid = pMissionInfo->backTaskId;
                if (backMissionid > 0)
                {
                    MissionInfo *pBackMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(backMissionid);
                    if (nullptr == pBackMissionInfo)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                                   "CheckTrunkMission nullptr == pBackMissionInfo cid:{}, missionid:{},backMissionid:{} ",
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

                    int32_t ret = OnAccept(backMissionid, notify);
                    if (proto_ff::RET_SUCCESS != ret)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                                   "CheckTrunkMission...OnAccept failed...cid:{},mission:{},backMissionid:{},ret:{} ",
                                   m_pMaster->Cid(), missionid, backMissionid, ret);
                    }
                    else
                    {
                        NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                                   "MissionPart::CheckTrunkMission...accept mission...cid:{},kind:{}, mission:{},backMissionid:{},ret:{} ",
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

//接取任务
void NFMissionPart::OnAccept(uint64_t missionId, uint32_t kind)
{
    //
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
    int32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
    EventTabal::iterator iter = _eventTabal.find(eventType);
    if (_eventTabal.end() != iter)
    {
        auto &mapLvMission = iter->second;
        auto iterLv = mapLvMission.begin();
        for (; iterLv != mapLvMission.end(); ++iterLv)
        {
            auto &setMission = iterLv->second;
            if (iterLv->first <= level)
            {
                if (dynamicId > 0)
                {
                    auto iterMission = setMission.find(dynamicId);
                    if (iterMission != setMission.end())
                    {
                        OnUpdateProgress((*iterMission), data);
                        break;
                    }
                }
                else
                {
                    auto iterMission = setMission.begin();
                    for (; iterMission != setMission.end(); ++iterMission)
                    {
                        OnUpdateProgress((*iterMission), data);
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
MissionDropMap *NFMissionPart::GetMissionDrop(uint64_t monsterId)
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
    //先查找已接列表中是否有该任务
    auto iter = _playerTrackMissionMap.find(missionId);
    if (iter == _playerTrackMissionMap.end())
    {
        return proto_ff::RET_MISSION_NOT_EXIST;
    }

    if (MISSION_E_ACCEPTED != iter->second.status)
    {
        return proto_ff::RET_MISSION_STATE_NOT_MATCH;
    }

    SET_UINT64 setAreaMonsDy;
    setAreaMonsDy.clear();
    bool notify = false;
    //任务执行单元开始执行 多完成条件
    for (uint32_t i = 0; i < iter->second.items.size(); i++)
    {
        ItemInfo &cond = iter->second.items[i];
        OnUpdateCondProcess(data, cond, notify);
        if (notify)
        {
            MarkDirty();
            //
            if (MISSION_FINISH_TYPE_KILL_MONS_AREA == cond.type && cond.currentValue < cond.finalValue)
            {
                setAreaMonsDy.insert(missionId);
            }
        }
    }

    //判断任务是否完成
    bool isCompletedFlag = true;
    for (uint32_t i = 0; i < iter->second.items.size(); i++)
    {
        if (!iter->second.items[i].completedFlag)
        {
            isCompletedFlag = false;
            break;
        }
    }

    //如果完成了
    if (isCompletedFlag)
    {
        //任务已经完成
        iter->second.status = MISSION_E_COMPLETION;
        //
        MissionInfo *pMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetMissionCfgInfo(iter->second.missionId);
        if (nullptr != pMissionInfo)
        {
        }
        else
        {
            auto pDyMissionInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetDyMissionCfgInfo(iter->second.missionId);
            if (pDyMissionInfo)
            {
                //完成任务(动态任务)
                OnFinishDy(iter->second.dynamicId, pDyMissionInfo->kind);
            }
        }
    }

    if (notify)
    {
        UpdateMissionProgress(missionId);
    }

    if (setAreaMonsDy.size() > 0)
    {
        //OnCheckAreaFreshMonster(setAreaMonsDy);
    }

    return proto_ff::RET_SUCCESS;
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

//根据任务类型获取动态任务记录信息
DyMissionTrack *NFMissionPart::GetDyMissionTrack(int32_t missionType)
{
    PlayerDyMissionTrackMap::iterator iter = _mapDyMissionTrack.find(missionType);
    return (iter != _mapDyMissionTrack.end()) ? &iter->second : nullptr;
}

//完成任务(动态任务)
void NFMissionPart::OnFinishDy(uint64_t dymissionId, uint32_t dymissionType)
{
    if (dymissionType == MISSION_TYPE_ID_BOUNTY)
    {
        DyMissionTrack *pDyTrack = GetDyMissionTrack(MISSION_TYPE_ID_BOUNTY);
        if (pDyTrack)
        {
            SMissionReward missionReward;
            OnAddDyMissionReward(dymissionType, dymissionId, missionReward);

            if (pDyTrack->acceptNum >= 10 && pDyTrack->bountyParam.ten_status == 0)
            {
                pDyTrack->bountyParam.ten_status = 1;
            }
            else if (pDyTrack->acceptNum >= 20 && pDyTrack->bountyParam.twenty_status == 0)
            {
                pDyTrack->bountyParam.twenty_status = 1;
            }

            MarkDirty();

            SET_UINT32 setMissionType;
            setMissionType.insert(dymissionType);
            NotifyDyAcceptCount(setMissionType);
        }
    }
}

int32_t NFMissionPart::OnAddDyMissionReward(int32_t missionType, uint64_t missionId, SMissionReward &missionReward)
{
/*    if (nullptr == pPlayer)
    {
        return RET_FAIL;
    }
    int32_t level = pPlayer->GetAttr(A_LEVEL);
    const TASK_REWARD *pReward = GetDyMissionReward(missionType, level);
    if (nullptr == pReward)
    {
        return RET_FAIL;
    }
    PackagePart *pPackage = dynamic_cast<PackagePart *>(pPlayer->GetPart(PART_PACKAGE));
    if (nullptr == pPackage)
    {
        return RET_FAIL;
    }

    SCommonSource sourceParam;
    sourceParam.src = S_MISSION;
    sourceParam.param1 = missionId;

    SCenterReward sreward;
    sreward.charId = pPlayer->Cid();
    sreward.zid = pPlayer->GetZid();
    sreward.source = sourceParam;

    uint32_t profression = pPlayer->GetAttr(A_PROF);
    const TASK_REWARD &reward = *pReward;

    LIST_ITEM lstItemA;
    lstItemA.clear();
    //
    uint32_t isize = (uint32_t) reward.size();
    for (uint32_t i = 0; i < isize; ++i)
    {
        uint32_t rewardType = reward[i].type;

        if (reward[i].profession != 0 && profression != reward[i].profession)
        {
            continue;
        }
        if (MISSION_AWARD_GOODS == rewardType || MISSION_AWARD_EQUIP == rewardType)
        {
            pPackage->AddItem(reward[i].id, reward[i].value, sourceParam, reward[i].bind);

            //
            SItem item;
            item.nItemID = reward[i].id;
            item.nNum = reward[i].value;
            item.byBind = reward[i].bind;
            lstItemA.push_back(item);
        }
        else if (MISSION_AWARD_SKILL == rewardType)
        {
            SkillPart *pSkillPart = dynamic_cast<SkillPart *>(pPlayer->GetPart(PART_SKILL));
            if (nullptr != pSkillPart)
            {
                SCommonSource source;
                if (!pSkillPart->AddSkill(reward[i].id, 1, source, true))
                {
                    LogErrFmtPrint("[logic] MissionManager::OnAddDyMissionReward...AddSkill failed...cid:%lu,missionType:%d, level:%d,missionId:%lu ",
                                   pPlayer->Cid(), missionType, level, missionId);
                }
                else
                {
                    missionReward.setSkill.insert(reward[i].id);
                }
            }
        }
        else if (MISSION_AWARD_ATTR == rewardType) //属性奖励
        {
            pPlayer->AddAttr(reward[i].id, reward[i].value, &sourceParam, true);
            missionReward.mapAttr[reward[i].id] += reward[i].value;
        }
        else if (MISSION_AWARD_USE_CONTRI == rewardType)
        {
            sreward.useContri += reward[i].id;
            missionReward.useContri += reward[i].id;
        }
        else if (MISSION_AWARD_UNION_EXP == rewardType)
        {
            sreward.unionExp += reward[i].id;
            missionReward.unionExp += reward[i].id;
        }
    }
    //
    g_GetItemMgr()->MergeItem(lstItemA, missionReward.lstItem);*/

    return proto_ff::RET_SUCCESS;
}

//更新动态任务接取次数
void NFMissionPart::NotifyDyAcceptCount(SET_UINT32 &setMissionType)
{
    proto_ff::GCUpdateDyAcceptCount notify;
    proto_ff::DyMissionCntAllProto *proto = notify.mutable_dy_count();
    if (nullptr != proto)
    {
        SET_UINT32::iterator iter = setMissionType.begin();
        for (; iter != setMissionType.end(); ++iter)
        {
            uint32_t missionType = (*iter);
            uint32_t acceptNum = 0;
            DyMissionTrack *pDyTrack = GetDyMissionTrack(missionType);
            if (nullptr != pDyTrack)
            {
                acceptNum = pDyTrack->acceptNum;
            }

            proto_ff::DyMissionCntProto *protoA = proto->add_count();
            if (nullptr != protoA)
            {
                protoA->set_missiontype(missionType);
                protoA->set_accept_num(acceptNum);
                if (missionType == MISSION_TYPE_ID_BOUNTY)
                {
                    auto pBounty = protoA->mutable_bounty_param();
                    pBounty->set_ten_state(pDyTrack->bountyParam.ten_status);
                    pBounty->set_twenty_state(pDyTrack->bountyParam.twenty_status);
                }
            }
        }

        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_UPDDATE_DY_ACCEPT_NUM, notify);
    }
}

bool NFMissionPart::ValidDyMissionId(uint64_t dyMissionId) //是否是有效的动态任务ID
{
    if (dyMissionId >= 1 && dyMissionId <= MISSION_MAX_DYNAMIC_ALLOC)
    {
        return true;
    }
    return false;
}

uint64_t NFMissionPart::AllocNewDyMisssionId() //分配一个动态任务ID
{
    for (uint32_t i = 1; i <= MISSION_MAX_DYNAMIC_ALLOC; ++i)
    {
        if (!_aryDyIdAlloc[i])
        {
            _aryDyIdAlloc[i] = true;
            return i;
        }
    }
    return 0;
}

void NFMissionPart::FreeDyMissionId(uint64_t dyMissionId) //回收一个动态任务ID
{
    if (dyMissionId >= 1 && dyMissionId <= MISSION_MAX_DYNAMIC_ALLOC)
    {
        _aryDyIdAlloc[dyMissionId] = false;
    }
}

int NFMissionPart::HandleNpcAcceptMission(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::CGNpcAcceptMissionReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    uint64_t cid = m_pMaster->Cid();
    int32_t missionType = req.missiontype();
    //
    int32_t ret = proto_ff::RET_MISSION_NOT_EXIST;
    ret = AcceptMissionByType(missionType, true);
    if (proto_ff::RET_SUCCESS != ret)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "HandleNpcAcceptMission....AcceptMissionByType failed...cid:{},missionType:{},ret:{} ", cid,
                   missionType, ret);
    }

    proto_ff::CGNpcAcceptMissionRsp rsp;
    rsp.set_missiontype(missionType);
    rsp.set_retcode(ret);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_NPC_ACCEPTMISSION, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::HandleSubmitMission(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::HandleTalkWithNpc(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::HandleSubmitMissionGoods(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::HandleOnekeyFinishMission(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::HandleOnceFinishMission(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::HandleMissionRecvSpecialReward(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFMissionPart::SendMissionList(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::CGQueryMissionListReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    proto_ff::GCQueryMissionListRsp rsp;

    //已接任务列表
    for (auto missionIte = _playerTrackMissionMap.begin(); missionIte != _playerTrackMissionMap.end(); ++missionIte)
    {
        proto_ff::CMissionTrack *missionTrack = rsp.add_acceptedlist();
        if (nullptr != missionTrack)
        {
            missionIte->second.SetMissionTrackProto(*missionTrack);
        }
    }

    //动态任务周期内已经接取的次数
    proto_ff::DyMissionCntAllProto *pAllProto = rsp.mutable_dy_count();
    if (nullptr != pAllProto)
    {
        for (auto iter = _mapDyMissionTrack.begin(); iter != _mapDyMissionTrack.end(); ++iter)
        {
            DyMissionTrack *pDyTrack = &iter->second;
            if (nullptr != pDyTrack)
            {
                proto_ff::DyMissionCntProto *proto = pAllProto->add_count();
                if (nullptr != proto)
                {
                    proto->set_missiontype(iter->first);
                    proto->set_accept_num(pDyTrack->acceptNum);
                    if (iter->first == MISSION_TYPE_ID_BOUNTY)
                    {
                        auto pBounty = proto->mutable_bounty_param();
                        pBounty->set_ten_state(pDyTrack->bountyParam.ten_status);
                        pBounty->set_twenty_state(pDyTrack->bountyParam.twenty_status);
                    }
                }
            }
        }
    }

    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_QUERY_MiSSIONLIST, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int32_t NFMissionPart::AcceptMissionByType(int32_t missionType, bool notify)
{
    int32_t ret = CanAcceptMissionByType(missionType);
    if (proto_ff::RET_SUCCESS == ret)
    {
        uint64_t missionId = DyRandMissionId(missionType);
        const DyMissionInfo *pDyMissionCfgInfo = NFMissionDescStoreEx::Instance(m_pObjPluginManager)->GetDyMissionCfgInfo(missionId);
        if (nullptr == pDyMissionCfgInfo)
        {
            ret = proto_ff::RET_MISSION_NOT_EXIST;
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                       "AcceptMissionByType...can not find mission config....cid:{} ,missionType:{}, missionid:{}, notify:{}", m_pMaster->Cid(),
                       missionType, missionId, (int32_t) notify);
        }
        else
        {
            ret = OnAcceptDy(missionId, notify);
            if (proto_ff::RET_SUCCESS != ret)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
                           "AcceptMissionByType...OnAcceptDy failed....cid:{} ,missionType:{}, missionid:{}, notify:{}, ret:{} ", m_pMaster->Cid(),
                           missionType, missionId, (int32_t) notify, ret);
            }
        }
    }

    return ret;
}

//根据任务类型随机一个任务ID
uint64_t NFMissionPart::DyRandMissionId(int32_t missionType)
{
    const SET_UINT64 *pMissionLst = GetDyMissionLstByType(missionType);
    if (nullptr == pMissionLst)
    {
        MMOLOG_FMT_ERROR("DyRandMissionId...nullptr == pMissionLst...missionType:%d ,cid:%lu ", missionType, cid);
        return RET_FAIL;
    }
    uint32_t level = pPlayer->GetAttr(A_LEVEL);
    //获取满足条件的任务ID
    VEC_UINT64 vecMission;
    vecMission.clear();
    SET_UINT64::const_iterator iterSet = pMissionLst->begin();
    for (; iterSet != pMissionLst->end(); ++iterSet)
    {
        const uint64_t missionId = (*iterSet);
        const DyMissionInfo *pDyMissionCfgInfo = GetDyMissionCfgInfo(missionId);
        if (nullptr == pDyMissionCfgInfo || level < pDyMissionCfgInfo->minLev || level > pDyMissionCfgInfo->maxLev)
        {
            continue;
        }
        vecMission.push_back(missionId);
    }
    int32_t iszie = vecMission.size();
    if (iszie <= 0)
    {
        MMOLOG_FMT_ERROR("DyRandMissionId....iszie <= 0....missionType:%d, cid:%lu ", missionType, cid);
        return RET_FAIL;
    }
    int32_t rnd = Random(iszie);
    uint64_t resmissionId = vecMission.at(rnd);
    //
    return resmissionId;
}

//获取任务最大环数
int32_t NFMissionPart::DyMaxCount(int32_t missionType, int32_t level)
{
    int32_t count = 0;
    auto pTaskDynamicCfg = TaskdynamicTaskdynamicDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    for (auto iter = pTaskDynamicCfg->begin(); iter != pTaskDynamicCfg->end(); ++iter)
    {
        auto &info = *iter;
        if (missionType == info.m_tasktype && level >= info.m_minlv && level <= info.m_maxlv)
        {
            count = info.m_rececount;
            break;
        }
    }
    return count;
}

//根据任务类型获取动态任务已经接取次数
uint32_t NFMissionPart::GetDyMissionAceeptCnt(int32_t missionType)
{
    DyMissionTrack *pDyTrack = GetDyMissionTrack(missionType);
    if (nullptr != pDyTrack)
    {
        return pDyTrack->acceptNum;
    }
    return 0;
}

int32_t NFMissionPart::CanAcceptMissionByType(int32_t missionType)
{
    if (MISSION_TYPE_ID_GUILD == missionType)
    {
        if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
        {
            return proto_ff::RET_FACTION_NOT_JOIN;
        }
    }
    int32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
    int32_t maxCount = DyMaxCount(missionType, level);
    int32_t acceptNum = GetDyMissionAceeptCnt(missionType);
    if (maxCount == MISSION_INFINITE_COUNT || acceptNum < maxCount)
    {
        if (MissionNumByType(missionType) <= 0)
        {
            return proto_ff::RET_SUCCESS;
        }
        else
        {
            return proto_ff::RET_MISSION_HAVE_TYPE_ACCEPT;
        }
    }
    return proto_ff::RET_MISSION_PERIOD_FINISH_NUM_LIMIT;
}

int32_t NFMissionPart::ClearMissionByType(int32_t missionType, bool notify)
{
    return 0;
}
