// -------------------------------------------------------------------------
//    @FileName         :    NFRankPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFRankDefine.h"

class NFRankPart : public NFShmObjTemplate<NFRankPart, EOT_LOGIC_PART_ID+PART_RANK, NFPart>
{
public:
    NFRankPart();

    virtual ~NFRankPart();

    int CreateInit();

    int ResumeInit();
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);

    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);
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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);
public:
    //发送数值到中心服更新排行榜
    void UpdateRank(enRankType rankType, uint64_t value);
    //获取玩家的排行榜数值
    uint64_t GetPlayerRankValue(uint32_t rankType);
public:
    //请求排行榜数据
    int OnGetRankDataRequest(uint32_t msgId, NFDataPackage &packet);
};