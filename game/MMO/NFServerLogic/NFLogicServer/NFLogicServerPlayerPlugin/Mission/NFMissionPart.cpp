// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#include "NFMissionPart.h"

#include <Achievement/NFGodRelicsPart.h>
#include <DescStore/BossBossDesc.h>
#include <DescStoreEx/MonsterDescEx.h>
#include <DescStoreEx/SkillDescEx.h>
#include <Facade/NFEquipPart.h>
#include <Facade/NFFacadePart.h>
#include <Fest/NFFestPart.h>
#include <NFComm/NFCore/NFTimeUtility.h>
#include <Player/NFFunctionUnlockPart.h>
#include <Player/NFMiniActivityPart.h>
#include <Skill/NFSkillPart.h>

#include "NFLogicCommon/NFEventDefine.h"
#include "proto_svr_event.pb.h"
#include "Package/NFPackagePart.h"
#include "NFComm/NFCore/NFRandom.hpp"

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
	m_aryDyIdAlloc.resize(m_aryDyIdAlloc.max_size());
	for (int i = 0; i < (int)m_aryDyIdAlloc.size(); i++)
	{
		m_aryDyIdAlloc[i] = false;
	}
	return 0;
}

int NFMissionPart::ResumeInit()
{
	return 0;
}

int NFMissionPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
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
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_LIGHT_SOUL, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_COLLECT, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_EQUIP_DRESS, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_EQUIP_UNDRESS, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_JOIN_CLAN, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	Subscribe(NF_ST_LOGIC_SERVER, EVENT_GOD_RELICS_GROUP_FINISH, CREATURE_PLAYER, m_pMaster->Cid(), "MissionPart");
	return 0;
}

int NFMissionPart::UnInit()
{
	return NFPart::UnInit();
}

int NFMissionPart::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
	//走任务内部事件
	switch (nEventID)
	{
		case EVENT_CREATURE_DEAD: //生物死亡
		{
			OnDie();
			break;
		}
		case EVENT_ITEM_CHANGE:
		{
			OnItemChange(pMessage);
			break;
		}
		case EVENT_ARENA_JOIN:
		{
			OnArenaJoin(pMessage);
			break;
		}
		case EVENT_PASS_DUPLICATE:
		{
			OnPassDuplicate(pMessage);
			break;
		}
		case EVENT_ADD_FRIEND:
		{
			OnAddFriend();
			break;
		}
		case EVENT_STONE_INLAY:
		{
			OnStoneInlay(pMessage);
			break;
		}
		case EVENT_EQUP_STREN:
		{
			OnSlotStren(pMessage);
			break;
		}
		case EVENT_LEVELUP:
		{
			OnLevelUp();
			break;
		}
		case EVENT_GUILD_CHANGE:
		{
			OnGuildChange(pMessage);
			break;
		}
		case EVENT_WING_ADVANCE:
		{
			OnWingLevup(pMessage);
			break;
		}
		case EVENT_TREASURE_ADVANCE:
		{
			OnTreasureLevup(pMessage);
			break;
		}
		case EVENT_PARTNER_ADVANCE:
		{
			OnPartnerLevup(pMessage);
			break;
		}
		case EVENT_LIGHT_SOUL:
		{
			OnLightSoul(pMessage);
			break;
		}
		case EVENT_FUNCTIONUNLOCK:
		{
			const proto_ff::FunctionUnlockEvent* pEvent = dynamic_cast<const proto_ff::FunctionUnlockEvent *>(pMessage);
			if (nullptr != pEvent)
			{
				CheckFunctionMisssion(pEvent->functionid());
			}
			break;
		}
		case EVENT_COLLECT:
		{
			OnCollectEvent(pMessage);
			break;
		}
		case EVENT_EQUIP_DRESS:
		{
			OnEquipDress(pMessage);
			break;
		}
		case EVENT_EQUIP_UNDRESS:
		{
			OnEquipUnDress(pMessage);
			break;
		}
		case EVENT_JOIN_CLAN:
		{
			OnJoinClan(pMessage);
			break;
		}
		case EVENT_GOD_RELICS_GROUP_FINISH:
		{
			OnGodRelicTaskGroup(pMessage);
			break;
		}
		default:
			break;
	}
	return 0;
}

int NFMissionPart::RegisterMessage()
{
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_QUERY_MiSSIONLIST);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_NPC_ACCEPTMISSION);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_ABANDONMISSION);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_SUBMITMISSION);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_TALKWITHNPC);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_SUBMITMISSIONGOODS);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_MISSION_ONEKEY_FINISH);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_MISSION_ONCE_FINISH);
	RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_MISSION_RECV_SPECIAL_REWARD);
	return 0;
}

int NFMissionPart::LoadFromDB(const proto_ff::RoleDBData& dbData)
{
	if (dbData.has_task())
	{
		const proto_ff::CharacterDBTaskData& missionDBData = dbData.task();
		//已接任务列表
		uint32_t nAccept = missionDBData.missiontrack_size();
		for (uint32_t i = 0; i < nAccept; ++i)
		{
			const proto_ff::CharacterDBMissionTrack& missionDBTrack = missionDBData.missiontrack(i);
			if (m_playerTrackMissionMap.size() >= m_playerTrackMissionMap.max_size())
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_playerTrackMissionMap Space Not Enough, need size:{}", nAccept);
				continue;
			}
			MissionTrack* pMissionTrack = &m_playerTrackMissionMap[missionDBTrack.dynamicid()];
			if (nullptr != pMissionTrack)
			{
				if (!pMissionTrack->CopyFromMissionProto(missionDBTrack))
				{
					continue;
				}
				uint64_t dynamicId = pMissionTrack->dynamicId;
				//任务进度等级
				int32_t progressLev = 1;
				MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(pMissionTrack->missionId);
				if (nullptr != pMissionInfo)
				{
					progressLev = pMissionInfo->progressLev;
				}
				//检查下任务进度是否已经完成,外网出现过任务进度完成了但是状态没有置为完成状态
				bool completeFlag = true;
				for (auto iterChk = pMissionTrack->items.begin(); iterChk != pMissionTrack->items.end(); ++iterChk)
				{
					ItemInfo& itemInfo = (*iterChk);
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
						ItemInfo& itemInfo = (*iter);
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
					m_aryDyIdAlloc[dynamicId] = 1;
				}
			}
		}
		//已经提交的任务列表
		for (uint32_t j = 0; j < (uint32_t)missionDBData.already_submit_size(); ++j)
		{
			if (m_setAlreadySubmit.size() >= m_setAlreadySubmit.max_size())
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_setAlreadySubmit Space Not Enough, need size:{}",
						   missionDBData.already_submit_size());
				continue;
			}
			m_setAlreadySubmit.insert(missionDBData.already_submit(j));
		}
		//动态任务次数信息
		uint32_t nDyCnt = missionDBData.dyinfo_size();
		for (uint32_t n = 0; n < nDyCnt; ++n)
		{
			const proto_ff::CharacterDBDyMissionInfo& dyInfo = missionDBData.dyinfo(n);
			if (m_mapDyMissionTrack.size() >= m_mapDyMissionTrack.max_size())
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapDyMissionTrack Space Not Enough, need size:{}", nDyCnt);
				continue;
			}
			DyMissionTrack& track = m_mapDyMissionTrack[dyInfo.mission_type()];
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
			const proto_ff::CharacterDBRecentSubmitMission& recent = missionDBData.recent_submit(m);
			auto iter = m_mapRecentSubmit.find(recent.mission_type());
			if (iter != m_mapRecentSubmit.end())
			{
				if (iter->second.size() >= iter->second.max_size())
				{
					NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapRecentSubmit mission_type Space Not Enough....");
					continue;
				}
				iter->second.insert(recent.mission_id());
			}
			else
			{
				if (m_mapRecentSubmit.size() >= m_mapRecentSubmit.max_size())
				{
					NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapRecentSubmit Space Not Enough....");
					continue;
				}
				m_mapRecentSubmit[recent.mission_type()].insert(recent.mission_id());
			}
		}
	}
	return 0;
}

