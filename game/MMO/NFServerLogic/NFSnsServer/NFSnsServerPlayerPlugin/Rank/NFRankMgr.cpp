// -------------------------------------------------------------------------
//    @FileName         :    NFRankMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankMgr
//
// -------------------------------------------------------------------------

#include "NFRankMgr.h"

#include <Rank.pb.h>
#include <Cache/NFCacheMgr.h>
#include <DescStore/RankingRankingDesc.h>
#include <Faction/NFFactionMgr.h>
#include <NFComm/NFCore/NFCommonApi.h>
#include <NFServerComm/NFServerCommon/NFDBObjMgr.h>
#include "AllProtocol.h"

NFRankMgr::NFRankMgr()
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

NFRankMgr::~NFRankMgr()
{
}

int NFRankMgr::CreateInit()
{
    return 0;
}

int NFRankMgr::ResumeInit()
{
    return 0;
}

int NFRankMgr::RegisterMessage()
{
    RegisterServerMessage(proto_ff::LOGIC_TO_CENTER_UPDATERANK);
    RegisterServerMessage(proto_ff::LOGIC_TO_CENTER_RANKDATA, true);
    return 0;
}

int NFRankMgr::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFRankMgr::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::LOGIC_TO_CENTER_RANKDATA:
        {
            OnRankInfoReq(msgId, packet);
            break;
        }
        case proto_ff::LOGIC_TO_CENTER_UPDATERANK:
        {
            OnUpdateRankReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFRankMgr::OnUpdateRankReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::GWUpdateRankReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    if (req.value() <= 0)
    {
        return 0;
    }

    //更新
    UpdateRankData(req);
    return 0;
}

void NFRankMgr::UpdateRankData(uint32_t nType, uint64_t charID, uint64_t nValue)
{
    auto pRank = GetRankList(nType);
    if (nullptr == pRank)
    {
        NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankManager::UpdateRankData no this type rank ranktype:{}", nType);
        return;
    }
    if (nValue <= 0)
        return;
    std::vector<int64_t> vecInt;
    std::vector<string> vecStr;
    pRank->UpdateNode(charID, nValue, vecInt, vecStr);
}

