// -------------------------------------------------------------------------
//    @FileName         :    NFRankMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankMgr
//
// -------------------------------------------------------------------------

#pragma once

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
