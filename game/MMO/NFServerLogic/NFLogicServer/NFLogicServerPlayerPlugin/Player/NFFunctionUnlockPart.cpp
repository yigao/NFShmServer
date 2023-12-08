// -------------------------------------------------------------------------
//    @FileName         :    NFFunctionUnlockPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFunctionUnlockPart
//
// -------------------------------------------------------------------------

#include "NFFunctionUnlockPart.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "DescStoreEx/FunctionunlockDescEx.h"
#include "Mission/NFMissionPart.h"
#include "proto_svr_event.pb.h"
#include "ClientServer.pb.h"
#include "NFVipPart.h"
#include "NFPayPart.h"
#include "Package/NFPackagePart.h"
#include "DescStore/FunctionunlockPreviewDesc.h"
#include "NFGodEvilPart.h"
#include "NFLogicServer/NFLogicServerPlayerPlugin/Growth/NFBestEQPart.h"
#include "NFMarryPart.h"
#include "NFTurnPart.h"
#include "NFDupPart.h"
#include "NFSoulPart.h"

NFFunctionUnlockPart::NFFunctionUnlockPart()
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
    
    //订阅升级,完成任务
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_LEVELUP, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_FINISH_TASK, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_FACADE_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_PAY, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_VIP_UP, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_PASS_DUPLICATE, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_GODE_EVIL_ACTIVE, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_BEQ_CMPT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_MARRY_CMPT_RECV_TASK, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_TURN_CMPT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_SOUL_CMPT_TASK, CREATURE_PLAYER, m_pMaster->Cid(), "FunctionUnlockPart");
    return 0;
}

int NFFunctionUnlockPart::UnInit()
{
    return NFPart::UnInit();
}

int NFFunctionUnlockPart::LoadFromDB(const proto_ff::RoleDBData &dbData)
{
    if (dbData.has_unlockinfo())
    {
        //功能解锁数据
        const proto_ff::FunctionUnlockInfo &unlockInfo = dbData.unlockinfo();
        for (int i = 0; i < unlockInfo.data_size(); ++i)
        {
            auto &data = unlockInfo.data(i);
            CHECK_EXPR_BREAK(m_mapUnLock.size() < m_mapUnLock.max_size(), "m_mapUnLock Space Not Enough");
            m_mapUnLock.emplace(data.unlockid(), data.get_reward());
        }
    }
    return 0;
}

int NFFunctionUnlockPart::InitConfig(const proto_ff::RoleDBData &data)
{
    return 0;
}

int NFFunctionUnlockPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    proto_ff::FunctionUnlockInfo *pInfo = dbData.mutable_unlockinfo();
    //已解锁功能id
    for (auto &iter : m_mapUnLock)
    {
        auto pData = pInfo->add_data();
        pData->set_unlockid(iter.first);
        pData->set_get_reward(iter.second);
    }
    
    return 0;
}

int NFFunctionUnlockPart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFFunctionUnlockPart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    proto_ff::FunctionUnlockInfo *proto = playerInfo.mutable_unlockinfo();
    //检查所有功能是否可开启
    CheckALLFunctions(false);
    //已解锁功能id
    for (auto &iter : m_mapUnLock)
    {
        auto pData = proto->add_data();
        pData->set_unlockid(iter.first);
        pData->set_get_reward(iter.second);
    }
    return 0;
}

int NFFunctionUnlockPart::DailyZeroUpdate()
{
    CheckALLFunctions(true);
    return 0;
}

int NFFunctionUnlockPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_SERVER_FUNCTIONUNLOCK_GET_REWARD_REQ);
    return 0;
}

int NFFunctionUnlockPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_SERVER_FUNCTIONUNLOCK_GET_REWARD_REQ:
        {
            OnHandleGetReward(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFFunctionUnlockPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFFunctionUnlockPart::OnHandleGetReward(uint32_t msgId, NFDataPackage &packet)
{
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
    auto pPreviewCfg = FunctionunlockPreviewDesc::Instance()->GetDescByFunctionid(msgReq.function_id());
    if (pPreviewCfg)
    {
        NFPackagePart *pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
        if (pPackage)
        {
            SCommonSource sourceParam;
            sourceParam.src = S_FunctionUnlock;
            LIST_ITEM lstItem;
            SItem item(pPreviewCfg->m_rewardItem, pPreviewCfg->m_rewardNum, EBindState::EBindState_no);
            lstItem.push_back(item);
            ret = pPackage->AddItem(lstItem, sourceParam, true, true);
        }
    }
    
    if (ret)
    {
        iter->second = true;
        rsp.set_ret_code(proto_ff::RET_SUCCESS);
        pData->set_get_reward(true);
        SetNeedSave(true);
    }
    m_pMaster->SendMsgToClient(proto_ff::SERVER_TO_CLIENT_FUNCTIONUNLOCK_GET_REWARD_RSP, rsp);
    return 0;
}

bool NFFunctionUnlockPart::UnlockAllFunc()
{
    auto mapUnlockCfg = FunctionunlockFunctionunlockDesc::Instance()->GetResDescPtr();
    if (nullptr == mapUnlockCfg)
    {
        return false;
    }
    
    VEC_UINT64 noticeList;
    noticeList.clear();
    //
    for (const auto &iter : *mapUnlockCfg)
    {
        if (!isFunctionUnlock(iter.first))
        {
            AddUnlock(iter.first);
            noticeList.push_back(iter.first);
        }
    }
    //
    if (noticeList.size() > 0)
    {
        sendFunctionUnlockInfo(&noticeList);
        //保存标记
        SetNeedSave(true);
        //
        for (auto &iteradd : noticeList)
        {
            //解锁事件
            proto_ff::FunctionUnlockEvent unlockEvent;
            unlockEvent.set_functionid(iteradd);
            unlockEvent.set_sync(true);
            FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), unlockEvent);
        }
    }
    return true;
}

bool NFFunctionUnlockPart::isFunctionUnlock(uint64_t functionId)
{
    auto iter = m_mapUnLock.find(functionId);
    return (iter != m_mapUnLock.end()) ? true : false;
}

void NFFunctionUnlockPart::Unlock(int64_t functionId)
{
    if (isFunctionUnlock(functionId))
        return;
    AddUnlock(functionId);
    sendFunctionUnlockInfo(nullptr);
}

void NFFunctionUnlockPart::UnlockSendAdd(int64_t functionId)
{
    if (isFunctionUnlock(functionId))
        return;
    AddUnlock(functionId);
    
    proto_ff::FunctionUnlockEvent unlockEvent;
    unlockEvent.set_functionid(functionId);
    unlockEvent.set_sync(true);
    FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), unlockEvent);
    
    auto iter = m_mapUnLock.find(functionId);
    if (iter != m_mapUnLock.end())
    {
        VEC_UINT64 list;
        list.push_back(functionId);
        sendFunctionUnlockInfo(&list);
    }
}

void NFFunctionUnlockPart::checkUnlock(uint32_t nType, int64_t nValue)
{
    const SET_UINT64 *pList = FunctionunlockDescEx::Instance()->GetUnlockFunctionList(nType, nValue, true);
    if (nullptr == pList)
    {
        return;
    }
    
    NFMissionPart *pMissionPart = dynamic_cast<NFMissionPart *>(m_pMaster->GetPart(PART_MISSION));
    if (nullptr == pMissionPart)
    {
        return;
    }
    
    NFPayPart *pPayPart = dynamic_cast<NFPayPart *>(m_pMaster->GetPart(PART_PAY));
    if (nullptr == pPayPart)
    {
        return;
    }
    
    //玩家等级
    int32_t level = (int32_t) m_pMaster->GetAttr(proto_ff::A_LEVEL);
    //转职等级
    int32_t ocGrade = (int32_t) GetOccupationGrade(0);
    //VIP等级
    int32_t viplevel = m_pMaster->GetAttr(proto_ff::A_VIP_LEVEL);
    //历史充值人名币
    int32_t totalrmb = (int32_t) pPayPart->RealRmb();
    //开服天数
    uint32_t opendays = OpenDays();
    //新增的功能开发列表
    VEC_UINT64 vecAddLst;
    vecAddLst.clear();
    //是否有功能是从开启列表中移除的标记
    bool delFlag = false;
    //
    for (auto iter : *pList)
    {
        auto pUnlockCfg = FunctionunlockFunctionunlockDesc::Instance()->GetDesc(iter);
        if (nullptr == pUnlockCfg)
        {
            continue;
        }
        if (FUNCTION_UNLOCK_TYPE_SPECIAL == pUnlockCfg->m_openType)
        {
            continue;
        }
        //
        bool unlockFlag = CheckUnlock(level, ocGrade, opendays, viplevel, totalrmb, pMissionPart, *pUnlockCfg);
        //
        if (isFunctionUnlock(pUnlockCfg->m_functionId))
        {
            if (!unlockFlag)
            {
                delFlag = true;
                DelUnlock(pUnlockCfg->m_functionId);
            }
        }
        else if (unlockFlag)
        {
            vecAddLst.push_back(pUnlockCfg->m_functionId);
            AddUnlock(pUnlockCfg->m_functionId);
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
            unlockEvent.set_sync(true);
            FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), unlockEvent);
        }
    }
}

