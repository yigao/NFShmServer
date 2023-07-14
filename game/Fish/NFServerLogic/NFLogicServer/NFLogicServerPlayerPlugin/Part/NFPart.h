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
    //******************part调用生物接口******************
    //生物init调用
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer);

    //生物uint调用
    virtual int UnInit();

public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::tbFishPlayerData& data) { return 0; }

    /**
     * @brief
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
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate(uint64_t unixSec) { return 0; }

    /**
     * @brief 每日零点 刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate(uint64_t unixSec) { return 0; }

public:
    /**
     * @brief update
     * @param tick
     */
    virtual int Update() { return 0; }

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
    static int RegisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType, bool createCo);

    static int RegisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType, bool createCo);

public:
    //部件类型
    uint32_t PartType() { return m_partType; }
public:
    virtual uint32_t GetCurRoleDetailSeq() const;
protected:
    NFShmPtr<NFPlayer> m_pMaster;
    uint64_t m_playerId;
    uint32_t m_partType;
private:
DECLARE_IDCREATE(NFPart)
};