int NFMissionPart::SaveDB(proto_ff::RoleDBData& dbData)
{
	proto_ff::CharacterDBTaskData* pTaskData = dbData.mutable_task();
	pTaskData->Clear();
	//动态任务数据
	for (auto iterDy = m_mapDyMissionTrack.begin(); iterDy != m_mapDyMissionTrack.end(); ++iterDy)
	{
		DyMissionTrack& info = iterDy->second;
		proto_ff::CharacterDBDyMissionInfo* proto = pTaskData->add_dyinfo();
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
	for (PlayerTrackMissionMap::iterator it = m_playerTrackMissionMap.begin(); it != m_playerTrackMissionMap.end(); ++it)
	{
		auto pSingleMissionTrack = pTaskData->mutable_missiontrack()->Add();
		if (nullptr != pSingleMissionTrack)
		{
			it->second.SetMissionTrackProto(*pSingleMissionTrack);
		}
	}
	//已经提交任务
	for (auto iterAlready = m_setAlreadySubmit.begin(); iterAlready != m_setAlreadySubmit.end(); ++iterAlready)
	{
		pTaskData->add_already_submit((*iterAlready));
	}
	//最近提交的任务
	for (auto iterRecent = m_mapRecentSubmit.begin(); iterRecent != m_mapRecentSubmit.end(); ++iterRecent)
	{
		auto& setMission = iterRecent->second;
		for (auto iterMission = setMission.begin(); iterMission != setMission.end(); ++iterMission)
		{
			proto_ff::CharacterDBRecentSubmitMission* pRecentProto = pTaskData->add_recent_submit();
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
	//检查工会任务
	CheckGuildMission(false);
	//检查任务刷新
	CheckMissionFresh(false);
	//检查主支线任务
	CheckTrunkMission(false);
	return 0;
}

int NFMissionPart::DailyZeroUpdate()
{
	//检查任务刷新
	CheckMissionFresh(true);
	return 0;
}

int NFMissionPart::WeekZeroUpdate()
{
	//检查任务刷新
	CheckMissionFresh(true);
	return 0;
}

int NFMissionPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
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
		case proto_ff::CLIENT_TO_LOGIC_MISSION_RECV_SPECIAL_REWARD: //领取特殊奖励
		{
			HandleMissionRecvSpecialReward(msgId, packet);
			break;
		}
		default:
			break;
	}
	return 0;
}

int NFMissionPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
	return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFMissionPart::CheckTrunkMission(bool notify)
{
	if ((m_mapRecentSubmit.size() <= 0 && m_playerTrackMissionMap.size() <= 0) ||
		((!HaveRecentSubmit(MISSION_TYPE_ID_TRUNK)) && (MissionNumByType(MISSION_TYPE_ID_TRUNK) <= 0)))
	{
		//最近提交任务列表为空,并且已接取任务列表也为空
		//最近提交任务列表不为空，并且最近提交任务列表中没有主线任务，并且已接取任务列表也为空中也没有主线任务
		auto& mapFirst = TaskDescEx::Instance()->GetFirstMission();
		for (auto iterFirt = mapFirst.begin(); iterFirt != mapFirst.end(); ++iterFirt)
		{
			auto& setMission = iterFirt->second;
			for (auto iterMission = setMission.begin(); iterMission != setMission.end(); ++iterMission)
			{
				uint64_t missionid = (*iterMission);
				MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionid);
				if (nullptr == pMissionInfo)
				{
					NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "CheckTrunkMission nullptr == pMissionInfo cid:{}, missionid:{} ",
							   m_pMaster->Cid(),
							   missionid);
					continue;
				}
				if (HaveAccept(missionid))
				{
					continue;
				}
				if (HaveSubmited(missionid))
				{
					continue;
				}
				int32_t ret = AcceptMission(missionid, notify);
				if (proto_ff::RET_SUCCESS != ret)
				{
					if (MISSION_TYPE_ID_TRUNK == pMissionInfo->kind)
					{
						NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
								   "CheckTrunkMission...OnAcceptType failed...cid:{}, kind:{}, mission:{}, ret:{} ",
								   m_pMaster->Cid(),
								   pMissionInfo->kind, missionid, ret);
					}
				}
				else
				{
					NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
							   "MissionPart::CheckTrunkMission...accept mission...cid:{}, kind:{}, mission:{}, ret:{} ", m_pMaster->Cid(),
							   pMissionInfo->kind, missionid, ret);
				}
			}
		}
	}
	else
	{
		for (auto iterRecent = m_mapRecentSubmit.begin(); iterRecent != m_mapRecentSubmit.end(); ++iterRecent)
		{
			auto& setMission = iterRecent->second;
			for (auto iterMission = setMission.begin(); iterMission != setMission.end(); ++iterMission)
			{
				uint64_t missionid = (*iterMission);
				MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionid);
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
					MissionInfo* pBackMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(backMissionid);
					if (nullptr == pBackMissionInfo)
					{
						NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
								   "CheckTrunkMission nullptr == pBackMissionInfo cid:{}, missionid:{},backMissionid:{} ",
								   m_pMaster->Cid(), missionid, backMissionid);
						continue;
					}
					//
					if (HaveAccept(backMissionid))
					{
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
					int32_t ret = AcceptMission(backMissionid, notify);
					if (proto_ff::RET_SUCCESS != ret)
					{
						NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
								   "CheckTrunkMission...OnAcceptType failed...cid:{},mission:{},backMissionid:{},ret:{} ",
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

void NFMissionPart::CheckLevMission(bool notify)
{
	uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
	auto pMissionLst = TaskDescEx::Instance()->GetLevMission(level);
	if (nullptr != pMissionLst)
	{
		for (auto iterMission = pMissionLst->begin(); iterMission != pMissionLst->end(); ++iterMission)
		{
			uint64_t missionId = (*iterMission);
			//
			if (HaveAccept(missionId))
			{
				continue;
			}
			if (HaveSubmited(missionId))
			{
				continue;
			}
			int32_t ret = AcceptMission(missionId, notify);
			if (proto_ff::RET_SUCCESS != ret)
			{
				NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "CheckLevMission...OnAccept failed...cid:%lu,mission:%lu,ret:%d,level:%u ", m_pMaster->Cid(), missionId,
							  ret, level);
			}
			else
			{
				NFLogDebugFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "CheckLevMission...accept mission...cid:%lu, mission:%lu,ret:%d, level:%u ", m_pMaster->Cid(),
							  missionId, ret, level);
			}
		}
	}
}

void NFMissionPart::CheckGuildMission(bool notify)
{
	if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
	{
		ClearMissionByType(MISSION_TYPE_ID_GUILD, notify);
	}
	else
	{
		//m_guildMission.InitPrestige();
		CheckLevMission(notify);
		CheckTrunkMission(notify);
		if (MissionNumByType(MISSION_TYPE_ID_WEEK_LOOP_INSTANCE) <= 0 && !HaveSubmitedByType(MISSION_TYPE_ID_WEEK_LOOP_INSTANCE))
		{
			AcceptMissionByType(MISSION_TYPE_ID_WEEK_LOOP_INSTANCE, notify);
		}
		if (MissionNumByType(MISSION_TYPE_ID_GUILD_PRESTIGE_TASK) <= 0 && MissionNumByType(MISSION_TYPE_ID_GUILD_PRESTIGE_TASK_INSTANCE) <= 0)
		{
			//if (m_guildMission.m_prestigeData.accept_num() > 0)
			//{
			//	AcceptDyMissionByType(MISSION_TYPE_ID_GUILD_PRESTIGE_TASK_INSTANCE, notify);
			//}
		}
	}
}

void NFMissionPart::CheckMissionFresh(bool notify)
{
	uint64_t nowTime = NFTime::Now().UnixSec();
	//
	SET_UINT32 setMissionType;
	//周循环任务，每周重置
	DyMissionTrack* pDyLoop = GetDyMissionTrack(MISSION_TYPE_ID_WEEK_LOOP);
	if (nullptr != pDyLoop && NFTimeUtility::CheckWeekUpdate(nowTime, pDyLoop->lastFresh))
	{
		pDyLoop->acceptNum = 0;
		pDyLoop->lastFresh = nowTime;
		setMissionType.insert(pDyLoop->kind);
		//清空诺林冒险任务
		ClearMissionByType(MISSION_TYPE_ID_WEEK_LOOP, notify);
		//
		SetNeedSave(true);
	}
	DyMissionTrack* pDyBounty = GetDyMissionTrack(MISSION_TYPE_ID_BOUNTY);
	if (nullptr != pDyBounty && NFTimeUtility::CheckDayUpdate(nowTime, pDyBounty->lastFresh))
	{
		NFMiniActivityPart* pActivityPart = dynamic_cast<NFMiniActivityPart *>(m_pMaster->GetPart(PART_MINI_ACTIVITY));
		if (pActivityPart)
		{
			uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
			int32_t maxCount = DyMaxCount(MISSION_TYPE_ID_BOUNTY, level);
			pActivityPart->AddBackTask(BACK_TYPE_TASK, MISSION_TYPE_ID_BOUNTY, maxCount - pDyBounty->acceptNum, 0, pDyBounty->lastFresh, maxCount, 0);
		}
		pDyBounty->acceptNum = 0;
		pDyBounty->lastFresh = nowTime;
		pDyBounty->bountyParam.ten_status = 0;
		pDyBounty->bountyParam.twenty_status = 0;
		setMissionType.insert(pDyBounty->kind);
		//清空赏金任务任务
		ClearMissionByType(MISSION_TYPE_ID_BOUNTY, notify);
		//
		SetNeedSave(true);
	}
	//工会任务是每天重置
	DyMissionTrack* pDyGuild = GetDyMissionTrack(MISSION_TYPE_ID_GUILD);
	if (nullptr != pDyGuild && NFTimeUtility::CheckDayUpdate(nowTime, pDyGuild->lastFresh))
	{
		NFMiniActivityPart* pActivityPart = dynamic_cast<NFMiniActivityPart *>(m_pMaster->GetPart(PART_MINI_ACTIVITY));
		if (pActivityPart)
		{
			uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
			int32_t maxCount = DyMaxCount(MISSION_TYPE_ID_GUILD, level);
			pActivityPart->AddBackTask(BACK_TYPE_TASK, MISSION_TYPE_ID_GUILD, maxCount - pDyGuild->acceptNum, 0, pDyGuild->lastFresh, maxCount, 0);
		}
		pDyGuild->acceptNum = 0;
		pDyGuild->lastFresh = nowTime;
		setMissionType.insert(pDyGuild->kind);
		//清空工会任务
		ClearMissionByType(MISSION_TYPE_ID_GUILD, notify);
		//
		SetNeedSave(true);
	}
	//工会任务是每天重置
	DyMissionTrack* pDyGuildPrestige = GetDyMissionTrack(MISSION_TYPE_ID_GUILD_PRESTIGE_TASK);
	if (nullptr != pDyGuildPrestige && NFTimeUtility::CheckDayUpdate(nowTime, pDyGuildPrestige->lastFresh))
	{
		NFMiniActivityPart* pActivityPart = dynamic_cast<NFMiniActivityPart *>(m_pMaster->GetPart(PART_MINI_ACTIVITY));
		if (pActivityPart)
		{
			uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
			int32_t maxCount = DyMaxCount(MISSION_TYPE_ID_GUILD_PRESTIGE_TASK, level);
			pActivityPart->AddBackTask(BACK_TYPE_TASK, MISSION_TYPE_ID_GUILD_PRESTIGE_TASK, maxCount - pDyGuildPrestige->acceptNum, 0, pDyGuildPrestige->lastFresh, maxCount, 0);
		}
		pDyGuildPrestige->acceptNum = 0;
		pDyGuildPrestige->lastFresh = nowTime;
		setMissionType.insert(pDyGuildPrestige->kind);
		//清空工会任务
		ClearMissionByType(MISSION_TYPE_ID_GUILD_PRESTIGE_TASK, notify);
		//
		SetNeedSave(true);
	}
	DyMissionTrack* pEscort = GetDyMissionTrack(MISSION_TYPE_ID_ESCORT);
	if (nullptr != pEscort && NFTimeUtility::CheckDayUpdate(nowTime, pEscort->lastFresh))
	{
		NFMiniActivityPart* pActivityPart = dynamic_cast<NFMiniActivityPart *>(m_pMaster->GetPart(PART_MINI_ACTIVITY));
		if (pActivityPart)
		{
			uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
			int32_t maxCount = DyMaxCount(MISSION_TYPE_ID_ESCORT, level);
			pActivityPart->AddBackTask(BACK_TYPE_TASK, MISSION_TYPE_ID_ESCORT, maxCount - pEscort->acceptNum, 0, pEscort->lastFresh, maxCount, 0);
		}
		pEscort->acceptNum = 0;
		pEscort->lastFresh = nowTime;
		setMissionType.insert(pEscort->kind);
		//清空诺林冒险任务
		ClearMissionByType(MISSION_TYPE_ID_ESCORT, notify);
		//
		SetNeedSave(true);
	}
	DyMissionTrack* pHuntTreasure = GetDyMissionTrack(MISSION_TYPE_ID_HUNT_TREASURE);
	if (nullptr != pHuntTreasure && NFTimeUtility::CheckDayUpdate(nowTime, pHuntTreasure->lastFresh))
	{
		int32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
		pHuntTreasure->acceptNum = DyMaxCount(MISSION_TYPE_ID_HUNT_TREASURE, level);
		pHuntTreasure->lastFresh = nowTime;
		setMissionType.insert(pHuntTreasure->kind);
		ClearMissionByType(MISSION_TYPE_ID_HUNT_TREASURE, notify);
		if (HaveSubmitedByType(MISSION_TYPE_ID_HUNT_TREASURE_INSTANCE))
		{
			ClearSubmitedByType(MISSION_TYPE_ID_HUNT_TREASURE_INSTANCE);
			AcceptMissionByType(MISSION_TYPE_ID_HUNT_TREASURE_INSTANCE, notify);
		}
		//
		SetNeedSave(true);
	}
	//
	if (notify)
	{
		NotifyDyAcceptCount(setMissionType);
	}
}

void NFMissionPart::CheckFunctionMisssion(uint64_t functionid, bool notify)
{
	auto pMissionLst = TaskDescEx::Instance()->GetFunctionMission(functionid);
	if (nullptr != pMissionLst)
	{
		for (auto iterMission = pMissionLst->begin(); iterMission != pMissionLst->end(); ++iterMission)
		{
			uint64_t missionId = (*iterMission);
			//
			if (HaveAccept(missionId))
			{
				continue;
			}
			if (HaveSubmited(missionId))
			{
				continue;
			}
			int32_t ret = AcceptMission(missionId, notify);
			if (proto_ff::RET_SUCCESS != ret)
			{
				NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "OnAccept failed...cid:%lu,mission:%lu,ret:%d,functionId:%u ", m_pMaster->Cid(),
							  missionId,
							  ret, functionid);
			}
			else
			{
				NFLogDebugFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "CheckFunctionMisssion...accept mission...cid:%lu, mission:%lu,ret:%d, functionId:%u ",
							  m_pMaster->Cid(),
							  missionId, ret, functionid);
			}
		}
	}
}

int NFMissionPart::HandleNpcAcceptMission(uint32_t msgId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
	proto_ff::CGNpcAcceptMissionReq req;
	CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
	uint64_t cid = m_pMaster->Cid();
	int32_t missionType = req.missiontype();
	//
	int32_t ret = proto_ff::RET_MISSION_NOT_EXIST;
	ret = AcceptDyMissionByType(missionType, true);
	if (proto_ff::RET_SUCCESS != ret)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "HandleNpcAcceptMission....AcceptMissionByType failed...cid:{},missionType:{},ret:{} ", cid,
				   missionType, ret);
	}
	proto_ff::CGNpcAcceptMissionRsp rsp;
	rsp.set_missiontype(missionType);
	rsp.set_retcode(ret);
	m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_NPC_ACCEPTMISSION, rsp);
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

int NFMissionPart::HandleSubmitMission(uint32_t msgId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
	proto_ff::CGSubmitMissionReq req;
	CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

	proto_ff::GCSubmitMissionRsp rsp;
	uint64_t dymissionId = req.dynamicid();
	uint32_t index = req.index();
	//
	MissionInfo* pMissionCfgInfo = nullptr;
	const DyMissionInfo* pDyMissionCfgInfo = nullptr;
	int32_t ret = proto_ff::RET_MISSION_NOT_EXIST;
	auto pMissionTrack = GetMissionTrack(dymissionId);
	if (pMissionTrack)
	{
		uint64_t missionId = pMissionTrack->missionId;
		pMissionCfgInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
		if (nullptr != pMissionCfgInfo)
		{
			ret = OnSubmit(missionId, index);
		}
		else
		{
			pDyMissionCfgInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
			if (nullptr != pDyMissionCfgInfo)
			{
				ret = OnSubmitDy(dymissionId);
			}
		}
	}
	if (proto_ff::RET_MISSION_NOT_EXIST != ret && proto_ff::RET_SUCCESS != ret) //这里做特殊处理，成功和任务不存在的时候不返回给前端，只有其他错误的时候才返回给前端
	{
		rsp.set_dynamicid(dymissionId);
		rsp.set_ret(ret);
		m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_SUBMITMISSION, rsp);
	}
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

int NFMissionPart::HandleTalkWithNpc(uint32_t msgId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
	proto_ff::CGTalkWithNpcReq req;
	CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
	uint64_t dymissionId = req.dynamicid();
	uint64_t itemId = req.npcid();
	uint32_t type = req.type();
	PlayerTrackMissionMap::iterator it = m_playerTrackMissionMap.find(dymissionId);
	if (it == m_playerTrackMissionMap.end())
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] CGTalkWithNpcReq but dymissionId = %lu not in playerTrackMissionMap...cid:%lu",
				   dymissionId, m_pMaster->Cid());
		return -1;
	}
	//只有对话和到达某区域可以通过该协议进行提交
	if (type != MISSION_FINISH_TYPE_KILL_MONS_AREA
		&& type != MISSION_FINISH_TYPE_TAKL
		&& type != MISSION_FINISH_TYPE_AREA
		&& type != MISSION_FINISH_TYPE_FINISH_ACTION)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] CGTalkWithNpcReq...type error... cid:%lu, dymissionId:%lu, itemid:%lu , type:%d..",
				   m_pMaster->Cid(), dymissionId, itemId, type);
		return -1;
	}
	if (MISSION_FINISH_TYPE_KILL_MONS_AREA == type)
	{
		//任务区域刷怪
		//OnAreaFreshMonster(dymissionId);
		return 0;
	}
	//NPC交谈,到达区域，区域使用行为按钮、完成新手引导步骤
	uint32_t eventType = MISSION_COND_TYPE_TO_EVENT(type);
	ExecuteData executeData(eventType, itemId, 1);
	OnEvent(eventType, executeData);
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

int NFMissionPart::HandleSubmitMissionGoods(uint32_t msgId, NFDataPackage& packet)
{
	return 0;
}

int NFMissionPart::HandleOnekeyFinishMission(uint32_t msgId, NFDataPackage& packet)
{
	return 0;
}

int NFMissionPart::HandleOnceFinishMission(uint32_t msgId, NFDataPackage& packet)
{
	return 0;
}

int NFMissionPart::HandleMissionRecvSpecialReward(uint32_t msgId, NFDataPackage& packet)
{
	return 0;
}

