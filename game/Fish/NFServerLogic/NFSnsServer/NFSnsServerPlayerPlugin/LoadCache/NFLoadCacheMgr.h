// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLoadCacheData.h"
#include "Cache/NFPlayerSimple.h"
#include "Cache/NFPlayerDetail.h"

class NFLoadCacheMgr : public NFShmObjTemplate<NFLoadCacheMgr, EOT_SNS_LOAD_CACHE_MGR_ID, NFShmObj>
{
public:
    NFLoadCacheMgr();

    virtual ~NFLoadCacheMgr();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnTimer(int timeId, int callcount) override;
    int RefreshSimpleQueue();
    int RefreshDetailQueue();
    int RefreshRpcQueue();
public:
    // 接口没有做RoleSimple检测,需要自己提前检测（如TransSnsBase）
    int GetPlayerSimpleInfo(uint64_t playerId, int transId, uint64_t time);

    NFPlayerSimple* GetPlayerSimpleInfoByRpc(uint64_t playerId, uint64_t time);

    // 接口会去check是否RoleSimple已经存在，存在会直接返回
    int GetCheckedRoleSimpleInfo(uint64_t playerId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    int TransGetPlayerSimpleInfo(uint64_t playerId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    NFPlayerSimple* RpcGetPlayerSimpleInfo(uint64_t playerId, bool bCreatePlayer = false);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    int HandleGetRoleSimpleTransFinished(int iRunLogicRetCode, uint64_t roleId);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    int HandleGetRoleSimpleRpcFinished(int iRunLogicRetCode, uint64_t roleId);

    /**
     * @brief 创建玩家DB数据 通过rpc异步去数据库插入数据
     * @param role_id
     * @return
     */
    NFPlayerSimple* CreatePlayerSimpleDBDataByRpc(const proto_ff::tbFishSnsPlayerSimpleData& dbData);
public:
    /**
     * @brief
     * @param roleId
     * @param transId
     * @param time
     * @return
     */
    int GetPlayerDetailInfo(uint64_t roleId, int transId, uint32_t time);

    /**
     * @brief
     * @param playerId
     * @param time
     * @return
     */
    NFPlayerDetail* GetPlayerDetailInfoByRpc(uint64_t playerId, uint64_t time);

    /**
     * @brief
     * @param data
     * @return
     */
    int TransGetRoleDetailInfo(uint64_t playerId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    NFPlayerDetail* RpcGetPlayerDetailInfo(uint64_t playerId, bool bCreatePlayer = false);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    int HandleGetRoleDetailTransFinished(int iRunLogicRetCode, uint64_t roleId);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    int HandleGetRoleDetailRpcFinished(int iRunLogicRetCode, uint64_t roleId);

    /**
     * @brief 创建玩家DB数据 通过rpc异步去数据库插入数据
     * @param role_id
     * @return
     */
    NFPlayerDetail* CreatePlayerDetailDBDataByRpc(const proto_ff::tbFishSnsPlayerDetailData& dbData);
private:
    int m_refreshTimer;
    int m_refreshRpcTimer;
    bool flag;
private:
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GET_PLAYER_SIMPLE_INFO_QUEUE> m_playerSimpleWaitLoadMap;
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GETTING_PLAYER_SIZE> m_playerSimpleLoadingMap;
private:
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GET_PLAYER_SIMPLE_INFO_QUEUE> m_playerDetailWaitLoadMap;
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GETTING_PLAYER_SIZE> m_playerDetailLoadingMap;
private:
    NFShmHashMap<int64_t, int32_t, SNS_GETTING_PLAYER_SIZE> m_waitResumeRpcMap;
};