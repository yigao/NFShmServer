// -------------------------------------------------------------------------
//    @FileName         :    NFRankMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <Rank.pb.h>
#include <NFComm/NFShmCore/NFShmPtr.h>
#include <NFComm/NFShmStl/NFShmHashMap.h>
#include <NFLogicCommon/NFRankDefine.h>
#include <ObService/NFSnsObService.h>

#include "NFCommonRank.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFRankMgr : public NFShmObjTemplate<NFRankMgr, EOT_SNS_SERVICE_ID+SNS_OB_SERVICE_RANK, NFSnsObService>
{
public:
    NFRankMgr();
    
    virtual ~NFRankMgr();
    
    int CreateInit();
    int ResumeInit();
public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet);
public:
    //请求更新排行榜
    int OnUpdateRankReq(uint32_t msgId, NFDataPackage& packet);
    //请求排行榜数据
    int OnRankInfoReq(uint32_t msgId, NFDataPackage& packet);
public:
    //更新排行榜数据  enRankType
    void UpdateRankData(const proto_ff::GWUpdateRankReq& req);
    void UpdateRankData(uint32_t nType, uint64_t charID, uint64_t nValue);
    //发送排行榜数据给客户端
    int SendRankData(uint32_t nType, uint64_t charID, uint64_t selfValue, uint64_t unionId);
    //设置节点proto数据
    bool SetRankNodeProtoByCharId(proto_ff::RankNodeData* pNode, uint32_t rankType, uint32_t rank, uint64_t charID, uint64_t value);
    //设置节点proto数据
    bool SetRankNodeProtoByUnionId(proto_ff::RankNodeData* pNode, uint32_t rankType, uint32_t rank, uint64_t unionID, uint64_t value);
public:
    virtual int LoadFromDB(const std::string& dbData);

    virtual int SaveToDB(std::string& dbData);

    virtual int InitConfig();

    virtual int LoadAllRank();
public:
    //创建排行榜数据
    NFCommonRank* CreateRankList(uint32_t nType);
    //获取某一类型的排行榜对象
    NFCommonRank* GetRankList(uint32_t nType);
public:
    NFShmHashMap<uint32_t, NFShmPtr<NFCommonRank>, RANK_TYPE_MAX> m_rankData;
};
