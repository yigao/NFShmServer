// -------------------------------------------------------------------------
//    @FileName         :    NFGodRelicsPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFGodRelicsPart
//
// -------------------------------------------------------------------------

#include "NFGodRelicsPart.h"
#include "MiniActivity.pb.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "Package/NFPackagePart.h"
#include "proto_svr_event.pb.h"
#include "DescStore/GodrelicsGodrelicsDesc.h"
#include "Skill/NFSkillPart.h"
#include "Player/NFFunctionUnlockPart.h"

NFGodRelicsPart::NFGodRelicsPart()
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

NFGodRelicsPart::~NFGodRelicsPart()
{
}

int NFGodRelicsPart::CreateInit()
{
    m_curGroupId = 0;
    return 0;
}

int NFGodRelicsPart::ResumeInit()
{
    return 0;
}

int NFGodRelicsPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFGodRelicsPart::UnInit()
{
    return NFPart::UnInit();
}

int NFGodRelicsPart::LoadFromDB(const proto_ff::RoleDBData &data)
{
    auto &god_relics = data.mini_activity().god_relics_data();
    for (int i = 0; i < (int) god_relics.group_data_size(); i++)
    {
        const ::proto_ff::GodRelicsTaskGroupEntry &groupData = god_relics.group_data(i);
        auto pGroup = &m_groupMap[groupData.group_cfg_id()];
        pGroup->ReadFromPB(groupData);
    }
    m_curGroupId = god_relics.cur_group_id();
    return 0;
}

int NFGodRelicsPart::InitConfig(const proto_ff::RoleDBData &data)
{
    auto pCfgMap = GodrelicsConditionDesc::Instance()->GetResDescPtr();
    for (auto iter = pCfgMap->begin(); iter != pCfgMap->end(); iter++)
    {
        auto &refCfg = iter->second;
        auto pGroupData = GetGroup(refCfg.m_group);
        if (pGroupData == NULL)
        {
            pGroupData = InsertGroup(refCfg.m_group);
            if (pGroupData == NULL)
            {
                return -1;
            }
        }
        
        pGroupData->addTask(refCfg.m_id, refCfg.m_count);
    }
    
    if (m_curGroupId <= 0)
    {
        for (auto iter = m_groupMap.begin(); iter != m_groupMap.end(); iter++)
        {
            if (m_curGroupId <= 0)
            {
                m_curGroupId = iter->first;
            }
            else
            {
                if (iter->first < m_curGroupId)
                {
                    m_curGroupId = iter->first;
                }
            }
        }
        
        auto pCurGroup = GetGroup(m_curGroupId);
        if (pCurGroup == NULL)
        {
            return -1;
        }
        
        pCurGroup->normal_reward_state = proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_NOT_FINISH;
    }
    
    SetNeedSave(true);
    return 0;
}

int NFGodRelicsPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    auto pGodInfo = dbData.mutable_mini_activity()->mutable_god_relics_data();
    pGodInfo->set_cur_group_id(m_curGroupId);
    for (auto iter = m_groupMap.begin(); iter != m_groupMap.end(); iter++)
    {
        auto pGroupData = pGodInfo->add_group_data();
        if (pGroupData)
        {
            iter->second.WriteToPB(pGroupData);
        }
    }
    return 0;
}

int NFGodRelicsPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_GET_GOD_RELICS_INFO_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_GET_GOD_RELICS_TASK_REWARD_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_GET_GOD_RELICS_GROUP_TASK_REWARD_REQ);
    return 0;
}

int NFGodRelicsPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_GET_GOD_RELICS_INFO_REQ:
        {
            OnHandleGetGodRelicsInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_GET_GOD_RELICS_TASK_REWARD_REQ:
        {
            OnHandleGetGodRelicsTaskReward(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_GET_GOD_RELICS_GROUP_TASK_REWARD_REQ:
        {
            OnHandleGetGodRelecsGroupTaskReward(msgId, packet);
            break;
        }
        default:
        {
            break;
        }
    }
    return 0;
}

int NFGodRelicsPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

stGodRelicsTaskGroupEntry *NFGodRelicsPart::GetGroup(int64_t groupId)
{
    auto iter = m_groupMap.find(groupId);
    if (iter != m_groupMap.end())
    {
        return &iter->second;
    }
    return NULL;
}

stGodRelicsTaskGroupEntry *NFGodRelicsPart::InsertGroup(int64_t groupId)
{
    m_groupMap[groupId] = stGodRelicsTaskGroupEntry(groupId);
    return &m_groupMap[groupId];
}

stGodRelicsTaskEntry *NFGodRelicsPart::GetTask(int64_t groupId, int64_t taskId)
{
    auto pGroup = GetGroup(groupId);
    if (pGroup)
    {
        return pGroup->getTask(taskId);
    }
    
    return NULL;
}

bool NFGodRelicsPart::IsPrevFinish(int64_t groupId, int64_t taskId)
{
    auto pTaskEntryCfg = GodrelicsConditionDesc::Instance()->GetDesc(taskId);
    if (pTaskEntryCfg && pTaskEntryCfg->m_determine == 0)
    {
        return true;
    }
    
    if (m_curGroupId != groupId)
    {
        return false;
    }
    
    auto pGroup = GetGroup(groupId);
    if (pGroup)
    {
        for (auto iter = pGroup->task_map.begin(); iter != pGroup->task_map.end(); iter++)
        {
            if (iter->first < taskId)
            {
                if (iter->second.task_state != proto_ff::EN_GODRELICS_TASK_STATUS_GET_REWARD)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

bool NFGodRelicsPart::IsFinishGroup(int64_t groupId)
{
    auto pGroup = GetGroup(groupId);
    if (pGroup)
    {
        return pGroup->normal_reward_state == proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_GET_REWARD;
    }
    return false;
}

int NFGodRelicsPart::OnHandleGetGodRelicsInfo(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::GetGodRelicsInfoReq msgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, msgReq);
    
    proto_ff::GetGodRelicsInfoRsp rsp;
    rsp.set_cur_group_id(m_curGroupId);
    for (auto iter = m_groupMap.begin(); iter != m_groupMap.end(); iter++)
    {
        iter->second.WriteToPB(rsp.add_group_data());
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_INFO_RSP, rsp);
    return 0;
}

int NFGodRelicsPart::OnHandleGetGodRelicsTaskReward(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::GetGodRelicsTaskRewardReq msgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, msgReq);
    
    proto_ff::GetGodRelicsTaskRewardRsp rsp;
    rsp.set_ret_code(proto_ff::RET_FAIL);
    rsp.set_task_id(msgReq.task_id());
    
    auto pTaskEntryCfg = GodrelicsConditionDesc::Instance()->GetDesc(msgReq.task_id());
    if (pTaskEntryCfg == NULL)
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    if (m_curGroupId != msgReq.group_id())
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    auto pGroup = GetGroup(msgReq.group_id());
    auto pTask = GetTask(msgReq.group_id(), msgReq.task_id());
    if (pTask == NULL || pGroup == NULL)
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    if (pTask->task_state != proto_ff::EN_GODRELICS_TASK_STATUS_FINISH)
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    NFPackagePart *pPackage = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackage);
    
    SCommonSource sourceParam;
    sourceParam.src = S_GodRelics;
    LIST_ITEM lstItem;
    
    SItem item(pTaskEntryCfg->m_rewardItem, pTaskEntryCfg->m_rewardNumber, EBindState::EBindState_no);
    lstItem.push_back(item);
    
    if (!pPackage->AddItem(lstItem, sourceParam, true, true))
    {
        rsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    pTask->task_state = proto_ff::EN_GODRELICS_TASK_STATUS_GET_REWARD;
    SetNeedSave(true);
    pGroup->WriteToPB(rsp.mutable_group_data());
    
    proto_ff::GodRelicsFinish event;
    event.set_id(pTask->task_cfg_id);
    FireExecute(NF_ST_LOGIC_SERVER, EVENT_GOD_RELICS_FINISH, CREATURE_PLAYER, m_pMaster->Cid(), event);
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_TASK_REWARD_RSP, rsp);
    
    if (pGroup->isFinish())
    {
        pGroup->normal_reward_state = proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_FINISH;
        SetNeedSave(true);
        proto_ff::UpdateGodRelecsNotify notify;
        pGroup->WriteToPB(notify.mutable_group_data());
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_UPDATE_GOD_RELICS_NOTIFY, notify);
        
    }
    return 0;
}

int NFGodRelicsPart::OnHandleGetGodRelecsGroupTaskReward(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::GetGodRelecsGroupTaskRewardReq msgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, msgReq);
    
    proto_ff::GetGodRelecsGroupTaskRewardRsp rsp;
    rsp.set_ret_code(proto_ff::RET_FAIL);
    
    if (m_curGroupId != msgReq.group_id())
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_GROUP_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    auto pGroup = GetGroup(msgReq.group_id());
    if (pGroup == NULL)
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_GROUP_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    if (pGroup->normal_reward_state != proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_FINISH)
    {
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_GROUP_TASK_REWARD_RSP, rsp);
        return 0;
    }
    
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    pGroup->normal_reward_state = proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_GET_REWARD;
    pGroup->WriteToPB(rsp.mutable_old_group_data());
    SetNeedSave(true);
    int64_t srcGroupId = m_curGroupId;
    
    auto pNewGroup = GetGroup(m_curGroupId + 1);
    if (pNewGroup)
    {
        m_curGroupId = m_curGroupId + 1;
        pNewGroup->normal_reward_state = proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_NOT_FINISH;
        SetNeedSave(true);
        pNewGroup->WriteToPB(rsp.mutable_new_group_data());
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_GET_GOD_RELICS_GROUP_TASK_REWARD_RSP, rsp);
    
    auto pGroupInfo = GodrelicsGodrelicsDesc::Instance()->GetDesc(srcGroupId);
    if (pGroupInfo)
    {
        //add skill
        NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
        if (pSkillPart)
        {
            SCommonSource src;
            src.src = S_GodRelics;
            pSkillPart->AddSkill(pGroupInfo->m_skillID, 1, src, true);
        }
        
        NFFunctionUnlockPart *pFunctionPart = dynamic_cast<NFFunctionUnlockPart *>(m_pMaster->GetPart(PART_FUNCTIONUNLOCK));
        if (pFunctionPart != NULL)
        {
            if (pGroupInfo->m_functionId > 0 && !pFunctionPart->isFunctionUnlock(pGroupInfo->m_functionId))
            {
                pFunctionPart->UnlockSendAdd(pGroupInfo->m_functionId);
            }
        }
    }
    
    proto_ff::GodRelicsFinish event;
    event.set_id(pGroup->group_cfg_id);
    FireExecute(NF_ST_LOGIC_SERVER, EVENT_GOD_RELICS_GROUP_FINISH, CREATURE_PLAYER, m_pMaster->Cid(), event);
    return 0;
}
