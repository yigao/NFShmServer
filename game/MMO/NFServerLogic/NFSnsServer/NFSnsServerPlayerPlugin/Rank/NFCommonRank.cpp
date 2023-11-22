// -------------------------------------------------------------------------
//    @FileName         :    NFCommonRank.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommonRank
//
// -------------------------------------------------------------------------

#include "NFCommonRank.h"

#include <Cache/NFCacheMgr.h>
#include <Faction/NFFactionMgr.h>
#include <NFLogicCommon/NFRankDefine.h>

NFCommonRank::NFCommonRank()
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

NFCommonRank::~NFCommonRank()
{
}

int NFCommonRank::CreateInit()
{
    m_iServerType = NF_ST_SNS_SERVER;
    m_rankType = 0;
    return 0;
}
    
int NFCommonRank::ResumeInit()
{
    return 0;
}

int NFCommonRank::LoadFromDB(const std::string& dbData)
{
    proto_ff::RankTypeDBData rankData;
    bool ok = rankData.ParseFromString(dbData);
    CHECK_EXPR(ok, -1, "Parse Failed, rankType", m_rankType);
    CHECK_EXPR(rankData.ranktype() == (int)m_rankType, -1, "Parse Error, pb rank type:{} != rank type:{}", rankData.ranktype(), m_rankType);

    for (int32_t i = 0; i < rankData.nodelist_size(); ++i)
    {
        const proto_ff::RankNodeDBData& tNode = rankData.nodelist(i);
        std::vector<int64_t> vecInt;
        std::vector<string> vecStr;
        for(int j = 0; j < (int)tNode.paramint_size(); j++)
        {
            vecInt.push_back(tNode.paramint(j));
        }

        for(int j = 0; j < (int)tNode.paramstr_size(); j++)
        {
            vecStr.push_back(tNode.paramstr(j));
        }
        TryToAddNewNode(tNode.cid(), tNode.value(), vecInt, vecStr);
    }
    return 0;
}

int NFCommonRank::SaveToDB(std::string& dbData)
{
    proto_ff::RankTypeDBData rankData;
    rankData.set_ranktype(m_rankType);
    for (auto iter = m_rankData.begin(); iter != m_rankData.end(); ++iter)
    {
        auto& data = iter->second;
        proto_ff::RankNodeDBData* pNode = rankData.add_nodelist();
        if (pNode)
        {
            pNode->set_cid(data.m_cid);
            pNode->set_value(iter->first);
            for(int i = 0; i < (int)data.m_paramInt.size(); i++)
            {
                pNode->add_paramint(data.m_paramInt[i]);
            }
            for(int i = 0; i < (int)data.m_paramStr.size(); i++)
            {
                pNode->add_paramstr(data.m_paramStr[i].data());
            }
        }
    }

    return 0;
}

int NFCommonRank::InitConfig()
{
    MarkDirty();
    return 0;
}

int NFCommonRank::GetDbId()
{
    return m_rankType;
}

uint64_t NFCommonRank::GetLowestValue()
{
    if (m_rankData.size() == 0)
    {
        return 0;
    }
    auto iter = m_rankData.rbegin();
    return iter->first;
}

void NFCommonRank::TryToAddNewNode(uint64_t charID, uint64_t nValue, const std::vector<int64_t>& paramIntVec, const std::vector<string>& paramStrVec)
{
    if (nValue > 1000000000000000) return;
    //排行榜已满 且 值比最小值还小  则不能进榜
    if (m_rankData.size() >= RANK_REAL_SIZE)
    {
        if (nValue <= GetLowestValue())
        {
            return;
        }
        else
        {
            EraseLowestValue();
        }
    }
    RankNode tNode;
    tNode.m_cid = charID;
    tNode.m_paramInt = paramIntVec;
    tNode.m_paramStr.insert(tNode.m_paramStr.end(), paramStrVec.begin(), paramStrVec.end());
    //保存排行榜数据
    auto insert_iter = m_rankData.insert(std::make_pair(nValue, tNode));
    //保存查询数据
    m_cidInRank.insert(std::make_pair(charID, insert_iter));
    MarkDirty();
}

void NFCommonRank::UpdateNodeData(uint64_t charID, uint64_t nValue, const std::vector<int64_t>& paramIntVec, const std::vector<string>& paramStrVec)
{
    DeleteNode(charID);
    TryToAddNewNode(charID, nValue, paramIntVec, paramStrVec);
}

void NFCommonRank::EraseLowestValue()
{
    if (m_rankData.size() <= 0) return;

    auto iter = m_rankData.end();
    iter--;
    m_cidInRank.erase(iter->second.m_cid);
    m_rankData.erase(iter);
}

bool NFCommonRank::DeleteNode(uint64_t cid)
{
    auto iter = m_cidInRank.find(cid);
    if (iter != m_cidInRank.end())
    {
        //删除排行数据
        auto rank_iter = iter->second;
        assert(rank_iter->second.m_cid == cid);
        m_rankData.erase(rank_iter);
    }
    //删除查询数据
    m_cidInRank.erase(cid);
    MarkDirty();
    return true;
}

bool NFCommonRank::UpdateNode(uint64_t charID, uint64_t nValue, const std::vector<int64_t>& paramIntVec, const std::vector<string>& paramStrVec)
{
    //1玩家离线数据
    if (m_rankType != RANK_TYPE_GUILD)
    {
        auto pSimpleData = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(charID);
        if (nullptr == pSimpleData)
        {
            NFLogError(NF_LOG_SYSTEMLOG, charID, "[center] RankList::UpdateNode failed...no offlinedata...charID:{}", charID);
            return false;
        }
    }
    //2.检查是否是榜内玩家
    auto iter = m_cidInRank.find(charID);
    if (iter == m_cidInRank.end())
    {
        //榜外玩家尝试加入
        TryToAddNewNode(charID, nValue, paramIntVec, paramStrVec);
    }
    else
    {
        //更新榜内玩家
        UpdateNodeData(charID, nValue, paramIntVec, paramStrVec);
    }
    return true;
}

NFCommonRank::MapRankNode* NFCommonRank::GetNodeList()
{
    return &m_rankData;
}

int NFCommonRank::InitRank(uint32_t rankType)
{
    m_rankType = rankType;
    return 0;
}
