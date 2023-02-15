// -------------------------------------------------------------------------
//    @FileName         :    NFFunctionUnlockPart.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFFunctionUnlockPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFPart.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "functionunlock_s.h"

#define MAX_FUNCTION_UNLOCK_NUM 1000

class NFFunctionUnlockPart : public NFPart
{
public:
    NFFunctionUnlockPart();

    virtual ~NFFunctionUnlockPart();

    int CreateInit();

    int ResumeInit();

public:
    //******************part调用生物接口******************
    //生物init调用
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);

    //生物uint调用
    virtual int UnInit();

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }

    /**
     * @brief  登陆入口
     * @param playerInfo
     * @return
     */
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);

    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate(uint64_t unixSec);
public:

    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);

public:
    static int RetisterClientMessage(NFIPluginManager *pPluginManager);

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);

public:
    int OnHandleGetReward(uint32_t msgId, NFDataPackage &packet);

public:
    //解锁所有功能
    int UnlockAllFunc();

    //功能是否解锁  FunctionUnlock_ID_TYPE
    bool isFunctionUnlock(uint64_t functionId);

    void Unlock(int64_t functionId);

    void UnlockSendAdd(int64_t functionId);

private:
    //检查解锁
    void checkUnlock(uint32_t nType, int64_t nValue);

    //发送数据到客户端
    void sendFunctionUnlockInfo(VEC_UINT64 *pList);

    //移除解锁功能
    void DelUnlock(uint64_t unlockid);

    //添加解锁功能
    void AddUnlock(uint64_t unlockid);

    //检查所有的功能是否可解锁
    int CheckALLFunctions(bool sync = true);

    //获取转职等级
    uint32_t GetOccupationGrade(uint64_t occupationId);

    //检查功能是否解锁
    bool CheckUnlock(int32_t Lev, int32_t occupationLev, uint32_t opendays, int32_t viplev, int32_t totalrmb,
                     const proto_ff_s::functionunlockfunctionUnlock_s &cfg);

    //开服天数
    uint32_t OpenDays();

private:
    NFShmHashMap<uint64_t, bool, MAX_FUNCTION_UNLOCK_NUM> m_mapUnLock; //玩家已解锁的功能
DECLARE_IDCREATE(NFFunctionUnlockPart)
};