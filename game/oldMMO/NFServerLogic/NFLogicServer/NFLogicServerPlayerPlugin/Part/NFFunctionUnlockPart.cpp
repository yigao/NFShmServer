// -------------------------------------------------------------------------
//    @FileName         :    NFFunctionUnlockPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFFunctionUnlockPart
//
// -------------------------------------------------------------------------

#include "NFFunctionUnlockPart.h"
#include "Player/NFPlayer.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "ClientServerCmd.pb.h"
#include "ClientServer.pb.h"
#include "Event.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFLogicCommon/PackageDefine.h"
#include "NFPackagePart.h"
#include "DescStore/FunctionunlockPreviewDesc.h"
#include "DescStore/FunctionunlockFunctionunlockDesc.h"
#include "NFLogicCommon/NFFuncUnLockDefine.h"
#include "DescStoreEx/NFFuncUnLockDescStoreEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFunctionUnlockPart, EOT_LOGIC_FUNCTIONUNLOCK_PART_ID, NFPart)

NFFunctionUnlockPart::NFFunctionUnlockPart() : NFPart()
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

NFFunctionUnlockPart::~NFFunctionUnlockPart()
{
}

int NFFunctionUnlockPart::CreateInit()
{
    return 0;
}

int NFFunctionUnlockPart::ResumeInit()
{
    return 0;
}

int NFFunctionUnlockPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    if (dbData.has_unlockinfo())
    {
        //功能解锁数据
        const ::proto_ff::FunctionUnlockInfo &unlockInfo = dbData.unlockinfo();
        for (int i = 0; i < unlockInfo.data_size(); ++i)
        {
            auto& data = unlockInfo.data(i);
            auto iter = m_mapUnLock.emplace_hint(data.unlockid(), data.get_reward());
            if (iter == m_mapUnLock.end())
            {
                NFLogError(NF_LOG_SYSTEMLOG, pMaster->GetRoleId(), "m_mapUnLock space not enouth, Insert Failed! unlockId:{} get_reward:{}", data.unlockid(), data.get_reward());
            }
        }
    }

    //订阅升级,完成任务
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_LEVELUP, m_pMaster->GetRoleId(), CREATURE_PLAYER, "NFFunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_FINISH_TASK, m_pMaster->GetRoleId(), CREATURE_PLAYER, "NFFunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_FACADE_CHANGE, m_pMaster->GetRoleId(), CREATURE_PLAYER, "NFFunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_PAY, m_pMaster->GetRoleId(), CREATURE_PLAYER, "NFFunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_VIP_UP, m_pMaster->GetRoleId(), CREATURE_PLAYER, "NFFunctionUnlockPart");
    return 0;
}

int NFFunctionUnlockPart::UnInit()
{
    NFPart::UnInit();
    return 0;
}


int NFFunctionUnlockPart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_SERVER_FUNCTIONUNLOCK_GET_REWARD_REQ, PART_FUNCTIONUNLOCK);
    return 0;
}

int NFFunctionUnlockPart::RegisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFFunctionUnlockPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    ::proto_ff::FunctionUnlockInfo* pInfo = dbData.mutable_unlockinfo();

    //已解锁功能id
    for(auto iter = m_mapUnLock.begin(); iter != m_mapUnLock.end(); iter++)
    {
        auto pData = pInfo->add_data();
        pData->set_unlockid(iter->first);
        pData->set_get_reward(iter->second);
    }

    return 0;
}

int NFFunctionUnlockPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch(msgId)
    {
        case proto_ff::CLIENT_TO_SERVER_FUNCTIONUNLOCK_GET_REWARD_REQ:
        {
            OnHandleGetReward(msgId, packet);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetRoleId(), "packet:{} not handle", packet.ToString());
            break;
        }
    }
    return 0;
}

