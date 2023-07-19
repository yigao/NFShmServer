// -------------------------------------------------------------------------
//    @FileName         :    NFPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFCore/NFTime.h"
#include "DBProto.pb.h"
#include "NFComm/NFShmCore/NFShmPtr.h"

class NFPlayer;

class NFPart : public NFShmObj, public NFSeqOP
{
public:
    NFPart();

    virtual ~NFPart();

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
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer);

    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishPlayerData& data) { return 0; }

    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::tbFishPlayerData& data) { return 0; }

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::tbFishPlayerData &dbData) { return 0; }

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
    virtual int MonthZeroUpdate() { return 0; };
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

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

public:
    /**
     * @brief
     * @param nMsgID
     * @param createCo
     * @return
     */
    virtual int RegisterClientMessage(uint32_t nMsgID, bool createCo = false);

    /**
     * @brief
     * @param nMsgID
     * @param createCo
     * @return
     */
    virtual int RegisterServerMessage(uint32_t nMsgID, bool createCo = false);
public:
    //部件类型
    uint32_t PartType() { return m_partType; }
    void SetPartType(uint32_t partType) { m_partType = partType; }
public:
    virtual uint32_t GetCurRoleDetailSeq() const;
protected:
    NFShmPtr<NFPlayer> m_pMaster;
    uint64_t m_playerId;
    uint32_t m_partType;
private:
DECLARE_IDCREATE(NFPart)
};