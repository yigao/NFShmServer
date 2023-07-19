// -------------------------------------------------------------------------
//    @FileName         :    NFSnsJettonPart.h
//    @Author           :    gaoyi
//    @Date             :    23-7-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsJettonPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFSnsPart.h"
#include "NFLogicCommon/NFLogicCommon.h"

class NFSnsJettonPart : public NFSnsPart
{
public:
    NFSnsJettonPart();

    virtual ~NFSnsJettonPart();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param pMaster
     * @param partType
     * @param data
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayerDetail *pMaster, uint32_t partType, const proto_ff::tbFishSnsPlayerDetailData &data, bool bCreatePlayer);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();
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

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);

    /** 处理服务器之间的rpc，这里负责转发玩家part的rpc
     * @brief
     * @param msgId
     * @param pRequest
     * @param pRespone
     * @param param1
     * @param param2
     * @return
     */
    virtual int OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message* pRequest, google::protobuf::Message* pRespone);
public:
    /**
     * @brief
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleGetBankDataReq(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishSnsPlayerDetailData& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::tbFishSnsPlayerDetailData& data);

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::tbFishSnsPlayerDetailData &dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }

public:
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }

    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate()  { return 0; }
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }
public:
    int AddBankJettonService(proto_ff::Proto_LTS_PlayerAddBankJettonReq* pRequest, proto_ff::Proto_STL_PlayerAddBankJettonRsp* pResone);
private:
    uint64_t m_bankJetton;
    NFCommonStr m_bankPassword;
    bool m_isCanUseBank;
private:
DECLARE_IDCREATE(NFSnsJettonPart)
};