int NFFunctionUnlockPart::OnHandleGetReward(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::FunctionUnlockGetRewardReq msgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, msgReq);

    proto_ff::FunctionUnlockGetRewardRsp rsp;
    rsp.set_ret_code(proto_ff::RET_FAIL);
    auto pData = rsp.mutable_data();
    pData->set_unlockid(msgReq.function_id());
    pData->set_get_reward(false);

    auto iter = m_mapUnLock.find(msgReq.function_id());
    if (iter == m_mapUnLock.end())
    {
        m_pMaster->SendMsgToClient(proto_ff::SERVER_TO_CLIENT_FUNCTIONUNLOCK_GET_REWARD_RSP, rsp);
        return -1;
    }

    if (iter->second == true)
    {
        m_pMaster->SendMsgToClient(proto_ff::SERVER_TO_CLIENT_FUNCTIONUNLOCK_GET_REWARD_RSP, rsp);
        return -1;
    }

    bool ret = false;
    auto pPreviewMap = FunctionunlockPreviewDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    for(auto i = 0; i < (int)pPreviewMap->size(); i++)
    {
        auto pPreview = &pPreviewMap->at(i);

        if ((uint64_t)pPreview->m_functionid == msgReq.function_id())
        {
            NFPackagePart *pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
            if (pPackage)
            {
                SCommonSource sourceParam;
                sourceParam.src = S_FunctionUnlock;
                LIST_ITEM lstItem;
                SItem item(pPreview->m_rewarditem, pPreview->m_rewardnum, EBindState::EBindState_no);
                lstItem.push_back(item);
                ret = pPackage->AddItem(lstItem, sourceParam, true, true);
            }
            break;
        }
    }

    if (ret)
    {
        iter->second = true;
        rsp.set_ret_code(proto_ff::RET_SUCCESS);
        pData->set_get_reward(true);
        MarkDirty();
    }

    m_pMaster->SendMsgToClient(proto_ff::SERVER_TO_CLIENT_FUNCTIONUNLOCK_GET_REWARD_RSP, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFFunctionUnlockPart::UnlockAllFunc()
{
    auto pArrayUnlockCfg = FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_NULL(pArrayUnlockCfg)

    VEC_UINT64 noticeList;
    noticeList.clear();
    //
    for (auto i = 0; i < (int)pArrayUnlockCfg->size(); i++)
    {
        auto pInfo = &pArrayUnlockCfg->at(i);
        CHECK_NULL(pInfo);
        if (!isFunctionUnlock(pInfo->m_functionid))
        {
            AddUnlock(pInfo->m_functionid);
            noticeList.push_back(pInfo->m_functionid);
        }
    }
    //
    if (noticeList.size() > 0)
    {
        sendFunctionUnlockInfo(&noticeList);
        //保存标记
        MarkDirty();
        //
        for (auto &iteradd : noticeList)
        {
            //解锁事件
            proto_ff::FunctionUnlockEvent unlockEvent;
            unlockEvent.set_functionid(iteradd);
            FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, m_pMaster->GetRoleId(), CREATURE_PLAYER, unlockEvent);
        }
    }
    return true;
}

bool NFFunctionUnlockPart::isFunctionUnlock(uint64_t m_functionid)
{
    auto iter = m_mapUnLock.find(m_functionid);
    return (iter != m_mapUnLock.end());
}

void NFFunctionUnlockPart::Unlock(int64_t m_functionid)
{
    if (isFunctionUnlock(m_functionid)) return;
    AddUnlock(m_functionid);
    sendFunctionUnlockInfo(nullptr);
}

void NFFunctionUnlockPart::UnlockSendAdd(int64_t m_functionid)
{
    if (isFunctionUnlock(m_functionid)) return;
    AddUnlock(m_functionid);
    auto iter = m_mapUnLock.find(m_functionid);
    if (iter != m_mapUnLock.end())
    {
        VEC_UINT64 list;
        list.push_back(m_functionid);
        sendFunctionUnlockInfo(&list);
    }
}