int NFMissionPart::SendMissionList(uint32_t msgId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
	proto_ff::CGQueryMissionListReq req;
	CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
	SendMissionInfo();
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

void NFMissionPart::SendMissionInfo()
{
	proto_ff::GCQueryMissionListRsp rsp;
	//已接任务列表
	for (auto missionIte = m_playerTrackMissionMap.begin(); missionIte != m_playerTrackMissionMap.end(); ++missionIte)
	{
		proto_ff::CMissionTrack* missionTrack = rsp.add_acceptedlist();
		if (nullptr != missionTrack)
		{
			missionIte->second.SetMissionTrackProto(*missionTrack);
		}
	}
	//动态任务周期内已经接取的次数
	proto_ff::DyMissionCntAllProto* pAllProto = rsp.mutable_dy_count();
	if (nullptr != pAllProto)
	{
		for (auto iter = m_mapDyMissionTrack.begin(); iter != m_mapDyMissionTrack.end(); ++iter)
		{
			DyMissionTrack* pDyTrack = &iter->second;
			if (nullptr != pDyTrack)
			{
				proto_ff::DyMissionCntProto* proto = pAllProto->add_count();
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
}

int32_t NFMissionPart::AcceptMission(uint64_t missionId, bool notify)
{
	//接取任务
	MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
	if (nullptr == pMissionInfo)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "OnAcceptType Have Not MissionID={} Config, Please Check Mission Config", missionId);
		return proto_ff::RET_MISSION_NOT_EXIST;
	}
	int32_t ret = CanAccept(missionId);
	if (proto_ff::RET_SUCCESS != ret)
	{
		return ret;
	}
	//添加到可接列表中来
	MissionTrack* pMissionTrack = AllocMissionTrack(missionId);
	if (nullptr == pMissionTrack)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptType MissionID={}, Allcol MissionTrackObj is nullptr", missionId);
		return proto_ff::RET_FAIL;
	}
	//填充完成条件信息 多任务条件
	//接取任务获取中间道具
	AddReward(pMissionInfo->missionId, pMissionInfo->kind, pMissionInfo->receAdd);
	//填充任务数据信息
	pMissionTrack->missionId = missionId;
	pMissionTrack->dynamicId = missionId; //主支线任务动态任务ID和配置ID一样
	pMissionTrack->missionType = pMissionInfo->kind;
	pMissionTrack->acceptMissionTime = NFTime::Now().UnixSec();
	pMissionTrack->status = MISSION_E_ACCEPTED;
	if (proto_ff::RET_SUCCESS != OnExtractCond(pMissionInfo, pMissionTrack))
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptType MissionID={}, OnExtractCond failed...", missionId);
		return proto_ff::RET_FAIL;
	}
	MarkDirty();
	OnAccept(missionId, pMissionInfo->kind);
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
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_ACCEPT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), acceptEvent);
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
			if (!pMissionTrack->items[i].completedFlag || pMissionTrack->items[i].IsSpecialCond())
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

	if (isCompletedFlag)
	{
		//完成任务
		OnFinish(missionId, pMissionInfo->kind);
	}
	//日志
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::OnAccept(uint64_t missionId, uint32_t kind)
{
}

int32_t NFMissionPart::CanAccept(uint64_t missionId)
{
	MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
	if (nullptr == pMissionInfo)
	{
		return proto_ff::RET_MISSION_NOT_EXIST;
	}
	return CanAccept(pMissionInfo);
}

int32_t NFMissionPart::CanAccept(MissionInfo* pMissionInfo)
{
	if (nullptr == pMissionInfo)
	{
		return proto_ff::RET_CONFIG_ERROR;
	}
	//是否接取过该任务
	if (HaveAccept(pMissionInfo->missionId))
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
	if (MISSION_TYPE_ID_WEEK_LOOP_INSTANCE == pMissionInfo->kind ||
		MISSION_TYPE_ID_WEEK_LOOP == pMissionInfo->kind ||
		MISSION_TYPE_ID_GUILD_PRESTIGE_TASK == pMissionInfo->kind)
	{
		if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
		{
			return proto_ff::RET_FACTION_NOT_JOIN;
		}
	}
	int32_t ret = CanAccept(pMissionInfo->accept);
	if (proto_ff::RET_SUCCESS != ret)
	{
		return ret;
	}
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::CanAccept(const AcceptInfo& cond)
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
	//功能开发ID
	if (cond.functionId > 0)
	{
		auto pFunctionPart = dynamic_cast<NFFunctionUnlockPart *>(m_pMaster->GetPart(PART_FUNCTIONUNLOCK));
		CHECK_EXPR(pFunctionPart, proto_ff::RET_FAIL, "");
		if (!pFunctionPart->isFunctionUnlock(cond.functionId))
		{
			return proto_ff::RET_MISSION_FUNCTION_UNLOCK_LIMIT;
		}
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

int32_t NFMissionPart::AcceptDyMission(uint64_t missionId, bool notify)
{
	int32_t ret = CanAcceptDy(missionId);
	if (proto_ff::RET_SUCCESS != ret)
	{
		return ret;
	}

	//接取任务
	const DyMissionInfo* pMissionInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
	if (nullptr == pMissionInfo)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDyType nullptr == pMissionInfo  cid:{}, missionid:{}", m_pMaster->Cid(),
				   missionId);
		return proto_ff::RET_MISSION_NOT_EXIST;
	}

	//生成动态任务ID
	uint64_t dymissionId = AllocNewDyMisssionId();
	if (!ValidDyMissionId(dymissionId))
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDyType AllocNewDyMisssionId failed... cid:{},missionid:{},dymissionId:{}",
				   m_pMaster->Cid(), missionId, dymissionId);
		return proto_ff::RET_FAIL;
	}

	MissionTrack* pMissionTrack = AllocMissionTrack(dymissionId);
	if (nullptr == pMissionTrack)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDyType Allcol MissionTrackObj is nullptr cid:{},missionid:{},dymissionId:{}",
				   m_pMaster->Cid(), missionId, dymissionId);
		FreeDyMissionId(dymissionId);
		return proto_ff::RET_FAIL;
	}

	//填充任务数据信息
	pMissionTrack->missionId = missionId;
	pMissionTrack->dynamicId = dymissionId;
	pMissionTrack->acceptMissionTime = NFTime::Now().UnixSec();
	pMissionTrack->missionType = pMissionInfo->kind;
	pMissionTrack->status = MISSION_E_ACCEPTED;
	//填充完成条件信息 多任务条件
	if (proto_ff::RET_SUCCESS != OnExtractDyCond(pMissionInfo, pMissionTrack))
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDyType OnExtractCond failed...cid:{},missionid:{},dymissionId:{}",
				   m_pMaster->Cid(), missionId, dymissionId);
		return proto_ff::RET_FAIL;
	}

	MarkDirty();
	//提取属性奖励
	OnExtractDyAttrReward(pMissionTrack);
	//
	//接取任务,需要放到更新任务进度前面，跟前端处理相关
	OnAcceptDy(dymissionId, pMissionInfo->kind);
	//如果要通知客户端
	if (notify)
	{
		UpdateMissionProgress(dymissionId);
	}
	//接取任务事件
	proto_ff::AcceptTaskEvent acceptEvent;
	acceptEvent.set_cid(m_pMaster->Cid());
	acceptEvent.set_taskid(missionId);
	acceptEvent.set_tasktype(pMissionInfo->kind);
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_ACCEPT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), acceptEvent);
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
		OnAddMissionDrop(pMissionTrack, 1);
		//注册事件
		for (uint32_t i = 0; i < pMissionTrack->items.size(); i++)
		{
			if (!pMissionTrack->items[i].completedFlag || pMissionTrack->items[i].IsSpecialCond())
			{
				int32_t relEvent = MISSION_COND_TYPE_TO_EVENT(pMissionTrack->items[i].type);
				RegisterEvent(relEvent, pMissionTrack->dynamicId, 1);
			}
		}
	}
	//如果接取就完成，需要再次通知客户端
	if (isCompletedFlag && notify)
	{
		UpdateMissionProgress(dymissionId);
	}
	//
	if (isCompletedFlag)
	{
		//完成任务
		OnFinishDy(missionId, dymissionId, pMissionInfo->kind);
	}
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::AcceptDyMission(uint64_t missionId, proto_ff::CMissionTrack& track, bool notify)
{
	CharIDType cid = m_pMaster->Cid();
	int32_t ret = CanAcceptDy(missionId);
	if (proto_ff::RET_SUCCESS != ret)
	{
		return ret;
	}
	//接取任务
	const DyMissionInfo* pMissionInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
	if (nullptr == pMissionInfo)
	{
		NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDy nullptr == pMissionInfo  cid:%lu,missionid:%lu", cid, missionId);
		return proto_ff::RET_MISSION_NOT_EXIST;
	}
	//生成动态任务ID
	uint64_t dymissionId = AllocNewDyMisssionId();
	if (!ValidDyMissionId(dymissionId))
	{
		NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDy AllocNewDyMisssionId failed... cid:%lu,missionid:%lu,dymissionId:%lu", cid, missionId, dymissionId);
		return proto_ff::RET_FAIL;
	}
	//
	MissionTrack* pMissionTrack = AllocMissionTrack(dymissionId);
	if (nullptr == pMissionTrack)
	{
		FreeDyMissionId(dymissionId);
		NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnAcceptDy Allcol MissionTrackObj is nullptr cid:%lu,missionid:%lu,dymissionId:%lu", cid, missionId, dymissionId);
		return proto_ff::RET_FAIL;
	}
	pMissionTrack->CopyFromMissionProto(track);
	track.set_dynamicid(dymissionId);
	//填充任务数据信息
	pMissionTrack->missionId = missionId;
	pMissionTrack->dynamicId = dymissionId;
	pMissionTrack->acceptMissionTime = NFTime::Now().UnixSec();
	pMissionTrack->status = MISSION_E_ACCEPTED;
	//提取属性奖励
	OnExtractDyAttrReward(pMissionTrack);
	//
	SetNeedSave(true);
	//
	//接取任务,需要放到更新任务进度前面，跟前端处理相关
	AcceptDyMission(dymissionId, pMissionInfo->kind);
	//如果要通知客户端
	if (notify)
	{
		UpdateMissionProgress(dymissionId);
	}
	//接取任务事件
	proto_ff::AcceptTaskEvent acceptEvent;
	acceptEvent.set_cid(cid);
	acceptEvent.set_taskid(missionId);
	acceptEvent.set_tasktype(pMissionInfo->kind);
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_ACCEPT_TASK, CREATURE_PLAYER, cid, acceptEvent);
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
		OnAddMissionDrop(pMissionTrack, 1);
		//注册事件
		for (uint32_t i = 0; i < pMissionTrack->items.size(); i++)
		{
			if (!pMissionTrack->items[i].completedFlag || pMissionTrack->items[i].IsSpecialCond())
			{
				int32_t relEvent = MISSION_COND_TYPE_TO_EVENT(pMissionTrack->items[i].type);
				RegisterEvent(relEvent, pMissionTrack->dynamicId, 1);
			}
		}
	}
	//如果接取就完成，需要再次通知客户端
	if (isCompletedFlag && notify)
	{
		UpdateMissionProgress(dymissionId);
	}
	//
	if (isCompletedFlag)
	{
		//完成任务
		OnFinishDy(missionId, dymissionId, pMissionInfo->kind);
	}
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::OnAcceptDy(uint64_t dymissionId, int32_t missionType)
{
	NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] MissionPart::OnAcceptDyType...cid:{}, missionType:{} ", m_pMaster->Cid(), missionType);
	OnAddAcceptDyCount(missionType, 1);
}

int32_t NFMissionPart::CanAcceptDy(uint64_t dyCfgId)
{
	const DyMissionInfo* pDyMissionInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(dyCfgId);
	return CanAcceptDy(pDyMissionInfo);
}

int32_t NFMissionPart::CanAcceptDy(const DyMissionInfo* pDyMissionInfo)
{
	if (nullptr == pDyMissionInfo)
	{
		return proto_ff::RET_FAIL;
	}

	if (MISSION_TYPE_ID_WEEK_LOOP_INSTANCE == pDyMissionInfo->kind ||
		MISSION_TYPE_ID_WEEK_LOOP == pDyMissionInfo->kind ||
		MISSION_TYPE_ID_GUILD_PRESTIGE_TASK == pDyMissionInfo->kind)
	{
		if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
		{
			return proto_ff::RET_FACTION_NOT_JOIN;
		}
	}

	uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
	if (MissionNumByType(pDyMissionInfo->kind) > 0)
	{
		return proto_ff::RET_MISSION_PERIOD_ONCE_EXIST_NUM_LIMIT;
	}

	if (level < pDyMissionInfo->minLev || level > pDyMissionInfo->maxLev)
	{
		return proto_ff::RET_MISSION_LEVEL_ERROR;
	}

	int32_t maxCount = DyMaxCount(pDyMissionInfo->kind, level);
	if (maxCount != MISSION_INFINITE_COUNT)
	{
		if ((int32_t)GetDyMissionAceeptCnt(pDyMissionInfo->kind) >= maxCount)
		{
			return proto_ff::RET_MISSION_PERIOD_FINISH_NUM_LIMIT;
		}
	}
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::OnAddAcceptDyCount(int32_t missionType, uint32_t count)
{
	//更新动态任务计数
	DyMissionTrack* pDyTrack = GetDyMissionTrack(missionType);
	if (nullptr == pDyTrack)
	{
		if (m_mapDyMissionTrack.size() >= m_mapDyMissionTrack.max_size())
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapDyMissionTrack Space Not Enough");
			return;
		}
		DyMissionTrack& track = m_mapDyMissionTrack[missionType];
		track.kind = missionType;
		track.acceptNum = 0;
		track.lastFresh = NFTime::Now().UnixSec();
		pDyTrack = GetDyMissionTrack(missionType);
		if (nullptr == pDyTrack)
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapDyMissionTrack can't find mission type:{}", missionType);
			return;
		}
	}
	pDyTrack->acceptNum += count;
	SET_UINT32 setMissionType;
	setMissionType.insert(missionType);
	NotifyDyAcceptCount(setMissionType);
	MarkDirty();
}

int32_t NFMissionPart::AcceptDyMissionByType(int32_t missionType, bool notify)
{
	int32_t ret = CanAcceptDyMissionByType(missionType);
	if (proto_ff::RET_SUCCESS == ret)
	{
		uint64_t missionId = DyRandMissionId(missionType);
		const DyMissionInfo* pDyMissionCfgInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
		if (nullptr == pDyMissionCfgInfo)
		{
			ret = proto_ff::RET_MISSION_NOT_EXIST;
			NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
						  "AcceptDyMissionByType...can not find mission config....cid:{} ,missionType:{}, missionid:{}, notify:{}", m_pMaster->Cid(),
						  missionType, missionId, (int32_t) notify);
		}
		else
		{
			ret = AcceptDyMission(missionId, notify);
			if (proto_ff::RET_SUCCESS != ret)
			{
				NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
							  "AcceptDyMissionByType...OnAcceptDy failed....cid:{} ,missionType:{}, missionid:{}, notify:{}, ret:{} ",
							  m_pMaster->Cid(),
							  missionType, missionId, (int32_t) notify, ret);
			}
		}
	}
	return ret;
}

