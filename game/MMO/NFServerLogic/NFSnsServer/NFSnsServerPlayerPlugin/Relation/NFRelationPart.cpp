// -------------------------------------------------------------------------
//    @FileName         :    NFFriendPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFFriendPart
//
// -------------------------------------------------------------------------

#include "NFRelationPart.h"
#include "ClientServerCmd.pb.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "Relation.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFLogicCommon/RelationDefine.h"
#include "Cache/NFRoleSimple.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRelationPart, EOT_SNS_RelationPart_ID, NFSnsPart)

NFRelationPart::NFRelationPart()
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

NFRelationPart::~NFRelationPart()
{
}

int NFRelationPart::CreateInit()
{
    return 0;
}

int NFRelationPart::ResumeInit()
{
    return 0;
}

int NFRelationPart::Init(const proto_ff::RoleDBSnsDetail &data)
{
    return 0;
}

int NFRelationPart::UnInit()
{
    return 0;
}

int NFRelationPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_CENTER_RELATION_DATA_REQ:
        {
            OnHandleRelationDataReq(msgId, packet);
            break;
        }
        default:
            break;
    }

    return 0;
}

int NFRelationPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFSnsPart::OnHandleServerMessage(msgId, packet);
}

int NFRelationPart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_CENTER_RELATION_DATA_REQ, SNS_PART_RELATION);
    return 0;
}

int NFRelationPart::RetisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFRelationPart::OnHandleRelationDataReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CWRelationDataReq relationInfoReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, relationInfoReq);

    //检查分组索引

    uint32_t groupIndex = relationInfoReq.groupindex();
    if (groupIndex >= GROUP_MAX)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_cid, "CWRelationInfoReq groupIndex is error. groupIndex:{}, CharID:{} ", groupIndex, m_cid);
        return -1;
    }

    auto pRoleSimple = GetRoleSimple();
    if (pRoleSimple == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_cid, "CWRelationInfoReq  pRoleSimple is nil. m_cid:{} ", m_cid);
        return -1;
    }

    proto_ff::WCRelationDataRsp relationInfoRsp;

    //发送数据到看客户端
    relationInfoRsp.set_groupindex(groupIndex);
    pRoleSimple->SendMsgToClient(proto_ff::CENTER_TO_CLIENT_RELATION_DATA_RSP, relationInfoRsp);
    return 0;
}

bool NFRelationPart::addGiftRecord(uint64_t targetId, uint64_t itemId, uint32_t sendType)
{
    return false;
}

bool NFRelationPart::AddFriend(uint64_t cid)
{
    auto pRelationPlayer = m_friendPlayerTeam.AddPlayer(cid);
    if (pRelationPlayer)
    {
        pRelationPlayer->closeness = 0;
        pRelationPlayer->todayCloseness = 0;
        pRelationPlayer->updateTime = NFTime::Now().UnixSec();
        MarkDirty();
        return true;
    }
    return false;
}

bool NFRelationPart::AddHate(uint64_t cid)
{
    auto pPlayer = m_hatePlayerTeam.GetPlayer(cid);
    if (pPlayer == NULL)
    {
        pPlayer = m_hatePlayerTeam.AddPlayer(cid);
    }

    if (pPlayer)
    {
        pPlayer->m_killMeTimes += 1;
        MarkDirty();
    }
    return false;
}

bool NFRelationPart::AddBlack(uint64_t cid)
{
    auto pRelationPlayer = m_blackPlayerTeam.AddPlayer(cid);
    if (pRelationPlayer)
    {
        MarkDirty();
        return true;
    }
    return false;
}

bool NFRelationPart::addRecent(uint64_t cid, uint32_t recentType)
{
    return false;
}

bool NFRelationPart::addApply(uint64_t cid, string sConnect)
{
    return false;
}

bool NFRelationPart::addShield(uint64_t cid)
{
    return false;
}

bool NFRelationPart::deleteRelation(uint32_t groupIndex, uint64_t cid)
{
    return false;
}

void NFRelationPart::deleteRelationByGroup(uint32_t groupIndex)
{

}

uint64_t NFRelationPart::delFront(uint32_t groupIndex)
{
    return 0;
}

bool NFRelationPart::isRelationExit(uint32_t groupIndex, uint64_t cid)
{
    return false;
}

uint32_t NFRelationPart::getLeftSize(uint32_t groupIndex)
{
    return 0;
}

uint32_t NFRelationPart::getMaxSize(uint32_t groupIndex)
{
    switch (groupIndex)
    {
        case GROUP_FRIEND:
        {
            return m_friendPlayerTeam.GetMaxSize();
        }
        case GROUP_BLACK:
        {
            return m_blackPlayerTeam.GetMaxSize();
        }
        case GROUP_HATE:
        {
            return m_hatePlayerTeam.GetMaxSize();
        }
        case GROUP_RECENT:
        {
            return m_recentPlayerTeam.GetMaxSize();
        }
        case GROUP_APPLY:
        {
            return m_applyPlayerTeam.GetMaxSize();
        }
        case GROUP_SHIELD:
        {
            return m_shieldPlayerTeam.GetMaxSize();
        }
        default:
            break;
    }

    return 0;
}

uint32_t NFRelationPart::getCurSize(uint32_t groupIndex)
{
    switch (groupIndex)
    {
        case GROUP_FRIEND:
        {
            return m_friendPlayerTeam.GetSize();
        }
        case GROUP_BLACK:
        {
            return m_blackPlayerTeam.GetSize();
        }
        case GROUP_HATE:
        {
            return m_hatePlayerTeam.GetSize();
        }
        case GROUP_RECENT:
        {
            return m_recentPlayerTeam.GetSize();
        }
        case GROUP_APPLY:
        {
            return m_applyPlayerTeam.GetSize();
        }
        case GROUP_SHIELD:
        {
            return m_shieldPlayerTeam.GetSize();
        }
        default:
            break;
    }

    return 0;
}

bool NFRelationPart::GetRelationIdList(uint32_t groupIndex, std::list<uint64_t> &ids, uint32_t limitCount)
{
    return false;
}

bool NFRelationPart::AddFriendCloseness(uint64_t cid, uint32_t type, uint64_t param)
{
    return false;
}

int32_t NFRelationPart::getFriendCloseness(uint64_t destId)
{
    return 0;
}

uint32_t NFRelationPart::getFriendClosenessLv(uint64_t destId)
{
    return 0;
}

bool NFRelationPart::InCdTime()
{
    return false;
}

uint32_t NFRelationPart::GetFriendsAdd()
{
    return 0;
}

void NFRelationPart::AddFriendsAdd()
{

}

void NFRelationPart::SetFriendsAdd(uint32_t value)
{

}

void NFRelationPart::AddActive()
{

}

uint32_t NFRelationPart::GetActive()
{
    return 0;
}

NFRelationCommonPlayer *NFRelationPart::GetPlayer(uint32_t groupIndex, uint64_t destId)
{
    return nullptr;
}

uint64_t NFRelationPart::GetStartRobotId()
{
    return 0;
}

bool NFRelationPart::setThanksGift(uint32_t recordId)
{
    return false;
}