void NFFunctionUnlockPart::checkUnlock(uint32_t nType, int64_t nValue)
{
    auto pList = NFFuncUnLockDescStoreEx::Instance(m_pObjPluginManager)->GetUnlockFunctionList(nType, nValue,true);
    if (nullptr == pList)
    {
        return;
    }
    //todo need  MissionPart PayPart
/*	MissionPart *pMissionPart = dynamic_cast<MissionPart*>(m_pMaster->GetPart(PART_MISSION));
	if (nullptr == pMissionPart)
	{
		return;
	}
	PayPart *pPayPart = dynamic_cast<PayPart*>(m_pMaster->GetPart(PART_PAY));
	if (nullptr == pPayPart)
	{
		return;
	}*/
    //玩家等级
    int32_t level = (int32_t)m_pMaster->GetAttr(proto_ff::A_LEVEL);
    //转职等级
    int32_t ocGrade = (int32_t)GetOccupationGrade(0);
    //VIP等级
    int32_t viplevel = 0; //todo need A_VIP_LEVEL (int32_t)m_pMaster->GetAttr(A_VIP_LEVEL);
    //历史充值人名币
    int32_t totalrmb = 0; //todo need pay (int32_t)pPayPart->RealPayRmb();
    //开服天数
    uint32_t opendays = OpenDays();
    //新增的功能开发列表
    VEC_UINT64 vecAddLst;
    vecAddLst.clear();
    //是否有功能是从开启列表中移除的标记
    bool delFlag = false;
    //
    for(auto iter = pList->begin(); iter != pList->end(); iter++)
    {
        uint32_t m_functionid = *(iter);
        auto pUnlockCfg = FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetDesc(m_functionid);
        if (nullptr == pUnlockCfg)
        {
            continue;
        }
        if(FUNCTION_UNLOCK_TYPE_SPECIAL == pUnlockCfg->m_opentype)
        {
            continue;
        }
        //
        bool unlockFlag = CheckUnlock(level, ocGrade, opendays, viplevel, totalrmb, *pUnlockCfg);
        //
        if (isFunctionUnlock(pUnlockCfg->m_functionid))
        {
            if (!unlockFlag)
            {
                delFlag = true;
                DelUnlock(pUnlockCfg->m_functionid);
            }
        }
        else if (unlockFlag)
        {
            vecAddLst.push_back(pUnlockCfg->m_functionid);
            AddUnlock(pUnlockCfg->m_functionid);
        }
    }
    //
    if (delFlag)
    {
        sendFunctionUnlockInfo(nullptr);
    }
    else if (vecAddLst.size() > 0)
    {
        sendFunctionUnlockInfo(&vecAddLst);
        //
        for (auto &iteradd : vecAddLst)
        {
            //解锁事件
            proto_ff::FunctionUnlockEvent unlockEvent;
            unlockEvent.set_functionid(iteradd);
            FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, m_pMaster->GetRoleId(), CREATURE_PLAYER, unlockEvent);
        }
    }
}

void NFFunctionUnlockPart::sendFunctionUnlockInfo(VEC_UINT64 *pList)
{
    proto_ff::FunctionUnlockInfoRsp infoRsp;
    infoRsp.set_retcode(proto_ff::RET_SUCCESS);
    if (nullptr == pList)
    {
        //发送全部以解锁功能
        infoRsp.set_syntype(FUNCTION_SYNC_TYPE_ALL);
        for (auto iter = m_mapUnLock.begin(); iter != m_mapUnLock.end(); iter++)
        {
            auto pData = infoRsp.add_data();
            pData->set_unlockid(iter->first);
            pData->set_get_reward(iter->second);
        }
    }
    else
    {
        if (pList->size() <= 0)
        {
            return;
        }
        //发送新增的
        infoRsp.set_syntype(FUNCTION_SYNC_TYPE_ADD);
        for (auto &iter : *pList)
        {
            auto pData = infoRsp.add_data();
            pData->set_unlockid(iter);
            pData->set_get_reward(false);
        }
    }
    m_pMaster->SendMsgToClient(proto_ff::SERVER_TO_CLIENT_FUNCTIONUNLOCK_INFO, infoRsp);
}

void NFFunctionUnlockPart::DelUnlock(uint64_t unlockid)
{
    m_mapUnLock.erase(unlockid);
}

void NFFunctionUnlockPart::AddUnlock(uint64_t unlockid)
{
    auto iter = m_mapUnLock.emplace_hint(unlockid, false);
    if (iter == m_mapUnLock.end())
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetRoleId(), "AddUnlock Failed, unlockid:{}, not enough space!!", unlockid);
    }
}