void NFFunctionUnlockPart::sendFunctionUnlockInfo(const VEC_UINT64 *pList)
{
    proto_ff::FunctionUnlockInfoRsp infoRsp;
    infoRsp.set_retcode(proto_ff::RET_SUCCESS);
    if (nullptr == pList)
    {
        //发送全部以解锁功能
        infoRsp.set_syntype(FUNCTION_SYNC_TYPE_ALL);
        for (auto &iter : m_mapUnLock)
        {
            auto pData = infoRsp.add_data();
            pData->set_unlockid(iter.first);
            pData->set_get_reward(iter.second);
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
    m_mapUnLock.emplace(unlockid, false);
    SetNeedSave(true);
}

bool NFFunctionUnlockPart::CheckALLFunctions(bool sync)
{
    auto mapUnlockCfg = FunctionunlockFunctionunlockDesc::Instance()->GetResDescPtr();
    if (nullptr == mapUnlockCfg)
    {
        return false;
    }
    
    NFMissionPart *pMissionPart = dynamic_cast<NFMissionPart *>(m_pMaster->GetPart(PART_MISSION));
    if (nullptr == pMissionPart)
    {
        return false;
    }
    
    //玩家等级
    int32_t level = (int32_t) m_pMaster->GetAttr(proto_ff::A_LEVEL);
    //转职等级
    int32_t ocGrade = (int32_t) GetOccupationGrade(0);
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
    for (auto iterator = mapUnlockCfg->begin(); iterator != mapUnlockCfg->end(); ++iterator)
    {
        auto &tInfo = iterator->second;
        if (FUNCTION_UNLOCK_TYPE_SPECIAL == tInfo.m_openType)
        {
            continue;
        }
        //
        bool unlockFlag = CheckUnlock(level, ocGrade, opendays, viplevel, totalrmb, pMissionPart, tInfo);
        //
        if (isFunctionUnlock(tInfo.m_functionId))
        {
            if (!unlockFlag)
            {
                delFlag = true;
                DelUnlock(tInfo.m_functionId);
            }
        }
        else if (unlockFlag)
        {
            vecAddLst.push_back(tInfo.m_functionId);
            AddUnlock(tInfo.m_functionId);
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
                unlockEvent.set_sync(sync);
                FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), unlockEvent);
            }
        }
    }
    else
    {
        if (vecAddLst.size() > 0)
        {
            for (auto &iteradd : vecAddLst)
            {
                //解锁事件
                //解锁事件
                proto_ff::FunctionUnlockEvent unlockEvent;
                unlockEvent.set_functionid(iteradd);
                unlockEvent.set_sync(sync);
                FireExecute(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), unlockEvent);
            }
        }
    }
    return true;
}

uint32_t NFFunctionUnlockPart::GetOccupationGrade(uint64_t occupationId)
{
    return 0;
}

