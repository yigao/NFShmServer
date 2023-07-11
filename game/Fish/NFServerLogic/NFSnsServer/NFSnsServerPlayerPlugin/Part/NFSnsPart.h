// -------------------------------------------------------------------------
//    @FileName         :    NFSnsPart.h
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "AllProtocol.h"

class NFPlayerDetail;
class NFPlayerSimple;
class NFSnsPart : public NFShmObj, public NFSeqOP
{
public:
    NFSnsPart();

    virtual ~NFSnsPart();

    int CreateInit();

    int ResumeInit();
public:
    int InitBase(NFPlayerDetail *pMaster, uint32_t partType);
public:
    virtual int Init(const proto_ff::tbFishSnsPlayerData &data);

    virtual int UnInit();

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
    static int RegisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType);

    static int RegisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType);

public:
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
    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyUpdate(uint64_t unixSec) { return 0; }

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekUpdate(uint64_t unixSec) { return 0; }
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
    virtual int Update(uint64_t tick) { return 0; }

public:
    virtual int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);

    virtual int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);

    virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);

    virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData);
public:
    //部件类型
    uint32_t PartType() { return m_partType; }
public:
    virtual uint32_t GetCurRoleDetailSeq() const;
public:
    NFPlayerSimple* GetPlayerSimple();
protected:
    NFShmPtr<NFPlayerDetail> m_pMaster;
    uint64_t m_playerId;
    uint32_t m_partType;
private:
DECLARE_IDCREATE(NFSnsPart)
};