int32_t NFMissionPart::AcceptDyMissionByType(int32_t missionType, uint64_t missionId, proto_ff::CMissionTrack& missionProto, bool notify)
{
	int32_t ret = CanAcceptDyMissionByType(missionType);
	if (proto_ff::RET_SUCCESS == ret)
	{
		const DyMissionInfo* pDyMissionCfgInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
		if (nullptr == pDyMissionCfgInfo)
		{
			ret = proto_ff::RET_MISSION_NOT_EXIST;
			NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AcceptDyMissionByType...can not find mission config....cid:%lu,missionType:%d, missionid:%Lu, notify:%d",
						  m_pMaster->Cid(), missionType, missionId, (int32_t) notify);
		}
		else
		{
			ret = AcceptDyMission(missionId, missionProto, notify);
			if (proto_ff::RET_SUCCESS != ret)
			{
				NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AcceptDyMissionByType...OnAcceptDy failed....cid:%lu,missionType:%d, missionid:%Lu, notify:%d,ret:%d ",
							  m_pMaster->Cid(), missionType, missionId, (int32_t) notify, ret);
			}
		}
	}
	return ret;
}

int32_t NFMissionPart::AcceptMissionByType(int32_t missionType, bool notify)
{
	if (MISSION_TYPE_ID_GUILD == missionType
		|| MISSION_TYPE_ID_WEEK_LOOP_INSTANCE == missionType
		|| MISSION_TYPE_ID_WEEK_LOOP == missionType
		|| MISSION_TYPE_ID_GUILD_PRESTIGE_TASK == missionType)
	{
		if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
		{
			return proto_ff::RET_FACTION_NOT_JOIN;
		}
	}
	int32_t ret = proto_ff::RET_SUCCESS;
	auto pSetUint64 = TaskDescEx::Instance()->GetFirstMissionByType(missionType);
	if (pSetUint64 == NULL)
	{
		return proto_ff::RET_MISSION_NOT_EXIST;
	}
	for (auto iter = pSetUint64->begin(); iter != pSetUint64->end(); iter++)
	{
		uint64_t missionId = *iter;
		const MissionInfo* pMissionCfgInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
		if (nullptr == pMissionCfgInfo)
		{
			ret = proto_ff::RET_MISSION_NOT_EXIST;
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AcceptMissionByType...can not find mission config....cid:%lu,missionType:%d, missionid:%Lu, notify:%d",
					   m_pMaster->Cid(), missionType, missionId, (int32_t) notify);
		}
		else
		{
			ret = AcceptMission(missionId, notify);
			if (proto_ff::RET_SUCCESS != ret)
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AcceptMissionByType...OnAcceptDy failed....cid:%lu,missionType:%d, missionid:%Lu, notify:%d,ret:%d ",
						   m_pMaster->Cid(), missionType, missionId, (int32_t) notify, ret);
			}
		}
	}
	return ret;
}

int32_t NFMissionPart::CanAcceptDyMissionByType(int32_t missionType)
{
	if (MISSION_TYPE_ID_GUILD == missionType
		|| MISSION_TYPE_ID_WEEK_LOOP_INSTANCE == missionType
		|| MISSION_TYPE_ID_WEEK_LOOP == missionType
		|| MISSION_TYPE_ID_GUILD_PRESTIGE_TASK == missionType)
	{
		if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
		{
			return proto_ff::RET_FACTION_NOT_JOIN;
		}
	}
	if (missionType == MISSION_TYPE_ID_HUNT_TREASURE)
	{
		if (!HaveSubmitedByType(MISSION_TYPE_ID_HUNT_TREASURE_INSTANCE))
		{
			return proto_ff::RET_MISSION_CAN_NOT_ACCEPT;
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
	MAP_UINT64_UINT64 mapDelMission;
	mapDelMission.clear();
	MAP_UINT64_UINT64 mapDelMissionEx;
	mapDelMissionEx.clear();
	int32_t delCount = 0;
	PlayerTrackMissionMap::iterator iter = m_playerTrackMissionMap.begin();
	for (; iter != m_playerTrackMissionMap.end(); ++iter)
	{
		uint64_t missionId = iter->second.missionId;
		uint64_t dymissionId = iter->second.dynamicId;
		const DyMissionInfo* pDyMissionCfgInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
		if (nullptr != pDyMissionCfgInfo)
		{
			if ((uint32_t)missionType == pDyMissionCfgInfo->kind)
			{
				mapDelMission[dymissionId] = missionId;
			}
		}
		else
		{
			MissionInfo* pMissionCfgInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
			if (nullptr != pMissionCfgInfo)
			{
				if ((uint32_t)missionType == pMissionCfgInfo->kind)
				{
					mapDelMissionEx[dymissionId] = missionId;
					if (MISSION_TYPE_ID_TRUNK == pMissionCfgInfo->kind)
					{
						NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "ClearMissionByType..remove trunk mission..cid:{}, missionid:{} ",
								   m_pMaster->Cid(), missionId);
					}
				}
			}
		}
	}
	//
	for (auto iterDel = mapDelMission.begin(); iterDel != mapDelMission.end(); ++iterDel)
	{
		uint64_t dymissionId = iterDel->first;
		uint64_t missionId = iterDel->second;
		int32_t ret = RemoveDyMission(dymissionId, notify);
		if (proto_ff::RET_SUCCESS != ret)
		{
			//这里必须打印日志，如果移除失败，很可能导致下面刷新阵营任务分配的动态ID有重复的
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
					   "MissionPart::ClearMissionByType...RemoveDyMission failed....cid:%lu,missionType:{}, missionId:{}, dymissionid:{},ret:{} ",
					   m_pMaster->Cid(),
					   missionType, missionId, dymissionId, ret);
		}
		else
		{
			delCount += 1;
		}
	}
	//
	for (auto iterDelEx = mapDelMissionEx.begin(); iterDelEx != mapDelMissionEx.end(); ++iterDelEx)
	{
		uint64_t dymissionId = iterDelEx->first;
		uint64_t missionId = iterDelEx->second;
		MissionInfo* pMissionCfgInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
		if (nullptr != pMissionCfgInfo)
		{
			int32_t ret = RemoveMission(pMissionCfgInfo);
			if (proto_ff::RET_SUCCESS != ret)
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
						   "MissionPart::ClearMissionByType...RemoveMission failed....cid:{}, missionId:{}, dymissionid:{},ret:{} ",
						   m_pMaster->Cid(),
						   missionId, dymissionId, ret);
			}
			else
			{
				delCount += 1;
			}
		}
		else
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
					   "MissionPart::ClearMissionByType...pMissionCfgInfo is nullptr....cid:{}, missionId:{}, dymissionid:{} ", m_pMaster->Cid(),
					   missionId, dymissionId);
		}
	}
	return delCount;
}

int32_t NFMissionPart::DyMaxCount(int32_t missionType, int32_t level)
{
	int32_t count = 0;
	auto pTaskDynamicCfg = TaskdynamicTaskdynamicDesc::Instance()->GetResDescPtr();
	for (auto iter = pTaskDynamicCfg->begin(); iter != pTaskDynamicCfg->end(); ++iter)
	{
		auto& info = iter->second;
		if (missionType == info.m_taskType && level >= info.m_minlv && level <= info.m_maxlv)
		{
			count = info.m_receCount;
			break;
		}
	}
	return count;
}

uint32_t NFMissionPart::GetDyMissionAceeptCnt(int32_t missionType)
{
	DyMissionTrack* pDyTrack = GetDyMissionTrack(missionType);
	if (nullptr != pDyTrack)
	{
		return pDyTrack->acceptNum;
	}
	return 0;
}

void NFMissionPart::OnFinishDy(uint64_t missionId, uint64_t dymissionId, uint32_t dymissionType)
{
	proto_ff::FinishTaskEvent taskEvent;
	taskEvent.set_taskid(missionId);
	taskEvent.set_tasktype(dymissionType);
	taskEvent.set_cid(m_pMaster->Cid());
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_FINISH_NOT_SUMIT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), taskEvent);

	if (dymissionType == MISSION_TYPE_ID_BOUNTY)
	{
		DyMissionTrack* pDyTrack = GetDyMissionTrack(MISSION_TYPE_ID_BOUNTY);
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

void NFMissionPart::OnFinish(uint64_t missionId, uint32_t kind)
{
	auto pMissionTrack = GetMissionTrack(missionId);
	if (pMissionTrack)
	{
		auto& items = pMissionTrack->items;
		for (int i = 0; i < (int)items.size(); i++)
		{
			ItemInfo& cond = items[i];
			OnFinishCondProcess(cond);
		}
	}
	//完成任务触发事件
	proto_ff::FinishTaskEvent taskEvent;
	taskEvent.set_taskid(missionId);
	taskEvent.set_tasktype(kind);
	taskEvent.set_cid(m_pMaster->Cid());
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_FINISH_NOT_SUMIT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), taskEvent);
}

void NFMissionPart::OnFinishCondProcess(ItemInfo& cond)
{
	if (cond.type == MISSION_FINISH_TYPE_ACTIVE_DEITY)
	{
		NFDeityPart* pDeityPart = dynamic_cast<NFDeityPart *>(m_pMaster->GetPart(PART_DEITY));
		if (pDeityPart)
		{
			pDeityPart->ActiveFantasyAndEnterBattle(cond.parma1, cond.parma2);
		}
	}
}

DyMissionTrack* NFMissionPart::GetDyMissionTrack(int32_t missionType)
{
	auto iter = m_mapDyMissionTrack.find(missionType);
	if (iter != m_mapDyMissionTrack.end())
	{
		return &iter->second;
	}
	return nullptr;
}