int NFRankMgr::SendRankData(uint32_t nType, uint64_t charID, uint64_t selfValue, uint64_t unionId)
{
    proto_ff::RankDataResponse rankInfoRsp;
    auto pMySimpeData = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(charID);
    CHECK_NULL(pMySimpeData);

    proto_ff::RankDataInfo* rankInfo = rankInfoRsp.mutable_info();
    auto pRank = GetRankList(nType);
    if (nullptr == pRank)
    {
        NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankManager::GetRankData pRank is nil ranktype:{}", nType);
        return -1;
    }
    //排名数据
    auto pRankData = pRank->GetNodeList();
    if (nullptr == pRankData)
    {
        NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankManager::GetRankData pRank is nil ranktype:{}", nType);
        return -1;
    }

    //设置数据
    rankInfo->set_ranktype(nType);
    rankInfo->set_selfrank(0);
    uint32_t nRank = 1;
    std::set<uint64_t> needDelete;

    for (auto iter = pRankData->begin(); iter != pRankData->end(); ++iter)
    {
        if (nRank > RANK_MAX_SIZE)
        {
            break;
        }
        //设置节点数据
        if (nType == RANK_TYPE_GUILD)
        {
            //检查工会是否还在
            auto pUnion = NFSnsFactionMgr::Instance(m_pObjPluginManager)->GetFaction(iter->second.m_cid);
            if (nullptr == pUnion)
            {
                needDelete.insert(iter->second.m_cid);
                NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankManager::SendRankData pUnion is nil delete from rank.....unionId:{}", iter->second.m_cid);
                continue;
            }

            if (iter->second.m_cid == unionId)
            {
                rankInfo->set_selfrank(nRank);
            }

            auto pRankNode = rankInfo->add_ranklist();
            //检查玩家是否还在
            auto pLeaderCharacterData = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(charID, pUnion->LeaderCid());
            if (pLeaderCharacterData)
            {
                if (nRank == 1)
                {
                    pRankNode->set_fight(pLeaderCharacterData->Fight());
                    pRankNode->set_name(pLeaderCharacterData->GetName());
                    pRankNode->mutable_facade()->CopyFrom(pLeaderCharacterData->FacadeToPB());
                }
            }

            SetRankNodeProtoByUnionId(pRankNode, nType, nRank, iter->second.m_cid, iter->first);
        }
        else
        {
            //检查玩家是否还在
            auto pOfflineCharacterData = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(charID, iter->second.m_cid);
            if (nullptr == pOfflineCharacterData)
            {
                needDelete.insert(iter->second.m_cid);
                NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankManager::SendRankData pOfflineCharacterData is nil delete from rank.....charID:%lu", iter->second.m_cid);
                continue;
            }
            if (iter->second.m_cid == charID)
            {
                rankInfo->set_selfrank(nRank);
            }
            auto pRankNode = rankInfo->add_ranklist();
            pRankNode->set_online(pOfflineCharacterData->IsOnline());
            if (nRank == 1)
            {
                pRankNode->set_fight(pOfflineCharacterData->Fight());
                pRankNode->set_name(pOfflineCharacterData->GetName());
                pRankNode->mutable_facade()->CopyFrom(pOfflineCharacterData->FacadeToPB());
            }
            SetRankNodeProtoByCharId(pRankNode, nType, nRank, iter->second.m_cid, iter->first);
        }
        ++nRank;
    }
    //设置自己的数据
    auto pSelfNode = rankInfo->mutable_selfdata();
    SetRankNodeProtoByCharId(pSelfNode, nType, rankInfo->selfrank(), charID, selfValue);

    //发送数据
    pMySimpeData->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_RANK_DATA_RSP, rankInfoRsp);

    //删除没有数据的
    for (auto iter = needDelete.begin(); iter != needDelete.end(); ++iter)
    {
        pRank->DeleteNode(*iter);
    }

    return 0;
}

void NFRankMgr::UpdateRankData(const proto_ff::GWUpdateRankReq& req)
{
    uint32_t nType = req.ranktype();
    uint64_t charID = req.charid();
    uint64_t nValue = req.value();
    auto pRank = GetRankList(nType);
    if (nullptr == pRank)
    {
        NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankManager::UpdateRankData no this type rank ranktype:{}", nType);
        return;
    }
    if (nValue <= 0)
        return;

    std::vector<int64_t> vecInt;
    std::vector<string> vecStr;
    for (int i = 0; i < (int)req.paramint_size(); i++)
    {
        vecInt.push_back(req.paramint(i));
    }

    for (int i = 0; i < (int)req.paramstr_size(); i++)
    {
        vecStr.push_back(req.paramstr(i));
    }

    pRank->UpdateNode(charID, nValue, vecInt, vecStr);
}

bool NFRankMgr::SetRankNodeProtoByUnionId(proto_ff::RankNodeData* pNode, uint32_t rankType, uint32_t rank, uint64_t unionID, uint64_t value)
{
    if (nullptr == pNode)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] RankManager::SetRankNodeProtoByUnionId pNode is nil ranktype:%d,unionID:%lu", rankType, unionID);
        return false;
    }

    //显示数据配置
    auto pConfig = RankingRankingDesc::Instance()->GetDesc(rankType);
    if (nullptr == pConfig)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] RankManager::SetRankNodeProtoByUnionId pConfig is nil ranktype:%d,unionID:%lu", rankType, unionID);
        return false;
    }

    auto pUnion = NFSnsFactionMgr::Instance(m_pObjPluginManager)->GetFaction(unionID);
    if (nullptr == pUnion)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[center] RankManager::SetRankNodeProtoByUnionId pUnion is nil ranktype:%d,unionID:%lu", rankType, unionID);
        return false;
    }
    //设置节点数据
    pNode->set_cid(pUnion->LeaderCid());

    for (uint32_t i = 0; i < pConfig->m_dateID.size(); ++i)
    {
        uint32_t nType = pConfig->m_dateID[i];
        switch (nType)
        {
            case RANK_PLAYER_PARAM_GUILD_RANK:
            {
                pNode->add_sparam(NFCommon::tostr(rank)); //
                break;
            }
            case RANK_PLAYER_PARAM_GUILD_NAME: //工会名字
            {
                pNode->add_sparam(pUnion->Name());
                break;
            }
            case RANK_PLAYER_PARAM_GUILD_LEVEL: //9帮派等级
            {
                pNode->add_sparam(NFCommon::tostr(pUnion->Level()));
                break;
            }
            //排行数值，直接用传进来的值
            case RANK_PLAYER_PARAM_POWER:
            case RANK_PLAYER_PARAM_LEVEL:
            case RANK_PLAYER_PARAM_GUILD_POWER:
            {
                pNode->add_sparam(NFCommon::tostr(value));
                break;
            }
            default:
                pNode->add_sparam("0");
                break;
        }
    }
    return true;
}

