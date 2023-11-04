// -------------------------------------------------------------------------
//    @FileName         :    NFFunctionUnlockPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFunctionUnlockPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "E_Functionunlock_s.h"

class NFMissionPart;
class NFFunctionUnlockPart : public NFShmObjTemplate<NFFunctionUnlockPart, EOT_LOGIC_PART_ID+PART_FUNCTIONUNLOCK, NFPart>
{
public:
    NFFunctionUnlockPart();

    virtual ~NFFunctionUnlockPart();

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
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData& data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData& data);
    
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
    virtual int OnLogin();
    virtual int OnLogin(proto_ff::PlayerInfoRsp& playerInfo);
    
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
    virtual int DailyZeroUpdate();
    
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
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto& outproto) { return 0; }
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
    int OnHandleGetReward(uint32_t msgId, NFDataPackage &packet);
public:
    //解锁所有功能
    bool UnlockAllFunc();
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
    bool CheckALLFunctions(bool sync = true);
    //获取转职等级
    uint32_t GetOccupationGrade(uint64_t occupationId);
    //检查功能是否解锁
    bool CheckUnlock(int32_t Lev, int32_t occupationLev, uint32_t opendays, int32_t viplev, int32_t totalrmb, NFMissionPart *pMissionPart, const  proto_ff_s::E_FunctionunlockFunctionunlock_s &cfg);
    //开服天数
    uint32_t OpenDays();
private:
    NFShmHashMap<uint64_t, bool, DEFINE_SHEET_FUNCTIONUNLOCKFUNCTIONUNLOCK_E_FUNCTIONUNLOCKFUNCTIONUNLOCK_LIST_MAX_NUM> m_mapUnLock; //玩家已解锁的功能
};