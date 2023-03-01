// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePart.h
//    @Author           :    gaoyi
//    @Date             :    23-2-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "DBProto2.pb.h"
#include "NFComm/NFShmCore/NFSeqOP.h"

class NFCreature;

class NFBattlePart : public NFShmObj, public NFSeqOP
{
public:
    NFBattlePart();

    virtual ~NFBattlePart();

    int CreateInit();

    int ResumeInit();
public:
    virtual int Init(NFCreature *pMaster, uint32_t partType, const proto_ff::RoleEnterSceneData &data);

    virtual int UnInit();

public:
    virtual uint32_t GetCurRoleDetailSeq() const;
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
    static int RetisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType);

    static int RetisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType);
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
    //部件类型
    uint32_t PartType() { return m_partType; }

public:
    NFCreature* GetMaster();
protected:
    int m_masterCid;
    uint32_t m_partType;

private:
DECLARE_IDCREATE(NFBattlePart)
};