bool NFRankMgr::SetRankNodeProtoByCharId(proto_ff::RankNodeData* pNode, uint32_t rankType, uint32_t rank, uint64_t charID, uint64_t value)
{
    if (nullptr == pNode)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] RankManager::SetRankNodeProtoByCharId pNode is nil ranktype:%d", rankType);
        return false;
    }
    //显示数据配置
    auto pConfig = RankingRankingDesc::Instance()->GetDesc(rankType);
    if (nullptr == pConfig)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[center] RankManager::SetRankNodeProtoByCharId pConfig is nil ranktype:%d", rankType);
        return false;
    }
    //玩家离线数据
    auto pOfflineCharacterData = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(charID);
    if (nullptr == pOfflineCharacterData)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[center] RankManager::SetRankNodeProtoByCharId pOfflineCharacterData is nil ranktype:%d,charID:%lu", rankType, charID);
        return false;
    }

    //设置节点数据
    pNode->set_cid(charID);
    pNode->set_viplevel(pOfflineCharacterData->VipLevel());

    for (uint32_t i = 0; i < pConfig->m_dateID.size(); ++i)
    {
        uint32_t nType = pConfig->m_dateID.at(i);
        switch (nType)
        {
            case RANK_PLAYER_PARAM_RANK:
            {
                pNode->add_sparam(NFCommon::tostr(rank));
                break;
            }
            case RANK_PLAYER_PARAM_NAME: //玩家名字
            {
                pNode->add_sparam(pOfflineCharacterData->GetName());
                break;
            }
            case RANK_PLAYER_PARAM_JOB: //玩家名字
            {
                pNode->add_sparam(NFCommon::tostr(pOfflineCharacterData->Prof()));
                break;
            }
            case RANK_PLAYER_PARAM_GUILD_NAME: //工会名字
            {
                pNode->add_sparam(NFSnsFactionMgr::Instance(m_pObjPluginManager)->GetFactionNameByCid(charID));
                break;
            }
            case RANK_PLAYER_PARAM_PT_STAGE: //4玩家修真境界
            {
                pNode->add_sparam(NFCommon::tostr(pOfflineCharacterData->PtStage()));
                break;
            }
            default:
                pNode->add_sparam(NFCommon::tostr(value));
                break;
        }
    }
    return true;
}

int NFRankMgr::LoadFromDB(const std::string& dbData)
{
    return 0;
}

int NFRankMgr::SaveToDB(std::string& dbData)
{
    return 0;
}

int NFRankMgr::InitConfig()
{
    MarkDirty();
    return 0;
}