int NFFunctionUnlockPart::CheckALLFunctions(bool sync)
{
    auto pArrayUnLockCfg = FunctionunlockFunctionunlockDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_NULL(pArrayUnLockCfg);

    //玩家等级
    int32_t level = (int32_t)m_pMaster->GetAttr(proto_ff::A_LEVEL);
    //转职等级
    int32_t ocGrade = (int32_t)GetOccupationGrade(0);
    //VIP等级
    int32_t viplevel = 0; //todo need A_VIP_LEVEL (int32_t)m_pMaster->GetAttr(A_VIP_LEVEL);
    //历史充值人名币
    int32_t totalrmb = 0; // todo need pay part (int32_t)pPayPart->RealPayRmb();
    //开服天数
    uint32_t opendays = OpenDays();
    //是否有功能是从开启列表中移除的标记
    bool delFlag = false;
    //新增开启列表
    VEC_UINT64 vecAddLst;
    vecAddLst.clear();
    //
    for (auto i = 0; i < (int)pArrayUnLockCfg->size(); i++)
    {
        auto pInfo = &pArrayUnLockCfg->at(i);
        CHECK_NULL(pInfo);

        if(FUNCTION_UNLOCK_TYPE_SPECIAL ==  pInfo->m_opentype)
        {
            continue;
        }
        //
        bool unlockFlag = CheckUnlock(level, ocGrade, opendays, viplevel, totalrmb, *pInfo);
        //
        if (isFunctionUnlock(pInfo->m_functionid))
        {
            if (!unlockFlag)
            {
                delFlag = true;
                DelUnlock(pInfo->m_functionid);
            }
        }
        else if (unlockFlag)
        {
            vecAddLst.push_back(pInfo->m_functionid);
            AddUnlock(pInfo->m_functionid);
        }
    }
    //
    if (sync)
    {
        if (delFlag)
        {
            sendFunctionUnlockInfo(nullptr);
        }
        else if (vecAddLst.size() > 0)
        {
            sendFunctionUnlockInfo(&vecAddLst);
            //
            for (auto &iteradd : vecAddLst)
            {
                //解锁事件
                proto_ff::FunctionUnlockEvent unlockEvent;
                unlockEvent.set_functionid(iteradd);
                FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, m_pMaster->GetRoleId(), CREATURE_PLAYER, unlockEvent);
            }
        }
    }
    else {
        if (vecAddLst.size() > 0)
        {
            for (auto &iteradd : vecAddLst)
            {
                //解锁事件
                proto_ff::FunctionUnlockEvent unlockEvent;
                unlockEvent.set_functionid(iteradd);
                FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, m_pMaster->GetRoleId(), CREATURE_PLAYER, unlockEvent);
            }
        }
    }
    return true;
}

uint32_t NFFunctionUnlockPart::GetOccupationGrade(uint64_t occupationId)
{
    return 0;
}

bool NFFunctionUnlockPart::CheckUnlock(int32_t Lev, int32_t occupationLev, uint32_t opendays, int32_t viplev, int32_t totalrmb,
                                       const proto_ff_s::E_FunctionunlockFunctionunlock_s &cfg)
{
    if ((int32_t)opendays < cfg.m_opendaily)
    {
        return false;
    }
    int32_t m_opentype = cfg.m_opentype;
    int64_t m_openval = cfg.m_openval;
    if (FUNCTION_UNLOCK_TYPE_LEVEL == m_opentype)
    {
        return ((int64_t)Lev >= m_openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_TAST == m_opentype)
    {
/*		if (nullptr == pMissionPart)
		{
			return false;
		}
		return pMissionPart->HaveSubmited(m_openval);*/
    }
    else if (FUNCTION_UNLOCK_TYPE_TRANSFER == m_opentype)
    {
        return ((int64_t)occupationLev >= m_openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_PAYRMB == m_opentype)
    {
        return ((int64_t)totalrmb >= m_openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_VIP_LEV == m_opentype)
    {
        return ((int64_t)viplev >= m_openval);
    }

    return false;
}

uint32_t NFFunctionUnlockPart::OpenDays()
{
    return INT32_MAX;
/*    uint32_t zid = m_pMaster->GetZid();
    if (g_GetLogicService()->IsMerged(zid))
    {
        //合服之后，不需要再判定开服天数了，为了逻辑上统一，合服之后开服天数返回一个很大的值
        return INT32_MAX;
    }
    return g_GetLogicService()->GetDayFromOpen(zid);*/
}

int NFFunctionUnlockPart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    ::proto_ff::FunctionUnlockInfo *proto = playerInfo.mutable_unlockinfo();
    CHECK_NULL(proto);

    //检查所有功能是否可开启
    CheckALLFunctions(false);

    //已解锁功能id
    for (auto iter = m_mapUnLock.begin(); iter != m_mapUnLock.end(); iter++)
    {
        auto pData = proto->add_data();
        pData->set_unlockid(iter->first);
        pData->set_get_reward(iter->second);
    }
    return 0;
}

int NFFunctionUnlockPart::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                    const google::protobuf::Message *pMessage)
{
    if (nEventID == EVENT_LEVELUP)
    {
        EVENT_PROCESS_WITH_PRINTF(serverType, nEventID, bySrcType, nSrcID, pMessage, proto_ff::PlayerLeveUpEvent, pEventMsg);
        uint32_t nLevel = pEventMsg->level();
        checkUnlock(FUNCTION_UNLOCK_TYPE_LEVEL, nLevel);
    }
    return 0;
}

int NFFunctionUnlockPart::DailyZeroUpdate(uint64_t unixSec)
{
    CheckALLFunctions(true);
    return 0;
}

