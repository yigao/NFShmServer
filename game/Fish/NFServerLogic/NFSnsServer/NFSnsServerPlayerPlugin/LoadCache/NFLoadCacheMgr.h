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

class NFLoadCacheMgr : public NFShmObj
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

    int TransGetRoleSimpleInfo(uint64_t playerId);

    NFPlayerSimple* RpcGetRoleSimpleInfo(uint64_t playerId);

    int HandleGetRoleSimpleTransFinished(int iRunLogicRetCode, uint64_t roleId);
    int HandleGetRoleSimpleRpcFinished(int iRunLogicRetCode, uint64_t roleId);
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
     * @param data
     * @return
     */
    int TransGetRoleDetailInfo(NFLoadCacheData *data);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    int HandleGetRoleDetailTransFinished(int iRunLogicRetCode, uint64_t roleId);
private:
    int m_refreshTimer;
    bool flag;
private:
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GET_PLAYER_SIMPLE_INFO_QUEUE> m_playerSimpleWaitLoadMap;
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GETTING_PLAYER_SIZE> m_playerSimpleLoadingMap;
private:
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GET_PLAYER_SIMPLE_INFO_QUEUE> m_playerDetailWaitLoadMap;
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GETTING_PLAYER_SIZE> m_playerDetailLoadingMap;
private:
    NFShmHashMap<int64_t, int32_t, SNS_GETTING_PLAYER_SIZE> m_waitResumeRpcMap;
DECLARE_IDCREATE(NFLoadCacheMgr)
};