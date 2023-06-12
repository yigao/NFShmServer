// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerMgr.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmOldHashMap.h"
#include "DBProto.pb.h"
#include "Trans/NFTransSaveRoleDetail.h"
#include "NFComm/NFShmCore/NFTickByRunIndexOP.h"
#include "NFLogicCommon/NFRoleDefine.h"

class NFPlayer;

class NFPlayerMgr : public NFShmObj, public NFTickByRunIndexOP
{
public:
    NFPlayerMgr();

    virtual ~NFPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * @brief
     * @return
     */
    int Execute();

    /**
     * @brief
     * @param pPlayer
     * @param iReason
     * @return
     */
    int SavePlayerRoleDetail(NFPlayer *pPlayer, TRANS_SAVE_ROLE_DETAIL_REASON iReason);

    virtual int OnTimer(int timeId, int callcount);
public:
    /**
     * @brief 处理玩家登陆一些回调事情
     * @param pPlayer
     * @param isLoadDB
     * @return
     */
    int OnLoad(NFPlayer *pPlayer, bool isLoadDB);

    int OnLogin(NFPlayer *pPlayer, bool isLoadDB);

    /**
     * @brief 处理玩家登出一些回调事情
     * @param pPlayer
     * @return
     */
    int OnLogout(NFPlayer *pPlayer);

    /**
     * @brief 处理玩家掉线一些回调事情
     * @param pPlayer
     * @return
     */
    int OnDisconnect(NFPlayer *pPlayer);

    /**
     * @brief 处理玩家重连一些回调事情
     * @param pPlayer
     * @return
     */
    int OnReconnect(NFPlayer *pPlayer);
public:
    //////////////////////////////每日每周刷新接口///////////////////////////////
    /**
     * @brief 每日每周刷新接口  策划配置，几点
     * @param unixSec
     */
    int DailyUpdate(uint64_t unixSec);

    /**
     * @brief 每日每周刷新接口  策划配置，几点
     * @param unixSec
     */
    int WeekUpdate(uint64_t unixSec);
    //////////////////////////////每日零点 每周一零点 刷新接口///////////////////////////////

    /**
     * @brief 每日零点 每周一零点 刷新接口
     * @param unixSec
     */
    int DailyZeroUpdate(uint64_t unixSec);

    /**
     * @brief 每日零点 每周一零点 刷新接口
     * @param unixSec
     */
    int WeekZeroUpdate(uint64_t unixSec);
public:
    /**
     * @brief 处理玩家离线事件
     * @param pPlayer
     * @param isLoadDB
     * @return
     */
    int OnEventLogLogin(NFPlayer *pPlayer, bool isLoadDB);
public:
    /**
     * @brief 通过roleId获取玩家数据
     * @param roleId
     * @return
     */
    NFPlayer *GetPlayer(uint64_t roleId);

    /**
     * @brief 通过roleId创建玩家数据, 如果玩家存在，返回NULL
     * @param roleId
     * @return
     */
    NFPlayer *CreatePlayer(uint64_t roleId, uint64_t uid, const ::proto_ff::RoleDBData &dbData);

    /**
     * @brief 删除玩家数据
     * @param pPlayer
     * @return
     */
    int DeletePlayer(NFPlayer *pPlayer);

public:
    int LoginGame(uint64_t roleId, const CharLoginInfo& loginInfo);
    int LogoutGame(uint64_t uid, uint64_t roleId, uint32_t type, uint32_t reqTransId);
    int TransScene(uint64_t uid, uint64_t roleId, uint64_t mapId, uint32_t transType, uint64_t dstId);
public:
    /**
     * @brief 继承自NFTickByRunIndexOP， 用来平衡处理每一帧应该处理的玩家数
     * @param dwCurRunIndex
     * @param bIsTickAll
     * @return
     */
    virtual int DoTick(uint32_t dwCurRunIndex, bool bIsTickAll = false);
private:
    int m_dayZeroTimer;
    int m_weekZeroTimer;
DECLARE_IDCREATE(NFPlayerMgr);
};