int32_t NFMissionPart::OnAddDyMissionReward(int32_t missionType, uint64_t missionId, SMissionReward& missionReward)
{
	int32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
	const TASK_REWARD* pReward = TaskDescEx::Instance()->GetDyMissionReward(missionType, level);
	if (nullptr == pReward)
	{
		return proto_ff::RET_FAIL;
	}
	NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
	if (nullptr == pPackage)
	{
		return proto_ff::RET_FAIL;
	}
	SCommonSource sourceParam;
	sourceParam.src = S_MISSION;
	sourceParam.param1 = missionId;

	uint32_t profression = m_pMaster->GetAttr(proto_ff::A_PROF);
	const TASK_REWARD& reward = *pReward;
	//节日活动 奖励倍率
	int32_t nMult = 0;
	if (MISSION_TYPE_ID_HUNT_TREASURE == missionType || MISSION_TYPE_ID_HUNT_TREASURE_USE_ITEM18 == missionType || MISSION_TYPE_ID_HUNT_TREASURE_USE_ITEM19 == missionType)
	{
		NFFestPart* pfest = dynamic_cast<NFFestPart *>(m_pMaster->GetPart(PART_FEST));
		if (nullptr != pfest)
			nMult = pfest->GetTaskMult();
	}

	LIST_ITEM lstItemA;
	lstItemA.clear();
	//
	uint32_t isize = (uint32_t)reward.size();
	for (uint32_t i = 0; i < isize; ++i)
	{
		uint32_t rewardType = reward[i].type;
		if (reward[i].profession != 0 && profression != reward[i].profession)
		{
			continue;
		}

		int64_t nNum = reward[i].value;
		if (nMult > 1)
			nNum *= nMult;

		if (MISSION_AWARD_GOODS == rewardType || MISSION_AWARD_EQUIP == rewardType)
		{
			if (reward[i].id > 0)
			{
				pPackage->AddItem(reward[i].id, nNum, sourceParam, reward[i].bind);
				//
				SItem item;
				item.nItemID = reward[i].id;
				item.nNum = nNum;
				item.byBind = reward[i].bind;
				lstItemA.push_back(item);
			}
			else if (reward[i].boxId > 0)
			{
				/*VEC_UINT64 vecBox;
				for(int64_t x = 0; x < nNum; x++)
				{
					vecBox.push_back(reward[i].boxId);
				}

				stBoxInfo genBoxInfo;
				g_GetDropMgr()->AddBox(pPlayer, vecBox, sourceParam, &genBoxInfo);

				for(int x = 0; x < (int)genBoxInfo.vecItemProto.size(); x++)
				{
					auto& genBoxItem = genBoxInfo.vecItemProto[i];
					lstItemA.push_back(SItem(genBoxItem.item_id(), genBoxItem.item_num(), genBoxItem.bind()));
				}*/
			}
		}
		else if (MISSION_AWARD_SKILL == rewardType)
		{
			NFSkillPart* pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
			if (nullptr != pSkillPart)
			{
				if (!pSkillPart->AddSkill(reward[i].id, 1, sourceParam, true))
				{
					NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddSkill failed...cid:%lu,missionType:%d, level:%d,missionId:%lu ",
								  m_pMaster->Cid(), missionType, level, missionId);
				}
				else
				{
					missionReward.setSkill.insert(reward[i].id);
				}
			}
		}
		else if (MISSION_AWARD_ATTR == rewardType) //属性奖励
		{
			m_pMaster->AddAttr(reward[i].id, reward[i].value, &sourceParam, true);
			missionReward.mapAttr[reward[i].id] += reward[i].value;
		}
		else if (MISSION_AWARD_USE_CONTRI == rewardType)
		{
			m_pMaster->AddAttr(proto_ff::A_CONTRI, nNum, &sourceParam, true);
		}
		else if (MISSION_AWARD_UNION_EXP == rewardType)
		{
			m_pMaster->AddAttr(proto_ff::A_FACTION_BUILD, nNum, &sourceParam, true);
		}
	}
	//
	NFItemMgr::MergeItem(lstItemA, missionReward.lstItem);
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::NotifyDyAcceptCount(SET_UINT32& setMissionType)
{
	proto_ff::GCUpdateDyAcceptCount notify;
	proto_ff::DyMissionCntAllProto* proto = notify.mutable_dy_count();
	if (nullptr != proto)
	{
		for (auto iter = setMissionType.begin(); iter != setMissionType.end(); ++iter)
		{
			uint32_t missionType = (*iter);
			uint32_t acceptNum = 0;
			DyMissionTrack* pDyTrack = GetDyMissionTrack(missionType);
			if (nullptr != pDyTrack)
			{
				acceptNum = pDyTrack->acceptNum;
			}
			proto_ff::DyMissionCntProto* protoA = proto->add_count();
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

bool NFMissionPart::ValidDyMissionId(uint64_t dyMissionId)
{
	if (dyMissionId >= 1 && dyMissionId <= MISSION_MAX_DYNAMIC_ALLOC)
	{
		return true;
	}
	return false;
}

uint64_t NFMissionPart::AllocNewDyMisssionId()
{
	for (uint32_t i = 1; i <= MISSION_MAX_DYNAMIC_ALLOC; ++i)
	{
		if (!m_aryDyIdAlloc[i])
		{
			m_aryDyIdAlloc[i] = true;
			return i;
		}
	}
	return 0;
}

void NFMissionPart::FreeDyMissionId(uint64_t dyMissionId)
{
	if (dyMissionId >= 1 && dyMissionId <= MISSION_MAX_DYNAMIC_ALLOC)
	{
		m_aryDyIdAlloc[dyMissionId] = false;
	}
}

uint64_t NFMissionPart::DyRandMissionId(int32_t missionType)
{
	auto* pMissionLst = TaskDescEx::Instance()->GetDyMissionLstByType(missionType);
	if (nullptr == pMissionLst)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "DyRandMissionId...nullptr == pMissionLst...missionType:{} ,cid:{} ", missionType,
				   m_pMaster->Cid());
		return proto_ff::RET_FAIL;
	}
	uint32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
	//获取满足条件的任务ID
	std::vector<std::pair<uint64_t, uint32_t>> vecMission;
	vecMission.clear();
	int32_t allVle = 0;
	for (auto iterSet = pMissionLst->begin(); iterSet != pMissionLst->end(); ++iterSet)
	{
		const uint64_t missionId = (*iterSet);
		const DyMissionInfo* pDyMissionCfgInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
		if (nullptr == pDyMissionCfgInfo || level < pDyMissionCfgInfo->minLev || level > pDyMissionCfgInfo->maxLev)
		{
			continue;
		}
		vecMission.push_back(std::make_pair(missionId, pDyMissionCfgInfo->weights));
		allVle += pDyMissionCfgInfo->weights;
	}
	uint32_t random_v = NFRandInt(0, allVle);
	uint32_t curV = 0;
	for (uint32_t k = 0; k < (uint32_t)vecMission.size(); k++)
	{
		curV += vecMission[k].second;
		if (random_v <= curV)
		{
			return vecMission[k].first;
		}
	}
	//
	return proto_ff::RET_FAIL;
}

bool NFMissionPart::HaveRecentSubmit(int32_t missionType)
{
	return m_mapRecentSubmit.find(missionType) != m_mapRecentSubmit.end();
}

int32_t NFMissionPart::MissionNumByType(int32_t missionType)
{
	int32_t num = 0;
	auto iter = m_playerTrackMissionMap.begin();
	for (; iter != m_playerTrackMissionMap.end(); ++iter)
	{
		if ((uint32_t)missionType == iter->second.missionType)
		{
			num++;
		}
	}
	return num;
}

bool NFMissionPart::HaveAccept(const uint64_t& missionId)
{
	return m_playerTrackMissionMap.find(missionId) != m_playerTrackMissionMap.end();
}

bool NFMissionPart::HaveSubmited(uint64_t missionId)
{
	return m_setAlreadySubmit.find(missionId) != m_setAlreadySubmit.end();
}

bool NFMissionPart::HaveSubmitedByType(int32_t missionType)
{
	auto pSetUint64 = TaskDescEx::Instance()->GetFirstMissionByType(missionType);
	if (pSetUint64 == NULL)
	{
		return false;
	}
	for (auto iter = pSetUint64->begin(); iter != pSetUint64->end(); iter++)
	{
		uint64_t missionId = *iter;
		if (HaveSubmited(missionId))
		{
			return true;
		}
	}
	return false;
}

bool NFMissionPart::ClearSubmitedByType(int32_t missionType)
{
	auto pSetUint64 = TaskDescEx::Instance()->GetFirstMissionByType(missionType);
	if (pSetUint64 == NULL)
	{
		return false;
	}
	std::vector<uint64_t> del;
	for (auto iter = pSetUint64->begin(); iter != pSetUint64->end(); iter++)
	{
		uint64_t missionId = *iter;
		if (HaveSubmited(missionId))
		{
			del.push_back(missionId);
		}
	}
	for (auto iter = del.begin(); iter != del.end(); iter++)
	{
		m_setAlreadySubmit.erase(*iter);
	}
	return true;
}

int32_t NFMissionPart::OnExtractCond(MissionInfo* pMissionInfo, MissionTrack* pMissionTrack)
{
	CHECK_EXPR(pMissionInfo, proto_ff::RET_FAIL, "pMissionInfo == Null");
	CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == Null");
	const InterExecute& execute = pMissionInfo->execute;
	for (auto iter = execute.items.begin(); iter != execute.items.end(); ++iter)
	{
		const InterItemPair& inter = (*iter);
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

void NFMissionPart::OnPreUpdateProgress(ItemInfo& cond)
{
	if (cond.completedFlag)
	{
		return;
	}
	int64_t count = 0;
	int32_t event = MISSION_COND_TYPE_TO_EVENT(cond.type);
	if (M_EVENT_COLL_COLLECT_ITEM == event) //收集物品
	{
		if (cond.type == MISSION_FINISH_TYPE_EQUIP_KILL_MONS)
		{
			cond.currentValue = cond.finalValue;
			cond.completedFlag = true;
			return;
		}
		//收集物品		格式：3 = 物品id = 所需物品数目 = 怪物id = 掉落包id = 区域id
		NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
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
		//装备槽位强化等级	格式 11301=0=装备槽位数量=等级=ui编号=0
		NFEquipPart* pPackage = dynamic_cast<NFEquipPart *>(m_pMaster->GetPart(PART_EQUIP));
		if (nullptr != pPackage)
		{
			count = pPackage->GetStrongLvNum(cond.parma1);
		}
	}
	else if (M_EVENT_INBUFF == event) //处于某种BUFF
	{
	}
	else if (M_EVENT_LEVEL == event) //等级达到多少级
	{
		//升到指定等级	格式: 14=所需等级数值=目标值=0=0=0
		//升级到xx级 ,前端显示 0/1,
		if ((uint64_t)m_pMaster->GetAttr(proto_ff::A_LEVEL) >= cond.itemId)
		{
			count = cond.itemId;
		}
	}
	else if (M_EVENT_JOIN_GUILD == event)
	{
		//加入工会				格式 10101=0=1=linkid=0=0
		if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) > 0)
		{
			count = 1;
		}
	}
	else if (M_EVENT_TREASURE_LEV == event)
	{
		NFFacadePart* pFacadePart = dynamic_cast<NFFacadePart *>(m_pMaster->GetPart(PART_FACADE));
		if (nullptr != pFacadePart)
		{
			FacadeInfo* pFacadeInfo = pFacadePart->GetFacadeInfo(proto_ff::FACADE_WING_TYPE);
			if (pFacadeInfo)
			{
				uint64_t lev = (uint64_t)pFacadeInfo->m_nFacadeLev;
				if (lev >= cond.itemId)
				{
					count = cond.finalValue;
				}
			}
		}
	}
	else if (M_EVENT_PARTNER_RANKLEV == event)
	{
		NFFacadePart* pFacadePart = dynamic_cast<NFFacadePart *>(m_pMaster->GetPart(PART_FACADE));
		if (nullptr != pFacadePart)
		{
			FacadeInfo* pFacadeInfo = pFacadePart->GetFacadeInfo(proto_ff::FACADE_PARTNER_TYPE);
			if (pFacadeInfo)
			{
				uint64_t lev = (uint64_t)pFacadeInfo->m_nFacadeLev;
				if (lev >= cond.itemId)
				{
					count = cond.finalValue;
				}
			}
		}
	}
	else if (M_EVENT_WING_LEV == event)
	{
		NFFacadePart* pFacadePart = dynamic_cast<NFFacadePart *>(m_pMaster->GetPart(PART_FACADE));
		if (nullptr != pFacadePart)
		{
			FacadeInfo* pFacadeInfo = pFacadePart->GetFacadeInfo(proto_ff::FACADE_WING_TYPE);
			if (pFacadeInfo)
			{
				uint64_t lev = (uint64_t)pFacadeInfo->m_nFacadeLev;
				if (lev >= cond.itemId)
				{
					count = cond.finalValue;
				}
			}
		}
	}
	else if (M_EVENT_SKILL_LEVEL == event)
	{
		NFSkillPart* pSkilPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
		if (nullptr != pSkilPart)
		{
			auto pSkillInfo = pSkilPart->GetSkillInfo(cond.itemId);
			if (pSkillInfo)
			{
				count = pSkillInfo->level;
				if (count >= cond.finalValue)
				{
					count = cond.finalValue;
				}
			}
		}
	}
	else if (M_EVENT_APTITUDE == event)
	{
	}
	else if (M_EVENT_FETCH_OPERATE == event)
	{
	}
	else if (M_EVENT_USE_GOODS == event)
	{
		if (MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type || MISSION_FINISH_TYPE_SUBMIT_SPEC2_EQUIP == cond.type
			|| MISSION_FINISH_TYPE_SUBMIT_SPEC3_EQUIP == cond.type)
		{
			ExecuteData data(event, 0, 0, 0, (int32_t)S_MissionSubmitItem);
			bool notify = false;
			OnUpdateCondProcess(data, cond, notify);
			return;
		}
	}
	else if (M_EVENT_ACTION_BUTTON == event)
	{
		if (MISSION_FINISH_TYPE_FINISH_JIESUO == cond.type)
		{
			ExecuteData data(event, cond.itemId, count);
			bool notify = false;
			OnUpdateCondProcess(data, cond, notify);
			return;
		}
		else if (MISSION_FINISH_TYPE_FINISH_TIANJIPU == cond.type)
		{
			NFGodRelicsPart* pGodRelics = dynamic_cast<NFGodRelicsPart *>(m_pMaster->GetPart(PART_GODRELIS));
			if (pGodRelics)
			{
				if (pGodRelics->IsFinishGroup(cond.itemId))
				{
					ExecuteData data(event, cond.itemId, 1);
					bool notify = false;
					OnUpdateCondProcess(data, cond, notify);
				}
			}
			return;
		}
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

void NFMissionPart::OnUpdateCondProcess(const ExecuteData& data, ItemInfo& cond, bool& notify)
{
	int32_t relevent = MISSION_COND_TYPE_TO_EVENT(cond.type);
	if ((uint32_t)relevent != data.type)
	{
		return;
	}
	if (cond.completedFlag)
	{
		if (cond.type == MISSION_FINISH_TYPE_EQUIP_KILL_MONS && (EMonsCreateType)data.source == EMonsCreateType::MapBoss && data.id >= cond.parma3)
		{
			NFEquipPart* pEquipPart = dynamic_cast<NFEquipPart *>(m_pMaster->GetPart(PART_EQUIP));
			NFPackagePart* pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
			if (pEquipPart && pPackagePart)
			{
				int count = 0;
				for (int e_pos = proto_ff::EEquipPos_m_weapon; e_pos <= proto_ff::EEquipPos_shoe; e_pos++)
				{
					auto& equipVec = pEquipPart->GetEquip();
					auto pEquip = equipVec.GetEquip(e_pos);
					if (pEquip)
					{
						auto pEquipCfg = pEquip->GetEquipCfg();
						if (pEquip && pEquipCfg->m_star >= (int)cond.parma2
							&& pEquipCfg->m_quality >= (int)cond.parma1 && pEquipCfg->m_wearQuality >= (int)cond.itemId)
						{
							continue;
						}
						int64_t equipId = EquipDescEx::Instance()->GetEquipID(e_pos, m_pMaster->GetAttr(proto_ff::A_PROF), cond.parma2, cond.parma1, cond.itemId);
						if (equipId > 0)
						{
							int64_t nUnBindNum = 0;
							int64_t nBindNum = 0;
							if (pPackagePart->GetItemNum(equipId, nUnBindNum, nBindNum) <= 0)
							{
								SCommonSource source;
								source.src = S_MISSION;
								pPackagePart->AddItem(equipId, 1, source, true);
								count++;
								if (count >= cond.finalValue)
								{
									return;
								}
							}
						}
					}
				}
				return;
			}
		}
		return;
	}
	if (MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type || MISSION_FINISH_TYPE_SUBMIT_SPEC2_EQUIP == cond.type
		|| MISSION_FINISH_TYPE_SUBMIT_SPEC3_EQUIP == cond.type) //提交指定品阶和品质的装备特殊处理下
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
	else if (M_EVENT_KILL_BOSS == relevent)
	{
	}
	else if (cond.itemId != data.id)
	{
		return;
	} //
	if (M_EVENT_LEVEL == relevent
		|| M_EVENT_TREASURE_LEV == relevent    //宝具等级
		|| M_EVENT_PARTNER_RANKLEV == relevent //契灵等阶
		|| M_EVENT_WING_LEV == relevent        //翅膀等级
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
			NFEquipPart* pPackage = dynamic_cast<NFEquipPart *>(m_pMaster->GetPart(PART_EQUIP));
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
		}
	}
	else if (M_EVENT_COLL_COLLECT_ITEM == relevent && data.source == S_Package_Storage)
	{
		int32_t currentValue = data.count;
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
		return;
	}
	else
	{
		//提交物品的条件，物品扣除来源必须是从任务这边扣除的
		if (MISSION_FINISH_TYPE_SUBMIT_ITEM == cond.type || MISSION_FINISH_TYPE_SUBMIT_EQUIP == cond.type ||
			MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type || MISSION_FINISH_TYPE_SUBMIT_SPEC2_EQUIP == cond.type
			|| MISSION_FINISH_TYPE_SUBMIT_SPEC3_EQUIP == cond.type)
		{
			if (S_MissionSubmitItem != data.source)
			{
				return;
			}
			if (MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == cond.type) //提交指定品质的装备时，需要验证
			{
				if (data.id > 0)
				{
					auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(data.id);
					if (nullptr != pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId)
					{
						//品阶大于等于条件配置值，品质大于等于条件配置值
					}
					else
					{
						return;
					}
				}
				NFEquipPart* pEquipPart = dynamic_cast<NFEquipPart *>(m_pMaster->GetPart(PART_EQUIP));
				if (pEquipPart)
				{
					int condNum = 0;
					for (int e_pos = proto_ff::EEquipPos_m_weapon; e_pos <= proto_ff::EEquipPos_shoe; e_pos++)
					{
						auto& equipVec = pEquipPart->GetEquip();
						auto pEquip = equipVec.GetEquip(e_pos);
						if (pEquip)
						{
							auto pEquipCfg = pEquip->GetEquipCfg();
							if (pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId)
							{
								condNum++;
							}
						}
					}
					int32_t currentValue = condNum;
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
					return;
				}
			}
			else if (MISSION_FINISH_TYPE_SUBMIT_SPEC2_EQUIP == cond.type)
			{
				if (cond.completedFlag)
					return;
				if (data.id > 0)
				{
					auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(data.id);
					if (nullptr != pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId &&
						pEquipCfg->m_star >= (int32_t)cond.parma2)
					{
						//品阶大于等于条件配置值，品质大于等于条件配置值
						if (cond.parma3 != 0 && pEquipCfg->m_position != (int32_t)cond.parma3)
						{
							return;
						}
					}
					else
					{
						return;
					}
				}
				NFEquipPart* pEquipPart = dynamic_cast<NFEquipPart *>(m_pMaster->GetPart(PART_EQUIP));
				if (pEquipPart)
				{
					int condNum = 0;
					auto& equipVec = pEquipPart->GetEquip();
					if (cond.parma3 == 0)
					{
						for (int e_pos = proto_ff::EEquipPos_m_weapon; e_pos <= proto_ff::EEquipPos_shoe; e_pos++)
						{
							auto pEquip = equipVec.GetEquip(e_pos);
							if (pEquip)
							{
								auto pEquipCfg = pEquip->GetEquipCfg();
								if (pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId &&
									pEquipCfg->m_star >= (int32_t)cond.parma2)
								{
									condNum++;
								}
							}
						}
					}
					else
					{
						auto pEquip = equipVec.GetEquip(cond.parma3);
						if (pEquip)
						{
							auto pEquipCfg = pEquip->GetEquipCfg();
							if (pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId &&
								pEquipCfg->m_star >= (int32_t)cond.parma2)
							{
								condNum++;
							}
						}
					}
					int32_t currentValue = condNum;
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
					return;
				}
			}
			else if (MISSION_FINISH_TYPE_SUBMIT_SPEC3_EQUIP == cond.type)
			{
				if (cond.completedFlag)
					return;
				if (data.id > 0)
				{
					auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(data.id);
					if (nullptr != pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId &&
						pEquipCfg->m_star >= (int32_t)cond.parma2)
					{
					}
					else
					{
						return;
					}
				}
				NFEquipPart* pEquipPart = dynamic_cast<NFEquipPart *>(m_pMaster->GetPart(PART_EQUIP));
				if (pEquipPart)
				{
					int condNum = 0;
					for (int e_pos = proto_ff::EEquipPos_m_weapon; e_pos <= proto_ff::EEquipPos_shoe; e_pos++)
					{
						auto& equipVec = pEquipPart->GetEquip();
						auto pEquip = equipVec.GetEquip(e_pos);
						if (pEquip)
						{
							auto pEquipCfg = pEquip->GetEquipCfg();
							if (pEquipCfg && pEquipCfg->m_quality >= (int32_t)cond.parma1 && pEquipCfg->m_wearQuality >= (int32_t)cond.itemId)
							{
								condNum++;
							}
						}
					}
					int32_t currentValue = condNum;
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
					return;
				}
			}
		}
		else if (MISSION_FINISH_TYPE_KILL_MONS_WILD_BOSS == cond.type)
		{
			//野外BOSS需要判断来源
			if ((int32_t)EMonsCreateType::MapBoss != data.source)
			{
				return;
			}
		}
		else if (MISSION_FINISH_TYPE_COLLECT_MONS == cond.type)
		{
		}
		else if (MISSION_FINISH_TYPE_KILL_MONS_BARREN_BOSS == cond.type)
		{
		}
		else if (MISSION_FINISH_TYPE_BOSS_KILL_BY_QUALITY == cond.type)
		{
			auto pBossCfg = BossBossDesc::Instance()->GetDesc(data.id);
			if (pBossCfg == NULL)
			{
				return;
			}
			if (pBossCfg->m_classOrder < (int)cond.parma2)
			{
				return;
			}
		}
		else if (MISSION_FINISH_TYPE_BOSS_KILL == cond.type)
		{
			if (cond.itemId != data.id)
			{
				return;
			}
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

int32_t NFMissionPart::OnExtractDyCond(const DyMissionInfo* pDyMissionInfo, MissionTrack* pMissionTrack, bool preUpdate)
{
	CHECK_EXPR(pDyMissionInfo, proto_ff::RET_FAIL, "pDyMissionInfo == NULL");
	CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == NULL");
	//抽取一个动态条件ID
	if (pDyMissionInfo->setComplete.size() < 1)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnExtractDyCond pDyMissionInfo->setComplete.size() < 1  missionid:{} ",
				   pDyMissionInfo->missionId);
		return proto_ff::RET_FAIL;
	}
	VEC_INT64 vecCond;
	vecCond.clear();
	for (auto iter = pDyMissionInfo->setComplete.begin(); iter != pDyMissionInfo->setComplete.end(); ++iter)
	{
		vecCond.push_back((*iter));
	}
	int32_t isize = vecCond.size();
	int32_t rndidx = NFRandInt(0, isize); // 0 - (isize-1)
	int64_t condId = vecCond.at(rndidx);
	const DyConditionInfo* pDyConditionInfo = TaskDescEx::Instance()->GetDyConditionCfgInfo(condId);
	if (nullptr == pDyConditionInfo)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnExtractDyCond nullptr == pDyConditionInfo missionid:{}, condid:{} ",
				   pDyMissionInfo->missionId, condId);
		return proto_ff::RET_FAIL;
	}
	//动态生成任务条件
	ItemInfo condItem;
	uint64_t textId;
	int32_t ret = OnGeneralCond(pDyMissionInfo, pDyConditionInfo, condItem, textId);
	if (proto_ff::RET_SUCCESS != ret)
	{
		return ret;
	}
	if (preUpdate)
	{
		//条件预更新
		OnPreUpdateProgress(condItem);
	}
	//添加到条件列表中
	pMissionTrack->items.push_back(condItem);
	pMissionTrack->textId = textId;
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::OnGeneralCond(const DyMissionInfo* pDyMissionInfo, const DyConditionInfo* pDyConditionInfo, ItemInfo& cond, uint64_t& textId)
{
	CHECK_EXPR(pDyMissionInfo, proto_ff::RET_FAIL, "pDyMissionInfo == NULL");
	CHECK_EXPR(pDyConditionInfo, proto_ff::RET_FAIL, "pDyConditionInfo == NULL");
	//条件赋值
	cond.type = pDyConditionInfo->cond.itemType;
	cond.itemId = pDyConditionInfo->cond.itemId;
	cond.finalValue = pDyConditionInfo->cond.itemCount;
	cond.parma1 = pDyConditionInfo->cond.parma1;
	cond.parma2 = pDyConditionInfo->cond.parma2;
	cond.parma3 = pDyConditionInfo->cond.parma3;
	//随机textid
	textId = TaskDescEx::Instance()->GetDyTextId(pDyMissionInfo->kind, cond.type);
	if (textId <= 0)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
				   "[logic] MissionManager::OnGeneralCond...can not find textid..... missionid:{} ,condid:{}, kind:{}, condType:{}",
				   pDyMissionInfo->missionId, pDyConditionInfo->condId, pDyMissionInfo->kind, cond.type);
	}
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::OnExtractDyAttrReward(MissionTrack* pNewMissinTrack)
{
	return 0;
}

int32_t NFMissionPart::AddReward(uint64_t missionId, int32_t kind, TASK_REWARD& reward, float ration)
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
			NFSkillPart* pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
			if (nullptr != pSkillPart)
			{
				SCommonSource source;
				if (!pSkillPart->AddSkill(reward[i].id, 1, source, true))
				{
					NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddReward...AddSkill failed...cid:%lu, skill:%s,missionid:%lu", m_pMaster->Cid(),
								  reward[i].id, missionId);
				}
			}
		}
		else if (MISSION_AWARD_ATTR == rewardType) //属性奖励
		{
			int64_t value = ceil(reward[i].value * ration);
			//
			m_pMaster->AddAttr(reward[i].id, value, &sourceParam, true);
		}
		else if (MISSION_AWARD_UNION_EXP == rewardType)
		{
			m_pMaster->AddAttr(proto_ff::A_FACTION_BUILD, reward[i].value, &sourceParam, true);
		}
		else if (MISSION_AWARD_USE_CONTRI == rewardType)
		{
			m_pMaster->AddAttr(proto_ff::A_CONTRI, reward[i].value, &sourceParam, true);
		}
	}
	//添加物品
	if (addItems.size() > 0)
	{
		NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
		CHECK_EXPR(pPackage, proto_ff::RET_FAIL, "");
		//上面判断过背包，这里直接添加物品
		pPackage->AddItem(addItems, sourceParam);
	}
	return proto_ff::RET_SUCCESS;
}

