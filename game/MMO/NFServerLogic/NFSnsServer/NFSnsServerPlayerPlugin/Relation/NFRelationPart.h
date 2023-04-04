// -------------------------------------------------------------------------
//    @FileName         :    NFFriendPart.h
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFFriendPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFSnsPart.h"
#include "NFRelationTeam.hpp"
#include "NFLogicCommon/RelationDefine.h"

class NFRelationPart : public NFSnsPart
{
public:
    NFRelationPart();

    virtual ~NFRelationPart();

    int CreateInit();

    int ResumeInit();

public:
    virtual int Init(const proto_ff::RoleDBSnsDetail &data);

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
    static int RegisterClientMessage(NFIPluginManager *pPluginManager);

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);

public:
    int OnHandleRelationDataReq(uint32_t msgId, NFDataPackage &packet);

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
    //添加收礼记录
    bool addGiftRecord(uint64_t targetId, uint64_t itemId, uint32_t sendType);

    //添加好友
    bool AddFriend(uint64_t cid);

    //添加仇人
    bool AddHate(uint64_t cid);

    //添加黑名单
    bool AddBlack(uint64_t cid);

    //添加最近联系人
    bool addRecent(uint64_t cid, uint32_t recentType);

    //添加好友申请
    bool addApply(uint64_t cid, string sConnect);

    //添加屏蔽发言申请
    bool addShield(uint64_t cid);

    //删除关系
    bool deleteRelation(uint32_t groupIndex, uint64_t cid);

    //删除某一类型的所有关系 （清除申请列表）
    void deleteRelationByGroup(uint32_t groupIndex);

    //删除头部元素
    uint64_t delFront(uint32_t groupIndex);

    //某个关系是否存在
    bool isRelationExit(uint32_t groupIndex, uint64_t cid);

    //获取某组关系的剩余容量
    uint32_t getLeftSize(uint32_t groupIndex);

    //获取某组关系最大容量
    uint32_t getMaxSize(uint32_t groupIndex);

    //获取某组关系数量
    uint32_t getCurSize(uint32_t groupIndex);

    //获取某组关系数据
    GroupList &GetGroupList();

    //获取某组关系的id列表
    bool GetRelationIdList(uint32_t groupIndex, std::list<uint64_t> &ids, uint32_t limitCount = 0);

    //增加亲密度
    bool AddFriendCloseness(uint64_t cid, uint32_t type, uint64_t param = 0);

    //获取亲密值
    int32_t getFriendCloseness(uint64_t destId);

    //获取亲密值等级
    uint32_t getFriendClosenessLv(uint64_t destId);

    //数据是否改变（保存数据判断依据）
    inline bool IsChange() { return m_change; }

    //是否在冷却时间中
    bool InCdTime();

    //获取离线时好友增加数量
    uint32_t GetFriendsAdd();

    //增加离线时好友增加数量
    void AddFriendsAdd();

    //设置离线时好友增加数量
    void SetFriendsAdd(uint32_t value);

    //增加活跃值(对象操作次数)
    void AddActive();

    //获取活跃值(对象操作次数)
    uint32_t GetActive();

    //获取玩家
    NFRelationCommonPlayer *GetPlayer(uint32_t groupIndex, uint64_t destId)

    //获取最大机器人id
    uint64_t GetStartRobotId();

    //获取收礼记录
    GiftRecords &GetGiftRecords() { return _giftRecords; }

    //设置感谢送礼
    bool setThanksGift(uint32_t recordId);

private:
    /**
     * @brief 好友
     */
    NFRelationTeam<NFRelationFriendPlayer, MAX_FRIEND_SIZE> m_friendPlayerTeam;
    /**
     * @brief 黑名单
     */
    NFRelationTeam<NFRelationCommonPlayer, MAX_FRIEND_SIZE> m_blackPlayerTeam;
    /**
     * @brief 仇人
     */
    NFRelationTeam<NFRelationHatePlayer, MAX_FRIEND_SIZE> m_hatePlayerTeam;
    /**
     * @brief 最近联系人
     */
    NFRelationTeam<NFRelationRecentPlayer, MAX_FRIEND_SIZE> m_recentPlayerTeam;
    /**
     * @brief 申请好友列表
     */
    NFRelationTeam<NFRelationApplyPlayer, MAX_APPLY_SIZE> m_applyPlayerTeam;
    /**
     * @brief 屏蔽发言列表
     */
    NFRelationTeam<NFRelationCommonPlayer, MAX_SHIELD_SIZE> m_shieldPlayerTeam;
private:
DECLARE_IDCREATE(NFRelationPart)
};