int NFRankMgr::LoadAllRank()
{
    m_rankData[RANK_TYPE_POWER] = CreateRankList(RANK_TYPE_POWER);
    m_rankData[RANK_TYPE_LEVEL] = CreateRankList(RANK_TYPE_LEVEL);
    m_rankData[RANK_TYPE_GUILD] = CreateRankList(RANK_TYPE_GUILD);
    m_rankData[RANK_TYPE_EQUIP] = CreateRankList(RANK_TYPE_EQUIP);
    m_rankData[RANK_TYPE_XIUZHEN] = CreateRankList(RANK_TYPE_XIUZHEN);
    m_rankData[RANK_TYPE_FANGREN_XIUZHEN] = CreateRankList(RANK_TYPE_FANGREN_XIUZHEN);
    m_rankData[RANK_TYPE_BATTLE_PASS_XIANCE] = CreateRankList(RANK_TYPE_BATTLE_PASS_XIANCE);
    m_rankData[RANK_TYPE_BATTLE_PASS_BAODING] = CreateRankList(RANK_TYPE_BATTLE_PASS_BAODING);
    m_rankData[RANK_TYPE_PET_FIGHT] = CreateRankList(RANK_TYPE_PET_FIGHT);
    m_rankData[RANK_TYPE_MOUNT_FIGHT] = CreateRankList(RANK_TYPE_MOUNT_FIGHT);
    m_rankData[RANK_TYPE_YUANMAO_SUM] = CreateRankList(RANK_TYPE_YUANMAO_SUM);
    m_rankData[RANK_TYPE_WING_FIGHT] = CreateRankList(RANK_TYPE_WING_FIGHT);
    m_rankData[RANK_TYPE_BAOSHI_LEVEL] = CreateRankList(RANK_TYPE_BAOSHI_LEVEL);
    m_rankData[RANK_TYPE_MARRY_VALUE] = CreateRankList(RANK_TYPE_MARRY_VALUE);
    m_rankData[RANK_TYPE_DEITY_FIGHT] = CreateRankList(RANK_TYPE_DEITY_FIGHT);
    m_rankData[RANK_TYPE_BEAST_FIGHT] = CreateRankList(RANK_TYPE_BEAST_FIGHT);
    m_rankData[RANK_TYPE_BIAOBAI_VALUE] = CreateRankList(RANK_TYPE_BIAOBAI_VALUE);
    m_rankData[RANK_TYPE_MEILI_VALUE] = CreateRankList(RANK_TYPE_MEILI_VALUE);
    m_rankData[RANK_TYPE_ANQI_FIGHT] = CreateRankList(RANK_TYPE_ANQI_FIGHT);
    m_rankData[RANK_TYPE_LINGJIA_FIGHT] = CreateRankList(RANK_TYPE_LINGJIA_FIGHT);

    for (auto iter = m_rankData.begin(); iter != m_rankData.end(); iter++)
    {
        NFDBObjMgr::Instance(m_pObjPluginManager)->LoadFromDB(iter->second.GetPoint());
    }
    return 0;
}

NFCommonRank* NFRankMgr::CreateRankList(uint32_t nType)
{
    auto pRank = GetRankList(nType);
    if (pRank)
    {
        return pRank;
    }
    
    pRank = NFCommonRank::CreateObj(m_pObjPluginManager);
    CHECK_EXPR(pRank, NULL, "CreateRankList Failed, nType:{}", nType);
    pRank->InitRank(nType);
    return pRank;
}

NFCommonRank* NFRankMgr::GetRankList(uint32_t nType)
{
    auto iter = m_rankData.find(nType);
    if (iter != m_rankData.end())
    {
        return iter->second.GetPoint();
    }
    return NULL;
}

int NFRankMgr::OnRankInfoReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::GWRankDataReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    uint64_t unionId = NFSnsFactionMgr::Instance(m_pObjPluginManager)->RoleFactionId(req.charid());
    if (req.ranktype() == RANK_TYPE_GUILD)
    {
        auto pFaction = NFSnsFactionMgr::Instance(m_pObjPluginManager)->GetFaction(unionId);
        if (pFaction)
        {
            uint64_t nFight = pFaction->Fight();
            req.set_value(nFight);
        }
        else
        {
            req.set_value(0);
        }
    }
    //发送数据
    SendRankData(req.ranktype(), req.charid(), req.value(), unionId);
    return 0;
}
