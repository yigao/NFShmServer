// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFWorldCommonDefine.h"
#include "NFLoginQueue.h"
#include <vector>

class NFWorldPlayer;
class NFWorldPlayerMgr : public NFShmObj {
public:
    NFWorldPlayerMgr(NFIPluginManager* pPluginManager);
    virtual ~NFWorldPlayerMgr();

    int CreateInit();
    int ResumeInit();

    virtual void OnTimer(int timeId, int callcount) override;
public:
    /**
     * @brief
     * @return
     */
    int PlayerTick();
public:

    /**
     * @brief 通过playerId获取玩家数据
     * @param playerId
     * @return
     */
    NFWorldPlayer *GetPlayer(uint64_t playerId);

    /**
     * @brief 通过playerId创建玩家数据, 如果玩家存在，返回NULL
     * @param playerId
     * @return
     */
    NFWorldPlayer *CreatePlayer(uint64_t playerId);

    /**
     * @brief 删除玩家数据
     * @param pPlayer
     * @return
     */
    int DeletePlayer(NFWorldPlayer *pPlayer);

public:
    /**
     * @brief 通过cid找到玩家
     * @param cid 角色ID
     * @return
     */
    NFWorldPlayer *GetPlayerByCid(uint64_t cid);

    /**
     * @brief 删除cid
     * @param cid
     * @return
     */
    int EraseCid(uint64_t cid);
public:
    /**
     * @brief 排队
     */

    uint32_t GetCurrentLoginNum() const;

    void SetCurrentLoginNum(uint32_t currentLoginNum);

    uint32_t GetMaxQueueNum() const;

    void SetMaxQueueNum(uint32_t maxQueueNum);

    uint32_t GetStartQueueNum() const;

    void SetStartQueueNum(uint32_t startQueueNum);

    /**
     * @brief 是否需要排队
     * @return
     */
    bool IsNeedLoginQueue() const;

    /**
     * @brief 是否排队队列已经满了
     * @return
     */
    bool IsLoginQueueFull() const;

    /**
     * @brief 是否在排队队列中
     * @param playerId
     * @return
     */
    bool IsInLoginQueue(uint64_t playerId) const;

     /**
      * @brief 加入到登陆排队中
      * @param playerId
      * @return
      */
    bool InsertLoginQueue(uint64_t playerId);

    /**
     * @brief 通过玩家ID获得排队数据
     * @param playerId
     * @return
     */
    NFLoginQueue* GetLoginQueue(uint64_t playerId);

    /**
     * @brief 获得当前排队人数
     * @return
     */
    uint32_t GetLoginQueueNum() const;
public:

private:
    /**
     * @brief 玩家ticker定时
     */
    int m_playerTickTimer;

    /**
     * @brief 玩家charId与playerId映射，支持最大在线=WORLD_SERVER_MAX_ONLINE_COUNT
     */
    NFShmHashMap<uint64_t, uint64_t, WORLD_SERVER_MAX_ONLINE_COUNT> m_charIdToPlayerIdMap;

private:
    /**
     * @brief 排队
     */

    /**
     * @brief 记录排队uid表列
     */
    NFShmHashMap<uint64_t, NFLoginQueue, WORLD_SERVER_MAX_ONLINE_COUNT> m_loginQueueMap;

    /**
     * @brief 计算已经进入的登陆的人数  包含在选角色界面和进入游戏的
     */
    uint32_t m_currentLoginNum;

    /**
     * @brief 最多排队的人数
     */
    uint32_t m_maxQueueNum;

    /**
     * @brief 开始排队人数
     */
    uint32_t m_startQueueNum;
DECLARE_IDCREATE(NFWorldPlayerMgr)
};