bool NFMissionPart::CanAddReward(uint64_t missionId, int32_t kind, TASK_REWARD& reward, LIST_ITEM& lstOutItem)
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
			/*const SkillCfg* pSkill = SkillDescEx::Instance()->GetCfg(reward[i].id);
			if (nullptr == pSkill)
			{
				LogErrFmtPrint("[logic] MissionManager::CanAddReward nullptr == pSkill  cid:%lu, pre:%s,missionid:%lu", pPlayer->Cid(),
							   param.strPre.c_str(), param.missionId);
				return false;
			}*/
		}
	}
	if (addItems.size() > 0)
	{
		NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
		NF_ASSERT(pPackage);
		if (!pPackage->CanAddItem(addItems))
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "missionId:{} add items failed.......", missionId);
			return false;
		}
		lstOutItem.insert(lstOutItem.end(), addItems.begin(), addItems.end());
	}
	return true;
}

int32_t NFMissionPart::RemoveMission(MissionInfo* pMissionInfo)
{
	CHECK_EXPR(pMissionInfo, proto_ff::RET_FAIL, "pMissionInfo == NULL");
	auto iter = m_playerTrackMissionMap.find(pMissionInfo->missionId);
	if (iter == m_playerTrackMissionMap.end())
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] RemoveMission missionId={} can not find mission data , charId={}",
				   pMissionInfo->missionId, m_pMaster->Cid());
		return proto_ff::RET_FAIL;
	}
	return RemoveMission(&iter->second, pMissionInfo);
}

int32_t NFMissionPart::RemoveMission(MissionTrack* pMissinTrack, MissionInfo* pMissionInfo)
{
	CHECK_EXPR(pMissinTrack, proto_ff::RET_FAIL, "pMissinTrack == NULL");
	CHECK_EXPR(pMissionInfo, proto_ff::RET_FAIL, "pMissionInfo == NULL");
	//移除任务掉落
	OnDelMissionDrop(pMissinTrack);
	//移除中间物品
	RemoveReward(pMissinTrack);
	//移除任务数据
	m_playerTrackMissionMap.erase(pMissinTrack->dynamicId);
	//移除接取任务时发放的物品
	RemoveReward(pMissionInfo->missionId, pMissionInfo->receAdd);
	//移除任务事件监听
	RemoveEvent(pMissionInfo->missionId);
	//通知删除任务
	NotifyDelMission(pMissionInfo->missionId);
	//
	MarkDirty();
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::RemoveDyMission(uint64_t dymissionId, bool notify)
{
	if (!ValidDyMissionId(dymissionId))
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] RemoveDyMission  dymissionId:{} ValidDyMissionId failed, charId={}", dymissionId,
				   m_pMaster->Cid());
		return proto_ff::RET_FAIL;
	}
	auto iter = m_playerTrackMissionMap.find(dymissionId);
	if (iter == m_playerTrackMissionMap.end())
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] RemoveDyMission dymissionId:{} can not find mission data , charId={}", dymissionId,
				   m_pMaster->Cid());
		return proto_ff::RET_FAIL;
	}
	uint64_t missionId = iter->second.missionId;
	const DyMissionInfo* pDyMissionCfgInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(missionId);
	if (nullptr == pDyMissionCfgInfo)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
				   "[logic] RemoveDyMission dymissionId:{}, missionid:{}, can not find mission config , charId={}", dymissionId, missionId,
				   m_pMaster->Cid());
		return proto_ff::RET_FAIL;
	}
	//移除任务掉落
	OnDelMissionDrop(&iter->second);
	//移除任务物品
	OnDelMissionItem(&iter->second);
	//移除任务数据
	m_playerTrackMissionMap.erase(iter);
	MarkDirty();
	//回收动态任务ID,如果是阵营任务或者赏金任务，动态ID由阵营和赏金可接列表那里回收
	FreeDyMissionId(dymissionId);
	//移除任务事件监听
	RemoveEvent(dymissionId);
	//通知删除任务
	if (notify)
	{
		NotifyDelMission(dymissionId);
	}
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::OnUpdateProgress(uint64_t missionId, const ExecuteData& data)
{
	//先查找已接列表中是否有该任务
	auto iter = m_playerTrackMissionMap.find(missionId);
	if (iter == m_playerTrackMissionMap.end())
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
		ItemInfo& cond = iter->second.items[i];
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
		MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(iter->second.missionId);
		if (nullptr != pMissionInfo)
		{
		}
		else
		{
			auto pDyMissionInfo = TaskDescEx::Instance()->GetDyMissionCfgInfo(iter->second.missionId);
			if (pDyMissionInfo)
			{
				//完成任务(动态任务)
				OnFinishDy(iter->second.missionId, iter->second.dynamicId, pDyMissionInfo->kind);
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

void NFMissionPart::UpdateMissionProgress(uint64_t missionId)
{
	auto missionIte = m_playerTrackMissionMap.find(missionId);
	if (missionIte != m_playerTrackMissionMap.end())
	{
		proto_ff::GCUpdateMissionStatusNotify notify;
		proto_ff::CMissionTrack* pMissionTrack = notify.add_updatelist();
		if (nullptr != pMissionTrack)
		{
			auto& missionInfo = missionIte->second;
			missionIte->second.SetMissionTrackProto(*pMissionTrack);
			auto& items = missionInfo.items;
			for (uint32_t i = 0; i < items.size(); i++)
			{
				NFLogDebugFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
							  "[logic] Update missionDyId=%lu,missionId=%lu,Status:%d, CondType=%u,textid:%lu,id=%lu, CurValue=%u, FinValue=%u, param1:%lu,param2:%lu,param3:%lu cid:%lu ",
							  missionId, missionInfo.missionId, missionInfo.status, items[i].type,
							  missionInfo.textId, items[i].itemId,
							  items[i].currentValue, items[i].finalValue, items[i].parma1,
							  items[i].parma2, items[i].parma3, m_pMaster->Cid());
			}
			m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_UPDATEMISSIONSTATUSNOTIFY, notify);
		}
	}
}

void NFMissionPart::NotifyDelMission(uint64_t dymissionId)
{
	proto_ff::GCDeleteMissionNotify notify;
	NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] Delete old DyMissionID={}, cid:{} ", dymissionId, m_pMaster->Cid());
	notify.add_dynamicid(dymissionId);
	m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GCDELETEMISSIONNOTIFY, notify);
}