bool NFFunctionUnlockPart::CheckUnlock(int32_t Lev, int32_t occupationLev, uint32_t opendays, int32_t viplev, int32_t totalrmb, NFMissionPart *pMissionPart, const proto_ff_s::E_FunctionunlockFunctionunlock_s &cfg)
{
    if ((int32_t) opendays < cfg.m_openDaily)
    {
        return false;
    }
    auto pDupPart = dynamic_cast<NFDupPart *>(m_pMaster->GetPart(PART_DUP));
    if (!pDupPart)
        return false;
    
    int32_t opentype = cfg.m_openType;
    int64_t openval = cfg.m_openVal;
    if (FUNCTION_UNLOCK_TYPE_LEVEL == opentype)
    {
        return ((int64_t) Lev >= openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_TAST == opentype)
    {
        if (nullptr == pMissionPart)
        {
            return false;
        }
        return pMissionPart->HaveSubmited(openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_TRANSFER == opentype)
    {
        return ((int64_t) occupationLev >= openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_PAYRMB == opentype)
    {
        return ((int64_t) totalrmb >= openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_VIP_LEV == opentype)
    {
        return ((int64_t) viplev >= openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_DUP == opentype)
    {
        return pDupPart->IsPassDup(openval);
    }
    else if (FUNCTION_UNLOCK_TYPE_GOD_EVIL == opentype)
    {
        NFGodEvilPart *pgodevil = dynamic_cast<NFGodEvilPart *>(m_pMaster->GetPart(PART_GODEVIL));
        if (nullptr != pgodevil)
            return pgodevil->IsActive();
    }
    else if (FUNCTION_UNLOCK_TYPE_BEST_EQ == opentype)
    {
        auto bestEQPart = dynamic_cast<NFBestEQPart *>(m_pMaster->GetPart(PART_BESTEQ));
        if (bestEQPart)
        {
            return bestEQPart->IsCmptTaskAll();
        }
    }
    else if (FUNCTION_UNLOCK_TYPE_MARRY_TASK == opentype)
    {
        auto marryPart = dynamic_cast<NFMarryPart *>(m_pMaster->GetPart(PART_MARRY));
        if (marryPart)
        {
            return marryPart->IsCmptTask();
        }
    }
    else if (FUNCTION_UNLOCK_TYPE_TURN_TASK == opentype)
    {
        auto turnPart = dynamic_cast<NFTurnPart *>(m_pMaster->GetPart(PART_TURN));
        if (turnPart)
        {
            return turnPart->IsCmptTaskAll();
        }
    }
    else if (FUNCTION_UNLOCK_TYPE_SOUL_TASK == opentype)
    {
        auto soulPart = dynamic_cast<NFSoulPart *>(m_pMaster->GetPart(PART_SOUL));
        if (soulPart)
        {
            return soulPart->IsCmptTaskAll();
        }
    }
    return false;
}

uint32_t NFFunctionUnlockPart::OpenDays()
{
    uint32_t zid = m_pMaster->GetZid();

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_EXPR(pConfig, 1, "");
    
    if (pConfig->IsMerged(zid))
    {
        //合服之后，不需要再判定开服天数了，为了逻辑上统一，合服之后开服天数返回一个很大的值
        return INT32_MAX;
    }
    
    return pConfig->GetDayFromOpen(zid);
}

int NFFunctionUnlockPart::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    switch (nEventID)
    {
        case EVENT_LEVELUP:
        {
            const proto_ff::PlayerLeveUpEvent *levelEvent = dynamic_cast<const proto_ff::PlayerLeveUpEvent *>(pMessage);
            CHECK_NULL(levelEvent);
            uint32_t nLevel = levelEvent->level();
            checkUnlock(FUNCTION_UNLOCK_TYPE_LEVEL, nLevel);
            break;
        }
        case EVENT_FINISH_TASK:
        {
            const proto_ff::FinishTaskEvent *taskEvent = dynamic_cast<const proto_ff::FinishTaskEvent *>(pMessage);
            CHECK_NULL(taskEvent);
            uint64_t taskId = taskEvent->taskid();
            checkUnlock(FUNCTION_UNLOCK_TYPE_TAST, taskId);
            break;
        }
        case EVENT_FACADE_CHANGE:
        {
            const proto_ff::ChangeFacadeEvent *facadeEvent = dynamic_cast<const proto_ff::ChangeFacadeEvent *>(pMessage);
            CHECK_NULL(facadeEvent);
            uint64_t occupationId = facadeEvent->occupationid();
            uint64_t octrade = GetOccupationGrade(occupationId);//转职等级
            checkUnlock(FUNCTION_UNLOCK_TYPE_TRANSFER, octrade);
            break;
        }
        case EVENT_PAY:
        {
            //todo need PayPart
            const proto_ff::PayEvent *pPayEvent = dynamic_cast<const proto_ff::PayEvent *>(pMessage);
            CHECK_NULL(pPayEvent);
            checkUnlock(FUNCTION_UNLOCK_TYPE_RECHARGE, pPayEvent->payindex());
            break;
        }
        case EVENT_VIP_UP:
        {
            checkUnlock(FUNCTION_UNLOCK_TYPE_VIP_LEV, (uint64_t) m_pMaster->GetAttr(proto_ff::A_VIP_LEVEL));
            break;
        }
        case EVENT_PASS_DUPLICATE:
        {
            const proto_ff::PassDupEvent *pPass = dynamic_cast<const proto_ff::PassDupEvent *>(pMessage);
            CHECK_NULL(pPass);
            
            uint64_t dupId = pPass->dupid();
            checkUnlock(FUNCTION_UNLOCK_TYPE_DUP, dupId);
            break;
        }
        case EVENT_GODE_EVIL_ACTIVE:
        {
            checkUnlock(FUNCTION_UNLOCK_TYPE_GOD_EVIL, 1);
            break;
        }
        case EVENT_BEQ_CMPT_TASK:
        {
            checkUnlock(FUNCTION_UNLOCK_TYPE_BEST_EQ, 1);
            break;
        }
        case EVENT_MARRY_CMPT_RECV_TASK:
        {
            checkUnlock(FUNCTION_UNLOCK_TYPE_MARRY_TASK, 1);
            break;
        }
        case EVENT_TURN_CMPT_TASK:
        {
            checkUnlock(FUNCTION_UNLOCK_TYPE_TURN_TASK, 1);
            break;
        }
        case EVENT_SOUL_CMPT_TASK:
        {
            checkUnlock(FUNCTION_UNLOCK_TYPE_SOUL_TASK, 1);
            break;
        }
        default:break;
    }
    return 0;
}
