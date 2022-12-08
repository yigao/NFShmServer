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
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLoadCacheData.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFShmStaticList.hpp"
#include "Cache/NFRoleSimple.h"

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
public:
    // 接口没有做RoleSimple检测,需要自己提前检测（如TransSnsBase）
    int GetRoleSimpleInfo(uint64_t roleId, int transId, uint64_t time);

    // 接口会去check是否RoleSimple已经存在，存在会直接返回
    int GetCheckedRoleSimpleInfo(uint64_t roleId);

    int TransGetRoleSimpleInfo(NFLoadCacheData *data);

    int HandleGetRoleSimpleTransFinished(int iRunLogicRetCode, uint64_t roleId);
public:
    /**
     * @brief
     * @param roleId
     * @param transId
     * @param time
     * @return
     */
    int GetRoleDetailInfo(uint64_t roleId, int transId, uint32_t time);

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
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GET_ROLE_SIMPLE_INFO_QUEUE> m_roleSimpleWaitLoadMap;
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GETTING_ROLE_SIZE> m_roleSimpleLoadingMap;
private:
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GET_ROLE_SIMPLE_INFO_QUEUE> m_roleDetailWaitLoadMap;
    NFShmHashMap<uint64_t, NFLoadCacheData, SNS_GETTING_ROLE_SIZE> m_roleDetailLoadingMap;
DECLARE_IDCREATE(NFLoadCacheMgr)
};