int32_t NFMissionPart::OnDelMissionItem(MissionTrack* pMissionTrack)
{
	CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == NULL");
	NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
	CHECK_EXPR(pPackage, proto_ff::RET_FAIL, "pPackage == NULL");
	for (auto iter = pMissionTrack->items.begin(); iter != pMissionTrack->items.end(); ++iter)
	{
		ItemInfo& cond = (*iter);
		if (MISSION_FINISH_TYPE_COLLECT_ITEM == cond.type
			|| MISSION_FINISH_TYPE_COLLECT_CLIENT == cond.type
		)
		{
			if (cond.currentValue > 0)
			{
				SCommonSource sourceParam;
				sourceParam.src = S_MISSION;
				sourceParam.param1 = pMissionTrack->missionId;
				pPackage->RemoveItem(cond.itemId, cond.currentValue, sourceParam);
			}
		}
	}
	return proto_ff::RET_SUCCESS;
}

int32_t NFMissionPart::OnAddMissionDrop(MissionTrack* pMissionTrack, int32_t progressLev)
{
	CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == NULL");
	uint64_t missionId = pMissionTrack->missionId;
	uint64_t dymissionId = pMissionTrack->dynamicId;
	for (auto iter = pMissionTrack->items.begin(); iter != pMissionTrack->items.end(); ++iter)
	{
		ItemInfo& cond = (*iter);
		if (MISSION_FINISH_TYPE_COLLECT_KILL_MONS == cond.type
			|| MISSION_FINISH_TYPE_COLLECT_ITEM == cond.type
		)
		{
			//收集物品		格式 301=物品id=物品数量=生物ID=宝箱id=追踪区域ID（背包中有足够数量，即完成任务）
			//打怪收集		格式 302=物品id=物品数量=生物ID=宝箱id=追踪路径id
			if (!AddMissionDrop(dymissionId, cond.parma1, 0, cond.parma2, progressLev))
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
						   "AddMissionDrop failed....cid:{}, missionid:{}, dymissionid:{}, condtype:{},itemid:{},finalvalue:{},param1:{},param2:{},param3:{} ",
						   m_pMaster->Cid(), missionId, dymissionId, cond.type, cond.itemId, cond.finalValue, cond.parma1, cond.parma2, cond.parma3);
			}
		}
		else if (MISSION_FINISH_TYPE_COLLECT_MONS == cond.type)
		{
			//采集怪物		格式 305=物品id=物品数量=可采集怪物类型=宝箱id=0
			auto pVec = MonsterDescEx::Instance()->GetTaskTypeMonster(cond.parma1);
			if (pVec)
			{
				for (int i = 0; i < (int)pVec->size(); i++)
				{
					int64_t monsterId = pVec->at(i);
					if (!AddMissionDrop(dymissionId, monsterId, 0, cond.parma2, progressLev))
					{
						NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
									  "AddMissionDrop monsterId:%lu failed....cid:%lu, missionid:%lu, dymissionid:%lu, condtype:%d,itemid:%lu,finalvalue:%u,param1:%lu,param2:%lu,param3:%lu ",
									  monsterId, m_pMaster->Cid(), missionId, dymissionId, cond.type, cond.itemId, cond.finalValue, cond.parma1, cond.parma2, cond.parma3);
					}
				}
			}
		}
	}
	return proto_ff::RET_SUCCESS;
}

bool NFMissionPart::AddMissionDrop(uint64_t dymissionId, uint64_t monsId, uint64_t dropId, uint64_t boxId, int32_t progressLev)
{
	auto iterMons = m_mapMissionAllDrop.find(monsId);
	if (iterMons != m_mapMissionAllDrop.end())
	{
		MissionDropMap& mapDrop = iterMons->second;
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
		if (m_mapMissionAllDrop.size() >= m_mapMissionAllDrop.max_size())
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapMissionAllDrop Space Not Enough");
			return false;
		}
		m_mapMissionAllDrop[monsId][dymissionId] = stDrop;
	}
	return true;
}

bool NFMissionPart::DelMissionDrop(uint64_t dymissionId, uint64_t monsId)
{
	MissionAllDropMap::iterator iterMons = m_mapMissionAllDrop.find(monsId);
	if (iterMons != m_mapMissionAllDrop.end())
	{
		MissionDropMap& mapDrop = iterMons->second;
		MissionDropMap::iterator iterMission = mapDrop.find(dymissionId);
		if (iterMission != mapDrop.end())
		{
			mapDrop.erase(iterMission);
			if (mapDrop.size() <= 0)
			{
				m_mapMissionAllDrop.erase(iterMons);
			}
			//
			return true;
		}
	}
	return false;
}

MissionDropMap* NFMissionPart::GetMissionDrop(uint64_t monsterId)
{
	MissionAllDropMap::iterator iterMons = m_mapMissionAllDrop.find(monsterId);
	if (iterMons != m_mapMissionAllDrop.end())
	{
		return &iterMons->second;
	}
	return NULL;
}

int32_t NFMissionPart::OnDelMissionDrop(MissionTrack* pMissionTrack)
{
	CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == NULL");
	uint64_t missionId = pMissionTrack->missionId;
	uint64_t dymissionId = pMissionTrack->dynamicId;
	for (auto iter = pMissionTrack->items.begin(); iter != pMissionTrack->items.end(); ++iter)
	{
		ItemInfo& cond = (*iter);
		if (MISSION_FINISH_TYPE_COLLECT_KILL_MONS == cond.type)
		{
			//打怪收集		格式 302=物品id=物品数量=生物ID=宝箱id=追踪路径id
			if (!DelMissionDrop(dymissionId, cond.parma1))
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
						   "OnDelMissionDrop...pMissionPart->DelMissionDrop failed....cid:{}, missionid:{}, dymissionid:{}, condtype:{},itemid:{},finalvalue:{},param1:{},param2:{},param3:{} ",
						   m_pMaster->Cid(), missionId, dymissionId, cond.type, cond.itemId, cond.finalValue, cond.parma1, cond.parma2, cond.parma3);
			}
		}
	}
	return proto_ff::RET_SUCCESS;
}

int NFMissionPart::RemoveReward(MissionTrack* pMissionTrack)
{
	CHECK_EXPR(pMissionTrack, proto_ff::RET_FAIL, "pMissionTrack == NULL");
	NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
	CHECK_EXPR(pPackage, proto_ff::RET_FAIL, "pPackage == NULL");
	SCommonSource param;
	param.src = S_MISSION;
	param.param1 = pMissionTrack->missionId;
	for (auto iter = pMissionTrack->items.begin(); iter != pMissionTrack->items.end(); ++iter)
	{
		ItemInfo& cond = (*iter);
		if (MISSION_FINISH_TYPE_COLLECT_ITEM == cond.type
			|| MISSION_FINISH_TYPE_COLLECT_KILL_MONS == cond.type
			|| MISSION_FINISH_TYPE_COLLECT_CLIENT == cond.type
		)
		{
			pPackage->RemoveItem(cond.itemId, cond.finalValue, param);
		}
	}
	return proto_ff::RET_SUCCESS;
}

int NFMissionPart::RemoveReward(uint64_t missionId, TASK_REWARD& reward)
{
	SCommonSource sourceParam;
	sourceParam.src = S_MISSION;
	sourceParam.param1 = missionId;
	ORDER_MAP_INT32_INT32 costAttrs;
	NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
	CHECK_EXPR(pPackage, proto_ff::RET_FAIL, "pPackage == NULL");
	for (uint32_t i = 0; i < reward.size(); ++i)
	{
		uint32_t rewardType = reward[i].type;
		if (rewardType == MISSION_AWARD_GOODS || rewardType == MISSION_AWARD_EQUIP) //道具
		{
			if (nullptr != pPackage)
			{
				pPackage->RemoveItem(reward[i].id, reward[i].value, sourceParam, reward[i].bind);
			}
		}
		else if (rewardType == MISSION_AWARD_ATTR) //属性
		{
			int32_t id = reward[i].id;
			int64_t costValue = -reward[i].value;
			m_pMaster->AddAttr(id, costValue, &sourceParam, true);
		}
	}
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::RegisterEvent(uint32_t eventType, uint64_t missionId, int32_t progressLev)
{
	auto iter = m_eventTabal.find(eventType);
	if (iter != m_eventTabal.end())
	{
		auto& mapLevMission = iter->second;
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
		if (m_eventTabal.size() >= m_eventTabal.max_size())
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_eventTabal Space Not Enough");
		}
		m_eventTabal[eventType][progressLev].insert(missionId);
	}
}

void NFMissionPart::RemoveEvent(uint64_t missionId)
{
	auto iter = m_eventTabal.begin();
	while (iter != m_eventTabal.end())
	{
		auto& mapLevMission = iter->second;
		auto iterLv = mapLevMission.begin();
		while (iterLv != mapLevMission.end())
		{
			auto& setMission = iterLv->second;
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
			iter = m_eventTabal.erase(iter);
			continue;
		}
		++iter;
	}
}

void NFMissionPart::OnEvent(uint32_t eventType, const ExecuteData& data, uint64_t dynamicId)
{
	int32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
	EventTabal::iterator iter = m_eventTabal.find(eventType);
	if (m_eventTabal.end() != iter)
	{
		auto& mapLvMission = iter->second;
		auto iterLv = mapLvMission.begin();
		for (; iterLv != mapLvMission.end(); ++iterLv)
		{
			auto& setMission = iterLv->second;
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

int32_t NFMissionPart::OnSubmit(uint64_t missionId, uint32_t selidx)
{
	NFPackagePart* pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
	CHECK_EXPR(pPackagePart, proto_ff::RET_FAIL, "NFPackagePart == NULL");
	MissionInfo* pMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(missionId);
	if (nullptr == pMissionInfo)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] OnSubmit Have Not MissionID={} Config, Please Check Mission Config", missionId);
		return proto_ff::RET_MISSION_NOT_EXIST;
	}

	//查找提交的任务是否在已接列表中存在
	auto iter = m_playerTrackMissionMap.find(missionId);
	if (m_playerTrackMissionMap.end() == iter)
	{
		return proto_ff::RET_MISSION_NOT_EXIST;
	}

	MissionTrack* pSubmitMissionTrack = &iter->second;
	if (nullptr == pSubmitMissionTrack)
	{
		return proto_ff::RET_FAIL;
	}

	//判断任务是否完成
	if (MISSION_E_COMPLETION != pSubmitMissionTrack->status)
	{
		return proto_ff::RET_MISSION_STATE_NOT_MATCH;
	}

	uint64_t subdynamicId = pSubmitMissionTrack->dynamicId;
	//固定奖励放后面，可能给予奖励之后会触发刷新可接列表
	LIST_ITEM lstOutItem;
	lstOutItem.clear();
	if (!CanAddReward(pMissionInfo->missionId, pMissionInfo->kind, pMissionInfo->subAward, lstOutItem))
	{
		//背包空间不足
		return proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH;
	}

	//移除任务
	int32_t ret = RemoveMission(pSubmitMissionTrack, pMissionInfo);
	if (proto_ff::RET_SUCCESS != ret)
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
				   "MissionManager::OnSubmit...RemoveMission failed..cid:{},dynamic:{},missionid:{},backmission:{},ret:{}", m_pMaster->Cid(),
				   subdynamicId, pMissionInfo->missionId, pMissionInfo->backTaskId, ret);
		return ret;
	}

	int32_t retReward = AddReward(pMissionInfo->missionId, pMissionInfo->kind, pMissionInfo->subAward);
	if (proto_ff::RET_SUCCESS != retReward)
	{
		//正常是不会到这里，打印日志方便后面定位问题
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
				   "MissionManager::OnSubmit...AddReward failed..cid:{},dynamic:{},missionid:{},backmission:{},retReward:{}", m_pMaster->Cid(),
				   subdynamicId, pMissionInfo->missionId, pMissionInfo->backTaskId, retReward);
	}

	//提交任务
	uint64_t premissionid = 0;
	if (pMissionInfo->setPreTask.size() > 0)
	{
		premissionid = (*pMissionInfo->setPreTask.begin());
	}

	OnSubmit(missionId, premissionid, pMissionInfo->kind);
	//完成任务触发事件
	uint32_t missionType = pMissionInfo->kind;
	proto_ff::FinishTaskEvent taskEvent;
	taskEvent.set_taskid(missionId);
	taskEvent.set_tasktype(missionType);
	taskEvent.set_cid(m_pMaster->Cid());
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_FINISH_TASK, CREATURE_PLAYER, m_pMaster->Cid(), taskEvent);
	//
	NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
			   "MissionManager::OnSubmit...success cid:{},dynamic:{},missionid:{},premission:{},backmission:{},ret:{}", m_pMaster->Cid(),
			   subdynamicId, pMissionInfo->missionId, premissionid, pMissionInfo->backTaskId, ret);
	//
	if (pMissionInfo->backTaskId > 0)
	{
		const MissionInfo* pBackMissionInfo = TaskDescEx::Instance()->GetMissionCfgInfo(pMissionInfo->backTaskId);
		if (nullptr != pBackMissionInfo)
		{
			//如果有后置任务自动接取
			int32_t retaccept = AcceptMission(pMissionInfo->backTaskId, true);
			if (proto_ff::RET_SUCCESS != retaccept)
			{
				NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
						   "MissionManager::OnSubmit...can not accept backtask...cid:{},missionid:{},backmission:{},retaccept:{}",
						   m_pMaster->Cid(), pMissionInfo->missionId, pMissionInfo->backTaskId, retaccept);
			}
			else
			{
				NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
						   "MissionManager::OnSubmit...accept backtask success...cid:{},missionid:{},backmission:{} ", m_pMaster->Cid(),
						   pMissionInfo->missionId, pMissionInfo->backTaskId);
			}
		}
		else
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
					   "MissionManager::OnSubmit...can not find backtask cfg...cid:{},missionid:{},backmission:{} ", m_pMaster->Cid(),
					   pMissionInfo->missionId, pMissionInfo->backTaskId);
		}
	}
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::OnSubmit(uint64_t missionId, uint64_t premissionId, uint32_t kind)
{
	auto iter = m_mapRecentSubmit.find(kind);
	if (iter != m_mapRecentSubmit.end())
	{
		iter->second.erase(premissionId);
		if (iter->second.size() >= iter->second.max_size())
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapRecentSubmit iter->second Space Not Enough");
			return;
		}
		iter->second.insert(missionId);
	}
	else
	{
		if (m_mapRecentSubmit.size() >= m_mapRecentSubmit.max_size())
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_mapRecentSubmit iter->second Space Not Enough");
			return;
		}
		m_mapRecentSubmit[kind].insert(missionId);
	}
	m_setAlreadySubmit.insert(missionId);
	MarkDirty();
	//
	CheckPreAcceptMission(missionId);
}

