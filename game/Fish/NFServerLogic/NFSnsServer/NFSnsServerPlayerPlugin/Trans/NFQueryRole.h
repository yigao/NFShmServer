// -------------------------------------------------------------------------
//    @FileName         :    NFQueryRole.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFQueryRole
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFArray.h"

#define MAX_QUERY_ROLE  120
#define TRANS_SNS_BASE_TIMEOUT 60

class NFQueryRole
{
public:
    NFQueryRole();

    virtual ~NFQueryRole();

    int CreateInit();

    int ResumeInit();

    NFQueryRole& operator=(const NFQueryRole& query)
    {
        if (this != &query)
        {
            m_queryRoleList = query.m_queryRoleList;
            m_queryedNum = query.m_queryedNum;
            m_roleId = query.m_roleId;
        }

        return *this;
    }
public:
    /**
     * @brief 添加一个要查询的roleId
     * @param roleId
     * @return
     */
    int Add(uint64_t roleId);
public:
    /**
     * @brief 被查询的角色队列
     */
    NFArray<uint64_t, MAX_QUERY_ROLE> m_queryRoleList;

    /**
     * @brief 已经查询到的数量
     */
    int m_queryedNum;

    /**
     * @brief
     */
    int m_queryedDetailNum;

    /**
     * @brief 查询的角色ID
     */
    uint64_t m_roleId;
};