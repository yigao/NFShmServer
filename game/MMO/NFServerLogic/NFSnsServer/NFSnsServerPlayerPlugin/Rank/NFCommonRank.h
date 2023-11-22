// -------------------------------------------------------------------------
//    @FileName         :    NFCommonRank.h
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommonRank
//
// -------------------------------------------------------------------------

#pragma once

#include <DBProxy2.pb.h>
#include <NFComm/NFShmStl/NFShmHashMap.h>
#include <NFComm/NFShmStl/NFShmMap.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFLogicCommon/NFLogicCommon.h>
#include <NFServerComm/NFServerCommon/NFDBGlobalTemplate.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

//排行榜最大容量
#define RANK_MAX_SIZE 100
//排行榜实际排名容量
#define RANK_REAL_SIZE 150
//世界等级取排行榜前几名平均值
#define RANK_WORLDLEVEL_RANK 5

class RankNode
{
public:
    uint64_t m_cid;
    uint64_t m_rank;
    NFShmVector<int64_t, 1> m_paramInt;
    NFShmVector<NFCommonStr, 1> m_paramStr;

    RankNode()
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

    RankNode(const RankNode& other)
    {
        if (this != &other)
        {
            CopyFrom(other);
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    void CopyFrom(const RankNode& other)
    {
        m_cid = other.m_cid;
        m_rank = other.m_rank;
        m_paramInt = other.m_paramInt;
        m_paramStr = other.m_paramStr;
    }

    RankNode& operator =(const RankNode& other)
    {
        if (this != &other)
        {
            CopyFrom(other);
        }
        return *this;
    }
};

class NFCommonRank : public NFDBGlobalTemplate<NFCommonRank, proto_ff::tbSnsRank, EOT_SNS_COMMON_RANK>
{
    typedef NFShmMultiMap<uint64_t, RankNode, RANK_REAL_SIZE, std::greater<uint64_t>> MapRankNode;
public:
    NFCommonRank();

    virtual ~NFCommonRank();

    int CreateInit();
    int ResumeInit();

public:
    int InitRank(uint32_t rankType);

public:
    virtual int LoadFromDB(const std::string& dbData);

    virtual int SaveToDB(std::string& dbData);

    virtual int InitConfig();

    virtual int GetDbId();
public:
    //更新节点
    bool UpdateNode(uint64_t charID, uint64_t nValue, const std::vector<int64_t>& paramIntVec, const std::vector<string>& paramStrVec);
    //获取列表
    MapRankNode* GetNodeList();
    //获取排名
    uint32_t GetRank(uint64_t cid);
    //删除节点
    bool DeleteNode(uint64_t cid);
protected:
    //获取最后一名的数值
    uint64_t GetLowestValue();
    //尝试添加新的玩家到排行榜，添加成功返回排名，失败返回0
    void TryToAddNewNode(uint64_t charID, uint64_t nValue, const std::vector<int64_t>& paramIntVec, const std::vector<string>& paramStrVec);
    //更新榜内玩家数据
    void UpdateNodeData(uint64_t charID, uint64_t nValue, const std::vector<int64_t>& paramIntVec, const std::vector<string>& paramStrVec);
    void EraseLowestValue();
protected:
    uint32_t m_rankType;
    MapRankNode m_rankData;
    NFShmHashMap<uint64_t, MapRankNode::iterator, RANK_REAL_SIZE> m_cidInRank;
};