void NFMissionPart::CheckPreAcceptMission(uint64_t missionId, bool notify)
{
	auto pSetPreAccept = TaskDescEx::Instance()->GetPreAcceptMission(missionId);
	if (nullptr == pSetPreAccept)
	{
		return;
	}
	for (auto iter = pSetPreAccept->begin(); iter != pSetPreAccept->end(); ++iter)
	{
		uint64_t acceptId = (*iter);
		MissionInfo* pMissionCfg = TaskDescEx::Instance()->GetMissionCfgInfo(acceptId);
		if (nullptr == pMissionCfg)
		{
			continue;
		}
		if (HaveAccept(acceptId))
		{
			continue;
		}
		if (HaveSubmited(acceptId))
		{
			continue;
		}
		if (proto_ff::RET_SUCCESS != CanAccept(pMissionCfg->accept))
		{
			continue;
		}
		int32_t ret = AcceptMission(acceptId, notify);
		if (proto_ff::RET_SUCCESS != ret)
		{
			NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
					   "MissionPart::CheckPreAcceptMission...OnAccept failed...cid:{},mission:{},acceptId:{},ret:{} ", m_pMaster->Cid(),
					   missionId, acceptId, ret);
		}
		else
		{
			NFLogDebug(NF_LOG_SYSTEMLOG, m_pMaster->Cid(),
					   "MissionPart::CheckPreAcceptMission...accept mission...cid:{},mission:{},acceptId:{},ret:{}", m_pMaster->Cid(),
					   missionId, acceptId, ret);
		}
	}
}

int32_t NFMissionPart::OnSubmitDy(uint64_t dymissionId)
{
	NFPackagePart* pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
	CHECK_EXPR(pPackage, proto_ff::RET_FAIL, "pPackage == NULL");
	//查找提交的任务是否在已接列表中存在
	auto iter = m_playerTrackMissionMap.find(dymissionId);
	if (m_playerTrackMissionMap.end() == iter)
	{
		return proto_ff::RET_MISSION_NOT_EXIST;
	}
	//判断任务是否完成
	if (MISSION_E_COMPLETION != iter->second.status)
	{
		return proto_ff::RET_MISSION_STATE_NOT_MATCH;
	}
	uint64_t missionId = iter->second.missionId;
	uint32_t missionType = iter->second.missionType;
	//移除任务
	int32_t ret = RemoveDyMission(dymissionId, true);
	if (proto_ff::RET_SUCCESS != ret)
	{
		return ret;
	}
	if (missionType != MISSION_TYPE_ID_BOUNTY)
	{
		//任务奖励
		SMissionReward missionReward;
		OnAddDyMissionReward(missionType, missionId, missionReward);
	}
	//完成任务触发事件
	proto_ff::FinishTaskEvent taskEvent;
	taskEvent.set_taskid(missionId);
	taskEvent.set_tasktype(missionType);
	taskEvent.set_cid(m_pMaster->Cid());
	FireExecute(NF_ST_LOGIC_SERVER, EVENT_FINISH_TASK, CREATURE_PLAYER, m_pMaster->Cid(), taskEvent);
	//任务提交处理,要放到奖励后面，奖励中如果有经验会有升级的情况
	OnSubmitDy(dymissionId, missionType);
	return proto_ff::RET_SUCCESS;
}

void NFMissionPart::OnSubmitDy(uint64_t dymissionId, int32_t missionType)
{
	if (MISSION_TYPE_ID_GUILD == missionType || MISSION_TYPE_ID_BOUNTY == missionType)
	{
		AcceptDyMissionByType(missionType, true);
	}
}

void NFMissionPart::OnFinishLoopMission(int32_t count)
{
	ExecuteData allExecuteData(M_EVENT_LOOPMISSIONNUM, 0, count);
	OnEvent(M_EVENT_LOOPMISSIONNUM, allExecuteData);
}

MissionTrack* NFMissionPart::AllocMissionTrack(uint64_t missionId)
{
	if (m_playerTrackMissionMap.size() >= m_playerTrackMissionMap.max_size())
	{
		NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "_playerTrackMissionMap Space Noet Enough.......");
		return NULL;
	}
	return &m_playerTrackMissionMap[missionId];
}

MissionTrack* NFMissionPart::GetMissionTrack(uint64_t missionId)
{
	auto iter = m_playerTrackMissionMap.find(missionId);
	if (iter != m_playerTrackMissionMap.end())
	{
		return &iter->second;
	}
	return nullptr;
}

int NFMissionPart::OnDie()
{
	return 0;
}

int NFMissionPart::OnLevelUp()
{
	CheckLevMission(true);
	CheckTrunkMission(true);
	//检查工会任务
	CheckGuildMission(true);
	return 0;
}

int NFMissionPart::OnPassDuplicate(const google::protobuf::Message* pMessage)
{
	const proto_ff::PassDupEvent* pPassDupEvent = dynamic_cast<const proto_ff::PassDupEvent *>(pMessage);
	CHECK_NULL(pPassDupEvent);
	uint64_t dupId = pPassDupEvent->dupid();
	uint64_t groupId = pPassDupEvent->groupid();
	ExecuteData executeData(M_EVENT_PASS_DUPLICATE, dupId, 1);
	OnEvent(M_EVENT_PASS_DUPLICATE, executeData);
	//
	ExecuteData executeDataEx(M_EVENT_PASS_DUPLICATE, groupId, 1);
	OnEvent(M_EVENT_PASS_DUPLICATE, executeDataEx);
	return 0;
}

int NFMissionPart::OnItemChange(const google::protobuf::Message* pMessage)
{
	const proto_ff::ItemChangeEvent* itemChangeEvent = dynamic_cast<const proto_ff::ItemChangeEvent *>(pMessage);
	CHECK_NULL(itemChangeEvent);
	uint64_t itemId = itemChangeEvent->itemid();
	int64_t itemNum = itemChangeEvent->itemnum();
	if (itemNum > 0)
	{
		ExecuteData executeData(M_EVENT_COLL_COLLECT_ITEM, itemId, itemNum, 0, S_Package_Storage);
		OnEvent(M_EVENT_COLL_COLLECT_ITEM, executeData);
	}
	else
	{
		//这里只有提交物品和提交装备两种才会调用 OnEvent，其他都不掉用,对应物品来源是
		if (S_MissionSubmitItem == itemChangeEvent->itemsource().src())
		{
			uint64_t dynamicId = itemChangeEvent->itemsource().param1();
			ExecuteData executeData(M_EVENT_USE_GOODS, itemId, abs(itemNum), 0, (int32_t)itemChangeEvent->itemsource().src());
			//提交物品的任务，只是单独完成某一个任务
			OnEvent(M_EVENT_USE_GOODS, executeData, dynamicId);
		}
	}
	return 0;
}

int NFMissionPart::OnArenaJoin(const google::protobuf::Message* pMessage)
{
	ExecuteData executeData(M_EVENT_ARENA_JOIN, 0, 1);
	OnEvent(M_EVENT_ARENA_JOIN, executeData);
	return 0;
}

int NFMissionPart::OnAddFriend()
{
	ExecuteData executeData(M_EVENT_ADD_FRIEND, 0, 1);
	OnEvent(M_EVENT_ADD_FRIEND, executeData);
	return 0;
}

int NFMissionPart::OnSlotStren(const google::protobuf::Message* pMessage)
{
	ExecuteData executeData(M_EVENT_SLOT_STREN);
	OnEvent(M_EVENT_SLOT_STREN, executeData);
	return 0;
}

int NFMissionPart::OnEblemInaly(const google::protobuf::Message* pMessage)
{
	ExecuteData executeData(M_EVENT_EMBLEM_INLAY, 0, 1);
	OnEvent(M_EVENT_EMBLEM_INLAY, executeData);
	return 0;
}

int NFMissionPart::OnAptitude(const google::protobuf::Message* pMessage)
{
	return 0;
}

int NFMissionPart::OnStoneInlay(const google::protobuf::Message* pMessage)
{
	ExecuteData allExecuteData(M_EVENT_ANY_STONE_INLAY, 0, 1);
	OnEvent(M_EVENT_ANY_STONE_INLAY, allExecuteData);
	return 0;
}

int NFMissionPart::OnGuildChange(const google::protobuf::Message* pMessage)
{
	CheckGuildMission(true);
	if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) > 0)
	{
		ExecuteData allExecuteData(M_EVENT_JOIN_GUILD, 0, 1);
		OnEvent(M_EVENT_JOIN_GUILD, allExecuteData);
	}
	return 0;
}

int NFMissionPart::OnConvoyCommit(const google::protobuf::Message* pMessage)
{
	ExecuteData allExecuteData(M_EVENT_CONNVOY_COMMIT, 0, 1);
	OnEvent(M_EVENT_CONNVOY_COMMIT, allExecuteData);
	return 0;
}

int NFMissionPart::OnWingLevup(const google::protobuf::Message* pMessage)
{
	const proto_ff::WingAdvance* pWingEvent = dynamic_cast<const proto_ff::WingAdvance *>(pMessage);
	if (nullptr != pWingEvent)
	{
		ExecuteData allExecuteData(M_EVENT_WING_LEV, (uint64_t)pWingEvent->nlevel());
		OnEvent(M_EVENT_WING_LEV, allExecuteData);
	}
	return 0;
}

int NFMissionPart::OnTreasureLevup(const google::protobuf::Message* pMessage)
{
	const proto_ff::TreasureAdvance* pTreasureEvent = dynamic_cast<const proto_ff::TreasureAdvance *>(pMessage);
	if (nullptr != pTreasureEvent)
	{
		ExecuteData allExecuteData(M_EVENT_TREASURE_LEV, (uint64_t)pTreasureEvent->nlevel());
		OnEvent(M_EVENT_TREASURE_LEV, allExecuteData);
	}
	return 0;
}

int NFMissionPart::OnPartnerLevup(const google::protobuf::Message* pMessage)
{
	const proto_ff::PartnerAdvance* pPartnerEvent = dynamic_cast<const proto_ff::PartnerAdvance *>(pMessage);
	if (nullptr != pPartnerEvent)
	{
		ExecuteData allExecuteData(M_EVENT_PARTNER_RANKLEV, (uint64_t)pPartnerEvent->nlevel());
		OnEvent(M_EVENT_PARTNER_RANKLEV, allExecuteData);
	}
	return 0;
}

int NFMissionPart::OnLightSoul(const google::protobuf::Message* pMessage)
{
	const proto_ff::LightSoulEvent* pSoulEvent = dynamic_cast<const proto_ff::LightSoulEvent *>(pMessage);
	CHECK_NULL(pSoulEvent);
	ExecuteData allExecuteData(M_EVENT_LIGHT_SOUL, pSoulEvent->soul_type(), 1);
	OnEvent(M_EVENT_LIGHT_SOUL, allExecuteData);
	return 0;
}

int NFMissionPart::OnCollectEvent(const google::protobuf::Message* pMessage)
{
	const proto_ff::CollectEvent* pEvent = dynamic_cast<const proto_ff::CollectEvent *>(pMessage);
	CHECK_NULL(pEvent);
	ExecuteData allExecuteData(M_EVENT_COLL_COLLECT_ITEM, pEvent->monsid(), 1);
	OnEvent(M_EVENT_COLL_COLLECT_ITEM, allExecuteData);
	return 0;
}

int NFMissionPart::OnEquipDress(const google::protobuf::Message* pMessage)
{
	const proto_ff::DressEquipChangeEvent* pEvent = dynamic_cast<const proto_ff::DressEquipChangeEvent *>(pMessage);
	CHECK_NULL(pEvent);
	ExecuteData executeData(M_EVENT_USE_GOODS, pEvent->itemid(), 0, 0, (int32_t)S_MissionSubmitItem);
	//提交物品的任务，只是单独完成某一个任务
	OnEvent(M_EVENT_USE_GOODS, executeData);
	return 0;
}

int NFMissionPart::OnEquipUnDress(const google::protobuf::Message* pMessage)
{
	const proto_ff::EquipUndress* pEvent = dynamic_cast<const proto_ff::EquipUndress *>(pMessage);
	CHECK_NULL(pEvent);
	ExecuteData executeData(M_EVENT_USE_GOODS, pEvent->itemid(), 0, 0, (int32_t)S_MissionSubmitItem);
	//提交物品的任务，只是单独完成某一个任务
	OnEvent(M_EVENT_USE_GOODS, executeData);
	return 0;
}

int NFMissionPart::OnJoinClan(const google::protobuf::Message* pMessage)
{
	const proto_ff::ClanJoinEvent* pEvent = dynamic_cast<const proto_ff::ClanJoinEvent *>(pMessage);
	CHECK_NULL(pEvent);
	if (pEvent->clan_type() == 1)
	{
		ExecuteData allExecuteData(M_EVENT_CROSS_3V3, 0, 1);
		OnEvent(M_EVENT_CROSS_3V3, allExecuteData);
	}
	return 0;
}

int NFMissionPart::OnGodRelicTaskGroup(const google::protobuf::Message* pMessage)
{
	const proto_ff::GodRelicsFinish* pEvent = dynamic_cast<const proto_ff::GodRelicsFinish *>(pMessage);
	CHECK_NULL(pEvent);
	ExecuteData allExecuteData(M_EVENT_ACTION_BUTTON, pEvent->id(), 1);
	OnEvent(M_EVENT_ACTION_BUTTON, allExecuteData);
	return 0;
}
